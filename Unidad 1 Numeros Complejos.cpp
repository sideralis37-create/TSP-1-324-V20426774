// ESTE PROGRAMA RECIBE LA PARTE REAL Y LA PARTE IMAGINARIA DE DOS NUMEROS COMPLEJOS
// COMPARA LA SUMA Y EL PRODUCTO DE AMBOS NUMEROS COMPLEJOS E INFORMA 
// SI LA SUMA Y EL PRODUCTO SON IGUALES
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib> 

using namespace std;

class complejos                                              //SE DEFINE LA CLASE DE NUMEROS COMPLEJOS 
{
    private:
        float re;
        float im;
    public:
    complejos()                                             // CONSTRUCTOR
    {
        this-> re=0;
        this-> im=0;
        cout<<"ESCRIBA LA PARTE REAL DEL NUMERO:"<<'\n'<<endl;
        cin>>re;
        cout<<"ESCRIBA LA PARTE IMAGINARIA DEL NUMERO:"<<'\n'<<endl;
        cin>>im;
    }  
    friend float suma(complejos z1, complejos z2);          //FUNCION QUE SUMA AMBOS NUMEROS COMPLEJOS
    friend float producto (complejos w1, complejos w2);     //FUNCION QUE CALCULA EL PRODUCTO DE AMBOS NUMEROS COMPLEJOS 
    friend float comparar (complejos y1, complejos y2);     //FUNCION QUE COMPARA AMBOS NUMEROS COMPLEJOS E INFORMA SI LA SUMA Y EL PRODUCTO SON IGUALES O NO
};
float suma(complejos z1, complejos z2)                      //FUNCION MIEMBRO FUERA DE LINEA QUE SUMA LOS NUMEROS 
{
    float r=0;
    float i=0;
    r=z1.re+z2.re;
    i=z1.im+z2.im;
    cout<<"LA SUMA ES: "<<r<<" + "<<i<<"i"<<'\n'<<endl;
    return 0;
}
float producto (complejos w1, complejos w2)                 //FUNCION MIEMBRO FUERA DE LINEA QUE CALCULA EL PRODUCTO 
{
    float r=0;
    float i=0;
    r=(w1.re*w2.re)-(w1.im*w2.im);
    i=(w1.re*w2.im)+(w1.im*w2.re);
    cout<<"EL PRODUCTO ES: "<<r<<" + "<<i<<"i"<<'\n'<<endl;
    return 0;
}
float comparar (complejos y1, complejos y2)                 //FUNCION MIEMBRO QUE COMPARA LA SUMA Y EL PRODUCTO
{
    float r=0, er=0;
    float i=0, mi=0;
    r=y1.re+y2.re;
    i=y1.im+y2.im;
    er=(y1.re*y2.re)-(y1.im*y2.im);
    mi=(y1.re*y2.im)+(y1.im*y2.re);
    if (r==er and i==mi) 
    {
        cout<<"***LA SUMA Y EL PRODUCTO SON IGUALES***"<<'\n'<<endl;
        cout<<"LA SUMA ES: "<<r<<" + "<<i<<"i"<<'\n'<<endl;
        cout<<"EL PRODUCTO ES: "<<er<<" + "<<mi<<"i"<<'\n'<<endl;
    }
    else    
    cout<<"***EL PRODUCTO Y LA SUMA SON DIFERENTES***"<<'\n'<<endl;
    cout <<"***PRESIONE <ENTER> PARA CONTINUAR***"<<endl;
    system("pause");
    system("cls");
    return 0;
}

int main()                                              
{
    complejos a;
    complejos b;
    suma(a,b);
    producto (a,b);
    comparar (a,b);
    return 0;
}