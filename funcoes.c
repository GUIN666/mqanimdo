#include "funcoes.h"/*Todas as fun��es, procedimentos e defines*/



/*
Procedmento ApagarArea.
Cria uma window da cor preta, a qual se sobrep�e aos limites de linha e coluna.
*/
void ApagarArea(QUADRADO atual)
{
	CriarTela(atual, BLACK);
}

/*
Procedimento ApagarQuadrado.
A fun��o dele � apagar o quadrado de caracteres por meio de printf() com espa�os em brancos, utilizando como localizador o cursor.
*/
void ApagarQuadrado(COORD quadrado)
{
	int i;
	for(i = 0; i < 3; i++)	/*la�o de repeti��o*/
	{
		gotoxy(quadrado.X, quadrado.Y + i); /*utiliza o Y como par�metro para escrever a cada linha, sendo somado com a variavel i, a qual ir� asumir os papeis de 0, 1 e 2*/
		printf("   ");
	}
}

/*
Procedimento AtivarCOORD.
Este procedimento inicializa as vari�veis do tipo COORD passando os par�metros X e Y. O objetivo deste procedimento � reduzir o tamanho da decla��o de vari�veis.
*/
void AtivarCOORD(COORD *Item, int ValorX, int ValorY)
{
	Item->X = ValorX;
	Item->Y = ValorY;
}

/*
Procedimento AutomaticoXY.
A fun��o deste procedimento � movimentar o cursor automaticamente, al�m de impedir que o quadrado de caracteres avance os limites, fazendo a ilusao de
"rebater", necessitando dos seguintes par�metros:

autom		-> Para se localizar em qual dire��o seguir, sendo 1 para cima, 2 esquerda, 3 direita e 4, para baixo. Alterado caso atinja limite.
posicao 	-> Para localizar o cursor e garantir que ele nao ultrapasse os limites do quadrado (inicialmente da cor azul) .
final			-> Para localizar o limite do quadrado (inicialmente da cor azul).
inicial		-> Para localizar o inicio do quadrado (inicialmente da cor azul).
*/
void AutomaticoXY(RETANGULOS *todos)
{
	int limiteX = todos->tamanho.ponto3.X - todos->tamanho.ponto1.X -2; /*Calculo do limite final menos o inicial subtra�do o tamanha do quadrado de caracteres -1 como desconto para condi��o de rebater*/
    int limiteY = todos->tamanho.ponto2.Y - todos->tamanho.ponto1.Y -2;
	
    switch (todos->automatico) {
        case 1: /* Cima */
            if(limiteY > 3)	/*Pausar o quadrado de caracteres caso n�o tenha espa�o para ele se mover*/
			{
				if (todos->cursor.Y < todos->tamanho.ponto1.Y + 2)
				{					/*Se a posi��o Y do cursor for inferior a 2 (assumindo o valor de 1), incremente o Y e mude a vari�vel automatica para baixo (4)*/
					todos->cursor.Y = todos->cursor.Y + 1;
					todos->automatico = 4;
				}
				else
				{										/*Senao, decremente o Y at� que ele seja menor do que 2*/
					todos->cursor.Y = todos->cursor.Y - 1;
				}
			}
            break;
        case 2: /* Esquerda */
            if(limiteX > 3) /*Pausar o quadrado de caracteres caso n�o tenha espa�o para ele se mover*/
			{
				if (todos->cursor.X < todos->tamanho.ponto1.X + 2)
				{					/*Se a posi��o X do cursor for inferior a 2 (assumindo o valor de 1), incremente o X e mude a vari�vel automatica para direita (3)*/
					todos->cursor.X = todos->cursor.X + 1;
					todos->automatico = 3;
				}
				else
				{										/*Senao, decremente o X at� que ele seja menor do que 2*/
					todos->cursor.X = todos->cursor.X - 1;
				}
			}
            break;
        case 3: /* Direita */
			if(limiteX > 3) /*Pausar o quadrado de caracteres caso n�o tenha espa�o para ele se mover*/
			{
				if (todos->cursor.X > limiteX - 1) 
				{			/*Se a posi��o X do cursor for superior ao limite calculano na linha 105, decremente o X e mude a vari�vel automatica para esquerda (2)*/
					todos->cursor.X = todos->cursor.X - 1;
					todos->automatico= 2;
				}
				else
				{										/*Senao, incremente o X at� que seja maior que o limite calculado*/
					todos->cursor.X = todos->cursor.X + 1;
				}
			}
            break;
        case 4: /* Baixo */
		if(limiteY > 3) /*Pausar o quadrado de caracteres caso n�o tenha espa�o para ele se mover*/
		{
		    if (todos->cursor.Y > limiteY -1)
			{			/*Se a posi��o Y do cursor for superior ao limite calculano na linha 106, decremente o Y e mude a vari�vel automatica para cima (1)*/
                todos->cursor.Y =todos->cursor.Y - 1;
                todos->automatico = 1;
            }
			else
			{										/*Senao, incremente o Y at� que seja maior que o limite calculado*/
                todos->cursor.Y = todos->cursor.Y + 1;
            }
            break;
		}
    }
}

