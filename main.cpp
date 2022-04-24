#include <iostream>
#include <string>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo {
    int dato;
    Nodo* der;
    Nodo* izq;
    Nodo* padre;
    string nombre;
    float ahorro;
};

//Prototipos
void menu();

Nodo* crearNodo(int, Nodo*);
Nodo* crearNodo(int, Nodo*, string, float);
void insertarNodo(Nodo*&, int, Nodo*, string nombre, float ahorro);
void mostrarArbol(Nodo*, int);
bool busqueda(Nodo*, int);
void preOrden(Nodo*);
void inOrden(Nodo*);
void postOrden(Nodo*);
void eliminar(Nodo*, int);
void eliminarNodo(Nodo*);
Nodo* minimo(Nodo*);
void reemplazar(Nodo*, Nodo*);
void destruirNodo(Nodo*);
Nodo* busq(Nodo* arbol, int n);
void  AhorroMinimo(Nodo* arbol, int Min, int&);
void  AhorroMaximo(Nodo* arbol, int Max, int&);
Nodo* busquedaNodo(Nodo* arbol, int id);

Nodo* arbol = NULL;

int main() {
    menu();
    _getch();
    return 0;
}

//Funcion de menu
void menu() {
    int dato, opcion, contador = 0;
    string nombre;
    float ahorro;
    Nodo* NodoEncontrado = NULL;
    do {
        cout << "\t.:MENU: ." << endl;
        cout << "l. Insertar un nuevo nodo" << endl;
        cout << "2. Mostrar el arbol completo" << endl;
        cout << "3. Buscar un elemento en el arbol" << endl;
        cout << "4. Recorrer el arbol en PreOrden" << endl;
        cout << "5. Recorrer el arbol en InOrden" << endl;
        cout << "6. Recorrer el arbol en PosOrden" << endl;
        cout << "7. Eliminar un nodo del arbol" << endl;
        cout << "8. Mostrar Ahorro minimo" << endl;
        cout << "9. Mostrar Ahorro maximo" << endl;
        cout << "10. Salir\n" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                system("cls");
                cout << "\t .:. INSERTAR DATOS EN EL NODO .:." << endl;
                cout << "\nDigite un numero: ";
                cin >> dato;
                cout << "\nIngrese un nombre: ";
                cin >> nombre;
                cout << "\nIngrese ahorro: ";
                cin >> ahorro;
                insertarNodo(arbol, dato, NULL, nombre, ahorro); //Insertamos un nuevo nodo
                cout << "\n";
                //system("pause");
                break;
            case 2:
                system("cls");
                cout << "\t .:. MOSTRAR ARBOL COMPLETO .:.\n\n" << endl;
                mostrarArbol(arbol, contador); //Insertamos un nuevo nodo
                cout << "\n";
                system("pause");
                break;
            case 3:
                system("cls");
                cout << "\t .:. BUSCAR UN ELEMENTO EN EL ARBOL .:." << endl;
                cout << "\nDigite el elemento a buscar: ";
                cin >> dato;
                if (busqueda(arbol, dato) == true) {
                    cout << "\nElemento " << dato << ":" << nombre << " a sido encontrado en el arbol\n";
                }
                else {
                    cout << "\nElemento no encontrado\n";
                }
                cout << "\n";
                system("pause");
                break;
            case 4:
                system("cls");
                cout << "\t .:. RECORRIDO EN PREORDEN .:." << endl;

                preOrden(arbol);
                cout << "\n\n";
                system("pause");
                break;
            case 5:
                system("cls");
                cout << "\t .:. RECORRIDO EN INORDEN .:." << endl;

                inOrden(arbol);
                cout << "\n\n";
                system("pause");
                break;
            case 6:
                system("cls");
                cout << "\t .:. RECORRIDO EN POSTORDEN .:." << endl;

                postOrden(arbol);
                cout << "\n\n";
                system("pause");
                break;
            case 7:
                system("cls");
                cout << "\t .:. ELIMINAR UN NODO DE UN ARBOL .:." << endl;
                cout << "\nDigite el numero a eliminar: ";
                cin >> dato;
                eliminar(arbol, dato);
                cout << "\n\n";
                system("pause");
                break;
            case 8:
                system("cls");
                cout << "\t .:. MOSTRAR AHORRO MINIMO .:." << endl;
                int id;
                AhorroMinimo(arbol, 9999, id);
                cout << "" << endl;
                cout << id << "| ";
                Nodo* nn;
                nn = busquedaNodo(arbol, id);
                cout << nn->nombre << ", " << nn->ahorro << " (s/)" << endl;

                system("pause");
                break;
            case 9:
                system("cls");
                cout << "\t .:. MOSTRAR AHORRO MAXIMO .:." << endl;
                int idt;
                AhorroMaximo(arbol, 0, idt);
                cout << idt << "| ";
                Nodo* mm;
                mm = busquedaNodo(arbol, idt);
                cout << mm->nombre << ", " << mm->ahorro << " (s/)" << endl;


                system("pause");
                break;
        }
        system("cls");
    } while (opcion != 10);
}

