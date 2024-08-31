#include "Persona.h"

using namespace System;

void Ventana()
{
	Console::SetWindowSize(60, 40);
}

void VerificarIMC(Persona* personaN)
{
	double imc = personaN->calcularIMC();
	if (imc == -1)
	{
		cout << personaN->getNombre() << " esta en su peso ideal" << endl;
	}
	else if (imc == 0)
	{
		cout << personaN->getNombre() << " esta por debajo de su peso ideal" << endl;
	}
	else if (imc == 1)
	{
		cout << personaN->getNombre() << " tiene sobrepeso" << endl;
	}
}

void VerificarEdad(Persona* personaN)
{
	if (personaN->esMayorDeEdad())
	{
		cout << personaN->getNombre() << " es mayor de edad" << endl;
	}
	else
	{
		cout << personaN->getNombre() << " es menor de edad" << endl;
	}
}

int main()
{
	Ventana();
	srand(time(nullptr));
	string nombre;
	int edad;
	char sexo;
	double peso;
	double altura;

	cout << "Ingrese nombre: ";
	getline(cin, nombre);
	do
	{
		cout << "Ingrese edad: "; cin >> edad;
	} while (edad < 1);
	cout << "Ingrese sexo: "; cin >> sexo;
	do
	{
		cout << "Ingrese peso: "; cin >> peso;
	} while (peso < 35);
	do
	{
		cout << "Ingrese altura: "; cin >> altura;
	} while (altura < 1.40);
	Persona* persona1 = new Persona(nombre, edad, "61009235", sexo, peso, altura);
	Persona* persona2 = new Persona(nombre, edad, sexo);
	Persona* persona3 = new Persona();
	persona3->setNombre("Jaime");
	persona3->setEdad(56);
	persona3->setSexo('H');
	persona3->setPeso(55.8);
	persona3->setAltura(1.81);
	Persona** personas = new Persona * [3];
	personas[0] = persona1;
	personas[1] = persona2;
	personas[2] = persona3;

	for (int i = 0; i < 3; i++)
	{
		cout << endl << "Informacion persona " << i + 1 << endl;
		cout << personas[i]->toString() << endl;
		VerificarIMC(personas[i]);
		VerificarEdad(personas[i]);
		cout << endl;
	}
	//Eliminar Memoria
	for (int i = 0; i < 3; i++)
	{
		delete personas[i];
	}
	delete[] personas;

	system("pause>0");
	return 0;
}