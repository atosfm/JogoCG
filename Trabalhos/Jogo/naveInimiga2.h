#include "naveGenerica.h"


#pragma once/* Evita o erro de v�rios includes iguais sendo chamados num mesmo arquivo
				na hora de compilar.*/

class naveInimiga2 : public naveGenerica
{
protected:
	
	float pontosT[18][2];	// Matriz de pontos que definem todos os tri�ngulos do modelo.
	GLfloat corT[6][3];		// Matriz de pontos que definem as cores dos tri�ngulos do modelo.
	float pontosR[8][2];	// Matriz de pontos que definem todos os quadril�teros do modelo.
	GLfloat corR[2][3];		// Matriz de pontos que definem as cores dos quadril�teros do modelo.

	float stepX;		// Incremento utilizado para gerar movimento na coordenada x
	float stepY;		// Incremento utilizado para gerar movimento na coordenada y
public:
	naveInimiga2(){}
	// Construtor da classe
	naveInimiga2(std::string filePath) : naveGenerica(){
		stepY = 0.1f;
		stepX = 0.1f;
		xc = 3;
		yc = 3;
		carregaMatrizes(filePath);
	}
	// M�todo que l� o arquivo do modelo.
	void carregaMatrizes(std::string filePath){
		readFileVertices(filePath, pontosT, corT, pontosR, corR);
	}
	// Chama o m�todo gen�rico de desenhar
	void desenha(){
		desenhaGenerico(pontosT, corT, pontosR, corR);
	}
};