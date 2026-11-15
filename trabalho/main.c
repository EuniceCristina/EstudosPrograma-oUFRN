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


void iniciarFase(struct Personagem *vaqueiro,int *posicao,int *pegadaBoi,int *vitoriaChefe){

    vaqueiro->habilidadeEspecial = 1;    /* data */
    *posicao=0;
    *pegadaBoi=0;
    *vitoriaChefe=0;
};

void tesouro(struct Personagem *vaqueiro){
    printf("\n\nVocê encontrou um tesouro! ");
    
    int sorteio = rand() % 4 + 1;

    switch (sorteio) {
        case 1:
            vaqueiro->forca += 2;
            printf("\n\nVocê ganhou +2 de força!");
            break;

        case 2:
            vaqueiro->defesa += 2;
            printf("\n\nVocê ganhou +2 de defesa!");
            break;

        case 3:
            vaqueiro->agilidade += 2;
            printf("\n\nVocê ganhou +2 de agilidade!");
            break;

        case 4:
            vaqueiro->inteligencia += 2;
            printf("\n\nVocê ganhou +2 de inteligência!");
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
    printf("\n\nVocê reduziu a resistência do boi %s em %d.", boi->nome, dano);
    boi->resistencia -= dano;
    if (boi->resistencia <= 0) {
        boi->resistencia = 0;
        

    }
    printf("\n\n%s - Vida: %d, Ataque: %d, Defesa: %d", boi->nome, boi->resistencia, boi->reacao, boi->dificuldade);

}
void habilidadeEspecial(struct Personagem *vaqueiro, struct Boi *boi){
    if (boi->resistencia <= 0) {
         return;
     }
    if (vaqueiro->habilidadeEspecial == 0) {
        printf("\n\nVocê já usou sua habilidade especial nesta batalha. Escolha outra ação.");
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

void missao(struct Personagem *vaqueiro, struct Boi *boi, int *pegadaBoi,int fase,int *vitoriaChefe){
    int fuga=0;
    printf("\n\nVocê chegou na casa da missão. Prepare-se para lutar contra o chefe da fase, o Boi Caboclo!");
    if (fase==1){
        strcpy(boi->nome,"Boi Caboclo");
        boi->resistencia = 40;
        boi->reacao = 8;
        boi->dificuldade = 5;
        boi->xp = 30;
        
    } else if(fase==2){
        strcpy(boi->nome,"Boi Ferradura");
        boi->resistencia = 70;
        boi->reacao = 13;
        boi->dificuldade = 9;
        boi->xp = 55;
       
    } else if (fase==3){
        strcpy(boi->nome,"Boi Lendario Corone");
        boi->resistencia = 140;
        boi->reacao = 20;
        boi->dificuldade = 16;
        boi->xp = 120;
        
    };
    
    printf("\n\nVocê chegou na casa da missão. Prepare-se para lutar contra o chefe da fase, o %s!",boi->nome);
    while (boi->resistencia > 0 && vaqueiro->vida > 0 && fuga ==0){
                
    printf("\n\n%s - Vida: %d, Ataque: %d, Defesa: %d", boi->nome, boi->resistencia, boi->reacao, boi->dificuldade);
    printf("\n%s - Vida: %d, Ataque: %d, Defesa: %d", vaqueiro->nome, vaqueiro->vida, vaqueiro->ataque, vaqueiro->defesa);
    int acao;
    int defesaOriginal = vaqueiro->defesa;
    printf("\n\nDefina sua ação: 1- Derrubar boi, 2- Segurar o boi, 3- Usar habilidade especial, 4- Pular vez\n:");
    scanf("%d", &acao);
    switch (acao) {
        case 1: 
            puxadaVaqueiro(vaqueiro, boi);
            break;
        case 2:
            printf("\n\nVVocê segurou o boi e estabilizou sua posição.");
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
            printf("\n\nValeu o boi.\nVocê derrobou o %s!", boi->nome);
            
            vaqueiro->xp += boi->xp;
            *vitoriaChefe=1;
            recebeBonus(vaqueiro);
        } else if (vaqueiro->vida==0){
            printf("\nZero.\nVocê não conseguiu concluir a derrubada. Fim de jogo.", boi->nome);
            exit(0);
        } else if (fuga==1){
            printf("\n\nVocê desistiu da missão. Sem recomoensa.");
            return;
        }


};
void combate(struct Personagem *vaqueiro, struct Boi *boi, int *pegadaBoi,int fase){
        printf("\n\nVocê parou numa casa de combate. Prepare-se para lutar contra um boi!");
        
        int fuga = 0;
        int numBoi = rand() % 2 + 1;
        if (fase == 1) {
        if (numBoi == 1) {
            strcpy(boi->nome, "Boi Pintado");
            boi->resistencia = 30;
            boi->reacao = 6;
            boi->dificuldade = 3;
            boi->xp = 20;
        } else {
            strcpy(boi->nome, "Boi Malhado");
            boi->resistencia = 35;
            boi->reacao = 7;
            boi->dificuldade = 4;
            boi->xp = 25;
        }
        } else if (fase == 2) {
        if (numBoi == 1) {
            strcpy(boi->nome, "Boi Corrente");
            boi->resistencia = 60;
            boi->reacao = 10;
            boi->dificuldade = 7;
            boi->xp = 45;
        } else {
            strcpy(boi->nome, "Boi Ventania");
            boi->resistencia = 65;
            boi->reacao = 12;
            boi->dificuldade = 8;
            boi->xp = 50;
            }
        } else if (fase==3){
           if (numBoi == 1) {
            strcpy(boi->nome, "Boi Tempestade");
            boi->resistencia = 100;
            boi->reacao = 16;
            boi->dificuldade = 12;
            boi->xp = 80;
        } else {
            strcpy(boi->nome, "Boi Aço");
            boi->resistencia = 110;
            boi->reacao = 18;
            boi->dificuldade = 14;
            boi->xp = 90;
            } 
        }

        
        printf("\nVocê encontrou o %s! Prepare-se para a derrubada", boi->nome, *pegadaBoi);
        while (boi->resistencia > 0 && vaqueiro->vida > 0 && fuga ==0){
            printf("\n\n%s - Vida: %d, Ataque: %d, Defesa: %d", boi->nome, boi->resistencia, boi->reacao, boi->dificuldade);
            printf("\n%s - Vida: %d, Ataque: %d, Defesa: %d", vaqueiro->nome, vaqueiro->vida, vaqueiro->ataque, vaqueiro->defesa);
            int acao;
            int defesaOriginal = vaqueiro->defesa;
            

            

            vaqueiro->habilidadeEspecial = 1;
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
        printf("\n\n<Tecle ENTER para continuar>");
        while( getchar() != '\n' ); 
        system("cls");
        if (boi->resistencia==0){
            printf("\n\nValeu o boi.\nVocê derrobou o %s!", boi->nome);
            *pegadaBoi+=1;
            vaqueiro->xp += boi->xp;
            recebeBonus(vaqueiro);
        } else if (vaqueiro->vida==0){
            printf("\nZero.\nVocê não conseguiu concluir a derrubada. Fim de jogo.", boi->nome);
            exit(0);
        } else if (fuga == 1){
            printf("\n\nVocê desistiu da tentativa de derrubada. Prepare-se para a próxima rodada.");
            return;
        }
}
void avancaCasa(int *posicao, char casas[12][20], Personagem *vaqueiro, Boi *boi, int *pegadaBoi,int fase,int *vitoriaChefe){ 
    int meta=0;
    if (fase==1){
        meta=2;
    }else if (fase==2){
        meta=3;
    }else if(fase==3){
        meta=4;
    }
    while (*pegadaBoi <meta || *vitoriaChefe==0){
        int d6 = (rand() % 11 + 1);
        printf("\n\nVocê tirou %d no dado.", d6);
        *posicao +=d6;
        if (*posicao > 11) {
            *posicao = *posicao % 12;
        }
        switch (*posicao) {
            case 1:
                printf("\n\nVocê parou numa casa vazia. Nada acontece. \nSe prepare-se para a próxima rodada.");
                break;
            case 2:
                combate(vaqueiro, boi, pegadaBoi,fase);

                break;

            case 3:
                tesouro(vaqueiro);
                break;
            case 4:
                combate(vaqueiro, boi, pegadaBoi,fase);
                break;
            case 5:
                printf("\n\nVocê parou numa casa de cura. Você recuperou 20 pontos de vida.");
                vaqueiro->vida += 50;
                break;
            case 6:
                printf("\n\nVocê parou numa casa de armadilha. Você perdeu 20 pontos de vida.");
                vaqueiro->vida -= 20;
                break;
            case 7:
                combate(vaqueiro, boi, pegadaBoi,fase);
                break;
            case 8:
                printf("\n\nVocê parou numa casa vazia. Nada acontece. \nSe prepare-se para a próxima rodada.");
                break;
            case 9:
                tesouro(vaqueiro);
                break;
            case 11:
                missao(vaqueiro, boi, pegadaBoi, fase,vitoriaChefe);
                break;
        
            

        };
        printf("\n\n<Tecle ENTER para continuar>");
        while( getchar() != '\n' ); 
        system("cls");
   

    };
    
    printf("\n\nParabéns, você concluiu a missão e derrubou 2 bois! Você venceu a fase!");
    printf("\n\n<Tecle ENTER para continuar>");
        while( getchar() != '\n' ); 
        system("cls");
    

};


int main(){

    char casas[12][20] = {"Início","Vazia","Combate","Tesouro","Combate","Cura","Armadilha","Combate","Vazia","Tesouro","Missão","Chefe / Fim"};
    int posicao =0;
    int pegadaBoi =0;
    int vitoriaChefe=0;
    struct Personagem vaqueiro;
    struct Boi boi;
    int fase =1;
    printf("\n\n1- Vaqueiro Nym\n" 
        "Classe: Equilibrado\n" 
        "Vida: 110\n" 
        "Força: 12\n" 
        "Defesa: 9\n" 
        "Agilidade: 10\n" 
        "Inteligência: 6\n" 
        "Chance de fuga: 25\n"
        "Equipamentos: Cavalo Ventania,gibão de couro\n"
        "Habilidade especial:Laço Certeiro(ataque com bônus de dano fixo) ");

    printf("\n\n2- Vaqueira Marta\n" 
        "Classe: Força\n" 
        "Vida: 130\n" 
        "Força: 14\n" 
        "Defesa: 12\n" 
        "Agilidade: 7\n" 
        "Inteligência: 5\n" 
        "Chance de fuga: 20\n"
        "Equipamentos: Cavalo Trovão, perneira reforçada, laço pesado\n"
        "Habilidade especial: Puxada de Ferro(reduz a defesa do boi por um turno)\n");

     printf("\n\n3- Vaqueiro Zé Relâmpago\n" 
        "Classe: Agilidade\n" 
        "Vida: 95\n" 
        "Força: 9\n" 
        "Defesa: 8\n" 
        "Agilidade: 15\n" 
        "Inteligência: 8\n" 
        "Chance de fuga: 25\n"
        "Equipamentos: Cavalo Seta, esporas, chapéu de couro\n"
        "Habilidade especial:Corrida Relâmpago(aumenta chance de fuga) ");


    printf("\n\nEscolha seu personagem: ");
    int numPersonagem;
    scanf("%d", &numPersonagem);

    switch (numPersonagem) {
        case 1: 
            strcpy(vaqueiro.nome,"Vaqueiro.ym");
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
            strcpy(vaqueiro.nome,"Vaqueiro.é Relâmpago");
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

    printf("\n\nFase 1 - Mirim");
    printf("\nMissão: derrubar 2 bois e vencer o chefe da fase, o Boi Caboclo. Dificuldade: baixa.");

    printf("\nBoi          Descricao                  Vida  Ataque  Defesa  XP");
    printf("\nBoi Pintado  Boi jovem e arisco         30    6       3       20");
    printf("\nBoi Malhado  Boi rapido e imprevisivel  35    7       4       25");
    printf("\nBoi Caboclo  Chefe da fase Mirim        40    8       5       30");
    iniciarFase(&vaqueiro,&posicao,&pegadaBoi,&vitoriaChefe);
    printf("\n\n%s, você está na casa %s.", vaqueiro.nome, casas[posicao]);
    printf("\n\nLançando dados para avançar de casa...");
    avancaCasa(&posicao, casas, &vaqueiro, &boi, &pegadaBoi,fase,&vitoriaChefe);
    fase+=1;
    
    printf("\n\nFase 2 - Arpirante");
    printf("\nMissão: derrubar 3 bois, incluindo o chefe Boi Ferradura. Dificuldade: média.");

    printf("\nBoi            Descricao                   Vida  Ataque  Defesa   XP");
    printf("\nBoi Corrente   Boi jovem e arisco          60    10       7       45");
    printf("\nBoi Ventania   Boi rapido e imprevisivel   65    12       8       50");
    printf("\nBoi Ferradura  Chefe da fase Aspirante     70    13       9       55");

    printf("\n\n%s, você está na casa %s.", vaqueiro.nome, casas[posicao]);
   
   
   iniciarFase(&vaqueiro,&posicao,&pegadaBoi,&vitoriaChefe);
   printf("\n\nLançando dados para avançar de casa...");
   avancaCasa(&posicao, casas, &vaqueiro, &boi, &pegadaBoi,fase,&vitoriaChefe);

   fase+=1;
   printf("\n\nFase 3 - Profissional");
   printf("\nMissão: derrubar 3 bois e vencer o Boi Lendário Coroné. Dificuldade: alta.");
   
    printf("\nBoi                    Descricao                  Vida  Ataque  Defesa  XP");
    printf("\nBoi Tempestade         Boi jovem e arisco         30    6       3       20");
    printf("\nBoi Aço                Boi rapido e imprevisivel  35    7       4       25");
    printf("\nBoi Lendário Coroné    Chefe da fase Mirim        40    8       5       30");
   
   printf("\n\n%s, você está na casa %s.", vaqueiro.nome, casas[posicao]);
   
   
   iniciarFase(&vaqueiro,&posicao,&pegadaBoi,&vitoriaChefe);
   printf("\n\nLançando dados para avançar de casa...");
   avancaCasa(&posicao, casas, &vaqueiro, &boi, &pegadaBoi,fase,&vitoriaChefe);
    return 0;


    
    
};
