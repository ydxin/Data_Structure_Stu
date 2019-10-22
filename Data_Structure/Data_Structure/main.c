#include <Windows.h>
#include <stdbool.h>
#include "link_queue.h"

void PrintString(ch);

int main()
{

	

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
