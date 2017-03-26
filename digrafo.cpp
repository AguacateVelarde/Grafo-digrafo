#include <iostream>
#include <stdio.h>
#include "cola.h"
#include "pila.h"
#include <stdlib.h>
using namespace std;

template < class type > 
class Grafo{
private: 
	type* dato;
	bool** matrizAdyacente;
	int posGlobal,tam;
public:
	Grafo( int tam ){
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
		int k = 0, l;

		for (int i = 0; i < tam; ++i)
			check[ i ] = false;
		
		
	}


	type* busquedaAnchura(  ){
		cola < int > Cola( tam ); 

	}

	type* recorridoDijsktra(  ){

	}


};

int main (int argc, char *argv[]) {
	int num, inicio, fin;
	int op; 
	int dato;
	int * busquedas; 
	system("color F0"); 
	cout << "GRAFO CON MATRIZ ADYACENTE\n  Leonardo Velarde Andrade" << endl<< endl << endl; 
	cout << "Datos a agregar: ";
	cin >> num;
	while(num<=1){
		cout << "El grafo debe tener al menos 2 vertices...\n Intente de nuevo: ";
		cin >> num;
	}
	
	Grafo<int> test(num);
	system("cls");	
	cout << "Inserte sus datos..."<< endl; 
	for(int i =1; i<= num; i++){
		cout << "Dato " << i << ": ";
		cin >> dato; 
		test.agregaVertice(dato); 
	}
	cout << "Dato insertados exitosamente!!"<< endl;
	system("pause");
	system("cls");
	do{
		cout << "\t M E N U"
			<< "\n1. Insertar Arista"
			<< "\n2. Ver Matriz Adyacente"
			<< "\n3. Ver Aristas"
			<< "\n4. Ver Vertices"
			<< "\n5. Eliminar Arista"
			<< "\n6. Ver grado de un vertice"
			<< "\n7. Ver grado inverso de un vertice"
			<< "\n8. Busqueda por Profundidad"
			<< "\n9. Busqueda por Anchura"
			<< "\n10. Salir"

			<< endl;
		cin >> op;
		switch(op){
		case 1:
			cout << "Vertices: ";
			test.mostrarVertice();
			cout << "Donde inicia: "; 
			cin >> inicio; 
			cout << "Donde termina: ";
			cin >> fin; 
			test.agregaArista(inicio, fin);
			break;
		case 2:
			cout << endl;
			test.mostrarMatrizAdyacente();
			cout << endl << endl;
			break;
		case 3:
			cout << "Donde inicia: "; 
			cin >> inicio; 
			cout << "Donde termina: ";
			cin >> fin; 
			test.mostrarAristas(inicio, fin);
			break;
		case 4:
			test.mostrarVertice(); 
			break; 
		case 5:
			test.mostrarVertice();
			cout << "Donde inicia: "; 
			cin >> inicio; 
			cout << "Donde termina: ";
			cin >> fin; 
			test.eliminarArista(inicio, fin);
			break;
		case 6:
			test.mostrarVertice();
			cout << "Agregue Vertice: ";
			cin >> inicio; 
			cout << "El grado de "<< inicio << " es: " << test.grado(inicio)<< endl;
		break;

		case 7:
		
			test.mostrarVertice();
			cout << "Agregue Vertice: ";
			cin >> inicio; 
			cout << "El grado Inverso de "<< inicio << " es: " << test.gradoInverso(inicio)<< endl;
		break;
		case 8:
			*busquedas = *(test.busquedaProfundidad());
			for (int i = 0; i < sizeof( busquedas ); ++i){
				cout << busquedas [ i ] << " ";
			}
			cout << endl;
		break;
		case 9:
		break;
		case 10: 
			cout<< "saliendo..." << endl;
			op = -1;
			break;
		}
	}while(op!= -1);
	return 0;
}
