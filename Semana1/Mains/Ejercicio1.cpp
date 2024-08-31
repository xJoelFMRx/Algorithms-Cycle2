#include "Password.h"

using namespace System;

void Ventana()
{
	Console::SetWindowSize(60, 40);
}

int main()
{
	Ventana();
	srand(time(nullptr));
	int tam = rand() % (10 - 5 + 1) + 5;
	Password** pass = new Password * [tam];
	bool* esFuerte = new bool[tam];

	for (int i = 0; i < tam; i++)
	{
		pass[i] = new Password();
		esFuerte[i] = pass[i]->esSeguro();
	}
	for (int i = 0; i < tam; i++)
	{
		cout << i + 1 << ") " << pass[i]->getPassword() << ":" << "Fuerte: ";
		if (esFuerte[i])
		{
			cout << "V" << endl;
		}
		else
		{
			cout << "F" << endl;
		}
	}
	//Eliminando Memoria
	for (int i = 0; i < tam; i++)
	{
		delete pass[i];
	}
	delete[] pass;
	delete[] esFuerte;

	system("pause>0");
	return 0;
}