/*
Fun��o CorRand.
Fun��o que retorna um inteiro entre 1 e 15, sendo representada pelas cores que variam de 0 (sendo 0 o preto, o qual foi excluido desta fun��o) a 15 (sendo 15 a branca).
As paletas de cores enumeradas de 0 a 15, foi retirada da bibliteca conio_v_3.2.4.c.
*/
int CorRand(void)
{
	srand(time(NULL));
	return ((rand() % 15 + 1));
}

/*
Fun��o DescCor.
Fun��o que retorna uma string. Tem por objetivo descobrir e imprimir a cor arual da vari�vel "opcao", utilizando a enumera��o de cores da biblioteca conio ja apresentada na fun��o anterior (CorRand()).
*/
char *DescCor( int opcao)
{
	if ( opcao == 0)
	{
		return("PRETO");
	}
	if ( opcao == 1)
	{
		return("AZUL");
	}
	if ( opcao == 2)
	{
		return("VERDE");
	}
	if ( opcao == 3)
	{
		return("CIANO");
	}
	if ( opcao == 4)
	{
		return("VERMELHO");
	}
	if ( opcao == 5)
	{
		return("MAGENTA");
	}
	if ( opcao == 6)
	{
		return("MARROM");
	}
	if ( opcao == 7)
	{
		return("CINZA CLARO");
	}
	if ( opcao == 8)
	{
		return("CINZA ESCURO");
	}
	if ( opcao == 9)
	{
		return("AZUL CLARO");
	}
	if ( opcao == 10)
	{
		return("VERDE CLARO");
	}
	if ( opcao == 11)
	{
		return("CIANO CLARO");
	}
	if ( opcao == 12)
	{
		return("ROSA");
	}
	if ( opcao == 13)
	{
		return("ROXO");
	}
	if ( opcao == 14)
	{
		return("AMARELO");
	}
	if ( opcao == 15)
	{
		return("BRANCO");
	}
	return(0);
}

/*
Função em char que descobre a direção dado um valor de 1 a 4
*/
char *DescDir(int direcao)
{
	switch (direcao)
	{
	case 1:
		return "CIMA";
		break;
	case 2:
		return "ESQUERDA";
		break;
	case 3:
		return "DIREITA";
		break;
	case 4:
		return "BAIXO";
		break;
	default:
		return "NULL";
		break;
	}
}

/*
Procedimento DespersonalizarConsoleFULL
Procedimento que volta o t�tulo e o tamanho do console para sua resolução anterior, o mesmo para o cursor e barra de tarefas
*/
void DespersonalizarConsoleFULL(MEMORIACONSOLE antigo)
{
	/*titulo*/
	setTituloConsole(antigo.titulo);
	/*dimensionar*/
	setDimensaoJanela(antigo.resolucao.X,antigo.resolucao.Y);
	/*posicionar*/
	setPosicaoJanela(antigo.posicao.X, antigo.posicao.Y);
	/*ligar cursor*/
	setCursorStatus(LIGAR);
	/*barra de tarefas visivel*/
	setEstadoBarraTarefas(VISIVEL);
	textbackground(antigo.cor.CorFundo);
	textcolor(antigo.cor.CorTexto);
}
void CriarTela(QUADRADO telaSolicitada, int cor)
{
	int i, j; /*i mexe no x e j meche no y*/
	int j2;
	
	textcolor(cor);
	textbackground(cor);
	j = telaSolicitada.ponto1.Y;
	j2 = telaSolicitada.ponto2.Y;
	for(i = telaSolicitada.ponto1.X; i < telaSolicitada.ponto3.X; i++)
	{
		gotoxy(i,j);
		printf("X");
		gotoxy(i,j2);
		printf("X");
	}
	j = telaSolicitada.ponto1.X;
	j2 = telaSolicitada.ponto3.X;
	for(i = telaSolicitada.ponto1.Y; i < telaSolicitada.ponto2.Y; i++)
	{
		gotoxy(j,i);
		printf("X");
		gotoxy(j2,i);
		printf("X");
	}
	textcolor(LIGHTGRAY);
	textbackground(BLACK);
}

