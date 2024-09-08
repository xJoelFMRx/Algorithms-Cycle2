#pragma once
#include "Conductor.h"

class ListaConductores
{
private:
	int numConductores;
	Conductor** conductores;

public:
	ListaConductores();
	~ListaConductores();
	void agregarConductor(Conductor* conductor);
	void eliminarConductor(string DNI);
	void modificarConductor(string placa);
	void mostrarConductores();
	void reporteConductoresMayores50();
	void reporteConductoresMujeres();
	int getNumConductores();
	int buscarConductoresPorPlaca(string placaVehiculo);
};

ListaConductores::ListaConductores()
{
	numConductores = 0;
	conductores = nullptr;
}

ListaConductores::~ListaConductores()
{
	if (conductores != nullptr)
	{
		for (int i = 0; i < numConductores; i++)
		{
			delete conductores[i];
		}
		delete[] conductores;
	}
}

void ListaConductores::agregarConductor(Conductor* conductor)
{
	Conductor** temp = new Conductor * [numConductores + 1];
	for (int i = 0; i < numConductores; i++)
	{
		temp[i] = conductores[i];
	}
	temp[numConductores] = conductor;
	numConductores++;
	delete[] conductores;
	conductores = temp;
}

void ListaConductores::eliminarConductor(string DNI)
{
	bool dniEncontrado = false;
	for (int i = 0; i < numConductores; i++)
	{
		if (conductores[i]->getDNI() == DNI)
		{
			delete conductores[i];
			for (int j = i; j < numConductores - 1; j++)
			{
				conductores[j] = conductores[j + 1];
			}
			numConductores--;
			dniEncontrado = true;
			cout << endl << "SE ELIMINO EL CONDUCTOR CON EXITO!!" << endl;
			break;
		}
	}
	if (!dniEncontrado)
	{
		cout << endl << "DNI NO ENCONTRADO" << endl;
	}
}

int ListaConductores::buscarConductoresPorPlaca(string placaVehiculo)
{
	for (int i = 0; i < numConductores; i++)
	{
		if (conductores[i]->getPlaca() == placaVehiculo)
		{
			return i;
		}
	}
	return -1;
}

void ListaConductores::modificarConductor(string placaVehiculo)
{
	string DNI, nombre, apellido, placa, empresa;
	int edad, kilometraje, opcion;
	char sexo;
	int indice = buscarConductoresPorPlaca(placaVehiculo);
	if (indice == -1)
	{
		cout << endl << "CONDUCTOR NO ENCONTRADO!" << endl;
		return;
	}
	Conductor* conductor = conductores[indice];
	do
	{
		cout << "Seleccione el atributo a modificar:" << endl;
		cout << "1. DNI" << endl;
		cout << "2. Nombre" << endl;
		cout << "3. Apellido" << endl;
		cout << "4. Edad" << endl;
		cout << "5. Sexo" << endl;
		cout << "6. Empresa" << endl;
		cout << "7. Kilometraje" << endl;
		cout << "8. Placa" << endl;
		cout << "0. Terminar modificaciones" << endl;
		cout << "Ingresar Opcion: "; cin >> opcion;
		system("cls");

		switch (opcion)
		{
		case 1:
			system("cls");
			do
			{
				cout << "Ingrese el nuevo DNI: "; cin >> DNI;
			} while (DNI.empty());
			conductor->setDNI(DNI);
			system("pause>0");
			break;
		case 2:
			system("cls");
			do
			{
				cout << "Ingrese el nuevo nombre: "; cin >> nombre;

			} while (nombre.empty());
			conductor->setNombre(nombre);
			system("pause>0");
			break;
		case 3:
			system("cls");
			do
			{
				cout << "Ingrese el nuevo apellido: "; cin >> apellido;
			} while (apellido.empty());
			conductor->setApellido(apellido);
			system("pause>0");
			break;
		case 4:
			system("cls");
			do
			{
				cout << "Ingrese la nueva edad: "; cin >> edad;
			} while (edad < 18 || edad > 100);
			conductor->setEdad(edad);
			system("pause>0");
			break;
		case 5:
			system("cls");
			do
			{
				cout << "Ingrese el nuevo sexo (M/F): "; cin >> sexo;
				sexo = toupper(sexo);
			} while (sexo != 'M' && sexo != 'F');
			conductor->setSexo(sexo);
			system("pause>0");
			break;
		case 6:
			system("cls");
			do
			{
				cout << "Ingrese la nueva empresa: ";
				cin.ignore();
				getline(cin, empresa);
			} while (empresa.empty());
			conductor->setEmpresa(empresa);
			system("pause>0");
			break;
		case 7:
			system("cls");
			do
			{
				cout << "Ingrese el nuevo kilometraje: "; cin >> kilometraje;
			} while (kilometraje < 1);
			conductor->setKilometraje(kilometraje);
			system("pause>0");
			break;
		case 8:
			system("cls");
			do
			{
				cout << "Ingrese la nueva placa: "; cin >> placa;
			} while (placa.empty());
			conductor->setPlaca(placa);
			system("pause>0");
			break;
		case 0:
			break;
		}
		system("cls");
	} while (opcion != 0);

	cout << "SE MODIFICO CON EXITO LOS DATOS DEL CONDUCTOR!!" << endl;
}

void ListaConductores::mostrarConductores()
{
	cout << "\t\t\tTOTAL DE CONDUCTORES\n\n";
	for (int i = 0; i < numConductores; i++)
	{
		conductores[i]->mostrarConductor();
		cout << endl;
	}
}

void ListaConductores::reporteConductoresMayores50()
{
	bool mayor50 = false;
	for (int i = 0; i < numConductores; i++)
	{
		if (conductores[i]->getEdad() > 50)
		{
			if (!mayor50)
			{
				cout << "\t\t\tREPORTE CONDUCTORES MAYORES 50\n\n";
				mayor50 = true;
			}
			conductores[i]->mostrarConductor();
			cout << endl;
		}
	}
	if (!mayor50)
	{
		cout << "NO HAY CONDUCTORES MAYORES DE 50" << endl;
	}
}

void ListaConductores::reporteConductoresMujeres()
{
	bool haymujeres = false;
	for (int i = 0; i < numConductores; i++)
	{
		if (conductores[i]->getSexo() == 'F')
		{
			if (!haymujeres)
			{
				cout << "\t\t\tREPORTE CONDUCTORAS MUJERES\n\n";
				haymujeres = true;
			}
			conductores[i]->mostrarConductor();
			cout << endl;
		}
	}
	if (!haymujeres)
	{
		cout << "NO HAY CONDUCTORAS MUJERES" << endl;
	}
}

int ListaConductores::getNumConductores()
{
	return numConductores;
}