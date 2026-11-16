#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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



/* Interface narrativa: as pausas usam ENTER sem depender de system("pause"). */
void linha(void) {
    printf("\n============================================================\n");
}
void limparTela(void) {
    system("cls"); /* Terminal do Windows */
}
void esperarEnter(void) {
    int c;
    printf("\n\n[Pressione ENTER para continuar...] ");
    fflush(stdout);
    while ((c = getchar()) != '\n' && c != EOF) { }
}
int lerEscolha(void) {
    char entrada[64];
    int valor;
    while (1) {
        if (!fgets(entrada, sizeof(entrada), stdin)) return 4;
        if (sscanf(entrada, "%d", &valor) == 1) return valor;
        printf("Digite o numero da opcao: ");
    }
}
void titulo(const char *texto) {
    linha();
    printf("                 %s", texto);
    linha();
}
void locutor(const char *fala) {
    printf("\n[LOCUTOR] %s\n", fala);
}
void abertura(void) {
    limparTela();
    titulo("VAQUEJADA RPG - O DESAFIO DO LOCUTOR");
    printf("\nNo coracao do sertao, a poeira sobe e a arquibancada vibra.\n");
    printf("O maior circuito de vaquejada da regiao esta prestes a comecar.\n");
    locutor("Boa noite, minha gente! Hoje a pista vai conhecer um novo campeao!");
    locutor("Tres etapas esperam por voce: Mirim, Aspirante e Profissional.");
    printf("\nCada derrubada exige coragem, estrategia e um pouco de sorte.\n");
    esperarEnter();
    limparTela();
}
void apresentarFase(int fase, const Personagem *p) {
    limparTela();
    if (fase == 1) {
        titulo("ETAPA 1 - MIRIM");
        locutor("O sol ainda esta alto. E hora de provar seu valor na primeira pista!");
        printf("\n%s precisa derrubar 2 bois comuns e superar o Boi Caboclo.\n", p->nome);
        printf("Bois da etapa: Pintado, Malhado e Caboclo (chefe).\n");
    } else if (fase == 2) {
        titulo("ETAPA 2 - ASPIRANTE");
        locutor("A arquibancada cresceu e os bois estao mais fortes!");
        printf("\n%s precisa derrubar 3 bois comuns e superar o Boi Ferradura.\n", p->nome);
        printf("Bois da etapa: Corrente, Ventania e Ferradura (chefe).\n");
    } else {
        titulo("ETAPA 3 - PROFISSIONAL");
        locutor("Chegou a grande final! O titulo do circuito esta em jogo!");
        printf("\n%s precisa derrubar 4 bois comuns e superar o lendario Corone.\n", p->nome);
        printf("Bois da etapa: Tempestade, Aco e Lendario Corone (chefe).\n");
    }
    printf("\nA experiencia e os atributos conquistados acompanham o vaqueiro.\n");
    printf("Vida atual: %d | XP: %d\n", p->vida, p->xp);
    esperarEnter();
    limparTela();
}

void iniciarFase(struct Personagem *vaqueiro,int *posicao,int *pegadaBoi,int *vitoriaChefe){

    vaqueiro->habilidadeEspecial = 1;    /* data */
    *posicao=0;
    *pegadaBoi=0;
    *vitoriaChefe=0;
};

