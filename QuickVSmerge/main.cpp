#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <fstream>

using namespace std;


class Prueba
{
public:
    Prueba()
    {
        int longitud=10000;
        srand(time(NULL));
        arreglo=new int[longitud]{};

        for(int i=0;i<longitud;i++)
        {
            arreglo[i]=0+rand()%(10001-0);//Numero aleatorio
        }

        longArreglo=longitud;

    }
    Prueba(int longitud,int opcion)
    {
        cout << "-------------------------------------------------------------" << endl;
        switch(opcion)
        {
        case 1://ordenado de forma ascendente
            cout << "Generando arreglo ordenado de forma ascendente" << endl;
            srand(time(NULL));
            arreglo=new int[longitud]{};
            arreglo1=new int[longitud]{};

            for(int i=0;i<longitud;i++)
            {
                arreglo[i]=i;//numeracion ordenada de forma ascendente
                arreglo1[i]=i;
            }
            longArreglo=longitud;
            longArreglo1=longitud;
            break;
        case 2://ordenado de forma descendente
            cout << "Generando arreglo ordenado de forma descendente" << endl;
            srand(time(NULL));
            arreglo=new int[longitud]{};
            arreglo1=new int[longitud]{};

            for(int i=0;i<longitud;i++)
            {
                arreglo[i]=longitud-i;
                arreglo1[i]=longitud-i;
            }
            longArreglo=longitud;
            longArreglo1=longitud;
            break;
        default:
            cout << "Generando arreglo ordenado de numeros aleatorios" << endl;
            srand(time(NULL));
            arreglo=new int[longitud]{};
            arreglo1=new int[longitud]{};
            int num=0;

            for(int i=0;i<longitud;i++)
            {
                num=0+rand()%(1000001-0);//Numero aleatorio
                arreglo[i]=num;
                arreglo1[i]=num;
            }
            longArreglo=longitud;
            longArreglo1=longitud;
            break;//numeros aleatorios
        }


    }
    ~Prueba()
    {
        delete [] arreglo;
        delete [] arreglo1;
    }
    void iniciar(int opcion)
    {
        cout << "Inicio de la prueba con n= " << longArreglo << endl;
        switch(opcion)
        {

        case 1:
            cout<<"Prueba con merge sort"<<endl;
            t0=clock();//Inicio del cronometro
            mergesort(arreglo,longArreglo);
            t1=clock();//FIn de cronometro
            tiempo = (double(t1-t0)/CLOCKS_PER_SEC*1000);
            cout << "Execution Time mergeSort: " << tiempo <<"ms"<< endl;
            break;

        case 2://Quick sort
            cout << "Prueba de Quick Sort" << endl;
            t0=clock();//Inicio del cronometro
            quicksort(arreglo1,longArreglo1);

            t1=clock();//FIn de cronometro
            tiempo = (double(t1-t0)/CLOCKS_PER_SEC*1000);
            cout << "Execution Time QuickSort: " << tiempo <<"ms"<< endl;
            break;

        }
    }
public:
    int *arreglo;
    int longArreglo;
    int *arreglo1;
    int longArreglo1;
    unsigned t0,t1;
    double tiempo;

    void intercala(int* &arr,int p,int q,int r)
    {
        int *tempB=new int[r-p+1]{};
        int i;
        int j;
        for(i=p;i<q+1;i++)
        {
            tempB[i-p]=arr[i];
        }
        for(j=q+1;j<r+1;j++)
        {
            tempB[j-p]=arr[r+q+1-j];
        }
        i=p-p;
        j=r-p;
        int k;
        for(k=p;k<r+1;k++)
        {
            if(tempB[i]<=tempB[j])
            {
                arr[k]=tempB[i];
                i=i+1;
            }
            else
            {

                arr[k]=tempB[j];
                j=j-1;
            }
        }
        delete [] tempB;
    }

    void mergesort(int* &arr,int p,int r)
    {
        if(p<r)
        {
            int q=((p+r)/2);
            mergesort(arr,p,q);
            mergesort(arr,q+1,r);
            intercala(arr,p,q,r);
        }
    }
    void mergesort(int* &arr,int longArreglo)
    {
        mergesort(arr,0,longArreglo-1);
        verificar(arr,longArreglo);
        //mostrar(arr,longArreglo);
    }
    static int compare (const void * a, const void * b)
    {
        return ( *(int*)a - *(int*)b );
    }

    void quicksort(int* &arr,int longArreglo)
    {
        qsort(arr,longArreglo,sizeof(int),compare);
        verificar(arr,longArreglo);
    }
    void mostrar(int *arreglo,int longArreglo)
    {
        for(int a=0;a<longArreglo;a++)
        {
            cout<<arreglo[a]<<"->";
        }
        cout<<endl;
    }

    void verificar(int* arreglo, int longi)
    {
        for(int a=0;a<longArreglo-1;a++)
        {
            if(arreglo[a]>arreglo[a+1])
            {
                cout<<"error"<<"en:->"<<arreglo[a]<<"->"<<arreglo[a+1]<<"->"<<endl;
                return;
            }
        }
    }
};

int main()
{
    ofstream archivo;

    archivo.open("datos7.csv");

    Prueba *uno;
    archivo<<"n;merge;quick"<<endl;

    for(int i=1000;i<1000001;i=i+1000)
    {
        uno=new Prueba(i,3);
        archivo<<i<<";";
        uno->iniciar(1);
        archivo<<uno->tiempo<<";";
        uno->iniciar(2);
        archivo<<uno->tiempo<<";";
        delete uno;
        archivo<<endl;
    }
    cout << "Hello world!" << endl;
    archivo.close();
    return 0;
}
