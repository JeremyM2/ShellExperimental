#include <iostream>
#include <cstdlib>   //para utilizar srand y rand
#include <chrono>   //DIFICIL
#define MAX_RAND 100
void setArray(int *a,int n);
void printArray(int *a,int n);
void shellSort(int v[], int n);
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int n = 10000;         //tamanio del arreglo
    int repeticiones = 500;
    int v[n];           
    
    std::chrono::high_resolution_clock::time_point ti_ss,tf_ss; //reloj preciso

    for (size_t i = 100; i < n; i=i+100)
    {
        std::chrono::nanoseconds acum{};//definiendo acumulador
        for (size_t j = 0; j < repeticiones; j++)
        {
            setArray(v,i);
            ti_ss = std::chrono::high_resolution_clock::now();//tiempo_inicial
            shellSort(v,i); 
            tf_ss = std::chrono::high_resolution_clock::now();//tiempo final
            acum+=std::chrono::duration_cast<std::chrono::nanoseconds>(tf_ss-ti_ss);
        }

        std::cout<<i<<','<<acum.count()/repeticiones<<'\n';//tomando tiempo promedio
        
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
void shellSort(int v[], int n) {

  for (int intervalo = n / 2; intervalo > 0; intervalo /= 2) 
  {
    for (int i = intervalo; i < n; i += 1) 
    {
     int temp = v[i];
     int j;
        for (j = i; j >= intervalo && v[j - intervalo] > temp; j -= intervalo) 
        {
            v[j] = v[j - intervalo];
        }
      v[j] = temp;
    }
  }
}