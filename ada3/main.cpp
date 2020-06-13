#include <iostream>
#include <ctime>
#include<stdlib.h>
#include<time.h>
#include <fstream>


using namespace std;

////Practica de Laboratorio 2 de ADA
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
    Prueba(int longitud,int opcion)
    {
        cout << "-------------------------------------------------------------" << endl;
        switch(opcion)
        {
        case 1://ordenado de forma ascendente
            cout << "Generando arreglo ordenado de forma ascendente" << endl;
            srand(time(NULL));
            arreglo=new int[longitud]{};

            for(int i=0;i<longitud;i++)
            {
                arreglo[i]=i;//numeracion ordenada de forma ascendente
            }
            longArreglo=longitud;
            compara=0;
            asigna=0;
            crea=0;
            memoria=0;
            break;
        case 2://ordenado de forma descendente
            cout << "Generando arreglo ordenado de forma descendente" << endl;
            srand(time(NULL));
            arreglo=new int[longitud]{};

            for(int i=0;i<longitud;i++)
            {
                arreglo[i]=longitud-i;
            }
            longArreglo=longitud;
            compara=0;
            asigna=0;
            crea=0;
            memoria=0;
            break;
        default:
            cout << "Generando arreglo ordenado de numeros aleatorios" << endl;
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
            break;//numeros aleatorios


        }



    }
    ~Prueba()
    {
        delete [] arreglo;
    }
    void iniciar(int opcion)
    {

        cout << "Inicio de la prueba con n= " << longArreglo << endl;
        switch(opcion)
        {
        case 1://insert sort
            cout << "Prueba de Insert Sort" << endl;
            t0=clock();//Inicio del cronometro
            insertionSort(arreglo,longArreglo);
            t1=clock();//FIn de cronometro
            tiempo = (double(t1-t0)/CLOCKS_PER_SEC*1000);
            cout << "Execution Time InsertSort: " << tiempo <<"ms"<< endl;
            costo();//calculo del "costo"
            break;
        case 2://bubble sort
            cout << "Prueba de bubble Sort" << endl;
            t0=clock();//Inicio del cronometro
            bubbleSort(arreglo,longArreglo);
            t1=clock();//FIn de cronometro
            tiempo = (double(t1-t0)/CLOCKS_PER_SEC*1000);
            cout << "Execution Time BubbleSort: " << tiempo <<"ms"<< endl;
            costo();//calculo del "costo"
            break;
        case 3:
            cout<<"Prueba con merge sort"<<endl;
            t0=clock();//Inicio del cronometro
            mergesort(arreglo,longArreglo);
            t1=clock();//FIn de cronometro
            tiempo = (double(t1-t0)/CLOCKS_PER_SEC*1000);
            cout << "Execution Time mergeSort: " << tiempo <<"ms"<< endl;
            costo();//calculo del "costo"
            break;

        }
    }
public:
    int *arreglo;
    int longArreglo;
    unsigned t0,t1;
    unsigned compara,asigna,crea,memoria;
    unsigned cos;
    double tiempo;


    void costo()
    {   //cout<<"Comparaciones: "<<compara<<endl;
        //cout<<"Asignaciones: "<<asigna<<endl;
        //cout<<"Creaciones: "<<crea<<endl;
        cos=((compara*2)+(asigna*8)+(crea*200)+((50)+(longArreglo*10)));
        cout<<"El costo total es: "<<cos<<endl;
    }

    void insertionSort(int* &arr, int n)
    {
        int i;crea++;
        int key;crea++;
        int j;crea++;
        asigna++;
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
        compara++;

    }
    void bubbleSort(int* &arr, int n)
    {
        int i;crea++;
        int j;crea++;
        asigna++;
        for (i = 0; i < n-1; i++)
        {
            //del for
            asigna++;//actualizacion del i
            compara++;//for
            //
            asigna++;
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
            compara++;

        }
        compara++;

    }
    void swap(int *xp, int *yp)
    {
        int temp = *xp;crea++;
        *xp = *yp;asigna++;asigna++;
        *yp = temp;asigna++;
    }



    void intercala(int* &arr,int p,int q,int r)
    {
        int *tempB=new int[r+1]{}; memoria=memoria+r+1;
        int i;crea++;
        int j;crea++;
        asigna++;
        for(i=0;i<q+1;i++)
        {
            compara++;
            asigna++;
            tempB[i]=arr[i];asigna++;
        }
        compara++;
        asigna++;
        for(j=q+1;j<r+1;j++)
        {
            compara++;
            asigna++;
            tempB[r+q+1-j]=arr[j];asigna++;
        }
        compara++;
        i=p;asigna++;
        j=r;asigna++;
        int k;crea++;
        asigna++;
        for(k=p;k<r+1;k++)
        {
            compara++;
            asigna++;
            if(tempB[i]<=tempB[j])
            {
                compara++;
                arr[k]=tempB[i];asigna++;
                i=i+1;asigna++;
            }
            else
            {

                arr[k]=tempB[j];asigna++;
                j=j-1;asigna++;
            }
        }
        compara++;
        delete [] tempB;
    }
    void intercal2(int* &arr,int p,int q,int r)
    {
        int *tempB=new int[r+1]{}; memoria=memoria+r+1;
        int i;crea++;
        int j;crea++;
        asigna++;
        for(i=0;i<r;i++)
        {
            compara++;
            asigna++;
            tempB[i]=arr[i];asigna++;
        }
        compara++;
        asigna++;

        i=p;asigna++;
        j=q+1;asigna++;
        int k;crea++;
        asigna++;
        for(k=p;k<r+1;k++)
        {
            compara++;
            asigna++;
            int medio=q+1;asigna++;crea++;
            if(i<medio&&(j>=r||tempB[i]<=tempB[j]))
            {
                compara++;compara++;compara++;
                arr[k]=tempB[i];asigna++;
                i=i+1;asigna++;
            }
            else
            {
                compara++;compara++;compara++;
                arr[k]=tempB[j];asigna++;
                j=j+1;asigna++;
            }
        }
        compara++;
        delete [] tempB;
    }
    void mostrar(int *arreglo,int longArreglo)
    {
        for(int a=0;a<longArreglo;a++)
        {
            cout<<arreglo[a]<<"->";
        }
        cout<<endl;
    }
    void mergesort(int* &arr,int p,int r)
    {
        if(p<r)
        {
            compara++;
            crea++;
            int q=((p+r)/2);asigna++;
            mergesort(arr,p,q-1);
            mergesort(arr,q+1,r);
            intercal2(arr,p,q,r);
        }
        else
        {
            compara++;
        }
    }
    void mergesort(int* &arr,int longArreglo)
    {
        mergesort(arr,0,longArreglo-1);
    }



};




int main()
{   //necesita c++11 o superior









    ofstream archivo;

    archivo.open("datos.csv");







    //int pruebas[]={500, 1000, 2000, 5000, 10000, 20000};
    Prueba *uno;


    int opcionArreglo[]={1,2,3};//1:ascendente, 2: descendente, otro:aleatorio
    for (auto &y:opcionArreglo)
    {
        for (int a=1;a<1001;a++)
        {
            int opcionAlgoritmo[]={3};//1:insert sort, 2:bubble sort, 3: merge
            for (auto &z:opcionAlgoritmo)
            {
                uno=new Prueba(a,y);
                uno->iniciar(z);
                archivo<<uno->cos<<";";
                delete uno;
            }
            archivo<<endl;


        }
         archivo<<endl;



    }
    archivo.close();




    return 0;
}
