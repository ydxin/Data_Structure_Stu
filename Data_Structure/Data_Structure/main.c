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
	
	int a[5] = { 1,2,3,4,5 };
	CreateOLinkNode(a, 5);
	system("pause");
	return 0;
}

