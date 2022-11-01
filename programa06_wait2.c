#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


//Sandoval Miramontes Joaquín
int main()
{
  printf("Sandoval Miramontes Joaquín\n");
  int retorno_fork;
  int arg_wait;
  int pid = getpid();   //Regresa el PID del proceso actual (proceso padre)
  printf( "Iniciando proceso con pid %d\n", pid );
  printf( "Llamando a fork\n" );
  retorno_fork = fork(); //Se crea un subproceso y se guarda la salida
  if( retorno_fork != 0 )
  {
    //Secuencia del proceso padre
    printf( "Proceso padre, la variable retorno_fork=%d\n",retorno_fork );
    printf( "Proceso padre, llamando a wait\n" );
    //Se espera a que el proceso hijo termine
    //Regresa el PID del proceso hijo que esperó
    //Almacena en arg_wait el status del proceso hijo
    int retorno_wait =  wait( &arg_wait );
    printf( "Proceso padre, despues de wait\n" );
    printf( "Proceso padre, el valor &arg_wait=%p\n",&arg_wait );
    printf( "Proceso padre, la variable arg_wait=%d\n",arg_wait );
    //Revisamos si el proceso hijo terminó de manera correcta
    printf( "Proceso padre, WIFEXITED(arg_wait)=%d\n",WIFEXITED(arg_wait) );
    //Revisamos el status que regresa el proceso hijo con exit() o return
    printf( "Proceso padre, WEXITSTATUS(arg_wait) codigo de salida del hijo=%d\n",WEXITSTATUS(arg_wait) );
    printf( "Proceso padre, la variable retorno_wait=%d\n",retorno_wait );
    printf( "EXIT_SUCCESS en el proceso padre=%d\n", EXIT_SUCCESS );
    //Terminamos el proceso padre
    exit( EXIT_SUCCESS );
  }
  else
  {
    printf( "Proceso hijo, el pid es %d\n", getpid() );
    printf( "Proceso hijo, a dormir 10 seg\n" );
    //Se duerme el proceso hijo por 10 segundos
    sleep( 10 );
    printf( "Proceso hijo, despierta\n" );
    printf( "proceso hijo=%d\n", 2 );
    //Terminamos el proceso hijo con el status mandado en exit()
    exit( 2 );
  }
}
