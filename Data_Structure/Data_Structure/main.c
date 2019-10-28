#include <Windows.h>
#include <stdbool.h>
#include "link_queue.h"
#include "recursion.h"
#include "array.h"
void PrintString(char *ch);

int main()
{
	Josephus(8, 4);
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
