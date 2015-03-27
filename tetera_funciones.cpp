#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

	int num; // variable de opciones del 1-5
	
    // parametros de los valores de Ambient, diffuse,specular y shine
    double amb1=0.329412f,amb2=0.223529f,amb3=0.027451f,dif1=0.780392f,dif2=0.568627f,dif3=0.113725f,esp1= 0.992157f,esp2=0.941176f,esp3=0.807843f,sh=27.8974f;
	void ponerMaterial(); //creamos funcion
	
		
	
	void teclado (unsigned char key, int x, int y)
	
			{
    switch (key)
    
    {
	case '1':
	num=1;
			ponerMaterial();
			break;
	case '2':
	num=2;
			ponerMaterial();
			break;
    case '3' :
    num=3;
            ponerMaterial();
        break;
    case '4' :
    num=4;
          ponerMaterial();
        break;
    case '5' :
    num=5;
        ponerMaterial();
        break;
        exit(0);} // exit 
    

    glutPostRedisplay();		  // actualización de visualización
}

/*
if ( key1 == '1' ) (a1=0.135;a2=0.2225;a3=0.1575;d1=0.54;d2=0.89;d3=0.63;e1=0.316228;e2=0.316228;e3=0.316228;s=0.1);
			//if ( key == '2' ) ponerMaterial();
			//if ( key == '3' ) ponerMaterial();
			//if ( key == '4' ) ponerMaterial();
			//if ( key == '5' ) ponerMaterial();
			
		}
	*/	
		
		void init(void)
		{
			
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0); //Activamos las luces en 0
		glDepthFunc(GL_LESS); //comparación de profundidad
		glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST

		}
		void reshape(int w, int h)
		{
		glViewport(0, 0, (GLsizei) w, (GLsizei) h);
		// Activamos la matriz de proyeccion.
		glMatrixMode(GL_PROJECTION);
		// "limpiamos" esta con la matriz identidad.
		glLoadIdentity();
		// Usamos proyeccion ortogonal
		glOrtho(-300, 300, -300, 300, -300, 300);
		// Activamos la matriz de modelado/visionado.
		glMatrixMode(GL_MODELVIEW);
		// "Limpiamos" la matriz
		glLoadIdentity();
		}
		
		
		
		
		
		void display(void)
				
				
		{
			//preparando material
		GLfloat mat_ambient[] = {amb1 ,amb2 , amb3};
		GLfloat mat_diffuse[] = { dif1,dif2 ,dif3  };
		GLfloat mat_specular[] = {esp1, esp2,esp3  };
		GLfloat shine[] = {sh};
			
				 
		
		// "Limpiamos" el frame buffer con el color de "Clear", en este
		// caso negro.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode( GL_MODELVIEW_MATRIX );
		glLoadIdentity();
		// Rotacion de 25 grados en torno al eje x
		glRotated(25.0, 1.0, 0.0, 0.0);
		// Rotacion de -30 grados en torno al eje y
		glRotated(-30.0, 0.0, 1.0, 0.0);
		// Dibujamos una "Tetera" y le aplico el material
		glPushMatrix();
		
		//aplicando material
		
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);		
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);		
		glMaterialfv(GL_FRONT, GL_SHININESS, shine);
		
		
		//setMaterial
		glutSolidTeapot(125.0);
		glFlush();
}
			
		

		void ponerMaterial()
{
	if (num==1)
	{
		amb1=0.135;amb2=0.2225;amb3=0.1575;dif1=0.54;dif2=0.89;dif3=0.63;esp1=0.316228;esp2=0.316228;esp3=0.316228;sh=0.1;
		}
	if (num==2) 
	{
		amb1=0.05375;amb2=0.05;amb3=0.06625;dif1=0.18275;dif2=0.17;dif3=0.22525;esp1=0.332741;esp2=0.328634;esp3=0.346435;sh=0.3;
		}
	if (num==3) 
	{
		amb1=0.25; amb2=0.20725;amb3=0.20725;dif1=1.0;dif2=0.829;dif3=0.829;esp1=0.296648;esp2=0.296648;esp3=0.296648;sh=0.088;
		}
	if (num==4) 
	{
		amb1=0.1745; amb2=0.01175;amb3=0.01175;dif1=0.61424;dif2=0.04136;dif3=0.04136;esp1=0.727811;esp2=0.626959;esp3=0.625969;sh=0.6;
		}
	if (num==5) 
	{
		amb1=0.1; amb2=0.18725;amb3=0.01745;dif1=0.396;dif2=0.74151;dif3=0.69102;esp1=0.297254;esp2=0.30829;esp3=0.306678;sh=0.1;
		}
	
	}

	
		int main(int argc, char **argv)
		{
		
		
			
			
			
		// Inicializo OpenGL
		glutInit(&argc, argv);
		// Activamos buffer simple y colores del tipo RGB
		glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
		// Definimos una ventana de medidas 800 x 600 como ventana
		// de visualizacion en pixels
		glutInitWindowSize (800, 600);
		// Posicionamos la ventana en la esquina superior izquierda de
		// la pantalla.
		glutInitWindowPosition (0, 0);
		// Creamos literalmente la ventana y le adjudicamos el nombre que se
		// observara en su barra de titulo.
		glutCreateWindow ("Tetera");
		
		// Funciones de retrollamada
		  glutDisplayFunc(display);
		  glutKeyboardFunc(teclado); //invoca funcion de teclado
		  
		  
		// Inicializamos el sistema
		init();
		glutDisplayFunc(display);
		glutReshapeFunc(reshape);
		glutMainLoop();
		return 0;
		
	}

