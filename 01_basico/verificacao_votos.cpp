/*
 * Programa básico em C/C++
 * Verifica a obrigatoriedade do voto com base na idade
 * Conteúdos: if/else, operadores lógicos, entrada de dados
 */

#include <stdio.h>
#include <locale.h>

int idade;

int main() {
    setlocale(LC_ALL, "Portuguese");

    printf("Informe a sua idade: ");
    scanf("%d", &idade);

    	if (idade <= 15) {
        	printf("\nNão vota.");
    	} 
    	else if (idade == 16 || idade == 17 || idade > 70) {
        	printf("\nVoto facultativo.");
    	} 
    	else {
        	printf("\nVoto obrigatório!");
    	}

    printf("\n\nO voto é um direito do cidadão! Escolha bem nas eleições.");

    return 0;
}


