#include <stdio.h>

struct Carta {
    char estado;          // letra de A a H
    char codigo[4];       // ex: A01
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;            // em bilhoes de reais
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para ler os dados da carta
void lerCarta(struct Carta *carta, int numero) {
    printf("===== CADASTRO CARTA %d =====\n", numero);
    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta->estado);
    printf("Codigo da Carta (ex: A01): ");
    scanf("%3s", carta->codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);
    printf("Populacao (numero inteiro): ");
    scanf("%d", &carta->populacao);
    printf("Area (em km2): ");
    scanf("%f", &carta->area);
    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &carta->pib);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta->pontosTuristicos);
    printf("\n");
}

// Função para calcular densidade populacional e PIB per capita
void calcularIndices(struct Carta *carta) {
    // Densidade = populacao / area
    carta->densidadePopulacional = carta->populacao / carta->area;

    // PIB per capita = (PIB em reais) / populacao
    // PIB está em bilhões, então multiplica por 1 bilhao (1.000.000.000)
    carta->pibPerCapita = (carta->pib * 1000000000) / carta->populacao;
}

// Função para exibir os dados da carta incluindo os calculados
void exibirCarta(struct Carta carta, int numero) {
    printf("===== CARTA %d =====\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Codigo: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f km2\n", carta.area);
    printf("PIB: %.2f bilhoes de reais\n", carta.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km2\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
    printf("\n");
}

int main() {
    struct Carta carta1, carta2;

    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    calcularIndices(&carta1);
    calcularIndices(&carta2);

    printf("===== EXIBICAO DE DADOS =====\n\n");

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    printf("Aperte ENTER para sair...");
    getchar();
    getchar();

    return 0;
}
