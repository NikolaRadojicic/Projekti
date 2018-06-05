#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include "def.h"
#include "image.h"

/* Funkcija kojom kazemo sta se desava kada se promeni velicina prozora */
void on_reshape(int width,int height){
	
	/* Postavlja se viewport */
	glViewport(0, 0, width, height);

	/* Postavljaju se parametri projekcije */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float)width / height, 1 ,1500);


}

/*Funkcija sa kojom cemo crtati po ekranu*/

void on_display(void){

	/* Brisemo sve u baferima i postavljamo novu pozadinu */		
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	/* Postavlja se vidna tacka */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0,2.5,8.65,0,0,0,0,1,0);
	
	
	/*Ako je vrednost meni_ispis = 1 to nam je znak da treba da nacrtamo meni , to se obicno odma desava na pocetku igre*/
	if(meni_ispis == 1)
		NacrtajMeni();	
	else 
		Start();		/*Inace cemo pokrenuti igru jer meni nije aktivan */
	
	if(pokrenuta_igra && !meni_ispis){	/*Ukoliko je igra pokrenuta i nismo otvorili meni crtacemo sve */
		
		NacrtajTeksturu();
		NacrtajPoligon();	
		kreirajLoptice();
		
			
		if(gotova_igra || pojeo == br_loptica ){	/*Ako je igra gotova ili smo pojeli sve loptice kreiracemo obavestenje o tome*/
			
			if(pojeo == br_loptica)
				upisi();

			KreirajObavestenje();
							
				}

		if(vreme == 0){	
					/*Ako nam je isteklo vreme onda zavrsavamo igru i ispisujemo obavestenje*/
			KreirajObavestenje();		
			gotova_igra = 1;
	
				}

		IspisiPodatke(score,preostalo_loptica);	/*Svakako treba ispisati podatke o igri*/

		if( esc_stisnut){	/*Ako stisnemo 'ESC' taster kreiracemo prozor sa opcijama  i pauziracemo igru */
			
			KreirajEscProzor();
			pokrenuta_igra = 0;	
		}	
		
			}

	glutSwapBuffers();	/*Menjamo bafere*/
}


