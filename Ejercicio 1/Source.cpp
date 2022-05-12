//Escribe una función recursiva para eliminar todos los elementos de una lista.
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

void insertarFinal(Nodo*&, int);
void eliminarLista(Nodo*&, int&);
void listar(Nodo*);

int main(void) {
    Nodo* lista = NULL;

    int dato, cant;
    cout << "Cantidad de datos a ingresar: "; cin >> cant;
    for (int i = 0; i < cant; i++) {
        cout << "Digite un numero: ";
        cin >> dato;
        insertarFinal(lista, dato);
    }

    cout << "Elementos de la lista: " << endl;
    listar(lista);

    cout << "\n\nEliminar elementos";
    eliminarLista(lista, dato);

    cout << "\n\nLista sin elementos: " << endl;
    listar(lista);

    return 0;
}

void insertarFinal(Nodo*& lista, int valor)
{
    Nodo* nuevoNodo, * ultimo;
    nuevoNodo = new Nodo;

    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;  //Final

    if (lista == NULL) {
        lista = nuevoNodo;
    }
    else {
        ultimo = lista;  //empieza en la cabecera

        while (ultimo->siguiente != NULL) {
            ultimo = ultimo->siguiente;
        }

        ultimo->siguiente = nuevoNodo;
    }
}

void eliminarLista(Nodo*& lista, int& pos)
{
    Nodo* actual = lista; // Empieza en la cabecera


    if (actual == NULL) {
        return;
    }

    else {
        pos = actual->dato;                   // Guarda el elemento antes de borrarlo
        lista = actual->siguiente;            // lista empieza en el siguiente dato
        delete actual;
        eliminarLista(lista, pos);
    }

}


void listar(Nodo* lista)
{
    int c;
    Nodo* actual = lista;  //apunta a la cabecera

    if (actual == NULL)
        cout << " ";

    else {
        cout << actual->dato << "  ";
        actual = actual->siguiente; //para actualizar el valor al siguiente
        listar(actual);
        c++;
        cout << "La cantidad de elemteos son:" << c;
    }
}
