
#include "stackAdt.h"
#include"slladt.cpp"
#include<iostream>
using namespace std;

template<class T>
stackAdt<T>::stackAdt()
{
     top=NULL;
}
template<class T>
stackAdt<T>::~stackAdt()
{
	// TODO Auto-generated destructor stub
}

template<class T>
void stackAdt<T>::push(T x)
{
	l1.insert_beg(x);
	top=l1.head_sll();
}

template<class T>
T stackAdt<T>::pop()
{
	T x;
	if(!isempty())
	{
		x=l1.delete_beg();
		top=l1.head_sll();
		return x;
	}
	/*else
		cout<<"Stack is empty";*/
}

template<class T>
T stackAdt<T>::peep()
{
	if(!isempty())
         return l1.data_head();
	else
		return -1;
}

template<class T>
bool stackAdt<T>::isempty()
{
	if(l1.head_1())
		return true;
	else
		return false;
}

template<class T>
void stackAdt<T>::display1()
{
	l1.display();
}
