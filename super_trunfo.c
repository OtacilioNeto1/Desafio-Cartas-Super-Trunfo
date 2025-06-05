#include <stdio.h>

// Definição da struct para a carta
struct Carta {
    char estado[3];           // Ex: "SP"
    char codigo[4];           // Ex: "A01"
    char nomeCidade[50];      // Nome da cidade
    int populacao;            // Número de habitantes
    float area;               // Área em km²
    float pib;                // PIB em bilhões
    int pontosTuristicos;     // Número de pontos turísticos

    float densidadePopulacional;  // calculada: populacao / area
    float pibPerCapita;            // calculado: pib / populacao
};

// Função para ler dados da carta
void cadastrarCarta(struct Carta *carta, int numCarta) {
    printf("===== CADASTRO CARTA %d =====\n", numCarta);

    printf("Estado (ex: SP): ");
    scanf("%2s", carta->estado);

    printf("Codigo da carta (ex: A01): ");
    scanf("%3s", carta->codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", &carta->nomeCidade);

    printf("Populacao: ");
    scanf("%d", &carta->populacao);

    printf("Area (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (bilhoes): ");
    scanf("%f", &carta->pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Calcular densidade e PIB per capita
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib * 1e9 / carta->populacao;  // Convertendo pib em reais para per capita

    printf("\n");
}

// Função que compara o atributo escolhido e exibe o vencedor
void compararAtributo(struct Carta c1, struct Carta c2, int atributo) {
    // atributo:
    // 1 = Populacao
    // 2 = Area
    // 3 = PIB
    // 4 = Densidade Populacional
    // 5 = PIB per Capita

    float valor1, valor2;
    char nomeAtributo[30];
    int cartaVencedora = 0; // 1 ou 2

    // Atribuir valores e nome do atributo conforme escolha
    if (atributo == 1) {
        valor1 = (float)c1.populacao;
        valor2 = (float)c2.populacao;
        sprintf(nomeAtributo, "Populacao");
    } else if (atributo == 2) {
        valor1 = c1.area;
        valor2 = c2.area;
        sprintf(nomeAtributo, "Area");
    } else if (atributo == 3) {
        valor1 = c1.pib;
        valor2 = c2.pib;
        sprintf(nomeAtributo, "PIB");
    } else if (atributo == 4) {
        valor1 = c1.densidadePopulacional;
        valor2 = c2.densidadePopulacional;
        sprintf(nomeAtributo, "Densidade Populacional");
    } else if (atributo == 5) {
        valor1 = c1.pibPerCapita;
        valor2 = c2.pibPerCapita;
        sprintf(nomeAtributo, "PIB per Capita");
    } else {
        printf("Atributo invalido!\n");
        return;
    }

    // Comparação:
    // Para Densidade Populacional, menor vence
    // Para os demais, maior vence

    if (atributo == 4) { // Densidade Populacional
        if (valor1 < valor2)
            cartaVencedora = 1;
        else
            cartaVencedora = 2;
    } else {
        if (valor1 > valor2)
            cartaVencedora = 1;
        else
            cartaVencedora = 2;
    }

    // Exibir resultados
    printf("Comparacao de cartas (Atributo: %s):\n\n", nomeAtributo);
    printf("Carta 1 - %s (%s): %.2f\n", c1.nomeCidade, c1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", c2.nomeCidade, c2.estado, valor2);
    printf("\nResultado: Carta %d (%s) venceu!\n", cartaVencedora,
           (cartaVencedora == 1) ? c1.nomeCidade : c2.nomeCidade);
}

int main() {
    struct Carta carta1, carta2;

    // Cadastro das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    // Escolha do atributo a comparar (mude aqui para testar outro)
    // 1 = Populacao, 2 = Area, 3 = PIB, 4 = Densidade Populacional, 5 = PIB per Capita
    int atributoEscolhido = 1;

    // Comparar e mostrar resultado
    compararAtributo(carta1, carta2, atributoEscolhido);

    printf("\nPressione ENTER para sair...");
    getchar();
    getchar(); 

    return 0;
}