//funcion para crear un nuevo nodo
Nodo* crearNodo(int n, Nodo* padre, string nombre, float ahorro) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;
    nuevo_nodo->nombre = nombre;
    nuevo_nodo->ahorro = ahorro;
    return nuevo_nodo;
}

Nodo* crearNodo(int n, Nodo* padre) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;
    return nuevo_nodo;
}

//Función para insertar eLementos en eL arboL
void insertarNodo(Nodo*& arbol, int n, Nodo* padre, string nombre, float ahorro) {
    if (arbol == NULL) { //Si e¿ arboL esta vacio
        Nodo* nuevo_nodo = crearNodo(n, padre, nombre, ahorro);
        arbol = nuevo_nodo;
    }
    else { //Si eL arboL tiene un nodo o mas
        int valorRaiz = arbol->dato; //Obtenemos eL vaLor de La raíz
        if (n < valorRaiz) { //Si eL eLemento es menor a La raiz, insertamos en izq
            insertarNodo(arbol->izq, n, arbol, nombre, ahorro);
        }
        else {//Si el eLemento es mayor a La raíz, insertamos en der
            insertarNodo(arbol->der, n, arbol, nombre, ahorro);
        }
    }
}

//Funcion para mostrar el arbol completo
void mostrarArbol(Nodo* arbol, int cont) {
    if (arbol == NULL) { //Si eL arboL esta vacio
        return;
    }
    else {
        mostrarArbol(arbol->der, cont + 1);
        for (int i = 0; i < cont; i++) {
            cout << "     ";
        }
        cout << arbol->dato << endl;
        for (int i = 0; i < cont; i++) {
            cout << "     ";
        }
        cout << arbol->nombre << "|" << arbol->ahorro << endl;
        mostrarArbol(arbol->izq, cont + 1);
    }
}

//Funcion para Buscar un elemento en el arbol
bool busqueda(Nodo* arbol, int n) {
    if (arbol == NULL) { //si el arbol esta vacio
        return false;
    }
    else if (arbol->dato == n) { //si el nodo es igual al elemento
        return true;
    }
    else if (n < arbol->dato) {
        return busqueda(arbol->izq, n);
    }
    else {
        return busqueda(arbol->der, n);
    }
}

//Funcion para recorrido en profundidad - PreOrden
void preOrden(Nodo* arbol) {
    if (arbol == NULL) { //Si el arbol esta vacio
        return;
    }
    else {
        cout << arbol->nombre << " : " << arbol->ahorro << "|";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

//Funcion para recorrido en profundidad - InOrden
void inOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        inOrden(arbol->izq);
        cout << arbol->nombre << " : " << arbol->ahorro << "|";
        inOrden(arbol->der);
    }
}

