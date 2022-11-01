#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
//Sandoval Miramontes Joaquín
int main()
{
	printf("Sandoval Miramontes Joaquín\n");
  int arg_wait;	//Variable donde se guarda el estatus del la función wait
  printf( "Iniciando proceso con pid %d\n", getpid() );
  printf( "Llamando a wait\n" );
  int retorno_wait = wait( &arg_wait ); //Invocación a función wait
  //Como no hay proceso hijo, wait() regresa -1
  //Por lo mismo, el estatus es 0
  printf( "Despues de wait\n" );
  printf( "El valor &arg_wait=%p\n",&arg_wait );
  printf( "La variable arg_wait=%d\n",arg_wait );
  printf( "La variable retorno_wait=%d\n",retorno_wait );
  //Comprobamos el estatus con WIFEXITED
  //Regresa TRUE porque el hijo terminó correctamente
  if (WIFEXITED(arg_wait)){
  	printf("WIFEXITED\n");
  }
  return 0;
}
