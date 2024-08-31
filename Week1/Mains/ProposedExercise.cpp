#include "GestionDatos.h"

using namespace System;

void Ventana()
{
    Console::SetWindowSize(75, 40);
}

void MostrarMenu()
{
    cout << "\t\t\tSISTEMA DE GESTION\n";
    cout << "\t===================================================\n";
    cout << "\t1. Alta (Alumnos y Docentes)\n";
    cout << "\t2. Inscribir a materia (Alumnos)\n";
    cout << "\t3. Anotar titular (Docente)\n";
    cout << "\t4. Cargar nota (Alumnos)\n";
    cout << "\t5. Modificar datos (Alumnos y Docentes)\n";
    cout << "\t6. Agregar materia\n";
    cout << "\t7. Salir\n";
}

int main()
{
    GestionDatos* gestiondatos = new GestionDatos();
    int opcion;

    Ventana();

    do
    {
        MostrarMenu();
        cout << "\tIngrese Opcion: "; cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            system("cls");
            gestiondatos->registrarPersona();
            system("pause>0");
            break;
        case 2:
            system("cls");
            if (gestiondatos->hayAlumnos()) {
                if (gestiondatos->hayMaterias()) {
                    gestiondatos->inscribirAlumnoEnMateria();
                }
                else {
                    cout << "NO HAY MATERIAS REGISTRADAS PARA INSCRIBIR A LOS ALUMNOS." << endl;
                }
            }
            else {
                cout << "NO HAY ALUMNOS REGISTRADOS PARA INSCRIBIR EN UNA MATERIA." << endl;
            }
            system("pause>0");
            break;
        case 3:
            system("cls");
            if (gestiondatos->hayDocentes()) {
                if (gestiondatos->hayMaterias()) {
                    gestiondatos->anotarDocenteEnMateria();
                }
                else {
                    cout << "NO HAY MATERIAS REGISTRADAS PARA ANOTAR A LOS DOCENTES." << endl;
                }
            }
            else {
                cout << "NO HAY DOCENTES REGISTRADOS PARA ANOTAR EN UNA MATERIA." << endl;
            }
            system("pause>0");
            break;
        case 4:
            system("cls");
            if (gestiondatos->hayAlumnos()) {
                if (gestiondatos->hayMaterias()) {
                    gestiondatos->cargarNotaAlumno();
                }
                else {
                    cout << "NO HAY MATERIAS REGISTRADAS PARA CARGAR NOTAS." << endl;
                }
            }
            else {
                cout << "NO HAY ALUMNOS REGISTRADOS PARA CARGAR NOTAS." << endl;
            }
            system("pause>0");
            break;
        case 5:
            system("cls");
            if (gestiondatos->hayAlumnos() || gestiondatos->hayDocentes()) {
                gestiondatos->modificarDatos();
            }
            else {
                cout << "NO HAY ALUMNOS NI DOCENTES REGISTRADOS PARA MODIFICAR DATOS." << endl;
            }
            system("pause>0");
            break;
        case 6:
            system("cls");
            gestiondatos->agregarMateria();
            system("pause>0");
            break;
        case 7:
            delete gestiondatos;
            break;
        default:
            cout << "Opcion Invalida!!" << endl;
        }
        system("cls");
    } while (opcion != 7);

    return 0;
}
