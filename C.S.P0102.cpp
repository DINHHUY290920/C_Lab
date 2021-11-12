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
			printf("Outrange input!\nSize matrix 2 equal matrix 1\nTry again: ",min,max);
		else return output;
	}
}
void ElementMatrix(int **matrix,int r,int c){
	for(int i =0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("Element[%d][%d]:",i+1,j+1);
			matrix[i][j]= intInput("",INT_MIN,INT_MAX);
		}
	}
}
void AdditionMatrix(int **matrix1,int **matrix2,int **matrix3,int r,int c){
	printf("Result:");
	for(int i =0;i<r;i++){
		for(int j=0;j<c;j++){
			matrix3[i][j] = matrix1[i][j]+matrix2[i][j];
			printf("%d\t",matrix3[i][j]);
		}
		printf("\n");
	}
}
main(){
	int r,c,r1,c1,**matrix1,**matrix2,**matrix3;
	printf("Addition of 2 matrices");
	r = intInput("\nPlease enter row of matrix 1: ",1,INT_MAX);
	c = intInput("\nPlease enter column of matrix 1: ",1,INT_MAX);
	

	matrix1 = (int **)malloc(r* sizeof(int));
	for(int i = 0; i<r;i++){
		matrix1[i]= (int *)malloc(c* sizeof(int));
	}
	ElementMatrix(matrix1,r,c);
	
	
	r1 = intInput("\nPlease enter row of matrix 2: ",r,r);
	c1 = intInput("\nPlease enter column of matrix 2: ",c,c);
	matrix2 = (int **)malloc(r* sizeof(int));
	for(int i = 0; i<r;i++){
		matrix2[i]= (int *)malloc(c* sizeof(int));
	}
	ElementMatrix(matrix2,r1,c1);
	
	
	
	matrix3 = (int **)malloc(r* sizeof(int *));
	for(int i = 0; i<r;i++){
		matrix3[i]= (int *)malloc(c* sizeof(int));
	}
	AdditionMatrix(matrix1,matrix2,matrix3,r,c);
	for(int i=0;i<r;i++){
		free(matrix1[i]);
		free(matrix2[i]);
		free(matrix3[i]);
	}
	free(matrix1);
	free(matrix2);
	free(matrix3);
	
}
