#ifndef DEF_H_
#define DEF_H_

#include<GL/glut.h>

#define MAX_NEPRIJATELJA 9
#define BROJ_REDOVA_POLIGONA 20
#define BROJ_KOLONA_POLIGONA 21
#define FILENAME1 "wall.bmp"


extern const float poligon_sirina ;
extern const float poligon_duzina ;
extern int br_loptica;	
extern int pokrenuti_tajmeri;
extern int kreirani_neprijatelji ;
extern int kreiran_heroj ;
extern int pokrenuta_igra;
extern int gotova_igra ;
extern int pojeo;
extern int brojac_za_level;
extern char score[];
extern char preostalo_loptica[];
extern int vreme ;
extern char time_string[];
extern int nevidljiv;
extern int koristio_nevidljivost;
extern int meni_ispis;
extern int selektovan;
extern int start_podesavanje;
extern int meni_obavestenje ;
extern int high_score_prozor;
extern int esc_stisnut;
extern int br_esc_stisnut;
extern int poligon[BROJ_REDOVA_POLIGONA][BROJ_KOLONA_POLIGONA];
extern GLuint names[2];


/*Glavna stuktura kojom opisujemo svaku lopticu u igri*/
typedef struct LOPTA{
	
	float poluprecnik;
	float x_pos;
	float y_pos;
	float z_pos;	
	
	int red_poligona;
	int kolona_poligona;
	
	int aktivna ;	/*Ova promenljiva ako ima vrednost 1, znaci da treba da se crta loptica, inace ima stanje 0*/

	float boja[3];	/*Niz u kome cemo cuvati boju*/

	int level;	/*Ova promeljiva govorice nam kolika je snaga loptice*/

	int heroj ;	/*Ako je vrednost ove promenljive 1 onda je to znak da je loptica 'heroj' , inace ima vrednost 0 */

	float krece_se ;	/*ako je 0 loptica je u mestu ili  1  ako se krece*/

	char pravac ;	/*postojace pravci w,a,s,d  */
	char sled_pravac;	/*govorice nam koji ce biti sledeci pravac, tj ako nemozemo da promenimo pravac odmah ,menjamo ga kasnije*/
				/*jel desavace se da zelimo da promenimo pravac a udaramo u prepreku ,pa ce se pravac promeniti kasnije*/

	/*ovde cemo cuvati vrednosti pomeraja za svaku stranu , cim bude vrednost 0.3 onda cemo promeniti red ili kolonu date loptice*/
	float pomerio_gore;	
	float pomerio_dole;
	float pomerio_levo;
	float pomerio_desno; 
	int odredjen_pravac;	/*indikator koji nam kazuje da li smo odredili pravac kretanja*/
	float korak ;	/*korak za koji cemo pomerati lopticu u neku stranu kada tajmer pozove da se ona pomeri*/
}lopta;


extern lopta heroj ;
extern lopta neprijatelj[MAX_NEPRIJATELJA];

void on_reshape(int width,int height);	/*Funckija koja nam govori sta se desaca kada se promene dimenzije prozora*/
void on_display(void);			/*Funkcija kojom odredjujemo sta ce se crtati*/
void on_keyboard(unsigned char key, int x, int y);/*Funkcija kojom opisujemo sta se desi kada se pritisne neki taster*/
void NacrtajLopticu(lopta* loptica);	/*Funkcija kojom crtamo svaku lopticu na poligonu*/
void NacrtajPoligon(void);		/*Funkcija kojom crtamo sav poligon igre*/
void kreirajLoptice(void);		/*Funkcija kojom kreiramo sve loptice u poligonu*/
void IspisiGameOver(void);		/*Ovom funkcijom cemo ispisati poruku 'Game Over' u slucaju poraza */
void promeniScore();			/*Funkcija koja ce promeniti 'Score' svaki put kada se pojede loptica*/
void IspisiSkor(const char *s);		/*Funkcija kojom trenutni 'Score'*/
void IspisiWin(void);			/*Funcija kojom cemo ispisati poruku 'You are Winnner' u slucaju pobede*/
void postavi_pravac(char c,lopta* loptica); /*Funkcija koja ce menjati pravac svake loptice na poligonu */
void PomerajNeprijatelje(void);	/*Funkcija kojom cemo pomerati sve protivnicke loptice na poligonu*/
int ispravno_kretanje(lopta* loptica,char komanda); /*Ovom funkcijom proveravamo da li je moguce pomeriti lopticu u neku stranu */
int Dodirnute(lopta* neprijatelj,lopta* heroj); /*Ovom funkcijom cemo proveravati da li se dve loptice dodiruju*/
void ProveriKolizuju(lopta* neprijatelj,lopta* heroj); /*Proveravamo da li su dve loptice u mogucoj koliziji*/
void Start();	/* Funkcija kojom pokrecemo igru */
void resetujHeroja(lopta* h);	/* Funkcija kojom postavljamo ponovo pocetne vrednosti koje treba da ima heroj  */
void pokreni_ponovo();  /*Ovom funkcijom cemo restartovati sve brojace,indikatore i parametre igre na pocetnu vrednost*/
void tajmer_kolizija(int value); /*Tajmer koji cemo koristiti za proveru kolizije*/
void tajmer_pomeranje(int value); /*Tajmer koji cemo koristiti da bi pomerali loptice po poligonu */
void inicijalizujTeksture(void);	/* Funkcija kojom inicijalizujemo sve potrebno za rad sa teksturama */
void KreirajObavestenje(void);	/*Funkcija kojom cemo ispisati na ekran odredjeno obavestenje */
void tajmer_vreme(int value);	/*Tajmer koji ce nam menjati vreme koje je preostalo u igri*/
void promeniVreme(int* v);	/*Funkcija koja menja vreme koje se ispisuje */
void tajmer_nevidljiv(int value); /*Tajmer koji ce nam sluziti odredimo vreme za koje ce heroj biti nevidljiv*/
void NacrtajMeni(void);	/*Funkcija koja ce crtati prozor koji ce predstavljati meni*/
void NacrtajPodesavanje(void);	/*Funkcija koja ce crtati prozor koji ce predstavljati podesavanje igre*/
void upisi(void);	/*Funkcija kojom cemo upisati vreme za koje smo pobedili u datoteku u kojoj cuvamo rekorde */
void NacrtajHighScore(char s1[],char s2[],char s3[]);	/*Crtamo prozor u kome ce biti ispisana najbolja vremena za svaki nivo tezine*/
void KreirajEscProzor(); /*Funkcija koja ce crtati prozor kada se pritisne taster 'ESC' */
void IspisiListu();	/*Ispisuje se lista sa opcijama*/
void restartujIgru(); /*Restartujumo igru ponovo tako sto postavimo se brojace i indikatore na pocetne vrednosti*/	
void pomeri_loptu(lopta* l);/*Ova funkcija ce omoguciti da se loptice pomeraju na poligonu u pravcu koji je prethodno zadat */
void tajmer_polako_pomeraj(int value); /*tajmer koji ce na svakih 2ms da polako pomera pozicije lopti i da ih iscrtava*/

#endif
