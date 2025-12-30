/*
* Programa básico em C/C++
* Calcula a soma de todos os números de 1 a 100
* Conteúdo: for, variáveis, acumulador
*/
 
#include <stdio.h>
#include <locale.h>

int contador, soma;

int main (){
	soma = 0;
	setlocale (LC_ALL, "PORTUGUESE");
	
	printf ("A soma dos números de 1 a 100 é de: \n\n");
	
		for (contador = 1; contador <= 100; contador++){
			printf ("%d + %d = %d\n", contador, soma, soma + contador);
			soma += contador;			
		}
	printf ("O resultado final é de %d", soma);
	return 0;	
}

