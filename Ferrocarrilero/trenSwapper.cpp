#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


void mostrar(int *A,int n)
{
	for (int i=0;i<n;i++)
	{
		std::cout<<A[i]<<" ";
	}
	std::cout<<std::endl;
}

void swapLargo(int *A, int este, int conEste,int &contador)
{

	for(int i=este;i<conEste;i++)
	{
		
		std::swap(A[i],A[i+1]);
		contador++;
	}
	
	for(int j=conEste-1;j>este;j--)
	{
		std::swap(A[j],A[j-1]);
		contador++;
	}
	

	
}


void verificar(int* A, int n)
{
	for (int i=0;i<n-1;i++)
	{
		if(A[i]>A[i+1])
			std::cout<<"fallo"<<std::endl;
	}
}


int particiona(int *A,int p,int r,int &contador)
{
	int x=A[r];
	int i =p-1;
	for(int j=p;j<r;j++)
	{
		if(A[j]<=x)
		{
			i=i+1;
			swapLargo(A,i,j,contador);
			//contador+=((j-i)*2)-1;
		}
		
	}
	swapLargo(A,i+1,r,contador);
	//contador+=((r-i)*2);//((r-(i+1))*2)-1
	return i+1;
}

void quick(int *A,int p, int r,int &contador)
{
	if(p<r)
	{			
		int q=particiona(A,p,r,contador);
		quick(A,p,q-1,contador);
		quick(A,q+1,r,contador);			
	}	
}


int resuelve(int* A, int n)
{
	int swaps=0;
	quick(A,0,n-1,swaps);
	return swaps;
}




int main()
{
	int nCasos,nVagones;
	int vagones[52];

	std::cin>>nCasos;
	for(int caso=0;caso<nCasos;caso++)
	{
		std::cin>>nVagones;
		for (int i = 0; i < nVagones; ++i)
		{
			std::cin>>vagones[i];
		}
		int resultado=resuelve(vagones,nVagones);
		std::cout<<"La mejor cantidad de swaps de trenes es"<<resultado<<std::endl;
	}
	//int prueba[10]={9,8,7,6,5,4,3,2,1,5};
	//cout<<"En esta vaina se usaron: "<<resuelve(prueba,10);
	

	
	//mostrar(prueba,10);
	return 0;
}