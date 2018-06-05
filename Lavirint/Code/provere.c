#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<time.h>
#include "def.h"

/*Funkcija kojom proveravamo da li loptica moze da se pomeri u odredjenu stranu , tj da li udara u prepreku */
int ispravno_kretanje(lopta* loptica,char komanda){
	
	
	int red = loptica->red_poligona;
	int kolona = loptica->kolona_poligona;
	
	/* kada pritisnemo odredjeni taster da bi pomerili loptu moramo prvo proveriti da li je kretanje dozvoljeno ,ako jeste vracamo 1 */
	/* prvo proverimo da li je lopta u poligonu, a zatim proverimo da li ce mozda udariti u zid */
	/* ako kretanje ne moze da se izvrsi onda vratimo 0 */
	if (komanda == 'd'){

		if( kolona +1 <= 20){
	
			if( poligon[red][kolona+1] == 0)
				return 1;
		
			else
				return 0;

				}
		else 
			return 0;

			}

	else if (komanda == 'a'){

		if( kolona - 1 >= 0){
	
			if( poligon[red][kolona-1] == 0)
				return 1;
		
			else
				return 0;

				}
		else 
			return 0;

			}



	else if (komanda == 'w'){

		if( red - 1 >= 0){
	
			if( poligon[red - 1][kolona] == 0)
				return 1;
		
			else
				return 0;

				}

		else 
			return 0;

			}


	else if (komanda == 's'){

		if( red + 1 <= 18){
	
			if( poligon[red+1][kolona] == 0)
				return 1;
		
			else
				return 0;

				}

		else 
			return 0;


			}


	else return 0;
		
	
}

/* Proveravamo da li se dve loptice mozda dodiruju */
int Dodirnute(lopta* neprijatelj,lopta* heroj){
	/*samo kada su loptice za jedan red ili jednu kolonu maksimalno udaljenje jedna od druge proveravamo da li se dodiruju */
	if( ( abs(neprijatelj->kolona_poligona - heroj->kolona_poligona) <= 1 ) &&  ( abs( neprijatelj->red_poligona - 
		heroj->red_poligona) <= 1 )	){

			int x1 = heroj->x_pos;
			int y1 = heroj->y_pos;
			int z1 = heroj->z_pos;


			int x2 = neprijatelj->x_pos;
			int y2 = neprijatelj->x_pos;
			int z2 = neprijatelj->x_pos;
			/*racunamo udaljenost izmedju dve tacke tj izmedju dva centra lopti */
			float razlika = sqrt(  (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2) ) ;
			
			if(razlika < (heroj->poluprecnik + neprijatelj->poluprecnik ))
				return 1; 
			}
			
	
	else
		return 0;
}

/*Ako se loptice mozda dodiruju onda ona sa vecim 'levelom' moze da pojede onu sa manjim 'levelom' */
/*U slucaju da heroj ima veci ili jednak 'level' od ostalih kuglica on ih moze pojesti , u suprotnom druga kuglica moze pojesti heroja*/
void ProveriKolizuju(lopta* neprijatelj,lopta* heroj){


	int i;
	 for(i=0;i<br_loptica;i++){
		if( Dodirnute(neprijatelj+i,heroj) && (neprijatelj+i)->aktivna && !nevidljiv)
			if( (  heroj->level >= (neprijatelj+i)->level ) ){

				(neprijatelj+i)->aktivna = 0;
				++pojeo;
				++brojac_za_level;
				promeniScore();
				promeniEnemyNumber();
				/*ako heroj pojede trecinu loptica uvecace se njegov level i poluprecnik , ali promenice i boju*/
				if(brojac_za_level == (br_loptica/3) ){
					brojac_za_level = 0;
					heroj->level = heroj->level + 1;
					heroj->poluprecnik = heroj->poluprecnik + 0.03;
					heroj->boja[0] = (neprijatelj+i)->boja[0];	
					heroj->boja[1] = (neprijatelj+i)->boja[1];
					heroj->boja[2] = (neprijatelj+i)->boja[2];
					
						}
				
				}	
				else{	/*u slucaju da su loptice dodirnute a heroj je slabija loptica onda zavrsavamo igru*/
				
					gotova_igra=1;
	
				}

			
		}

}
