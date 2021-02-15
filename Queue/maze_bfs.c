#include<stdio.h>

#define MAX_QUEUE_SIZE 10001

int N,M;
int front;
int rear;
int maze[101][101];
int visit[101][101];

//방향 표현(상하좌우) 
int dx[4] = {0,0,-1,1}; 
int dy[4] = {1,-1,0,0};

//좌표 표현 
typedef struct xy{
	int x;
	int y;
}xy;

xy queue[MAX_QUEUE_SIZE];

int is_empty(){
	if (front == rear){
		return 1;
	}
	else
		return 0;
}

void enqueue(int x,int y){
	xy temp;
	temp.x = x;
	temp.y = y;
	rear = rear % MAX_QUEUE_SIZE;
	queue[rear++] = temp;
}

xy dequeue(){
	front = front % MAX_QUEUE_SIZE;
	return queue[front++];
}
void BFS(int x,int y){
	int nx, ny;
	while (! is_empty()){
		xy pop = dequeue();
		for (int i = 0; i < 4 ; i++){
			nx = pop.x + dx[i];
			ny = pop.y + dy[i];
			//미로 밖으로 나갈 경우 
			if (nx < 1 || nx > N || ny < 1 || ny > M)
				continue;
			//벽인 경우 
			if(maze[nx][ny] == 0)
				continue;
			if(visit[nx][ny] == 0){
				visit[nx][ny] = visit[pop.x][pop.y] + 1;
				enqueue(nx,ny);
			} 
		}
	}
}

int main(){
	scanf("%d%d",&N,&M);
	for (int x = 1; x <= N; x++)
		for (int y = 1; y <= M; y++)
			scanf("%1d", &maze[x][y]);
	enqueue(1,1);
	visit[1][1] = 1;
	BFS(1,1);
	printf("%d", visit[N][M]);
	return 0;
}
