#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>
#include "link_queue.h"
#include "recursion.h"
#include "array.h"
#include "search.h"
void PrintString(char *ch);

int main()
{
	RecType R[11];
	int a[11] = { 2,3,10,15,20,25,28,29,30,35,40 };
	for (int i = 0; i < 11; i++)
	{
		R[i].data =1 ;
		R[i].key = a[i];
	}
	
	int aa= BinSearchRes(R, 0, 10, 11, 26);
	//printf("%d\n", a);




	system("pause");
	return 0;
}




void PrintString(char* ch)
{
	int len = strlen(ch);
	for (int i = 0; i < len; i++)
		printf("%c",ch[i]);
	printf("\n");
}

