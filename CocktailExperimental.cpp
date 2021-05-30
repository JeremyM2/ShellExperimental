#include <iostream>
#include <cstdlib>
#include <chrono>
#define MAX_RAND 100
void setArray(int *a,int n);
void printArray(int *a,int n);
void CocktailSort(int v[], int n);
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int n = 10100;         
    int repeticiones = 500;
    int v[n];           
    
    std::chrono::high_resolution_clock::time_point ti_ss,tf_ss;

    for (size_t i = 100; i < n; i=i+100)
    {
        std::chrono::nanoseconds acum{};
        for (size_t j = 0; j < repeticiones; j++)
        {
            setArray(v,i);
            ti_ss = std::chrono::high_resolution_clock::now();
            CocktailSort(v,i);
            tf_ss = std::chrono::high_resolution_clock::now();
            acum+=std::chrono::duration_cast<std::chrono::nanoseconds>(tf_ss-ti_ss);
        }

        std::cout<<i<<','<<acum.count()/repeticiones<<'\n';
        
    }
        
    return 0;
}

void setArray(int *a, int n){
    for (int i = 0; i < n; i++)
    {
        a[i]=rand()%MAX_RAND;
    }   
}

void printArray(int *a,int n){
    for (int  i = 0; i < n; i++)
    {
        std::cout<<a[i]<<'\t';
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