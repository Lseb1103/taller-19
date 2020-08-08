#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main()
{
   string nombre;
   string apellido;
   int edad, id;
   char r;
   ofstream archivoprueba;
   string nombrearchivo;
   cout<<"INGRESE EL NOMBRE DEL ARCHIVO: ";
   getline(cin,nombrearchivo);
   archivoprueba.open(nombrearchivo.c_str(),ios::app);
   do
    {
    cout<<"\tIngrese el nombre: ";
    getline(cin,nombre,'\n');

    cout<<"\tIngrese el apellido: ";
    getline(cin,apellido,'\n');

    cout<<"\tIngrese el #ID: ";
    cin>>id;

    cout<<"\tIngrese la edad: ";
    cin>>edad;

    archivoprueba<<nombre<<" "<<apellido<<" "<<edad<<id<<"\n";

    cout<<"DESEA INGRESAR OTRO CONTACTO s/n";
    cin>>r;

    cin.ignore();
    }
   while(r=='s');

   archivoprueba.close();

   ifstream archivolectura("datos.txt");
   string texto;

   while(!archivolectura.eof())
    {
        archivolectura>>nombre>>apellido>>edad;

        if(!archivolectura.eof())
            {
        getline(archivolectura,texto);
        cout<<"El NOMBRE ES: "<<nombre<<"\n";
        cout<<"El APELLIDO ES: "<<apellido<<"\n";
        cout<<"EL # ID ES: "<<id<<"\n";
        cout<<"LA EDAD ES: "<<edad<<"\n";
            }

    }
   archivolectura.close();






    return 0;
}