/******************************************************************************
Disciplina: Algoritmos | 1° Periodo
Nome: Maria Fernanda Leonel Bertelli
Data: 11/12/2022
Enunciado: Trabalho Final - Jogo de caça ao submarino

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Variaveis globais
int lin_sub = 0, col_sub = 0; //linha e coluna do submarino
char oceano[3][3] = {{'*', '*', '*'},{'*', '*', '*'},{'*', '*', '*'}}; 

//Função que vai mostrar o oceano na tela antes da primeira jogada
void jogada_0() {
    
    int i = 0, j = 0;
    
    printf("\n\n~ AQUI ESTA O OCEANO ~");
    printf("\n");
    printf("   0 1 2\n");
    for (i = 0; i < 3; i++) {
    		printf(" %d ", i);
        for (j = 0; j < 3; j++) {
            printf(". ");
        }
        printf("\n");
    }
}

//Função para determinar a posição do submarino
void pos_sub() {
    
	lin_sub = rand() % 3;
	col_sub = rand() % 3;
	oceano[lin_sub][col_sub] = 'S';
}

int main()
{
    srand(time(NULL));
    
    //Declaração de variáveis
    int i, j, //contador de linha (i) e coluna (j)
    subi, subj, //Linha do submarino e coluna dele
    lin_cour, col_cour, //Linha do couraçado e coluna dele
    achou = 0, n; //quando linhas e colunas do submarino e couraçado estiverem iguais
    char res; //S ou N -> Se o usuario deseja jogar de novo
    
    printf("______________________________________________|JOGO DE CAÇA AO SUBMARINO|______________________________________________");
    printf("\n\n Neste jogo, você é o Couracado -> um navio de guerra que deve destruir o Submarino.   E, claro, o Submarino tambem");
    printf("\n tem o objetivo de destruir você! O couracado e o submarino tem suas posições.        O unico jeito de uma embarcacao");
    printf("\n cumprir sua missão é estar sob a mesma posicao do seu inimigo!      Entao, escolha bem as suas coordenadas (linha e ");
    printf("\n coluna - entre 0 a 2).      Para digitar sua posicao, escreva dois numeros separados por apenas um espaço em branco.");
    printf("\n Por exemplo = POSIÇÃO DO COURAÇADO: 0 2.    Voce ja estará pronto para o ataque! Lembre-se que se voce nao encontrar");
    printf("\n o Submarino, ele fará um contra-ataque!   Outra coisa também: se você deseja jogar de novo, digite 's' ou 'S' = Sim.");
    printf("\n Caso contrário, é só digitar qualquer caracter - numero ou letra - para significar que você não quer.");
    printf("\n______________________________________________________|Boa sorte|____________________________________________________");
    
    do{
        
        jogada_0(); 
        
        do {
            
            pos_sub();
            
            do {
                printf("\n- - - - - - - - - - - - -    - - - - - - - - - - - -   - - - - - - - - - - - - - -    - - - - - - - - - -");
                printf("\nPOSIÇÃO DO COURAÇADO: ");
                scanf("%d %d", &lin_cour, &col_cour);
                if (lin_cour > 2 || col_cour > 2) {
                    printf("\nEi! Você não leu a introdução? Precisa ser entre 0 a 2!");
                }
                
                oceano[lin_cour][col_cour] = 'C';
                
            } while (lin_cour > 2 || col_cour > 2);
        
            //Resultado da primeira jogada
            printf("   0 1 2\n");
            for (i = 0; i < 3; i++) {
                printf(" %d ", i);
                for (j = 0; j < 3; j++) {
                    printf("%c ", oceano[i][j]);
                }
                printf("\n");
            }
            
            if (lin_sub == lin_cour && col_sub == col_cour) {
                printf("\nParabens!!! Você destruiu o Submarino de primeira!\a"); 
                achou++;
                
            } else {
                printf("\nQue pena, você não encontrou o Submarino... ");
                printf("\nPrepare-se para o ataque dele!\n");
                
                oceano[lin_sub][col_sub] = '*'; 
                pos_sub();
                
                //Mostrando de novo o oceano com o ataque do submarino
                printf("   0 1 2\n");
                for (i = 0; i < 3; i++) {
                    printf(" %d ", i);
                    for (j = 0; j < 3; j++) {
                        printf("%c ", oceano[i][j]);
                    }
                    
                    printf("\n");
                }
                
                if (lin_sub == lin_cour && col_sub == col_cour) { 
                    printf("\n\n        |||||||||             GAME OVER           |||||||||        ");
                    printf("\n                   ___ O submarino te destruiu ___                ");
                    achou++;
                }
                
                if (achou == 0) { //Se ninguem acertou a posição de ninguém, ele zera a matriz e continua nesse loop até ir 
                
                printf("\nQue sorte!  O submarino nao te encontrou tambem :) \nSerá que você é capaz de vencer? \n\nDirecione novamente a sua embarcaçao!\a");
                    
    				for(i = 0; i < 3; i++){
    					for(j = 0; j < 3; j++){
    						oceano[i][j] = '*'; 
    					}
    					printf("\n");
    				}		
                }
            }
        } while (achou == 0);
        
        printf("\n\nVoce deseja jogar de novo?\n"); 
		scanf(" %c", &res);
        
    } while (res == 's' || res == 'S');

}














