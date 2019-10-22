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
	SqString* str = StrAssign();
	str->length = s->length + ch->length;
	for (int i = 0; i < s->length; i++)
		str->data[i] = s->data[i];
	for (int i =0; i < ch->length; i++)
		str->data[s->length+i] = ch->data[i];
	return str;
}













