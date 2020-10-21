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

// Solo definiciones
#include <iostream>
// #include "palindrome_prod.cc" // mirar si esto hay que incluirlo
using namespace std;

class Cifra {
 public:
  Cifra(const int = 0);
  Cifra(const Cifra&);
  ~Cifra();

  // Setters
  void set_cantidad_cifras(const int);
  // Getters
  int get_cantidad_cifras() const;
  int get_cifra_limite_inferior() const;
  int get_cifra_limite_superior() const;
  // Funciones
  bool Capicua(const int);
 private:
  int cantidad_cifras_;
  int cifra_limite_inferior_;
  int cifra_limite_superior_;

  void Build(void);
  void Destroy(void);
};
