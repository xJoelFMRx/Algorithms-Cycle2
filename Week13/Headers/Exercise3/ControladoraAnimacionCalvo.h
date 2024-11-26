#pragma once
#include "Circulo.h"
#include "Calvo.h"

ref class Controladora
{
private:
	Calvo^ calvo;
	List<Circulo^>^ circulos;

public:
	Controladora();
	void MoverObjetos(Graphics^ g);
	void DibujarObjetos(Graphics^ g, Bitmap^ imgCalvo);
	void AgregarCirculo(int ancho, int alto);
	void Iniciar(Graphics^ g, Bitmap^ imgCalvo);
	void LeerDatos();
	Calvo^ getCalvo();
};

Controladora::Controladora()
{
	calvo = nullptr;
	circulos = gcnew List<Circulo^>();
}

void Controladora::MoverObjetos(Graphics^ g)
{
	calvo->Mover(g);
	for (int i = 0; i < circulos->Count; i++)
	{
		circulos[i]->Mover(g);
	}
}

void Controladora::DibujarObjetos(Graphics^ g, Bitmap^ imgCalvo)
{
	calvo->DibujarCalvo(g, imgCalvo);
	for (int i = 0; i < circulos->Count; i++)
	{
		circulos[i]->DibujarCirculo(g);
	}
}

Calvo^ Controladora::getCalvo()
{
	return calvo;
}

void Controladora::AgregarCirculo(int ancho, int alto)
{
	Color color = Color::FromArgb(RandInt(0, 255), RandInt(0, 255), RandInt(0, 255));
	int radio = RandInt(20, 40);
	int dx = RandInt(-5, 5);
	int dy = RandInt(-5, 5);
	Circulo^ circulo = gcnew Circulo(RandInt(0, ancho - radio), RandInt(0, alto - radio), dx, dy, radio, color);
	circulos->Add(circulo);
}

void Controladora::LeerDatos()
{
	ifstream archivo("datos.txt");
	if (!archivo.is_open())
	{
		cout << "Error: El archivo de datos no existe." << endl;
		return;
	}
	int x = 450, y = 320; //Valores predeterminados de respaldo
	string linea;
	while (getline(archivo, linea))
	{
		size_t posIgual = linea.find('=');
		if (posIgual != string::npos)
		{
			string clave = linea.substr(0, posIgual);
			int valor = stoi(linea.substr(posIgual + 1));
			//Asignar los valores le dos a las variables correspondientes
			if (clave == "X") x = valor;
			else if (clave == "Y") y = valor;
		}
	}
	//Crear un nuevo personaje con los valores leidos
	calvo = gcnew Calvo(x, y);
	archivo.close();
}

void Controladora::Iniciar(Graphics^ g, Bitmap^ imgCalvo)
{
	MoverObjetos(g);
	DibujarObjetos(g, imgCalvo);
}