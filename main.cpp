#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
using namespace std;
char PulaTexto;

//Declara os status do jogador principal
struct Jogador {
    float vida;
    float mana;

//Função responsável por perder vida no combate
    void perderVida(float x) {
        vida -= x;
        if (vida < 0) {
            cout << "\n\n\t\tJOGADOR ESTÁ MORTO!";
            exit(0);
        }
    }

//Função responsável pela perca de mana ao usar skills
    void perderMana(float x) {
        mana -= x;
        if (mana < 0) {
            mana = 0;
        }
    }

//Função responsável pelo ganho de vida ao usar poções
    void ganharVida(float x) {
        vida += x;
        if (vida >= 100) {
            vida = 100;
            }
    }
    
       void ganharVida2(float x) {
        vida += x;
        if (vida >= 300) {
            vida = 300;
            }
    }

//Função responsável pelo ganho de mana ao usar poções
    void ganharMana(float x) {
        mana += x;
        if (mana >= 100) {
            mana = 100;
        }
    }
    
        void ganharMana2(float x) {
        mana += x;
        if (mana >= 300) {
            mana = 300;
        }
    }
};

//Declara o status basicos de todos os chefões do jogo
struct Boss {
    float vida;

//Função responsável por perder vida no combate
    void perderVida(float x) {
        vida -= x;
       
        if(vida < 0) {
            vida = 0;
        }
    }
};

//Função responsável por limpar cmd
void limparTela() {
    cout << "\033[2J\033[H";
}

//Função responsável por mostrar o menu de opções
void mostrarMenuCombate() {
    cout << endl
         << "\nMenu de opções: "
         << "\t1. Atacar\t2. Usar Itens\t\t3. Fugir" << endl
         << endl
         << "O que você deseja fazer?" << endl
         << endl;
}

//Função responsável pelo sistema de combate, indicando o que deve será feito ao utilizar as habilidades
void usarHabilidade(Jogador &jogador, Boss &boss, int habilidade) {
    int Asc = 35 + rand() % 50, CustoAsc = 10;
    int Fios = 15 + rand() % 50, CustoFios = 15;
    int Julgamento = 50 + rand() % 50, CustoJulgamento = 10;
    int Cura = 45 + rand() % 10, CustoCura = 75; 

    switch (habilidade) {
        case 1:
            if(jogador.mana <= CustoAsc) {
                cout << endl << "Não é possível utilizar esta skill, jogador sem mana!\n";
            }
            else {
            cout << endl
                 << "\n\tAS MINHAS VONTADES ASCENDEM AOS CÉUS!" << endl << endl
                 << "Você usou ASCENSÃO ANGELICAL! Seu dano foi de " << Asc;
            cout << " e gastou " << CustoAsc << " de sua mana.\n";
            jogador.perderMana(CustoAsc);
            boss.perderVida(Asc);
            }
            break;

        case 2:
            if(jogador.mana <= CustoFios) {
                cout << endl << "Não é possível utilizar esta skill, jogador sem mana!\n";
            }
            else {
            cout << endl
                 << "\n\tMEUS FIOS DE OURO DEFINIRAM SEU DESTINO!" << endl << endl
                 << "Você usou FIOS DE OURO! Seu dano foi de " << Fios;
            cout << " e gastou " << CustoFios << " de sua mana.\n";
            jogador.perderMana(CustoFios);
            boss.perderVida(Fios);
            }
            break;

        case 3:
            if(jogador.mana <= CustoJulgamento) {
                cout << endl << "Não é possível utilizar esta skill, jogador sem mana!\n";
            }
            else {
            cout << endl
                 << "\n\tQUE A GLÓRIA ETERNA EXECUTE SEU JULGAMENTO!" << endl << endl
                 << "Você usou JULGAMENTO DIVINO! Seu dano foi de " << Julgamento;
            cout << " e gastou " << CustoJulgamento << " de sua mana.\n";
            jogador.perderMana(CustoJulgamento);
            boss.perderVida(Julgamento);
            }
            break;
            
        case 4:
            if(jogador.mana <= CustoJulgamento) {
                cout << endl << "Não é possível utilizar esta skill, jogador sem mana!\n";
            }
            else {
            cout << endl
                 << "\n\tAQUELES QUE USAM DA LUZ PERMANECERAM NA GLÓRIA!" << endl << endl
                 << "Você usou BENÇÃO ETERNA e curou sua vida em: " << Cura;
                 jogador.vida = jogador.vida + Cura;
                 if(jogador.vida > 100) {
                     jogador.vida = 100;
                 }
                 cout << endl << "Vida atual: " << jogador.vida << endl;
                 jogador.perderMana(CustoCura);
            }
                 break;
    }
   
   
    cout << "\nVida atual do boss: " << boss.vida << ".\n";
    cout << "\nMana atual: " << jogador.mana << ".\n";
}

