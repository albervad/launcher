# 🚀 C++ Custom Launcher & Firewall Manipulator (Steam Bypass)

Un lanzador de aplicaciones personalizado desarrollado en **C++ y Qt**, diseñado originalmente para optimizar el acceso a herramientas y juegos. 

El aspecto más destacado de este proyecto desde la perspectiva de seguridad y sistemas es su **módulo de evasión de restricciones de red**. Implementa una manipulación dinámica del Firewall de Windows a través de PowerShell para realizar un *bypass* de los controles de conexión de Steam (permitiendo el juego simultáneo en el antiguo sistema de Family Sharing).

> **Nota:** Hoy en día, Steam permite esta funcionalidad de forma nativa. Este proyecto se mantiene como una demostración técnica de manipulación de reglas de red del sistema operativo, ejecución de procesos con privilegios y uso de la API de Windows.

## 🛡️ Enfoque en Seguridad e Internals del Sistema (Highlights)

Para el desarrollo de este proyecto fue necesario investigar e implementar conceptos de bajo nivel y administración del sistema:

* **Manipulación Dinámica del Firewall (Network Bypass):** * El programa interactúa directamente con el sistema host inyectando comandos en PowerShell de forma programática.
    * Utiliza `Enable-NetFirewallRule` y `Disable-NetFirewallRule` solicitando escalada de privilegios (`-verb runas`) para cortar selectivamente la telemetría y las comprobaciones de estado de Steam, aislando la aplicación del exterior sin afectar la red del resto del equipo.
* **Interacción con la API de Windows (WinAPI):** * Implementación de *Global Hotkeys* (`RegisterHotKey` con `MOD_CONTROL | MOD_ALT`) a nivel del sistema operativo para interceptar eventos de teclado (`WM_HOTKEY`) independientemente de la ventana que tenga el foco, demostrando comprensión de la cola de mensajes de Windows (`PeekMessage`).
* **Gestión de Procesos (Process Execution):** * Creación y gestión de procesos secundarios e hilos (Threads) en C++. Ejecución de procesos "Detached" (`QProcess::startDetached`) para asegurar que las aplicaciones hijas sobrevivan aunque el launcher principal se cierre.

## ⚙️ Características Generales

* **Interfaz Frameless y Oculta:** Interfaz de usuario sin bordes que se ejecuta en segundo plano (System Tray) para no consumir recursos innecesarios.
* **Aparición bajo demanda:** Se invoca y se oculta mediante la combinación de teclas `Ctrl + Alt + F12`.
* **Carga Dinámica:** Lee la configuración y las rutas de los ejecutables desde archivos locales (`apps.txt` y `games.txt`) en tiempo de ejecución, parseando la información para construir la UI dinámicamente.

## 🛠️ Stack Tecnológico

* **Lenguaje:** C++ (Standard Library, File I/O, Threading)
* **Framework GUI:** Qt (QProcess, QSystemTrayIcon, QDesktopServices)
* **OS APIs:** Windows API (User32.dll)
* **Scripting:** PowerShell (Living off the Land techniques)

## 💡 Lecciones Aprendidas y Mirada al Futuro

Este fue uno de mis primeros proyectos en C++. Si lo reescribiera hoy con un enfoque puramente orientado a la seguridad ofensiva o *Red Teaming*:
1.  Evitaría las llamadas directas a `powershell.exe` mediante `QProcess` por ser ruidosas y fácilmente detectables por un EDR. En su lugar, utilizaría llamadas directas a las APIs COM de Windows Firewall (`INetFwPolicy2`) para manipular las reglas de forma más sigilosa.
2.  Mejoraría la validación de los archivos `.txt` de configuración para prevenir vulnerabilidades de *Path Traversal* o inyección de comandos en los argumentos de los ejecutables cargados.
