#ifndef LIST
#define LIST
#include "Data.h"

typedef struct {
	void ** list;
	char * types;
	int length;
}List;

List * CreateList();
void append(List * list,char type,...);
void deleteitem(List * list,int index);
void printlist(List *list);
Data getitem(List *list,int index);
void setitem(List * list,int index,char type,...);
void freelist(List * list);

#endif