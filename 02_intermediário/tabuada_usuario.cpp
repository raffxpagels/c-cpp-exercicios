/*
 * Programa em C/C++
 * Exibe a tabuada de um número escolhido pelo usuário (1 a 10)
 * Conteúdo: entrada de dados, laço de repetição for
 */

#include <stdio.h>
#include <locale.h>

int numero, contador;

int main (){
    setlocale(LC_ALL, "PORTUGUESE");

    printf("Digite um número para ver a tabuada: ");
    scanf("%d", &numero);

    	if (numero < 1) {
        	printf("Número inválido.\n");
        	return 0;
    	}

    printf("\nTabuada do %d:\n\n", numero);

    	for (contador = 1; contador <= 10; contador++){
        	printf("%d x %d = %d\n", numero, contador, numero * contador);
    	}

    return 0;
}


