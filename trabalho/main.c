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
        int resistencia;
        int reacao;
        int dificuldade;
        int xp;
    } Boi;



void tesouro(struct Personagem *vaqueiro){
    printf("\nVocê encontrou um tesouro! ");
    
    int sorteio = rand() % 4 + 1;

    switch (sorteio) {
        case 1:
            vaqueiro->forca += 2;
            printf("\nVocê ganhou +2 de força!");
            break;

        case 2:
            vaqueiro->defesa += 2;
            printf("\nVocê ganhou +2 de defesa!");
            break;

        case 3:
            vaqueiro->agilidade += 2;
            printf("\nVocê ganhou +2 de agilidade!");
            break;

        case 4:
            vaqueiro->inteligencia += 2;
            printf("\nVocê ganhou +2 de inteligência!");
            break;
    }
}

void recebeBonus(struct Personagem *vaqueiro){
    if (vaqueiro->vida < 30) {
        vaqueiro->bonus = 5;
    } else if (vaqueiro->vida < 60) {
        vaqueiro->bonus = 3;
    } else {
        vaqueiro->bonus = 1;
    }
}
void puxadaVaqueiro(struct Personagem *vaqueiro, struct Boi *boi){
    if (boi->resistencia <= 0) {
         return;
     }
    int d20 = (rand() % 20 + 1);
    int ataque = d20 + vaqueiro->ataque + vaqueiro->bonus;
    printf("\nVocê tirou %d no dado.", d20);
    printf("\nForça da puxada é %d.", ataque);
    int dano = (ataque - boi->dificuldade);
    if (dano<=0){
        dano=1;
    };
    printf("\nVocê reduziu a resistência do boi %s em %d.", boi->nome, dano);
    boi->resistencia -= dano;
    if (boi->resistencia <= 0) {
        boi->resistencia = 0;
        

    }
    printf("\n%s - Vida: %d, Ataque: %d, Defesa: %d", boi->nome, boi->resistencia, boi->reacao, boi->dificuldade);

}
void habilidadeEspecial(struct Personagem *vaqueiro, struct Boi *boi){
    if (boi->resistencia <= 0) {
         return;
     }
    if (vaqueiro->habilidadeEspecial == 0) {
        printf("\nVocê já usou sua habilidade especial nesta batalha. Escolha outra ação.");
        return;
    }
    if (strcmp(vaqueiro->especial, "Laço Certeiro") == 0) {
        int d20 = (rand() % 20 + 1);
        int ataque = d20 + vaqueiro->ataque + vaqueiro->bonus + 5; 
        int dano = (ataque - boi->dificuldade);
        if (dano<=0){
            dano=1;
        };
        boi->resistencia -= dano;
        if (boi->resistencia < 0) {
            boi->resistencia = 0;
        }
    } else if (strcmp(vaqueiro->especial, "Puxada de Ferro") == 0) {
        boi->dificuldade -= 2; 
        if (boi->dificuldade < 0) {
            boi->dificuldade = 0; 
        }
    } else if (strcmp(vaqueiro->especial, "Corrida Relâmpago") == 0) {
        vaqueiro->chanceFuga += 10; 
    }
    vaqueiro->habilidadeEspecial = 0;
}

void pularVez(struct Personagem *vaqueiro, struct Boi *boi, int *fuga) {
    int d20 = (rand() % 20 + 1);
    int chanceFugaTotal = vaqueiro->chanceFuga + d20;
    printf("\nVocê tirou %d no dado.", d20);
    printf("\nSua chance de fuga total é %d.", chanceFugaTotal);
    if (chanceFugaTotal >= 30) {
        printf("\nVocê conseguiu fugir do combate!");
        *fuga = 1;
    } else {
        printf("\nVocê não conseguiu fugir do combate.");
    }
}
void resistenciaBoi(struct Personagem *vaqueiro, struct Boi *boi) {
    if (boi->resistencia <= 0) {
         return;
     }
     int d20 = (rand() % 20 + 1);
     int reaco = d20 + boi->reacao;
     int pregresso = reaco - vaqueiro->defesa;
     if (pregresso <= 0) {
         pregresso = 1;
     }
     vaqueiro->vida -= pregresso;
     if (vaqueiro->vida <= 0) {
         vaqueiro->vida = 0;
     }
     printf("\n\nO boi %s resistiu você e reduziu sua força em %d.", boi->nome, pregresso);
     printf("\n%s - Vida: %d, Ataque: %d, Defesa: %d\n", vaqueiro->nome, vaqueiro->vida, vaqueiro->ataque, vaqueiro->defesa);
}   

