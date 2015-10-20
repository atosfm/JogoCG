#include "naveGenerica.h"


#pragma once/* Evita o erro de v�rios includes iguais sendo chamados num mesmo arquivo
				na hora de compilar.*/

class tiroSimples : public naveGenerica
{
protected:
	
	float pontosR[4][2];	// Matriz de pontos que definem todos os quadril�teros do modelo.
	GLfloat corR[1][3];		// Matriz de pontos que definem as cores dos quadril�teros do modelo.

	
public:
	tiroSimples(){
		HP = 1;
		stepY = 0.5f;
		stepX = 0.5f;
		boundingBoxL = 0.1f;
		boundingBoxA = 0.1f;
		carregaMatrizes("modelos/tiroSimples.txt");
	}
	// Construtor da classe
	tiroSimples(std::string filePath) : naveGenerica(){
		HP = 1;
		stepY = 0.5f;
		stepX = 0.5f;
		boundingBoxL = 0.1f;
		boundingBoxA = 0.1f;
		carregaMatrizes(filePath);
	}
	// M�todo que l� o arquivo do modelo.
	void carregaMatrizes(std::string filePath){
		readFileVertices(filePath, pontosR, corR);
	}
	// Chama o m�todo gen�rico de desenhar
	void desenha(){
		desenhaGenerico(pontosR, corR);
	}
	float descreveFuncaoMovimento(){
		yc += stepY;
	}
	/* M�todo que desenha o modelo usando quadril�teros. (tiro)
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
			glVertex2f(xc + pontosR[r][0] , yc + pontosR[r][1]);
		}
		glEnd();

		glPopMatrix();
	}
};