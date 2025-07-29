#include <stdio.h>

int main() {
    int escolha;
    char *nomePeca;
    int casas;
    char continuar;

    do {
        // Menu para escolha da peça (com validação simples)
        while (1) {
            printf("=== MENU PRINCIPAL ===\n");
            printf("1 - Torre\n");
            printf("2 - Rainha\n");
            printf("3 - Bispo\n");
            printf("4 - Cavalo\n");
            printf("Escolha uma peça (1-4): ");
            scanf("%d", &escolha);

            if (escolha >= 1 && escolha <= 4)
                break;
            printf("Escolha inválida! Tente novamente.\n\n");
        }

        switch (escolha) {
            case 1: // Torre - for
                nomePeca = "Torre";
                casas = 5;
                printf("Movendo %s %d casa(s):\n", nomePeca, casas);
                for (int i = 1; i <= casas; i++) {
                    printf("%d° movimento: Movimento reto para direita\n", i);
                }
                break;

            case 2: // Rainha - while
                nomePeca = "Rainha";
                casas = 8; // 8 casas para a Rainha
                printf("Movendo %s %d casa(s):\n", nomePeca, casas);
                int j = 1;
                while (j <= casas) {
                    printf("%d° movimento: Movimento reto para esquerda\n", j);
                    j++;
                }
                break;

            case 3: // Bispo - do-while
                nomePeca = "Bispo";
                casas = 5;
                printf("Movendo %s %d casa(s):\n", nomePeca, casas);
                int k = 1;
                do {
                    printf("%d° movimento: Movimento para cima e direita (diagonal)\n", k);
                    k++;
                } while (k <= casas);
                break;

            case 4:
            nomePeca = "Cavalo";
            casas = 1; //aqui informa a quantidade de casas que a peça vai andar
            printf("Movendo %s casas:\n", nomePeca);
            int l = 1;
            while(l<= casas){
                for(int l=1; l<3; l++){
                    printf("%d° movimento para baixo\n", l);
                }
            
                printf("%d° movimento para a esquerda\n", l);
                l++;
                }
                break;
                
            default:
                nomePeca = "Peça desconhecida";
                printf("Escolha inválida!\n");
                break;
        }

        // Perguntar se usuário deseja continuar com outra jogada
        printf("\nDeseja mover outra peça? (s/n): ");
        scanf(" %c", &continuar);

        printf("\n");

    } while (continuar == 's' || continuar == 'S');

    printf("Jogo encerrado. Obrigado por jogar!\n");
    return 0;
}