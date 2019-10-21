#ifndef  _LINK_STACK_H_
#define _LINK_STACK_H_

typedef char ElemType;

typedef struct LinkStack
{
	ElemType data;
	struct LinkStack* next;
}LinkStack;

LinkStack* InitLinkStack();
void DestroyLinkStack(LinkStack* s);
int LinkStackIsEmpty(LinkStack* s);
void PushLinkStack(LinkStack* s, ElemType e);
void PopLinkStack(LinkStack* s, ElemType* e);
void GetLinkStackTop(LinkStack* s, ElemType* e);
int MatchBrackets(ElemType* ch);






#endif // ! _LINK_STACK_H_
