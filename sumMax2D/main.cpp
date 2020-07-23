#include <iostream>

void sumaMaxim2D(int **A, int n, int &masx,int &fI,int &fS,int &cI,int &cS)
{
	
	int **B = new int*[n];
	for (int i = 0; i < n; i++)
	{
    	B[i] = new int[n];
	}


	B[0][0]=A[0][0];
	for (int i=1;i<n;i++)
	{
		B[0][i]=B[0][i-1]+A[0][i];
		B[i][0]=B[i-1][0]+A[i][0];
	}
/*
for(int z=0;z<n;z++)
	{
		for (int k=0;k<n;k++)
		{
			std::cout<<B[z][k]<<" ";
		}
		std::cout<<"sfgsfg"<<std::endl;
	}
*/
	std::cout<<"n es "<<n<<std::endl;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			B[i][j]=A[i][j]+B[i-1][j]+B[i][j-1]-B[i-1][j-1];
		}	
	}

/*
	for(int z=0;z<n;z++)
	{
		for (int k=0;k<n;k++)
		{
			std::cout<<B[z][k]<<" ";
		}
		std::cout<<"sfgsfg"<<std::endl;
	}
*/

	masx=B[0][0];
	int mas=0;
	int sobraArriba=0;
	int sobraIzquierda=0;
	int sobraDoble=0;
	for(int fSuperior=0;fSuperior<n;fSuperior++)
	{
		for(int cSuperior=0;cSuperior<n;cSuperior++)
		{
			for(int fInferior=fSuperior;fInferior<n;fInferior++)
			{
				for(int cInferior=cSuperior;cInferior<n;cInferior++)
				{
					sobraArriba=0;
					sobraIzquierda=0;
					sobraDoble=0;
					if(fSuperior>0)
					{
						sobraArriba=B[fSuperior-1][cInferior];
					}
					if(cSuperior>0)
					{
						sobraIzquierda=B[fInferior][cSuperior-1];
					}
					if(fSuperior!=0&&cSuperior!=0)
					{
						sobraDoble=B[fSuperior-1][cSuperior-1];
					}
					mas=B[fInferior][cInferior]-sobraIzquierda-sobraArriba+sobraDoble;
					//std::cout<<"["<<fSuperior<<","<<cSuperior<<"]["<<fInferior<<","<<cInferior<<"]"<<mas<<std::endl;
					if(mas>masx)
					{
						masx=mas;

						fI=fInferior;
						fS=fSuperior;
						cS=cSuperior;
						cI=cInferior;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) 
	{
        delete [] B[i];
    }
    delete [] B;
}



int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	int **arreglo = new int*[n];
	for (int i = 0; i < n; i++)
	{
    	arreglo[i] = new int[n];
	}
	
	for(int i=0; i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			std::cin>>arreglo[i][j];
		}
	}

	int masx=0;
	int fI=0;
	int fS=0;
	int cS=0;
	int cI=0;
	std::cout<<"n es "<<n<<std::endl;
	sumaMaxim2D(arreglo,n,masx,fI,fS,cI,cS);
	std::cout<<masx<<std::endl;

	for (int i = 0; i < n; i++) 
	{
        delete [] arreglo[i];
    }
    delete [] arreglo;
	return 0;
}