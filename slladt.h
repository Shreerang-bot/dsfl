
#ifndef SLLADT_H_
#define SLLADT_H_
template<typename T>
struct node
{
    T data;
	struct node<T>* next;

};
template<class T>
class slladt
{
 node<T>* head;
public:
	slladt();
    node<T>* getnode();
    node<T>* head_sll();
	bool head_1();
	void create();
	void display();
	void insert_beg(T);
	T delete_beg();
	T data_head();
};

#endif /* SLLADT_H_ */
