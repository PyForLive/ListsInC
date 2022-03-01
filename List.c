#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "List.h"
#include "Data.h"
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

void deleteitem(List * list,int index){
	if (index<0){
		index=list->length-index
	}
	if (index>=length->length||index<0){
		return;
	}
	List * list_new=CreateList();
	for(int i=0;i<=list->length-1;i++){
		if (i==index){
			continue;
		}
		if (list->types[i]=='i'){
			append(list_new,'i',*(int *)list->list[i]);
		}

		if (list->types[i]=='c'){
			append(list_new,'c',*(char *)list->list[i]);
		}

		if (list->types[i]=='f'){
			append(list_new,'f',*(float *)list->list[i]);
		}

		if (list->types[i]=='d'){
			append(list_new,'d',*(double *)list->list[i]);
		}

		if (list->types[i]=='s'){
			append(list_new,'s',*(char **)list->list[i]);
		}
	}
	free(list->list);
	list->list=NULL;
	free(list->types);
	list->types=NULL;
	*list=*list_new;
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

Data getitem(List *list,int index){
	if (index<0){
		index=list->length-index
	}
	if (index>=length->length||index<0){
		return;
	}
	Data data=CreateDataByPointer(list->types[index],list->list[index]);
	return data;
}

void setitem(List * list,int index,char type,...){
	if (index<0){
		index=list->length-index
	}
	if (index>=length->length||index<0){
		return;
	}
	va_list lista;
	va_start(lista,type);
	if (index>=list->length){
		return;
	}
	if (type=='i'){
		list->types[index]=type;
		list->list[index]=malloc(sizeof(int));
		*(int *)list->list[index]=va_arg(lista,int);
	}
	else if (type=='c'){
		list->types[index]=type;
		list->list[index]=malloc(sizeof(char));
		*(char *)list->list[index]=(char)va_arg(lista,int);
	}
	else if (type=='f'){
		list->types[index]=type;
		list->list[index]=malloc(sizeof(float));
		*(float *)list->list[index]=(float)va_arg(lista,double);
	}
	else if (type=='d'){
		list->types[index]=type;
		list->list[index]=malloc(sizeof(double));
		*(double *)list->list[index]=va_arg(lista,double);
	}
	else if (type=='s'){
		list->types[index]=type;
		list->list[index]=malloc(sizeof(char *));
		*(char **)list->list[index]=va_arg(lista,char *);
	}
}

void freelist(List * list){
	free(list->list);
	list->list=NULL;
	free(list->types);
	list->types=NULL;
	list->length=0;
	free(list);
	list=NULL;
	
}