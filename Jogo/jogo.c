#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMERO_TENTATIVAS 11 

int main()
{
   int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;

    int chute;
    double pontos = 1000;
    
    /* Use o codigo assim se quiser determinar o NUMERO SECRETO
    int numerosecreto;
    printf("Determine o numero secreto: \n");
    scanf("%d", &numerosecreto);
    system("cls");
    printf("Tela limpa!\n"); */

    printf("- - - - - - - - - - \n");
    printf("JOGO DE ADIVINHACAO \n");
    printf("- - - - - - - - - - \n");

    for (int i = 1; i <= NUMERO_TENTATIVAS; i++)
    {
        printf("Tentativa %d de %d\n", i, NUMERO_TENTATIVAS);
        printf("Chute um numero: \n");
        scanf("%d", &chute);

        if (chute < 0){
            printf("Sao validos apenas numeros POSITIVOS, tente novamente!\n");
            i--;
            continue;
        }

        if (chute > numerosecreto){
            printf("%d e maior que o numero secreto, tente outra vez!\n", chute);
        }

        else if(chute < numerosecreto){
            printf("%d e menor que o numero secreto, tente outra vez!\n", chute);
        }

        double pontosperdidos = abs(chute - numerosecreto) / (double) 2;
        pontos = pontos - pontosperdidos;

        if (chute == numerosecreto){
            printf("Parabens, voce acertou na tentativa %d !! O numero secreto e: %d\n", i, numerosecreto);
            printf("Pontuacao %.1f: ", pontos);
            break;
        }
    }
}
