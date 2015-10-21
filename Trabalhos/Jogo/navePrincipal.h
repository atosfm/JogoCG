#include "tiroSimples.h"
#include<vector>


class navePrincipal : public naveGenerica
{
private:
	int vidas;				// Define a quantidade de vidas do jogador.	
	float pontosT[21][2];	// Matriz de pontos que definem todos os triângulos do modelo.
	GLfloat corT[7][3];		// Matriz de pontos que definem as cores dos triângulos do modelo.
	float pontosR[12][2];	// Matriz de pontos que definem todos os quadriláteros do modelo.
	GLfloat corR[3][3];		// Matriz de pontos que definem as cores dos quadriláteros do modelo.
	std::vector<tiroSimples> tiro1;	
public:
	navePrincipal(){		
		stepX = 0.1f;
		stepY = 0.1f;
		xc = 0;
		yc = 0;
		vidas = 5;
		carregaMatrizes("modelos/navePrincipal.txt");
	}
	// Construtor da classe
	navePrincipal(std::string filePath) : naveGenerica(){		
		stepX = 0.1f;
		stepY = 0.1f;
		xc = 0;
		yc = 0;
		vidas = 5;
		carregaMatrizes(filePath);
	}
	// Construtor da classe com passagem de parâmetro
	// x = xc, y = yc, b = boundingBox, h = HP, v = vidas, filePath = Caminho do arquivo
	navePrincipal(float x, float y, float ba, float bl, int h, int v, std::string filePath) : naveGenerica(){
		xc = x;
		yc = y;
		boundingBoxA = ba;
		boundingBoxL = bl;
		HP = h;
		vidas = v;
		carregaMatrizes(filePath);
		
	}
	// Método set do atributo vidas.
	void setVidas(int v){
		vidas = v;
	}
	// Método get do atributo vidas.
	int getVidas(){
		return vidas;
	}
	
	// Método que lê o arquivo do modelo.
	void carregaMatrizes(std::string filePath){
		readFileVertices(filePath, pontosT, corT, pontosR, corR);
	}
	// Chama o método genérico de desenhar
	void desenha(){
		desenhaGenerico(pontosT, corT, pontosR, corR);
	}
	// Método que movimenta a nave pelo pressionamento das setas no teclado.
	void movimentaNave(int k, GLfloat telaX, GLfloat telaY, naveGenerica naves[], int nIndices){
		GLfloat xc = getXC();
		GLfloat yc = getYC();
		GLfloat xci = xc;
		GLfloat yci = yc;
		switch (k)
		{
		case GLUT_KEY_UP:
			yc += stepY;
			break;
		case GLUT_KEY_DOWN:
			yc -= stepY;
			break;
		case GLUT_KEY_LEFT:
			xc -= stepX;
			break;
		case GLUT_KEY_RIGHT:
			xc += stepX;
			break;
		}						
		setCoord(xc, yc);
		colisaoTela(telaX, telaY);
		if ( (naveGenerica::verificaColisaoGeral(this, naves, nIndices )) ){
			setCoord(xci, yci);			
			glutPostRedisplay();
		}
		

	}
	void atirar1(GLfloat telaY){
		tiroSimples t;
		t.setCoord(xc + 0.45f, yc + 1.0f);		
		tiro1.push_back(t);
		//desenhaTiros();

		/*
		std::vector<tiroSimples>::iterator i;

		i = tiro1.begin();
		while (i != tiro1.end()){			
			i->acrescentaPassoY();
			i = tiro1.begin() + 1;
		}
			
		//*/
		//movimentaTiros1(telaY);
	}
	void desenhaTiros(){
		std::vector<tiroSimples>::iterator i;
		int n = 1;
		i = tiro1.begin();
		while (i != tiro1.end()){
			i->desenha();
			i = tiro1.begin() + n;
			n++;
		}
	}
	//*
	void movimentaTiros1(GLfloat telaY){
		std::vector<tiroSimples>::iterator i = tiro1.begin();		
		int n = tiro1.size();
		if (n > 0){
			n = 0;
			while (i != tiro1.end()){
				i->acrescentaPassoY();
				if (i->getYC() > telaY){
					tiro1.erase(i);
				}
				else{
					n++;
				}
				i = tiro1.begin() + n;
			}
		}
		
				
	}
	void colisaoTiros1(){

	}
	//*/
};