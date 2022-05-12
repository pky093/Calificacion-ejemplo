#include<iostream>
using namespace std;
void calificativo();
//hola mundo 
void notificar(char Calificativo)
{
    char sn;
    switch (Calificativo)
    {  
    case'A':case'a':cout << "Bueno\n"; break;
    case'B':case'b':cout << "Regular\n"; break;
    case'C':case'c':cout << "Malo\n"; break;
    case'D':case'd':cout << "Pesimo\n"; break;
    default:
    {
        cout << "Inv\xa0lido. Desea Ingresar nuevamente s/S: "; cin >> sn;
        if (sn == 'S' || sn == 's')
            calificativo();
    }
    }

}

void calificativo()
{
    char Calif;
    cout << "Ingrese Calificativo (A,B,C o D): ";
    cin >> Calif;

    notificar(Calif);
}

void main()
{
    calificativo();
}
