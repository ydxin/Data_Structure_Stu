#include <Windows.h>
#include "introduction.h"
//#include "linear_list.h"
//#include "link_list.h"
#include "double_link_list.h"
#include "circular_link_list.h"
#include "list_app.h"
#include "ordered_list.h"
#include "stack.h"
int main()
{
	ElemType* str = "abcdcba";
	int a = JudgeSym(str);
	if (a == SUCCESS) printf("success");
	else printf("failed");



	system("pause");
	return 0;
}

