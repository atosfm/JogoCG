#include "naveGenerica.h"


#pragma once/* Evita o erro de vários includes iguais sendo chamados num mesmo arquivo
				na hora de compilar.*/

class naveInimiga2 : public naveGenerica
{
protected:
	
	float pontosT[18][2];	// Matriz de pontos que definem todos os triângulos do modelo.
	GLfloat corT[6][3];		// Matriz de pontos que definem as cores dos triângulos do modelo.
	float pontosR[8][2];	// Matriz de pontos que definem todos os quadriláteros do modelo.
	GLfloat corR[2][3];		// Matriz de pontos que definem as cores dos quadriláteros do modelo.	
public:
	naveInimiga2(){
		stepY = 0.1f;
		stepX = 0.1f;
		xc = 7;
		yc = 5;
		carregaMatrizes("modelos/naveInimiga2.txt");
	}
	// Construtor da classe
	naveInimiga2(std::string filePath) : naveGenerica(){
		stepY = 0.1f;
		stepX = 0.1f;
		xc = 3;
		yc = 3;
		carregaMatrizes(filePath);
	}
	// Método que lê o arquivo do modelo.
	void carregaMatrizes(std::string filePath){
		readFileVertices(filePath, pontosT, corT, pontosR, corR);
	}
	// Chama o método genérico de desenhar
	void desenha(){
		desenhaGenerico(pontosT, corT, pontosR, corR);
	}
};