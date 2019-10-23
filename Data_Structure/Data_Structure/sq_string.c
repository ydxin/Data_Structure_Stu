#include <stdio.h>
#include "sq_string.h"
#include <stdlib.h>
#include <stdbool.h>
SqString* StrAssign(char* ch)
{
	SqString* s = (SqString*)malloc(sizeof(SqString));
	int i = 0;
	for (i = 0; ch[i] != '\0'; i++)	
		s->data[i] = ch[i];	
	s->length = i;
	return s;
}

void DestroyStr(SqString* s)
{
	free(s);
}

void StrCopy(SqString* s , SqString* ch)
{
	for (int i = 0; i < ch->length; i++)
		s->data[i] = ch->data[i];
	s->length = ch->length;
}

bool StrEqual(SqString *s,SqString *ch)
{
	int i = 0;
	if (s->length != ch->length)
		return false;
	for (i = 0; i < s->length; i++)
	{
		if (s->data[i] != ch->data[i])
			return false;
	}
	return true;
}

int StrLength(SqString* s)
{
	return s->length;
}

SqString*  ConCatStr(SqString* s, SqString* ch)
{
	SqString* str = StrAssign(ch);
	str->length = s->length + ch->length;
	for (int i = 0; i < s->length; i++)
		str->data[i] = s->data[i];
	for (int i =0; i < ch->length; i++)
		str->data[s->length+i] = ch->data[i];
	return str;
}


//链串
LinkString* InitLinkString(char* ch)
{
	LinkString* s = (LinkString*)malloc(sizeof(LinkString));
	LinkString* r = s;
	LinkString* p;
	for (int i = 0; ch[i] != '\0'; i++)
	{
		p = (LinkString*)malloc(sizeof(LinkString));
		p->data = ch[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return s;
}

void DestroyLinkString(LinkString* s)
{
	LinkString* pre = s;
	LinkString* p = s->next;
	while (p)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

int LinkStrLength(LinkString* s)
{
	LinkString* p = s->next;
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

void LinkStrCopy(LinkString* s, LinkString* t)
{
	LinkString* p = t->next;
	LinkString* r = s;
	LinkString* q;
	while (p)
	{
		q = (LinkString*)malloc(sizeof(LinkString));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r = r->next;
}

void ReplAB(LinkString* s)
{
	LinkString* p = s->next;
	
	while (p&&p->next)
	{
		if (p->data == 'a' && p->next->data == 'b')
		{
			p->data = 'x';
			p->next->data = 'y';
			LinkString* q = (LinkString*)malloc (sizeof(LinkString));
			q->data = 'z';
			q->next = p->next->next;
			p->next ->next= q;
		}
		p = p->next;
	}
}

void PrintLinkString(LinkString* s)
{
	LinkString* p = s->next;
	while (p)
	{
		printf("%c\t", p->data);
		p = p->next;
	}
	printf("\n");
}


//模式匹配
int StrBruteForce(LinkString* s, LinkString* t)
{
	LinkString* p = s;
	LinkString* p1;
	LinkString* q ;
	while (p->next)
	{
		q = t->next;
		p = p->next;
		p1 = p;
		while (p1 && q && p1->data == q->data)
		{
			p1 = p1->next;
			q = q->next;
		}
		if (!q )
			return true;
		if (!p1)
			return false;
	}
	return false;
}


//获得部分匹配值表
void GetIndexStr(SqString* s,int next [])
{
	int i = 1;
	int j = 0;
	next[0] = 0;
	while (i	 < s->length)
	{
		if (s->data[i] == s->data[j])
			next[i++] = (j++) + 1;
		else if ( j ==0 && s->data[i] != s->data[j])
			next[i++] = 0;			
		else 
		j = next[j - 1];
	}
}


//获得next数组 :相当于部分匹配值表右移1位，前插 - 1
void GetNextArr(SqString* s, int next[])
{
	int i =  0 ;
	int j =  -1 ;
	next[0] = -1;
	while (i < s->length - 1)
	{
		if (j == -1 || s->data[i] == s->data[j])
			next[++i] = ++j;
		else
			j = next[j];
	}
}

void GetNextArrAdd1(SqString* s, int next[])
{
	int i = 0;
	int j = -1;
	next[0] = j+1;
	while (i < s->length - 1)
	{
		if (j == -1 || s->data[i] == s->data[j])
			next[++i] = ++j +1;
		else
			j = next[j] - 1;
	}
}

void GetNextValArr(SqString* s, int nextVal[])
{
	int i = 0;
	int j = -1;
	nextVal[0] = -1;
	while (i < s->length - 1)
	{
		if (j == -1 || s->data[i] == s->data[j])
		{
			i++;
			j++;
			if (s->data[i] != s->data[j])
				nextVal[i] = j;
			else  nextVal[i] = nextVal[j];
		}
		else
			j = nextVal[j];
	}
}

int KMPStr1(SqString* s, SqString* t)
{
	int next[MAX_SIZE];
	int i = 0;
	int j = 0;
	GetNextValArr(t, next);
	while (i < s->length && j < t->length)
	{
		if (j == -1 || s->data[i] == t->data[j])
		{
			i++;
			j++;
		}
		else j = next[j];
	}
	if (j >= t->length)
		return (i - t->length);
	else
		return -1;
}


int KMPStr(SqString* s, SqString* t)
{
	int next[MAX_SIZE];
	int i = 0;
	int j = 0;
	GetNextArr(t,next);
	while (i < s->length && j<t->length)
	{
		if (j == -1 || s->data[i] == t->data[j])
		{
			i++;
			j++;
		}
		else j = next[j];
	}
	if (j >= t->length)
		return (i - t->length);
	else
		return -1;
}


