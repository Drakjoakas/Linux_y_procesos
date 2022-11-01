#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

//Sandoval Miramontes Joaquín
/*
@param char* program Comando a ejecutar por execvp
@param char** arg_list Argumentos del comando a ejecutar

Función que crea un proceso hijo con la función fork() y ejecuta un comando con execvp().

La función se encarga de crear el proceso hijo y ejecutar el programa, así como de manejar
la ejecución no exitosa.

*/
int spawn (char* program, char** arg_list)
{
  pid_t child_pid;
  /* Se crea un proceso hijo */
  child_pid = fork ();
  if (child_pid != 0) /* Secuencia del proceso padre */
    return child_pid;
  else {
    //Secuencia del proceso hijo
    
    printf("soy el hijo, lanzo el ls y termino\n");
    //Se ejecuta el comando con la función execvp()
    execvp (program, arg_list);
    /* En caso de error en execvp(), continua la ejecución y se indica el error */
    fprintf (stderr, "an error occurred in execvp\n");
    abort ();
  }
}

int main ()
{
  printf("Sandoval Miramontes Joaquin\n");
  int child_status=1;
  printf("1.child_status=%d\n",child_status);
  /* Lista de argumentos del comando a ejecutar */
  char* arg_list[] = {
    "ls", /* Comando a ejecutar */
    "-l",
    "/",
    NULL /* IMPORTANTE para indicar que el arreglo termina */
  };

  /* Se crea el proceso hijo que ejecute el comando ls
     Se ignora el PID del hijo */
  spawn ("ls", arg_list);
  printf("soy el padre, voy a esperar a que el hijo termine\n");
  /* Se espera a que termine la ejecución del hijo.
     Se guarda el status de salida del hijo en child_status */
  wait (&child_status);
  //En caso de una salida exitosa del hijo, se entra en el if
  if (WIFEXITED (child_status)){
    printf("2.child_status=%d\n",child_status);
    //se muestra el status de salida del hijo con WEXITSTATUS
    printf ("the child process exited normally, with exit code %d\n", WEXITSTATUS (child_status));
  }
  else
    printf ("the child process exited abnormally\n");
  return 0;
}

