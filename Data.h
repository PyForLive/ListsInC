#ifndef DATA

#define DATA

typedef struct {
	void *data;
	char type;
}Data;

Data CreateData(char type,...);
Data CreateDataByPointer(char type,void * point);
void *getData(Data data);
void setData(Data *data,char type,...);
void printData(Data data);
void writeData(Data data);
void freeData(Data * data);

#endif