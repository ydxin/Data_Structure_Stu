#include <Windows.h>
#include <stdbool.h>
#include "link_queue.h"
#include "recursion.h"
void PrintString(char *ch);

int main()
{
	int a = 	StepNums(3);
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
