#pragma once
#include "Contacto.h"

class VectorContactos
{
private:
	int numContactos;
	Contacto** contactos;

public:
	VectorContactos();
	~VectorContactos();
	void RegistrarContacto(Contacto* contacto);
	void ModificarContacto(int indice, Contacto* nuevoContacto);
	void EliminarContacto(int indice);
	int getNumContactos();
	Contacto* obtenerDatosContacto(int indice);
};

VectorContactos::VectorContactos()
{
	numContactos = 0;
	contactos = nullptr;
}

VectorContactos::~VectorContactos()
{
	if (contactos != nullptr)
	{
		for (int i = 0; i < numContactos; i++)
		{
			delete contactos[i];
		}
		delete[] contactos;
	}
}

void VectorContactos::RegistrarContacto(Contacto* contacto)
{
	Contacto** temp = new Contacto * [numContactos + 1];
	for (int i = 0; i < numContactos; i++)
	{
		temp[i] = contactos[i];
	}
	temp[numContactos] = contacto;
	numContactos++;
	delete[] contactos;
	contactos = temp;
}

void VectorContactos::ModificarContacto(int indice, Contacto* nuevoContacto)
{
	if (indice < 0 || indice >= numContactos)
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return;
	}
	delete contactos[indice];
	contactos[indice] = nuevoContacto;
}

void VectorContactos::EliminarContacto(int indice)
{
	if (indice < 0 || indice >= numContactos)
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return;
	}
	delete contactos[indice];
	Contacto** temp = new Contacto * [numContactos - 1];
	for (int i = 0, j = 0; i < numContactos; i++)
	{
		if (i != indice)
		{
			temp[j++] = contactos[i];
		}
	}
	numContactos--;
	delete[] contactos;
	contactos = temp;
}

int VectorContactos::getNumContactos()
{
	return numContactos;
}

Contacto* VectorContactos::obtenerDatosContacto(int indice)
{
	if (indice < 0 || indice >= numContactos)
	{
		cout << endl << "Indice fuera de rango!" << endl;
		return nullptr;
	}
	return contactos[indice];
}