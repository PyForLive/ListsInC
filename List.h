#ifndef LIST
#define LIST

typedef struct {
	void ** list;
	char * types;
	int length;
}List;

List * CreateList();
void append(List * list,char type,...);
void printlist(List *list);
void freelist(List * list);

#endif