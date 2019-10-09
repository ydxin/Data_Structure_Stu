#include "introduction.h"
#include "linear_list.h"
int main()
{
	SqList* pSql;
	int a[10] = { 4,2,5,16,3,53,12,32,53,43 };
	pSql =CreateList( a, 10);
	OddToEven(pSql);
	getch();
	return 0;
}

