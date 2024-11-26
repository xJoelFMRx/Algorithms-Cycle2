#pragma once
#include "Personaje.h"
#include "Disco.h"

class Controladora
{
private:
	vector<Disco*> discos;
	Personaje* personaje;
	clock_t tiempoInicio; 
	int tiempoTotal;      

public:
	Controladora();
	~Controladora();
	void Iniciar(Graphics^ g, Bitmap^ imgPersonaje, Bitmap^ imgEscenario, Bitmap^ Disco);
	void MoverObjetos(Graphics^ g);
	void DibujarObjetos(Graphics^ g, Bitmap^ imgPersonaje, Bitmap^ imgDisco);
	void mostrarEscenario(Graphics^ g, Bitmap^ img);
	void LeerConfiguracion();
	void Colisiones();
	void AgregarDiscos();
	bool JuegoTerminado();
	bool JugadorGano();
	int getTiempoJuego();
	Personaje* getPersonaje();
};

Controladora::Controladora()
{
	personaje = nullptr; 
	tiempoTotal = 0; 
	tiempoInicio = 0;
	AgregarDiscos();
}

Controladora::~Controladora()
{
	delete personaje;
	for (int i = 0; i < discos.size(); i++)
	{
		delete discos[i];
	}
	discos.clear();
}

void Controladora::AgregarDiscos()
{
	int cantidad = RandInt(1, 7);
	for (int i = 0; i < cantidad; i++)
	{
		int x = RandInt(0, 650);
		int y = RandInt(0, 550);
		discos.push_back(new Disco(x, y));
	}
}

void Controladora::MoverObjetos(Graphics^ g)
{
	personaje->Mover(g);
	for (int i = 0; i < discos.size(); i++)
	{
		discos[i]->Mover(g);
	}
}

void Controladora::DibujarObjetos(Graphics^ g, Bitmap^ imgPersonaje, Bitmap^ imgDisco)
{
	personaje->Dibujar(g, imgPersonaje);
	for (int i = 0; i < discos.size(); i++)
	{
		discos[i]->Dibujar(g, imgDisco);
	}
}

void Controladora::mostrarEscenario(Graphics^ g, Bitmap^ img)
{
	g->DrawImage(img, 0, 0, 700, 600);
}

Personaje* Controladora::getPersonaje()
{
	return personaje;
}

void Controladora::LeerConfiguracion()
{
	ifstream archivo("configuracion.txt");
	if (!archivo.is_open())
	{
		//Si el archivo no existe o no se puede abrir, no hacer nada.
		cout << "Error: El archivo de configuracion no existe." << endl;
		return;
	}
	int x = 350, y = 300, vidas = 10, tiempo = 20; //Valores predeterminados de respaldo
	//A partir de aca lee el archivo si se abre correctamente
	string linea;
	//Leer cada línea del archivo
	while (getline(archivo, linea))
	{
		size_t posIgual = linea.find('=');
		if (posIgual != string::npos)
		{
			string clave = linea.substr(0, posIgual);
			int valor = stoi(linea.substr(posIgual + 1));
			// Asignar los valores leídos a las variables correspondientes
			if (clave == "X") x = valor;
			else if (clave == "Y") y = valor;
			else if (clave == "N") vidas = valor;
			else if (clave == "T") tiempo = valor;
		}
	}
	//Crear un nuevo personaje con los valores leídos
	personaje = new Personaje(x, y, vidas);
	tiempoTotal = tiempo;
	tiempoInicio = clock(); 
	archivo.close(); 
}

void Controladora::Colisiones()
{
	for (int i = 0; i < discos.size(); i++)
	{
		if (discos[i]->mascara().IntersectsWith(personaje->mascara()))
		{
			personaje->bajarVidas();
			personaje->RegresarPosicionInicial();
		}
	}
	//Verificar colisión entre discos(azul y rojo)
	for (int i = 0; i < discos.size(); i++)
	{
		for (int j = i + 1; j < discos.size(); j++)
		{
			if (discos[i]->mascara().IntersectsWith(discos[j]->mascara()))
			{
				int tipo1 = discos[i]->getTypeDisco();
				int tipo2 = discos[j]->getTypeDisco();
				if ((tipo1 == 1 && tipo2 == 2) || (tipo1 == 2 && tipo2 == 1))
				{
					//Crear un nuevo disco aleatorio
					int x = RandInt(0, 650);
					int y = RandInt(0, 550);
					Disco* nuevoDisco = new Disco(x, y);
					nuevoDisco->setTypeDisco(3);
					discos.push_back(nuevoDisco);
					delete discos[j];
					delete discos[i];
					discos.erase(discos.begin() + j);
					discos.erase(discos.begin() + i);
					return;
				}
			}
		}
	}
}

void Controladora::Iniciar(Graphics^ g, Bitmap^ imgPersonaje, Bitmap^ imgEscenario, Bitmap^ imgDisco)
{
	mostrarEscenario(g, imgEscenario);
	MoverObjetos(g);
	DibujarObjetos(g, imgPersonaje, imgDisco);
	Colisiones();
}

bool Controladora::JuegoTerminado()
{
	return (personaje->getVidas() <= 0 || getTiempoJuego() <= 0);
}

bool Controladora::JugadorGano()
{
	return getTiempoJuego() <= 0 && personaje->getVidas() > 0;
}

int Controladora::getTiempoJuego()
{
	//Calcula el tiempo transcurrido en segundos
	clock_t tiempoActual = clock();
	int tiempoTranscurrido = (tiempoActual - tiempoInicio) / CLOCKS_PER_SEC;
	//Devuelve el tiempo restante
	return max(0, tiempoTotal - tiempoTranscurrido); //Asegura que no devuelva un valor negativo
}