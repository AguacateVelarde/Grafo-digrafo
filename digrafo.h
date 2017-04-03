#include <iostream>
#include <stdio.h>
#include "cola.h"
#include "pila.h"
#include <stdlib.h>
using namespace std;

template < class type >
class Digrafo{
private:
	type* dato;
	bool** matrizAdyacente;
	int posGlobal,tam;
public:
	Digrafo( int tam ){
		this -> tam = tam;
		dato = new type[tam];
		matrizAdyacente = new bool*[tam];
		//for(int i =0; i<tam; i++){
			for(int j = 0; j< tam; j++){
				matrizAdyacente[j] = new bool[tam];
			}
		//}
			for(int i =0; i<tam; i++){
			for(int j = 0; j< tam; j++){
				matrizAdyacente[i][j] = false;
			}
			}
		posGlobal = 0;
	}

	bool lleno(  ){
		if(matrizAdyacente == NULL) return true;
		else return false;
	}

	void mostrarMatrizAdyacente(  ){
		if(!lleno()){
		for(int i = 0; i < tam; i++){
			for(int j = 0; j< tam; j++){
				cout << " " << matrizAdyacente[i][j] << " ";
			}cout << endl;
		}}else{
			cout << "Matriz sin conexiones..."<< endl << endl;
		}
	}

	bool verticesVacios(){
		if(posGlobal == 0)return true;
		else return false;
	}

	void mostrarVertice(){
		if(!verticesVacios()){
		for(int i = 0; i<tam; i++){
			cout << dato[i] << " ";
		}
		cout << endl<< endl;
		}else{
			cout<< "No ha insertado ningun vertice..." << endl << endl;
		}
	}

	void mostrarAristas( type inicio, type fin ){
		int aux = buscarPosicion(inicio);
		int aux1 = buscarPosicion(fin);

		if(aux == -1 || aux1 == -1){
			cout<< "No existen los vertices que agrego" << endl<< endl << endl;
			return;}

			if(matrizAdyacente[aux][aux1]){
				cout << inicio << " | " << fin << endl;
			}else{
				cout << "No esta dirigido " << inicio << " a " << fin<< endl << endl;
			}
	}

	void agregaVertice( type add ){
		if(posGlobal< tam){
		dato[posGlobal] = add;
		posGlobal++; }
		else{
			cout << "Ya no puede agregar mas Vertices" << endl << endl;
		}
	}

	void agregaArista( type inicio, type fin ){
		int aux=buscarPosicion(inicio);
		int aux2=buscarPosicion(fin);

		if(aux == -1 || aux2 == -1){
			cout << "Esos vertices no existen"<< endl << endl;
		return; }
			matrizAdyacente[aux][aux2] = true;
			matrizAdyacente[aux2][aux] = true;
	}

	void eliminarArista( type inicio, type fin ){
		int aux=buscarPosicion(inicio);
		int aux2=buscarPosicion(fin);

		if(aux == -1 || aux2 == -1){
			cout << "Esos vertices no existen"<< endl << endl;
			return; }
		matrizAdyacente[aux][aux2] = false;
	}

	int buscarPosicion( type busca ){
		int aux = 0;
		while(dato[aux]!= busca) aux++;
		if(aux >= tam)return -1;
		else return aux;
	}

	int grado( type data ){
		int position = buscarPosicion(data);
		int count = 0;

		for (int i = 0; i < tam; ++i){
			if( matrizAdyacente[i][position] )
				count++;
		}
		return count;
	}

	int gradoInverso( type data ){
		int position = buscarPosicion( data );
		int count = 0;

		for (int i = 0; i < tam; ++i){
			if ( matrizAdyacente[position][i] )
				count++;
		}
		return count;
	}

	type* busquedaProfundidad(  ){
		pila < type > Pila( tam );
		type* data_return = new type[ tam ] ;
		bool* check = new bool[ tam ];
		int k = 1, l;


		for (int i = 0; i < tam; ++i)
			check[ i ] = false;

		Pila.push( dato[0] );
		check[0] = true;
		cout << dato[ 0 ] << ", ";
		cout << "Al menos entra aquí "<< endl;
		while ( !Pila.empty() ){
			//cout << "Al menos entra aquí 1 "<< endl;
			while( !check[ k ] ){
				Pila.push ( dato[ k ] );
				cout << dato[ k ] << ", ";
				check[ k ] = true;
				l=0;

				while( matrizAdyacente [ k ][ l ] == 0   && k < tam){
					std::cout << "Buscando siguiente k..." << '\n';
					(k == l+1 && l<tam ? l+=2 : l++);
				}
					k = l;
			}


			k = buscarPosicion( Pila.pop() );
		}



	}


	type* busquedaAnchura(  ){
		cola < int > Cola( tam );
		bool* check = new bool[ tam ];
		int _data;
		type* _return = new type[ tam ];
		int cont = 1;


		for (int i = 0; i < tam; ++i)
			check[ i ] = false;


		Cola.add ( dato [ 0 ] );
		check [ 0 ] = true;
		_return [ 0 ] = dato [ 0 ];


	 	while( !Cola.empty( ) ){
			_data = buscarPosicion ( Cola.extract( ) );


			for (int element = 0; element < tam; element++) {
				if ( matrizAdyacente [ _data ][ element ] == 1 && !check [ element ] ){
					Cola.add( dato [ element ] );
					check[ element ] = true;
					_return[ cont ] = dato [ element ];
				}
			}


			if( cont+1 != tam )cont++;else{
				Cola.extract();
			}


		}

return _return;

	}

	type* recorridoDijsktra(  ){

	}


};
