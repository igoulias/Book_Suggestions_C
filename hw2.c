/*goulias ioannhs 1785 gkourmpatshs nikolaos 1791*/

/*to sigkekrimeno programma analambanei na diabasei mia seira apo biblia , mia seira apo xrhstes , tis ba8mologies tous ka8ws kai na entopisei enan sigkekrimeno agorasth.
 * Skopos t einai na proteinei ena sigkekrimeno biblio ston agorasth simfwna me ton megalitero ba8mo omoiothtas pou o idios exxei me enan xrhsth*/



#include <stdio.h>
#include <string.h>
#define line_books 60 /*dhlwsh kai arxikopoihsh twn diaforwn diastasewn twn pinakwn pou xrisimopoiountai*/
#define column_books 121
#define line_user 100
#define column_user 21
#define line_grades 100
#define column_grades 60

int main (int argc , char* argv []) {
	char formatstring [10]; /*dhlwsh metablhtwn k arxikopoihsh*/
	int i, j, k, max = -1, sum, maxline, w = 0 ;
	char available_books [line_books] [column_books]; /*dhlwsh pinaka bibliwn*/
	char users [line_user] [column_user]; /*dhlwsh pinaka xrhstwn*/
	int grades [line_grades] [column_grades]; /*dhlwsh pinaka ba8mwn*/
	char str1 []= "EndOfNames";
	int number_of_books = 0;
	char client[21];
	
	scanf(" %d", &number_of_books); /*kataxwrhsh ari8mou bibliwn*/
	while (number_of_books < 1 || number_of_books > 60) { /*an o ari8mos bibliwn dn einai egkuros epanalambanetai i kataxwrhsh*/
		printf("wrong number of books, enter again:\n");
		scanf(" %d", &number_of_books);
	}
	
	for (i = 0;  i < number_of_books; i++) { /*kataxwrhsh twn sinolikwn bibliwn ston pinaka bibliwn*/
		sprintf(formatstring, "%%%ds" , column_books - 1);
		scanf(formatstring, &available_books[i]); 
	}
	
	i = -1;
	while (i < line_user) { /*kataxwrhsh twn diaforwn xrhstwn ston pinaka xrhstwn*/
		i++;
		sprintf(formatstring, "%%%ds" ,column_user - 1);
		scanf(formatstring, &users [i]);
		
		if (strcmp(str1,users[i]) == 0) { /*an do8ei to EndOfNames tote termatizetai i kataxwrhsh*/
			w = i; /*entopizetai i 8esh t teleutaiou xrhsth*/
			break;
		}
		
		for (j = 0; j < number_of_books; j++) { /*kataxwrhsh twn diaforwn ba8mwn k katagrafi tous ston sxetiko pinaka*/
			scanf(" %d", &grades[i][j]);
		}
	}
	k = -1;
	do {
		printf("Hi, what's your name? "); /*entopismos tou agorasth*/
		scanf("%20s",client);
		printf("\nHello %s!\n", client);
	
		for (i = 0; i < line_user; i++) {
			if(strcmp(client,users[i]) == 0) { /*entopizetai an o agorasths iparxei ston pinaka xrhstwn*/
				k = i; /*an nai to programma bgainei apo tin anazitisi kai sinexizei parakatw*/
				break;
			}
		}
		if (k == -1) printf("\nNo such user!\n"); /*an oxi tote tiponetai no such user kai epanalambanetai i parapanw diadikasia*/
	} while (k == -1);
	printf("\nUser #%d\n", k); /*otan do8ei egkuro onoma agorasth tiponetai i 8esh t ston pinaka xrhstwn*/
	
	max = -9999999;
	maxline = -1;
	for (i = 0; i < w; i++) { /*gia ton sinolo ton xrhstwn pou exoun dw8ei*/
		if (users[i] != users[k]) { /*ean to onoma t agorasth dn tautizetai me kapoio onoma xrhsth t pinaka tote ektelountai ta parakatw*/
			sum = 0;
			
			
			for (j = 0; j < number_of_books; j++) { 
				sum = sum +  grades[k][j] * grades[i][j]; /*upologismos eswterikou ginomenou twn ba8mwn twn diaforwn xrhstwn kai tou agorasth*/
			}
			
						
			if (sum > max) { /*an o neos ba8mos omoiothtas einai megaliteros t paliou tote o palios ginetai neos kai katagrafetai i 8esh ston pinaka t xrhsth me ton megalitero ba8mo omoiothtas*/
				max = sum;
				maxline = i;
			}
						
			
		}
	}
	printf("\n%s %d\n",users[maxline], max); /*tiponetai h 8esh t xrhsth me ton megalitero ba8mo omoiothtas ka8ws kai o ba8mos omoiothtas*/
	
	for (j = 0; j < number_of_books; j++) { /*gia to sinolo twn bibliwn pou uparxoun ston pinaka*/
		if (grades[maxline][j] > 0 && grades[k][j] == 0) { /*otan o ba8mos aksiologisis enos bibliou t xrhsth me ton megalitero ba8mo omoiothtas einai >0 kai otan o agorasths dn exei diabasei to sigkekrimeno biblio (==0) tote tuponetai We recommend kai to 1o biblio pou 8a plhrei ta prohgoumena*/
			printf("\nWe recommend: %s", available_books[j]);
			break;
		}
		if (j == number_of_books - 1) { /*an dn bre8oun biblia pou na plhroun ta parapanw tiponetai Sorry no recommendations*/
			printf("\nSorry, no recommendations!\n");
		}
	}
		
	return(0);
	}