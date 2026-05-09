# Ejercicio 3.1.2
Modifique el código de la Figura 2 para que el proceso padre incremente 10 veces el valor de una variable en pasos de 10, mientras que el proceso hijo registre cada valor en un archivo de texto.

*Ejecución del código modificado de la Figura 2:*

<img width="281" height="196" alt="Captura de pantalla 2026-05-08 201236" src="https://github.com/user-attachments/assets/dc686170-5c3d-44ba-baf6-1283a83dfe87" />

Se ha modificado el código para permitir que el proceso hijo escriba en un archivo de texto denomiado `log.txt` y verificar así que el hijo realmente está trabajando en paralelo.

Además, se creó una variable llamada `variable` para que el proceso padre incremente 10 veces el valor de dicha variable en pasos de 10, sin embargo, al momento de ejecutar `fork()` el proceso padre clona su memoria, es decir, que la variable `variable` del proceso hijo se vuelve totalmente independiente a la del padre.
Este problema se evidencia al momento de ejecutar el programa, donde el padre incrementaba la variable de 10 en 10, pero el proceso hijo sigue teniendo la variable inicial: 0.

Para solucionar esto y que el proceso hijo registre cada valor incrementado del proceso padre, se implementa un mecanismo de comunicación entre procesos (IPC) mediante el uso de pipes o tuberías (`pipe()`).
Esto permite que al momento que el proceso padre incremente la variable, esta se envíe por `pipe` hacia el hijo y se pueda escribir en el archivo de texto.
