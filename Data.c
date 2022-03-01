#include "Data.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>


Data CreateDataByPointer(char type,void * point){
	if (type=='i'){
		return CreateData(type,*(int *)point);
	}
	else if (type=='c'){
		return CreateData(type,*(char *)point);
	}
	else if (type=='f'){
		return CreateData(type,*(float*)point);
	}
	else if (type=='d'){
		return CreateData(type,*(double *)point);
	}
	else if (type=='s'){
		return CreateData(type,*(char **)point);
	}
	else {
		return CreateData('i',0);
	}
}

Data CreateData(char type,...){
	va_list list;
	va_start(list,type);
	if (type=='i'){
		int arg=va_arg(list,int);
		Data * data=(Data *)malloc(sizeof(Data));
		data->data=malloc(sizeof(int));
		*(int *)data->data=arg;
		data->type=type;
		va_end(list);
		return *data;
	}
	else if (type=='c'){
		char arg=(char)va_arg(list,int);
		Data * data=(Data *)malloc(sizeof(Data));
		data->data=malloc(sizeof(char));
		*(char *)data->data=arg;
		data->type=type;
		va_end(list);
		return *data;
	}
	else if (type=='f'){
		float arg=(float)va_arg(list,double);
		Data * data=(Data *)malloc(sizeof(Data));
		data->data=malloc(sizeof(float));
		*(float *)data->data=arg;
		data->type=type;
		va_end(list);
		return *data;
	}
	else if (type=='d'){
		double arg=va_arg(list,double);
		Data * data=(Data *)malloc(sizeof(Data));
		data->data=malloc(sizeof(double));
		*(double *)data->data=arg;
		data->type=type;
		va_end(list);
		return *data;
	}
	else if (type=='s'){
		char * arg=va_arg(list,char *);
		Data * data=(Data *)malloc(sizeof(Data));
		data->data=malloc(sizeof(char *));
		*(char **)data->data=arg;
		data->type=type;
		va_end(list);
		return *data;
	}
	else{
		return CreateData('i',0);

	}

}
void *getData(Data data){
	return data.data;
}
void setData(Data *data,char type,...){
	va_list list;
	va_start(list,type);
	if (type=='i'){
		int arg=va_arg(list,int);
		*(int *)data->data=arg;
		data->type=type;
	}
	else if (type=='c'){
		char arg=(char)va_arg(list,int);
		*(char *)data->data=arg;
		data->type=type;
	}
	else if (type=='f'){
		float arg=(float)va_arg(list,double);		
		*(float *)data->data=arg;
		data->type=type;
	}
	else if (type=='d'){
		double arg=va_arg(list,double);
		*(double *)data->data=arg;
		data->type=type;
	}
	else if (type=='s'){
		char * arg=va_arg(list,char *);
		*(char **)data->data=arg;
		data->type=type;
	}
	else {
		va_end(list);	
		return;
	}
	va_end(list);
}

void printData(Data data){
	if (data.type=='i'){
		printf("%d\n",*(int *)data.data);
	}
	else if(data.type=='c'){
		printf("%c\n",*(char *)data.data);
	}
	else if(data.type=='f'){
		printf("%f\n",*(float*)data.data);
	}
	else if(data.type=='d'){
		printf("%.12f\n",*(double*)data.data);
	}
	else if(data.type=='s'){
		printf("%s\n",*(char **)data.data);
	}
	else{
		return;
	}
}

void writeData(Data data){
	if (data.type=='i'){
		printf("%d",*(int *)data.data);
	}
	else if(data.type=='c'){
		printf("%c",*(char *)data.data);
	}
	else if(data.type=='f'){
		printf("%f",*(float*)data.data);
	}
	else if(data.type=='d'){
		printf("%.12f",*(double*)data.data);
	}
	else if(data.type=='s'){
		printf("%s",*(char **)data.data);
	}
	else{
		return;
	}
}

void freeData(Data * data){
	free(data->data);
	data->type='?';
	return;
}

