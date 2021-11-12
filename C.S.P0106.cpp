#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void lengthOfTheLongest(char *string){
	char word[50],lword[50];
	int longest =0,longw =0;
	for(int i=strlen(string)-1;i>=0;i--){
		if(string[i]==32){
			strcpy(word, &string[i+1]);
			longw = strlen(word);
			string[i]=0;
			if(longest<longw){
				longest=longw;
				strcpy(lword,word);
			}
		}
	}
	//xet word ddau tien
	strcpy(word,&string[0]);
	longw = strlen(word);
	if(longest<longw){
		longest = longw;
		strcpy(lword,word);
	}
	printf("the longest substring: %s [%d]",lword,longest);
}
int main(){
	char string[100];
	printf("please enter any string: ");
	gets(string);
	lengthOfTheLongest(string);
}
