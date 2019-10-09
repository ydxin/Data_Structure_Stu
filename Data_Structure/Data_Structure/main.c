#include "introduction.h"
#include "linear_list.h"
#include "link_list.h"
int main()
{
	SqList* pSql;
	LinkNode* pLink;
	int a[10] = { 4,2,5,16,3,53,12,32,53,43 };
	pLink = CreateLinkListR(a,10);
	LinkListInsert(pLink, 3, 100);
	pSql =CreateList( a, 10);
	OddToEven(pSql);
	getch();
	return 0;
}