//Funcion para recorrido en profundidad - PostOrden
void postOrden(Nodo* arbol) {
    if (arbol == NULL) { //si el arbol esta vacio
        return;
    }
    else {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->nombre << " : " << arbol->ahorro << "|";
    }
}

//Funcion Eliminar un nodo del arbol
void eliminar(Nodo* arbol, int n) {
    if (arbol == NULL) { //Si el arbol esta vacio
        return; //No haces nada
    }
    else if (n < arbol->dato) { //Si el valor es menor
        eliminar(arbol->izq, n); //Busca por la izquierda
    }
    else if (n > arbol->dato) {//Si el valor es mayor
        eliminar(arbol->der, n); //Buscar por la derecha
    }
    else { //Si ya encontraste el valor del nodo
        eliminarNodo(arbol);
    }
}

//Funcion para determinar el nodo mas izq posible
Nodo* minimo(Nodo* arbol) {
    if (arbol == NULL) { //Si el arbol esta vacio
        return NULL; //retorna nulo
    }
    if (arbol->izq) { //Si tiene hijo izq
        return minimo(arbol->izq);//buscamos la parte mas izq posible
    }
    else { //Si no tiene hijo izq
        return arbol; //retornamos el mismo nodo
    }
}

//Funcion para remplazar dos nodos
void reemplazar(Nodo* arbol, Nodo* nuevoNodo) {
    if (arbol->padre) {
        //arbol->padre hay que asignarle su nuevo hijo
        if (arbol->dato == arbol->padre->izq->dato) {
            arbol->padre->izq = nuevoNodo;
        }
        else if (arbol->dato == arbol->padre->der->dato) {
            arbol->padre->der = nuevoNodo;
        }
    }
    if (nuevoNodo) {
        //Procedemos a asignarle su nuevo padre
        nuevoNodo->padre = arbol->padre;
    }
}

//Funcion para destruir un nodo
void destruirNodo(Nodo* nodo) {
    nodo->izq = NULL;
    nodo->der = NULL;
    delete nodo;
}

//Funcion para eliminar el nodo encontrado
void eliminarNodo(Nodo* nodoEliminar) {
    if (nodoEliminar->izq && nodoEliminar->der) { //Si el nodo tiene hijo izq y hijo der
        Nodo* menor = minimo(nodoEliminar->der);
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    }
    else if (nodoEliminar->izq) { //Si tiene hijo izq
        reemplazar(nodoEliminar, nodoEliminar->izq);
        destruirNodo(nodoEliminar);
    }
    else if (nodoEliminar->der) { //Si tiene hijo der
        reemplazar(nodoEliminar, nodoEliminar->der);
        destruirNodo(nodoEliminar);
    }
    else {//Si un nodo no tiene hijos entonces es una hoja
        reemplazar(nodoEliminar, NULL);
        destruirNodo(nodoEliminar);
    }
}

void  AhorroMinimo(Nodo* arbol, int Min, int& id) {
    if (arbol == NULL) {
        return;
    }
    else {
        if (arbol->ahorro < Min) {
            Min = arbol->ahorro;
            id = arbol->dato;
        }
        AhorroMinimo(arbol->izq, Min, id);
        AhorroMinimo(arbol->der, Min, id);
    }
}
void  AhorroMaximo(Nodo* arbol, int Max, int& idt) {
    if (arbol == NULL) {
        return;
    }
    else {
        if (arbol->ahorro > Max) {
            Max = arbol->ahorro;
            idt = arbol->dato;
        }
        AhorroMaximo(arbol->izq, Max, idt);
        AhorroMaximo(arbol->der, Max, idt);
    }
}

//Busqueda de Nodo
Nodo* busquedaNodo(Nodo* arbol, int id) {
    if (arbol == NULL) { //si el arbol esta vacio
        return NULL;
    }
    else if (arbol->dato == id) { //si el nodo es igual al elemento
        return arbol;
    }
    else if (id < arbol->dato) {
        return busquedaNodo(arbol->izq, id);
    }
    else {
        return busquedaNodo(arbol->der, id);
    }
}