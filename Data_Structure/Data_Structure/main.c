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
	OLinkNode* pOLink1;
	OLinkNode* pOLink2;
	OLinkNode* pOLink;
	int a[5] = { 5,14,33,52,1 };
	int b[6] = { 2,3,54,23,53,45 };
	pOLink1=CreateOLinkNode(a, 5);
	pOLink2 = CreateOLinkNode(b, 6);
	pOLink = UnionOLinkList(pOLink1, pOLink2);
	DispOLinkList(pOLink1);
	DispOLinkList(pOLink2);
	DispOLinkList(pOLink);
	DestroyOLinkList(pOLink1);
	DestroyOLinkList(pOLink2);
	DestroyOLinkList(pOLink);
	system("pause");
	return 0;
}

