# Ejercicio 3.1.1
Ejecute el programa de la Figura 1 e identifique los valores PID y PPID de cada proceso.

Ejecución de la Figura 1:

<img width="369" height="116" alt="Captura de pantalla 2026-05-06 210117" src="https://github.com/user-attachments/assets/e57fa7af-7b63-4182-b830-e51602555c53" />

Al ejecutar el código de la Figura 1 se generaron dos procesos: el proceso padre y el proceso hijo, donde sus valores PID Y PPID fueron los siguientes:
1. **Proceso Padre**
   - **PID:** 19818 - Este valor corresponde al proceso original que inició la ejecución del programa y su continuación después de ejecutar `fork()`.
2. **Proceso Hijo**
   - **PID:** 19819 - Este proceso es creado por el `fork()`.
   - **PPID:** 19818 - Que el PPID del hijo sea igual al PID del padre solo evidencia la relación padre-hijo que existe ya que el PPID indica qué proceso creó al proceso hijo.
