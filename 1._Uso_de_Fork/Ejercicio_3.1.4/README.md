# Ejercicio 3.1.4

Modificar el código de la Figura 4 para que cada proceso hijo haga una tarea diferente.

*Creación de un proceso padre y de tres procesos hijos.*

### Ejecución del código:

<img width="281" height="196" alt="Captura de pantalla ejecución" src="Captura de pantalla 2026-05-11 174133.png" /> 

### Detalles de la Implementación
El código fue adaptado para demostrar el control sobre la jerarquía de procesos en sistemas Unix/Linux. Los cambios realizados fueron:

1. **Tareas Diferenciadas:** Cada proceso hijo identifica su rol mediante su número de iteración y ejecuta una lógica específica (conteo, cuenta regresiva o suma), demostrando que procesos con el mismo código base pueden realizar acciones distintas.
2. **Uso de `exit()`:** Se incluyó para que cada hijo finalice su ejecución inmediatamente después de su tarea, previniendo que continúen en el ciclo de creación de procesos del padre.
3. **Uso de `wait()`:** Esta función sincroniza al padre para que espere la terminación de cada hijo, garantizando que el flujo de la terminal coincida con la lógica programada.
