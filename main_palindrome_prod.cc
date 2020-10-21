// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTORA: Helena García Díaz
// FECHA: 15-10-2020
// E-MAIL: alu0100829150@ull.edu.es
// ASIGNATURA: Computabilidad y Algoritmia
// PRACTICA: P03
// url de informacion: https://es.wikipedia.org/wiki/Pal%C3%ADndromo
// ESTE PROGRAMA:
// Recibe un numero n
// Muestra por pantalla los numeros primos entre 1 y N
// LINEA DE EJECUCION: ./palindrome_prod n output.txt
// LINEA PARA COMPILAR: g++ -std=c++14 -g -Wall -o palindrome_prod main_palindrome_prod.cc palindrome_prod.cc

#include <iostream>
#include <fstream>
#include "palindrome_prod.h"
using namespace std;

int main (int argc, char *argv[]) {
  if (argc != 3) {
    if ((argc > 1) && (string (argv[1]) == "--help")) {
      cout << "Modo de empleo: ./palindrome_prod [NUMERO_ENTERO] [FICHERO]";
      cout << endl;
      cout << "Guarda en [FICHERO] aquellos productos de dos numeros de";
      cout << " [NUMERO_ENTERO] digitos, cuyos resultados sean capicúas.";
      cout << endl;
    } else {
      cout << "Opcion incorrecta" << endl;
      cout << "Pruebe './palindrome_prod --help' para mas informacion" << endl;
    }
  } else {
    Cifra Valores(atoi(argv[1]));
    ofstream fichero_salida(argv[2]);
    int numero_actual_uno = Valores.get_cifra_limite_inferior();
    int numero_final = Valores.get_cifra_limite_superior();
    while (numero_actual_uno <= numero_final) {
      int numero_actual_dos = numero_actual_uno;
      while (numero_actual_dos <= numero_final) {
        int resultado = 0;
        resultado = numero_actual_uno * numero_actual_dos;
        if (Valores.Capicua(resultado)) {
          fichero_salida << numero_actual_uno << " * " 
          << numero_actual_dos << " = " << resultado << endl;
        }
        numero_actual_dos++;
      }
      numero_actual_uno++;  
    }
    fichero_salida.close();
  }
  return 0;
}