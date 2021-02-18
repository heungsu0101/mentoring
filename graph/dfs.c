#include <stdio.h>

		   		 //A, B, C, D, E, F, G, H
int graph[8][8] = {0, 1, 0, 0, 0, 1, 1, 0,
				   1, 0, 1, 1, 0, 0, 0, 0,
				   0, 1, 0, 0, 0, 0, 0, 0,
				   0, 1, 0, 1, 1, 0, 0, 0,
				   0, 0, 0, 1, 0, 0, 0, 0,
			  	   1, 0, 0, 0, 0, 0, 0, 0,
				   1, 0, 0, 0, 0, 0, 0, 1,
				   0, 0, 0, 0, 0, 0, 1, 0};

char alpha[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int visit[8] = {0, };

void dfs(int x)
{
	visit[x] = 1;
	printf("%c ", alpha[x]);
	for (int j = x; j < 8; j++){
		for (int i = 0; i < 8; i++){
			if(graph[i][j] == 1 && (visit[j] == 0)){
				dfs(j);
			}	
		}
	} 
}

int main()
{
	printf("dfs result : ");
	dfs(0);
	printf("\n");
	return 0;
}