/*
Procedimento PersonalizarConsoleFULL
Procedimento que altera o t�tulo e o tamanho do console para sua resolução maxima, isto claro, ocultando o cursor e salvando seus valores como retorno
*/
MEMORIACONSOLE PersonalizarConsoleFULL(char *Titulo)
{
	/*declarar variaveis*/
	MEMORIACONSOLE tela;
	/*gravar cores antigas de fonte e fundo*/
	tela.cor = getCoresJanela();
	/*gravar resolução atual do console*/
	tela.resolucao = tamanhoJanelaConsole();
	/*gravar posição da janela*/
	tela.posicao = getPosicaoJanela();
	/*titulo antigo*/
	tela.titulo = getTituloConsole();
	/*titulo*/
	setTituloConsole(Titulo);
	/*desligar cursor*/
	setCursorStatus(DESLIGAR);
	/*barra de tarefas invisivel*/
	setEstadoBarraTarefas(INVISIVEL);
	/*posicionar*/
	setPosicaoJanela(1, 1);
	/*dimensionar*/
	setDimensaoJanela(MaxDimensaoJanela().X, MaxDimensaoJanela().Y);
	/*retornar a memoria*/
	return tela;
}

/*
Procedimento PrintarInfo.
Procedimento que busca imprimir os dados do programa.
*/
void PrintarInfo( RETANGULOS atual)
{
	textcolor(WHITE);
	gotoxy(atual.tamanho.ponto2.X, atual.tamanho.ponto2.Y);
	printf("|(X,Y):(%d,%d)", atual.cursor.X, atual.cursor.Y);
	printf("|Cor: %s", DescCor( atual.cortxt ));
	printf("|Dir: ");
	printf("%s", DescDir( atual.automatico ));
	printf("|Cor Borda: %s", DescCor( atual.cor ));
	printf("|Vel: %d ", atual.velocidade);
}

/*
Procedimento PrintarQuadrado.
A fun��o dele � escrever o quadrado de caracteres por meio de printf() com asteristicos, utilizando como localizador o cursor.
*/
void PrintarQuadrado(COORD *quadrado, int cor)
{
	int i;
	textcolor(cor);		/*Cor dado aleatoriamente caso seja solicitado (inicialmente � LIGHTGRAY e na forma randomizada, o 0 (preto) nunca � selecionado)*/
	for(i = 0; i < 3; i++) /*la�o de repeti��o*/
	{
		gotoxy(quadrado->X, quadrado->Y + i); /*utiliza o Y como par�metro para escrever a cada linha, sendo somado com a variavel i, a qual ir� asumir os papeis de 0, 1 e 2*/
		printf("***");
	}
}

void ValoresPadroes(RETANGULOS *retangulo)
{
	int x, y;
	retangulo->cor = BLUE; /* Cor da janela 1 = AZUL */
    retangulo->cortxt = LIGHTGRAY; /* Cor do texto 7 = LIGHTGRAY */
    retangulo->id = 0; /* Identificação do primeiro quadrado*/
	
	
	x = retangulo->tamanho.ponto1.X + 2;
	y = retangulo->tamanho.ponto1.Y + 2;
	/* Ativar Variáveis de coordenadas */
	AtivarCOORD( &retangulo->tamanho.ponto1, 1, 1 );
	AtivarCOORD( &retangulo->tamanho.ponto2, 1,LINHAS );
	AtivarCOORD( &retangulo->tamanho.ponto3, LINHAS, 1 );
	AtivarCOORD( &retangulo->tamanho.ponto4, LINHAS, COLUNAS );
	AtivarCOORD( &retangulo->cursor, x, y);
}
int controlaIndice(int i, int qtd)
{
	if(i < qtd)
	{
		return i+1;
	}
	else
	{
		return 0;
	}
}
/*controlador de velocidade*/
int controladorGeral(int velocidade)
{
	if ( velocidade >= VELOCIDADEMAX)
	{
		return VELOCIDADEMIN;
	}
	else 
	{
		return velocidade + VELOCIDADEPADRAO;
	}
}

