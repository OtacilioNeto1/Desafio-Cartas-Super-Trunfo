#include <stdio.h>
#include <string.h>

// Definição da struct Pais
typedef struct {
    char nomePais[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Pais;

// Função para ler dados de um país
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

    // Calcular densidade demografica
    pais->densidadeDemografica = pais->populacao / pais->area;

    printf("\n");
}

// Função para mostrar dados de um país
void mostrarPais(Pais pais, int num) {
    printf("===== PAIS %d =====\n", num);
    printf("Nome do pais: %s\n", pais.nomePais);
    printf("Populacao: %lu\n", pais.populacao);
    printf("Area: %.2f km2\n", pais.area);
    printf("PIB: %.2f bilhoes\n", pais.pib);
    printf("Pontos turisticos: %d\n", pais.pontosTuristicos);
    printf("Densidade demografica: %.2f hab/km2\n\n", pais.densidadeDemografica);
}

// Função para comparar os dois países
void compararPaises(Pais p1, Pais p2, int opcao) {
    printf("===== RESULTADO DA COMPARACAO =====\n");

    float valor1 = 0, valor2 = 0;
    char nomeAtributo[30] = "";
    int vencedor = 0; // 0 empate, 1 p1 vence, 2 p2 vence

    switch(opcao) {
        case 1: // Populacao
            valor1 = (float)p1.populacao;
            valor2 = (float)p2.populacao;
            strcpy(nomeAtributo, "Populacao");
            break;
        case 2: // Area
            valor1 = p1.area;
            valor2 = p2.area;
            strcpy(nomeAtributo, "Area");
            break;
        case 3: // PIB
            valor1 = p1.pib;
            valor2 = p2.pib;
            strcpy(nomeAtributo, "PIB");
            break;
        case 4: // Pontos turisticos
            valor1 = (float)p1.pontosTuristicos;
            valor2 = (float)p2.pontosTuristicos;
            strcpy(nomeAtributo, "Pontos Turisticos");
            break;
        case 5: // Densidade demografica (menor vence)
            valor1 = p1.densidadeDemografica;
            valor2 = p2.densidadeDemografica;
            strcpy(nomeAtributo, "Densidade Demografica");
            break;
        default:
            printf("Opcao invalida para comparacao.\n");
            return;
    }

    // Mostrar valores
    printf("%s:\n", nomeAtributo);
    printf("Pais 1 - %s: %.2f\n", p1.nomePais, valor1);
    printf("Pais 2 - %s: %.2f\n", p2.nomePais, valor2);

    // Decisão aninhada
    if (valor1 == valor2) {
        printf("Resultado: Empate!\n");
    } else {
        if (opcao == 5) { // densidade demografica menor vence
            if (valor1 < valor2)
                vencedor = 1;
            else
                vencedor = 2;
        } else { // maior vence
            if (valor1 > valor2)
                vencedor = 1;
            else
                vencedor = 2;
        }

        if (vencedor == 1) {
            printf("Resultado: Pais 1 (%s) venceu!\n", p1.nomePais);
        } else {
            printf("Resultado: Pais 2 (%s) venceu!\n", p2.nomePais);
        }
    }

    printf("\n");
}

int main() {
    Pais pais1, pais2;
    int opcao;

    lerPais(&pais1, 1);
    lerPais(&pais2, 2);

    mostrarPais(pais1, 1);
    mostrarPais(pais2, 2);

    printf("===== MENU DE COMPARACAO =====\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    printf("\n");

    compararPaises(pais1, pais2, opcao);

    printf("Pressione ENTER para sair...");
    getchar(); // limpa buffer
    getchar(); // espera ENTER

    return 0;
}
