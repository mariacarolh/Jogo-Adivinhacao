#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

   int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;

    int chute;
    double pontos = 1000;

    int i;
    int nivel;
    int numerotentativas;

    printf("Selecione um nivel de dificuldade\n");
    printf("1 (Facil) | 2 (Medio) 3 (Dificil)\n");
    scanf("%d", &nivel);

    switch(nivel){
        case 1:
            numerotentativas = 15;
            break;

        case 2:
            numerotentativas = 10;
            break;

        case 3:
            numerotentativas = 5;
            break;
    }

    printf("- - - - - - - - - - \n");
    printf("JOGO DE ADIVINHACAO \n");
    printf("- - - - - - - - - - \n");
    
    for (i = 1; i <= numerotentativas; i++){

        printf("Tentativa %d de %d\n", i, numerotentativas);
        printf("Chute um numero: \n");
        scanf("%d", &chute);

        if (chute < 0){
            printf("Sao validos apenas numeros POSITIVOS, tente novamente!\n");
            i--;
            continue;
        }

        if (chute > numerosecreto){
            printf("%d e maior que o numero secreto.\n", chute);
        }
        else if(chute < numerosecreto){
            printf("%d e menor que o numero secreto.\n", chute);
        }

        double pontosperdidos = abs(chute - numerosecreto) / (double) 2;
        pontos = pontos - pontosperdidos;

        if (chute == numerosecreto){
            printf("Parabens, voce acertou na tentativa %d !! O numero secreto e: %d\n", i, numerosecreto);
            printf("Pontuacao %.1f: ", pontos);
            break;
        }

    }  
        if (i > numerotentativas){
            printf("Nao foi dessa vez! O numero secreto era: %d", numerosecreto);
        }
}
