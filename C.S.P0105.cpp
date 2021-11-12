#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Reverse(char s[]){
	int length = strlen(s);
	for(int i =0;i<length/2;i++){
		char temp = s[i];
		s[i] = s[length-1-i];
		s[length-1-i] = temp;
	}
}
void display(char str[]){
	Reverse(str);
	printf("Result: ");
	printf("%s",str);
}
main(){
	char string[100];
	printf("please enter any string: ");
	fgets(string,100,stdin);
	display(string);
}
