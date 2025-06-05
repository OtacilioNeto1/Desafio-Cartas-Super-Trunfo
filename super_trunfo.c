#include <stdio.h>

struct Carta {
    char estado;                 // letra de A a H
    char codigo[4];              // ex: A01
    char nomeCidade[50];
    unsigned long int populacao; // mudou para unsigned long int
    float area;
    float pib;                   // em bilhoes de reais
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
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
    printf("Populacao (numero inteiro, maior que 0): ");
    scanf("%lu", &carta->populacao);
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
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000.0f) / carta->populacao;
}

// Função para calcular o super poder
void calcularSuperPoder(struct Carta *carta) {
    // Super Poder = populacao + area + pib + pontosTuristicos + pibPerCapita + (1 / densidadePopulacional)
    float pop = (float)carta->populacao;
    float densidadeInv = 1.0f / carta->densidadePopulacional;

    carta->superPoder = pop + carta->area + carta->pib + (float)carta->pontosTuristicos + carta->pibPerCapita + densidadeInv;
}

// Função para exibir os dados da carta incluindo os calculados
void exibirCarta(struct Carta carta, int numero) {
    printf("===== CARTA %d =====\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Codigo: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("Populacao: %lu\n", carta.populacao);
    printf("Area: %.2f km2\n", carta.area);
    printf("PIB: %.2f bilhoes de reais\n", carta.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km2\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n\n", carta.superPoder);
}

// Função para exibir os resultados da comparação
void compararCartas(struct Carta c1, struct Carta c2) {
    printf("===== COMPARACAO DE CARTAS =====\n\n");

    // Populacao: maior vence
    printf("Populacao: Carta %d venceu (%d)\n", 
        1 * (c1.populacao > c2.populacao) + 2 * (c1.populacao <= c2.populacao), 
        (c1.populacao > c2.populacao));

    // Area: maior vence
    printf("Area: Carta %d venceu (%d)\n", 
        1 * (c1.area > c2.area) + 2 * (c1.area <= c2.area), 
        (c1.area > c2.area));

    // PIB: maior vence
    printf("PIB: Carta %d venceu (%d)\n", 
        1 * (c1.pib > c2.pib) + 2 * (c1.pib <= c2.pib), 
        (c1.pib > c2.pib));

    // Pontos Turisticos: maior vence
    printf("Pontos Turisticos: Carta %d venceu (%d)\n", 
        1 * (c1.pontosTuristicos > c2.pontosTuristicos) + 2 * (c1.pontosTuristicos <= c2.pontosTuristicos), 
        (c1.pontosTuristicos > c2.pontosTuristicos));

    // Densidade Populacional: menor vence
    printf("Densidade Populacional: Carta %d venceu (%d)\n", 
        1 * (c1.densidadePopulacional < c2.densidadePopulacional) + 2 * (c1.densidadePopulacional >= c2.densidadePopulacional), 
        (c1.densidadePopulacional < c2.densidadePopulacional));

    // PIB per Capita: maior vence
    printf("PIB per Capita: Carta %d venceu (%d)\n", 
        1 * (c1.pibPerCapita > c2.pibPerCapita) + 2 * (c1.pibPerCapita <= c2.pibPerCapita), 
        (c1.pibPerCapita > c2.pibPerCapita));

    // Super Poder: maior vence
    printf("Super Poder: Carta %d venceu (%d)\n", 
        1 * (c1.superPoder > c2.superPoder) + 2 * (c1.superPoder <= c2.superPoder), 
        (c1.superPoder > c2.superPoder));

    printf("\n");
}



int main() {
    struct Carta carta1, carta2;

    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    calcularIndices(&carta1);
    calcularIndices(&carta2);

    calcularSuperPoder(&carta1);
    calcularSuperPoder(&carta2);

    printf("===== EXIBICAO DE DADOS =====\n\n");
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    compararCartas(carta1, carta2);

    printf("Aperte ENTER para sair...");
    getchar(); // consome o '\n' pendente
    getchar(); // espera o Enter do usuario

    return 0;
}
