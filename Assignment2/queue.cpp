/*
 * queue.cpp
 *
 *  Created on: 03-Jan-2020
 *      Author: g10
 */

#include "queue.h"
#include <iostream>

namespace std {

template <class T>
queue<T>::queue() {
	front=NULL;
	rear=NULL;
}

template <class T>
queue<T>::~queue() {

}

template <class T>
void queue<T>::enqueue(T info)
{
	node<T> *newnode;
	newnode=new node<T>();
	newnode->data=info;
	newnode->next=NULL;
	if(isEmpty())
	{
		front=newnode;
		rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}

template <class T>
void queue<T>::dequeue()
{
	node<T> *temp,*prev;
	T patdata;


	int temppriorityn,temppriorityf;
	temp=front;
	prev=front;
	if(front!=NULL)
	{
		temppriorityf=temp->data.priority;
		while(temp!=NULL)							//searching highest priority
		{
			temppriorityn=temp->data.priority;
			if(temppriorityn>temppriorityf)
			{
				temppriorityf=temppriorityn;
			}
			temp=temp->next;
		}
		temp=front;
		while(temppriorityf!=temp->data.priority)
		{
			temp=temp->next;
		}
		//deletion
		if(temp==front)							//if found at first place
		{
			front=temp->next;
			//delete temp;
		}
		else									//elsewhere
		{
			while(prev->next!=temp)
			{
				prev=prev->next;
			}
			prev->next=temp->next;
			if(temp==rear)
			{
				rear=prev;
			}
			//delete temp;
		}
		cout<<"Patient Served\n";
		cout<<"patient Details:";
		cout<<"\nNAME 	 : "<<temp->data.name;
		cout<<"\nID	 	 : "<<temp->data.id;
		cout<<"\nIllness  : "<<temp->data.disease;
		cout<<"\n\n\t\tUPDATED RECORD ::\n";
		delete temp;
	}
	else
	{
		cout<<"Empty Queue !! ";
	}

}

template <class T>
int queue<T>::isEmpty()
{
	if(front==NULL)
		return 1;
	else
		return 0;
}

template <class T>
void queue<T>::display()
{
	node<T> *temp;
	temp=front;
	cout<<"\n\n--------------------------------------------------------------------------------------------------------";
	cout<<"\nName\t\t\tID\t\tIllness\t\t\tBloodgroup\tContact No.\t\t";
	cout<<"\n\n--------------------------------------------------------------------------------------------------------\n";
	if(front==NULL)
	{
		cout<<"\n\t\t\t\t\t<empty>";
	}
	while(temp!=NULL)

	{
		cout<<temp->data.name<<"\t\t\t"<<temp->data.id<<"\t\t"<<temp->data.disease<<"\t\t\t"<<temp->data.bloodgroup<<"\t\t"<<temp->data.mobile<<endl;
		temp=temp->next;
	}
}




} /* namespace std */