void usarHabilidade2(Jogador &jogador, Boss &boss, int habilidade) {
    int EXC = 35 + rand() % 50 + 100, CustoEXC = 10;
    int CON = 15 + rand() % 50 + 100, CustoCON = 15;
    int DET = 50 + rand() % 50 + 150, CustoDET = 10;
    int BEN = 100 + rand() % 100, CustoBEN = 75; 

    switch (habilidade) {
        case 1:
            if(jogador.mana < CustoEXC) {
                cout << endl << "Não é possível utilizar esta skill, jogador sem mana!\n";
            }
            else {
            cout << endl
                 << "\n\tSINTAM O PODER DA MINHA ONIPRESÊNCIA!!" << endl << endl
                 << "Você usou EXCALIBUR! Seu dano foi de " << EXC;
            cout << " e gastou " << CustoEXC << " de sua mana.\n";
            jogador.perderMana(CustoEXC);
            boss.perderVida(EXC);
            }
            break;

        case 2:
            if(jogador.mana < CustoCON) {
                cout << endl << "Não é possível utilizar esta skill, jogador sem mana!\n";
            }
            else {
            cout << endl
                 << "\n\tEU ESTOU NO CONTROLE DA LINHA DO TEMPO!!" << endl << endl
                 << "Você usou CONTROLE TEMPORAL! Seu dano foi de " << CON;
            cout << " e gastou " << CustoCON << " de sua mana.\n";
            jogador.perderMana(CustoCON);
            boss.perderVida(CON);
            }
            break;

        case 3:
            if(jogador.mana < CustoDET) {
                cout << endl << "Não é possível utilizar esta skill, jogador sem mana!\n";
            }
            else {
            cout << endl
                 << "\n\tNÃO HÁ NADA MAIS BRILHANTE QUE A MINHA LUZ!" << endl << endl
                 << "Você usou DETERMINAÇÃO ANGELICAL! Seu dano foi de " << DET;
            cout << " e gastou " << CustoDET << " de sua mana.\n";
            jogador.perderMana(CustoDET);
            boss.perderVida(DET);
            }
            break;
            
        case 4:
            if(jogador.mana < CustoBEN) {
                cout << endl << "Não é possível utilizar esta skill, jogador sem mana!\n";
            }
            else {
            cout << endl
                 << "\n\tSINTA O PODER DO EMISSÁRIO DA LUZ!" << endl << endl
                 << "Você usou REJUVENESCER DOURADO e curou sua vida em: " << BEN;
                 jogador.vida = jogador.vida + BEN;
                 if(jogador.vida > 300) {
                     jogador.vida = 300;
                 }
                 cout << endl << "Vida atual: " << jogador.vida << endl;
                 jogador.perderMana(CustoBEN);
            }
                 break;
    }
   
   
    cout << "\nVida atual do boss: " << boss.vida << ".\n";
    cout << "\nMana atual: " << jogador.mana << ".\n";
}

//Determina as ações do chefão aleatóriamente
void acaoDoBoss(Jogador &jogador, Boss &boss) {
    int acaoBoss = rand() % 4 + 1;
    int dano;
    int cura;

    switch (acaoBoss) {
        case 1:
            dano = 20 + rand() % 20;
            cout << endl
                 << "\n\tDesapareçam da minha frente! Que a morte os consuma!" << endl << endl
                 << "\nBaba Lysaga usou Blight! Você recebeu " << dano << " de dano.\n";
            break;

        case 2:
            dano = 15 + rand() % 45;
            cout << endl
                 << "\n\tSentem o medo? Sentem a morte espreitando? A escuridão os abraça!" << endl << endl
                 << "\nBaba Lysaga usou Controle Mental! Você recebeu " << dano << " de dano.\n";
            break;

        case 3:
            dano = 10 + rand() % 30;
            cout << endl
                 << "\n\tAs criaturas deste pântano são minhas amigas... e sua algozes!" << endl << endl
                 << "\nBaba Lysaga invocou Mortos Vivos para te atacar! Você recebeu " << dano << " de dano.\n";
            break;
            
        case 4:
        	dano = 0;
            cura = 50 + rand() % 50;
            cout << endl
                 << "\n\tSinto meu poder transbordando! Pereçam sobre minha maldição!" << endl << endl
                 << "\nBaba Lysaga usou Curar e se curou em: " << cura;
                 boss.vida = boss.vida + cura;
                 if(boss.vida > 300) {
                     boss.vida = 300;
                 }
                 cout << "\nVida atual do boss: " << boss.vida;
                 break;
    }
    jogador.perderVida(dano);
    cout << "\n\nSua vida atual é de: " << jogador.vida << ".\n";
}

