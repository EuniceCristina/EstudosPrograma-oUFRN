#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Personagem {
        char nome[20];
        char classe[20];
        int vida;
        int ataque;
        int forca;
        int bonus;
        int defesa;
        int agilidade;
        int xp;
        int inteligencia;
        char equipamento[50];
        char especial[50];
        int chanceFuga;
        int habilidadeEspecial;
    } Personagem;

    typedef struct Boi {
        char nome[20];
        int vida;
        int ataque;
        int defesa;
        int xp;
    } Boi;




void recebeBonus(struct Personagem *heroi){
    if (heroi->vida < 30) {
        heroi->bonus = 5;
    } else if (heroi->vida < 60) {
        heroi->bonus = 3;
    } else {
        heroi->bonus = 1;
    }
}
void ataqueVaqueiro(struct Personagem *heroi, struct Boi *boi){
    if (boi->vida <= 0) {
         return;
     }
    int d20 = (rand() % 20 + 1);
    int ataque = d20 + heroi->ataque + heroi->bonus;
    printf("\nVocê tirou %d no dado.", d20);
    printf("\nSeu ataque total é %d.", ataque);
    int dano = (ataque - boi->defesa);
    if (dano<=0){
        dano=1;
    };
    printf("\nVocê causou %d de dano ao %s.", dano, boi->nome);
    boi->vida -= dano;
    if (boi->vida <= 0) {
        boi->vida = 0;
        

    }
    printf("\n%s - Vida: %d, Ataque: %d, Defesa: %d", boi->nome, boi->vida, boi->ataque, boi->defesa);

}
void habilidadeEspecial(struct Personagem *heroi, struct Boi *boi){
    if (boi->vida <= 0) {
         return;
     }
    if (heroi->habilidadeEspecial == 0) {
        printf("\nVocê já usou sua habilidade especial nesta batalha. Escolha outra ação.");
        return;
    }
    if (strcmp(heroi->especial, "Laço Certeiro") == 0) {
        int d20 = (rand() % 20 + 1);
        int ataque = d20 + heroi->ataque + heroi->bonus + 5; 
        int dano = (ataque - boi->defesa);
        if (dano<=0){
            dano=1;
        };
        boi->vida -= dano;
    } else if (strcmp(heroi->especial, "Puxada de Ferro") == 0) {
        boi->defesa -= 2; 
        if (boi->defesa < 0) {
            boi->defesa = 0; 
        }
    } else if (strcmp(heroi->especial, "Corrida Relâmpago") == 0) {
        heroi->chanceFuga += 10; 
    }
    heroi->habilidadeEspecial = 0;
}

void fugaHeroi(struct Personagem *heroi, struct Boi *boi, int *fuga) {
    int d20 = (rand() % 20 + 1);
    int chanceFugaTotal = heroi->chanceFuga + d20;
    printf("\nVocê tirou %d no dado.", d20);
    printf("\nSua chance de fuga total é %d.", chanceFugaTotal);
    if (chanceFugaTotal >= 30) {
        printf("\nVocê conseguiu fugir do combate!");
        *fuga = 1;
    } else {
        printf("\nVocê não conseguiu fugir do combate.");
    }
}
void avancaCasa(int *posicao, char casas[12][20], Personagem *heroi, Boi *boi) {
    int d6 = (rand() % 2 + 1);
    printf("\nVocê tirou %d no dado.", d6);
    *posicao +=d6;
    
    

    switch (*posicao) {
        case 1:
            printf("\nVocê parou numa casa vazia. Nada acontece. \nSe prepare-se para a próxima rodada.");
            break;
        case 2:
            printf("\nVocê parou numa casa de combate. Prepare-se para lutar contra um boi!");
            int numBoi = (rand() % 3 + 1);
            int fuga = 0;
            switch (numBoi) {
                case 1:
                    strcpy(boi->nome,"Boi Pintado");
                    boi->vida = 30;
                    boi->ataque = 6;
                    boi->defesa = 3;
                    boi->xp = 20;
                    break;
                case 2:
                    strcpy(boi->nome,"Boi Malhado");
                    boi->vida = 35;
                    boi->ataque = 7;
                    boi->defesa = 4;
                    boi->xp = 25;
                    break;
                case 3:
                    strcpy(boi->nome,"Boi Caboclo");
                    boi->vida = 40;
                    boi->ataque = 8;
                    boi->defesa = 5;
                    boi->xp = 30;
                    break;
            }
            printf("\nVocê encontrou o %s! Prepare-se para a batalha!", boi->nome);
            while (boi->vida > 0 && heroi->vida > 0 && fuga ==0){
                
                printf("\n%s - Vida: %d, Ataque: %d, Defesa: %d", boi->nome, boi->vida, boi->ataque, boi->defesa);
                printf("\n%s - Vida: %d, Ataque: %d, Defesa: %d", heroi->nome, heroi->vida, heroi->ataque, heroi->defesa);
                int acao;
                printf("\nDefina sua ação: 1- Atacar, 2- Defender, 3- Usar habilidade especial, 4- Fugir\n:");
                scanf("%d", &acao);
                switch (acao) {
                    case 1: 
                        ataqueVaqueiro(heroi, boi);
                        break;
                    case 2:
                        printf("\nVocê escolheu se defender. Sua defesa aumentou temporariamente.");
                        heroi->defesa += 2;
                        break;
                    case 3:
                        habilidadeEspecial(heroi, boi);
                        break;
                    case 4:
                        fugaHeroi(heroi, boi, &fuga);
                        
                        break;
                        

                };
            };
            if (boi->vida==0){
                printf("\nVocê derrotou o %s!", boi->nome);
                heroi->xp += boi->xp;
                recebeBonus(heroi);
            } else if (heroi->vida==0){
                printf("\nVocê foi derrotado pelo %s. Fim de jogo.", boi->nome);
                exit(0);
            } else if (fuga){
                printf("\nVocê fugiu do combate. Prepare-se para a próxima rodada.");
                return;
            }

            break;
           

    };

    

};

