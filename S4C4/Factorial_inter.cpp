#include<iostream>
using namespace std;

int factorial(int);
int main();
{
    cout << "Por favor ingrese un numero: ";
    int numero;
    cin >> numero;
    int factor=0;
    if (numero==0)
    {
        factor=1;
    }
    else if (numero<0)
    {
        factor=0;
    }
    else
    {
        factorial(numero);
    }
    return 0;
}

int factorial(int numero)
{
    for (int i=1; i<=numero;i++)
    {
        int factor=factor*i;
    }
}