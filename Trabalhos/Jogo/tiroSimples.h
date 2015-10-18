#include "naveGenerica.h"


#pragma once/* Evita o erro de v�rios includes iguais sendo chamados num mesmo arquivo
				na hora de compilar.*/

class tiroSimples : public naveGenerica
{
protected:
	
	float pontosR[4][2];	// Matriz de pontos que definem todos os quadril�teros do modelo.
	GLfloat corR[1][3];		// Matriz de pontos que definem as cores dos quadril�teros do modelo.

	float stepX;		// Incremento utilizado para gerar movimento na coordenada x
	float stepY;		// Incremento utilizado para gerar movimento na coordenada y
public:
	tiroSimples(){}
	// Construtor da classe
	tiroSimples(std::string filePath) : naveGenerica(){
		HP = 1;
		stepY = 0.5f;
		stepX = 0.5f;
		boundingBoxL = 0.1;
		boundingBoxA = 0.1;
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
};