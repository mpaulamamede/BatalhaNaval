#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINMAX 8
#define COLMAX 8
#define CHARMAX 20

struct Defensor
{
    char Nome[CHARMAX];
    int Gabarito[LINMAX][COLMAX];
    int acertos;
    int tamStr;
};

struct Atacante
{
    char Nome[CHARMAX];
    int Tiros[LINMAX][COLMAX];
    int qtdTiros;
    int tamStr;
};

int main(){
    struct Defensor defensor = {0};
    struct Atacante atacante = {0};
    atacante.qtdTiros = 5;
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    
    printf("- Defensor, digite seu nome: ");
    fflush(stdin);
    fgets(defensor.Nome, CHARMAX, stdin);

    printf("- Atacante, digite seu nome: ");
    fflush(stdin);
    fgets(atacante.Nome, CHARMAX, stdin);

    defensor.tamStr = strlen(defensor.Nome);
    atacante.tamStr = strlen(atacante.Nome);

    defensor.Nome[defensor.tamStr-1] = '\0';
    atacante.Nome[atacante.tamStr-1] = '\0';

    printf("\n");
    printf("REGRAS DO JOGO\n");
    printf("1: O defensor escolhe tres posicoes para colocar seus barcos.\n");
    printf("2: O atacante inicialmente tem 5 tentativas para acertar a posicao dos barcos e afunda-los.\n");
    printf("3: Quando o atacante erra, ele perde uma tentativa. Quando acerta, nao gasta a tentativa e ganha outra.\n");
    printf("4: O jogo acaba quando o atacante acerta as tres posicoes dos barcos ou fica sem tentativas. \n");
    printf("\n");
    printf("TABULEIRO\n");
    for(i=0; i<LINMAX; i++){
        for(j=0; j<COLMAX; j++){
            printf("%d ", defensor.Gabarito[i][j]); 
        }

        printf("\n");
    }
    printf("\n");
    printf("LEGENDA\n");
    printf("9 - Navio afundado\n5 - Tiro na agua\n");
    printf("\n");

    for(i=0; i<3; i++){
        do{
        printf("- %s, digite as coordenadas x e y do barco numero %d (entre 0 e 7): ", defensor.Nome, i+1);
        scanf("%d %d", &x, &y);        
        }while(x<0 || y<0 || x>7 || y>7);
        defensor.Gabarito[x][y] = 1;
    }
    printf("\n");

    /*for(i=0; i<LINMAX; i++){
        for(j=0; j<COLMAX; j++){
            printf("%d ", defensor.Gabarito[i][j]); 
        }

        printf("\n");
    }*/

    printf("- Que a batalha comece!\n");
    printf("\n");

    while(atacante.qtdTiros>0 && defensor.acertos<3){
        do{
            printf("- %s, digite as coordenadas x e y de ataque (entre 0 e 7):", atacante.Nome);
            scanf("%d %d", &x, &y);
        }while(x<0 || y<0 || x>7 || y>7);
        printf("\n");

        atacante.qtdTiros--;

        if(defensor.Gabarito[x][y] == 1 && atacante.Tiros[x][y] == 0){
            printf("- Acertou!\n");
            atacante.Tiros[x][y] = 9;   
            atacante.qtdTiros += 2;         
            defensor.acertos++;

            if(defensor.acertos==3 || atacante.qtdTiros==0){
                break;
            }else{
                printf("Tentativas restantes: %d\n", atacante.qtdTiros);
            }
            printf("\n");            
        }else if(defensor.Gabarito[x][y] == 1 && atacante.Tiros[x][y] == 9){
            printf("- Voce ja acertou nessa posicao! Tente novamente.\n");
            atacante.qtdTiros++;
            printf("Tentativas restantes: %d\n", atacante.qtdTiros);  
            printf("\n");
        }else if(defensor.Gabarito[x][y] == 0 && atacante.Tiros[x][y] == 0){
            printf("- Errou!\n");
            atacante.Tiros[x][y] = 5; 

            if(defensor.acertos==3 || atacante.qtdTiros==0){
                break;
            }else{
                printf("Tentativas restantes: %d\n", atacante.qtdTiros);
            }                  
            printf("\n");
        }else if(defensor.Gabarito[x][y] == 0 && atacante.Tiros[x][y] == 5){
            printf("- Voce ja errou nessa posicao! Tente novamente.\n");
            atacante.qtdTiros++;
            printf("Tentativas restantes: %d\n", atacante.qtdTiros); 
            printf("\n");          
        }

        for(i=0; i<LINMAX; i++){
            for(j=0; j<COLMAX; j++){
                printf("%d ", atacante.Tiros[i][j]); 
            }

            printf("\n");
        }
        printf("\n");
    }

    if(defensor.acertos==3){
        printf("- %s ganhou!\n", atacante.Nome);
    }else{
        printf("- %s ganhou!\n", defensor.Nome);
    }
    printf("\n");

    for(i=0; i<LINMAX; i++){
        for(j=0; j<COLMAX; j++){
            printf("%d ", atacante.Tiros[i][j]); 
        }

        printf("\n");
    }
    printf("\n");

    return 0;
}






