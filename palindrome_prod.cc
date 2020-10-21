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

#include "palindrome_prod.h"

// Constructor
// Recibe una cantidad y en funcion de ella determina el resto de atributos
Cifra::Cifra(const int KDigitos):cantidad_cifras_(KDigitos) {
  Build();
};

// Destructor
Cifra::~Cifra() {
  Destroy();
};

// Crea el elemento de la clase
void Cifra::Build() {
  int digitos = 1; // La cantidad de cifras mínima posible es 1
  cifra_limite_inferior_ = 1;
  cifra_limite_superior_ = 9; 
  while (digitos < cantidad_cifras_) {
    cifra_limite_inferior_ = cifra_limite_inferior_ * 10;
    cifra_limite_superior_ = (cifra_limite_superior_ * 10) + 9;
    digitos++;
  }
};

// Destruye el elemento de la clase
void Cifra::Destroy() {
  cantidad_cifras_  = 0;
  cifra_limite_inferior_ = 0;
  cifra_limite_superior_ = 0;
};

// Recibe un nuevo valor para un atributo
// Reconstruye los atributos que se ven modificados
void Cifra::set_cantidad_cifras(const int kDigitoNuevo) {
  Destroy();
  cantidad_cifras_ = kDigitoNuevo;
  Build();
};

// // Devuelve un atributo  
int Cifra::get_cantidad_cifras() const {
  return cantidad_cifras_;
};

// // Devuelve un atributo 
int Cifra::get_cifra_limite_inferior() const {
  return cifra_limite_inferior_;
};

// Devuelve un atributo 
int Cifra::get_cifra_limite_superior() const {
  return cifra_limite_superior_;
};

// Recibe una cifra
// Si es capicúa devuelve 1
// Si no es capicua devuelve 0
bool Cifra::Capicua(const int KNumero) {
  int resto = 0, inverso = 0;
  bool capicua = false;
  int copia_numero = KNumero;
  while (copia_numero >= 1) {
    resto = copia_numero % 10; // poner nombre constante
    copia_numero = copia_numero /10;
    inverso = inverso * 10 + resto;
  }
  if (inverso == KNumero) {
    capicua = true;
  } else {
    capicua = false;
  }
  return capicua;
};