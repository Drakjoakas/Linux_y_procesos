#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//Sandoval Miramontes Joaquín

int main()
{
  printf("Sandoval Miramontes Joaquin\n");
  int retorno_fork;
  int arg_wait;
  int pid = getpid();
  printf( "Iniciando proceso con pid %d\n", pid );
  printf( "Llamando a fork la primera vez\n" );
  //Se crea el primer hijo con la funci´on fork()
  retorno_fork = fork();
  if( retorno_fork != 0 )
  {
    //Secuencia del padre
    printf( "Proceso padre, la variable retorno_fork la primera vez=%d\n",retorno_fork );
    printf( "Llamando a fork la segunda vez\n" );
    //se crea un segundo hijo con la función fork()
    retorno_fork = fork();
    if( retorno_fork != 0 )
    {
      //Secuencia del padre
      printf( "Proceso padre, llamando a wait\n" );
      /*
        El padre se pone en espera a la terminación de ALGUNO de sus hijos

        Debido a que se usa wait() y no waitpid(), el padre esperará hasta que
        cualquiera de sus hijos despierte, sin importar cual.

        En la primera ejecución, al terminar primero el hijo 1, el padre reanuda
        su ejecución después de éste.

        En la segunda ejecución, el hijo 1 duerme 20 s, 10 s más que el hijo 2,
        por lo que el hijo 2 termina primero y el padre reanuda después del 
        hijo 2 en lugar de después del hijo 1
      */
      int retorno_wait =  wait( &arg_wait );
      printf( "Proceso padre, despues de wait\n" );
      printf( "Proceso padre, el valor &arg_wait=%p\n",&arg_wait );
      printf( "Proceso padre, la variable arg_wait=%d\n",arg_wait );
      printf( "Proceso padre, la variable retorno_wait=%d\n",retorno_wait );
      printf( "EXIT_SUCCESS en el proceso padre=%d\n", EXIT_SUCCESS );
      //Revisamos que la terminación del hijo haya sido correcta
      //(Solo por precaución)
      if (WIFEXITED(arg_wait)){
        //WIFEXITED regresa 1 porque el hijo terminó correctamente
        printf( "Valor de WIFEXITED()=%d\n",WIFEXITED(arg_wait));
        //WEXITSTATUS regresa 0 porque el hijo, al terminar, regresa
        // EXIT_SUCCESS, cuyo valor es 0
        printf( "Valor de WEXITSTATUS()=%d\n",WEXITSTATUS(arg_wait));
      }
      //Padre termina su ejecución con éxito EXIT_SUCCESS
      exit( EXIT_SUCCESS );
    }
    else
    {
      //secuencia del hijo 2
      printf( "Proceso hijo 2, el pid es %d\n", getpid() );
      printf( "Proceso hijo 2, a dormir 10 seg\n" );
      //Hijo 2 see duerme 10 s
      sleep( 10 );
      printf( "Proceso hijo 2, despierta\n" );
      printf( "EXIT_SUCCESS en el proceso hijo 2=%d\n", EXIT_SUCCESS );
      //El hijo 2 termina su ejecución con éxito EXIT_SUCCESS
      exit( EXIT_SUCCESS );
    }
  }
  else
  {
    //Secuencia del hijo 1
    printf( "Proceso hijo 1, el pid es %d\n", getpid() );
    printf( "Proceso hijo 1, a dormir 10 seg\n" );
    //Hijo 1 se duerme primero 10 s
    //En la segunda ejecución se duerme 20 s
    sleep( 10 );
    printf( "Proceso hijo 1, despierta\n" );
    printf( "EXIT_SUCCESS en el proceso hijo 1=%d\n", EXIT_SUCCESS );
    //El hijo 1 termina su ejecución con éxito EXIT_SUCCESS
    exit( EXIT_SUCCESS );
  }
}
