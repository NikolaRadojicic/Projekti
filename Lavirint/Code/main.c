#include<stdio.h>
#include "def.h"
#include<stdlib.h>
#include<GL/glut.h>


int main(int argc,char **argv){

	/* Inicijalizuje se glut */
	glutInit(&argc,argv);	
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 

	/* Kreiramo prozor */
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);

	/* Callback funkcije */
	glutDisplayFunc(on_display);
	glutKeyboardFunc(on_keyboard);
	glutReshapeFunc(on_reshape);

	/* OpenGl inicijalizacija */
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	
	/* Ulazimo u glavnu petlju */
	glutMainLoop();


	return 0;
}




