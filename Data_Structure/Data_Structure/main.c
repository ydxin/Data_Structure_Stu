#include <Windows.h>
#include "introduction.h"
#include "linear_list.h"
#include "link_list.h"
#include "double_link_list.h"
#include "circular_link_list.h"
#include "list_app.h"
#include "ordered_list.h"
int main()
{
	OLinkNode* pOLink;
	int a[5] = { 5,14,33,52,1 };
	pOLink=CreateOLinkNode(a, 5);
	DispOLinkList(pOLink);
	OLinkListInsert(pOLink, 10);
	OLinkListInsert(pOLink, 2);
	OLinkListInsert(pOLink, 120);
	DispOLinkList(pOLink);
	DestroyOLinkList(pOLink);
	system("pause");
	return 0;
}

