#pragma once
#include "Plato.h"

class VectorPlatos
{
private:
	int numPlatos;
	Plato** platos;

public:
	VectorPlatos();
	~VectorPlatos();
	void RegistrarPlato(Plato* plato);
	void ModificarPlato(int indice, Plato* nuevoPlato);
	void EliminarPlato(int indice);
	int getNumPlatos();
	Plato* obtenerDatosPlato(int indice);
};

VectorPlatos::VectorPlatos()
{
	numPlatos = 0;
	platos = nullptr;
}

VectorPlatos::~VectorPlatos()
{
	if (platos != nullptr)
	{
		for (int i = 0; i < numPlatos; i++)
		{
			delete platos[i];
		}
		delete[] platos;
	}
}

void VectorPlatos::RegistrarPlato(Plato* plato)
{
	Plato** temp = new Plato * [numPlatos + 1];
	for (int i = 0; i < numPlatos; i++)
	{
		temp[i] = platos[i];
	}
	temp[numPlatos] = plato;
	numPlatos++;
	delete[] platos;
	platos = temp;
}

void VectorPlatos::ModificarPlato(int indice, Plato* nuevoPlato)
{
	if (indice < 0 || indice >= numPlatos)
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return;
	}
	delete platos[indice];
	platos[indice] = nuevoPlato;
}

void VectorPlatos::EliminarPlato(int indice)
{
	if (indice < 0 || indice >= numPlatos)
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return;
	}
	delete platos[indice];
	Plato** temp = new Plato * [numPlatos - 1];
	for (int i = 0, j = 0; i < numPlatos; i++)
	{
		if (i != indice)
		{
			temp[j++] = platos[i];
		}
	}
	numPlatos--;
	delete[] platos;
	platos = temp;
}

int VectorPlatos::getNumPlatos()
{
	return numPlatos;
}

Plato* VectorPlatos::obtenerDatosPlato(int indice)
{
	if (indice < 0 || indice >= numPlatos)
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return nullptr;
	}
	return platos[indice];
}