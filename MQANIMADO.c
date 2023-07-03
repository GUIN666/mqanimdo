/* 
	Programa: múltiplos quadrados animados.
    Descrição: múltiplos quadrados animados que se movimentam pela tela, podendo fazer alterações visuais no programa.
    Programador: Nícolas Herculano Pires
    RGM: 47164
    Data da última modificação: 19/05/2023
	Código para compilar: gcc -o MQANIMADO.exe MQANIMADO.c conio_v3.2.4.c console_v1.5.4.c funcoes.c -pedantic -Wall -Werror -Wextra
*/
#include "conio_v3.2.4.h" 
 /* Funções clrscr() */
#include "console_v1.5.4.h"
 /* MaxDimensaoJanela(). Constante ESC. Struct COORD */
#include "funcoes.h"
 /* ApagarQuadrado(), AutomaticoXY()AtivarCOORD(), DetectAuto(), PersonalizarConsole(), Printarquadrado(), SetarArea(). */
 /* Constante COLUNAS, LINHAS, VELOCIDADE INICIAL */
#include <stdlib.h> 
/* Funções malloc(), rand(), srand(). Constante NULL */
#include <time.h> 
/*Função time()*/

/* Início do programa */
int main(int argc, char **argv)
{
	/* Ativar o registro de cada retangulo, atualmente, 10*/
    RETANGULOS retangulo[11];

	/* Ativar tecla de controle dos quadrados*/
	int qtd = 0;
	int selecionado = 0;
	DWORD sleep = 1;

	/* Ativar tecla de controle geral de repetição*/
	int teclaG;

	/* Tecla de evento*/
	EVENTO clique;
	/* Variaveis de controle*/
	int i = VELOCIDADEPADRAO;
	int j = 0;
	/* Ativar memoria do console */
	MEMORIACONSOLE principal = PersonalizarConsoleFULL("MULTIPLOS QUADRADOS ANIMADOS");

	/* Artifício para silenciar warning */
	argc = argc;
	argv = argv;

	/* Valores padroes de inicio*/
	ValoresPadroes(&retangulo[0]);
	
	/* Gerar uma posição central na tela para o cursor e aleatoría para o lado que ele irá se movimentar */
	AtivaAleatorio(&retangulo[0]);
	/* Limpar a tela e desenhar o quadrado inicialmente azul */

	clrscr();
	/*primeira tela*/
	CriarTela(retangulo[0].tamanho, BLUE);
	do /* Loop que sai ao teclar ESC */
	{
		if(hit(MOUSE_HIT) || hit(KEYBOARD_HIT))
		{
			clique = Evento();
		}
		for(j = 0; j <= qtd; j++)
		{
			if (i % retangulo[j].velocidade == 0)
			{
				if( j != selecionado)
				{
					CriarTela(retangulo[j].tamanho, LIGHTGRAY);
					/* Apagar o quadrado de caracteres */
					ApagarQuadrado( retangulo[j].cursor );
					/* Movimentar o cursor automaticamente */
					AutomaticoXY(&retangulo[j]); 
					/* Escrever o quadrado de caracteres */
					PrintarQuadrado( &retangulo[j].cursor, LIGHTGRAY );
					/*informações do quadrado*/
					PrintarInfo(retangulo[j]);
				}
				else
				{
				CriarTela(retangulo[j].tamanho, retangulo[j].cor);
					/* Apagar o quadrado de caracteres */
				ApagarQuadrado( retangulo[j].cursor );
					/* Movimentar o cursor automaticamente */
				AutomaticoXY(&retangulo[j]); 
					/* Escrever o quadrado de caracteres */
				PrintarQuadrado( &retangulo[j].cursor, retangulo[j].cortxt );
					/*informações do quadrado*/
				PrintarInfo(retangulo[j]);
				}

			}
			teclaG = Detector(retangulo, clique, &j, &qtd, &selecionado);
		}
		i = controladorGeral(i);
	}
	while ( teclaG != ESC );
	
	/*Repor as configurações do console*/
	DespersonalizarConsoleFULL(principal);

	return 0; /* Programa encerrou com sucesso */
}
/* Fim do programa */