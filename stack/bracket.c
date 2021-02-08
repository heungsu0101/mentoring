#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0
typedef struct _stack{
	int data[MAX_SIZE];
	int top;
}STACK;

STACK stack;

int isEmpty(){
	if(stack.top!= 0){
		return FALSE;
	}
	else{
		return TRUE;
	}
}
int push(char x){
	if(stack.top<MAX_SIZE){
		stack.data[stack.top++]=x;
	}
	else{
		return FALSE;
	}
}

char pop(){
	if(stack.top>0){
		return stack.data[--stack.top];
	}
	else{
		return FALSE;
	}
}
int main(){
	char a[MAX_SIZE];
	int count=0;
	scanf("%[^\n]",a);
	for(int i=0;i<strlen(a);i++){
		if(a[i]=='{'||a[i]=='['||a[i]=='('){
			push(a[i]);
		}
		if(a[i]=='}'||a[i]==']'||a[i]==')'){
			if(!isEmpty()){
				switch(a[i]){
					case '}' :
						if(pop()=='{'){
							break;
						}
						else{
							count++;
							break;
						}
						
					
					case ']' :	
						if(pop()=='['){
							break;
						}
						else{
							count++;
							break;
						}
						break;

					case ')' :
						if(pop()=='('){
							break;
						}
						else{
							count++;
							break;
						}
						break;
				}
			}
			else{
				count++;
			}
		}
	}
	if(!isEmpty()){
		count++;
	}
	if(count==0){
		printf("맞음");
	}
	else{
		printf("틀림");
	}
	return 0;
}
