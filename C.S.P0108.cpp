#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
void inputMany(int *arr, int n){
	
	printf("Input elements:\n");
	int i;
	for(i = 0; i < n; i++){
		printf("\tElement %d=",i+1);
		arr[i] = intInput(0, INT_MAX);
	}
}
void convertinttoASCII(int *arr,int n){
	int i;
	char c;
	for(int i =0;i<n;i++){
		if(arr[i]>=65 &&arr[i]<=90 || arr[i]>=97 && arr[i]<=122){
			c = arr[i];
			printf("\n[%d]  %c",i,c);
		}else{
			printf("\n[%d]  %d",i,arr[i]);
			
		}
	}
}

int main(){
int n;
	printf("Sum Even Odd program\n");
	printf("Enter a number of element n=");
	n = intInput(1, INT_MAX);
	int *arr;
	arr = (int*) malloc (n * sizeof(int));
	inputMany(arr, n);
	convertinttoASCII(arr,n);
	free(arr);
	
}