void acaoDoBoss1(Jogador &jogador, Boss &boss) {
    int acaoBoss1 = rand() % 3;
    int dano;
    int cura;

    switch (acaoBoss1) {
        case 1:
            dano = 20 + rand() % 10;
            cout << endl
                 << "\n\tVocês são corajosos ou tolos por virem até aqui? Pouco importa, suas vidas terminarão logo." << endl << endl
                 << "\nOs Guardas Vampiros usaram Espadada! Você recebeu " << dano << " de dano.\n";
            break;

        case 2:
            dano = 15 + rand() % 10;
            cout << endl
                 << "\n\tVocês sentiram a presença do Mestre? Ele sabe que estão aqui… e está esperando." << endl << endl
                 << "\nFantasmas usaram Chantagem! Você recebeu " << dano << " de dano.\n";
            break;

        case 3:
            dano = 10 + rand() % 10;
            cout << endl
                 << "\n\tEle nos deu a eternidade, e nós damos a vocês uma morte rápida." << endl << endl
                 << "\nOs zumbis utilizaram Mordida! Você recebeu " << dano << " de dano.\n";
            break;

                 cout << "\nVida atual do boss: " << boss.vida;
                 break;
    }
    jogador.perderVida(dano);
    cout << "\n\nSua vida atual é de: " << jogador.vida << ".\n";
}

void acaoDoBoss2(Jogador &jogador, Boss &boss) {
    int acaoBoss2 = rand() % 3;
    int dano;

    switch (acaoBoss2) {
        case 1:
            dano = 50 + rand() % 25;
            cout << endl
                 << "\n\tVocês acham que minha força reside apenas na escuridão? Que tolice…." << endl << endl
                 << "\nStrahd usou Finger Death! Você recebeu " << dano << " de dano.\n";
            break;

        case 2:
            dano = 75 + rand() % 10;
            cout << endl
                 << "\n\tSintam o verdadeiro poder de um vampiro!" << endl << endl
                 << "\nStrahd usou Charm Person! Você recebeu " << dano << " de dano.\n";
            break;

        case 3:
            dano = 90 + rand() % 9;
            cout << endl
                 << "\n\tEu jogo com vocês, como um gato brinca com um rato. Desesperem-se!" << endl << endl
                 << "\nStrahd usou Golpe Devastador! Você recebeu " << dano << " de dano.\n";
            break;

                 cout << "\nVida atual do boss: " << boss.vida;
                 break;
    }
    jogador.perderVida(dano);
    cout << "\n\nSua vida atual é de: " << jogador.vida << ".\n";
}


//Função responsável pelo sistema de poções
void usarItem(Jogador &jogador, int item) {
    int ganhoMana = 20 + rand() % 50 + 1;
    int ganhoVida = 30 + rand() % 35 + 1;

    switch(item) {
        case 1:
            if(jogador.vida < 100) {
            jogador.ganharVida(ganhoVida);
            cout << " Você regenerou sua vida em: " << ganhoVida << ".";
            }
            else {
            cout << "\nNão foi possível regenerar.";
            }
            break;
       
        case 2:
            if(jogador.mana < 100) {
            jogador.ganharMana(ganhoMana);
            cout << " Você regenerou sua mana em: " << ganhoMana << ".";
            }
            else {
            cout << "\nNão foi possível regenerar.";
            }
            break;
    }
    cout << "\n\nVida atual: " << jogador.vida << ", Mana atual: " << jogador.mana << ".\n";
}

void usarItem2(Jogador &jogador, int item) {
    int ganhoMana = 100 + rand() % 50 + 1;
    int ganhoVida = 100 + rand() % 35 + 1;

    switch(item) {
        case 1:
            if(jogador.vida < 300) {
            jogador.ganharVida2(ganhoVida);
            cout << " Você regenerou sua vida em: " << ganhoVida << ".";
            }
            else {
            cout << "\nNão foi possível regenerar.";
            }
            break;
       
        case 2:
            if(jogador.mana < 300) {
            jogador.ganharMana2(ganhoMana);
            cout << " Você regenerou sua mana em: " << ganhoMana << ".";
            }
            else {
            cout << "\nNão foi possível regenerar.";
            }
            break;
    }
    cout << "\n\nVida atual: " << jogador.vida << ", Mana atual: " << jogador.mana << ".\n";
}