void tesouro(struct Personagem *vaqueiro){
    titulo("RECOMPENSA NA PISTA");
    locutor("Uma surpresa boa no caminho! O vaqueiro ganhou um presente!");
    
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
void usoHabilidade(struct Personagem *vaqueiro, struct Boi *boi,int fase) {

    if (boi->resistencia <= 0) {
        return;
    }

    if (vaqueiro->habilidadeEspecial == 0) {
        printf("\n[AVISO] Voce ja utilizou sua habilidade especial!");
        printf("\nEscolha outra acao.\n");
        return;
    }

    titulo("HABILIDADE ESPECIAL");

    printf("\n[LOCUTOR] %s vai usar sua habilidade especial!\n",
           vaqueiro->nome);

    if (fase== 1) {

        locutor("QUE LANCAMENTO! O laco foi certeiro!");

        int d20 = rand() % 20 + 1;
        int ataque = d20 + vaqueiro->ataque + vaqueiro->bonus + 5;
        int dano = ataque - boi->dificuldade;

        if (dano <= 0) {
            dano = 1;
        }

        boi->resistencia -= dano;

        if (boi->resistencia < 0) {
            boi->resistencia = 0;
        }

        printf("\nDado: %d", d20);
        printf("\nForca total da puxada: %d", ataque);
        printf("\nDano causado: %d", dano);
        printf("\nResistencia restante do boi: %d\n",
               boi->resistencia);
        vaqueiro->vida+=20;

    } else if (fase==2) {

        locutor("QUE FORCA! A vaqueira executou a Puxada de Ferro!");

        boi->dificuldade -= 2;

        if (boi->dificuldade < 0) {
            boi->dificuldade = 0;
        }

        printf("\nDefesa do boi reduzida em 2 pontos!");
        printf("\nDefesa atual do boi: %d\n",
               boi->dificuldade);
        vaqueiro->vida+=300;

    } else if (fase==3) {

        locutor("QUE VELOCIDADE! O vaqueiro dispara pela pista!");

        vaqueiro->chanceFuga += 10;

        printf("\nChance de fuga aumentada em 10 pontos!");
        printf("\nChance de fuga atual: %d\n",
               vaqueiro->chanceFuga);
        vaqueiro->vida+=600;

    } else {
        printf("\n[ERRO] Habilidade especial nao reconhecida!\n");
        return;
    }

    vaqueiro->habilidadeEspecial = 0;
    

    printf("\n[AVISO] Habilidade especial utilizada!");
    printf("\nVoce nao podera utiliza-la novamente neste combate.\n");
}
void pularVez(struct Personagem *vaqueiro, struct Boi *boi, int *fuga) {
    (void)boi;
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
     printf("\n[LOCUTOR] %s reagiu! Voce perdeu %d pontos de vida.", boi->nome, pregresso);
     printf("\n%s - Vida: %d, Ataque: %d, Defesa: %d\n", vaqueiro->nome, vaqueiro->vida, vaqueiro->ataque, vaqueiro->defesa);
}   

void missao(struct Personagem *vaqueiro, struct Boi *boi, int *pegadaBoi,int fase,int *vitoriaChefe){
    (void)pegadaBoi;
    int fuga=0;
    titulo("DESAFIO DO CHEFE");
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
    
    printf("\n[LOCUTOR] A torcida se levanta! O chefe %s entrou na pista!\n", boi->nome);
    
    esperarEnter();
    while (boi->resistencia > 0 && vaqueiro->vida > 0 && fuga ==0){
                
    printf("\n\n%s - Vida: %d, Ataque: %d, Defesa: %d", boi->nome, boi->resistencia, boi->reacao, boi->dificuldade);
    printf("\n%s - Vida: %d, Ataque: %d, Defesa: %d", vaqueiro->nome, vaqueiro->vida, vaqueiro->ataque, vaqueiro->defesa);
    
    typedef enum {
        DERRUBAR_BOI = 1,
        SEGURAR_BOI = 2,
        USAR_HABILIDADE = 3,
        PULAR_VEZ = 4
    } AcaoCombate;
    AcaoCombate acao;
    int defesaOriginal = vaqueiro->defesa;
    printf("\n\nDefina sua ação: 1- Derrubar boi, 2- Segurar o boi, 3- Usar habilidade especial, 4- Pular vez\n:");
    acao = (AcaoCombate) lerEscolha();
    switch (acao) {
        case DERRUBAR_BOI: 
            puxadaVaqueiro(vaqueiro, boi);
            break;
        case SEGURAR_BOI:
            locutor("Boa defesa! O vaqueiro se firmou na sela!");
            vaqueiro->defesa += 2;
            break;
        case USAR_HABILIDADE:
            usoHabilidade(vaqueiro, boi,fase);
            break;
        case PULAR_VEZ:
            pularVez(vaqueiro, boi, &fuga);
            break;
                        

         };
        if (boi->resistencia > 0 && vaqueiro->vida > 0 && fuga == 0) {
            resistenciaBoi(vaqueiro, boi);
        }
        vaqueiro->defesa = defesaOriginal;
        

        };
        if (boi->resistencia==0){
            printf("\n[LOCUTOR] VALEU O BOI! Voce derrubou %s!\n", boi->nome);
            
            vaqueiro->xp += boi->xp;
            *vitoriaChefe=1;
            recebeBonus(vaqueiro);
        } else if (vaqueiro->vida==0){
            titulo("GAME OVER");
            locutor("O vaqueiro nao conseguiu completar a prova. Fim de jogo!");
            exit(0);
        } else if (fuga==1){
            locutor("O vaqueiro recuou! O chefe continua esperando. Sem recompensa.");
            return;
        }


};
void combate(struct Personagem *vaqueiro, struct Boi *boi, int *pegadaBoi,int fase){
        titulo("ENTRADA NA PISTA");
        locutor("Mais um desafio! Os portoes vao se abrir!");
        
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

        
        printf("\n[LOCUTOR] O boi %s entrou na pista! Prepare o laco!\n", boi->nome);
        
        esperarEnter();
        while (boi->resistencia > 0 && vaqueiro->vida > 0 && fuga ==0){
            printf("\n\n%s - Vida: %d, Ataque: %d, Defesa: %d", boi->nome, boi->resistencia, boi->reacao, boi->dificuldade);
            printf("\n%s - Vida: %d, Ataque: %d, Defesa: %d", vaqueiro->nome, vaqueiro->vida, vaqueiro->ataque, vaqueiro->defesa);
            int acao;
            int defesaOriginal = vaqueiro->defesa;
            

            

            printf("\nDefina sua ação: 1- Derrubar boi, 2- Segurar o boi, 3- Usar habilidade especial, 4- Pular vez\n:");
            acao = lerEscolha();
            switch (acao) {
                case 1: 
                    puxadaVaqueiro(vaqueiro, boi);
                    break;
                case 2:
                    locutor("Boa defesa! O vaqueiro se firmou na sela!");
                    vaqueiro->defesa += 2;
                    break;
                case 3:
                    usoHabilidade(vaqueiro, boi,fase);
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
        esperarEnter();
        limparTela();
        if (boi->resistencia==0){
            printf("\n[LOCUTOR] VALEU O BOI! Voce derrubou %s!\n", boi->nome);
            *pegadaBoi+=1;
            vaqueiro->xp += boi->xp;
            recebeBonus(vaqueiro);
        } else if (vaqueiro->vida==0){
            titulo("GAME OVER");
            locutor("O vaqueiro nao conseguiu completar a prova. Fim de jogo!");
            exit(0);
        } else if (fuga == 1){
            locutor("A tentativa terminou sem derrubada. De volta ao tabuleiro!");
            return;
        }
}
void avancaCasa(int *posicao, char casas[11][20], Personagem *vaqueiro, Boi *boi, int *pegadaBoi,int fase,int *vitoriaChefe){ 
    int meta=0;
    if (fase==1){
        meta=2;
    }else if (fase==2){
        meta=3;
    }else if(fase==3){
        meta=4;
    }
    while (*pegadaBoi < meta || *vitoriaChefe == 0) {
        if (*pegadaBoi >= meta){
            missao(vaqueiro, boi, pegadaBoi, fase, vitoriaChefe);
        };
        titulo("RODADA NA PISTA");
        printf("\nFase: %d | %s | Vida: %d | XP: %d\n", fase, vaqueiro->nome, vaqueiro->vida, vaqueiro->xp);
        printf("Derrubadas comuns: %d/%d | Chefe vencido: %s\n",
               *pegadaBoi, meta, *vitoriaChefe ? "SIM" : "NAO");
        locutor("A pista esta livre! Vamos ver quantas casas o vaqueiro avanca!");
        esperarEnter();
        int passos = rand() % 10 + 1; /* Mantida a rolagem original do projeto. */
        printf("\n[LOCUTOR] O dado de avancar marcou %d!\n", passos);
        *posicao += passos;
        if (*posicao > 10) *posicao = *posicao % 10;
        printf("[PISTA] Casa %d - %s\n", *posicao + 1, casas[*posicao]);
        esperarEnter();
        limparTela();
        switch (*posicao) {
            case 0:
                locutor("De volta ao ponto de partida! A torcida ainda esta com voce!");
                break;
            case 1:
            case 8:
                titulo("TRECHO TRANQUILO");
                locutor("Sem surpresa por aqui. Aproveite para recuperar o folego!");
                break;
            case 2:
            case 4:
            case 7:
                combate(vaqueiro, boi, pegadaBoi, fase);
                break;
            case 3:
            case 9:
                locutor("Uma recompensa apareceu na trilha do competidor!");
                tesouro(vaqueiro);
                break;
            case 5:
                titulo("PARADA DE RECUPERACAO");
                locutor("A equipe chegou com agua e cuidados para o vaqueiro!");
                vaqueiro->vida += 50; /* Valor original do codigo. */
                printf("\n[EVENTO] +50 pontos de vida. Vida atual: %d\n", vaqueiro->vida);
                break;
            case 6:
                titulo("IMPREVISTO NA PISTA");
                locutor("Uma surpresa no percurso! O vaqueiro perdeu o equilibrio!");
                vaqueiro->vida -= 20;
                if (vaqueiro->vida < 0) vaqueiro->vida = 0;
                printf("\n[EVENTO] -20 pontos de vida. Vida atual: %d\n", vaqueiro->vida);
                if (vaqueiro->vida == 0) {
                    titulo("GAME OVER");
                    locutor("O competidor nao conseguiu continuar o circuito.");
                    esperarEnter();
                    exit(0);
                }
                break;
            case 10:
                if (*vitoriaChefe) {
                    locutor("O chefe ja foi superado! Siga buscando as derrubadas que faltam.");
                } else {
                    missao(vaqueiro, boi, pegadaBoi, fase, vitoriaChefe);
                }
                break;
        }
        printf("\n[PLACAR] Derrubadas: %d/%d | Chefe: %s | Vida: %d | XP: %d\n",
               *pegadaBoi, meta, *vitoriaChefe ? "VENCIDO" : "PENDENTE",
               vaqueiro->vida, vaqueiro->xp);
        esperarEnter();
        limparTela();
    }
    titulo("ETAPA CONCLUIDA!");
    printf("\n[LOCUTOR] QUE ESPETACULO! %s cumpriu a missao da fase %d!\n", vaqueiro->nome, fase);
    printf("Derrubadas comuns: %d | Chefe superado | XP total: %d\n", *pegadaBoi, vaqueiro->xp);
    esperarEnter();
    limparTela();

};


int main(){
    srand((unsigned int)time(NULL));
    abertura();

    char casas[11][20] = {"Início","Vazia","Combate","Tesouro","Combate","Cura","Armadilha","Combate","Vazia","Tesouro","Missão"};
    int posicao =0;
    int pegadaBoi =0;
    int vitoriaChefe=0;
    struct Personagem vaqueiro = {0};
    struct Boi boi;
    int fase =1;
    titulo("ESCOLHA SEU VAQUEIRO");
    locutor("Escolha quem vai representar voce no circuito!");
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
    numPersonagem = lerEscolha();

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
            strcpy(vaqueiro.nome,"Ze Relampago");
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

    titulo("COMPETIDOR CONFIRMADO");
    printf("\n[LOCUTOR] %s entrou no circuito!\n", vaqueiro.nome);
    esperarEnter();
    apresentarFase(1, &vaqueiro);
    iniciarFase(&vaqueiro,&posicao,&pegadaBoi,&vitoriaChefe);
    printf("\n%s, prepare-se para entrar na pista!\n", vaqueiro.nome);
    locutor("O circuito vai comecar!");
    avancaCasa(&posicao, casas, &vaqueiro, &boi, &pegadaBoi,fase,&vitoriaChefe);
    fase+=1;
    
    apresentarFase(2, &vaqueiro);
   iniciarFase(&vaqueiro,&posicao,&pegadaBoi,&vitoriaChefe);
   locutor("O circuito vai comecar!");
   avancaCasa(&posicao, casas, &vaqueiro, &boi, &pegadaBoi,fase,&vitoriaChefe);

   fase+=1;
   apresentarFase(3, &vaqueiro);
   iniciarFase(&vaqueiro,&posicao,&pegadaBoi,&vitoriaChefe);
   locutor("O circuito vai comecar!");
   avancaCasa(&posicao, casas, &vaqueiro, &boi, &pegadaBoi,fase,&vitoriaChefe);
    titulo("GRANDE CAMPEAO DO CIRCUITO");
    locutor("A festa e sua! O sertao inteiro aplaude o novo campeao!");
    printf("\nVaqueiro: %s\nClasse: %s\nVida restante: %d\nXP conquistado: %d\n",
           vaqueiro.nome, vaqueiro.classe, vaqueiro.vida, vaqueiro.xp);
    esperarEnter();
    return 0;
};
