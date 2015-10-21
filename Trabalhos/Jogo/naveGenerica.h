#include <gl/glut.h>
#include <fstream>
#include <string>


#pragma once	/* Evita o erro de v�rios includes iguais sendo chamados num mesmo arquivo
				na hora de compilar.*/
class naveGenerica
{
protected:
	int HP;				// HP: Health Points. Corresponde a vida do personagem
	float xc, yc;		// Define as coordenadas x e y do centro. Corresponde a coordenada inferior esquerda (0,0)
	float boundingBoxA;	// Define a altura da bounding box.
	float boundingBoxL;	// Define a largura da bounding box.
	int ct;				// Quantidade de cores para desenhar tri�ngulos
	int pt;				// Quantidade de pontos para desenhar tri�ngulos
	int cr;				// Quantidade de cores para desenhar quadril�teros
	int pr;				// Quantidade de pontos para desenhar quadril�teros
	int danoColisao;	// Quantidade de dano causado por uma colis�o.  Deve possuir valor 0 em todas as classes que forem tiros.
	int danoAtaque;		// Quantidade de dano causado por um ataque. Deve possuir valor 0 em todas as classes que n�o forem tiros.
	float stepX;		// Incremento utilizado para gerar movimento na coordenada x
	float stepY;		// Incremento utilizado para gerar movimento na coordenada y
public:
	// Construtor da classe sem passagem de par�metro.
	// Define a coordenada de centro como (xc,yc) = (0,0), boundingBox = 1 e HP = 100.
	naveGenerica(){
		ct = 0;
		pt = 0;
		cr = 0;
		pr = 0;
		xc = 0;
		yc = 0;
		boundingBoxA = 1;
		boundingBoxL = 1;
		danoColisao = 1;
		danoAtaque = 0;
		HP = 100;
	}
	// Construtor da classe com passagem de par�metro
	// x = xc, y = yc, b = boundingBox e h = HP
	naveGenerica(float x, float y, float ba, float bl, int h){
		xc = x;
		yc = y;
		boundingBoxA = ba;
		boundingBoxL = bl;
		HP = h;
	}
	// M�todo set do atributo xc. 
	void setXC(float x){
		xc = x;
	}
	// M�todo get do atributo xc. 
	float getXC(){
		return xc;
	}
	// M�todo set do atributo yc. 
	void setYC(float y){
		yc = y;
	}
	// M�todo get do atributo yc. 
	float getYC(){
		return yc;
	}
	// M�todo mais f�cil na hora de modificar as duas coordenadas ao mesmo tempo.
	void setCoord(float x, float y){
		xc = x;
		yc = y;
	}
	// M�todo set do atributo HP. 
	void setHP(int h){
		HP = h;
	}
	// M�todo get do atributo HP. 
	int getHP(){
		return HP;
	}
	// M�todo get do atributo danoColisao. 
	int getDanoColisao(){
		return danoColisao;
	}
	// M�todo get do atributo danoAtaque. 
	int getDanoAtaque(){
		return danoAtaque;
	}
	// M�todo que seve ser chamado caso haja colis�o entre naves para diminuir o HP da nave.
	void recebeDanoPorColisao(int colisao){
		HP -= colisao;
		if (HP < 0)
			HP = 0;
	}
	// M�todo que seve ser chamado caso haja colis�o entre naves e tiros para diminuir o HP da nave.
	void recebeDanoPorAtaque(int ataque){
		HP -= ataque;
		if (HP < 0)
			HP = 0;
	}
	// M�todo get do atributo getBoundingBoxA.
	float getBoundingBoxA(){
		return boundingBoxA;
	}
	// M�todo get do atributo getBoundingBoxL.
	float getBoundingBoxL(){
		return boundingBoxL;
	}
	void acrescentaPassoY(){
		yc += stepY;
	}
	/*Fun��o que descreve o movimento de uma nave. Recebe como par�metro uma fun��o que retorna um float.
	Deve ser implementada pelos inimigos. Recebe a cordenada xc como par�metro e calcula a coordenada yc*/
	void funcaoMovimento(float(*func)(float x)){
		yc = func(xc);
	}
	/*
	M�todo que l� o arquivo do modelo. Par�metros: 
	filePath = Caminho do arquivo. Adotaremos o padr�o "modelos/nomedoModelo.txt" sendo "modelos/" a pasta com os modelos.
	pontosT[][2] = Matriz de pontos que definem todos os tri�ngulos do modelo.
	corT[][3]	 = Matriz de pontos que definem as cores dos tri�ngulos do modelo.
	pontosR[][2] = Matriz de pontos que definem todos os quadril�teros do modelo.
	corR[][3]	 = Matriz de pontos que definem as cores dos quadril�teros do modelo.
	//*/
	void readFileVertices(std::string filePath, float pontosT[][2], GLfloat corT[][3], float pontosR[][2], GLfloat corR[][3]){
		std::ifstream file(filePath);
		char ch;
		ct = 0; pt = 0; cr = 0; pr = 0;
		while (file >> ch){
			switch (ch)
			{
			case 'u':
				file >> corT[ct][0] >> corT[ct][1] >> corT[ct][2];
				ct++;
				break;
			case 't':
				file >> pontosT[pt][0] >> pontosT[pt][1];
				pt++;
				break;
			case 'd':
				file >> corR[cr][0] >> corR[cr][1] >> corR[cr][2];
				cr++;
				break;
			case 'r':
				file >> pontosR[pr][0] >> pontosR[pr][1];
				pr++;
				break;
			}
		}

	}
	//*/

