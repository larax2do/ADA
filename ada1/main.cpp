#include <iostream>
#include <ctime>
#include<stdlib.h>
#include<time.h>

using namespace std;

////Practica de Laboratorio 1 de ADA
////NOMBRE: Thales Panibra

//[1] En el constructor se crea el arreglo de n elementos
//[2] En Iniciar se ejecuta el contador de tiempo
//[3] Se agredo al algoritmo contadores para calcular el "costo"

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
        compara=0;
        asigna=0;
        crea=0;
        memoria=0;
    }
    Prueba(int longitud)
    {
        srand(time(NULL));
        arreglo=new int[longitud]{};

        for(int i=0;i<longitud;i++)
        {
            arreglo[i]=0+rand()%(1000001-0);//Numero aleatorio
        }
        longArreglo=longitud;
        compara=0;
        asigna=0;
        crea=0;
        memoria=0;


    }
    ~Prueba()
    {
        delete [] arreglo;
    }
    void iniciar(int opcion)
    {
        double time;
        cout << "Inicio de la prueba con n= " << longArreglo << endl;
        switch(opcion)
        {
        case 1://insert sort
            t0=clock();//Inicio del cronometro
            insertionSort(arreglo,longArreglo);
            t1=clock();//FIn de cronometro
            time = (double(t1-t0)/CLOCKS_PER_SEC);
            cout << "Execution Time InsertSort: " << time << endl;
            costo();//calculo del "costo"
            break;
        case 2://bubble sort
            t0=clock();//Inicio del cronometro
            bubbleSort(arreglo,longArreglo);
            t1=clock();//FIn de cronometro
            time = (double(t1-t0)/CLOCKS_PER_SEC);
            cout << "Execution Time BubbleSort: " << time << endl;
            costo();//calculo del "costo"
            break;

        }
    }
private:
    int *arreglo;
    int longArreglo;
    unsigned t0,t1;
    unsigned compara,asigna,crea,memoria;


    void costo()
    {   cout<<"Comparaciones: "<<compara<<endl;
        cout<<"Asignaciones: "<<asigna<<endl;
        cout<<"Creaciones: "<<crea<<endl;
        cout<<"El costo total es: "<<((compara*2)+(asigna*8)+(crea*200)+((memoria*50)+(longArreglo*10)))<<endl;
    }

    void insertionSort(int* &arr, int n)
    {
        int i;crea++;
        int key;crea++;
        int j;crea++;
        for (i = 1; i < n; i++)
        {
            //del for
            asigna++;//actualizacion del i
            compara++;//for
            //
            key = arr[i];asigna++;
            j = i - 1;asigna++;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];asigna++;
                j = j - 1;asigna++;
                //del while
                compara++;
                compara++;
                //
            }
            arr[j + 1] = key;asigna++;

        }

    }
    void bubbleSort(int* &arr, int n)
    {
        int i;crea++;
        int j;crea++;
        for (i = 0; i < n-1; i++)
        {
            //del for
            asigna++;//actualizacion del i
            compara++;//for
            //
            for (j = 0; j < n-i-1; j++)
            {
                //del for
                asigna++;//actualizacion del i
                compara++;//for
                //
                if (arr[j] > arr[j+1])
                {
                    compara++;
                    swap(&arr[j], &arr[j+1]);
                }

            }

        }

    }
    void swap(int *xp, int *yp)
    {
        int temp = *xp;crea++;
        *xp = *yp;asigna++;asigna++;
        *yp = temp;asigna++;
    }



};





int main()
{
    //Para ejecutar tiene que crear una clase asigando el tamanio del arreglo dinamico
    Prueba *uno=new Prueba(10000);
    //Parara ejecutar llame la funcion iniciar indicando "1" para insert sort y 2 para Bubble sort
    uno->iniciar(1);
    delete uno;//No olvide eliminar la memoria dinamica xd
    Prueba *dos=new Prueba(10000);
    dos->iniciar(2);
    delete dos;
    return 0;
}
