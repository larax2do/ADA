#include <iostream>

using namespace std;


//Nombre: Thales Panibra
//https://github.com/larax2do/ADA/tree/master/sumMax

int trimax(int a,int b,int c)
{
    return max(a,max(b,c));
}

//algoritmo de suma maxima aplicando divide y conquista
//modificado para que retorne los valores extremos
void segmentoMaximoDV(int *A, int p, int r,int &pri,int &ul, int &sumita)
{
    if(p==r)
    {
        if(max(0,A[p])==0)
        {
            sumita=0;
            return;
        }
        else
        {
            pri=p;
            ul=p;
            sumita=A[p];
            return;
        }

    }
    int q=(p+r)/2;
    int qmas=q+1;
    int Iizq=-1;
    int Fizq=-2;
    int Ider=-3;
    int Fder=-4;
    int maxizq=0;
    segmentoMaximoDV(A,p,q,Iizq,Fizq,maxizq);
    int maxder=0;
    segmentoMaximoDV(A,qmas,r,Ider,Fder,maxder);
    int max2izq=A[q];
    int suma=max2izq;
    int Imedio=q-1;
    for(int i=Imedio;i>(p-1);i--)
    {
        suma=suma+A[i];
        max2izq=max(max2izq,suma);
        if(max2izq==suma)
        {
            Imedio=i;
        }
    }
    int max2der=A[q+1];
    suma=max2der;
    int Fmedio=q+2;
    for(int j=Fmedio;j<r+1;j++)
    {
        suma=suma+A[j];
        max2der=max(max2der,suma);
        if(max2der==suma)
        {
            Fmedio=j;
        }
    }
    int maxcruz=max2der+max2izq;
    int maxim=max(maxder,max(maxizq,maxcruz));
    if(maxim==maxder)
    {
        pri=Ider;
        ul=Fder;
        sumita=maxder;
    }
    else if(maxim==maxizq)
    {
        pri=Iizq;
        ul=Fizq;
        sumita=maxizq;
    }
    else
    {
        pri=Imedio;
        ul=Fmedio;
        sumita=maxcruz;
    }

}

//sobrecarga de la funcion para que llamar sea mas facil
void segmentoMaximoDV(int* A, int n,int ruta)
{
    int pri=-1;
    int ul=-2;
    int sumito=0;
    segmentoMaximoDV(A,0,n-1,pri,ul,sumito);
    if (sumito!=0)
    {
        cout<<"La mejor parte de la ruta "<<ruta<<" es entre las calles "<<pri+1<<" y "<<ul+2<<endl;
    }
    else
    {
        cout<<"La ruta "<<ruta<<" no tiene calles interesantes"<<endl;
    }
}

//Algoritmo de segemento de suma maxima con costo lineal
void segmentoMaximoLIN(int *A,int n,int &sumaMax, int& e, int& d)
{
    sumaMax=0;
    e=0;
    d=-1;

    int suma=0;
    int i=0;
    int f=-1;
    while(f<n-1)
    {
        f=f+1;
        suma=suma+A[f];
        if(suma<0)
        {
            suma=0;
            i=f+1;
        }
        else if(suma>=sumaMax)
        {
            sumaMax=suma;
            e=i;
            d=f;
        }
    }
}

void segmentoMaximoLIN(int *A,int n,int ruta)
{
    int pri=-1;
    int ul=-2;
    int sumito=0;
    segmentoMaximoLIN(A,n,sumito,pri,ul);
    if (sumito!=0)
    {
        cout<<"La mejor parte de la ruta "<<ruta<<" es entre las calles "<<pri+1<<" y "<<ul+2<<endl;
    }
    else
    {
        cout<<"La ruta "<<ruta<<" no tiene calles interesantes"<<endl;
    }
}

int main()
{
    int rutas=0;
    int calles=0;
    int *caminos=nullptr;
    int ncaminos=0;

    cin>>rutas;
    for(int i=1;i<rutas+1;i++)
    {
        cin>>calles;
        ncaminos=calles-1;
        caminos=new int[ncaminos]{};
        for(int j=0;j<ncaminos;j++)
        {
            cin>>caminos[j];
        }

        //Aqui podemos elejir que algoritmo usar
        segmentoMaximoLIN(caminos,ncaminos,i);
        segmentoMaximoDV(caminos,ncaminos,i);
        delete [] caminos;


    }


    int arr[]={-10,-50,-70,-50,-1};
    //{31,-41,59,26,-53,58,97,-93,-23,84};
    int sumMax=0;
    int e=0;
    int d=-1;
    segmentoMaximoLIN(arr,5,sumMax,e,d);
    cout << "El algoritmo termino! y la suma max es: "<<sumMax<<" entre: "<<e<<" y "<<d<< endl;
    int ini=-10;
    int fin=-11;
    int sumita=0;
    segmentoMaximoDV(arr,0,4,ini,fin,sumita);
    cout<<"Termino: " <<sumita<<" con inicio: "<<ini<<" y fin: "<<fin<<endl;
    return 0;
}
