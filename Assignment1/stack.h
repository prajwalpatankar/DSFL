/*
 * stack.h
 *
 *  Created on: 18-Dec-2019
 *      Author: g10
 */

#ifndef STACK_H_
#define STACK_H_
#include<iostream>

template<class T>
class stack {
	struct node
	{
		T data;
		struct node *next;
	};
	node *top;
public:
	stack();
	virtual ~stack();
	void push(T x);
	T pop();
	T stacktop();
	int isEmpty();
};

#endif
