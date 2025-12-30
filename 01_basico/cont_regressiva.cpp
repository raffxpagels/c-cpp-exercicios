/*
 * Programa básico em C/C++
 * Imprime os números de 100 até 0 utilizando laço for
 */

#include <stdio.h>
#include <locale.h>

int contador;

int main (){
	setlocale (LC_ALL, "PORTUGUESE");
	
	printf ("Os números de trás para frente são: \n");
	
	for (contador = 100; contador >= 0; contador--){
		printf ("%d\n", contador);
	}
	return 0;
}
