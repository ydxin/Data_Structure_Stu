#include "introduction.h"
#include "linear_list.h"
#include "link_list.h"
#include "double_link_list.h"
int main()
{
	LinkNode* pLink;
	DLinkNode* pDlink;
	
	LinkNode* L1;
	LinkNode* L2;
	int a[10] = { 1,2,13,4,5,6,27,8,9,10 };
	pDlink = CreateDLinkListR(a,10);
	getch();
	return 0;
}

