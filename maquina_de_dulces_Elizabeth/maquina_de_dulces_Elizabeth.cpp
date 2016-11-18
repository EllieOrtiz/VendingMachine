// maquina_de_dulces_Elizabeth.cpp : Defines the entry point for the console application
//COMP2315
//4 octubre 2014.
//This program simulates a candy machine.
//

#include "stdafx.h"	//header files
#include <iostream>
#include <string>
#include <iomanip>	

using namespace std;

void inicio();	//function prototypes
void func_basica(int x, string);

int main()
{
	string dulce;	//local variables
	int precio_dulce;
	char otro;
	
	do 
	{
	inicio();	//call inicio function
		
	cout << "Select candy (A,B or C): ";
	char escoge;

	do 
	{
		cin >> escoge;

		switch (escoge)		//cases depending on the selection a, b o c
			{
			case 'a':
			case 'A': cout << "Enter the name of the candy A: "; 
				break;
			case 'b':
			case 'B': cout << "Enter the name of the candy B: ";
				break;
			case 'c':
			case 'C': cout << "Enter the name of the candy C: ";
				break;
			default: cout << "Invalid selection...Please enter A, B or C: ";
			}
		}while(escoge != 'a' && escoge != 'A' && escoge != 'b' && escoge != 'B' && escoge != 'c' && escoge != 'C');	//si no es a, b o c sigue corriendo
	cin >>  dulce;

	if (escoge == 'a' || escoge == 'A')	//a price is assigned depending on the selection.
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
	cout << "The price is :" << precio_dulce;	//price of the candy is displayed.

	func_basica(precio_dulce, dulce);	//func_basica function called

	cout << "\nWould you like another candy(y/n)? ";	
		cin >> otro;

	}while(otro == 's' || otro == 'S');	//runs while the selection is y o Y 

	if(otro == 'n' || otro == 'N')	
		{
			cout << "Gracias...Vuelva pronto\n\n";
		}
system("pause");
return 0;
}	//main

void inicio()	//funcion presents the menu of options
{
	cout << "**Candy Machine**\n\n";
	cout << "Candy A: .50 cents";
	cout << "\tCandy B: .60 cents";
	cout << "\tCandy C: .75 cents\n\n";
}
	
void func_basica(int x, string candy)	//func_basica has two parameters. x which is the price of the candy and string which is the name of the candy
{
	int cant_entrada = 0;	//variables
	int moneda;
	int peseta = 0;		//counters for the inserted coins
	int dime = 0;
	int nickel = 0;	
			
	do 
		{
		cout << "\nEnter coins: ";	
		cin >> moneda;	//the user enters a coin

			if (moneda != 5 && moneda != 10 && moneda != 25)	//coin verification. if they aren't 5, 10 or 25, the coin is invalid.
			{
				cout << "Invalid coin... Please insert another coin.\n";
				cin >> moneda;
			}
			if (moneda == 5)	
			{
				nickel++;	//nickel counter
			}
			if (moneda == 10)		
			{
				dime++;		//dime counter
			}
			if (moneda == 25)	
			{
				peseta++;	//quarter counter
			}	

			cant_entrada += moneda;	//sum of the valid coins inserted.

	}while(cant_entrada < x);	//will run while the quantity of valid coins < to the candy price

	cout << "\nPlease take your " << candy << "...";	//candy sold
	
		if(cant_entrada > x)	//if coin quantity is > to candy price, returns change.
		{
			cant_entrada -= x;
			cout << "Here is your change = " << cant_entrada << " cents";
		}
		cout << "\n\nCoins entered:  ";	//Displays the cuantity of valid coins inserted.
		cout << peseta <<" Quarter(s)" <<  endl;
		cout << setw(15) << dime << " dime(s)" <<  endl;
		cout << setw(15) << nickel <<" nickel(s)" << endl;
}	//func_basica