int main(){

    char casas[12][20] = {"Início","Vazia","Combate","Tesouro","Combate","Cura","Armadilha","Combate","Vazia","Tesouro","Missão","Chefe / Fim"};
    int posicao =0;
    

    struct Personagem heroi;
    struct Boi boi;

    printf("1- Vaqueiro Nym\n" 
        "Classe: Equilibrado\n" 
        "Vida: 110\n" 
        "Força: 12\n" 
        "Defesa: 9\n" 
        "Agilidade: 10\n" 
        "Inteligência: 6\n" 
        "Chance de fuga: 25\n"
        "Equipamentos: Cavalo Ventania,gibão de couro\n"
        "Habilidade especial:Laço Certeiro(ataque com bônus de dano fixo) ");

    printf("2- Vaqueira Marta\n" 
        "Classe: Força\n" 
        "Vida: 130\n" 
        "Força: 14\n" 
        "Defesa: 12\n" 
        "Agilidade: 7\n" 
        "Inteligência: 5\n" 
        "Chance de fuga: 20\n"
        "Equipamentos: Cavalo Trovão, perneira reforçada, laço pesado\n"
        "Habilidade especial: Puxada de Ferro(reduz a defesa do boi por um turno)\n");

     printf("3- Vaqueiro Zé Relâmpago\n" 
        "Classe: Agilidade\n" 
        "Vida: 95\n" 
        "Força: 9\n" 
        "Defesa: 8\n" 
        "Agilidade: 15\n" 
        "Inteligência: 8\n" 
        "Chance de fuga: 25\n"
        "Equipamentos: Cavalo Seta, esporas, chapéu de couro\n"
        "Habilidade especial:Corrida Relâmpago(aumenta chance de fuga) ");


    printf("\nEscolha seu personagem: ");
    int numPersonagem;
    scanf("%d", &numPersonagem);

    switch (numPersonagem) {
        case 1: 
            strcpy(heroi.nome,"Vaqueiro Nym");
            strcpy(heroi.classe,"Equilibrado");
            heroi.vida = 110;
            heroi.ataque = 12;
            heroi.forca = 12;
            heroi.defesa = 9;
            heroi.agilidade = 10;
            heroi.inteligencia = 6;
            heroi.bonus=2;
            heroi.chanceFuga = 25;
            strcpy(heroi.equipamento,"Cavalo Ventania, gibão de couro");
            strcpy(heroi.especial,"Laço Certeiro");
            break;
        case 2:
            strcpy(heroi.nome,"Vaqueira Marta");
            strcpy(heroi.classe,"Força");
            heroi.vida = 130;
            heroi.ataque = 14;
            heroi.forca = 14;
            heroi.defesa = 12; 
            heroi.agilidade = 7;
            heroi.inteligencia = 5;
            heroi.bonus=3;
            heroi.chanceFuga = 20;
            strcpy(heroi.equipamento,"Cavalo Trovão, perneira reforçada, laço pesado");
            strcpy(heroi.especial,"Puxada de Ferro");
            break;

        case 3:
            strcpy(heroi.nome,"Vaqueiro Zé Relâmpago");
            strcpy(heroi.classe,"Agilidade");
            heroi.vida = 95;
            heroi.ataque = 9;
            heroi.forca = 9;
            heroi.defesa = 8;
            heroi.agilidade = 15;
            heroi.bonus=4;
            heroi.inteligencia = 8;
            heroi.chanceFuga = 25;
            strcpy(heroi.equipamento,"Cavalo Seta, esporas, chapéu de couro");
            strcpy(heroi.especial,"Corrida Relâmpago");
            break;
    };
    heroi.habilidadeEspecial = 1;

    printf("\nFase 1");
    printf("\nMissão: derrubar 2 bois e vencer o chefe da fase, o Boi Caboclo. Dificuldade: baixa.");

    printf("\nBoi          Descrição                  Vida  Ataque  Defesa  XP");
    printf("\nBoi Pintado  Boi jovem e arisco         30    6       3       20");
    printf("\nBoi Malhado  Boi rápido e imprevisível  35    7       4       25");
    printf("\nBoi Caboclo  Chefe da fase Mirim        40    8       5       30");

    printf("\n%s, você está na casa %s.", heroi.nome, casas[posicao]);
   
   printf("\n\nLançando dados para avançar de casa...");

   avancaCasa(&posicao, casas, &heroi, &boi);

   
   
    return 0;


    
    
};
