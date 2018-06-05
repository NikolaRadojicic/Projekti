#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<time.h>
#include "def.h"



/*Crta se loptica na poligonu*/

void NacrtajLopticu(lopta* loptica){

	
		

	glPushMatrix();
	/*Ukoliko je loptica heroj i ako je aktivirana nevidljivost onda loptica postaje crna*/
		if(loptica->heroj == 1 && nevidljiv == 1)	
			glColor3f(0,0,0);
		else		
			glColor3f(loptica->boja[0],loptica->boja[1],loptica->boja[2]);	/*Inace crtamo lopticu sa njenom dodeljenom bojom*/

		glTranslatef(loptica->x_pos,loptica->y_pos,loptica->z_pos);
		glutSolidSphere(loptica->poluprecnik,50,20);
		
	glPopMatrix();
	
	
		
}

/* Funkcija koja crta glavni poligon igre */
void NacrtajPoligon(void){

	/*Crtamo plavi deo poligona */
	glColor3f(0,0,1);
	glPushMatrix();

		glRotatef(-60,1,0,0);
		glBegin(GL_QUADS);
			
			glVertex3f(poligon_sirina/2,poligon_duzina/2,0);
			glVertex3f(poligon_sirina/2,-poligon_duzina/2,0);
			glVertex3f(-poligon_sirina/2,-poligon_duzina/2,0);
			glVertex3f(-poligon_sirina/2,poligon_duzina/2,0);
		glEnd();

	glPopMatrix();

	/* Odavde pa sve do kraja crtamo zidove koji su na poligonu */
	

	/*skroz donji zid*/
	glPushMatrix();
		glColor3f(1,0,0);
		glRotatef(-60,1,0,0);
		glTranslatef(0,-2.75,0.3);
		glScalef(10,2.4,2);	
		glutSolidCube(poligon_sirina / 28);
		
	glPopMatrix();

	/*gornji crni deo */
	glPushMatrix();
		glColor3f(0,0,0);
		glRotatef(-60,1,0,0);
		glTranslatef(0,-2.75,0.6);
		glScalef(10,2.4,0.1);	
		glutSolidCube(poligon_sirina / 28);
		
	glPopMatrix();
	
	

	/*levi zid dole*/
	glPushMatrix();
		glColor3f(1,0,0);
		glRotatef(-60,1,0,0);
		glTranslatef(-2.375,-2.3,0.3);
		glScalef(2.8,3.5,2);	
		glutSolidCube(poligon_sirina / 28);
		
	glPopMatrix();
	/*gornji crni deo*/
	glPushMatrix();
		glColor3f(0,0,0);
		glRotatef(-60,1,0,0);
		glTranslatef(-2.375,-2.3,0.6);
		glScalef(2.8,3.5,0.1);	
		glutSolidCube(poligon_sirina / 28);
		
	glPopMatrix();
	
	glColor3f(1,0,0);
	/*desni zid dole*/
	glPushMatrix();
		glColor3f(1,0,0);
		glRotatef(-60,1,0,0);
		glTranslatef(2.375,-2.3,0.3);
		glScalef(2.6,3.5,2);	
		glutSolidCube(poligon_sirina / 28);
		
	glPopMatrix();
	/*gornji crni deo*/
	glPushMatrix();
		glColor3f(0,0,0);
		glRotatef(-60,1,0,0);
		glTranslatef(2.375,-2.3,0.6);
		glScalef(2.6,3.5,0.1);	
		glutSolidCube(poligon_sirina / 28);
		
	glPopMatrix();

	
	/*srednji zid na sredini*/
	glPushMatrix();
		glColor3f(1,0,0);
		glRotatef(-60,1,0,0);
		glTranslatef(0,-0.25,0.3);
		glScalef(2.5,5,2);	
		glutSolidCube(poligon_sirina / 28);
		
	glPopMatrix();
	/*gornji crni deo*/
	glPushMatrix();
		glColor3f(0,0,0);
		glRotatef(-60,1,0,0);
		glTranslatef(0,-0.25,0.6);
		glScalef(2.5,5,0.1);	
		glutSolidCube(poligon_sirina / 28);
		
	glPopMatrix();

	

	/*srednji levi zid*/
	glPushMatrix();
		glColor3f(1,0,0);
		glRotatef(-60,1,0,0);
		glTranslatef(-1.70,-0.25,0.3);
		glScalef(6,5,2);	
		glutSolidCube(poligon_sirina / 28);
		
	glPopMatrix();
	/*gornji crni deo*/
	glPushMatrix();
		glColor3f(0,0,0);
		glRotatef(-60,1,0,0);
		glTranslatef(-1.70,-0.25,0.6);
		glScalef(6,5,0.1);	
		glutSolidCube(poligon_sirina / 28);
		
	glPopMatrix();

	

	/*srednji desni zid*/
	glPushMatrix();
		glColor3f(1,0,0);
		glRotatef(-60,1,0,0);
		glTranslatef(1.70,-0.25,0.3);
		glScalef(6,5,2);	
		glutSolidCube(poligon_sirina / 28);
		
	glPopMatrix();
	/*gornji crni deo*/
	glPushMatrix();
		glColor3f(0,0,0);
		glRotatef(-60,1,0,0);
		glTranslatef(1.70,-0.25,0.6);
		glScalef(6,5,0.1);	
		glutSolidCube(poligon_sirina / 28);
		
	glPopMatrix();

	
	/*skroz gornji zid */
	glPushMatrix();
		glColor3f(1,0,0);
		glRotatef(-60,1,0,0);
		glTranslatef(0,2,0.3);
		glScalef(12.2,3.5,2);	
		glutSolidCube(poligon_sirina / 28);
		
	glPopMatrix();
	/*gornji crni deo*/
	glPushMatrix();
		glColor3f(0,0,0);
		glRotatef(-60,1,0,0);
		glTranslatef(0,2,0.6);
		glScalef(12.2,3.5,0.1);	
		glutSolidCube(poligon_sirina / 28);
		
	glPopMatrix();

	
	/* deo za ispisivanje skora,vremena i drugih obavestenja */
	glPushMatrix();

		glBegin(GL_QUADS);
			glColor3f(0,0,0);
			glVertex3f(3,3.5,-3);
			glVertex3f(3,2.5,-3);
			glVertex3f(-3,2.5,-3);
			glVertex3f(-3,3.5,-3);
		glEnd();

	glPopMatrix();

	

}