//Função responsável por indicar o inicio do combate
void iniciarCombate(Jogador &jogador, Boss &boss) {
    cout << "\n\nVocê encontrou um chefão! O combate será iniciado.";

    while (boss.vida > 0 && jogador.vida > 0) {
        mostrarMenuCombate();

        int escolha;
        cin >> escolha;

        if (escolha == 1) {
            limparTela();
            int habilidade;
            cout << "\nQual habilidade deseja utilizar: \n";
            cout << "\n\t1. Ascensão Angelical \n\t2. Fios de Ouro \n\t3. Julgamento Divino \n\t4. Benção Eterna\n\n";
            cin >> habilidade;

            usarHabilidade(jogador, boss, habilidade);

            if (boss.vida <= 0) {
                cout << "\nParabéns! Você derrotou Baba Lysaga.\n";
                break;
            }
            acaoDoBoss(jogador, boss);
        }
        else if (escolha == 2) {
            limparTela();
            int item;
            cout << "\n\nQual item deseja utilizar: \n";
            cout << "\t1. Poção de Vida \n\t2. Poção de Mana \n\n";
            cin >> item;
            usarItem(jogador, item);
        }
        else if (escolha == 3) {
            cout << "\nVocê fugiu do combate.\n";
            break;
        }
        else {
            cout << "\nOpção inválida! Tente novamente.\n";
        }
    }
}

void iniciarCombate1(Jogador &jogador, Boss &boss) {
    cout << "\n\nVocê deverá enfrentar os guardas de Ravenloft! O combate será iniciado.";

    while (boss.vida > 0 && jogador.vida > 0) {
        mostrarMenuCombate();

        int escolha;
        cin >> escolha;

        if (escolha == 1) {
            limparTela();
            int habilidade;
            cout << "\nQual habilidade deseja utilizar: \n";
            cout << "\n\t1. Ascensão Angelical \n\t2. Fios de Ouro \n\t3. Julgamento Divino \n\t4. Benção Eterna\n\n";
            cin >> habilidade;

            usarHabilidade(jogador, boss, habilidade);

            if (boss.vida <= 0) {
                cout << "\nParabéns! Você venceu o exército de Strahd.\n";
                break;
            }
            acaoDoBoss1(jogador, boss);
        }
        else if (escolha == 2) {
            limparTela();
            int item;
            cout << "\n\nQual item deseja utilizar: \n";
            cout << "\t1. Poção de Vida \n\t2. Poção de Mana \n\n";
            cin >> item;
            usarItem(jogador, item);
        }
        else if (escolha == 3) {
            cout << "\nVocê fugiu do combate.\n";
            break;
        }
        else {
            cout << "\nOpção inválida! Tente novamente.\n";
        }
    }
}

void iniciarCombate2(Jogador &jogador, Boss &boss) {
    cout << "\n\nO embate contra Strahd finalmente começou! O combate será iniciado.";

    while (boss.vida > 0 && jogador.vida > 0) {
        mostrarMenuCombate();

        int escolha;
        cin >> escolha;

        if (escolha == 1) {
            limparTela();
            int habilidade;
            cout << "\nQual habilidade deseja utilizar: \n";
            cout << "\n\t1. Excalibur \n\t2. Controle Temporal \n\t3. Julgamento Divino \n\t4. Benção Eterna\n\n";
            cin >> habilidade;

            usarHabilidade2(jogador, boss, habilidade);

            if (boss.vida <= 0) {
                cout << "\nParabéns! Você venceu Strahd.\n";
                break;
            }
            acaoDoBoss2(jogador, boss);
        }
        else if (escolha == 2) {
            limparTela();
            int item;
            cout << "\n\nQual item deseja utilizar: \n";
            cout << "\t1. Poção de Vida \n\t2. Poção de Mana \n\n";
            cin >> item;
            usarItem2(jogador, item);
        }
        else if (escolha == 3) {
            cout << "\nVocê fugiu do combate.\n";
            break;
        }
        else {
            cout << "\nOpção inválida! Tente novamente.\n";
        }
    }
}

// PulaTexto - Função para "travar" o andamento dos textos da narração
void TravaTexto() {
    cout << "\n\n\tDigite '0' para continuar: ";
    cin >> PulaTexto;
};

