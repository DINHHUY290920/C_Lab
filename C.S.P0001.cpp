#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <windows.h>
#include <conio.h>


char ReversedString2(char *string){
	char word[50],Newword[100]="";
	
	for(int i=strlen(string);i>=0;i--){
		if(string[i]==95){
			strcat(Newword, &string[i+1]);
			strcat(Newword, "_");
			string[i]=0;
		}
	}
	strcat(Newword, &string[0]);
	strcpy(string,Newword);
	return *string;
}
void startMEssage(char *string){
	char k;
	do{
		ReversedString2(string);
		printf("%s\n",string);
		printf("Enter to continue, ESC to exiting\n");
		k=getch();
	}while(k!=27);
}
int main(){
	char string[100];
	printf("please enter any string: ");
	gets(string);
	startMEssage(string);	
}
