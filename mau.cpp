#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<math.h>
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
			printf("Outrange input!(%d-%d)\nTry again: ",min,max);
		else return output;
	}
}
void Menu(){
	printf("\n1. Add a value.");
	printf("\n2. Search a value.");
	printf("\n3. Print out the array.");
	printf("\n4. Print out values in a range of inputted min and max values, inclusively.");
	printf("\n5. Sort the array in ascending order. ");
	printf("\n6. Quit");
	printf("\nEnter your choice: ");
}

void addValue(int *arr, int *index){
	if(*index == 100){
		printf("\nfull element in array\n");
	}else{
		printf("\nInput an integer to store: ");
		arr[*index] = intInput(INT_MIN,INT_MAX);
		*index += 1;
		arr = (int*) realloc(arr, *index * sizeof(int));
	}
}
void search(int *arr,int index){
	if(index == 0){
		printf("\nNo have element in array\nAdd element if you want search array\n");
	}else{
		int searchNumber, i;
		printf("\nEnter number you want to search: ");
		searchNumber = intInput(INT_MIN,INT_MAX);
		for(int i=0;i<index;i++){
			if(searchNumber == arr[i]){
				printf("Your number is in slot number %d in array.\n",i+1);
			}
		}
		if(i==index){
			printf("your number not found.\n");
		}
	}
	
}
void display(int *arr,int index){
	if(index == 0){
		printf("\nNo have element in array\nAdd element if you want print array\n");
	}else{
		printf("All you current array:");
		int i;
		for(i = 0; i < index; i++){
			printf("\t%d", arr[i]);
		}
		printf("\n");
	}
}
void displayMinMax(int *arr,int index){
	if(index == 0){
		printf("\nNo have element in array\nAdd element if you want print array\n");
	}else{
		int dem =0;
		printf("Enter Min: ");
		int min = intInput(INT_MIN,INT_MAX);
		printf("Enter Max: ");
		int max = intInput(min,INT_MAX);
	
        for (int i = 0; i < index; i++) {
            if (arr[i] >= min && arr[i] <= max) {
                printf("%4d ", arr[i]);
                dem++;
            }
    	}
    	if(dem==0){
    		printf("No have element in rage");
		}
	}
	
}
void SapXepTangDan(int *arr,int index)
{
	if(index == 0){
		printf("\nNo have element in array\nAdd element if you want print array\n");
	}else{
		for(int i = 0; i <index-1; i++)
		{	
			for(int j = 0; j < index-i-1; j++)
			{
				if(arr[j] > arr[j+1])
				{
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
		printf("\nSort the array in ascending order:\n");
		for(int k=0;k<index;k++){
			printf("%4d",arr[k]);
		}
	}
	
}
void function(int *arr,int index){
	int opt,l=1;
	while(l){
		Menu();
		opt = intInput(1,6);
		switch(opt){
			case 1:
				addValue(arr,&index);
				break;
			case 2:
				search(arr,index);
				break;
			case 3:
				display(arr,index);
				break;
			case 4:
				displayMinMax(arr,index);
				break;
			case 5:
				SapXepTangDan(arr,index);
				break;
			case 6:
				l=0;
				printf("\nExited.");
				break;
		}
		printf("\n--------------------------------\n");
	}
}
int main(){
	int *arr;
	int index = 0;
	arr = (int*)malloc(index * sizeof(int));
	function(arr,index);
	free(arr);
}
