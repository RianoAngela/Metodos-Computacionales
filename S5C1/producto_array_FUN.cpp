#include <iostream>
using namespace std;

void producto(int array1[4], int array2[4])
void ppunto(int array1[4],int array2[4])


int main()
{
    int array1[]={1,2,3,4,5};
    int array2[]={10,20,30,40,50};
    cout<< producto(array1,array2); 
    cout<< ppunto(array1,array2);
    return 0;
}
    
void producto (int array1[4],int array2[4])
{
    int prod=0;
    for (int i=0;i<4;i++)
    {
        prod=array1[i]*array2[i];
    } 
}

void ppunto(int array1[4],int array2[4])
{
    int productopunto=0;
    for (int k=0;k<4;k++)
    {
        productopunto=productopunto +array1[k]*array2[k];
    }
}