void missao(struct Personagem *vaqueiro, struct Boi *boi){
    printf("\nVocê chegou na casa da missão. Prepare-se para lutar contra o chefe da fase, o Boi Caboclo!");
    strcpy(boi->nome,"Boi Caboclo");
    boi->resistencia = 40;
    boi->reacao = 8;
    boi->dificuldade = 5;
    boi->xp = 30;
    int fuga =0;
    while (boi->resistencia > 0 && vaqueiro->vida > 0 && fuga ==0){
                
    printf("\n%s - Vida: %d, Ataque: %d, Defesa: %d", boi->nome, boi->resistencia, boi->reacao, boi->dificuldade);
    printf("\n%s - Vida: %d, Ataque: %d, Defesa: %d", vaqueiro->nome, vaqueiro->vida, vaqueiro->ataque, vaqueiro->defesa);
    int acao;
    int fuga=0;
    int defesaOriginal = vaqueiro->defesa;
    printf("\nDefina sua ação: 1- Derrubar boi, 2- Segurar o boi, 3- Usar habilidade especial, 4- Pular vez\n:");
    scanf("%d", &acao);
    switch (acao) {
        case 1: 
            puxadaVaqueiro(vaqueiro, boi);
            break;
        case 2:
            printf("\nVVocê segurou o boi e estabilizou sua posição.");
            vaqueiro->defesa += 2;
            break;
        case 3:
            habilidadeEspecial(vaqueiro, boi);
            break;
        case 4:
            pularVez(vaqueiro, boi, &fuga);
            break;
                        

         };
        if (boi->resistencia > 0 && vaqueiro->vida > 0 && fuga == 0) {
            resistenciaBoi(vaqueiro, boi);
        }
        vaqueiro->defesa = defesaOriginal;

        };
        if (boi->resistencia==0){
            printf("\nValeu o boi.\nVocê derrobou o %s!", boi->nome);
            vaqueiro->xp += boi->xp;
            recebeBonus(vaqueiro);
        } else if (vaqueiro->vida==0){
            printf("\nZero.\nVocê não conseguiu concluir a derrubada. Fim de jogo.", boi->nome);
            exit(0);
        } else if (fuga==1){
            printf("\nVocê desistiu da missão. Sem recomoensa.");
            return;
        }

}
void combate(struct Personagem *vaqueiro, struct Boi *boi){
        printf("\nVocê parou numa casa de combate. Prepare-se para lutar contra um boi!");
        int numBoi = (rand() % 2 + 1);
        int fuga = 0;
        switch (numBoi) {
            case 1:
                strcpy(boi->nome,"Boi Pintado");
                boi->resistencia = 30;
                boi->reacao = 6;
                boi->dificuldade = 3;
                boi->xp = 20;
                break;
            case 2:
                strcpy(boi->nome,"Boi Malhado");
                boi->resistencia = 35;
                boi->reacao = 7;
                boi->dificuldade = 4;
                boi->xp = 25;
                break;
            
        }
        printf("\nVocê encontrou o %s! Prepare-se para a derrubada", boi->nome);
        while (boi->resistencia > 0 && vaqueiro->vida > 0 && fuga ==0){
                
            printf("\n%s - Vida: %d, Ataque: %d, Defesa: %d", boi->nome, boi->resistencia, boi->reacao, boi->dificuldade);
            printf("\n%s - Vida: %d, Ataque: %d, Defesa: %d", vaqueiro->nome, vaqueiro->vida, vaqueiro->ataque, vaqueiro->defesa);
            int acao;
            int defesaOriginal = vaqueiro->defesa;
            printf("\nDefina sua ação: 1- Derrubar boi, 2- Segurar o boi, 3- Usar habilidade especial, 4- Pular vez\n:");
            scanf("%d", &acao);
            switch (acao) {
                case 1: 
                    puxadaVaqueiro(vaqueiro, boi);
                    break;
                case 2:
                    printf("\nVVocê segurou o boi e estabilizou sua posição.");
                    vaqueiro->defesa += 2;
                    break;
                case 3:
                    habilidadeEspecial(vaqueiro, boi);
                    break;
                case 4:
                    pularVez(vaqueiro, boi, &fuga);
                        
                    break;
                        

            };
            if (boi->resistencia > 0 && vaqueiro->vida > 0 && fuga == 0) {
                resistenciaBoi(vaqueiro, boi);
            }
            vaqueiro->defesa = defesaOriginal;

        };
        if (boi->resistencia==0){
            printf("\nValeu o boi.\nVocê derrobou o %s!", boi->nome);
            vaqueiro->xp += boi->xp;
            recebeBonus(vaqueiro);
        } else if (vaqueiro->vida==0){
            printf("\nZero.\nVocê não conseguiu concluir a derrubada. Fim de jogo.", boi->nome);
            exit(0);
        } else if (fuga == 1){
            printf("\nVocê desistiu da tentativa de derrubada. Prepare-se para a próxima rodada.");
            return;
        }
}

