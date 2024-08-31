#pragma once
#include "VectorContactos.h"

class Controladora
{
private:
    VectorContactos* vectorcontactos;

public:
    Controladora();
    ~Controladora();
    void RegistroContactos();
    void ModificarDatosContactos();
    void EliminarContactos();
    void ReporteTodosContactos();
    void ReporteContactosCumplenMayo();
    void ReporteContactosVarones();
    void ReporteContactosFacebookWhatsApp();
    bool existenContactos();
};

Controladora::Controladora()
{
    vectorcontactos = new VectorContactos();
}

Controladora::~Controladora()
{
    delete vectorcontactos;
}

void Controladora::RegistroContactos()
{
    string nombre, facultad, fechanacimiento, email, redsocial;
    long long telefono;
    char sexo;
    cout << "Ingrese Nombre: ";
    cin.ignore();
    getline(cin, nombre);
    do
    {
        cout << "Ingrese Telefono: "; cin >> telefono;
    } while (telefono < 100000000 || telefono > 999999999);
    do
    {
        cout << "Ingrese Sexo: "; cin >> sexo;
        sexo = toupper(sexo);
    } while (sexo != 'V' && sexo != 'M');
    cout << "Ingrese Facultad: ";
    cin.ignore();
    getline(cin, facultad);
    cout << "Ingrese Fecha de Nacimiento: ";
    getline(cin, fechanacimiento);
    cout << "Ingrese Email: ";
    getline(cin, email);
    cout << "Ingrese Red Social: ";
    getline(cin, redsocial);
    Contacto* contacto = new Contacto(nombre, telefono, sexo, facultad, fechanacimiento, email, redsocial);
    vectorcontactos->RegistrarContacto(contacto);
}

void Controladora::ModificarDatosContactos()
{
    string nombre, facultad, fechanacimiento, email, redsocial;
    int indice, opcion;
    long long telefono;
    char sexo;
    cout << "Ingrese el indice del contacto a modificar: "; cin >> indice;
    if (indice < 0 || indice >= vectorcontactos->getNumContactos())
    {
        cout << endl << "Indice fuera de rango!" << endl;
        return;
    }
    Contacto* contacto = vectorcontactos->obtenerDatosContacto(indice);

    do
    {
        cout << "Seleccion el atributo a modificar:" << endl;
        cout << "1. Nombre del Contacto" << endl;
        cout << "2. Telefono" << endl;
        cout << "3. Sexo" << endl;
        cout << "4. Facultad" << endl;
        cout << "5. Fecha Nacimiento" << endl;
        cout << "6. Email" << endl;
        cout << "7. Red Social" << endl;
        cout << "0. Terminar modificaciones" << endl;
        cout << "Ingresar Opcion: "; cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            system("cls");
            cout << "Ingrese el nuevo nombre del contacto: ";
            cin.ignore();
            getline(cin, nombre);
            contacto->setNombre(nombre);
            system("pause>0");
            break;
        case 2:
            system("cls");
            do
            {
                cout << "Ingrese el nuevo telefono del contacto: "; cin >> telefono;
            } while (telefono < 100000000 || telefono > 999999999);
            contacto->setTelefono(telefono);
            system("pause>0");
            break;
        case 3:
            system("cls");
            do
            {
                cout << "Ingrese el nuevo sexo del contacto: "; cin >> sexo;
                sexo = toupper(sexo);
            } while (sexo != 'V' && sexo != 'M');
            contacto->setSexo(sexo);
            system("pause>0");
            break;
        case 4:
            system("cls");
            cout << "Ingrese la nueva facultad del contacto: ";
            cin.ignore();
            getline(cin, facultad);
            contacto->setFacultad(facultad);
            system("pause>0");
            break;
        case 5:
            system("cls");
            cout << "Ingrese la nueva fecha de nacimiento del contacto: ";
            cin.ignore();
            getline(cin, fechanacimiento);
            contacto->setFechaNacimiento(fechanacimiento);
            system("pause>0");
            break;
        case 6:
            system("cls");
            cout << "Ingrese el nuevo email del contacto: ";
            cin.ignore();
            getline(cin, email);
            contacto->setEmail(email);
            system("pause>0");
            break;
        case 7:
            system("cls");
            cout << "Ingrese la nueva red social del contacto: ";
            cin.ignore();
            getline(cin, redsocial);
            contacto->setRedSocial(redsocial);
            system("pause>0");
            break;
        case 0:
            break;
        }
        system("cls");
    } while (opcion != 0);
    cout << "SE MODIFICO CON EXITO LOS DATOS DEL CONTACTO!!" << endl;
}

void Controladora::EliminarContactos()
{
    int indice;
    cout << "Ingrese el indice del contacto a eliminar: "; cin >> indice;
    if (indice < 0 || indice >= vectorcontactos->getNumContactos())
    {
        cout << endl << "Indice fuera de rango!" << endl;
        return;
    }
    vectorcontactos->EliminarContacto(indice);
    cout << "\nSE ELIMINO CON EXITO EL CONTACTO!!" << endl;
}

void Controladora::ReporteTodosContactos()
{
    cout << "\t\t\tREPORTE DE TODOS LOS CONTACTOS\n\n";
    for (int i = 0; i < vectorcontactos->getNumContactos(); i++)
    {
        vectorcontactos->obtenerDatosContacto(i)->MostrarContacto();
        cout << endl;
    }
}

void Controladora::ReporteContactosCumplenMayo()
{
    bool found = false;
    for (int i = 0; i < vectorcontactos->getNumContactos(); i++)
    {
        if (vectorcontactos->obtenerDatosContacto(i)->getFechaNacimiento().substr(3, 2) == "05")
        {
            if (!found)
            {
                cout << "\t\t\tCONTACTOS QUE CUMPLEN EN MAYO\n\n";
                found = true;
            }
            vectorcontactos->obtenerDatosContacto(i)->MostrarContacto();
            cout << endl;
        }
    }
    if (!found)
    {
        cout << "NO HAY CONTACTOS QUE CUMPLAN EN MAYO" << endl;
    }
}

void Controladora::ReporteContactosVarones()
{
    bool found = false;
    for (int i = 0; i < vectorcontactos->getNumContactos(); i++)
    {
        if (vectorcontactos->obtenerDatosContacto(i)->getSexo() == 'V')
        {
            if (!found)
            {
                cout << "\t\t\tCONTACTOS VARONES\n\n";
                found = true;
            }
            vectorcontactos->obtenerDatosContacto(i)->MostrarContacto();
            cout << endl;
        }
    }
    if (!found)
    {
        cout << "NO HAY CONTACTOS VARONES" << endl;
    }
}

void Controladora::ReporteContactosFacebookWhatsApp()
{
    bool found = false;
    for (int i = 0; i < vectorcontactos->getNumContactos(); i++)
    {
        string redSocial = vectorcontactos->obtenerDatosContacto(i)->getRedSocial();
        if (redSocial.find("Facebook") != string::npos || redSocial.find("WhatsApp") != string::npos)
        {
            if (!found)
            {
                cout << "\t\t\tCONTACTOS CON FACEBOOK Y WHATSAPP\n\n";
                found = true;
            }
            vectorcontactos->obtenerDatosContacto(i)->MostrarContacto();
            cout << endl;
        }
    }
    if (!found)
    {
        cout << "NO HAY CONTACTOS CON RED SOCIAL FACEBOOK Y WHATSAPP" << endl;
    }
}

bool Controladora::existenContactos()
{
    return vectorcontactos->getNumContactos() > 0;
}