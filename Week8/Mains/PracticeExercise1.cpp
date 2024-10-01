#include "SubmarinoDestructor.h"

int main()
{
    Barco* barco1 = new Submarino("Azul", 17000);
    Barco* barco2 = new Destructor(80.5, 16000);
    SubmarinoDestructor* sd = new SubmarinoDestructor(20000,"Negro",100.15);
    barco1->getInfo();
    cout << endl;
    barco2->getInfo();
    cout << endl;
    sd->getInfo();

    delete barco1;
    delete barco2;
    delete sd;

    system("pause>0");
    return 0;
}