/* Função que controla de um ponto (p3) esta entre dois pontos (p1 e p2), retorna 1 caso esteja e 0 caso nao esteja*/
int controleDePontos(COORD p1, COORD p2, COORD p3)
{
	int minX = p1.X < p2.X ? p1.X : p2.X; /*encontrar o menor X*/
    int maxX = p1.X > p2.X ? p1.X : p2.X; /*encontrar o maior X*/
    int minY = p1.Y < p2.Y ? p1.Y : p2.Y; /*encontrar o menor Y*/
    int maxY = p1.Y > p2.Y ? p1.Y : p2.Y; /*encontrar o maior Y*/

    if (p3.X >= minX && p3.X <= maxX && p3.Y >= minY && p3.Y <= maxY) /*Se o p3.x for maior ou igual ao menor ponto X e menor ou igual o maior ponto X (o mesmo feito com o Y)*/
	{
        return 1;
    }

    return 0;
}

/*
Função que diz se um quadrado é valido (1) ou nao (0), para ser colocado ou se um de seus pontos esta causando interferencia no quadrado selecionado.
*/
int Interferencia(QUADRADO novo, QUADRADO atual)
{
	int testador = 0;
	/*teste do primeiro ponto*/
	if(controleDePontos(atual.ponto1, atual.ponto3, novo.ponto1)||(controleDePontos(atual.ponto1, atual.ponto2, novo.ponto1)))
	{
		testador++;
	}
	if(controleDePontos(atual.ponto3, atual.ponto4, novo.ponto1)||(controleDePontos(atual.ponto2, atual.ponto4, novo.ponto1)))
	{
		testador++;
	}
	/*teste do segundo ponto*/
	if(controleDePontos(atual.ponto1, atual.ponto3, novo.ponto2)||(controleDePontos(atual.ponto1, atual.ponto2, novo.ponto2)))
	{
		testador++;
	}
	if(controleDePontos(atual.ponto3, atual.ponto4, novo.ponto2)||(controleDePontos(atual.ponto2, atual.ponto4, novo.ponto2)))
	{
		testador++;
	}
	/*teste do terceiro ponto*/
	if(controleDePontos(atual.ponto1, atual.ponto3, novo.ponto3)||(controleDePontos(atual.ponto1, atual.ponto2, novo.ponto3)))
	{
		testador++;
	}
	if(controleDePontos(atual.ponto3, atual.ponto4, novo.ponto3)||(controleDePontos(atual.ponto2, atual.ponto4, novo.ponto3)))
	{
		testador++;
	}
	/*teste do quarto ponto*/
	if(controleDePontos(atual.ponto1, atual.ponto3, novo.ponto4)||(controleDePontos(atual.ponto1, atual.ponto2, novo.ponto4)))
	{
		testador++;
	}
	if(controleDePontos(atual.ponto3, atual.ponto4, novo.ponto4)||(controleDePontos(atual.ponto2, atual.ponto4, novo.ponto4)))
	{
		testador++;
	}
	
	return((testador > 2 ? 0 : 1));


}

