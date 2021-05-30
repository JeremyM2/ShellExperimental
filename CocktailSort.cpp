#include <iostream>
#include <cstdlib> 
#define MAX_RAND 100
// CocktailSort
void printArray(int *a,int tam){

    for (int  i = 0 ; i < tam; i++)
    {
        std::cout<<a[i]<<' ';
    }
    std::cout<<'\n';
    
}

void CocktailSort(int v[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped)
    {
        swapped = false;
 
        for (int i = start; i < end; ++i)
        {
            if (v[i] > v[i + 1]) {
                int aux = v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                swapped = true;
            }
        }
        
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i)
        {
            if (v[i] > v[i + 1]) {
                int aux = v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                swapped = true;
            }
        }
        ++start;
    }
}
void setArray(int *a, int n){
    for (int i = 0; i < n; i++)
    {
        a[i]=rand()%MAX_RAND;
    }   
}

int main() {
  int v[] = {123, 45, 3, 4, 355, 32, 12, 1,10,2};
  int tam = 10;
  setArray(v,tam);
  printArray(v, tam);
  CocktailSort(v, tam);
  std::cout << "Sorted array: \n";
  printArray(v, tam);
}