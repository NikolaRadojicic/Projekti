#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<time.h>
#include "def.h"

/*Ova funkcija ce omoguciti da se loptice pomeraju na poligonu u pravcu koji je prethodno zadat */
void pomeri_loptu(lopta *l){
		
		
		/*Ako nam sledeci pravac nije nepoznat ('n') i ako je moguce pomeriti se u tom pravcu onda pravac postaje sledeci pravac*/
		/*l->pomerio_desno == 0  && l->pomerio_levo == 0 .... znaci da nismo u nekoj medju poziciji izmedju dva reda ili dve kolone
		u poligonu kada bi se mozda desilo da bi udarali u neku prepreku , jer nam od reda i kolone u kojoj se nalazimo zavisi da li
			mozemo skrenuti u neku stranu pravilno */

		if(l->sled_pravac!='n' && ispravno_kretanje(l,l->sled_pravac) && l->pomerio_desno == 0 && l->pomerio_levo == 0
			&& l->pomerio_gore == 0 && l->pomerio_dole == 0)
					l->pravac = l->sled_pravac;
		
		/*Ako se loptica krece i ispravno je kretanje u smislu da nemamo ispred sebe na tom pravcu prepreku onda se pomeramo u tom 			pravcu */

		if( l->krece_se && ispravno_kretanje(l,l->pravac)){
			/*u zavisnosti od pravca kretanja menjamo vrednosti pozicija loptice*/
			if(l->pravac == 'w'){
				l->z_pos =(l->z_pos) - l->korak;
				l->y_pos = (-1)* (l->z_pos ) *1.0/sqrt(3) + (l->poluprecnik);
				l->pomerio_gore+= l->korak;
				glutPostRedisplay();
				}
			if(l->pravac == 's'){
				
				l->z_pos =(l->z_pos) + l->korak;
				l->y_pos = (-1)* (l->z_pos ) *1.0/sqrt(3) + (l->poluprecnik);
				l->pomerio_dole+= l->korak;
				glutPostRedisplay();
				}
			if(l->pravac == 'a'){
				l->x_pos = l->x_pos - l->korak;
				l->pomerio_levo+= l->korak;
				glutPostRedisplay();
				}
			if(l->pravac == 'd'){
				l->x_pos = l->x_pos + l->korak;
				l->pomerio_desno+= l->korak;
				glutPostRedisplay();
				}
			 

			}
			/*l->pomerio_gore, l->pomerio_dole ...  nam govori koliko smo se pomerili u neku stranu, ako se pomerimo u neku stranu 				priblizno oko 0.3 , tada cemo promeniti broj reda ili kolone, i vratiti brojace ponovo na 0  */
			if(l->pomerio_gore >= 0.298 && l->pomerio_gore <=0.3 ){
			
				l->red_poligona--;
				l->pomerio_gore = 0;
				
				}
			if(l->pomerio_dole >= 0.298 && l->pomerio_dole <=0.3 ){
			
				l->red_poligona++;
				l->pomerio_dole = 0;
			
				}
			if(l->pomerio_levo >= 0.298 && l->pomerio_levo <=0.3 ){
			
				l->kolona_poligona--;
				l->pomerio_levo = 0;
				
				}
			if(l->pomerio_desno >= 0.298 && l->pomerio_desno <=0.3 ){
			
				l->kolona_poligona++;
				l->pomerio_desno = 0;
				
				}
			
				
	
}


/* U zavisnosi od pritisnutog tastera postavljamo pravac loptice */
void postavi_pravac(char c,lopta* loptica){
	
			
			
				/*u svakom trenutku imacemo pravac kretanja i sledeci pravac kretanja */
				
				loptica->sled_pravac = c;
				loptica->krece_se = 1;


		
}




/* Slucajnim izborom bira se jedna od moguce 4 strane kretanje, i loptice se pomeraju u zavisnosti od izabrane strane*/
/* Ovu funkciju ce pozivati tajmer nakon nekog vremena */
void PomerajNeprijatelje(void){

	if(pokrenuta_igra){

		srand( time(NULL));
	
		int i;
		/*Sve loptice se pomeraju u neku stranu*/
		for(i=0;i<br_loptica;i++){
	
			int r = rand()%4;	/* generise se broj izmedju 0 i 3 */
		
			switch(r){
				/*svakom broju je dodeljena neka strana kretanja */
			case 0 : 
			
				if(ispravno_kretanje(&neprijatelj[i],'a')){
					postavi_pravac('a',&(neprijatelj[i]));
						}
				break;


			case 1 : 
			
				if(ispravno_kretanje(&neprijatelj[i],'w')){
						postavi_pravac('w',&(neprijatelj[i]));
						}
				break;



			case 2 : 
			
				if(ispravno_kretanje(&neprijatelj[i],'d')){
						postavi_pravac('d',&(neprijatelj[i]));
						}
				break;


			case 3 : 
			
				if(ispravno_kretanje(&neprijatelj[i],'s')){
						postavi_pravac('s',&(neprijatelj[i]));
						}
				break;

	
				}
	
		}

	}

}


void ukljuciNevidljivost(void){
	/*ulazimo u nevidljiv mod koji traje 2 sekunde */
	nevidljiv = 1;
	glutTimerFunc(2000,tajmer_nevidljiv,2);

}
