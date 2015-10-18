#include <math.h>
#include "navePrincipal.h"
#include "naveinimiga1.h"
#include "naveinimiga2.h"


const std::string caminhoNP = "modelos/navePrincipal.txt";
const std::string caminhoNI1 = "modelos/naveInimiga1.txt";
const std::string caminhoNI2 = "modelos/naveInimiga2.txt";

class principal {
protected:
	navePrincipal np;			// Nave Principal
	naveInimiga1 ni1;			// Inimigo 1
	naveInimiga2 ni2;			// Inimigo 2
	GLfloat telaX = 15.0f;		// Valor m�ximo atingido pela coordenada x. O valor m�nimo � 0.
	GLfloat telaY = 15.0f;		// Valor m�ximo atingido pela coordenada x. O valor m�nimo � 0.
	GLfloat stepX = 0.1f;		// Acr�scimo no atributo xc quando a nave se movimento no eixo x.
	GLfloat stepY = 0.1f;		// Acr�scimo no atributo yc quando a nave se movimento no eixo y.
	
	int windowWidth = 800;		// Largura da tela
	int windowHeight = 600;		// Altura da tela
	bool fullscreenON = false;	// Indica se o fullscreen est� ou n�o ativado
	bool anima = false;			// Indica se haver� ou n�o anima��o
	
	naveGenerica *n1, *n2,*n3,naves[200];
	
	//bool keyStates[256] = { false };	//
	//GLfloat cor[3] = { 0.3f, 0.6f, 0.3f };
	//GLfloat modCor = -0.1f;
public:
	principal()
	{
		telaX = 10.0f;
		telaY = 10.0f;
		stepX = 0.1f;
		stepY = 0.1f;
		windowWidth = 800;
		windowHeight = 600;		
		navePrincipal n(caminhoNP);
		naveInimiga1 ini(caminhoNI1);
		naveInimiga2 ini2(caminhoNI2);
		np = n;
		ni1 = ini;
		ni2 = ini2;
		naves[0] = ini;
		naves[1] = ini2;
		n1 = &n;
		n2 = &ini;
		n3 = &ini2;

	}
	void pressionarTecla(unsigned char key){
		GLfloat xc = np.getXC();
		GLfloat yc = np.getYC();
		GLfloat xci = xc;
		GLfloat yci = yc;
		switch (key) {
		case 'W':
		case 'w':
			yc += stepY;
			break;
		case 'S':
		case 's':
			yc -= stepY;
			break;
		case 'A':
		case 'a':
			xc -= stepX;
			break;
		case 'D':
		case 'd':
			xc += stepX;
			break;
		case 'F':
		case 'f':
			if (fullscreenON){
				fullscreenON = false;
				glutReshapeWindow(windowWidth, windowHeight);
			}
			else{
				glutFullScreen();
				fullscreenON = true;
			}
			break;
		case 27:   // ESC
			exit(0);
		case 13: // Enter
			break;
		}
		np.setCoord(xc, yc);
		if (naveGenerica::verificaColisaoGeral(&np, naves, 2)){
			np.setCoord(xci, yci);
		}
		
		np.colisaoTela(telaX,telaY);

		// Redesenha o quadrado com as novas coordenadas 
		glutPostRedisplay();
	}
	

	void pressionaSetas(int k){
		np.movimentaNave(k, telaX, telaY,naves,2);
	}
	/* Desenha a fun��o*/
	void desenhaTela()
	{
		glClearColor(stepX, 0.5, 0.5, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		//np.colisaoTela(telaX, telaY);
		np.desenha();
		ni1.desenha();
		ni2.desenha();

		glutSwapBuffers();
	}
	void remodelarTela(int w, int h){
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, telaX, 0, telaY);
	}
	float func(float x)
	{
		return sin(x);
	}
	void animacaoInicial(){
		GLfloat xc = np.getXC();			//
		GLfloat yc = np.getYC();
		if (xc < telaX - 1 && (!anima)){
			xc += stepX;
			yc += func(xc);
		}
		else
		{
			anima = true;
		}
		np.setCoord(xc, yc);
		//np.colisaoTela(telaX,telaY);
		glutPostRedisplay();
	}
	void iniciaTela(int argc, char **argv){
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
		glutInitWindowSize(windowWidth, windowHeight);
		glutInitWindowPosition(5, 5);
		glutCreateWindow("Avi�o2");		
	}
	
	void verificaColisaoGeral(){
		//verificaColisao(&np, &ni1);
		//verificaColisao(&np, &ni2);
		//verificaColisao(n1, n2);
		//verificaColisao(n1, n3);

	}

};

principal p;

/* Fun��o */

/* Redrawing func */
void redraw(void)
{
	p.desenhaTela();
};

/* Fun��o chamada enquanto nenhum evento � disparado */
void idle(void)
{
	glutPostRedisplay();
};

/* Key press processing */
void keyboardDown(unsigned char key, int x, int y) {	
	p.pressionarTecla(key);
}
void keyboardSpecialDown(int k, int x, int y) {
	p.pressionaSetas(k);
}


/* Window reashape */
void reshape(int w, int h)
{
	p.remodelarTela(w, h);
};

void Timer(int value)
{	
	//p.animacaoInicial();
	glutTimerFunc(33, Timer, 1);
}

void IniciaJogo(int argc, char **argv)
{
	p.iniciaTela(argc, argv);
	// Register GLUT callbacks. 
	glutDisplayFunc(redraw);
	glutKeyboardFunc(keyboardDown);
	glutSpecialFunc(keyboardSpecialDown);
	glutReshapeFunc(reshape);
	//glutTimerFunc(33, Timer, 1);
	glutIdleFunc(idle);


	glutMainLoop(); // Main loop 
}