// HISTÓRIA: Capítulo I
void CAPI(){
    Jogador jogador1{100, 100};
    Jogador jogador2{300, 300};
    Boss boss1{200};
    Boss boss2{500};
    Boss boss3{1000};
    cout << "\t\t\tCapítulo I\n\t\t Suburbios de Barovia" << endl << "\nEm uma carruagem, um Bardo cantarolava enquanto pilotava:\n"
    << "\n\tNas terras frias de Baróvia, ele reinava,\n" << "\tStrahd von Zarovich, sua fama assombrava.\n" << "\tUm conde guerreiro, de glória faminto,\n"
    << "\tMas o coração ferido o fez distinto.\n\n" << "\tTatyana, tão bela, seu amor despertou,\n" << "\tMas por Sergei, seu irmão, ela se apaixonou.\n"
    << "\tCom inveja e dor, fez um pacto sombrio,\n" << "\tPelo poder eterno, tornou-se um vazio.\n\n" << "\tNo altar de sangue, Sergei ele traiu,\n"
    << "\tTatyana fugiu e da vida partiu.\n" << "\tDas brumas surgiu a maldição cruel,\n" << "\tStrahd imortal, sob um eterno véu.\n\n"
    << "\tAgora ele vaga, sozinho a penar,\n" << "\tEm Baróvia sombria, condenado a reinar.\n" << "\tSeu amor perdido nunca poderá ter,\n"
    << "\tE na noite eterna, só resta sofrer.";
    
    cout << "\t\n\nDeitado nas costas da carruagem, surge um nobre guerreiro,\num manto branco cobria seu corpo, em uma de suas mãos carregava um livro\n"
    << "na outra, um cajado. De forma impaciente ele dispara ao bardo:" << endl 
    << "\n _ Você pode fazer silêncio? Estou tentando meditar!";
    
    TravaTexto();
    
    limparTela();
    
    cout << endl << "O bardo interrompe sua cantoria, e diz ao guerreiro: " << endl
    << "\n\t_ Você poderia ter mais paciência comigo, já estamos chegando senhor!\n\tEssas terras não são visitadas há décadas, o que tanto te interessa?!"
    << endl << "\n\t _ Tenho pendências a resolver com uma moradora antiga,\n\t não que isso seja do interesse de um mero bardo. - Disse o guerreiro impaciente."
    << endl << "\n\t_ S-senhor? Você vê aquilo? - Diz o Bardo com a voz trêmula." << endl << "\t_ Parece que finalmente chegamos - Retoma o guerreiro."
    << endl << endl << "Ambos avistam um pedaço de terra flutuante, com uma cabana de aparência bem velha em cima.\n" 
    << "\n\t_ Bardo, escute-me bem, se você teme a morte não saia daqui,\n\tse esconda dentro da sua carruagem enquanto cuido dos meus afazeres." << endl
    << endl << "O guerreiro então retira a manta que cobria seu corpo, revelando pares de asas em suas costas.\nUma auréola surge em sua cabeça e seus" 
    << " cabelos brancos brilhavam sob a luz do sol." << "\nO livro começou a flutuar na frente do guerreiro, e o cajado se enrolou como um anel em seu dedo."
    << "\nEntão o guerreiro alçou vôo e seguiu em direção aquele pedaço de terra." << endl << endl << "Ao aterrissar, um véu cobriu à luz do dia" 
    << " transformando a névoa de Baróvia\nem um profundo breu, nem a mais escuras das noites se aproximará de tal escuridão." << endl
    << "Uma risada ecoava de dentro da cabana: " << endl << "\n\t_ O que um homem tão bonito está fazendo aqui?\n\tMe daria a honra de saber seu nome? - Disse a sombra de uma senhora."
    << endl << "\n\t_ Meu nome? Sou Patestus, filho da luz. - Gritou o guerreiro" << endl << "\n\t_ Filho da luz é? HAHAHA - Ironiza a senhora.";
   
    TravaTexto();
    
    limparTela();
    
    cout << "\n\nEntão das sombras, uma senhora de pele verde com centenas de ferimentos surge\ne um cheiro podre preenche o ambiente.\n"
    << "\n\t_ Me diz então Patestus, o que você deseja dessa linda senhora?" << endl << "\n\t_ Quero o livro que você guarda ai nesse muquifo. - Retruca o guerreiro."
    << "\n\n\t_ O QUE?! O livro que o meu bebê me deu? Um fracassado igual você NUNCA\n\t poderia tocar nele. - Disse a senhora ao esboçar uma expressão de ódio."
    << "\n\n\t_ A única fracassada que tem aqui é você\n\tque vive presa nessa cabana que fede a merda. - Grita o guerreiro." << endl
    << "\n\t_ O QUE VOCê DISSE SEU BOSTINHA? Sou Baba Lysaga mãe de Strahd von Zarovich,\n\tsou a noite em pessoa, se você se acha tão digno venha me enfrentar filho da luz!"
    << endl << "\nO guerreiro então assume sua posição de combate, pronto para enfrentar a bruxa";
    
    TravaTexto();
    
    limparTela();
    
    iniciarCombate(jogador1, boss1);
    
    if(boss1.vida == 0) {
        
        TravaTexto();
        
        limparTela();
        cout << "\nO guerreiro ao descer daquela ilha voadora, se deparava com o bardo cantando: \n";
        cout << "\n\tNos pântanos escuros, a bruxa ele encontrou,\n" << "\tBaba Lysaga, num covil que o medo semeou.\n" << "\tCom feitiços e risadas, o ar ela preencheu,\n"
        << "\tMas o mago ergueu seu cajado, e a luta começou.\n" << "\n\tEla invocou espíritos, sombras da noite,\n" << "\tCom relâmpagos e fogo, ele revidou o açoite.\n"
        << "\tA cabana rugiu e tomou vida ao redor,\n" << "\tMas o mago com firmeza enfrentou o terror.\n" << "\n\tCom palavras antigas, a terra ele rasgou,\n"
        << "\tFeitiços e forças ocultas a bruxa desafiou.\n" << "\tO pântano fervia, mas ela caiu com um grito,\n" << "\tE o mago venceu, de pé, altivo e invicto.\n";
        
        TravaTexto();
    }
    
    limparTela();
    
    cout << endl << "\n\t_ Você voltou bravo guerreiro! - Disse o Bardo ao ver Patestus descer daquele pedaço de terra voador.\n" <<
    "\n\t_ Claro que voltei! Ainda tenho muitas coisas a se resolver, não posso ficar perdendo tempo - Respondeu Patestus.\n" <<
    "\n\t_ Você poderia ao menos me dizer o que você procurava com esta bruxa? - Perguntou o Bardo.\n" << 
    "\n\t_ Então no fim você sabia quem era a dona da cabana? - Perguntou Patestus.\n" <<
    "\n\t_ Bom, eu fazia uma ideia, mas é o que dizem, um bardo em companhia de um bruxo nunca recusaria uma missão! - Respondeu o Bardo confiantemente.\n" <<
    "\n\t_ Enfim, procurava isto!\n\nPatestus ergueu um livro, tinha a aparência velha, como se fosse uma coisa bem antiga, porém com uma bola de ouro como núcleo.\n" <<
    "\n\t_ Ok, mas... O que seria isso? - Perguntou o Bardo.\n" << "\n\t_ Isso? É o fim da névoa de Baróvia, um diário que Strahd presenteou sua mãe," <<
    " nele\n\tcontém todos os segredos sobre as forças ocultas que fizeram dele imortal. - Respondeu.\n" << "\n\t_ Se esse livro é tão importante, o que ele estava fazendo com Baba Lysaga?\n" <<
    "\n\t_ Pelo visto Baba Lysaga selou esse livro com algum tipo de feitiço, Strahd sabia que Lysaga tinha grande domínio sobre magias de sigilo.\n" ; 
    
    TravaTexto();
    limparTela();
    
    cout << "\nO guerreiro então começará a recitar palavras em uma língua desconhecida." <<
    " As partes cobertas de ouro no livro começaram a derreter,\nse transformando em um líquido vermelho que se assemelhava a sangue." <<
    " Após certo tempo, o livro finalmente foi aberto, mas parecia ter alguma coisa errada." <<
    "\n\n\t_ Hmm? Isso deveria acontecer? - Indagou o Bardo" << "\n\n\t_ Fique quieto! Estou tentando pensar." << endl
    << "\n\n O livro se fechou e começou a projetar a imagem de uma adaga, especificamente no coração de um homem.\nPatestus parecia não entender a situação," <<
    " mas não parecia nada preocupado." << "\n\n\t_ Senhor?? O livro se fechou e eu nem consegui compreender o que eu vi. - Disse o Bardo.\n" <<
    "\n\t_ Parece algum tipo de enigma, Lysaga deve ter implantado antes de proferir o sigilo, vamos ver novamente! - Respondeu Patestus.\n" << 
    "\nNa tentativa de abrir o livro pela segunda vez, o núcleo se rompeu sugando ambos para as trevas densas." << endl
    << "\n\t_ Onde estamos senhor????!!! - Gritou o Bardo.\n" << "\n\t_ Você não percebe? Estamos em Ravenloft, o livro nos trouxe para cá! - Respondeu.\n" <<
    "\n\t_ Mas qual seria o objetivo do livro nos trazendo aqui?! - Exclamou o Bardo.\n" << "\n\t_ Se você pensar um pouco você saberá. - Disse.\n" <<
    "\n\t_ Ainda não consegui assimilar senhor, poderia me explicar de uma vez?\n" << "\n\t_ Te falta inteligência querido bardo, aqui que está localizado a adaga.\n" <<
    "\n\t_ A adaga? Que adaga?! - Perguntou o bardo confuso.\n" << "\n\tA magia que usei para tirar o selamento do livro também serve para absorver as informações úteis,\n" <<
    "\tela utiliza dos meus pensamentos para absorver o conhecimento, e naquela hora, só pensei em matar Strahd.";
    
    TravaTexto();
    
    limparTela();
    
    cout << "\nPatestus então começou a explorar o local, o Bardo amedrontado estava o seguindo, mesmo que em passos lentos.\n" <<
    "Patestus parecia ter pleno conhecimento do local, porém ao entrar em um dos calabouços do castelo,\n o mesmo se tornou em um labirinto," <<
    "separando o bruxo de seu bardo.\n" << "\n\t_ Droga, aquele bardo desprovido de inteligência vai acabar morrendo nesse lugar\n - Disse o guerreiro ao retirar um boneco de sua bolsa." <<
    "\n\nEntão o bruxo lança um feitiço sobre este boneco, fazendo com que a pele dele se tornasse dura como pedra. Parecia algum tipo de proteção.\n" <<
    "\n\t_ Bom, isso deve funcionar, ao menos por hora." << "\n\nO guerreiro então continuou seu caminho. Algumas salas não davam a lugar nenhum, " <<
    "eram salões sem mobília alguma,\npareciam que nunca tinham sido nem visitados. Depois de certo tempo vasculhando as catacumbas desse castelo,\n" <<
    "Patestus finalmente tinha encontrado o lugar certo, era mais um desses salões, porém havia uma pessoa empalada\n e com uma faca em seu coração, " <<
    "assim como a visão tinha sugerido." << "Ao entrar naquela sala,\no corpo de Patestus ficou pesado, como se tivesse algo tentando impedir, 033" <<
    "porém o guerreiro prosseguiu à retirar.\nAo enconstar na adaga, um breu se instaurou no local, fechando todas as saídas daquela sala." <<
    "\n\n\t_ Quem há de perturbar a paz dos mortos deve perpetuar em sofrimento! - Disse uma voz.\n" <<
    "\n\t_ Quem é você? Eu ordeno que se apresente - Gritou Patestus.\n" <<
    "\n\t_ Você? Você acha que sou um só? Você libertou todos nós abrindo cada salão e iremos cumprir o que nosso mestre nos ordenou. - Respondeu a voz." <<
    "\n\n\t_ Pare de se rastejar pelas sombras como um rato, enfrente-me de uma vez! - Gritou o guerreiro.\n" << 
    "\nAo dizer isso, o salão que parecia vazio se lotou rapidamente com monstros,\ne todos possuíam uma coisa em comum, haviam brincado com o pós vida.";
    
    TravaTexto();
    
    limparTela();
    
    iniciarCombate1(jogador1, boss2);
    
    if(boss2.vida == 0) {
        
        TravaTexto();
        
        limparTela();
        
        cout << "O guerreiro ao derrotar os mortos que residiam em Ravenloft conseguiu retirar a adaga, fazendo com que ele teleportasse mais uma vez.\n" 
        << "Dessa vez, ele estava em um salão que se aparentava uma igreja, no teto tinham várias jaulas, e em uma delas o bardo estava:\n" 
        << "\n\tPara o castelo sombrio, eles então partiram,\n" << "\tOnde a escuridão e o terror jamais desistiram.\n" <<
        "\tRavenloft, em suas torres, espreitava o luar,\n" << "\tUm reino de trevas onde poucos ousam entrar.\n" << 
        "\n\tGuardas vampiros surgiram nas sombras, famintos,\n" << "\tO mago os enfrentou com raios indistintos.\n" <<
        "\tCada corredor, cada salão tinha um segredo escuro,\n" << "\tMas ele avançava, destemido e puro.\n" <<
        "\n\tAs gárgulas rugiam, os mortos sussurravam,\n" << "\tMas a luz do mago, os corredores iluminavam.\n" <<
        "\tEm meio a espectros e armadilhas traiçoeiras,\n" << "\tEle seguia em frente, sem medo das barreiras.\n";
        
        TravaTexto();
        
    }
    
    limparTela();
    
    cout << "\n\n\t_ Bardo?! Quem te prendeu ai em cima? - Gritou.\n" << "\n\t_ Senhor? Me ajude por favor!! - Respondeu o Bardo." <<
    "\n\n\t_ Não consigo te ajudar se você não me dizer quem foi que te prendeu ai em cima!\n" << "\n\t_ Foi Strahd!!!! Eu estava logo atrás de você, quando me senti tonto,\n" <<
    "\te do nada acordei em cima daquele altar! - O Bardo apontou ao altar daquele salão.\n" << "\n\t_ Ele ia me transformar em um de seus súditos, porém virei pedra no exato instante. - Continuou." <<
    "\n\n\t_ Strahd??! Onde ele está agora? - Perguntou Patestus.\n" << "\n\t_ Desde de sua tentativa falha de me matar ele s-" <<
    "\n\n\t_ Atrás de você bobinho." << "\n\nPatestus escutou um susurro dentro de sua cabeça, entrando por instinto em\nposição defensiva. No mesmo instante, Strahd deferiu um golpe em seu pescoço." <<
    "\nA armadura de luz que Patestus possui em sua instância defensiva não permitiu que Strahd causasse grandes danos." <<
    "\n\n\t_ Seu inútil! Esse fracote não serve nem de distração, quando eu terminar \n\tcom esse aspirante a bruxo, te tortuarei até a morte! - Gritou Strahd para o Bardo.\n" <<
    "\n\t_ Como que é a história? Mesmo que esse Bardo seja um fracote que não sabe se\n\tcuidar sozinho, ele narra a minha história em forma de música! Nunca deixairei que ele morra.\n" <<
    "\n\t_ Antes de fazer a segurança de outras pessoas você deveria cuidar de si mesmo!\n\tMesmo que meu ataque não causou grandes danos, eu já te amaldiçoei. - Disse Strahd." <<
    "\n\nNesse momento Patestus começou a sentir dores agudas por todo seu corpo,\nmanchas pretas tinham começado a consumir seus dedos, tirando cada gota de magia que Patestus tinha.\n" <<
    "\n\t_ MALDITO! O que você fez comigo? Você acha que maldições baratas poderiam me deter? - Disse Patestus enfurecido." <<
    "\n\n\t_ Eu venho esperando por um encontro com você desde que eu presenciei a queda de Baróvia,\n\tvocê sugou a vida de todos os cidadãos pensando apenas na sua!" <<
    " Você pode até não saber,\n\tmas Tatyana tinha um propósito com a luz. Você interferiu no destino dela, e agora, pagará por isso.";
    
    TravaTexto();
    
    limparTela();
    
    cout << "\n\n Patestus então caiu no chão, enfraquecido ele continuava a recitar suas magias, porém nenhuma delas surtiam efeito em Strahd.\n" <<
    " Strahd caminhava lentamente até Patestus para que pudesse dar o golpe final, ele fortificou sua presença para que Patestus não conseguisse mais se mexer." <<
    "\n\n\t_ Você será uma ótima marionete em minha coleção, não se preocupe, só vai doer um pouquinho HAHAHAHAHAHA - Ironizou Strahd." <<
    "\n\nEntão Strahd afiou suas unhas e enfiou no coração de Patestus, que apenas deu um último suspiro. No entanto, quando Strahd se virou contando vitória\n" <<
    " O salão ficou todo iluminado, ao olhar para trás se deparou com o espírito de Tatyana.\n" <<
    "\n\t_ Tatyana, o que você está fazendo aqui?! - Disse Strahd surpreso." << "\n\n\t_ A missão deste guerreiro ainda não acabou, eu lhe concedo a benção eterna - Disse Tatyana ao enconstar suas mãos em Patestus." <<
    "\n\nPatestus então se levantou, uma aura laranja o cercava, seus olhos estavam queimando como fogo: \n" <<
    "\n\t_ Strahd suas maldições já não fazem mais efeito em mim!\n\tVocê sentirá a verdadeira força do herdeiro do sol! - Patestus se levantou e assumiu posição de combate.";
    
    TravaTexto();
    
    limparTela();
    
    iniciarCombate2(jogador2, boss3);
    
    
    };    

// Função do Menu
void Menu(){
    int menu; // Variável de decisão do menu
   
    do {
    cout << "\n\t AS CRÔNICAS DE PATESTE" << endl << "\t Patestestus"; // Título
    cout << "\n\n\t 1. Continuar" << endl << "\t 2. Novo jogo" << endl << "\t 3. Créditos\n\n\tR: "; // Opções
    cin >> menu; // Captar decisão do menu
   
    switch(menu){
    case 1:
    limparTela();
   
    break;
   
    case 2:
    limparTela();
    CAPI();
    break;
   
    case 3:
    cout << "\n BASEADO EM UM CONTO DE DUNGEONS & DRAGONS\n" << "\t AS CRÔNICAS DE PATESTE" << endl << "\t Patestestus" << endl
    << "\n\tPENSADO, IDEALIZADO E CODADO POR:\n" << "\n\t Diego Alves 843649\n" << "\t Gabrielly Claudio 843644\n" << "\t Pedro Tavares 843712\n"
    << "\t Pietra Queiroz 842246\n" << "\n\t AGRADECEMOS POR JOGAR!";
    break;
   
    default:
    limparTela();
    }
   
    } while((menu < 1) || (menu > 3));
};


int main() {
    Menu();
    return 0;
};