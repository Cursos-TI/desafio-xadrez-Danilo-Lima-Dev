#include <stdio.h>

// Função recursiva para mover a Torre para a direita
void moverTorre(int movimento, int casas) {
    if (movimento > casas) return;
    printf("%d° movimento: Movimento reto para direita\n", movimento);
    moverTorre(movimento + 1, casas);
}

// Função recursiva para mover a Rainha para a esquerda
void moverRainha(int movimento, int casas) {
    if (movimento > casas) return;
    printf("%d° movimento: Movimento reto para esquerda\n", movimento);
    moverRainha(movimento + 1, casas);
}

// Função recursiva simples para Bispo (substitui os loops simples originais)
void moverBispo(int movimento, int casas) {
    if (movimento > casas) return;
    printf("%d° movimento: Movimento para cima e direita (diagonal)\n", movimento);
    moverBispo(movimento + 1, casas);
}

// Função para melhorar o movimento do Cavalo com loops aninhados para "L" para cima e para direita
// Movimento: duas casas para cima e uma para a direita
void moverCavalo(int movimentos) {
    int count = 1;
    for (int i = 0; i < movimentos; i++) {
        // Loop externo: movimento vertical, duas casas para cima
        for (int j = 1; j <= 2; j++) {
            printf("%d° movimento: Movimento para cima\n", count++);
            if (j == 1) continue;  // demonstração de continue
        }
        // Movimento horizontal: uma casa para direita
        printf("%d° movimento: Movimento para direita\n", count++);
    }
}

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
            case 1: // Torre - função recursiva
                nomePeca = "Torre";
                casas = 5;
                printf("Movendo %s %d casa(s):\n", nomePeca, casas);
                moverTorre(1, casas);
                break;

            case 2: // Rainha - função recursiva
                nomePeca = "Rainha";
                casas = 8;
                printf("Movendo %s %d casa(s):\n", nomePeca, casas);
                moverRainha(1, casas);
                break;

            case 3: // Bispo - função recursiva simples
                nomePeca = "Bispo";
                casas = 5;
                printf("Movendo %s %d casa(s) na diagonal (cima e direita):\n", nomePeca, casas);
                moverBispo(1, casas);
                break;

            case 4: // Cavalo com loops aninhados
                nomePeca = "Cavalo";
                casas = 2;
                printf("Movendo %s %d movimento(s) em 'L' para cima e para direita:\n", nomePeca, casas);
                moverCavalo(casas);
                break;

            default:
                nomePeca = "Peça desconhecida";
                printf("Escolha inválida!\n");
                break;
        }

        printf("\nDeseja mover outra peça? (s/n): ");
        scanf(" %c", &continuar);

        printf("\n");

    } while (continuar == 's' || continuar == 'S');

    printf("Jogo encerrado. Obrigado por jogar!\n");
    return 0;
}
