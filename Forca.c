/*__________________________________________________________________________
|_________________________________ Autor: __________________________________|
|                           Thiago Rodrigues de Souza                       |
|                                                                           |
|___________________________________________________________________________|
|___________________________________________________________________________|
|______________________________Dados academicos: ___________________________|
|    Projeto acadêmico, realizado pelo grupo DESTROYER, alunos do IFTM,     |
| curso de ADS (Analise e Desenvolvimento de Softwares), primeiro           |
| período, na matéria Algoritmos e Lógica de programação, Professor         |
| Gilberto Oliveira, tendo como objetivo a criação de um jogo atendendo     |
| os requisitos estipulados, usando as práticas adquiridas ao longo do      |
| curso.                                                                    |
|___________________________________________________________________________|
|____________________________ Sobre o Jogo: ________________________________|
|                                                                           |
|                           JOGO DA FORCA 2.0                               |
|___________________________________________________________________________|
|   Jogo tradicional, onde o objetivo é trazer diversão ao ususario, onde o |
| mesmo tem que tentar advinhar uma palavra secreta, letra a letra.         |
| Buscando uma maior interação com o jogo, o sistema possui vinte palavras  |
| armazenadas e tambem possui a possibilidade do usuario inserir as palavras|
| de sua preferencia.                                                       |
| Durante o jogo a pessoa pode realizar ajustes e definir quantos erros     |
| podem ocorrer.                                                            |
| Vitoria: Ocorre quando o jogador acertar todas as letras da palavras      |
| Derrota: Ocorre quando o jogador atingir a quantidade de erros definidos  |
| no sistema.                                                               |
|___________________________________________________________________________|
|______________________________ Funçoes ____________________________________|
|                                                                           |
| 1 Jogar:                                                                  |
|           1.1 Jogar com Banco de Dados;                                   |
|           1.2 Jogar com as palavras cadastradas.                          |
| 2 Placar:                                                                 |
|           2.1 Visualizar placar em tempo real.                            |
| 3 Palavras Cadastradas:                                                   |
|           3.1 Palavras do Banco de Dados;                                 |
|           3.2 Palavras do Cadastro.                                       |
| 4 Cadastrar Palavras:                                                     |
|           4.1 Cadastrar Palavra.                                          |
| 5 Ajustes:                                                                |
|           5.1 Dificuldade;                                                |
|           5.2 Cores.                                                      |
| 6 Sair:                                                                   |
|           6.1 Sair.                                                       |
|                                                                           |
|___________________________________________________________________________|
|                                                                           |
|             Divirta-se, boa sorte!                                        |
|             Direitos autorais livres, usem a vontade.                     |
|___________________________________________________________________________|*/

//Bibliotecas utilizadas:
    #include <stdio.h>
    #include <time.h>
    #include <string.h>
    #include <locale.h>

