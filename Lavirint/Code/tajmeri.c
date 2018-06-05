

#include<time.h>
#include "def.h"



/* Tajmer koji ce na svakih 200ms da pomera neprijatelje(loptice) u neku stranu */
void tajmer_pomeranje(int value){


	if( value!= 0 )
		return ;

	PomerajNeprijatelje();

	glutTimerFunc(200, tajmer_pomeranje, 0);

}

/*tajmer koji ce na svakih 2ms da polako pomera pozicije lopti i da ih iscrtava*/
void tajmer_polako_pomeraj(int value){
	
	if(value !=3)
		return;

	int i;
	if(!(gotova_igra || esc_stisnut || !pokrenuta_igra)){
		for(i=0;i<br_loptica;i++){	
			pomeri_loptu( &(neprijatelj[i]) );
			}
		pomeri_loptu( &heroj );

		}
	
	glutTimerFunc(2,tajmer_polako_pomeraj,3);

	


}


/* Tajmer koji ce na svakih 10ms da proverava da li su se mozda dodirnule kuglice*/
void tajmer_kolizija(int value){

	
	
	if( value!= 1 )
		return ;

	ProveriKolizuju(neprijatelj,&heroj);
	glutTimerFunc(10, tajmer_kolizija, 1);
	
}

/*Tajmer koji ce na svakih 1000ms preostalo vreme u igri za 1 sec*/
void tajmer_vreme(int value){

	if(value!= 2)
		return;
	if(!esc_stisnut && pokrenuta_igra)
		promeniVreme(&vreme);
	glutTimerFunc(1000,tajmer_vreme,2);
}

/*Tajmer koji ce nakon odredjenog vremena postaviti vrednosti za nevidljivost*/
void tajmer_nevidljiv(int value){

	if(value!= 2)
		return;

	nevidljiv = 0;
	koristio_nevidljivost = 1;
}


