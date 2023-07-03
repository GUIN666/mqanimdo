/*****************************************************************************************/
/*				Arquivo cabe�alho que acompanha as fun��es do arquivo           */
/*				 "MQANIMADO.c".															*/
/*				PS: Detalhamento sobre cada fun��o no arquivo "funcoes.c"		*/
/*																															*/
/*****************************************************************************************/

/******INICIO DA DEFINI��O DE BIBLIOTECAS E INCLUDES******/
#include <stdio.h> 
/*Fun��o Printf()*/

#include <stdlib.h> 
/* Fun��es srand(), rand(). Constante NULL */

#include <time.h>
/*	Fun��o time()*/

#include "conio_v3.2.4.h" 
/* Fun��es kbhit(), getch(), gotoxy(), Sleep(), textbackground(), textcolor(), window()*/
/* enum COLORS*/

#include "console_v1.5.4.h"
/* Fun��es getresolucao(), setDimensaoJanela(), setPosicaoJanela(), setTituloConsole(), */
/* Constantes ESC, TAB, ESPACO, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, SETA_PARA_SIMA, SETA_PARA_BAIXO, SETA_PARA_DIREITA, SETA_PARA_ESQUERDA */
/*	struct COORD*/
/******FIM DA DEFINI��O DE BIBLIOTECAS E INCLUDES******/

/******INICIO DA DECLARAÇÃO DE STRUCTS UTILIZADAS******/

/*struct que armazena as características de cada retangulo e seu cursor*/
typedef struct TQUADRADO
{
    COORD ponto1; /* Do ponto 1 ao ponto 3, se obtém a linha inicial*/
    COORD ponto2; /* Do ponto 2 ao ponto 1, se obtém a coluna inicial*/
    COORD ponto3; /* Do ponto 3 ao ponto 4, se obtém a coluna final*/
    COORD ponto4; /* Do ponto 4 ao ponto 2, se obtém a linha final*/
    /* Para um melhor aproveitamento do código, foi decidido em operar com vértices (pontos) em vez de arestas (linha e coluna)*/

}QUADRADO;

/*lista encadeada, ant = final da lista anterior, prox começo da prox lista*/
typedef struct TREETANGULO
{
    QUADRADO tamanho;
    COORD cursor;
    int cor;
    int cortxt;
    int id;
    int automatico;
    int velocidade;
}RETANGULOS;

typedef struct TMEMCONS
{
    COORD resolucao;
    COORD posicao;
    CORES cor;
    char *titulo;
}MEMORIACONSOLE;


/******FIM DA DECLARAÇÃO DE STRUCTS UTILIZADAS******/


/******INICIO DA DEFINI��O DE DEFINES E CONSTANTES******/
#define COLUNAS 10 /* Largura do quadrado */
#define LINHAS 10 /* Altura do quadrado */
#define QTDQUADRADOS 10 /* Quantidade de quadrados solicidado*/
#define VELOCIDADEMAX 1000 /* Velocidade de uma coluna e linha a cada 2 segundos */
#define VELOCIDADEPADRAO 1 /* Velocidade de uma coluna e linha a cada 100 milissegundo */
#define VELOCIDADEMIN 1 /* Velocidade de uma coluna e linha a cada 100 milissegundo */
#define NIL 0
/******FIM DA DEFINI��O DE DEFINES E CONSTANTES******/

/******INICIO DA DECLARA��O DE FUN��ES E PROCEDIMENTOS******/
QUADRADO andaquadrado(QUADRADO );
void ApagarArea(QUADRADO);
void ApagarQuadrado(COORD);
void AtivaAleatorio(RETANGULOS *);
void AtivarCOORD(COORD *, int , int );
QUADRADO ativaNil(void);
void AutomaticoXY(RETANGULOS *);
int cabenatela(COORD);
int controladorGeral(int);
int controlaIndice(int, int);
int controleDePontos(COORD, COORD, COORD);
int CorRand(void);
void CriarTela(QUADRADO, int);
QUADRADO decrementaBaixo(QUADRADO);
QUADRADO decrementaCima(QUADRADO);
QUADRADO decrementaDireita(QUADRADO);
QUADRADO decrementaEsquerda(QUADRADO);
char *DescDir(int);
char *DescCor(int);
void DespersonalizarConsoleFULL(MEMORIACONSOLE);
int Detector(RETANGULOS *, EVENTO, int*, int *, int*);
void FuncaoF1aoF10(int, RETANGULOS *, int, int);
QUADRADO incrementaBaixo(QUADRADO);
QUADRADO incrementaCima(QUADRADO);
QUADRADO incrementaDireita(QUADRADO);
QUADRADO incrementaEsquerda(QUADRADO);
int Interferencia(QUADRADO, QUADRADO);
int InterferenciaVetor(RETANGULOS *, QUADRADO, int);
/*COORD menorcoord(COORD, COORD);*/
int pegaQuadrado (RETANGULOS *, int, COORD);
MEMORIACONSOLE PersonalizarConsoleFULL(char *);
void PrintarInfo( RETANGULOS);
void PrintarQuadrado(COORD *, int );
void quadradoAtivo(RETANGULOS *, int, int, int);
void quadradoInativo(RETANGULOS *);
QUADRADO validaQuadradoNovo(RETANGULOS *, int);
void ValoresPadroes(RETANGULOS *);
/******FIM DA DECLARA��O DE FUN��ES E PROCEDIMENTOS******/