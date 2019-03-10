/*goulias ioannhs 1785 gkourmpatshs nikolaos 1791*/

/*to sigkekrimeno programma analambanei na diabasei mia seira apo biblia , mia seira apo xrhstes , tis ba8mologies tous ka8ws kai na entopisei enan sigkekrimeno agorasth.
 * Skopos t einai na proteinei ola ta  biblia ston agorasth simfwna me ton  megalitero ba8mo omoiothtas pou o idios exei me enan xrhsth*/




#include <stdio.h>
#include <string.h>
#define line_books 60 /*dhlwsh kai arxikopoihsh twn diaforwn diastasewn twn pinakwn pou xrisimopoiountai*/
#define column_books 121
#define line_user 100
#define column_user 21
#define line_grades 100
#define column_grades 60

char available_books [line_books] [column_books];  /*dhlwsh pinaka bibliwn*/
char users [line_user] [column_user]; /*dhlwsh pinaka xrhstwn*/
int grades [line_grades] [column_grades];/*dhlwsh pinaka ba8mwn*/
char formatstring [10];
int number_info_books(); /*dhlwsh sunarthshs pou entopizei ton sinoliko ari8mo bibliwn pou dinontai kai ta kataxwrei ston pinaka bibliwn*/
int scan_users_grades (int number_of_books); /*dhlwsh sunarthshs pou kataxwrei tou xrhstes kai tous ba8mous tous pairnontas os metablhth ton ari8mo twn bibliwn*/
int spec_user (int w); /*dhlwsh sunarthshs pou pairnei os eisodo to plh8os ton xrhstwn kai entopizei ton agorasth*/
int similarity_grade_user (int w,int k,int number_of_books); /*dhlwsh sunarthshs pou pairnei os isodo to plh8os ton xrhstwn ton agorasth kai ton ari8mo bibliwn kai upologizei ton megisto ba8mo omoiothtas me ton agorasth kai ton xrhsth me ton megisto ba8mo omiothtas*/
void recommendations(int maxline,int k,int number_of_books); /*dhlwsh sunarthshs pou pairnei os isodo tin timh ths  8eshs t xrhsth me ton megisto ba8mo omiothtas ton agorasth kai ton ari8mo bibliwn kai tipwnei ta protinomena biblia*/

int main (int argc, char* argv []) {
	 int number_of_books = 0, w = 0, k = -1, maxline = 0; /*dhlwsh k arxikopoihsh metablitwn stin main pou xreiazontai gia tin ilopoihsh twn sunarthsewn*/
	
	number_of_books = number_info_books (); /*o ari8mos ton bibliwn ginetai isoutai me oti epistrepsei i number_info_books meta tin ektelesi ths*/
	w = scan_users_grades (number_of_books); /*o ari8mos twn xrhstwn isoutai me oti epistrepsei i scan_users_grades meta tin ektelesi tis*/
	do { 
		k = spec_user(w); /*to k dhladh i 8esh t agorasth isoutai me tin timh pou 8a epistrepsei i spec_user meta tin ektelesi tis kai epanalambanetai eos otou to k pou 8a epistrepsei na einai egkuro*/ 
	} while (k == -1);
	maxline = similarity_grade_user(w, k ,number_of_books); /*i 8esh t xrhsth me ton megalutero ba8mo omiothtas me ton agorasth isoutai me oti epistrepsei i similarity_grade_user meta tin ektelesi ths*/
	recommendations (maxline,k,number_of_books); /*ektelesh ths sinartisis recommendations*/
	
	return(0);
}


int number_info_books () { /*tupos ths number_info_books*/
	int i, number_of_books = 0; /*dhlwsh k arxikopoihsh metablhtwn*/
	
		scanf(" %d", &number_of_books);
		
		while (number_of_books < 1 || number_of_books > 60) { /*an o ari8mos bibliwn den einai egkuros epanalambanetai i anagnwsh t ari8mou bibliwn*/
			printf("wrong number of books, enter again:\n");
			scanf(" %d", &number_of_books);
		}
		
		for (i = 0;  i < number_of_books; i++) { /*kataxwrhsh twn bibliwn ston antistixo pinaka*/
			sprintf(formatstring, "%%%ds" , column_books - 1);
			scanf(formatstring, &available_books[i]); 
		}
		
	return (number_of_books); /*epistrofh ths timhs t ari8mou twn bibliwn*/
}




