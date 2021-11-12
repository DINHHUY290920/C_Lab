#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int intInput(char S[],int min, int max){
	int i, output, check;
	char ch;
	while(1){
		printf("%s",S);
		check = scanf("%d%c", &output, &ch);
		fflush(stdin);
		if(check != 2 || ch != 10)
			printf("Wrong input!\nTry again: ");
		else if(output < min || output > max)
			printf("Outrange input!(%d-%d)\nTry again: ",min,max);
		else return output;
	}
}


int output(int *arr,int n)
{
	printf("Array element: \n");
	for(int i = 0; i < n; i++)
	{
		printf("%4d", arr[i]);
	}
}
void Maximum(int *arr,int n){
	int max = arr[0];
	printf("\n\nArray maximum value:");
	for(int i =1;i<n;i++){
		if(max<arr[i]){
			max=arr[i];
		}
	}
	printf("%d", max);
}
void EvenElement(int *arr,int n){
	printf("\n\nArray even value:");
	for(int i=0;i<n;i++){
		if(arr[i]%2==0){
			printf("%4d",arr[i]);
		}
	}
}

int main(){
int n;
	printf("Enter a number of element n=");
	n = intInput(" ",1, INT_MAX);
	int *arr;
	arr = (int*) malloc (n * sizeof(int));
	for(int i=0;i<n;i++){
		arr[i]=intInput("\nelement :",INT_MIN, INT_MAX);
	}
	output(arr,n);
	Maximum(arr,n);
	EvenElement(arr,n);
	free(arr);
}

