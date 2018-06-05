
#include<math.h>
#include<time.h>
#include "def.h"

/*Pokrecemo igru i pokrecemo tajmere za pomeranje loptica i proveru kolizije*/

void Start(){
	
	inicijalizujTeksture(); /*Inicijalizujemo sve potrebno sa crtanje tekstura*/
	pokrenuta_igra = 1;
	if(!pokrenuti_tajmeri && !meni_ispis && !esc_stisnut){
	
		pokrenuti_tajmeri=1;			
		glutTimerFunc(200, tajmer_pomeranje, 0);
		glutTimerFunc(10,tajmer_kolizija,1);
		glutTimerFunc(1000,tajmer_vreme,2);
		glutTimerFunc(2,tajmer_polako_pomeraj,3);
	}
}

/* Postavlja pocetne parametre heroja */
void resetujHeroja(lopta* h){

	h->x_pos = 3;
	h->y_pos=-1.332051 ;
	h->z_pos = 3;
	h->red_poligona = 18;
	h->kolona_poligona = 20;
	h->level = 1;
	h->poluprecnik = 0.2;
	h->boja[0] = 1;
	h->boja[1] = 1;
	h->boja[2] = 0;
	h->krece_se = 1;
	h->pravac = 'w';
	h->sled_pravac = 'n';
	h->odredjen_pravac = 0;
	h->pomerio_levo = 0;
	h->pomerio_desno = 0;
	h->pomerio_gore= 0;
	h->pomerio_dole = 0;

}

/* Restartujemo sve parametre i indikatore na pocetne vrednosti i pokrecemo igru ponovo*/
void pokreni_ponovo(){


	 score [6] = 0 + '0';
	 vreme = 40;
	 preostalo_loptica[13] = br_loptica + '0';
	 nevidljiv = 0;
	 koristio_nevidljivost = 0;
	 kreirani_neprijatelji = 0 ;
	 gotova_igra = 0;
	 pojeo = 0;
	 brojac_za_level = 0;
	 resetujHeroja(&heroj);	
	 Start();

}
/*restartujemo sve parametre na pocetne vrednosti i ucitavamo meni ponovo*/
void restartujIgru(void){

	selektovan = 1;
	start_podesavanje = 0;
	meni_obavestenje = 0 ;
	esc_stisnut = 0;
	br_esc_stisnut = 0;
	meni_ispis = 1;
	pokreni_ponovo();
	glutPostRedisplay();


}
