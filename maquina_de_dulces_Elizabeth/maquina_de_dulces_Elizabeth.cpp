// maquina_de_dulces_Elizabeth.cpp : Defines the entry point for the console application
//COMP2315
//4 octubre 2014.
//Este programa simula una maquina de dulce computadorizada.
//

#include "stdafx.h"	//header files
#include <iostream>
#include <string>
#include <iomanip>	

using namespace std;

void inicio();	//prototipos de las funciones
void func_basica(int x, string);

int main()
{
	string dulce;	//variables locales
	int precio_dulce;
	char otro;
	
	do 
	{
	inicio();	//se llama a la funcion inicio 
		
	cout << "Que tipo de dulce desea?: ";
	char escoge;

	do 
	{
		cin >> escoge;

		switch (escoge)		//depende el tipo de dulce que se escoge entre a, b o c
			{
			case 'a':
			case 'A': cout << "Entre el nombre del dulce que selecciono de tipo A: "; 
				break;
			case 'b':
			case 'B': cout << "Entre el nombre del dulce que selecciono de tipo B: ";
				break;
			case 'c':
			case 'C': cout << "Entre el nombre del dulce que selecciono de tipo C: ";
				break;
			default: cout << "Tipo de dulce invalido...Entre otro tipo: ";
			}
		}while(escoge != 'a' && escoge != 'A' && escoge != 'b' && escoge != 'B' && escoge != 'c' && escoge != 'C');	//si no es a, b o c sigue corriendo
	cin >>  dulce;

	if (escoge == 'a' || escoge == 'A')	//se le asigna el precio al dulce dependiendo la opcion seleccionada por el cliente.
		{
			precio_dulce = 50;
		}
	if (escoge == 'b' || escoge == 'B')
		{
			precio_dulce = 60;
		}
	if (escoge == 'c' || escoge == 'C')
		{
			precio_dulce = 75;
		}
	cout << "El precio del dulce es:" << precio_dulce;	//se le informa el precio del dulce al cliente

	func_basica(precio_dulce, dulce);	//se llama a la func_basica

	cout << "\nDesea otro dulce(s/n)? ";	//luego de haber corrido la func_basica se le pregunta al cliente si desea o no otro dulce
		cin >> otro;

	}while(otro == 's' || otro == 'S');	//vuelve a correr siempre y cuando se seleccione s o S

	if(otro == 'n' || otro == 'N')	//si el usuario no quiere mas dulces
		{
			cout << "Gracias...Vuelva pronto\n\n";
		}
system("pause");
return 0;
}	//main

void inicio()	//funcion de inicio presenta el menu de las opciones de dulces
{
	cout << "**MAQUINA DE DULCES**\n\n";
	cout << "Dulce A: .50 centavos";
	cout << "\tDulce B: .60 centavos";
	cout << "\tDulce C: .75 centavos\n\n";
}
	
void func_basica(int x, string candy)	//la func_basica tiene 2 parametros el de x es el precio del dulce y el de string es el nombre del dulce
{
	int cant_entrada = 0;	//variables
	int moneda;
	int peseta = 0;		//contadores por tipo de moneda entrada
	int dime = 0;
	int nickel = 0;	
			
	do 
		{
		cout << "\nEntre una moneda: ";	//se pide moneda
		cin >> moneda;	//el usuario entra moneda

			if (moneda != 5 && moneda != 10 && moneda != 25)	//se verifican las monedas. si no son 5, 10 o 25, es moneda invalida
			{
				cout << "Moneda invalida... Entre otra moneda.\n";
				cin >> moneda;
			}
			if (moneda == 5)	
			{
				nickel++;	//contador de nickel
			}
			if (moneda == 10)		
			{
				dime++;		//contador de dime
			}
			if (moneda == 25)	
			{
				peseta++;	//contador de peseta
			}	

			cant_entrada += moneda;	//se va sumando la cantidad de monedas validas entradas

	}while(cant_entrada < x);	//va a correr mientras la cantidad de monedas validas entradas sea menor que x que viene siendo el valor del dulce

	cout << "\nAqui esta su " << candy << "...";	//se entrega el dulce
	
		if(cant_entrada > x)	//si la cantidad entrada es mayor que el precio del dulce devuelve el cambio
		{
			cant_entrada -= x;
			cout << "Aqui esta su cambio = " << cant_entrada << " centavos";
		}
		cout << "\n\nSu cantidad:  ";	//se presenta la cantidad entrada de las monedas validas
		cout << peseta <<" peseta(s)" <<  endl;
		cout << setw(15) << dime << " dime(s)" <<  endl;
		cout << setw(15) << nickel <<" nickel(s)" << endl;
}	//func_basica


