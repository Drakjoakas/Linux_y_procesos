#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/*
Sandoval Miramontes Joaquín
*/

/*
 @param char*   program  comando a ejecutar por execvp()
 @param char**  arg_list argumentos del comando mandado en program

 Función que crea un nuevo proceso hijo con fokr().
 Si el proceso es creado correctamente, ejecuta
*/
int spawn (char* program, char** arg_list)
{
 pid_t child_pid;
 child_pid = fork ();  //Creación del proceso hijo
 if (child_pid != 0) //Flujo del proceso padre
  return child_pid;
 else
 {  //Flujo del proceso hijo
  execvp (program, arg_list);  //Crea un nuevo programa de acuerdo a los parámetros enviados
  //Si el programa se crea correctamente, se termina le ejecución del proceso en este punto
  //En caso de error al crear el programa, la ejecución continua
  fprintf (stderr, "ocurrio un error al ejecutar execvp(...)\n"); 
  abort ();
 }
}

int main ()
{
  printf("Sandoval Miramontes Joaquín\n");
  //Argumentos del programa
  char* arg_list[] = {
   "ls",  //Comando a ejecutar
   "-l",  //Argumentos
   "/",
   NULL   //Importante agregar este apuntador NULL para indicar el final del arreglo
  };

  //Invocación a la función spawn() con el comando ls
  spawn ("ls", arg_list);
  printf ("Termina el proceso padre\n"); //Final del proceso padre
  return 0;
}
