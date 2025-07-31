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

// Função recursiva para mover o Bispo diagonal (alto e direita)
// e também implementa loops aninhados: externo para vertical, interno para horizontal
void moverBispoRecursivoComLoops(int v, int maxV, int h, int maxH) {
    if (v > maxV) return;

    if (h > maxH) {
        // Quando termina o loop horizontal, recursa para o próximo vertical
        moverBispoRecursivoComLoops(v + 1, maxV, 1, maxH);
        return;
    }

    printf("%d° movimento: Movimento para cima e direita (diagonal) - v=%d h=%d\n", (v + h - 1), v, h);
    moverBispoRecursivoComLoops(v, maxV, h + 1, maxH);
}

// Função recursiva simples para Bispo (substitui o do-while original)
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
            // Exemplo de uso de continue: se quiser pular algo, mas aqui só demonstra
            if (j == 1) continue;  // apenas demonstração; continue não é necessário aqui
        }
        // Loop interno: movimento horizontal, uma casa para direita
        printf("%d° movimento: Movimento para direita\n", count++);
        // Exemplo de break para controlar fluxo (não usado na prática aqui, só ilustração)
        // if (count > movimentos*3) break;
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
            printf("Escolha uma peça (1-4): \n");
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

            case 3: // Bispo - função recursiva com loops aninhados demonstrada
                nomePeca = "Bispo";
                casas = 3; // menor valor para loops aninhados
                printf("Movendo %s (recursivo com loops aninhados) %d casa(s):\n", nomePeca, casas);
                moverBispoRecursivoComLoops(1, casas, 1, casas);
                // Também pode usar a versão simples recursiva abaixo:
                // moverBispo(1, casas);
                break;

            case 4: // Cavalo com loops aninhados
                nomePeca = "Cavalo";
                casas = 2; // número de movimentos L que o cavalo irá fazer
                printf("Movendo %s %d movimento(s) em 'L' para cima e para direita:\n", nomePeca, casas);
                moverCavalo(casas);
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