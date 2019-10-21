#include <Windows.h>
#include <stdbool.h>
//#include "introduction.h"
//#include "linear_list.h"
//#include "link_list.h"
//#include "double_link_list.h"
//#include "circular_link_list.h"
//#include "list_app.h"
//#include "ordered_list.h"
#include "stack.h"
#include "link_stack.h"
int main()
{
	char* ch = "(56-40)/(6-2)";
	char postExp[50];
	bool a = MatchBrackets(ch);
	Trans(ch, postExp);

	system("pause");
	return 0;
}

