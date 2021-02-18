#include <stdio.h>

char arr[100] = {0, 'A', 'B', 'C', 'D', 'E', 'F'};

void inOrder(char x, int pos)
{
	
	if (arr[pos * 2] != 0){
		inOrder(arr[pos * 2], pos * 2);
	}

	printf("[%c] ", x);

	if (arr[(pos * 2) + 1] != 0){
		inOrder(arr[(pos * 2 ) + 1], (pos * 2) + 1);
	}
}

void preOrder(char x, int pos)
{
	printf("[%c] ", x);

	if (arr[pos * 2] != 0){
		preOrder(arr[pos * 2], pos * 2);
	}
	if (arr[(pos * 2) + 1] != 0){
		preOrder(arr[(pos * 2 ) + 1], (pos * 2) + 1);
	}
	
}

void postOrder(char x, int pos)
{
	if (arr[pos * 2] != 0){
		postOrder(arr[pos * 2], pos * 2);
	}
	if (arr[(pos * 2) + 1] != 0){
		postOrder(arr[(pos * 2 ) + 1], (pos * 2) + 1);
	}
	
	printf("[%c] ", x);
}

int main()
{

	// 중위 순회
	printf("중위 순회 : ");
	inOrder(arr[1], 1);
	printf("\n");
	// 전위 순회 
	printf("전위 순회 : ");
	preOrder(arr[1], 1);
	printf("\n"); 
	// 후위 순회
	printf("후위 순회 : ");
	postOrder(arr[1], 1);
	printf("\n");
	return 0;

}