	/*L� o arquivo do modelo. Essa vers�o s� desenha quadril�teros. Par�metros:
	filePath = Caminho do arquivo. Adotaremos o padr�o "modelos/nomedoModelo.txt" sendo "modelos/" a pasta com os modelos.
	pontosR[][2] = Matriz de pontos que definem todos os quadril�teros do modelo.
	corR[][3]	 = Matriz de pontos que definem as cores dos quadril�teros do modelo.
	*/
	void readFileVertices(std::string filePath, float pontosR[][2], GLfloat corR[][3]){
		std::ifstream file(filePath);
		char ch;
		cr = 0; pr = 0;
		while (file >> ch){
			switch (ch)
			{
			case 'd':
				file >> corR[cr][0] >> corR[cr][1] >> corR[cr][2];
				cr++;
				break;
			case 'r':
				file >> pontosR[pr][0] >> pontosR[pr][1];
				pr++;
				break;
			}
		}

	}
	// Verifica as bordas.  Se a window for menor e o 
	// quadrado sair do volume de visualiza��o 
	void colisaoTela(float telaX, float telaY){
		if (xc > telaX - boundingBoxL)
			xc = telaX - boundingBoxL;
		else{
			if (xc <= telaX - boundingBoxL && xc<0)
				xc = 0;
		}


		if (yc > telaY - boundingBoxA)
			yc = telaY - boundingBoxA;
		else{
			if (yc < telaY - boundingBoxA && yc<0)
				yc = 0;
		}
	}
	/* M�todo que desenha o modelo usando tri�ngulos e quadril�teros.
	pontosT[][2] = Matriz de pontos que definem todos os tri�ngulos do modelo.
	corT[][3]	 = Matriz de pontos que definem as cores dos tri�ngulos do modelo.
	pontosR[][2] = Matriz de pontos que definem todos os quadril�teros do modelo.
	corR[][3]	 = Matriz de pontos que definem as cores dos quadril�teros do modelo.
	*/
	void desenhaGenerico(float pontosT[][2], GLfloat corT[][3], float pontosR[][2], GLfloat corR[][3]){
		glPushMatrix();
		int aux = 0;
		glColor3fv(corT[aux]);
		glBegin(GL_TRIANGLES);
		for (int t = 0; t < pt; t++){
			if ((t + 1) % 3 == 0 && aux < ct){
				glColor3fv(corT[aux]);
				aux++;
			}
			glVertex2f(xc + pontosT[t][0] * boundingBoxL, yc + pontosT[t][1] * boundingBoxA);
		}
		glEnd();
		aux = 0;
		glColor3fv(corR[aux]);
		glBegin(GL_QUADS);
		for (int r = 0; r < pr; r++){
			if ((r + 1) % 4 == 0 && aux < cr){
				glColor3fv(corR[aux]);
				aux++;
			}
			glVertex2f(xc + pontosR[r][0] * boundingBoxL, yc + pontosR[r][1] * boundingBoxA);
		}
		glEnd();

		glPopMatrix();
	}
	//*/


	/* M�todo que desenha o modelo usando quadril�teros.
	pontosR[][2] = Matriz de pontos que definem todos os quadril�teros do modelo.
	corR[][3]	 = Matriz de pontos que definem as cores dos quadril�teros do modelo.
	*/
	void desenhaGenerico(float pontosR[][2], GLfloat corR[][3]){
		glPushMatrix();		

		int aux = 0;
		glColor3fv(corR[aux]);
		glBegin(GL_QUADS);
		for (int r = 0; r < pr; r++){
			if ((r + 1) % 4 == 0 && aux < cr){
				glColor3fv(corR[aux]);
				aux++;
			}
			glVertex2f(xc + pontosR[r][0] * boundingBoxL, yc + pontosR[r][1] * boundingBoxA);
		}
		glEnd();

		glPopMatrix();
	}
	// M�todo que verifica a colis�o entre dois objetos
	// *n1 - Ponteiro que aponta para um Objeto qualquer que herde ou seja da classe naveGenerica
	// *n2 - Ponteiro que aponta para um Objeto qualquer que herde ou seja da classe naveGenerica
	static bool verificaColisao(naveGenerica *n1, naveGenerica *n2){
		if ((n1->getXC() + n1->getBoundingBoxL() < n2->getXC()) //D1<E2
			||(n1->getXC() > n2->getXC() + n2->getBoundingBoxL()) //E1>D2
			||(n1->getYC() + n1->getBoundingBoxA() < n2->getYC()) //C1<B2
			||(n1->getYC() > n2->getYC() + n2->getBoundingBoxA())){ //B1>C2
			return false;
		}
		else{
			n1->recebeDanoPorColisao(n2->getDanoColisao());	// Caso seja uma colis�o entre naves, cada nave recebe dano 1, sen�o, n�o haver� dano por colis�o.
			n2->recebeDanoPorColisao(n1->getDanoColisao());
			
			n1->recebeDanoPorAtaque(n2->getDanoAtaque());		// Caso seja uma colis�o entre uma nave e um tiro, a nave recebe o dano do tiro, sen�o, n�o haver� dano por ataque.				
			n2->recebeDanoPorAtaque(n1->getDanoAtaque());
			return true;
		}
	}
	// M�todo que verifica a colis�o entre in�meros objetos
	//	*n1 - Ponteiro que aponta para um Objeto qualquer que herde ou seja da classe naveGenerica
	//	naves[] - Vetor de naves presentes na tela.
	//	nNaves - N�mero de naves presentes na tela.
	static bool verificaColisaoGeral(naveGenerica *n1, naveGenerica naves[], int nNaves){		
		for (int x = 0; x < nNaves; x++){
			if (verificaColisao(n1, &naves[x])){
				return true;
			}
		}
		return false;
		
	}
};