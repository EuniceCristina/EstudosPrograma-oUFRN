#include <stdio.h>

enum TiposTaxas {
    POUPANCA = 1,
    CDB = 2,
    TESOURO_SELIC = 3
};

typedef struct {
    char nome[30];
    float taxa;
    float saldo;
    float saldos[120];
} Investimento;


int menu() {

    int opcao;

    printf("\n===== MENU =====\n");
    printf("1 - Poupanca\n");
    printf("2 - CDB Prefixado\n");
    printf("3 - Tesouro Selic\n");
    printf("0 - Sair\n");

    printf("Opcao: ");
    scanf("%d", &opcao);

    return opcao;
}


int main() {

    char nome[20];
    float renda;
    int tempo;
    float percentual;
    float aporte;

    Investimento investimentos[3] = {
        {"Poupanca", 0.005, 0.0, {0}},
        {"CDB Prefixado", 0.008, 0.0, {0}},
        {"Tesouro Selic", 0.0068, 0.0, {0}}
    };


    printf("Digite seu nome: ");
    scanf("%19s", nome);

    printf("Digite sua renda mensal: ");
    scanf("%f", &renda);

    printf("Digite o percentual da renda para investir: ");
    scanf("%f", &percentual);

    printf("Digite seu tempo de investimento [em meses]: ");
    scanf("%d", &tempo);

    if (tempo > 120) {
        tempo = 120;
        printf("Tempo ajustado para o limite de 120 meses.\n");
    }

    aporte = renda * (percentual / 100.0);


    // Calculo dos investimentos
    for (int i = 0; i < tempo; i++) {

        for (int j = 0; j < 3; j++) {

            investimentos[j].saldo =
                (investimentos[j].saldo + aporte)
                * (1 + investimentos[j].taxa);

            investimentos[j].saldos[i] =
                investimentos[j].saldo;
        }
    }


    int opcao;

    do {

        opcao = menu();

        switch (opcao) {

            case POUPANCA:
                printf("\nInvestimento escolhido: %s\n",
                       investimentos[0].nome);

                printf("Taxa: %.2f%% ao mes\n",
                       investimentos[0].taxa * 100);

                printf("Saldo final: R$ %.2f\n",
                       investimentos[0].saldo);
                break;


            case CDB:
                printf("\nInvestimento escolhido: %s\n",
                       investimentos[1].nome);

                printf("Taxa: %.2f%% ao mes\n",
                       investimentos[1].taxa * 100);

                printf("Saldo final: R$ %.2f\n",
                       investimentos[1].saldo);
                break;


            case TESOURO_SELIC:
                printf("\nInvestimento escolhido: %s\n",
                       investimentos[2].nome);

                printf("Taxa: %.2f%% ao mes\n",
                       investimentos[2].taxa * 100);

                printf("Saldo final: R$ %.2f\n",
                       investimentos[2].saldo);
                break;


            case 0:
                printf("\nSaindo...\n");
                break;


            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);


    return 0;
}