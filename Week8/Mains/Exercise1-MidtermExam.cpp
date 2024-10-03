#include "Perro.h"
#include "Conejo.h"
#include "Tortuga.h"
#include "Gato.h"
#include "Caballo.h"
#include "Pajaro.h"
#define ANCHO_CONSOLA 75
#define ALTO_CONSOLA 40

void Ventana()
{
    Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
}

void MostrarMenu()
{
    cout << "\t\t\tMENU ANIMALES\n";
    cout << "\t\t===========================\n";
    cout << "\t\t[1] Elegir Conejo\n";
    cout << "\t\t[2] Elegir Tortuga\n";
    cout << "\t\t[3] Elegir Perro\n";
    cout << "\t\t[4] Elegir Gato\n";
    cout << "\t\t[5] Elegir Caballo\n";
    cout << "\t\t[6] Elegir Pajaro\n";
    cout << "\t\t[9] Salir\n";
}

int main()
{
    int opc;

    Ventana();
    do
    {
        MostrarMenu();
        cout << "\t\tIngrese opcion: "; cin >> opc;
        system("cls");

        switch (opc)
        {
        case 1:
        {
            system("cls");
            double velocidad;
            double size;
            cout << "Ingrese velocidad del conejo: "; cin >> velocidad;
            cout << "Ingrese size del conejo: "; cin >> size;
            Animal* conejo = new Conejo(velocidad, size);
            cout << endl;
            cout << "La fuerza del conejo es: " << conejo->calcularFuerza() << endl;
            cout << "La velocidad del conejo es: " << conejo->calcularVelocidad() << endl;
            system("pause>0");
            break;
        }
        case 2:
        {
            system("cls");
            double velocidad;
            double size;
            cout << "Ingrese velocidad de la tortuga: "; cin >> velocidad;
            cout << "Ingrese size de la tortuga: "; cin >> size;
            Animal* tortuga = new Tortuga(velocidad, size);
            cout << endl;
            cout << "La fuerza de la tortuga es: " << tortuga->calcularFuerza() << endl;
            cout << "La velocidad de la tortuga es: " << tortuga->calcularVelocidad() << endl;
            system("pause>0");
            break;
        }
        case 3:
        {
            system("cls");
            string raza;
            double size;
            cin.ignore();
            cout << "Ingrese raza del perro: "; 
            getline(cin, raza);
            cout << "Ingrese size del perro: "; cin >> size;
            Animal* perro = new Perro(raza, size);
            cout << endl;
            cout << "La fuerza del perro es: " << perro->calcularFuerza() << endl;
            cout << "La velocidad del perro es: " << perro->calcularVelocidad() << endl;
            system("pause>0");
            break;
        }
        case 4:
        {
            system("cls");
            double peso;
            double size;
            cout << "Ingrese peso del gato: "; cin >> peso;
            cout << "Ingrese size del gato: "; cin >> size;
            Animal* gato = new Gato(peso, size);
            cout << endl;
            cout << "La agilidad del gato es: " << gato->calcularAgilidad() << endl;
            cout << "La velocidad del gato es: " << gato->calcularVelocidad() << endl;
            system("pause>0");
            break;
        }
        case 5:
        {
            system("cls");
            double peso;
            double altura;
            cout << "Ingrese peso del caballo: "; cin >> peso;
            cout << "Ingrese altura del caballo: "; cin >> altura;
            Animal* caballo = new Caballo(altura, peso);
            cout << endl;
            cout << "La fuerza del caballo es: " << caballo->calcularFuerza() << endl;
            cout << "La velocidad del caballo es: " << caballo->calcularVelocidad() << endl;
            system("pause>0");
            break;
        }
        case 6:
        {
            system("cls");
            double ancho;
            double alto;
            cout << "Ingrese ancho de la ala del pajaro: "; cin >> ancho;
            cout << "Ingrese alto de la ala del pajaro: "; cin >> alto;
            Animal* pajaro = new Pajaro(ancho, alto);
            cout << endl;
            cout << "La velocidad de vuelo del pajaro es: " << pajaro->calcularVelocidad() << endl;
            system("pause>0");
            break;
        }
        case 9:
        {
            break;
        }
        default:
            cout << "Opcion Invalida!" << endl;
        }
        system("cls");
    } while (opc != 9);

    return 0;
}