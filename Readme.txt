Hola a todos.
List es un tipo de dato definido por el programador.
Cual tiene varios metodos en el cual dejare la descripcion de cada uno.

List esta definido como sigue
"
typedef struct {
	void ** list;
	char * types;
	int length;
}List;
"
CAMPOS:
	
	campo list:
		El campo list , como ves es un puntero a puntero void. 
		Seguro estas diciendo, porque este PySemos se complica tanto la vida definiendo puntero a puntero y todo eso.
		Bueno la primera referencia o sea el puntero que apunta a otro puntero va a apuntar a nada mas y nada menos
		que a a la primera posicion de un bloque contiguo de memoria y esa primera posicion de memoria a la vez sera
		un puntero a void que apuntara hacia el valor de ese elemento que puede ser entero,float,double,char o char * (string),
		En otras palabras el campo list sera un arreglo de punteros a void (areglo dinamico), donde cada puntero void apuntara 
		hacia el valor de el elemento que esta almacenada en esa posicion.

	campo types:
		El campo types, como lo ves es un puntero a char.
		En otras palabras un string para muchos lenguajes modernos de alto nivel.
		En donde en ese string se almacenara en la i-esima posicion el tipo de dato al que  apunta el puntero void
		de la i-esima posicion del campo list.Se que esta un poquito complicadito.He aqui un ejemplo.

		Supongamos que tenemos una lista que tiene 5 elementos.

		elementos=5,"Juanito","La Habana",0345609234,"Calle tal entre no se y no quien numero pi"

		por tanto el string types quedaria asi.
		"issis"
		osea la i representa un int, y la s un string (char *), Vaya hacia el final de la documentacion para documentarse mas
		sobre estos metacaracteres.

	campo length:
		Y por supuesto no podia faltar el campo length, muy importante por cierto para el funcionamiento interno de
		List.
		length ya lo dice longitud, longitud de que bueno length es un entero que almacenara cuantos elementos estan
		almacenados en la lista.

ADVERTENCIA:
	Nada se declara como List, se declara como List *. O sea puntero a List.

METODOS:
	CreateList:
		List * CreateList();
		Bien esta es la funcion principal y es porque nada se declara como List sino como List*.
		CraeteList como ya lo dice crea una lista pero como lo ves en la definicion
		
		List * CreateList()
		^^^^^^
		||||||

		devuelve un puntero no una lista, porque te estaras preguntando, porque lo que hace es pedir memoria dinamica al sistema operativo,
		por lo tanto estas trabajando con un puntero que el sistema operativo te deevolvio en el cual habia memoria disponible.
		Pero no te preocupes trabajar con puntero o con estructura no se va a sentir la diferencia practicamente todo lo que vayas hacer con la lista lo haras a partir de la API que te proporciono apendizar,borrar elemento, imprimir, etc.

		Por lo tanto para crear una lista debes hacerlo asi:

		List * name_list=CreateList();

	append:
		Esta definido de la siguiente manera void append(List * list,char type,...);.
		append como ya lo dice append aniade al final o apendiza como lo quieras llamar un nuevo elemento.

		Argumento list => Un puntero a List (Ya Createlist te devuelv e ese puntero que es el que necesito)
		Argumento type => Es un metacaracter definido de los de abajo, si no es ninguno de esos no hace nada
		Argumento ... => Un argumento variable el cual depende del type que le des si le das 'i' en type entonces ... debe
		ser un entero y asi.(Para mas informacion de los metacaracteres vaya abajo de la documentacion).

	deletitme:
		Esta definido de la siguiente manera void deleteitem(List * list,int index);.
		deletitem elimina el index-esimo elemento en list (puede ser negativo en ese caso te referiras contando desde atras o sea
		si tienes 5 elementos e index le das el valor -1 borrarias el primer elemento del list contando desde atras o sea en este caso borrarias el ultimo elemento).
	printlist:
		void printlist(List *list);
		Simplemente imprime la lista;
		OJO si quieres imprimir y ver como va tu lista, por favor no lo hagas manual, te complicarias mucho mejor utiliza este metodo.

	getitem:
		
		Este metodo te devolvera el index-esimo elemento de la lista, esta definido asi:
			Data getitem(List *list,int index);
			^^^^
			||||
		Data esta definido de la siguiente forma

		typedef struct {
			void *data;
			char type;
		}Data;

		Devolvera getitem un data, porque te preguntas por cuestiones de desarrollo,
		Abajo antes de llegar a los Metacaracteres esta la definicion que lleva y los metodos de la API para Data.

	setitem:
		Este metodo esta definido asi:
			void setitem(List * list,int index,char type,...);

		este metodo el elemento index-esimo lo cambia al valor del elemento que pases a ...;
		type sera un metacaracter que describira que tipo de elemento le pasaras a ...


	freelist:

		Esta definido asi:
			void freelist(List * list);
		OJO al terminar de trabajar con List, llama a este metodo con su respectivo argumento.
		Si no lo haces se te creara en la DRAM un lago de memoria, o sea esta memoria dinamica dada a List, se te quedara ahi en la memoria
		sin hacer nada a menos que reinicies la maquina.


DATA
	Data esta definido asi:
	
	
	typedef struct {
		void *data;
		char type;
	}Data;

	el campo data apuntara al elemento que sea puede ser una struct un dato primitivo otro puntero lo que sea.
	type es un metacaracter que limita a Data a apuntar solo a datos primitivos.
	(Vea abajo la documentacion de los Metacaracateres)

	METODOS:
		CreateData:
			Data CreateData(char type,...);
			Argumento type => Metacaracter que indica el tipo de el elemento
			Argumento ... => Elemento de tipo type
		printData:
			definido como void printData(Data data);
			solo imprime por pantalla el valor al cual el puntero del campo data apunta y un salto de linea.
		writeData:
			definido como void writeData(Data data);
			solo imprime por pantalla el valor al cual el puntero del campo data apunta.
		getData:
			definido como void *getData(Data data);
			devuelve un el campo data de el argumento data
		setData:
			definido como void setData(Data *data,char type,...);
			data es un puntero a Data.
			type es un metacaracter que describe de que tipo sera el elemento que le des en ...
			entonces el puntero en el campo data de la desreferencia de lo que apunte el argumento data, su valor
			sera ahora ... y tipo type.
		freeData:
			definido como void freeData(Data * data);
			libera el espacio en memoria de el argumento data;



Metacaracteres:
	'i' => int
	'c' => char
	'f' => float
	'd' => double
	's' => string (char *)


En un futuro esta libreria pienso aumentar los metacaracteres y la logica para que se puedan guardar mas cosas aparte de solo datos primitivos, Si desea participar en el proyecto estoy en WhatsApp +5355041213 o en celsomoises629@gmail.com


























