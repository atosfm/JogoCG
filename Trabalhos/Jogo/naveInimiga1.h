#include "naveGenerica.h"


#pragma once
class naveInimiga1 : public naveGenerica
{
private:
	float pontosR[20][2];	// Matriz de pontos que definem todos os quadril�teros do modelo.
	GLfloat corR[5][3];		// Matriz de pontos que definem as cores dos quadril�teros do modelo.
	float stepX;		// Acr�scimo no atributo xc quando a nave se movimento no eixo x.
	float stepY;		// Acr�scimo no atributo yc quando a nave se movimento no eixo y.
public:
	naveInimiga1(){}
	// Construtor da classe
	naveInimiga1(std::string filePath) : naveGenerica(){
		stepX = 0.2f;
		stepY = 0.2f;
		xc = 4;
		yc = 1;
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