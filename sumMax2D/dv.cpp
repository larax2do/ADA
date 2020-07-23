#include <iostream>



int subMax2D(int **A,int fs,int cs, int fi,int ci, bool vertical)
{
	if(fs==fi&&cs==ci)
	{
		return std::max(0,A[fs][cs]);
	}
	if(vertical)
	{
		if(cs!=ci)
		{
			int v=(cs+ci)/2;

			int maxizq=subMax2D(A,fs,cs,fi,v,!vertical);
			int maxder=subMax2D(A,fs,v+1,fi,ci,!vertical);

			int max2izq=A[fs][v];
			int max2der=A[fs][v+1];
			int maxcruz=A[fs][v];
			//std::cout<<"---------------------------------------"<<std::endl;
			for(int n=1;n<(fi+fs+2);n++)
			{
				//std::cout<<"maxcruz_prev1: "<<maxcruz<<std::endl;
				//std::cout<<"n="<<n<<std::endl;
				for(int nn=fs;nn<(fi-n+2);nn++)
				{

					//std::cout<<"nn="<<nn<<std::endl;
					int suma=0;
					for(int r=nn;r<nn+n;r++)
					{
						//std::cout<<"r="<<r<<std::endl;
						suma+=A[r][v];
					}
					max2izq=suma;
					//std::cout<<"suma="<<suma<<std::endl;
					//std::cout<<"ojo1"<<std::endl;
					for(int i =v-1;i>(cs-1);i--)
					{
						//std::cout<<"i="<<i<<std::endl;
						int acumulado=0;
						for(int r=nn;r<nn+n;r++)
						{
							acumulado+=A[r][i];
							//std::cout<<"r="<<r<<std::endl;
						}
						suma=suma+acumulado;
						//std::cout<<"suma="<<suma<<std::endl;
						max2izq=std::max(max2izq,suma);
					}
					//std::cout<<"ojo2"<<std::endl;
					suma =0;
					for(int r=nn;r<nn+n;r++)
						suma+=A[r][v+1];
					max2der=suma;
					//std::cout<<"suma="<<suma<<std::endl;
					//std::cout<<"ojo3"<<std::endl;
					for(int i =v+2;i<(ci+1);i++)
					{
						int acumulado=0;
						for(int r=nn;r<nn+n;r++)
							acumulado+=A[r][i];
						suma=suma+acumulado;
						//std::cout<<"suma="<<suma<<std::endl;
						max2der=std::max(max2der,suma);
					}
					//std::cout<<"maxcruz_prev1: "<<maxcruz<<std::endl;
					maxcruz=std::max(maxcruz,max2izq+max2der);
					//std::cout<<"maxcruz_prev: "<<maxcruz<<std::endl;
					//std::cout<<"actualizacion de maxcruz vertical= "<<maxcruz<<endl;

				}

					
			}
			//std::cout<<"["<<fs<<","<<cs<<"]["<<fi<<","<<ci<<"]"<<std::endl;
			//std::cout<<"maxizq: "<<maxizq<<std::endl;
			//std::cout<<"maxder: "<<maxder<<std::endl;
			//std::cout<<"maxcruz: "<<maxcruz<<std::endl;

			return std::max(std::max(maxder,maxizq),maxcruz);
		}
		else
		{
			return subMax2D(A,fs,cs,fi,ci,!vertical);
		}


		

			
	}
	else//horizontal
	{
		if(fs!=fi)
		{
			int h=(fs+fi)/2;
			int maxsup=subMax2D(A,fs,cs,h,ci,!vertical);
			int maxinf=subMax2D(A,h+1,cs,fi,ci,!vertical);

			int max2sup=A[h][cs];
			int max2inf=A[h+1][cs];
			int maxcruz=A[h][cs];
			//std::cout<<"---------------------------------------"<<std::endl;
			for(int n=1;n<(ci+cs+2);n++)
			{
				//std::cout<<"maxcruz_prev1: "<<maxcruz<<std::endl;
				//std::cout<<"n="<<n<<std::endl;
				for(int nn=cs;nn<(ci-n+2);nn++)
				{
					//std::cout<<"nn="<<nn<<std::endl;
					int suma=0;
					for(int r=nn;r<nn+n;r++)
						suma+=A[h][r];
					//std::cout<<"suma="<<suma<<std::endl;
					max2sup=suma;

					for(int i =h-1;i>(fs-1);i--)
					{
						int acumulado=0;
						for(int r=nn;r<nn+n;r++)
							acumulado+=A[i][r];
						suma=suma+acumulado;
						//std::cout<<"suma="<<suma<<std::endl;
						max2sup=std::max(max2sup,suma);
					}

					suma=0;

					for(int r=nn;r<nn+n;r++)
						suma+=A[h+1][r];
					//std::cout<<"suma="<<suma<<std::endl;
					max2inf=suma;

					for(int i =h+2;i<(fi+1);i++)
					{
						int acumulado=0;
						for(int r=nn;r<nn+n;r++)
							acumulado+=A[i][r];
						suma=suma+acumulado;
						//std::cout<<"suma="<<suma<<std::endl;
						max2inf=std::max(max2inf,suma);
					}
					
					maxcruz=std::max(maxcruz,max2inf+max2sup);
					//std::cout<<"maxcruz_prev: "<<maxcruz<<std::endl;
				}

			}

			//std::cout<<"["<<fs<<","<<cs<<"]["<<fi<<","<<ci<<"]"<<std::endl;
			//std::cout<<"maxsup: "<<maxsup<<std::endl;
			//std::cout<<"maxinf: "<<maxinf<<std::endl;
			//std::cout<<"maxcruz: "<<maxcruz<<std::endl;
			return std::max(std::max(maxinf,maxsup),maxcruz);
		}
		else
		{
			return subMax2D(A,fs,cs,fi,ci,!vertical);
		}
			


	}
	



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
	
	std::cout<<subMax2D(arreglo,0,0,n-1,n-1,true)<<std::endl;

	for (int i = 0; i < n; i++) 
	{
        delete [] arreglo[i];
    }
    delete [] arreglo;
	return 0;
}