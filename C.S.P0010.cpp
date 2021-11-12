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
void XoaPhantu(int *arr,int &n,int v){
	for(int i = v; i <n; i++){
        arr[i] = arr[i+1];
    }
    
    --n;
}
void find(int *arr,int &n)
{
	int m;
	for(int i = 0; i < n;)
	{
		while(1){
			for(int j = i + 1; j < n; j++)
			{
				if(arr[i] == arr[j])
				{
					XoaPhantu(arr,n,j);
				}
			}
		i++;
		break;
		}
		
	}	
}

main(){
	int n;
	printf("Enter a number of element n=");
	n = intInput(" ",1, INT_MAX);
	int *arr;
	arr = (int*) malloc (n * sizeof(int));
	for(int i=0;i<n;i++){
		arr[i]=intInput("\nelement :",INT_MIN, INT_MAX);
	}
	printf("\nThe original array:");
	for(int k = 0;k<n;k++){
		printf("%4d",arr[k]);
	}
	find(arr,n);
	printf("\nThe array after removing duplicate elements:");
	for(int j = 0;j<n;j++){
		printf("%4d",arr[j]);
	}
	free(arr);
}

