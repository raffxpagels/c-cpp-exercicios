/* 
* Programa básico em C/C++
* Calcula a média do aluno
* Conteúdo: entrada/saída, variáveis, if/else
*/

#include <stdio.h>
#include <locale.h>

float nota1, nota2, media;

int main (){
	setlocale(LC_ALL, "PORTUGUESE");

	printf ("\nEntre com a primeira nota: ");
	scanf ("%f", &nota1);
	printf ("\nEntre com a segunda nota: ");
	scanf ("%f", &nota2);
	media = (nota1 + nota2) / 2;
	printf ("\nA média final é de: %.2f", media);
	
	if (media <= 5.9)
		printf ("\nVocê foi reprovado.");
	else
		printf ("\nVocê foi aprovado!");
		
	return 0;	
}


