#include <stdio.h>

typedef struct {
    char cidade[50];
    int populacao;
    float area;
    float pib;
} Carta;

void cadastrarCarta(Carta* carta) {
    printf("\nDigite o nome da cidade: ");
    scanf("%s", carta->cidade);

    printf("Digite a população: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área: ");
    scanf("%f", &carta->area);

    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);
}

void compararCartas(Carta c1, Carta c2, int atributo1, int atributo2) {
    // Comparação para o primeiro atributo
    printf("\nComparando atributos...\n");
    if (atributo1 == 1) {
        printf("Atributo 1: População\n");
        printf("%s: %d, %s: %d\n", c1.cidade, c1.populacao, c2.cidade, c2.populacao);
    } else if (atributo1 == 2) {
        printf("Atributo 1: Área\n");
        printf("%s: %.2f, %s: %.2f\n", c1.cidade, c1.area, c2.cidade, c2.area);
    } else if (atributo1 == 3) {
        printf("Atributo 1: PIB\n");
        printf("%s: %.2f, %s: %.2f\n", c1.cidade, c1.pib, c2.cidade, c2.pib);
    }

    // Comparação do segundo atributo
    if (atributo2 == 1) {
        printf("Atributo 2: População\n");
        printf("%s: %d, %s: %d\n", c1.cidade, c1.populacao, c2.cidade, c2.populacao);
    } else if (atributo2 == 2) {
        printf("Atributo 2: Área\n");
        printf("%s: %.2f, %s: %.2f\n", c1.cidade, c1.area, c2.cidade, c2.area);
    } else if (atributo2 == 3) {
        printf("Atributo 2: PIB\n");
        printf("%s: %.2f, %s: %.2f\n", c1.cidade, c1.pib, c2.cidade, c2.pib);
    }

    // Lógica para determinar o vencedor usando operadores ternários
    printf("\nResultado da comparação:\n");
    int vencedor = (atributo1 == 1) ? (c1.populacao > c2.populacao ? 1 : (c1.populacao < c2.populacao ? 2 : 0)) :
                  (atributo1 == 2) ? (c1.area > c2.area ? 1 : (c1.area < c2.area ? 2 : 0)) :
                  (c1.pib > c2.pib ? 1 : (c1.pib < c2.pib ? 2 : 0));

    int vencedorFinal = (vencedor == 0) ? 
                        (atributo2 == 1 ? (c1.populacao > c2.populacao ? 1 : (c1.populacao < c2.populacao ? 2 : 0)) : 
                        (atributo2 == 2 ? (c1.area > c2.area ? 1 : (c1.area < c2.area ? 2 : 0)) : 
                        (c1.pib > c2.pib ? 1 : (c1.pib < c2.pib ? 2 : 0)))) : vencedor;

    if (vencedorFinal == 1)
        printf("\nA carta %s venceu!\n", c1.cidade);
    else if (vencedorFinal == 2)
        printf("\nA carta %s venceu!\n", c2.cidade);
    else
        printf("\nEmpate!\n");
}

int main() {
    Carta carta1, carta2;
    int atributo1, atributo2;

    printf("Cadastrar a primeira carta:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastrar a segunda carta:\n");
    cadastrarCarta(&carta2);

    printf("\nEscolha o primeiro atributo para comparar (1 - População, 2 - Área, 3 - PIB): ");
    scanf("%d", &atributo1);

    printf("Escolha o segundo atributo para comparar (1 - População, 2 - Área, 3 - PIB): ");
    scanf("%d", &atributo2);

    compararCartas(carta1, carta2, atributo1, atributo2);

    return 0;
}
