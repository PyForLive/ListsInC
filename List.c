#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
List *CreateList(){
	List * list=(List *)malloc(sizeof(List));
	list->list=malloc(0);
	list->types=malloc(0);
	list->length=0;
	return list;
}

void append(List *list,char type,...){
	va_list lista;
	va_start(lista,type);
	if (type=='i'){
		int arg=va_arg(lista,int);
		// Apendizar a el campo list
		list->list=realloc(list->list,sizeof(void *)*(list->length+1));
		list->list[list->length]=malloc(sizeof(int));
		*(int*)list->list[list->length]=arg;
		// Apendizar el campo types
		list->types=realloc(list->types,sizeof(char)*(list->length+1));
		list->types[list->length]=type;
		// Aumentar la longitud
		list->length++;
	}
	else if(type=='c'){
		char arg=(char)va_arg(lista,int);
		// Apendizar a el campo list
		list->list=realloc(list->list,sizeof(void *)*(list->length+1));
		list->list[list->length]=malloc(sizeof(char));
		*(char*)list->list[list->length]=arg;
		// Apendizar el campo types
		list->types=realloc(list->types,sizeof(char)*(list->length+1));
		list->types[list->length]=type;
		// Aumentar la longitud
		list->length++;		
	}
	else if(type=='f'){
		float arg=(float)va_arg(lista,double);
		// Apendizar a el campo list
		list->list=realloc(list->list,sizeof(void *)*(list->length+1));
		list->list[list->length]=malloc(sizeof(float));
		// Apendizar el campo types
		*(float*)list->list[list->length]=arg;
		list->types=realloc(list->types,sizeof(char)*(list->length+1));
		list->types[list->length]=type;
		// Aumentar la longitud
		list->length++;
	}
	else if (type=='d'){
		double arg=va_arg(lista,double);
		// Apendizar a el campo list
		list->list=realloc(list->list,sizeof(void *)*(list->length+1));
		list->list[list->length]=malloc(sizeof(double));
		// Apendizar el campo types
		*(double*)list->list[list->length]=arg;
		list->types=realloc(list->types,sizeof(char)*(list->length+1));
		list->types[list->length]=type;
		// Aumentar la longitud
		list->length++;	
	}
	else if (type=='s'){
		char* arg=va_arg(lista,char *);
		// Apendizar a el campo list
		list->list=realloc(list->list,sizeof(void *)*(list->length+1));
		list->list[list->length]=malloc(sizeof(char *));
		// Apendizar el campo types
		*(char **)list->list[list->length]=arg;
		list->types=realloc(list->types,sizeof(char)*(list->length+1));
		list->types[list->length]=type;
		// Aumentar la longitud
		list->length++;
	}
	va_end(lista);
}

void printlist(List *list){
	printf("[ ");
	for(int i=0;i<list->length;i++){
		if (list->types[i]=='i'){
			printf("%d",*(int *)list->list[i]);
		}
		else if (list->types[i]=='c'){
			printf("%c",*(char *)list->list[i]);
		}
		else if (list->types[i]=='f'){
			printf("%f",*(float *)list->list[i]);
		}
		else if (list->types[i]=='d'){
			printf("%.12f",*(double *)list->list[i]);
		}
		else if (list->types[i]=='s'){
			printf("%s",*(char **)list->list[i]);
		}
		if (i<list->length-1){
			printf(", ");
		}
		if (i%12==0 && i>0){
			printf("\n");
		}
	}
	printf(" ]\n");
}


void freelist(List * list){
	free(list->list);
	free(list->types);
	free(list);
	list->list=NULL;
	list->types=NULL;
	list=NULL;
}