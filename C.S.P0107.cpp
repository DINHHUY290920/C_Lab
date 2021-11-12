#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
//the first occurrence
nguyen
dinh
huy

in
void SearchSubInMain(char *string,char *sub){
	int dem =0;
	char* p = strtok(string," ");
	while(p != NULL){
		dem+=1;
		if(strstr(p,sub)!=NULL){
			printf("Starting position of the substring in the main string: %d",dem);
			break;
		}
		p = strtok(NULL," ");
	}
}
int main(){
	char string[100],sub[100];
	printf("please enter main string: ");
	gets(string);
	printf("please enter substring: ");
	gets(sub);
	SearchSubInMain(string,sub);
}