QUADRADO incrementaDireita(QUADRADO atual)
{
	atual.ponto3.X = atual.ponto3.X + 1;
	atual.ponto4.X = atual.ponto4.X + 1;

	return atual;
}
QUADRADO incrementaEsquerda(QUADRADO atual)
{
	atual.ponto1.X = atual.ponto1.X - 1;
	atual.ponto2.X = atual.ponto2.X - 1;

	return atual;
}
QUADRADO incrementaBaixo(QUADRADO atual)
{
	atual.ponto2.Y = atual.ponto2.Y + 1;
	atual.ponto4.Y = atual.ponto4.Y + 1;

	return atual;
}
QUADRADO incrementaCima(QUADRADO atual)
{
	atual.ponto1.Y = atual.ponto1.Y - 1;
	atual.ponto3.Y = atual.ponto3.Y - 1;

	return atual;
}
QUADRADO decrementaDireita(QUADRADO atual)
{
	atual.ponto3.X = atual.ponto3.X - 1;
	atual.ponto4.X = atual.ponto4.X - 1;

	return atual;
}
QUADRADO decrementaEsquerda(QUADRADO atual)
{
	atual.ponto1.X = atual.ponto1.X + 1;
	atual.ponto2.X = atual.ponto2.X + 1;

	return atual;
}
QUADRADO decrementaBaixo(QUADRADO atual)
{
	atual.ponto2.Y = atual.ponto2.Y - 1;
	atual.ponto4.Y = atual.ponto4.Y - 1;

	return atual;
}
QUADRADO decrementaCima(QUADRADO atual)
{
	atual.ponto1.Y = atual.ponto1.Y + 1;
	atual.ponto3.Y = atual.ponto3.Y + 1;

	return atual;
}

QUADRADO ativaNil(void)
{
	QUADRADO unico;
	
	unico.ponto1.X = NIL;
	unico.ponto1.Y = NIL;
	unico.ponto2.X = NIL;
	unico.ponto2.Y = NIL;
	unico.ponto3.X = NIL;
	unico.ponto3.Y = NIL;
	unico.ponto4.X = NIL;
	unico.ponto4.Y = NIL;

	return unico;
}

