//ESTE PROGRAMA PIDE UNA LISTA DE N NUMEROS REALES AL USUARIO Y SON ALMACENADOS EN UNA LISTA ENLAZADA
//EL PROGRAMA CALCULA LA SUMA DE TODOS LOS ELEMENTOS Y SU PRMEDIO
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <climits> 

using namespace std;

class Node                                  //SE DEFINE LA CLASE NODO       
{
    public:
    double data;
    Node* next;
    Node()                                  // CONSTRUCTOR DE LA CLASE INICIA LAS VARIABLES 
    {
        data = 0;
        next = NULL;
    }
    Node(double data)                          // CONSTRUCTOR CON PARAMETROS
    {
        this->data = data;
        this->next = NULL;
    }
};

class Pila                            // SE DEFINE LA CLASE LISTA ENLAZADA
{
    public:
    Node* head;
    Pila()                            // COSTRUCTOR DE LA CLASE LISTA ENLAZADA
    {
        head = NULL;
    }
    void insertAtHead(double data)             // FUNCION QUE INSERTA UN NODO EN EL INICIO DE LA LISTA
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
};

int main() 
{
    Pila list;                              // SE CREA UN OBJETO DE LA CASE PILA 
    double m, suma=0, prom=0;
    int c=0;
    char r;
    do                                      // EN ESTE BUCLE SE CREA EL DIALOGO CON EL USUARIO PARA PEDIR LOS DATOS
    {
        cout<<"***DESEA AGREGAR UN REAL A LA LISTA?***"<<'\n'<<endl;
        cout<<"***ESCRIBA S PARA SI O N PARA NO***"<<'\n'<<endl;
        cin>>r;
        if (r=='N' or r=='n')
        {
            break;
        }
        cout<<"ESCRIBA EL NUMERO REAL "<<c+1<<" :"<<'\n'<<endl;
        cin>>m;
        suma=suma+m;                                                        //SE CALCULA LA SUMA DE LOS N NUMEROS REALES
        list.insertAtHead(m);                                               //EN ESTA SENTENCIA SE ENVIAN LOS VALORES A LOS NODOS Y SE LLENA LA LISTA
        c=c+1;                                                              //SE CUENTA LA CANTIDAD DE NUMEROS QUE INGRESA EL USUARIO
    } while (r=='s' or r=='S');
    prom=suma/c;                                                            //SE CALCULA EL PROMEDIO DE LOS N NUMEROS REALES 
    cout << "***LA LISTA DE NUMEROS REALES ES: "<<'\n'<<endl;
    list.print();                                                           // SE IMPRIME LA LISTA DE N REALES                             
    cout<<"LA SUMA DE LOS "<<c<<" ELEMENTOS ES: "<<suma<<'\n'<<endl;
    cout<<"EL PROMEDIO DE LOS "<<c<<" ELEMENTOS ES: "<<prom<<'\n'<<endl;
    return 0;
}
