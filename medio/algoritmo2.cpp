#include <iterator>
#include <iostream>
#include <algorithm> // for std::partition
#include <functional> // for std::less

#include <iterator>     // std::iterator, std::input_iterator_tag

using namespace std;

void mostrar(int *A,int n)
{
	for (int i=0;i<n;i++)
	{
		std::cout<<A[i]<<" ";
	}
	std::cout<<std::endl;
}




template<typename RandomAccessIterator, typename Order>
void quicksort(RandomAccessIterator first, RandomAccessIterator last, Order order,RandomAccessIterator nmedio,bool &si)
{
	if (last - first > 1)
 	{
 		if(si)
 		{
 			return;
 		}
    	RandomAccessIterator split = std::partition(first+1, last, std::bind2nd(order, *first));
    	if(split==nmedio)
    	{
    		si=true;

    	}
    	std::iter_swap(first, split-1);
    	quicksort(first, split-1, order,nmedio,si);
    	quicksort(split, last, order,nmedio,si);
	}
}
 
template<typename RandomAccessIterator>
RandomAccessIterator quicksort(RandomAccessIterator first, RandomAccessIterator last,RandomAccessIterator nmedio)
{

	
	bool si=false;
	quicksort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>(),nmedio,si);
	return nmedio;
}



int main()
{
	/*
	std::array<int,8001> numbers;
	auto nmedio=numbers.begin()+((numbers.size()-1)/2);
	for(int j=0;j<8000;j++)
	{
		for(int i=0; i<8001;i++)
		{
			cin>>numbers[i];
		}
		cout<<*(quicksort(numbers.begin(),numbers.end(),nmedio))<<std::endl;
	}
	
	*/


	/*
	std::array<int,11> numbers{{9,8,7,6,5,4,3,2,1,10,11}};

	auto nmedio=numbers.begin()+((numbers.size()-1)/2);
	
	//cout<<*nmedio;
  	cout<<*(quicksort(numbers.begin(),numbers.end(),nmedio));

	*/

	int hola[6]={1,2,3,4,5,6};

	auto var=hola.begin();

	//cout<<*numbers.end();

  	//for(const auto& s: numbers)
        //std::cout << s << ' ';

	return 0;
}