int cabenatela(COORD ponto)
{
	COORD dimensao = MaxDimensaoJanela();
	
	/*se o ponto estiver dentro da dimensao retorne 1*/
	if(ponto.X < dimensao.X && ponto.Y < dimensao.Y && ponto.X > 0 && ponto.Y > 0)
	{
		return (1); /*cabe*/
	}
	/*se o ponto X estiver no limite ou ultrapassado, porém o ponto Y nao, retorne 2*/
	if(ponto.X >= dimensao.X && ponto.Y < dimensao.Y)
	{
		return (2);/*nao cabe no X*/
	}
	/*se o ponto X for menor que o limite, porém o ponto Y estiver no limite ou passado, retorne 3*/
	if(ponto.X < dimensao.X && ponto.Y >= dimensao.Y)
	{
		return (3);/*nao cabe no Y*/
	}
	if(ponto.X <= 0 || ponto.Y <= 0)
	{
		return (4);
	}
	return (0); /*não cabe*/
}
/*cria e valida um quadrado novo*/
QUADRADO validaQuadradoNovo(RETANGULOS *vetor, int qtd)
{
	int i, aux;
	QUADRADO novo;
	aux = 0;
	for(i = 0; i < qtd && aux == 0; i++)
	{
		novo.ponto4.X = vetor[i].tamanho.ponto3.X + 6;
		novo.ponto4.Y = vetor[i].tamanho.ponto3.Y + 6;
		if(cabenatela(novo.ponto4) == 1)
		{
			aux = 1;
			novo.ponto1.X = vetor[i].tamanho.ponto3.X + 1;
			novo.ponto1.Y = vetor[i].tamanho.ponto3.Y;
		}
		if(cabenatela(novo.ponto4) >= 2) /*nao cabe na direita*/
		{
			/*testa embaixo*/
			novo.ponto4.X = vetor[i].tamanho.ponto2.X + 6;
			novo.ponto4.Y =vetor[i].tamanho.ponto2.Y + 6;
			if(cabenatela(novo.ponto4) == 1)
			{
				aux = 1;
				novo.ponto1.X = vetor[i].tamanho.ponto4.X;
				novo.ponto1.Y =vetor[i].tamanho.ponto4.Y + 1;
			}
			else
			{	/*testa em cima*/
				novo.ponto4.X = vetor[i].tamanho.ponto1.X + 6;
				novo.ponto4.Y =vetor[i].tamanho.ponto1.Y - 6;
				if(cabenatela(novo.ponto4) == 1)
				{
					aux = 1;
					novo.ponto1.X = vetor[i].tamanho.ponto1.X;
					novo.ponto1.Y = vetor[i].tamanho.ponto1.Y - 1;
				}
				else
				{	/*testa na esquerda*/
					novo.ponto4.X = vetor[i].tamanho.ponto2.X - 6;
					novo.ponto4.Y =vetor[i].tamanho.ponto2.Y;
					if(cabenatela(novo.ponto4) == 1)
					{
						aux = 1;
						novo.ponto1.X = vetor[i].tamanho.ponto2.X - 1;
						novo.ponto1.Y = vetor[i].tamanho.ponto2.Y;
					}
				}
			}
		}
		if(!aux && i == qtd-1)
		{
			i = 0;
		}
		novo.ponto2.X = novo.ponto1.X;
		novo.ponto2.Y = novo.ponto4.Y;
		novo.ponto3.X = novo.ponto4.X;
		novo.ponto3.Y = novo.ponto1.Y;

	}

	while(aux && InterferenciaVetor(vetor,novo,qtd))
	{
		novo = andaquadrado(novo);
	}
	return((aux ? novo : ativaNil()));
	
}
QUADRADO andaquadrado(QUADRADO atual)
{
	QUADRADO novo;
	novo = atual;
	/*direita*/
	if(cabenatela(novo.ponto4) == 1) /*cabe*/
	{
		novo = incrementaDireita(novo);
		novo = decrementaEsquerda(novo);
	}
	if(cabenatela(novo.ponto4) == 2)
	{
		novo = incrementaBaixo(novo);
		novo = decrementaCima(novo);
		novo = decrementaDireita(novo);
		novo = incrementaEsquerda(novo);
	}
	if(cabenatela(novo.ponto4) == 3)
	{
		novo = incrementaCima(novo);
		novo = decrementaBaixo(novo);
		novo = incrementaDireita(novo);
		novo = decrementaEsquerda(novo);
	}
	return novo;

}
int InterferenciaVetor(RETANGULOS *vetor, QUADRADO atual, int qtd)
{
	int i = 0;
	while( i < qtd && (Interferencia(atual, (vetor[i].tamanho))) == 0)
	{
		i++;
	}
	return( i > 0 ? 1 : 0);
}
/*
COORD menorcoord(COORD primeiro, COORD segundo)
{
	if (primeiro.X < segundo.X || (primeiro.X == segundo.X && primeiro.Y < segundo.Y))
	{
		return(primeiro);
	}
	return(segundo);
}
*/ 
void quadradoInativo(RETANGULOS *selecionado)
{
	selecionado->cor = LIGHTGRAY;
	selecionado->cortxt = LIGHTGRAY;
}
void quadradoAtivo(RETANGULOS *selecionado, int id, int cor, int cortxt) /*apenas o que bater com a id vai ser o selecionado*/
{
	
	selecionado[id].cor = BLUE;
	selecionado[id].cortxt =LIGHTGRAY;
}
int pegaQuadrado (RETANGULOS *todos, int qtd, COORD tecla)
{
	int i;
	for (i = 0; i < qtd; i++)
	{
		if(controleDePontos(todos[i].tamanho.ponto1, todos[i].tamanho.ponto4, tecla))
		{
			return(todos[i].id);
		}
	}
	return(-1);
}
int Detector(RETANGULOS *todos, EVENTO clique, int *i, int *qtd, int *selecionado)
{
	int salvaI;
		if(clique.tipo_evento & MOUSE_EVENT) /*tipo de evento do mouse*/
		{
			if(clique.mouse.botao_clicou & BOTAO_ESQUERDO_PRESSIONADO && pegaQuadrado(todos, *qtd, clique.mouse.posicao) != -1)
			{
				*selecionado = pegaQuadrado(todos, *qtd, clique.mouse.posicao);
				quadradoAtivo(todos, *selecionado, BLUE, LIGHTGRAY);
			}
			return 0;
		}
		if(clique.tipo_evento & KEY_EVENT && clique.teclado.status_tecla & PRESSIONADA) /*tipo de evento do teclado*/
		{
			if(clique.teclado.codigo_tecla >= F1 && clique.teclado.codigo_tecla <= F10)
			{
				FuncaoF1aoF10(clique.teclado.codigo_tecla, todos, *selecionado, *qtd);
				return 0;
			}
			else
			{
				if(clique.teclado.status_teclas_controle & RIGHT_CTRL_PRESSED  | clique.teclado.status_teclas_controle & LEFT_CTRL_PRESSED) /*controle*/
				{
					
					printf("a");
					salvaI = *i;
					*qtd = *qtd +1;
					*i = *qtd;
					todos[*i].id = *i;
					todos[*i].tamanho = validaQuadradoNovo(todos, *qtd); /*valida um quadrado novo*/
					if (todos[*i].tamanho.ponto1.X == NIL)
					{
						*qtd = *qtd -1;
						*i = salvaI;
					}
					else
					{
						quadradoAtivo(&todos[*i], *i, BLUE, LIGHTGRAY); /*ativa com as cores padores*/
						*selecionado = *i;
						AtivaAleatorio(&(todos[*i])); /*da os valores de direç~cao*/
					}
					return 0;
				}
				switch(clique.teclado.codigo_tecla)
				{
					case ESC:
						return ESC;
						break;
					case SETA_PARA_CIMA:
						todos[*selecionado].automatico = 1; /*cima*/
						break;
					case SETA_PARA_BAIXO:
						todos[*selecionado].automatico = 4; /*baixo*/
						break;
					case SETA_PARA_ESQUERDA:
						todos[*selecionado].automatico = 2; /*esquerda*/
						break;
					case SETA_PARA_DIREITA:
						todos[*selecionado].automatico = 3; /*direita*/
						break;
					case TAB:
						todos[*selecionado].cortxt = CorRand();
						break;
					case ESPACO:
						todos[*selecionado].cor = CorRand();
						break;
				}
			}
			
		}
	return 0;
}
void FuncaoF1aoF10(int opcao, RETANGULOS *todos, int i, int qtd)
{
	switch (opcao)
	{
		case F1:
			if (todos[i].velocidade > VELOCIDADEMIN)
			{
				todos[i].velocidade = todos[i].velocidade -1;
			}
		break;
		case F2:
			if (todos[i].velocidade < VELOCIDADEMAX)
			{
				todos[i].velocidade = todos[i].velocidade +1;
			}
		break;
		case F3:
			if(InterferenciaVetor(todos, incrementaEsquerda(todos[i].tamanho),qtd))
			{
				todos[i].tamanho = incrementaEsquerda(todos[i].tamanho);
			}
		break;
		case F4:
		if(InterferenciaVetor(todos, decrementaEsquerda(todos[i].tamanho),qtd))
			{
				todos[i].tamanho = decrementaEsquerda(todos[i].tamanho);
			}
		break;
		case F5:
		if(InterferenciaVetor(todos, incrementaDireita(todos[i].tamanho),qtd))
			{
				todos[i].tamanho = incrementaDireita(todos[i].tamanho);
			}
		break;
		case F6:
		if(InterferenciaVetor(todos, decrementaDireita(todos[i].tamanho),qtd))
			{
				todos[i].tamanho = decrementaDireita(todos[i].tamanho);
			}
		break;
		case F7:
		if(InterferenciaVetor(todos, incrementaCima(todos[i].tamanho),qtd))
			{
				todos[i].tamanho = incrementaCima(todos[i].tamanho);
			}
		break;
		case F8:
		if(InterferenciaVetor(todos, decrementaCima(todos[i].tamanho),qtd))
			{
				todos[i].tamanho = decrementaCima(todos[i].tamanho);
			}
		break;
		case F9:
		if(InterferenciaVetor(todos, incrementaBaixo(todos[i].tamanho),qtd))
			{
				todos[i].tamanho = incrementaBaixo(todos[i].tamanho);
			}
		break;
		case F10:
		if(InterferenciaVetor(todos, decrementaBaixo(todos[i].tamanho),qtd))
			{
				todos[i].tamanho = decrementaBaixo(todos[i].tamanho);
			}
		break;
	}
	
}
void AtivaAleatorio(RETANGULOS *atual)
{

	srand( time( NULL ) );

	atual->velocidade = rand() % VELOCIDADEMAX + VELOCIDADEMIN;
	atual->automatico = rand() % 4 + 1;
	atual->cursor.X = atual->tamanho.ponto1.X+1;
	atual->cursor.Y = atual->tamanho.ponto1.Y+1;
}
