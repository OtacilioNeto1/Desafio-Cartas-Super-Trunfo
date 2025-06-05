#include <stdio.h>
#include <string.h>

typedef struct {
    char nomePais[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Pais;

void lerPais(Pais *pais, int num) {
    printf("===== CADASTRO PAIS %d =====\n", num);
    printf("Nome do pais: ");
    scanf(" %[^\n]", &pais->nomePais);

    printf("Populacao: ");
    scanf("%lu", &pais->populacao);

    printf("Area (km2): ");
    scanf("%f", &pais->area);

    printf("PIB (bilhoes): ");
    scanf("%f", &pais->pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &pais->pontosTuristicos);

    pais->densidadeDemografica = (pais->area != 0) ? (float)pais->populacao / pais->area : 0;

    printf("\n");
}

void mostrarPais(Pais p, int num) {
    printf("===== PAIS %d =====\n", num);
    printf("Nome do pais: %s\n", p.nomePais);
    printf("Populacao: %lu\n", p.populacao);
    printf("Area: %.2f km2\n", p.area);
    printf("PIB: %.2f bilhoes\n", p.pib);
    printf("Pontos turisticos: %d\n", p.pontosTuristicos);
    printf("Densidade demografica: %.2f hab/km2\n\n", p.densidadeDemografica);
}

// Retorna valor do atributo escolhido para um país
float getValorAtributo(Pais p, int atributo) {
    switch(atributo) {
        case 1: return (float)p.populacao;
        case 2: return p.area;
        case 3: return p.pib;
        case 4: return (float)p.pontosTuristicos;
        case 5: return p.densidadeDemografica;
        default: return 0.0f;
    }
}

// Retorna nome do atributo para exibição
const char* nomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Demografica";
        default: return "Atributo Desconhecido";
    }
}

// Menu para escolher atributo, excluindo o atributo já escolhido (passar 0 se nenhum escolhido ainda)
int escolherAtributo(int excluido) {
    int opcao;
    do {
        printf("Escolha o atributo para comparar:\n");
        if(excluido != 1) printf("1 - Populacao\n");
        if(excluido != 2) printf("2 - Area\n");
        if(excluido != 3) printf("3 - PIB\n");
        if(excluido != 4) printf("4 - Pontos Turisticos\n");
        if(excluido != 5) printf("5 - Densidade Demografica\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if(opcao < 1 || opcao > 5 || opcao == excluido)
            printf("Opcao invalida ou repetida! Tente novamente.\n\n");
        else
            break;
    } while(1);

    return opcao;
}

// Compara um atributo entre dois países, retornando:
// 1 se p1 vence
// 2 se p2 vence
// 0 empate
int compararAtributo(float v1, float v2, int atributo) {
    if (v1 == v2) return 0;
    if (atributo == 5) // densidade demografica menor vence
        return (v1 < v2) ? 1 : 2;
    else // maior vence
        return (v1 > v2) ? 1 : 2;
}

int main() {
    Pais pais1, pais2;
    int atr1, atr2;
    float v1_1, v1_2, v2_1, v2_2;
    int resultado1, resultado2;
    float soma1, soma2;

    // Leitura das cartas
    lerPais(&pais1, 1);
    lerPais(&pais2, 2);

    mostrarPais(pais1, 1);
    mostrarPais(pais2, 2);

    // Escolha dos atributos
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    atr1 = escolherAtributo(0);

    printf("\nEscolha o SEGUNDO atributo para comparar (diferente do primeiro):\n");
    atr2 = escolherAtributo(atr1);

    // Pega os valores
    v1_1 = getValorAtributo(pais1, atr1);
    v1_2 = getValorAtributo(pais1, atr2);
    v2_1 = getValorAtributo(pais2, atr1);
    v2_2 = getValorAtributo(pais2, atr2);

    // Compara os dois atributos individualmente
    resultado1 = compararAtributo(v1_1, v2_1, atr1);
    resultado2 = compararAtributo(v1_2, v2_2, atr2);

    // Soma dos valores para cada país (regra: soma dos valores reais, sem considerar quem vence)
    soma1 = v1_1 + v1_2;
    soma2 = v2_1 + v2_2;

    // Mostrar resultado
    printf("\n===== RESULTADO DA COMPARACAO =====\n");
    printf("Pais 1: %s\n", pais1.nomePais);
    printf("Pais 2: %s\n\n", pais2.nomePais);

    printf("Atributo 1: %s\n", nomeAtributo(atr1));
    printf("  Pais 1: %.2f\n", v1_1);
    printf("  Pais 2: %.2f\n\n", v2_1);

    printf("Atributo 2: %s\n", nomeAtributo(atr2));
    printf("  Pais 1: %.2f\n", v1_2);
    printf("  Pais 2: %.2f\n\n", v2_2);

    printf("Soma dos atributos:\n");
    printf("  Pais 1: %.2f\n", soma1);
    printf("  Pais 2: %.2f\n\n", soma2);

    // Decidir vencedor da rodada
    if (soma1 == soma2) {
        printf("Resultado final: Empate!\n");
    } else {
        int vencedorFinal = (soma1 > soma2) ? 1 : 2;
        printf("Resultado final: Pais %d (%s) venceu!\n", vencedorFinal, (vencedorFinal == 1) ? pais1.nomePais : pais2.nomePais);
    }

    printf("\nPressione ENTER para sair...");
    getchar(); // limpar buffer do scanf
    getchar(); // esperar enter

    return 0;
}
