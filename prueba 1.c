#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 7
//Inicio ejercicio 1
struct metadatos_t {
    int minimo;
    int maximo;
    int promedio_entero;
};


struct metadatos_t stats(int a[], int k){

    struct metadatos_t temp;
    int prom = 0;
    temp.maximo=a[0],temp.minimo=a[0],temp.promedio_entero=0;
    for (int i = 0; i <= k; i++)
    {
       if (a[i]>temp.maximo)
       {
           temp.maximo=a[i];
       } else if (a[i]<temp.minimo)
       {
           temp.minimo=a[i];
       }
       prom+=a[i];
    }
    temp.promedio_entero=(prom/(k+1));
    
    return temp;

}

void imprime_struct( struct metadatos_t p){
  printf("El maximo es %d, el minimo es %d y el promedio es %d\n",p.maximo,p.minimo,p.promedio_entero); 

}
//Fin ejercicio 1

void pedirArreglo(int a[], int n_max){
    for (int i = 0; i < n_max; i++)
    {
        printf("Ingrese el elemento %d\n",i+1);
        scanf("%d",&a[i]);
    }
}


int pedirEntero()
{
    int n;
    printf("Ingrese un indice k: ");
    scanf("%d", &n);
    assert(n>0);
    return n;
}

void imprimeArreglo(int a[], int n_max){
    printf("{ ");
    for (int i = 0; i < n_max; i++)
    {
        printf("%d ",a[i]);
    }
    printf("}\n");
}

void ordenar(int a[], int tam){
  int temp;
  for (int i = 0; i < (tam - 1); i++) 
  { 
    for (int j = 0; j < tam-i-1; j++) 
    { 
      if (a[j+1] < a[j]) 
      { 
        temp = a[j+1]; 
        a[j+1]= a[j]; 
        a[j] = temp; 
      } 
    } 
  } 
}

int main(){
    int k;
    int ar[N];
    pedirArreglo(ar,N);
    k=pedirEntero();
    assert(k>=0 && k<N);
    imprime_struct(stats(ar,k));
    ordenar(ar,N);
    printf("El arreglo ordenado es: ");
    imprimeArreglo(ar,k);

    return 0;
}
