#include <iostream>
#include <fstream>
#include <string>
void piramide_inver();
void datos_();
void ingresarDatos();
void salidaDatos();
using namespace std;
ofstream  datos;
ifstream imprimirdatos;
string nombrearchiv;
int main()
{
	bool ingres= false;
	int opc;
	do
	{
		cout << "Menu" << endl;
		cout << "1. ejercicio de archivos" << endl;
		cout << "2. ejercicios de las piramides" << endl;
		cout << "3. salir" << endl;
		cout << "opcion";
		cin >> opc;
		switch (opc)
		{
		case 1:
		{
			datos_();
			system("pause");
			break;
		}
		case 2:
		{
			piramide_inver();
			system("pause");
			break;
		}
		case 3:
		{
			ingres = true;
			break;
		}
		default:
		{
			cout << "opcion invalida" << endl;
			break;
		}
		}
	} while (ingres==false);
	return 0;

}
void datos_()
{
	cout << " ingrese el nombre para el archivo: ";
	cin >> nombrearchiv;
	ingresarDatos();
}
void ingresarDatos()
{
	int ingres;
	cout << "1. agregar mas datos" << endl;
	cout << "2. ver datos" << endl;
	cout << "opcion" << endl;
	cin >> ingres;
	cin.ignore();
	if (ingres==1)
	{
		string nombre, apellido;
		int edad;
		string ingresa;
		datos.open(nombrearchiv.c_str(), ios::app);
		do
		{
			cout << "nombre: ";
			getline(cin, nombre, '\n');
			cout << "apellido: ";
			getline(cin, apellido, '\n');
			cout << "edad: ";
			cin >> edad;
			datos << nombre << " " << apellido << " " << edad << "\n";
			cout << "desea ingresar mas contactos (s/n): ";
			cin >> ingresa;
			cin.ignore();
		} while (ingresa == "s");
		cout << "datos guardados con exito" << endl;
		datos.close();
	}
	if (ingres==2)
	{
		salidaDatos();
	}
}
void salidaDatos()
{
	string texto;
	string nombre, apellido;
	int edad;
	imprimirdatos.open(nombrearchiv.c_str(), ios::in);
	if (imprimirdatos.fail())
	{
		cout << "archivo dañado" << endl;
	}
	else
	{
		while (!imprimirdatos.eof())
		{
			imprimirdatos >> nombre >> apellido >> edad;
			if (!imprimirdatos.eof())
			{
				getline(imprimirdatos, texto);
				cout << "nombre: " << nombre << endl;
				cout << "apellido: " << apellido << endl;
				cout << "edad: " << edad << endl;
			}
		}
	}
	imprimirdatos.close();
}
void piramide_inver()
{
	ofstream piramide_inver;
	string pira, nombrearchiv;
	int nivel, i=1, j=1, k;
	cout << "nombre del archivo: "<< endl;
	cin >> nombrearchiv;
	cout << "ingrese el nivel de la piramide invertida";
	cin >> nivel;
	piramide_inver.open(nombrearchiv.c_str(), ios::out);
	k = nivel;
	while (i<=nivel)
	{
		while (j<=k)
		{
			if (i%2==0)
			{
				piramide_inver << "- ";
			}
			else
			{
				piramide_inver << "* ";
			}
			j++;
		}
		piramide_inver << "\n";
		i++;
		j = 1;
		k--;

	}
	piramide_inver.close();

	ifstream abrirpiramid;
	string text;
	abrirpiramid.open(nombrearchiv.c_str(), ios::in);
	while (!abrirpiramid.eof())
	{
		getline(abrirpiramid, text);
		cout << text << endl;
	}
	abrirpiramid.close();
}
