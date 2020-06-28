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
void verificar(int* A, int n)
{
	for (int i=0;i<n-1;i++)
	{
		if(A[i]>A[i+1])
			std::cout<<"fallo"<<std::endl;
	}
}


int particiona(int *A,int p,int r)
{
	int x=A[r];
	int i =p-1;
	for(int j=p;j<r;j++)
	{
		if(A[j]<=x)
		{
			i=i+1;
			std::swap(A[i],A[j]);
		}
		
	}
	std::swap(A[i+1],A[r]);
	return i+1;
}

void quick(int *A,int p, int r,int &nmedio, bool &si)
{
	if(si)
	{
		return;
	}
	else
	{
		if(p<r)
		{
			
			int q=particiona(A,p,r);
		
			if (q==nmedio)
			{
				si=true;
				nmedio=A[q];
				return;
			}
			else if(q>nmedio)
			{
				quick(A,p,q-1,nmedio,si);
			}
			else
			{
				quick(A,q+1,r,nmedio,si);
			}
		//std::cout<<"pivote: "<<A[q]<<"en"<<q<<std::endl;
			
			
		}
	}
	
}




int quickSort(int* A, int n)
{
	int nmedio=(n-1)/2;
	bool si=false;
	quick(A,0,n-1,nmedio,si);
	return nmedio;
}

int main()
{
	int arr[8001];
	for(int j=0;j<8000;j++)
	{
		for(int i=0; i<8001;i++)
		{
			cin>>arr[i];
		}
		std::cout<<quickSort(arr,8001)<<std::endl;
	}
	
	

	
	return 0;
}