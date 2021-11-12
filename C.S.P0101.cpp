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
		else if(output < min || output > max )
			printf("Outrange input!\nTry again: ",min,max);
		else return output;
	}
}
void RandomNum(int *arr, int n){
	int r;
	for(int i = 0;i<n;i++){
		r = 0+rand()%(100+1-0);
		printf("\n[%d]:\t%d",i+1,r);
		arr[i]=r;
	}
}

void SwapEOA(int* arr,int m,int h){
	int temp = arr[m];
	arr[m] = arr[h];
	arr[h] = temp;
}

main(){
	int n,m,h;
	printf("Enter a number of element n=");
	n = intInput(1, INT_MAX);
	int *arr;
	arr = (int*) malloc (n * sizeof(int));
	RandomNum(arr,n);
	
	printf("\nSwap 2 Element:\nElement 1:");
	m = intInput(1, n);
	m=m-1;
	printf("\nElement 2:");
	h = intInput(1, n);
	h=h-1;
	SwapEOA(arr,m,h);
	
	printf("\nArray after swap:");
	for(int i = 0;i<n;i++){
		printf("\n[%d]:\t%d",i+1,arr[i]);
	}
	free(arr);
	}