int scan_users_grades(int number_of_books) { /*tupos ths scan_users_grades*/
	int i, j, w = 0; /*dhlwsh k arxikopoihsh metablhtwn*/
	char str1 []= "EndOfNames";/*dhlwsh string EndOfNames*/
	i = -1;
	
	while (i < line_user) { /*gia oso to i einai mikrotero twn xrhstwn*/
		i++;
		sprintf(formatstring, "%%%ds" ,column_user - 1);
		scanf(formatstring, &users [i]);
		
		if (strcmp(str1,users[i]) == 0) { /*an to users[i] dhladh to teleutaio onoma xrhsth pou diabasthke tautizetai me to EndOfNames tote to w ginetai to plh8os twn xrhstwn pou diabastikan kai stamataei h while*/
			w = i;
			break;
		}
		
		for (j = 0; j < number_of_books; j++) { /*gia to plh8os twn bibliwn t pinaka ginetai i katagrafi kai kataxwrhsh twn ba8mologiwn ston pinaka ba8mologiwn*/
			scanf(" %d", &grades[i][j]);
		}
	}
	
	return(w); /*epistrofh ths timhs tou sinolou twn xrhstwn*/
}




int spec_user(int w) { /*tupos ths spec_user*/
	int k, i; /*dhlwsh k arxikopoihsh metablhtwn*/
	char client [21]; /*string gia ton agorasth*/
	k = -1;
	
	do { 
		printf("Hi, what's your name? ");
		scanf("%20s", client); /*diabazei to onoma t agorasth*/
		printf("\nHello %s!\n", client);
		
		for (i = 0; i < line_user; i++) { /*anazhtei sto sunolo twn xrhstwn pou do8hkan parapanw to onoma t agorasth an to brei bgainei apo tin epanalipsi kai orizei to k ws th 8esh t agorasth ston pinaka xrhstwn*/
			if(strcmp(client,users[i]) == 0) {
				k = i;
				break;
			}
		}
			
		if (k == -1) printf("No such user\n"); /*an dn do8ei egkuro onoma agorasth tote tuponetai No such user kai epanalambanontai ta parapanw*/
	} while (k == -1);
	
	printf("\nUser #%d\n", k); /*an dw8ei egkuro onoma tupwnetai User k h 8esh t agorasth ston pinaka xrhstwn*/
	return(k);/*epistrefei tin timh ths  8eshs t agorasth ston pinaka xrhstwn*/
}

int similarity_grade_user (int w,int k,int number_of_books) { /*tupos ths similarity_grade_user*/
int i, j, sum, max, maxline; /*dhlwsh k arxikopoihsh metablhtwn*/
	max = -9999999;
	maxline = -1;
	
	for (i = 0; i < w; i++) { /*gia to sinolo twn xrhstwn t pinaka*/
		if (users[i] != users[k]) { /*gia tous xrhstes pou dn exoun to idio onoma me ton agorasth*/
			sum = 0;
			
		for (j = 0; j < number_of_books; j++) { /*upologismos tou ba8mou omoiothtas gia to sinolo twn bibliwn*/
			sum = sum +  grades[k][j] * grades[i][j];
		}
						
		if (sum > max) { /*an i nea timh tou ba8mou omiothtas einai megaliteri tou teleutaiou megaluterou ba8mou omiothtas tote t max pairnei tin timh t neou megistou ba8mou omoiothtas*/
			max = sum;
			maxline = i; /*orizetai i 8esh t xrhsth me ton megisto ba8mo omiothtas me ton agorasth*/
		}
			
		}
	}
	printf("\n%s %d\n",users[maxline], max); /*tuponetai i timh ths 8eshs ston pinaka xrhstwn t xrhsth me ton megisto ba8mo omiothtas kai o megistos ba8mos omiothtas*/
	return (maxline); /*epistrofh ths timhs ths 8eshs t xrhsth me ton megalitero ba8mo omoiothtas me ton agorasth*/
}


void recommendations(int maxline,int k,int number_of_books) { /*tupos recommendations*/
	char recommended_books [number_of_books] [column_books]; /*dhlwsh pinaka twn proteinomenwn bibliwn*/
	int i = 0, j, u; /*dhlwsh kai arxikopoihsh metablitwn*/
	
	for (j = 0; j < number_of_books; j++) { /*gia to plh8os twn bibliwn*/
		if (grades[maxline][j] > 0 && grades[k][j] == 0) { /*gia t biblia p o ba8mos t xrhsth me ton megalutero ba8mo omoiothtas me ton agorasth einai megaliteros apo 0 kai dn ta exei diabasei o agorasths (==0) */
			strcpy (recommended_books [i], available_books [j]); /*kataxwrhsh ston pinaka proteinomenwn bibliwn ta biblia pou plhroun tis parapanw proupo8eseis*/
			i++;
		}
	}
	
	if (i == 0) { /*an dn bre8oun biblia pou na plhroun ta parapanw tiponetai sorry no recommendations*/
		printf("\nSorry, no recommendations!\n");
	}
	
	else {  /*alliws tiponetai we recommend kai o pinakas twn proteinomenwn bibliwn*/
		printf("\nWe recommend:");
		for (u = 0; u < i;  u++) {
			printf ("\n\t %s",recommended_books [u]);
		}
	}
	
}
	