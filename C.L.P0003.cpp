#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
void spinning(int num[]){
	int i;
    for(i = 0; i < 3; i++)
        num[i] = rand() % 10;
}
int isLucky(int luckyNum[]){
	if(luckyNum[0] == luckyNum[1] && luckyNum[0] == luckyNum[2]){
		return 3;
    }
	else if(luckyNum[0] == luckyNum[1] || luckyNum[1] == luckyNum[2] || luckyNum[0] == luckyNum[2]){
		return 2;
	}
	else
		return 1;
}
void shows(int num[]){
    int i;
    printf("The slot machine shows ");
    for(i = 0; i < 3; i++)
        printf("%d", num[i]);
    printf(" .\n");
}
int intInput(int min, int max){
	int i, output, check;
	char ch;
	while(1){
		check = scanf("%d%c", &output, &ch);
		fflush(stdin);
		if(check != 2 || ch != 10)
			printf("Wrong input!\nTry again: ");
		else if(output < min || output > max)
			printf("Outrange input!(%d-%d)\nTry again: ",min,max);
		else return output;
	}
}
void menu(float budget){
    printf("\nYou have $%g\n", budget);
    printf("Choose one of the following menu options:\n");
    printf("1. Play the Slot machine.\n");
    printf("2. Save game.\n");
    printf("3. Put Monney.\n");
    printf("4. Cash out.\n");
}
void push1coin(float *budget){
    int randomDigit[3];
	spinning(randomDigit);
    int slotcase = isLucky(randomDigit);
    shows(randomDigit);
    if(slotcase == 3){
        *budget += 10;
        printf("You win the big prize, $10.00!\n");
	} else if(slotcase == 2) {
        *budget += 0.5;
        printf("You win 50 cents!\n");
	} else 
		printf("Sorry you don't win anything.\n");
}
float openFile(char filename[]){
	float output;
	FILE *save;
    save = fopen(filename, "r");
    if(save == NULL){
    	fclose(save);
    	save = fopen(filename, "w");
		fprintf(save,"%f", 10.00);
    	fclose(save);
  		save = fopen(filename, "r");
	}
    fscanf(save,"%f", &output);
    fclose(save);
    return output;
}
void saveFile(char filename[], float input){
	remove(filename);
	FILE *save;
	save = fopen(filename, "w+");
	fprintf(save,"%f", input);
    fclose(save);
}
void Capchar(char* k){
	char s[] = "0123456789abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int r;
	for(int i = 0;i<6;i++){
		r = rand()%(strlen(s));
		k[i]=s[r];
	}
	printf(k);
}
bool ChechCapcha(char*k, char* h){
	for(int i = 0; i <6;){
		if(k[i]==h[i]){
			i++;
			break;
		}else{
			return false;
		}
	}
	return true;
}
int main() {
    srand(time(NULL));
    int loop = 1;
    char filename[20];
	strcpy(filename, "profile1.txt");
    float budget = openFile(filename);
    char k[9],h[9];
    while(loop){
        menu(budget);
        int choice = intInput(1,3);
        switch(choice){
            case 1:{
            	if(budget <= 0){
    				printf("Sorry, you're out of wallet!\nThankyou for playing, see you next time!");
    				printf("\nPress 3 if you want put money\n");
					break;
				}
                budget -= 0.25;
                push1coin(&budget);
                break;
            }
            case 2:{
            	saveFile(filename, budget);
   				printf("Your money had saved.\n");
   				loop = 0;
                break;
            }
            case 3:{
            	printf("\nYou want Put Money\nCapCha:");
            	Capchar(k);
            	printf("\nInput CapCha if you want put money: ");
            	gets(h);
            	if(ChechCapcha(k,h)==true){
            		printf("you have money");
            		budget +=10;
				}else{
					printf("Input wrong, no money for you");
				}
				break;
			}
            case 4:{
              printf("Thankyou for playing! You end with $%g!", budget);
              budget = 0;
              saveFile(filename, budget);
              loop = 0;
              break;
            }
        }
   }
    return 0;

}
