#pragma once
#include "Alumno.h"
#include "Docente.h"

class GestionDatos
{
private:
	vector<Docente> docentes;
	vector<Alumno> alumnos;
	vector<Materia> materias;

public:
	GestionDatos();
	void agregarMateria();
	void registrarPersona();
	void inscribirAlumnoEnMateria();
	void anotarDocenteEnMateria();
	void cargarNotaAlumno();
	void modificarDatos();
	bool hayAlumnos();
	bool hayDocentes();
	bool hayMaterias();
};

GestionDatos::GestionDatos() {}

void GestionDatos::agregarMateria()
{
	string codigo, nombre;
	cout << "Ingrese codigo de la materia: "; cin >> codigo;
	cout << "Ingrese nombre de la materia: ";
	cin.ignore();
	getline(cin, nombre);
	materias.push_back(Materia(codigo, nombre));
	cout << endl << "Materia agregada con exito!!" << endl;
}

void GestionDatos::registrarPersona()
{
	int tipo;
	cout << "Que desea registrar?" << endl;
	cout << "1. Docente" << endl;
	cout << "2. Alumnos" << endl;
	cout << "Ingrese numero: "; cin >> tipo;

	if (tipo == 1)
	{
		string DNI, apellidos, nombres, mail, titulo;
		cout << "Ingrese DNI del docente: "; cin >> DNI;
		cout << "Ingrese Apellidos del docente: ";
		cin.ignore();
		getline(cin, apellidos);
		cout << "Ingrese Nombres del docente: ";
		getline(cin, nombres);
		cout << "Ingrese Mail del docente: "; cin >> mail;
		cout << "Ingrese Titulo del docente: ";
		cin.ignore();
		getline(cin, titulo);

		Docente nuevoDocente(DNI, apellidos, nombres, mail, titulo);
		docentes.push_back(nuevoDocente);
		cout << endl << "Docente registrado con exito!!" << endl;
	}
	else if (tipo == 2)
	{
		string DNI, apellidos, nombres, carrera, mail;
		int edad;
		cout << "Ingrese DNI del alumno: "; cin >> DNI;
		cout << "Ingrese Apellidos del alumno: ";
		cin.ignore();
		getline(cin, apellidos);
		cout << "Ingrese Nombres del alumno: ";
		getline(cin, nombres);
		cout << "Ingrese Carrera del alumno: ";
		getline(cin, carrera);
		cout << "Ingrese Mail del alumno: "; cin >> mail;
		do
		{
			cout << "Ingrese Edad del alumno: "; cin >> edad;
		} while (edad < 16 || edad > 80);

		Alumno nuevoAlumno(DNI, apellidos, nombres, carrera, mail, edad);
		alumnos.push_back(nuevoAlumno);
		cout << endl << "Alumno registrado con exito!!" << endl;
	}
	else
	{
		cout << endl << "Tipo de persona invalido!!" << endl;
	}
}

void GestionDatos::inscribirAlumnoEnMateria()
{
	string DNI, codigoMateria;
	cout << "Ingrese DNI del alumno: "; cin >> DNI;
	cout << "Ingrese codigo de materia: "; cin >> codigoMateria;
	Alumno* alumnoEncontrado = nullptr;
	for (int i = 0; i < alumnos.size(); i++)
	{
		if (alumnos[i].getDNI() == DNI)
		{
			alumnoEncontrado = &alumnos[i];
			break;
		}
	}
	Materia* materiaEncontrada = nullptr;
	for (int i = 0; i < materias.size(); i++)
	{
		if (materias[i].getCodigo() == codigoMateria)
		{
			materiaEncontrada = &materias[i];
			break;
		}
	}
	if (alumnoEncontrado != nullptr && materiaEncontrada != nullptr)
	{
		alumnoEncontrado->inscribirMateria(*materiaEncontrada);
		cout << endl << "Alumno inscrito en la materia " << materiaEncontrada->getNombre() << " con exito!!" << endl;
	}
	else
	{
		cout << endl << "Alumno o materia no encontrado!!" << endl;
	}
}

