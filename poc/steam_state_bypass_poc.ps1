<#
.SYNOPSIS
    PoC: Event-Driven State Validation Bypass via Selective Host-Firewall Isolation (Legacy Steam Family Sharing)
.DESCRIPTION
    Prueba de concepto educativa (investigación histórica sobre el antiguo sistema de Steam Family Sharing).
    Demuestra cómo el bloqueo selectivo de tráfico entrante/saliente del ejecutable del cliente (steam.exe)
    tras la sincronización inicial de estado impide la recepción de eventos push de invalidación de biblioteca,
    congelando en caché local el último estado válido ("Disponible") sin afectar la conectividad del resto del SO.
.PARAMETER Mode
    - Install : Crea las reglas de firewall (Inbound y Outbound) para steam.exe (deshabilitadas por defecto).
    - Isolate : Activa las reglas (congela el estado actual de sesión de Steam cortando sus sockets).
    - Restore : Desactiva las reglas (restaura la sincronización de estado con los servidores).
    - Status  : Muestra si el aislamiento de estado está activo (ON) o inactivo (OFF).
    - Remove  : Elimina las reglas creadas del Firewall de Windows.
#>

[CmdletBinding()]
param(
    [Parameter(Mandatory = $false)]
    [ValidateSet("Install", "Isolate", "Restore", "Status", "Remove")]
    [string]$Mode = "Status",

    [Parameter(Mandatory = $false)]
    [string]$SteamPath = "${env:ProgramFiles(x86)}\Steam\steam.exe"
)

$RuleDisplayName = "offlineSteam"

function Test-Administrator {
    $currentUser = [Security.Principal.WindowsIdentity]::GetCurrent()
    $principal = New-Object Security.Principal.WindowsPrincipal($currentUser)
    return $principal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
}

function Get-IsolationStatus {
    $rules = Get-NetFirewallRule -DisplayName $RuleDisplayName -ErrorAction SilentlyContinue
    if (-not $rules) {
        Write-Host "[*] Estado: NO INSTALADO (No existen reglas '$RuleDisplayName')" -ForegroundColor Yellow
        return
    }
    $activeCount = ($rules | Where-Object { $_.Enabled -eq "True" } | Measure-Object).Count
    if ($activeCount -ge 2) {
        Write-Host "[+] Aislamiento de estado: ON (Estado de sesión congelado / Tráfico de steam.exe bloqueado)" -ForegroundColor Green
    } else {
        Write-Host "[-] Aislamiento de estado: OFF (Sincronización normal con servidores activa)" -ForegroundColor Cyan
    }
}

if ($Mode -eq "Status") {
    Get-IsolationStatus
    exit 0
}

if (-not (Test-Administrator)) {
    Write-Error "Este modo ('$Mode') requiere privilegios de Administrador para modificar Windows Filtering Platform / Firewall."
    exit 1
}

switch ($Mode) {
    "Install" {
        if (-not (Test-Path $SteamPath)) {
            Write-Error "No se encontró steam.exe en '$SteamPath'. Especifica la ruta con -SteamPath."
            exit 1
        }
        Remove-NetFirewallRule -DisplayName $RuleDisplayName -ErrorAction SilentlyContinue
        New-NetFirewallRule -DisplayName $RuleDisplayName -Direction Inbound  -Program $SteamPath -Action Block -Profile Any -Enabled False | Out-Null
        New-NetFirewallRule -DisplayName $RuleDisplayName -Direction Outbound -Program $SteamPath -Action Block -Profile Any -Enabled False | Out-Null
        Write-Host "[+] Reglas Inbound/Outbound '$RuleDisplayName' creadas para: $SteamPath" -ForegroundColor Green
        Get-IsolationStatus
    }
    "Isolate" {
        Enable-NetFirewallRule -DisplayName $RuleDisplayName -ErrorAction Stop | Out-Null
        Get-IsolationStatus
    }
    "Restore" {
        Disable-NetFirewallRule -DisplayName $RuleDisplayName -ErrorAction Stop | Out-Null
        Get-IsolationStatus
    }
    "Remove" {
        Remove-NetFirewallRule -DisplayName $RuleDisplayName -ErrorAction SilentlyContinue
        Write-Host "[*] Reglas '$RuleDisplayName' eliminadas correctamente." -ForegroundColor Yellow
    }
}
