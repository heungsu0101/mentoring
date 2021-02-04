#include<stdio.h>

#define MAX_SIZE 1000
#define TRUE 1
#define FALSE -1

typedef struct _stack{
	int data[MAX_SIZE];
	int top;
}STACK;

STACK stack;

void init(){
	stack.top=0;
}

int  isEmpty(){
	if(stack.top!=0){
		return FALSE;
	}
	else{
		return TRUE;
	}
}

int isFULL(){
	if(stack.top!=MAX_SIZE){
		return FALSE;
	}
	else{
		return TRUE;
	}
}

int size(){
	return stack.top;
}

int push(int x){
	if(stack.top<MAX_SIZE){
		stack.data[stack.top++]=x;
	}
	else{
		return FALSE;
	}
}

int pop(){
	if(stack.top>0){
		return stack.data[--stack.top];
	}
	else{
		return FALSE;
	}
}

int peek(){
	return stack.data[stack.top-1];
}

int main(){
	for(int i = 1; i <= 10; i++)
        	push(i);
 
        printf("peek : %d\n", peek());
 
        for(int i = 0; i < 10; i++)
            printf("poped : %d\n", pop());
	return 0;
}
