#include<stdio.h>
#include "def.h"
#include<string.h>

/*upisujemo u datoteku rezultate igre*/
void upisi(){

	
	FILE *f;
   	char s1[10],s2[10],s3[10];
   	int i1,i2,i3;
  
   	f = fopen("score.txt", "r");
	/* prvo procitamo sve rekorde iz datoteke score.txt */
   	fscanf(f, "%s %d %s %d %s %d", s1,&i1,s2,&i2,s3,&i3);
   
   	fclose(f);

   	f = fopen("score.txt", "w");
	/* u datoteci se nalaze najbolja vremena za koje su zavrsene partije */
   	/*proverimo da li je trenutno vreme bolje od vremena koje je u datoteci, ako je bolje upisujemo to vreme u datoteku */
	if(br_loptica == 3)
  		fprintf(f,"%s %d\n%s %d\n%s %d",s1,vreme>i1?vreme:i1,s2,i2,s3,i3);
	else if(br_loptica == 6)
  		fprintf(f,"%s %d\n%s %d\n%s %d",s1,i1,s2,vreme>i2?vreme:i2,s3,i3);
	else 
		fprintf(f,"%s %d\n%s %d\n%s %d",s1,i1,s2,i2,s3,vreme>i3?vreme:i3);

	
  
 	fclose(f);
		
}

/*citamo sve podatke iz datoteke*/
void procitaj(char s1[],char s2[],char s3[]){
	
	
	FILE *f;
	
	f = fopen("score.txt", "r");
	fscanf(f,"%[^\n] %[^\n] %[^\n]",s1,s2,s3);

	fclose(f);
	
	
		
			
	


}
