#include "naveGenerica.h"


#pragma once/* Evita o erro de vários includes iguais sendo chamados num mesmo arquivo
				na hora de compilar.*/

class tiroSimples : public naveGenerica
{
protected:
	
	float pontosR[4][2];	// Matriz de pontos que definem todos os quadriláteros do modelo.
	GLfloat corR[1][3];		// Matriz de pontos que definem as cores dos quadriláteros do modelo.

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
	// Método que lê o arquivo do modelo.
	void carregaMatrizes(std::string filePath){
		readFileVertices(filePath, pontosR, corR);
	}
	// Chama o método genérico de desenhar
	void desenha(){
		desenhaGenerico(pontosR, corR);
	}
};