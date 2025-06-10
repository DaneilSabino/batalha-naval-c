#include <stdio.h>

#define TAM 5
#define NAVIO 1
#define AGUA 0
#define ACERTO -1
#define AREA_EFEITO -2

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == NAVIO)
                printf(" N ");
            else if (tabuleiro[i][j] == ACERTO)
                printf(" X ");
            else if (tabuleiro[i][j] == AREA_EFEITO)
                printf(" * ");
            else
                printf(" ~ ");
        }
        printf("\n");
    }
}

void aplicarAtaqueArea(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = linha - 1; i <= linha + 1; i++) {
        for (int j = coluna - 1; j <= coluna + 1; j++) {
            if (i >= 0 && i < TAM && j >= 0 && j < TAM) {
                if (tabuleiro[i][j] == NAVIO)
                    tabuleiro[i][j] = ACERTO;
                else if (tabuleiro[i][j] == AGUA)
                    tabuleiro[i][j] = AREA_EFEITO;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    exibirTabuleiro(tabuleiro);

    int linha, coluna;
    printf("\nDigite as coordenadas do ataque especial (linha coluna): ");
    scanf("%d %d", &linha, &coluna);

    aplicarAtaqueArea(tabuleiro, linha, coluna);

    exibirTabuleiro(tabuleiro);

    return 0;
}
