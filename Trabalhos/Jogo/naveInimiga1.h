#include "naveGenerica.h"
using namespace std;

#pragma once
class naveInimiga1 : public naveGenerica
{
private:
	float pontosR[20][2];	// Matriz de pontos que definem todos os quadriláteros do modelo.
	GLfloat corR[5][3];		// Matriz de pontos que definem as cores dos quadriláteros do modelo.
	float stepX;		// Acréscimo no atributo xc quando a nave se movimento no eixo x.
	float stepY;		// Acréscimo no atributo yc quando a nave se movimento no eixo y.
public:
	naveInimiga1(){}
	// Construtor da classe
	naveInimiga1(string filePath) : naveGenerica(){
		stepX = 0.2f;
		stepY = 0.2f;
		xc = 4;
		yc = 1;
		carregaMatrizes(filePath);

	}
	// Método que lê o arquivo do modelo.
	void carregaMatrizes(string filePath){
		readFileVertices(filePath, pontosR, corR);
	}
	// Chama o método genérico de desenhar
	void desenha(){
		desenhaGenerico(pontosR, corR);
	}
};