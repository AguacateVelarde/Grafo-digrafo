#include <iostream>
using namespace std;

template < class type>
class cola{
public:
	cola( int );
	void add( type );
	type extract();
	void show();
	bool empty();
private:
	type *container;
	int tam;
	int last;


	bool llena();
};

template < class type>
cola<type>::cola( int tam ){
	this -> tam = tam;
	container = new type[tam];
	last = 0;
}

template <class type>
bool cola<type>::empty(){
	return ( !last );
}

template <class type>
bool cola<type>::llena(){
	return ( last == tam );
}

template <class type>
void cola<type>::add( type data ){
	if ( !llena() ){
		container[last] = data;
		last++;
	}else{
		cout << "Cola llena :("<< endl;
	}
}

template <class type>
type cola<type>::extract(){
	type buffer;
	if ( !empty() ){
		buffer = container[0];
		for (int i = 0; i < last-1; ++i){
			container[i] = container[i+1];
		}
		last--;
		// cout << "El ultimo elemento es: " << buffer << endl;
		return buffer;
	}else{
		cout << "La cola esta vacia :((((" << endl;
		return 0;
	}

}

template <class type>
void cola<type>::show(){
	for (int i = 0; i < last; ++i){
		cout << "Value: "<< container[i] << endl;
	}
}
