<#
.SYNOPSIS
    PoC Académica: Estudio de Sincronización de Estado Cliente-Servidor mediante Firewall Local (Sistema Legacy)
.DESCRIPTION
    AVISO LEGAL Y ÉTICO (ACADEMIC & ETHICAL DISCLAIMER):
    Este script se proporciona exclusivamente con fines educativos, académicos y de investigación
    en arquitectura de software y seguridad defensiva/ofensiva ética (estudio de CWE-840 / CWE-602
    sobre el antiguo sistema retirado de Steam Family Sharing).
    - No modifica binarios, no inyecta código en memoria ni vulnera mecanismos criptográficos o DRM.
    - Únicamente gestiona reglas estándar del Firewall de Windows en el propio equipo local del usuario
      para estudiar el comportamiento de una aplicación ante la pérdida de notificaciones push de red.
    - El autor no respalda ni promueve el incumplimiento de los Términos de Servicio (ToS) de ninguna plataforma.
.PARAMETER Mode
    - Install : Crea las reglas de firewall (Inbound y Outbound) en estado deshabilitado.
    - Isolate : Activa las reglas de aislamiento de red para el proceso seleccionado.
    - Restore : Desactiva las reglas y restaura la conectividad normal del proceso.
    - Status  : Muestra si las reglas de laboratorio están activas (ON) o inactivas (OFF).
    - Remove  : Elimina por completo las reglas de prueba del Firewall de Windows.
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
        Write-Host "[+] Reglas de aislamiento local: ON (Tráfico del proceso bloqueado en Firewall)" -ForegroundColor Green
    } else {
        Write-Host "[-] Reglas de aislamiento local: OFF (Sincronización de red normal activa)" -ForegroundColor Cyan
    }
}

if ($Mode -eq "Status") {
    Get-IsolationStatus
    exit 0
}

if (-not (Test-Administrator)) {
    Write-Error "El modo '$Mode' requiere privilegios de Administrador para gestionar reglas del Firewall de Windows."
    exit 1
}

switch ($Mode) {
    "Install" {
        if (-not (Test-Path $SteamPath)) {
            Write-Error "No se encontró el ejecutable en '$SteamPath'. Especifica la ruta con -SteamPath."
            exit 1
        }
        Remove-NetFirewallRule -DisplayName $RuleDisplayName -ErrorAction SilentlyContinue
        New-NetFirewallRule -DisplayName $RuleDisplayName -Direction Inbound  -Program $SteamPath -Action Block -Profile Any -Enabled False | Out-Null
        New-NetFirewallRule -DisplayName $RuleDisplayName -Direction Outbound -Program $SteamPath -Action Block -Profile Any -Enabled False | Out-Null
        Write-Host "[+] Reglas Inbound/Outbound '$RuleDisplayName' creadas (deshabilitadas por defecto) para: $SteamPath" -ForegroundColor Green
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
        Write-Host "[*] Reglas de prueba '$RuleDisplayName' eliminadas correctamente." -ForegroundColor Yellow
    }
}
