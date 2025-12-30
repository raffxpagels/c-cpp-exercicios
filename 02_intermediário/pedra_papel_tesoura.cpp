#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>

int opcao_usuario, nmr_maq, empate, vitoria, derrota, partida;

main () {
	setlocale(LC_ALL, "PORTUGUESE");
	
	printf("Bem-vindo ao jogo 'Pedra, Papel e Tesoura'.\n");
	printf("Escolha algum número e vamos jogar!\n");

	do {
		srand(time(NULL));
		nmr_maq = 1 + rand() % 3;

		printf("\n\n1 - Pedra\n");
		printf("2 - Papel\n");
		printf("3 - Tesoura\n\n");
		scanf("%i", &opcao_usuario);

		switch(opcao_usuario) {

			case 1:
				printf("Você escolheu 'Pedra'.\n");

				if (nmr_maq == opcao_usuario) {
					partida++;
					empate++;
					printf("Eu também escolhi 'Pedra'. Deu empate!\n");
				} else {
					if (nmr_maq == 2) {
						partida++;
						derrota++;
						printf("Eu escolhi a opção %i, 'Papel'. Você perdeu!\n", nmr_maq);
					} else {
						if (nmr_maq == 3) {
							partida++;
							vitoria++;
							printf("Eu escolhi a opção %i, 'Tesoura'. Você ganhou!\n", nmr_maq);
						}
					}
				}
				break;

			case 2:
				printf("Você escolheu 'Papel'.\n");

				if (nmr_maq == 1) {
					partida++;
					vitoria++;
					printf("Eu escolhi a opção %i, 'Pedra'. Você ganhou!\n", nmr_maq);
				} else {
					if (nmr_maq == opcao_usuario) {
						partida++;
						empate++;
						printf("Eu também escolhi 'Papel'. Deu empate!\n");
					} else {
						if (nmr_maq == 3) {
							partida++;
							derrota++;
							printf("Eu escolhi a opção %i, 'Tesoura'. Você perdeu!\n", nmr_maq);
						}
					}
				}
				break;

			case 3:
				printf("Você escolheu 'Tesoura'.\n");

				if (nmr_maq == 1) {
					partida++;
					derrota++;
					printf("Eu escolhi a opção %i, 'Pedra'. Você perdeu!\n", nmr_maq);
				} else {
					if (nmr_maq == 2) {
						partida++;
						vitoria++;
						printf("Eu escolhi a opção %i, 'Papel'. Você ganhou!\n", nmr_maq);
					} else {
						if (nmr_maq == opcao_usuario) {
							partida++;
							empate++;
							printf("Eu também escolhi 'Tesoura'. Deu empate!\n");
						}
					}
				}
				break;

			default:
				printf("Escolha uma opção válida!\n");
				break;
		}

		printf("\nDeseja jogar outra partida?\n");
		printf("Sim - S | Não - N: \n");

	} while (toupper(getche()) == 'S');

	printf("\n\n\n\n|     ESTATÍSTICAS     |\n\n");
	printf ("Número total de partidas: %i\n", partida);
	printf("Número de vitórias: %i\n", vitoria);
	printf("Número de derrotas: %i\n", derrota);
	printf("Número de empates: %i\n", empate);
}

