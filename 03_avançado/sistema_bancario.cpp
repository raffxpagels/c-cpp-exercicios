#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

struct regConta {
    float depositoConta;
    float saqueConta;
    float saldoConta;
};

int main() {
    struct regConta conta = {0, 0, 0};
    int vezes_deposito = 0, vezes_saque = 0;
    int opcao, saldo, senha = 1234, tentativa, flag;
    float valor_deposito, valor_saque;

    setlocale(LC_ALL, "PORTUGUESE");

    do {
        system("cls");
        printf("MENU Banco Pagels\n\n");
        printf("Selecione alguma das opcoes abaixo:\n");
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Ver saldo\n");
        printf("4 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                if (vezes_deposito == 4) {
                    printf("\nVoce realizou diversas acoes em sua conta\ne sera desligado por motivos de seguranca.\n");
                    system("pause");
                    break;
                }

                do {
                    flag = 0;

                    printf("\nDigite a quantia que deseja depositar:\n");
                    scanf("%f", &valor_deposito);

                    while (valor_deposito == 0) {
                        printf("Por favor, insira um valor que nao seja zero.\n");
                        scanf("%f", &valor_deposito);
                    }

                    printf("\nDigite a senha de quatro digitos: ");
                    scanf("%d", &tentativa);

                    if (tentativa == senha) {
                        flag = 1;
                    }

                    if (flag == 0) {
                        printf("\nSenha invalida. Tente novamente.\n");
                        system("pause");
                        break;
                    }

                    conta.depositoConta += valor_deposito;
                    conta.saldoConta = conta.depositoConta - conta.saqueConta;

                    printf("O valor de %.2f foi depositado.\n", valor_deposito);
                    printf("Deseja depositar outro valor? (S/N)\n");
                    fflush(stdin);

                    vezes_deposito++;

                } while (toupper(getche()) == 'S');

                break;

            case 2:
                if (vezes_saque > 2) {
                    printf("\nSeu saque foi bloqueado por motivos de seguranca.\n");
                    system("pause");
                    break;
                }

                do {
                    vezes_saque++;

                    printf("\nInsira o valor do saque: ");
                    scanf("%f", &valor_saque);

                    if (valor_saque > conta.saldoConta) {
                        printf("\nSaldo insuficiente para saque.\n");
                        system("pause");
                        break;
                    }

                    while (valor_saque == 0) {
                        printf("Por favor, insira um valor que nao seja zero.\n");
                        scanf("%f", &valor_saque);
                    }

                    printf("\nDigite a senha de quatro digitos: ");
                    scanf("%d", &tentativa);

                    if (tentativa != senha) {
                        printf("\nSenha invalida. Tente novamente.\n");
                        system("pause");
                        break;
                    }

                    conta.saqueConta += valor_saque;
                    conta.saldoConta = conta.depositoConta - conta.saqueConta;

                    printf("\nO saque foi feito com sucesso.\n");
                    printf("Gostaria de realizar outro saque? (S/N)\n");
                    fflush(stdin);

                } while (toupper(getche()) == 'S');

                break;

            case 3:
                printf("O saldo atual e de: %.2f\n", conta.saldoConta);
                system("pause");
                break;

            case 4:
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida. Digite um numero entre 1 e 4.\n");
                system("pause");
                break;
        }

    } while (opcao != 4);

    return 0;
}

