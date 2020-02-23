
#include"slladt.h"

#ifndef STACKADT_H_
#define STACKADT_H_

template<class T>
class stackAdt
{
	slladt<T> l1;
	node<T>* top;
public:
	stackAdt();
	virtual ~stackAdt();
	void push(T);
	T pop();
	T peep();
	bool isempty();
	void display1();
};

#endif /* STACKADT_H_ */
