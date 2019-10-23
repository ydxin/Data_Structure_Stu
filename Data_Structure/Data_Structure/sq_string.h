#ifndef  _SQ_STRING_H_
#define _SQ_STRING_H_
#include <stdbool.h>
#define MAX_SIZE  50

typedef struct SqString
{
	char data[MAX_SIZE];
	int length;

}SqString;

typedef struct  LinkString
{
	char data;
	struct LinkString* next;
}LinkString;



SqString* StrAssign(char* ch);

void DestroyStr(SqString* s);

void StrCopy(SqString* s, SqString* ch);

bool StrEqual(SqString* s, SqString* ch);

int StrLength(SqString* s);

SqString* ConCatStr(SqString* s, SqString* ch);


//  Á´´®
LinkString* InitLinkString(char* ch);
void DestroyLinkString(LinkString* s);
void LinkStrCopy(LinkString* s, LinkString* t);
void ReplAB(LinkString* s);
void PrintLinkString(LinkString* s);
void GetIndexStr(SqString* s, int next[]);
void GetNextArr(SqString* s, int next[]);



#endif // ! _SQ_STRING_H_
