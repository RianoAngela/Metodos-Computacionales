#include<iostream>
using namespace std;

int main()
{
    int numero=100;
    for (int i=0; i<numero;i++)
    {
        if (i%3==0 && i%5!=0)
        {
            cout<<i;
        }
    }
    return 0;
}