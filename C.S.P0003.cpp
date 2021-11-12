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

void SapXepTangDan(int *arr,int n)
{
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	for(int k=0;k<n;k++){
		printf("%4d",arr[k]);
	}
}

int search(int *arr,int n,int m){
	for(int i=0;i<n;i++){
		if(arr[i]>=m){
			return i;
		}
	}
	
}
void ThemPhanTu(int *arr,int &n,int m){
    int re = search(arr,n,m);
	for(int i = n; i > re; i--){
        arr[i] = arr[i-1];
    }
    arr[re] = m;
    ++n;
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
	printf("The Array after sorting:");
	SapXepTangDan(arr,n);
	int m = intInput("\nEnter new value: ",1, INT_MAX);
	ThemPhanTu(arr,n,m);
	printf("\nnew Array:");
	for(int j = 0;j<n;j++){
		printf("%4d",arr[j]);
	}
	free(arr);
}