/* Funkcija gde cemo definisati sta se desi kada se pritisne neki taster */
void on_keyboard(unsigned char key, int x, int y){
	
	if(meni_ispis){ /*Ukoliko je meni_ispis = 1 to nam je znak da treba da crtamo prozor menija i da smo trenutno u meniju*/
		
		if(!high_score_prozor){
		/*Ako pritisnemo taster 's' ili 'w' menjacemo opciju koja je selektovana */
			if( (key == 's') && (selektovan <= 2 ) ){	

				++selektovan;
				glutPostRedisplay();

				}
			else if( (key == 'w') && (selektovan >= 2)) {
	
				--selektovan;
				glutPostRedisplay();
				}

			}
	/*Ako nismo u podesavanju igre ili HighScoru i ako je selektovana prva opcija to je znak da smo pritisnuli 'New Game' */
	/*ulazimo u mod podesavanja*/
		if (start_podesavanje == 0 && !high_score_prozor && selektovan == 1 && key == 13){
			start_podesavanje = 1;
			glutPostRedisplay();
				}
		/*Inace sve isto samo je selektovana druga opcija 'HighScore' i ulazimo u mod za ispis rekorda*/
		else if (start_podesavanje == 0 && selektovan == 2 && key == 13){
			high_score_prozor = 1;
			glutPostRedisplay();
				}
		/*Inace znaci da smo selektovali Exit i izlazimo iz igre */
		else if (start_podesavanje == 0 && selektovan == 3 && key == 13){
			exit(1);
			
				}
		/*Ako smo u podesavasavanju tezine nivoa i stisnemo ESC inda se vracamo nazad ponovo na pocetak menija*/
		else if(start_podesavanje == 1 && key == 27){
			
			start_podesavanje = 0;
			glutPostRedisplay();
				}
		/*Ako smo u podesavanju za tezine nivoa i selektujemo neku opciju od moguce tri zavrsavamo sa delom za meni i pocinjemo igru*/
		/*Tezina igre odredjena je brojem neprijateljskih loptica*/

		else if(start_podesavanje == 1 && selektovan == 1 && key == 13 ){
			br_loptica = 9;
			meni_ispis = 0;
		
			glutPostRedisplay();
				}
		else if(start_podesavanje == 1 && selektovan == 2 && key == 13 ){
			br_loptica = 6;
			meni_ispis = 0;
		
			glutPostRedisplay();
				}	

		else if(start_podesavanje == 1 && selektovan == 3 && key == 13 ){
			br_loptica = 3;
			meni_ispis = 0;
		
			glutPostRedisplay();
				}	
		
		/*Ako je otvoren prozor za ispis rekorda i stisnemo ESC vraticemo se nazad u glavni meni*/
		if(high_score_prozor == 1 && key == 27){

			high_score_prozor = 0;
			glutPostRedisplay();
				}
		
			
		}
	/*Samo ako je pokrenuta igra i pritisnemo ESC onda smo postavili esc_stisnut na 1 , to ce biti znak da treba da se nacrta esc prozor*/
	else if(pokrenuta_igra){

		if(key == 27){
			esc_stisnut = 1;
			glutPostRedisplay();	

			}


		}

	
	if(esc_stisnut ){

		if(key == 27)
			br_esc_stisnut++;
		
		if(br_esc_stisnut == 2 ){	/*Ukoliko drugi put pritisnemo ESC zatvoricemo esc prozor*/

			esc_stisnut = 0 ;
			br_esc_stisnut = 0;	 
			glutPostRedisplay();
				}

		if( (key == 's') && (selektovan <= 2 ) ){	/*Inace mozemo da biramo odgovarajucu opciju u esc prozoru sa 'w' i 's' */

			++selektovan;
			glutPostRedisplay();

				}
		else if( (key == 'w') && (selektovan >= 2)) {

			--selektovan;
			glutPostRedisplay();

				}


	}
	/*Ako je esc prozor aktivan i ako pritisnemo enter, u zavisnoti od toga koja je opcija selektovana izvrsicemo neke operacije*/
	/*Ponovicemo ponovo partiju, pokrenucemo ponovo igru iz pocetka , ili cemo izaci iz igre */
	if(esc_stisnut && key == 13){

		if(selektovan == 2){
			
			restartujIgru();
			
			
			}

		else if(selektovan == 1){

			esc_stisnut = 0;
			br_esc_stisnut = 0;
			pokreni_ponovo();

			}

		else exit(1);

		}

		

	
		
		
	/*Ako je igra nije pokrenuta i ako nije aktivan esc_prozor , kada pritisnemo 'n' , partija ce se restartovati*/
	if(key == 'n' && !pokrenuta_igra && !esc_stisnut ) pokreni_ponovo();
	
	/*ako pritisnemo taster 'p' igra ce se zaustaviti dok ponovo ne stisnemo 'p' */
	if(key == 'p' && !gotova_igra && !esc_stisnut){
	
		if(pokrenuta_igra == 0)
			pokrenuta_igra = 1;
		else
			pokrenuta_igra = 0;
	
			
		
			}
	
	/*Ako je igra pokrenuta moguce je upravljati  sa glavnom loptom*/
	if(pokrenuta_igra){

		switch(key){


			/*Kada se pritisne neki od tastera w,a,s,d dodeljujemo pravac lopti*/
			
			
			
			case 'q': exit(1);
			
			case 32 :	if(!koristio_nevidljivost)  /*ukoliko stisnemo SPACE ucicemo u nevidljivi mod*/
						ukljuciNevidljivost();break;
				
			case 'a': 
					postavi_pravac('a',&heroj);break;
							
			case 'd': 
					postavi_pravac('d',&heroj);break;
		
			case 'w': 
					postavi_pravac('w',&heroj);break;
							
			
			case 's': 
					postavi_pravac('s',&heroj);break;
			
			}

	}
		

}