//Inicio função principal:
int main(){

//Set's Iniciais Padronizado pela equipe:
    system("color 4F");                         // Cores do sistema;
    system("title JOGO DA FORCA-ADS-IFTM :-)"); // Titulo do programa;
    system("MODE con cols=141 lines=40 ");      // Tamanho da Janela;
    setlocale(LC_ALL, "Portuguese");            // Acentuação padronizada;
    srand(time(NULL));                          // Aleatoriedade para sorteio das palavras;


// Declaração de variáveis;

    int     sair_do_jogo=0, vitoria=0, derrota=0,
            jogadas=0, sorteio_palavra=0, erros=0,
            acertos=0, tamanho_palavra=0, fim=0,
            igual=0, cad=0, i, p=3, s=16, c=2,
            nao_achou=0, cont_dig=0;

    char    letra, digitadas[30]="\0";

// Declaração de Struct
        struct guarda_palavra{
                char palavra[40];
                char dica[100];
                int num_letras;};

// Declaração de Array de Struct;
        struct guarda_palavra conjunto[50];

// Declaração de Funções;
        void layoult();
        void menu();
        void laterais();
        void superior_inferior();
        void advinhar_palavra();
        void titulo();
        void ganhou();
        void perdeu();


// Inicio da aplicação:
    do{
        system("cls");
        layoult();
        titulo();
        menu();
        switch(getch()){
                case '1':{
                    system("cls");
                    layoult();
                    titulo();
                    laterais();
                    printf("\n %c                 %c Palavra a ser cadastrada :\t\t\t\t\t\t\t\t\t\t\t\t  %c  \r\t\t\t\t\t\t", p, c, p);
                    fgets(conjunto[cad].palavra, 40, stdin);
                    printf(" %c                 %c Deixe uma dica :\t\t\t\t\t\t\t\t\t\t\t\t\t  %c  \r\t\t\t\t\t", p, c, p);
                    fgets(conjunto[cad].dica, 100, stdin);
                    conjunto[cad].num_letras=strlen(conjunto[cad].palavra);
                    cad=cad+1;
                    continue;
                }
                case '2':{
                    system("cls");
                    layoult();
                        if (cad==0) {
                            printf("\n %c\t\t\t\t\t [Aviso]%c Nenhuma palavra cadastrada %c [Aviso]\t\t\t\t\t\t\t  %c ", p, c, c, p);
                            laterais();
                            laterais();
                            superior_inferior();
                            system("pause");
                            break;
                            }
                    jogadas=jogadas+1;
                    erros=0;
                    acertos=0;
                    sorteio_palavra= rand()%cad;
                    printf("\n\n %c\t\t\t\t [Dica]: %s", p, &conjunto[sorteio_palavra].dica);
                    tamanho_palavra=conjunto[sorteio_palavra].num_letras-1;

                    printf("\t\t\t\t Dica de tamanho...: (%d Letras)", tamanho_palavra);

                    char palavra_secreta[tamanho_palavra];
                    strcpy(palavra_secreta, conjunto[sorteio_palavra].palavra);
                    strupr(palavra_secreta);

                    char parcial[tamanho_palavra];
                    for (i=0; i<tamanho_palavra; i++){
                        parcial[i]=' ';
                    }

                    do{

                        fflush(stdin);
                        printf("\n\t\t\t\t Parcial: ");
                        for (i=0; i<tamanho_palavra; i++){
                        printf("[_%c_]\t", parcial[i]);
                            }
                        printf ("\n\t\t\t\t Letras digitas: ");
                            for (i=0; i<cont_dig; i++ ){
                                printf("[_%c_]\t", digitadas[i]);

                            }
                        printf("\n\t\t\t\t Digite uma letra ==>>> ");
                        scanf("%c", &letra);
                        digitadas[cont_dig]=letra;
                        cont_dig=cont_dig+1;
                        letra = toupper(letra);
                        nao_achou=0;
                        system("cls");
                        printf("\t\t\t\t Numero de Erros (%d) de (6 Maximo).", erros);
                        printf("\t\t\t\t Numero de Acertos (%d) de (6 Maximo).", acertos);
                        for (i=0; i<tamanho_palavra; i++){
                                if (letra==palavra_secreta[i]){
                                        parcial[i]=letra;
                                        acertos=acertos+1 ;
                                }else{
                                        nao_achou=nao_achou+1;
                                        if (nao_achou==tamanho_palavra){
                                            erros=erros+1;
                                            printf("\t\t\t\t Errou, não tem a letra %c !\n", letra);
                                                if (erros>0){
                                                    printf("\nXXXXXXXXXXXXXXXXXXX ||D XXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXX ||D XXXXXXXXXXXXXXXXXXXXXXXXX\nXXX                 ||                        XXX");
                                                        if (erros>1){
                                                            printf("\nXXX                 ||                        XXX\nXXX                 \\\\\\                       XXX\nXXX         oooO　(o.o)　Oooo               XXX");
                                                                if (erros>2){
                                                                    printf("\nXXX             \\\\._(_)_.//                   XXX\nXXX                |___|                      XXX");
                                                                        if (erros>3){
                                                                            printf("\nXXX                |_|_|                      XXX\nXXX               .||.||.                     XXX");
                                                                                 if (erros>4){
                                                                                    printf("\nXXX             .oooO.Oooo                    XXX\nXXX                                           XXX");
                                                                                        if (erros>5){
                                                                                            printf("\nXXX         _________________________         XXX\nXXX        /  Eu ganhei hahaha, você \\\\  /// XXX\nXXX   .-.  \\ perdeu, jogue novamente!//_(';') XXX\nXXX  (o.o)  \\_______________________//   <o>  XXX\nXXX(,,)'(,,)                            _! !_ XXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
                                                                                        }
                                                                                 }
                                                                        }
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                        if (acertos==tamanho_palavra){
                                    vitoria=vitoria+1;
                                    ganhou();
                                    fim=1;
                        }

                        if (erros==6){
                                    derrota=derrota+1;
                                    perdeu();
                                    fim=1;
                        }
                    }while(fim!=1);
                    ///// set limpar digitadas, quantidade de acertos
                    ///// numero de erros impressos na tela
                    continue;
                }
                case '3':{
                    system("cls");
                    layoult();
                    titulo();
                    laterais();
                    printf("\n %c\t\t\t\t\t [PLACAR]%c____PLACAR ATUALIZADO____%c [PLACAR]\t\t\t\t\t\t\t  %c ", p, c, c, p);
                    printf("\n %c\t\t\t\t\t [PLACAR]%c [%d]<== Partidas Jogadas %c [PLACAR]\t\t\t\t\t\t\t  %c ", p, c, jogadas, c, p);
                    printf("\n %c\t\t\t\t\t [PLACAR]%c [%d]<====    Vitorias    %c [PLACAR]\t\t\t\t\t\t\t  %c ", p, c, vitoria, c, p);
                    printf("\n %c\t\t\t\t\t [PLACAR]%c [%d]<====    Derrotas    %c [PLACAR]\t\t\t\t\t\t\t  %c ", p, c, derrota, c, p);
                    laterais();
                    superior_inferior();
                    system("pause");
                    continue;
                }
                case '4':{
                    system("cls");
                    layoult();
                    printf("\n %c\t\t\t\t\t [CADASTRO]%c____PALAVRAS CADASTRADAS____%c [CADASTRO]\t\t\t\t\t\t  %c ", p, c, c, p);
                        if (cad==0) {
                            printf("\n %c\t\t\t\t\t [Aviso]%c Nenhuma palavra cadastrada %c [Aviso]\t\t\t\t\t\t\t\a  %c ", p, c, c, p);
                            laterais();
                            laterais();
                            superior_inferior();
                            system("pause");
                            break;
                            }
                    printf("\n %c\t\t\t\t\t [%d]<== Palavras cadastradas \t\t\t\t\t\t\t  %c ", p, cad, p);
                    for (i=0; i<cad; i++){
                        printf("\n %c \t  [%dº]: %s\t  Dica: %s\t  %c ", p, i+1, conjunto[i].palavra, conjunto[i].dica, p);
                    }
                    laterais();
                    superior_inferior();
                    system("pause");
                    continue;
                }
                case '5':{
                    sair_do_jogo=5;
                    break;
                }
                default :{
                    continue;
                }
        }

    }while(sair_do_jogo!=5);
printf("Obrigado por jogar, volte sempre!");
return 0;
}


                // Funções:

void layoult(){
int i=0, p=3, l=0;
 printf("\n ");
            for (i=0; i<138; i++){
                printf("%c", p);
            }
        printf("\n ");
            for (i=0; i<138; i++){
                printf("%c", p);
            }
            for (i=0; i<2; i++){
                printf("\n %c                                                                                                                                        %c  ", p, p);
            }
            void titulo ();

for (i=0; i<3; i++){
  printf("\n %c                                                                                                                                        %c  ", p, p);
}
}

void superior_inferior(){
    int i=0, p=3, l=0;

    for (l=0; l<2; l++){
            printf("\n ");

            for (i=0; i<138; i++){
                    printf("%c", p);
            }
            }
}
void laterais (){
    int i=0, p=3;
    for (i=0; i<3; i++){
        printf("\n %c                                                                                                                                        %c  ", p, p);
    }

}

void menu(){
    int p=3,s=16, c=2;
    laterais();
    printf("\n %c  \t\t\t\t\t\t\t _______________________  \t\t\t\t\t\t\t  %c  ", p, p);
    printf("\n %c  \t\t\t\t\t\t\t %c    Menu inicial:     %c \t\t\t\t\t\t\t  %c  ", p, c, c, p);
    printf("\n %c  \t\t\t\t\t\t\t %c %c 1 - Cadastrar      %c \t\t\t\t\t\t\t  %c  ", p, c, s, c, p);
    printf("\n %c  \t\t\t\t\t\t\t %c %c 2 - Jogar          %c \t\t\t\t\t\t\t  %c  ", p, c, s, c, p);
    printf("\n %c  \t\t\t\t\t\t\t %c %c 3 - Placar         %c \t\t\t\t\t\t\t  %c  ", p, c, s, c, p);
    printf("\n %c  \t\t\t\t\t\t\t %c %c 4 - Ver Palavras   %c \t\t\t\t\t\t\t  %c  ", p, c, s, c, p);
    printf("\n %c  \t\t\t\t\t\t\t %c______________________%c \t\t\t\t\t\t\t  %c  ", p, c, c, p);
    printf("\n %c  \t\t\t\t\t\t\t %c %c 5 - Sair           %c \t\t\t\t\t\t\t  %c  ", p, c, s, c, p);
    printf("\n %c  \t\t\t\t\t\t\t %c______________________%c \t\t\t\t\t\t\t\a  %c  ", p, c, c, p);
    laterais();
    superior_inferior();
    }




//ok
void ganhou (){
printf("\n  Ganhou !");
printf("\n          ");
printf("\n          ");
printf("\n  |o_0_o| ");
printf("\n     O    ");
printf("\n  ___|\__ ");
}
void perdeu(){
//colocar comandos
system("pause");

}

//ok
void titulo (){
int i=0, p=3,s=16, c=2;
printf("\n %c                              XXXXX|    XXXXXXXXX|     XXXXXXXXX|     XXXXXXXXX|           XXXXXXXXX|          X|                       %c  ", p, p);
printf("\n %c                               XXX|    XXXXXXXXXXX|   XXXXXXXXXXX|   XXXXXXXXXXX|          XXXXXXXXXXX|       XXX|                      %c  ", p, p);
printf("\n %c                               XXX|    XX|      XX|   XX|            XX|      XX|           X|      XXX|     XX|XX|                     %c  ", p, p);
printf("\n %c                               XXX|    XX|      XX|   XX|     XXX|   XX|      XX|           X|       XX|    XX|  XX|                    %c  ", p, p);
printf("\n %c                       XXX|    XXX|    XX|      XX|   XX|      XX|   XX|      XX|           X|      XXX|   XXXXXXXXX|                   %c  ", p, p);
printf("\n %c                       XXXXXXXXXXX|    XXXXXXXXXXX|   XXXXXXXXXXX|   XXXXXXXXXXX|          XXXXXXXXXXX|   XXX|    XXX|                  %c  ", p, p);
printf("\n %c                        XXXXXXXXX|      XXXXXXXXX|     XXXXXXXXX|     XXXXXXXXX|           XXXXXXXXX|    XXXX|    XXXX|                 %c  ", p, p);
            for (i=0; i<2; i++){
                printf("\n %c                                                                                                                                        %c  ", p, p);
            }
printf("\n %c                                    XXXXXXXXXXX|     XXXXXXXXX|    XXXXXXXXXX|    XXXXXXXXXXX|        X|                                %c  ", p, p);
printf("\n %c                                    XXXXXXXXXXX|    XXXXXXXXXXX|   XXXXXXXXXXX|   XXXXXXXXXXX|       XXX|                               %c  ", p, p);
printf("\n %c                                    XXX|            XX|      XX|   XXX|   XXX|    XXX|              XX|XX|                              %c  ", p, p);
printf("\n %c                                    XXXXXXXXXXX|    XX|      XX|   XXXXXXXXX|     XXX|             XX|  XX|                             %c  ", p, p);
printf("\n %c                                    XXXXXXXXXXX|    XX|      XX|   XXX| XXXX|     XXX|            XXXXXXXXX|                            %c  ", p, p);
printf("\n %c                                    XXX|            XXXXXXXXXXX|   XXX|  XXXX|    XXXXXXXXXXX|   XXX|    XXX|                           %c  ", p, p);
printf("\n %c                                    XXX|             XXXXXXXXX|    XXX|   XXXX|   XXXXXXXXXXX|  XXXX|    XXXX|                          %c  ", p, p);
}

// Uso na programação // Bibliotecas
// Uma fruta // Melancia
// Uma fruta // Caju
// Uma fruta // Banana
// Um veiculo // ferrari
// Um veiculo // bicicleta
// Um veiculo // Carreta
// Ex presidente do Brasil // Luiz
// Ex presidente do Brasil // Janio
// Ex presidente do Brasil // Fernando
// Um Pais // Paraguai
// Um Pais // Dinamarca
// Um Pais // Noruega
// Uma cidade // Uberlandia
// Uma cidade // Goiania
// Uma cidade // Paris
// Um animal // Cachorro
// Um animal // Cavalo
// Um animal // Burro
// Uma cor! // Amarelo
// Uma cor! // Verde
// Uma cor! // Azul