void avancaCasa(int *posicao, char casas[12][20], Personagem *vaqueiro, Boi *boi) {
    int d6 = (rand() % 11 + 1);
    printf("\nVocê tirou %d no dado.", d6);
    *posicao +=d6;
    
    switch (*posicao) {
        case 1:
            printf("\nVocê parou numa casa vazia. Nada acontece. \nSe prepare-se para a próxima rodada.");
            break;
        case 2:
            combate(vaqueiro, boi);

            break;

        case 3:
            tesouro(vaqueiro);
            break;
        case 4:
            combate(vaqueiro, boi);
            break;
        case 5:
            printf("\nVocê parou numa casa de cura. Você recuperou 20 pontos de vida.");
            vaqueiro->vida += 50;
            break;
        case 6:
            printf("\nVocê parou numa casa de armadilha. Você perdeu 20 pontos de vida.");
            vaqueiro->vida -= 20;
            break;
        case 7:
            combate(vaqueiro, boi);
            break;
        case 8:
            printf("\nVocê parou numa casa vazia. Nada acontece. \nSe prepare-se para a próxima rodada.");
            break;
        case 9:
            tesouro(vaqueiro);
            break;
        case 11:
            missao(vaqueiro, boi);
            break;
        

    };

    

};

int main(){

    char casas[12][20] = {"Início","Vazia","Combate","Tesouro","Combate","Cura","Armadilha","Combate","Vazia","Tesouro","Missão","Chefe / Fim"};
    int posicao =0;
    

    struct Personagem vaqueiro;
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
            strcpy(vaqueiro.nome,"Vaqueiro Nym");
            strcpy(vaqueiro.classe,"Equilibrado");
            vaqueiro.vida = 110;
            vaqueiro.ataque = 12;
            vaqueiro.forca = 12;
            vaqueiro.defesa = 9;
            vaqueiro.agilidade = 10;
            vaqueiro.inteligencia = 6;
            vaqueiro.bonus=2;
            vaqueiro.chanceFuga = 25;
            strcpy(vaqueiro.equipamento,"Cavalo Ventania, gibão de couro");
            strcpy(vaqueiro.especial,"Laço Certeiro");
            break;
        case 2:
            strcpy(vaqueiro.nome,"Vaqueira Marta");
            strcpy(vaqueiro.classe,"Força");
            vaqueiro.vida = 130;
            vaqueiro.ataque = 14;
            vaqueiro.forca = 14;
            vaqueiro.defesa = 12; 
            vaqueiro.agilidade = 7;
            vaqueiro.inteligencia = 5;
            vaqueiro.bonus=3;
            vaqueiro.chanceFuga = 20;
            strcpy(vaqueiro.equipamento,"Cavalo Trovão, perneira reforçada, laço pesado");
            strcpy(vaqueiro.especial,"Puxada de Ferro");
            break;

        case 3:
            strcpy(vaqueiro.nome,"Vaqueiro Zé Relâmpago");
            strcpy(vaqueiro.classe,"Agilidade");
            vaqueiro.vida = 95;
            vaqueiro.ataque = 9;
            vaqueiro.forca = 9;
            vaqueiro.defesa = 8;
            vaqueiro.agilidade = 15;
            vaqueiro.bonus=4;
            vaqueiro.inteligencia = 8;
            vaqueiro.chanceFuga = 25;
            strcpy(vaqueiro.equipamento,"Cavalo Seta, esporas, chapéu de couro");
            strcpy(vaqueiro.especial,"Corrida Relâmpago");
            break;
    };
    vaqueiro.habilidadeEspecial = 1;

    printf("\nFase 1");
    printf("\nMissão: derrubar 2 bois e vencer o chefe da fase, o Boi Caboclo. Dificuldade: baixa.");

    printf("\nBoi          Descrição                  Vida  Ataque  Defesa  XP");
    printf("\nBoi Pintado  Boi jovem e arisco         30    6       3       20");
    printf("\nBoi Malhado  Boi rápido e imprevisível  35    7       4       25");
    printf("\nBoi Caboclo  Chefe da fase Mirim        40    8       5       30");

    printf("\n%s, você está na casa %s.", vaqueiro.nome, casas[posicao]);
   
   printf("\n\nLançando dados para avançar de casa...");

   avancaCasa(&posicao, casas, &vaqueiro, &boi);

   
   
    return 0;


    
    
};
