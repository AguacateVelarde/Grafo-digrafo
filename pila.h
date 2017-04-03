#include <iostream>
using namespace std;

template <class type>
class pila{
public:
	pila( int );
	void push( type );
	type pop();
	void show();
	int getTop();
	bool empty();
	bool vacia();




	private:
		type *container;
		int tam;
		int top;



};
template < class type>
int pila< type >::getTop(){
	return top;

}
template < class type >
bool pila<type>::vacia(){
	return ( top == -1 );
}

template < class type>
bool pila<type>::empty(){
	return (top == ( tam - 1 ) );
}

template <class type>
pila<type>::pila( int tam ){
	top = -1;
	this -> tam = tam;
	container = new type[tam];
}

template <class type>
void pila<type>::push( type data ){
	if ( !empty() ){
		top++;
		container[top] = data;
		cout << "Dato agregado" << endl;
	}else{
		cout << "Ya no hay espacio en la pila :("<< endl;
	}
}

template <class type>
type pila<type>::pop(){
	if ( !vacia() ){
		cout << "El elemento que hizo pop fue: " << container[top]<< endl;
		top--;
	}else{
		cout << "Pila vacia :(" << endl;
	}
}
template<class type>
void pila<type>::show(){
	for (int i = top; i >= 0; i--){
		cout << "Value "<< i << ": "<< container[i] << endl;
	}
}
