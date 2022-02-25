
#include "List.h"
#include <stdio.h>

int main(){
	List * list;
	list=CreateList();
	append(list,'i',9);
	append(list,'i',88);
	append(list,'i',8888);
	append(list,'d',6.6);
	append(list,'s',"Hola desgraciados");
	append(list,'s',"Estoy escapao en C");
	//printf("%d\n",*((int *)list->list[1]));
	//printf("%c\n",list->types[1]);
	printlist(list);
	freelist(list);
}