/* Kreiraju se sve loptice na poligonu i vrsi se njihova inicijalizacija*/
void kreirajLoptice(void){
		
	NacrtajLopticu(&heroj);	/*Crtamo prvo heroja (zutu lopticu)*/

	if(kreirani_neprijatelji == 0) /*Ako nije izvrsena inicijalizacija neprijatelja inicijalizujemo ih*/
		InicijalizujNeprijatelje(br_loptica,neprijatelj);
	
	int i;
	
	
	for(i = 0; i< br_loptica ; i++){	/*Ako je loptica aktivna crtamo je , loptica je aktivna ukoliko je nismo pojeli */
		if(neprijatelj[i].aktivna == 1)
			NacrtajLopticu(&neprijatelj[i]);
	
			}

}

/*Crtamo prozor u kome ce biti ispisane najbolja vremena za koja smo zavrsili partiju sa pobedom*/
void NacrtajHighScore(char s1[],char s2[],char s3[]){ 
	
	

	glPushMatrix();
		
		glColor3f(0,1,0);

 		glRasterPos3f(-0.6,1,1);	
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, s1);

 		glRasterPos3f(-0.6,0.7,1);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, s2);

 		glRasterPos3f(-0.6,0.4,1);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, s3);
			
		
	glPopMatrix();



}

/*Crtamo pocetni meni koji se ispisuje kada se igra startuje*/
void NacrtajMeni(void){

	/*Prvo crtamo jedan sivi pravougaonik*/
	glColor3f(0.5,0.5,0.5);
	glPushMatrix();
			
		glRotatef(-20,1,0,0);	
		glBegin(GL_QUADS);
			
			glVertex3f(3,2,0);
			glVertex3f(3,-2,0);
			glVertex3f(-3,-2,0);
			glVertex3f(-3,2,0);
		glEnd();

	glPopMatrix();
	
	 char *s1;
	 char *s2;
	 char *s3;
	
	int i1,i2,i3;
	/*Zatim u zavisnosti od toga koji prozor trenutno gledamo ispisuju se odgovarajuce opcije*/
	if(start_podesavanje == 1){

			s1 = "High";
			s2 ="Medium";
			s3 = "Low";
				}
	
	else if(high_score_prozor == 1){
		/*Ako se nalazimo u delu HighScore procitacemo iz datoteke sve najbolje rekorde i ispisati ih*/
		char prvi[15],drugi[15],treci[15];	
		procitaj(prvi,drugi,treci);
		NacrtajHighScore(prvi,drugi,treci);
	
		 	
	


		}

	else if(!high_score_prozor){

		s1 = "New Game";
		s2 ="High Score";
		s3 = "Exit";


		

		}
	if(!high_score_prozor){

		IspisiListu(s1,s2,s3);

	}
}

/*Crtamo prozor u kome mozemo da biramo koju tezinu igre zelimo */
void NacrtajPodesavanje(void){
	/*Crtamo pravougaonik koji predstavlja prozor*/
	glColor3f(0.5,0.5,0.5);
	glPushMatrix();
			
		glRotatef(-20,1,0,0);
		glBegin(GL_QUADS);
			
			glVertex3f(3,2,0);
			glVertex3f(3,-2,0);
			glVertex3f(-3,-2,0);
			glVertex3f(-3,2,0);
		glEnd();

	glPopMatrix();

	


}

/*Crtamo prozor koji ce izaci kada se pritisne 'ESC' i u njemu ce biti ispisane opcije */
void KreirajEscProzor(){

	/*Nacrtamo pravougaonik koji predstavlja prozor*/
	glColor3f(0.5,0.5,0.5);
	
	glPushMatrix();
			
		glRotatef(-20,1,0,0);
		glBegin(GL_QUADS);
			
			glVertex3f(2,1,3);
			glVertex3f(2,-2,3);
			glVertex3f(-2,-2,3);
			glVertex3f(-2,1,3);
		glEnd();

	glPopMatrix();

	char *s1 = "Restart";
	char *s2 = "Load game again";
	char *s3 = "Exit game";

	/*Ispisujemo listu opcija*/

	IspisiListu(s1,s2,s3);
	
}


