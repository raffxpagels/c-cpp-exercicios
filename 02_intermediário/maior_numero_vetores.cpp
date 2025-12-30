/*
* Programa em C/C++
* Identifica o maior número do vetor
* Conteúdo: Vetores e laço de repetição
*/

#include <stdio.h>
#include <locale.h>

int main() {
    int nmr[10];
    int maior_nmr, indice_maior;
    setlocale (LC_ALL, "PORTUGUESE);
        
    	for (int i = 0; i < 10; i++) {
        	do {
            	printf("Entre com o número positivo: ");
            	scanf("%d", &nmr[i]);
            	if (nmr[i] < 0)
                	printf("Número invalido! Digite apenas positivos.\n");
        	} while (nmr[i] < 0);
    	}

   	maior_nmr = nmr[0];
    indice_maior = 0;

    	for (int i = 1; i < 10; i++) {
        	if (nmr[i] > maior_nmr) {
            	maior_nmr = nmr[i];
            	indice_maior = i;
        	}
    	}

    printf("\nO maior número digitado é %d no indice %d.\n", maior_nmr, indice_maior);

    return 0;
}


