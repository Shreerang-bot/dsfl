
#include "slladt.h"
#include<iostream>

using namespace std;

template<class T>
slladt<T>::slladt()
{
	head=NULL;
}

template<class T>
node<T>* slladt<T>::getnode()
{
	node<T> * p;
	p=new node<T>;
	cout<<"Enter the data::";
	cin>>p->data;
	p->next=NULL;

	return p;
}
template<class T>
void slladt<T>::create()
{
	int n,i;
	node<T>* p;
	cout<<"Enter number of elements you want:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		if(head==NULL)
		{
			head=getnode();
			p=head;
		}
		else
		{
			p->next=getnode();
			p=p->next;
		}
	}
}
template<class T>
void slladt<T>::display()
{
	node<T> *p;
	p=head;
	cout<<"List is::";
	while(p!=NULL)
	{
		cout<<p->data<<"--->";
		p=p->next;
	}
}
template<class T>
void slladt<T>::insert_beg(T x)
{
	node<T>* p;
	p=new node<T>;
	p->data=x;

	p->next=head;
	head=p;
}
template<class T>
T slladt<T>::delete_beg()
{
	node<T>*p;
	T x;
	if(head==NULL)
		return -1;
	else
	{
		p=head;
		x=head->data;
		head=p->next;
		delete p;
		return x;

	}
}

template<class T>
T slladt<T>::data_head()
{
	if(head==NULL)
		return -1;
	else
	{
		return head->data;
	}
}

template<class T>
bool slladt<T>::head_1()
{
	if(head==NULL)
		return true;
	else
		return false;

}

template<class T>
node<T>* slladt<T>::head_sll()
{
	return head;
}
