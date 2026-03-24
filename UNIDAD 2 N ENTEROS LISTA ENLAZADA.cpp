//ESTE PROGRAMA PIDE UNA LISTA DE ELEMENTOS AL USUARIO Y SON ALMACENADOS EN UNA LISTA ENLAZADA
//EL PROGRAMA ENCUENTRA EL NUMERO MAYOR Y EL MENOR DE LA LISTA
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <climits> 

using namespace std;

class Node                                  //SE DEFINE LA CLASE NODO       
{
    public:
    int data;
    Node* next;
    Node()                                  // CONSTRUCTOR DE LA CLASE INICIA LAS VARIABLES 
    {
        data = 0;
        next = NULL;
    }
    Node(int data)                          // CONSTRUCTOR CON PARAMETROS
    {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist                            // SE DEFINE LA CLASE LISTA ENLAZADA
{
    public:
    Node* head;
    Linkedlist()                            // COSTRUCTOR DE LA CLASE LISTA ENLAZADA
    {
        head = NULL;
    }
    void insertAtHead(int data)             // FUNCION QUE INSERTA UN NODO EN EL INICIO DE LA LISTA
    {
        Node* newNode = new Node(data);
        if (head == NULL)                   // LA CABEZA DE LA LISTA APUNTA A NULL
        {
            head = newNode;
            return;
        }
        newNode->next = this->head;
        this->head = newNode;
    }
    void print()                            // FUNCION QUE IMPRIME LA LISTA 
    {
        Node* temp = head;
        if (head == NULL)                  // IMPRIME UN MENSAJE SI LA LISTA ESTA VACIA
        {
            cout << "***LA LISTA ESTA VACIA***"<<'\n'<<endl;
            return;
        }
        while (temp != NULL)               // RECORRE TODA LA LISTA
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<'\n'<<endl;
    }
    void maxmin ()                          // FUNCION QUE BUSCA EL MAXIMO Y EL MINIMO DE LA LISTA 
    {
    int min = INT_MAX;
    int max = INT_MIN;
    Node* actual = head;
    while (actual != NULL)
    {
        if (actual->data < min)
        {
            min = actual->data;
        }
        if (actual->data > max)
        {
            max = actual-> data;
        }
        actual = actual-> next;
    }
    cout<<"*EL NUMERO MAYOR DE LA LISTA ES :"<<max<<'\n'<<endl;
    cout<<"*EL NUMERO MENOR DE LA LISTA ES :"<<min<<'\n'<<endl;
    }
};

int main() 
{
    Linkedlist list;                        // SE CREA UN OBJETO DE LA CASE LISTA 
    int m, c=1;
    char r;
    do                                      // EN ESTE BUCLE SE CREA EL DIALOGO CON EL USUARIO PARA PEDIR LOS DATOS
    {
        cout<<"***DESEA AGREGAR UN ENTERO A LA LISTA?***"<<'\n'<<endl;
        cout<<"***ESCRIBA S PARA SI O N PARA NO***"<<'\n'<<endl;
        cin>>r;
        if (r=='N' or r=='n')
        {
            break;
        }
        cout<<"ESCRIBA EL NUMERO "<<c<<" :"<<'\n'<<endl;
        cin>>m;
        list.insertAtHead(m);                               //EN ESTA SENTENCIA SE ENVIAN LOS VALORES A LOS NODOS Y SE LLENA LA LISTA
        c=c+1;
    } while (r=='s' or r=='S');
    cout << "***LA LISTA DE NUMEROS ENTEROS ES: "<<'\n'<<endl;
    list.print();                                           // SE IMPRIME LA LISTA
    list.maxmin();                                          //SE INVOCA LA FUNCION MIEMBRO QUE EJECUTA EL ALGORITMO DE BUSQUEDA DEL MAXIMO Y MINIMO E IMPRIME AMBOS NUMEROS 
    cout << endl;
    return 0;
}