void GestionDatos::anotarDocenteEnMateria()
{
	string DNI, codigoMateria;
	cout << "Ingrese DNI del docente: "; cin >> DNI;
	cout << "Ingrese codigo de la materia: "; cin >> codigoMateria;
	Docente* docenteEncontrado = nullptr;
	for (int i = 0; i < docentes.size(); i++)
	{
		if (docentes[i].getDNI() == DNI)
		{
			docenteEncontrado = &docentes[i];
			break;
		}
	}
	Materia* materiaEncontrada = nullptr;
	for (int i = 0; i < materias.size(); i++)
	{
		if (materias[i].getCodigo() == codigoMateria)
		{
			materiaEncontrada = &materias[i];
			break;
		}
	}
	if (docenteEncontrado != nullptr && materiaEncontrada != nullptr)
	{
		docenteEncontrado->anotarMateria(*materiaEncontrada);
		cout << endl << "Docente anotado en la materia " << materiaEncontrada->getNombre() << " con exito!!" << endl;
	}
	else
	{
		cout << endl << "Docente o materia no encontrado!!" << endl;
	}
}

void GestionDatos::cargarNotaAlumno()
{
	string DNI, codigoMateria;
	double nota;
	cout << "Ingrese DNI del alumno: "; cin >> DNI;
	cout << "Ingrese codigo de la materia: "; cin >> codigoMateria;
	do
	{
		cout << "Ingrese la nota: "; cin >> nota;
	} while (nota < 0 || nota > 20);
	Alumno* alumnoEncontrado = nullptr;
	for (int i = 0; i < alumnos.size(); i++)
	{
		if (alumnos[i].getDNI() == DNI)
		{
			alumnoEncontrado = &alumnos[i];
			break;
		}
	}
	if (alumnoEncontrado != nullptr)
	{
		alumnoEncontrado->cargarNota(codigoMateria, nota);
		cout << endl << "Nota cargada con exito!!" << endl;
	}
	else
	{
		cout << endl << "Alumno no encontrado!!" << endl;
	}
}

void GestionDatos::modificarDatos()
{
	int tipo;
	string DNI;
	cout << "Seleccione el tipo de persona: " << endl;
	cout << "1. Docente" << endl;
	cout << "2. Alumno" << endl;
	cout << "Ingrese numero: "; cin >> tipo;

	cout << "Ingrese DNI: "; cin >> DNI;
	if (tipo == 1)
	{
		Docente* docenteEncontrado = nullptr;
		for (int i = 0; i < docentes.size(); i++)
		{
			if (docentes[i].getDNI() == DNI)
			{
				docenteEncontrado = &docentes[i];
				break;
			}
		}

		if (docenteEncontrado != nullptr)
		{
			string apellidos, nombres, mail, titulo;
			cout << "Ingrese nuevos Apellido: ";
			cin.ignore();
			getline(cin, apellidos);
			cout << "Ingrese nuevos Nombres: ";
			getline(cin, nombres);
			cout << "Ingrese nuevo Mail: "; cin >> mail;
			cout << "Ingrese nuevo Titulo: ";
			cin.ignore();
			getline(cin, titulo);
			docenteEncontrado->modificarDatos(apellidos, nombres, mail, titulo);
			cout << endl << "Datos del docente modificados con exito!!" << endl;
		}
		else
		{
			cout << endl << "Docente no encontrado!!" << endl;
		}
	}
	else if (tipo == 2)
	{
		Alumno* alumnoEncontrado = nullptr;
		for (int i = 0; i < alumnos.size(); ++i) {
			if (alumnos[i].getDNI() == DNI) {
				alumnoEncontrado = &alumnos[i];
				break;
			}
		}

		if (alumnoEncontrado != nullptr) {
			string apellidos, nombres, mail;
			int edad;
			cout << "Ingrese nuevo Apellido: ";
			cin.ignore();
			getline(cin, apellidos);
			cout << "Ingrese nuevos Nombres: ";
			getline(cin, nombres);
			cout << "Ingrese nuevo Mail: "; cin >> mail;
			do
			{
				cout << "Ingrese nueva Edad: "; cin >> edad;
			} while (edad < 16 || edad > 80);
			alumnoEncontrado->modificarDatos(apellidos, nombres, mail, edad);
			cout << endl << "Datos del alumno modificados con exito!!" << endl;
		}
		else {
			cout << endl << "Alumno no encontrado!!" << endl;
		}
	}
	else
	{
		cout << endl << "Tipo de persona invalido!!" << endl;
	}
}

bool GestionDatos::hayAlumnos()
{
	return !alumnos.empty();
}

bool GestionDatos::hayDocentes()
{
	return !docentes.empty();
}

bool GestionDatos::hayMaterias()
{
	return !materias.empty();
}