#include <stdio.h> 
#include <cstdlib>
#include <stdlib.h>
#include <limits.h>
#include<math.h>
int CheckInput(char *msg, int MIN,int MAX){
	int Number, check;
	char ch;
	do{
		printf("%s", msg);
		fflush(stdin);
		check = scanf("%d%c", &Number, &ch);
		if(check==2 && ch=='\n'){
			if(Number>=MIN && Number<=MAX) break;
			else printf("Out of range, please enter %d-%d: ",MIN,MAX);
	}else printf("Invalid input, please enter an integer number: ");
		
	}while(1);
	return Number;
}
int checkSquare(){
	int square;
	do{
		square = CheckInput("",0,INT_MAX);
		//lam tron so can bac 2 cua square
		int s = sqrt(square);
		if(s == sqrt(square)){
			break;
		}else{
			printf("Please enter square number!");
		}
	}while(1);
	return square;
}
main(){
	int Size = CheckInput("Please enter number of terms: ",1,100);
	int a[Size];
	int total =0;
	for(int i=0;i<Size;i++){
		printf("Element [%d]: ",i);
		a[i] = checkSquare();
		total = total+a[i];
	}
	printf("\nTotal: %d",total);
}

