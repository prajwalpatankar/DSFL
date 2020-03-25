/*
 * stack.cpp
 *
 *  Created on: 18-Dec-2019
 *      Author: g10
 */

#include "stack.h"

template<class T>
stack<T>::stack() {
	// TODO Auto-generated constructor stub
	top=NULL;
}

template<class T>
stack<T>::~stack() {
	// TODO Auto-generated destructor stub
	node *temp;
	if(top==NULL)
	{
		return;
	}
	while(top!=NULL)
	{
		temp=top;
		top=top->next;
		delete temp;
	}
}

template<class T>
void stack<T>::push(T x)
{
	node *temp;
	temp=new node();
	temp->data=x;
	temp->next=NULL;
	if(top==NULL)
	{
		top=temp;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
}

template<class T>
T stack<T>::pop()
{
	node *temp;
	T x;
	temp=top;
	top=temp->next;
	x=temp->data;
	delete temp;
	return x;
}

template<class T>
T stack<T>::stacktop()
{
	return top->data;
}

template<class T>
int stack<T>::isEmpty()
{
	if(top==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
