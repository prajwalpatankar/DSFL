/*
 * queue.h
 *
 *  Created on: 03-Jan-2020
 *      Author: g10
 */

#ifndef QUEUE_H_
#define QUEUE_H_

namespace std {


template <class T>
struct node
{
	T data;
	node* next;
};

template <class T>
class queue {
	node<T> *front,*rear;
public:
	queue();
	virtual ~queue();
	void enqueue(T);
	void dequeue();
	int isEmpty();
	void display();
};

} /* namespace std */

#endif /* QUEUE_H_ */
