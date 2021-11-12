#include<stdio.h>
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

//10
//2 3
int prim(int n){
	if(n<2){
		return 0;
	}
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
//7
// 0 + 1 = 1
//1 + 1 = 2
//1 + 2 = 3
//3 + 2 = 5
//5 + 3 = 8
//8>7 va 8 != 7
//ko phai so fibo
void fibo(){
	int z ,i, fib1 = 0, fib2 = 1, fib ;
	printf("\nNumber tested: ");
	z = intInput(0, INT_MAX);
	while (fib1+fib2 <= z){
        fib = fib1 + fib2;
        fib2 = fib1;
        fib1 = fib;
   	}
	if( fib==z||z==1||z==0) {
		printf("It is a Fibonacci number.");
	}else {
		printf("It is not a Fibonacci number.");
	}
}

void sum(){
	int e, sum=0, count=0;
	printf("\nEnter an integer: ");
	e=intInput(0,INT_MAX);
	while((e%10)!=0){
		sum+=e%10;
		e=e/10;
	}
	printf("\nSum: %d",sum);	
}
int main(){
	int opt, n, i=2, dem=0;
	do{
	printf("\n1. The first primes");
	printf("\n2. Fibonacci element");
	printf("\n3. Sum of digits");
	printf("\n4. Quit\n");
	printf("\nChoose an option: ");
	opt = intInput(1,4);
	switch(opt){
		case 1:
				printf("\nNumber of primes: ");
				n = intInput(1,50);
				while(dem<n){
					if(prim(i)){
						printf("%4d",i);
						dem++;
					}
					i++;
				}
				break;
	 	case 2: fibo();
	 			break;
	 	case 3: sum();
	 			break;
	 }
	}while(opt!=4);
	printf("\nExited.");
	return 0;
}
