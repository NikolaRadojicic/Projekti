
#include<string.h>
#include<GL/glut.h>
#include<time.h>
#include "def.h"

/*Ovom funkcijom vrsimo izmenu stringa tako da nam on kazuje koliko je vremena ostalo do kraja*/
void promeniVreme(int* vreme){

	*vreme = (*vreme) - 1 ;
	char c7 = (*vreme) %10 + '0';
	char c6 = ( (*vreme) /10 ) %10 + '0';	
	time_string[7] = c7;
	time_string[6] = c6;
	
	
}

/*Ispisujemo preostalo vreme u igri*/
void IspisiVreme(const char *s){
	
	glColor3f(1,1,1);
 	glRasterPos3f(0,2.7,-2.9);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, s);

}

/*Kreiramo obavestenje koje ce nam ispisati da smo pobedili ili izgubili*/
void KreirajObavestenje(void){ 
 

	const char *s;

	if(pojeo == br_loptica)		/*Ukoliko smo pojeli sve loptice onda smo pobedili*/
		s = "You are winner!";
		
	else
		s = "GAME OVER";		/*Inace smo izgubili*/

	/*Crtamo pravougaonik na kome cemo ispisati poruku*/
	glColor3f(0,0,0);
	glPushMatrix();

		glRotatef(-20,1,0,0);
		glBegin(GL_QUADS);
			
			glVertex3f(2,1,1.4);
			glVertex3f(2,-1,1.4);
			glVertex3f(-2,-1,1.4);
			glVertex3f(-2,1,1.4);
		glEnd();

	glPopMatrix();
	
	/*Ispisujemo poruku*/
	glColor3f(1,0,0);
 	glRasterPos3f(-0.7,1,1.5);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, s);

	glRasterPos3f(-1.0,0.2,1.5);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Press N for new game !");
	pokrenuta_igra = 0;

}

/* Rezultat ce biti broj kugluca koje smo pojeli */
void promeniScore(){
	
	char c= pojeo + '0';	
	score [6] = c;
	
}


/*Menjamo broj neprijatelja*/
void promeniEnemyNumber(){

	char c= br_loptica - pojeo + '0';	
	preostalo_loptica[13] = c;
	
}

void ispisiBoje(){

	/*U zavisnosti od toga koji je level nas heroj on moze da jede loptice drugih boja, pa cemo ispisati boju koju sme jesti */
	if(heroj.level == 1)
		glColor3f(0,1,0);

	else if(heroj.level == 2)
		glColor3f(0,1,1);

	else glColor3f(0.7,0.5,0.4);

	glPushMatrix();

		
		glTranslatef(-1.3,2.8,-3);
		glutSolidSphere(0.1,50,20);

	glPopMatrix();


}
/* Ispisujemo Rezultat u gornji levi ugao*/
void IspisiPodatke(const char *s1, const char *s2){
	
	/*Ispisujemo Score i preostali broj loptica*/
	glColor3f(1,1,1);
 	glRasterPos3f(-2.8,3.2,-2.8);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, s1);
	

	glColor3f(1,1,1);
 	glRasterPos3f(-0,3.2,-2.8);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, s2);
	
	/*Ispisujemo koje to loptice moramo jesti sa trenutnim levelom */
	const char *s = "Must eat:";

	glColor3f(1,1,1);
 	glRasterPos3f(-2.8,2.7,-2.8);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, s);
	
	ispisiBoje();

	/*Ispisujemo broj preostalih neprijatelja i vreme */
	promeniEnemyNumber();
	IspisiVreme(time_string);
	
}

/*Ispisujemo listu opcija koje ce se pojaviti u prozoru */
void IspisiListu(char *s1,char *s2,char *s3){
		/* Ukoliko je neka opcija selektovana imace crvenu */
		glPushMatrix();
		if(selektovan == 1)
			glColor3f(1,0,0);
		else
			glColor3f(0,1,0);

 		glRasterPos3f(-0.6,1,3.2);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, s1);


		if(selektovan == 2)
			glColor3f(1,0,0);
		else
			glColor3f(0,1,0);

 		glRasterPos3f(-0.6,0.7,3.2);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, s2);

		if(selektovan == 3)
			glColor3f(1,0,0);
		else
			glColor3f(0,1,0);

 		glRasterPos3f(-0.6,0.4,3.2);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, s3);
			
		
	glPopMatrix();
}
