#include <iostream>
using namespace std;

// Clase que representa un nodo del arbol
class Nodo {
public:
    char operador;
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;

    // Constructor para numeros
    Nodo(int v) {
        valor = v;
        operador = '\0';
        izquierdo = nullptr;
        derecho = nullptr;
    }

    // Constructor para operadores
    Nodo(char op, Nodo* izq, Nodo* der) {
        operador = op;
        valor = 0;
        izquierdo = izq;
        derecho = der;
    }

    // Evalua recursivamente el arbol
    int evaluar() {
        // Si no tiene hijos, es un numero
        if (izquierdo == nullptr && derecho == nullptr) {
            return valor;
        }

        int valorIzq = izquierdo->evaluar();
        int valorDer = derecho->evaluar();

        if (operador == '+') {
            return valorIzq + valorDer;
        }

        if (operador == '*') {
            return valorIzq * valorDer;
        }

        return 0;
    }
};

int main() {

    // Hojas del arbol
    Nodo* n54 = new Nodo(54);
    Nodo* n5  = new Nodo(5);
    Nodo* n34 = new Nodo(34);
    Nodo* n1  = new Nodo(1);
    Nodo* n2  = new Nodo(2);

    // Operaciones de multiplicacion
    Nodo* mult1 = new Nodo('*', n5, n34);
    Nodo* mult2 = new Nodo('*', n1, n2);

    // Suma de las multiplicaciones
    Nodo* suma2 = new Nodo('+', mult1, mult2);

    // Raiz del arbol
    Nodo* raiz = new Nodo('+', n54, suma2);

    cout << "Expresion: 54 + 5 * 34 + 1 * 2" << endl;
    cout << "Resultado: " << raiz->evaluar() << endl;

    // Liberar memoria
    delete raiz;
    delete suma2;
    delete mult1;
    delete mult2;
    delete n54;
    delete n5;
    delete n34;
    delete n1;
    delete n2;

    return 0;
}