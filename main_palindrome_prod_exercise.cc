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
// LINEA PARA COMPILAR: g++ -std=c++14 -g -Wall -o palindrome_prod_exercise main_palindrome_prod_exercise.cc palindrome_prod.cc

#include <iostream>
#include <fstream>
#include "palindrome_prod.h"
using namespace std;

int main (int argc, char *argv[]) {
  if (argc != 4) {
    cout << "This program reads numbers from a file,";
    cout << " searches for palindromic numbers and writes them to a file if ";
    cout << "they are a result of the product between two numbers";
    cout << " of a given number of digits." << endl;
    cout << "Usage: ./palindrome_prod_exercise n InputFile OutputFile" << endl;
  } else {
    Cifra Valores(atoi(argv[1]));
    ifstream fichero_entrada(argv[2]);
    ofstream fichero_salida(argv[3]);
    int numero_actual_uno = Valores.get_cifra_limite_inferior();
    int numero_final = Valores.get_cifra_limite_superior();
    while (numero_actual_uno <= numero_final) {
      int numero_actual_dos = numero_actual_uno;
      while (numero_actual_dos <= numero_final) {
        int resultado = 0;
        resultado = numero_actual_uno * numero_actual_dos;
        if (Valores.Capicua(resultado)) {
          // Comparar con numeros del archivo de entrada
          // Volver al inicio del fichero
          fichero_entrada.seekg(0, fichero_entrada.beg); 
          while ( !fichero_entrada.eof()) {
            char char_del_numero[100];
            fichero_entrada >> char_del_numero;
            int int_del_numero = atoi(char_del_numero);
            if (resultado == int_del_numero) {
              fichero_salida << numero_actual_uno << " * " 
            << numero_actual_dos << " = " << resultado << endl;
            }
          }
        }
        numero_actual_dos++;
      }
      numero_actual_uno++;  
    }
    fichero_salida.close();
    fichero_entrada.close();
    // mostrar lo que hay en el fichero de salida
    int elementos_por_linea = 5;
    int elementos_mostrados = 0;
    ifstream lectura_fichero_salida(argv[3]); 
    char cadena_de_texto[150];
    cout << "Contenido de " << argv[3] << endl;
    while ( !lectura_fichero_salida.eof()) {
      ++elementos_mostrados;
      lectura_fichero_salida >> cadena_de_texto;
      cout << cadena_de_texto << " ";
      if (elementos_mostrados == elementos_por_linea) {
        cout << endl;
        elementos_mostrados = 0;
      }
    }
    lectura_fichero_salida.close();
  }
  return 0;
}