#include "link_stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
LinkStack* InitLinkStack()
{
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	s->next = NULL;
	return s;
}

void DestroyLinkStack(LinkStack* s)
{
	LinkStack* pre = s;
	LinkStack* p = s->next;
	while (p)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

int LinkStackIsEmpty(LinkStack* s)
{
	return (s->next == NULL);
}

void PushLinkStack(LinkStack* s, ElemType e)
{
	LinkStack* p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}

void PopLinkStack(LinkStack* s, ElemType*e)
{
	if (!s->next)
		return;
	LinkStack* p = s->next;
	*e = s->next->data;
	s->next = s->next->next;
	free(p);
}

void GetLinkStackTop(LinkStack* s, ElemType* e)
{
	if (!s->next)	return;
	*e = s->next->data;
}

int MatchBrackets(ElemType* ch)
{
	LinkStack* s = InitLinkStack();
	int n = strlen(ch);
	int i = 0;
	char e;
	bool match = true;
	while (i < n && match)
	{
		if (ch[i] == '(')
		{
			PushLinkStack(s, ch[i]);
		}
			
		else if (ch[i] == ')')
		{ 
			if (s->next->data == '(')		
				PopLinkStack(s, &e);
			else
			{
				DestroyLinkStack(s);
				return false;
			}
		}
		i++;
	}
	if (!LinkStackIsEmpty(s)) match = false; 
	DestroyLinkStack(s);
	return match;
}

