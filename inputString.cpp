char* InputStr(char MSG[]){
char* s;
char c;
int i=1;
 printf("\n%s",MSG);
 s=(char*)malloc(i*sizeof(char));//allocating 1 byte for s
 do{ 	
 	fflush(stdin);
 	c=getch();printf("%c",c);
 	if (c==13)break;// enter
 	s[i-1]=c;// *(s+i-1)=c
 	i++;
 	s=(char*)realloc(s,i*sizeof(char));//char=1 byte, expanded i bytes for s
 }while(1);
 s[i]=0;// assign and of line;//'/0'
 return s;	
}
char* InputStr(char MSG[]){
char* s;
char c;
int i=1;
 printf("\n%s",MSG);
 s=(char*)malloc(i*sizeof(char));//allocating 1 byte for s
 do{ 	
 	fflush(stdin);
 	c=getch();printf("%c",c);
 	if (c==13)break;// enter
 	s[i-1]=c;// *(s+i-1)=c
 	i++;
 	s=(char*)realloc(s,i*sizeof(char));//char=1 byte, expanded i bytes for s
 }while(1);
 s[i]=0;// assign and of line;//'/0'
 return s;	
}
int main(){
	char str1[length];
	int i=0;
	char ch;
	char* str=InputStr("Enter a name:");
	printf("\nThe string inputed: %s",str);
	printf("\nEnter a string without char*: ");
	do{
		fflush(stdin);
		ch=getch();printf("%c",ch);
		if (ch==13)break;
		str1[i++]=ch;
		if(i>=length){
			printf("\nExceed of length");
			break;
		}
	}while(1);
str1[i]=0;
	printf("\nThe string inputed 2: %s",str1);
	free(str);	
}
