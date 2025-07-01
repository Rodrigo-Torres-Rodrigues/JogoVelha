//Tempo gasto: 4 horas e 0 minutos

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void velha3x3(char board_velha3x3[3][3]){
    int col, linha;

    printf("\nEsta é a situação do jogo:\n");
    printf("   1   2   3");
    for(col = 0; col <= 2; col++){
        printf("\n%d|", col + 1);
        for(linha = 0; linha <= 2; linha++){
            printf(" %c |", board_velha3x3[col][linha]);
        }
    }
}

int verifyWin(char board[3][3], char player){
    int i;
    for(i = 0; i < 3; i++){
        if(board[i][0] ==player && board[i][1] == player && board[i][2] == player){
            return 1;
        }
        if(board[0][i] ==player && board[1][i] == player && board[2][i] == player){
            return 1;
        }
        if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X'){
            return 0;
        }
        if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X'){
            return 0;
        }
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return 1;
    }
    if(board[2][0] == player && board[1][1] == player && board[0][2] == player){
        return 1;
    }
    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
        return 0;
    }
    if(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X'){
        return 0;
    }
    return 2;
}

void main(){
    char player;
    int coordenates, round, aiCord1, aiCord2;
    bool continuar = true;
    char board[3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}}; //uma strign é quando coloamos um char com um array, se for sem os [], então é apeanas um caractere

    srand(time(0));

    printf("Escolha qual caractere você quer ser:\n");
    scanf("%c", &player);

    printf("\e[2J\e[H");

    while(round < 9){
        if(round % 2 == 1){
            velha3x3(board);
            printf("\nVocê é o '%c'.\nDigite as coordenadas (Linha, depois coluna, sem espaço):", player);
            scanf("%d", &coordenates);

            if(board[(coordenates/10) - 1][(coordenates % 10) - 1] == player || board[(coordenates/10) - 1][(coordenates % 10) - 1] == 'X'){
                printf("\e[2J\e[H");
                printf("Você digitou uma coordenada em que já há um  jogador!!!!!!");
                
            }else{
                board[(coordenates/10) - 1][(coordenates % 10) - 1] = player;
                round++;
                printf("\e[2J\e[H");
            }

        }else{
            aiCord1 = rand() % 3;
            aiCord2 = rand() % 3;
            if(board[aiCord1][aiCord2] != 'X' && board[aiCord1][aiCord2] != player){
                board[aiCord1][aiCord2] = 'X';
                round++;
            }
        }
        if(verifyWin(board, player) == 1){
            printf("Você venceu!!!!");
            round = 9;
        }
        if(verifyWin(board,player) == 0){
            printf("Você perdeu!!!!");
            round = 9;
        }
    }
    velha3x3(board);
}