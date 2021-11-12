#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){
	int X[100], tong=0,tb=0;
	X[0]=1,X[1]=2;X[2]=3;
	for(int i=3;i<99;i++){
	X[i]=X[i-1] +  X[i-2]  + X[i-3];
	}
	for(int j=0;j<99;j++){
	printf("%4d",X[j]);
	}
}
