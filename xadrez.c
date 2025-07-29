#include <stdio.h>

int main() {
    int escolha, casas;
    char continuar;

    do {
        // Menu para escolher a peça (while para validação)
        while (1) {
            printf("=== MENU PRINCIPAL ===\n");
            printf("1 - Torre\n");
            printf("2 - Rainha\n");
            printf("3 - Bispo\n");
            printf("Escolha uma peça (1-3): ");
            scanf("%d", &escolha);

            if (escolha >= 1 && escolha <= 3)
                break;
            printf("Escolha inválida! Tente novamente.\n");
        }

        // Validação da quantidade de casas para mover (do while)
        do {
            printf("Digite quantas casas deseja mover (1 a 5): ");
            scanf("%d", &casas);
            if (casas < 1 || casas > 5)
                printf("Valor inválido! Digite novamente.\n");
        } while (casas < 1 || casas > 5);

        // Escolhendo nome da peça para exibir mensagem
        char *nomePeca;
        switch (escolha) {
            case 1:
                nomePeca = "Torre";
                break;
            case 2:
                nomePeca = "Rainha";
                break;
            case 3:
                nomePeca = "Bispo";
                break;
            default:
                nomePeca = "Peça Desconhecida";
                break;
        }

        printf("Movendo %s %d casa(s):\n", nomePeca, casas);

        // For para repetir o número de casas com movimentos exclusivos por peça
        for (int i = 1; i <= casas; i++) {
            switch (escolha) {
                case 1: // Torre - movimento direita (Ex: sempre "para direita")
                    printf("%d° movimento: Movimento reto para direita\n", i);
                    break;
                case 2: // Rainha - pode mover em qualquer direção
                    printf("%d° movimento: Movimento para a direita\n", i);
                    break;
                case 3: // Bispo - movimento diagonal
                    printf("%d° movimento: Movimento para cima e direita (diagonal)\n", i);
                    break;
            }
        }

        // Pergunta se quer continuar jogando
        printf("Deseja mover outra peça? (s/n): ");
        // espaço antes de %c para consumir qualquer \n remanescente
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("Jogo encerrado. Obrigado por jogar!\n");

    return 0;
}