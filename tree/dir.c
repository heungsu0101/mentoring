#include<stdio.h>
#include<string.h>

typedef struct f{
   char name[100];
   int size;
}f;

int size;
//후위 순회를 이용한 폴더 용량 계산
int sizecount(f *a, int pos)
{
	if (pos<14){
		if (strcmp(a[pos * 2].name, "0") != 0){
			sizecount(a, pos * 2);
		}
		if (strcmp(a[(pos * 2) + 1].name, "0") != 0){
			sizecount(a, (pos * 2) + 1);
		}
	}
	else
		return 0;
	size += a[pos].size;
	return size;
}

int main(){

    f com_file[14] = {{"0",0}, {"Document",0}, {"Music",50}, {"Picture",100}, {"K-Pop",200}, {"Pop",300}, {"Photo",200}, {"Movie",500}, {"0",0}, {"0",0}, {"0",0}, {"0",0}, {"2020",1000}, {"2021",50}};
    char dir[31];
    int pos = 0; 

    scanf("%s", dir);
   
    for(int i = 1; i <= 13; i++){
 		if(strcmp(dir, com_file[i].name)==0){
			pos=i;
 	    }
    }
    if(pos == 0){
	    printf("없는 디렉토리명 입니다.\n");
	    return 0;
    }
	
    printf("%d\n", sizecount(com_file, pos));
   
	return 0;
}
