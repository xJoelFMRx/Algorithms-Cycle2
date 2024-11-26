#pragma once
#include "Carro.h"

ref class Controladora
{
private:
	Carro^ carro;
    int arbolesVerdes;
    int arbolesRojos;
    int contadorVerde;
    int contadorRojo;
    List<Point>^ posicionesVerdes;
    List<Point>^ posicionesRojos; 

public:
	Controladora(); 
	void Iniciar(Graphics^ g, Bitmap^ img);
    Carro^ getCarro();
    void IncrementarContadorVerde(); 
    void IncrementarContadorRojo();   
    int getContadorVerde();         
    int getContadorRojo();      
    void GenerarPosicionesArbolesRojos();  
    void GenerarPosicionesArbolesVerdes();
    void LimpiarArboles();
    void DibujarArboles(Graphics^ g);
    void LeerDatosDesdeArchivo();
};

Controladora::Controladora()
{
	carro = gcnew Carro(150, 200);
    arbolesVerdes = 0;
    arbolesRojos = 0;
    contadorVerde = 0;
    contadorRojo = 0;
    posicionesVerdes = gcnew List<Point>();
    posicionesRojos = gcnew List<Point>();
}

void Controladora::LeerDatosDesdeArchivo()
{
    ifstream archivo("datos.txt");
    if (archivo.is_open())
    {
        string linea;
        if (getline(archivo, linea))
        {
            arbolesVerdes = stoi(linea);
        }
        if (getline(archivo, linea))
        {
            arbolesRojos = stoi(linea);
        }
        archivo.close();
    }
    else
    {
        arbolesVerdes = 0;
        arbolesRojos = 0;
    }
}

void Controladora::GenerarPosicionesArbolesRojos()
{
    posicionesRojos->Clear();
    posicionesVerdes->Clear();
    for (int i = 0; i < arbolesRojos; ++i)
    {
        int x = RandInt(40, 600);
        int y = RandInt(40, 500);
        posicionesRojos->Add(Point(x, y));
    }
}

void Controladora::GenerarPosicionesArbolesVerdes()
{
    posicionesRojos->Clear();
    posicionesVerdes->Clear();
    for (int i = 0; i < arbolesVerdes; ++i)
    {
        int x = RandInt(40, 600);
        int y = RandInt(40, 500);
        posicionesVerdes->Add(Point(x, y));
    }
}

void Controladora::LimpiarArboles()
{
    posicionesVerdes->Clear();
    posicionesRojos->Clear();
}

void Controladora::DibujarArboles(Graphics^ g)
{
    int ancho = 20;  
    int alto = 50;  
    SolidBrush^ brochaVerde = gcnew SolidBrush(Color::Green);  
    SolidBrush^ brochaRoja = gcnew SolidBrush(Color::Red);   
    for (int i = 0; i < posicionesVerdes->Count; ++i)
    {
        g->FillRectangle(brochaVerde, posicionesVerdes[i].X, posicionesVerdes[i].Y, ancho, alto);
    }
    for (int i = 0; i < posicionesRojos->Count; ++i)
    {
        g->FillRectangle(brochaRoja, posicionesRojos[i].X, posicionesRojos[i].Y, ancho, alto);
    }
}

void Controladora::Iniciar(Graphics^ g, Bitmap^ img)
{
	carro->MoverCarro();
	carro->DibujarCarro(g, img);
    DibujarArboles(g);
}

Carro^ Controladora::getCarro()
{
    return carro;
}

void Controladora::IncrementarContadorVerde()
{
    contadorVerde++;
}

void Controladora::IncrementarContadorRojo()
{
    contadorRojo++;
}

int Controladora::getContadorVerde()
{
    return contadorVerde; 
}

int Controladora::getContadorRojo()
{
    return contadorRojo;   
}