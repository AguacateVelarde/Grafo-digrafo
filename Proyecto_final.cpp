#include "grafo.h"
#include "digrafo.h"

int main(int argc, char const *argv[]) {
  std::int opcion;
  do{
    std::cout << "1. Grafo"
              << "2. Digrafo "
              << "3. Salir "
              << '\n';
            std::cin >> opcion;

    switch( opcion ){
      case 1:

      break;
      case 2:
      
      break;
      case 3:
        opcion = -1;
      break;


    }
  }while( opcion != -1 )




  return 0;
}
