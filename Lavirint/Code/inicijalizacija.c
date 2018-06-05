#include<GL/glut.h>
#include<stdlib.h>
#include "def.h"
#include "image.h"

/*niz koji sluzi da se kasnije generisu identifikatori tekstura*/
GLuint names[2];

/*Sirina i visina poligona*/
const float poligon_sirina = 7.0;
const float poligon_duzina = 7.0 ;

/*Broj loptica koje ce biti neprijatelji*/
int br_loptica = 0;

/*indikator koji nam govori da li su pokrenuti tajmeri*/
int pokrenuti_tajmeri = 0;

/*indikatori koji nam govore da li su kreirani neprijatelji i heroj*/
int kreirani_neprijatelji = 0 ;
int kreiran_heroj = 0;


/*indikator koji nam govori da li je igra pokrenuta*/
int pokrenuta_igra = 0;

/*indikator koji nam govori da li je igra gotova*/
int gotova_igra = 0;
/*indikator koji nam govori da li smo jos u meniju na pocetku igre*/
int meni_ispis = 1;
/*U ovoj promenljivi cuvacemo informaciju o tome koja nam je trenutno izabrana opcija u meniju*/
int selektovan = 1;
/*indikator koji nam govori da li smo usli u podesavanje za tezinu nivoa*/
int start_podesavanje = 0;
/*indikator koji nam govori da li je otvoren meni prozor u igri(kada pritisnemo esc)*/
int  meni_obavestenje = 0;
/*indikator koji nam govori da li smo otvorili prozor koji nam ispisuje rekorde*/
int high_score_prozor = 0;
/*indikator koji nam govori da li smo pritisnuli esc taster*/
int esc_stisnut = 0;
/*Brojac koji ce brojati koliko smo pita uzastopno stisnuli esc taster*/
int br_esc_stisnut = 0;
/*Brojac kojim cemo brojati broj loptica koje smo pojeli */
int pojeo = 0;
/*brojac koji ce se uvecavati svaki put kada glavna loptica postane vece dimenzije*/
int brojac_za_level = 0;
/*indikator koji nam govori da li je heroj u nevidljivom modu*/
int nevidljiv = 0;
/*indikator na to da li smo vec iskoristili nevidljivost*/
int koristio_nevidljivost = 0;
/*Vreme za koje je predvidjeno da se pojedu sve kuglice na poligonu i pobedi*/
int vreme = 40;
/*String kojim cemo ispisivati preostalo vreme*/
char time_string[]="Time: 40";
/*String koji ce nam sluziti znamo koliko smo pojeli kuglica */
char score[] = "Score:0";
/*/*String koji ce nam sluziti znamo koliko je preostalo jos neprijatelja */
char preostalo_loptica[] = "Enemy number: ";
/* Pravimo loptu kojom cemo upravljati i to ce biti glavna lopta(heroj) */
lopta heroj = {.x_pos = 3, .y_pos = -1.332051  , .z_pos = 3 , .poluprecnik = 0.2 , .red_poligona = 18, .kolona_poligona = 20, .level = 1
		, .boja[0] = 1 , .boja[1] = 1 , .boja[2] = 0 , .heroj = 1 ,  .krece_se = 1 ,  .sled_pravac = 'n', .pravac = 'w'
		, .pomerio_levo = 0 , .pomerio_desno = 0 , .pomerio_gore = 0 , .pomerio_dole = 0 , .korak = 0.02  };

/* deklarisemo niz lopti ,koji ce biti protivnici */
lopta neprijatelj[MAX_NEPRIJATELJA];

/*matrica kojom je opisan poligon , na mestima gde su 1 tu postoji prepreka tj zid*/


int poligon[BROJ_REDOVA_POLIGONA][BROJ_KOLONA_POLIGONA] = { 
	     
			     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			     {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
			     {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
			     {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
		             {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
			     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			     {0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0},
			     {0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0},
			     {0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0},
		             {0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0},
			     {0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0},
			     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			     {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
			     {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
			     {0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0},
			     {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
			     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			   
			};

/* Funkcija kojom postavljamo sve parametre koji su vezani za neprijateljske loptice */
void InicijalizujNeprijatelje(int n,lopta* neprijatelj){

	kreirani_neprijatelji = 1;
	int i;
	
	for(i=0;i<n;i++){


		(neprijatelj+i)->x_pos = -3 ;
		(neprijatelj+i)->y_pos = 1.785641;
		(neprijatelj+i)->z_pos = -2.4;
		if(i>=n/3 && i<(n/3)*2){		/*prva trecina loptica ce biti najveceg poluprecnika i samim tim najjaca od svih*/
			(neprijatelj+i)->poluprecnik = 0.26;
			(neprijatelj+i)->boja[0]=0.7;
			(neprijatelj+i)->boja[1]=0.5;
			(neprijatelj+i)->boja[2]=0.4;
			(neprijatelj+i)->level = 3;
				}
		else if(i >= (n/3)*2){			/*druga trecina bice manje dimenzije poluprecnika od prethodne*/
			(neprijatelj+i)->poluprecnik = 0.23;
			(neprijatelj+i)->boja[0]=0;
			(neprijatelj+i)->boja[1]=1;
			(neprijatelj+i)->boja[2]=1;	
			(neprijatelj+i)->level=2;
			}
		else {					/*jedna trecina ce biti najmanje loptice i one su najmanje snage*/
			(neprijatelj+i)->poluprecnik = 0.2;
			(neprijatelj+i)->boja[0]=0;
			(neprijatelj+i)->boja[1]=1;
			(neprijatelj+i)->boja[2]=0;
			(neprijatelj+i)->level=1;
			}
		
		(neprijatelj+i)->red_poligona = 0;	
		(neprijatelj+i)->kolona_poligona = 0;
		(neprijatelj+i)->aktivna = 1;
		(neprijatelj+i)->heroj = 0;
		(neprijatelj+i)->korak = 0.01;
		(neprijatelj+i)->krece_se = 0;
		(neprijatelj+i)->sled_pravac = 'n';
		(neprijatelj+i)->odredjen_pravac = 0;
		(neprijatelj+i)->pomerio_levo = 0;
		(neprijatelj+i)->pomerio_desno = 0;
		(neprijatelj+i)->pomerio_gore = 0;
		(neprijatelj+i)->pomerio_dole = 0;

		}

}
/*Funkcije koja vrsi inicijalizaciju vezanu za crtanje tekstura*/
void inicijalizujTeksture(void){

	/******************** kod preuzet od asistenta Ivana Cukica ***********************/


    /* Objekat koji predstavlja teskturu ucitanu iz fajla. */
    Image * image;

  
    /* Ukljucuju se teksture. */
    glEnable(GL_TEXTURE_2D);

    /*
     * Podesava se rezim iscrtavanja tekstura tako da boje na teksturi
     * potpuno odredjuju boju objekata.
     */
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

		 
    image = image_init(0, 0);

 

    /* Generisu se identifikatori tekstura. */
    glGenTextures(2, names);


    /* Kreira se tekstura. */
    image_read(image, FILENAME1);

    glBindTexture(GL_TEXTURE_2D, names[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    /* Iskljucujemo aktivnu teksturu */
    glBindTexture(GL_TEXTURE_2D, 0);

    /* Unistava se objekat za citanje tekstura iz fajla. */
    image_done(image);

  
   
}
