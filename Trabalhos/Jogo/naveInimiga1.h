#include "naveGenerica.h"


#pragma once
class naveInimiga1 : public naveGenerica
{
private:
	float pontosR[20][2];	// Matriz de pontos que definem todos os quadriláteros do modelo.
	GLfloat corR[5][3];		// Matriz de pontos que definem as cores dos quadriláteros do modelo.	
public:
	naveInimiga1(){
		stepX = 0.2f;
		stepY = 0.2f;
		xc = 4;
		yc = 1;
		carregaMatrizes("modelos/naveInimiga1.txt");
	}
	// Construtor da classe
	naveInimiga1(std::string filePath) : naveGenerica(){
		stepX = 0.2f;
		stepY = 0.2f;
		xc = 4;
		yc = 1;
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