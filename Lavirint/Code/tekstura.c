
#include<GL/glut.h>
#include "def.h"
#include "image.h"


/*Zadavanje lokacije gde ce se nalaziti tekstura*/
void glQuad(){

		glBegin(GL_QUADS);

      			  glNormal3f(0, 0, 1);

      			  glTexCoord2f(0, 0);
      			  glVertex3f(-6, 0, 0);

     			  glTexCoord2f(12, 0);
       			  glVertex3f(6, 0, 0);

       			  glTexCoord2f(12, 6);
      			  glVertex3f(6, 6, 0);

      			  glTexCoord2f(0, 6);
      			  glVertex3f(-6, 6, 0);
    		glEnd();


}

/*Crta se tekstura koja predstavlja zidove*/
void NacrtajZidove(){

	glBindTexture(GL_TEXTURE_2D, names[1]);

	glPushMatrix();
		
		glTranslatef(0, 0, -3.5);	
		glQuad();

       glPopMatrix();
    
   		
	glPushMatrix();
		glTranslatef(-3.5, 0, 0);
		glRotatef(30,1,0,0);
		glRotatef(90,0,1,0);
		glQuad();

       glPopMatrix();
    
   		
	
	glPushMatrix();
		glTranslatef(3.5, 0, 0);
		glRotatef(30,1,0,0);
		glRotatef(90,0,1,0);
		glQuad();

       glPopMatrix();
    


	glPushMatrix();
		glRotatef(90,1,0,0);
		glTranslatef(0, 0, 3.5);
		glQuad();

       glPopMatrix();

  
       



}
/*Crtamo zidove koji su tekstura*/
void NacrtajTeksturu(){
	

	NacrtajZidove();
	

	glBindTexture(GL_TEXTURE_2D, 0);
	
}




