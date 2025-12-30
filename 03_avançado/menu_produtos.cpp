/*
 * Programa em C/C++
 * Programa feito para controle de produtos de uma confraternização
 * Conteúdos: struct, switch-if, laços de repetição
*/ 

#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct regProduto {
    char nomeProduto[50];
    int idProduto;
    float precoProduto;
    int qntdProduto;    
};

regProduto produto[15];
int flag, contador, i, codigo, opcao;
char resposta;

int main (){
    setlocale (LC_ALL, "PORTUGUESE");
    i = 0;
    
    do {
        system ("cls");
        printf ("Confraternização | MENU\n\n");
        
        printf ("1 - Incluir um produto\n");
        printf ("2 - Alterar um produto\n");
        printf ("3 - Excluir um produto\n");
        printf ("4 - Mostrar produtos\n");
        printf ("5 - Sair\n");
        scanf ("%i", &opcao);
        
        switch (opcao){
            
            case 1:
                
                if (i >= 15){
                    printf ("\nA lista de produtos está cheia. Exclua algum para inserir outro!\n");
                    system ("pause");
                    break;
                }
                
                do {
            
                    printf ("\nDigite o nome do produto: \n");
                    fflush(stdin);
                    gets (produto[i].nomeProduto);

                    do {
                        printf ("Digite o ID do produto: \n");
                        fflush(stdin);
                        scanf ("%i", &produto[i].idProduto);
                        
                        if (produto[i].idProduto == 0){
                            printf ("Por favor, insira um número que não seja nulo (zero).");
                        }
                        
                    } while (produto[i].idProduto == 0);
                    
                    printf ("Digite o preço do produto: \n");
                    fflush(stdin);
                    scanf ("%f", &produto[i].precoProduto);
                    printf ("Digite a quantidade do produto: \n");
                    fflush(stdin);
                    scanf ("%i", &produto[i].qntdProduto);
                    
                    printf ("Gostaria de acrescentar outro produto?\n S | N: \n");
                    fflush(stdin);
                    i++;

                } while (toupper(getche()) == 'S');
            break;
                
            case 2:
                
                flag = 0;
                printf ("Informe o ID do produto: ");
                scanf ("%i", &codigo);
                
                for (contador = 0; contador < i; contador++){

                    if (codigo == produto[contador].idProduto){
                        flag = 1;
                        printf ("\nDigite o nome do produto: \n");
                        fflush(stdin);
                        gets (produto[contador].nomeProduto);
                        printf ("Digite o preço do produto: \n");
                        scanf ("%f", &produto[contador].precoProduto);
                        printf ("Digite a quantidade do produto: \n");
                        scanf ("%d", &produto[contador].qntdProduto);
                        printf ("Alterado com sucesso.");
						system ("pause");
                    }
                }   
				
                if (flag == 0){
                    printf ("\nProduto não encontrado. Tente novamente!");
                    system ("pause");
                }
            break;
                        
            case 3:
                
                flag = 0;
                printf ("\nDigite o ID do produto que gostaria de excluir:");
                scanf ("%d", &codigo);
                
                for (contador = 0; contador < i; contador++){
                    
                    if (codigo == produto[contador].idProduto){
                        
                        flag = 1;
                        printf ("\nNome do produto: %s", produto[contador].nomeProduto);
                        printf ("\nID do produto: %d", produto[contador].idProduto);
                        printf ("\nPreço do produto: %.2f", produto[contador].precoProduto);
                        printf ("\nQuantidade do produto: %d", produto[contador].qntdProduto);
                        
                        printf ("\nDeseja mesmo excluir esse ítem?\n S | N: ");
                        scanf (" %c", &resposta);
                        
                        if (toupper(resposta) == 'S'){
                            strcpy (produto[contador].nomeProduto, "Excluído");
                            produto[contador].idProduto = 0;
                            produto[contador].precoProduto = 0;
                            produto[contador].qntdProduto = 0;
                            
                            printf ("O produto foi excluído com sucesso.");
                            system ("pause");
                            break;
                        }
                    }
                }
                
                if (flag == 0){
                    printf ("\nO produto não foi encontrado. Tente novamente.");
                    system ("pause");
                }
            break;
            
            case 4:
                printf ("- - - - PRODUTOS CADASTRADOS - - - - \n\n");
                printf ("\nID |   NOME        |       PRECO   |    QUANTIDADE   |");
                
                for (contador = 0; contador < i; contador++){
                    if (produto[contador].idProduto != 0){
                        printf ("\n%-4i", produto[contador].idProduto);
                        printf ("%-20s", produto[contador].nomeProduto);
                        printf ("%8.2f", produto[contador].precoProduto);
                        printf ("\t%3i", produto[contador].qntdProduto);
                    }    
                }
                printf ("\n-----------------------------------------------\n\n");
                system ("pause");
            break;
                
            case 5:
                break;    
            
            default:
                printf ("Opção inválida. Digite uma opção entre 1 e 5.");
                system ("pause");
            break;
        }        
    } while (opcao != 5);
}


