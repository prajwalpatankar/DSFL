/*============================================================================
 ROLL NO.  		   : 23245
 BATCH         	   : G-10
 ASSIGNMENT NO.	   : 10
 PROBLEM STATEMENT : A BUSINESS HAS SEVERAL OFFICES IN DIFFERENT COUNTRIES.
 	 	 	 	 	 THEY WANT TO LWASE PHONE LINES TO CONNECT THEM WITH
 	 	 	 	 	 EACH OTHER AND THE PHONE COMPANY CHARGES DIFFERENT RENT
 	 	 	 	 	 TO CONNECT DIFFERENT PAIRS OF CITIES. BUSINESS HOUSE
 	 	 	 	 	 WANTS TO CONNECT ALL ITS OFFICE WITH A MINIMUM TOTAL
 	 	 	 	 	 COST. SOLVE THE PROBLEM USING APPROPRIATE DATA STRUCTURE.
 ============================================================================*/

#include <iostream>
using namespace std;

struct graphedge
{
	int weight;
	int inTree;
	graphedge *nextedge;
	struct graphvertex *destinationvertex;
};

struct graphvertex
{
	int name;
	int inTree;
	graphedge *edgepointer;
	graphvertex *nextvertex;
};

struct graphhead
{
	int vertices;
	graphvertex *firstvertex;
};

class Graph
{
	graphhead *g;

public:
	Graph();
	void createGraph();
	void insertEdge();
	void display();
	void Prims();
	void displayPrims();
};

Graph::Graph()
{
	g=NULL;
}

void Graph::createGraph()
{
	graphvertex *newvertex,*vertexptr;
	g=new graphhead;
	g->vertices=0;
	g->firstvertex=NULL;
	cout<<"\nNEW GRAPH CREATED\n";
	cout<<"\nENTER NUMBER OF VERTICES : ";
	cin>>g->vertices;

	newvertex = new graphvertex;
	newvertex->name=1;
	newvertex->inTree=0;
	newvertex->nextvertex=NULL;
	newvertex->edgepointer=NULL;
	g->firstvertex=newvertex;
	vertexptr=g->firstvertex;

	for(int i=2; i <= g->vertices; i++)
	{
		newvertex = new graphvertex;
		newvertex->name=i;
		newvertex->inTree=0;
		vertexptr->nextvertex=newvertex;
		vertexptr=vertexptr->nextvertex;
		vertexptr->edgepointer=NULL;
		vertexptr->nextvertex=NULL;

	}
	vertexptr=g->firstvertex;
	cout<<"\nVERTICES CREATED : ";		//check creation
	for(int i=0;i<g->vertices;i++)
	{
		cout<<"  "<<vertexptr->name;
		vertexptr=vertexptr->nextvertex;
	}
}

void Graph::insertEdge()
{
	graphvertex *from, *to;
	graphedge *temp,*temp2;
	int startVertex, endVertex,weight;

	cout<<"STARTING VERTEX : ";
	cin>>startVertex;
	cout<<"DESTINATION VERTEX : ";
	cin>>endVertex;
	cout<<"ENTER WEIGHT : ";
	cin>>weight;

	from=g->firstvertex;
	to=g->firstvertex;

	while(from != NULL && from->name != startVertex)
	{
		from=from->nextvertex;
	}
	if(from != NULL)
	{

		while(to != NULL && to->name != endVertex)
		{
			to=to->nextvertex;
		}
		if(to != NULL)
		{
			if(from != to)
			{
				temp=from->edgepointer;

				while(temp!=NULL && temp->destinationvertex->name != to->name)
				{
					temp=temp->nextedge;
				}
				if(temp==NULL)		//Duplicate not found
				{
					temp=from->edgepointer;			//u1 to u2
					if(temp == NULL)
					{
						temp=new graphedge();
						temp->weight=weight;
						temp->inTree=0;
						from->edgepointer=temp;
						temp->destinationvertex=to;
						temp->nextedge=NULL;
					}
					else
					{
						while(temp->nextedge != NULL)
						{
							temp=temp->nextedge;
						}
						temp2=new graphedge();
						temp2->weight=weight;
						temp->inTree=0;
						temp2->destinationvertex=to;
						temp2->nextedge=NULL;
						temp->nextedge=temp2;
					}

					temp=to->edgepointer;				//u2 to u1
					if(temp == NULL)
					{
						temp=new graphedge();
						temp->weight=weight;
						temp->inTree=0;
						to->edgepointer=temp;
						temp->destinationvertex=from;
						temp->nextedge=NULL;
					}
					else
					{
						while(temp->nextedge != NULL)
						{
							temp=temp->nextedge;
						}
						temp2=new graphedge();
						temp2->weight=weight;
						temp->inTree=0;
						temp2->destinationvertex=from;
						temp2->nextedge=NULL;
						temp->nextedge=temp2;
					}
				}
				else
				{
					cout<<"EDGE ALREADY EXISTS !\n";
				}
			}
			else
			{
				cout<<"BOTH VERTICES CANNOT BE SAME\n";
			}
		}
		else
		{
			cout<<endl<<endVertex<<"DESTINATION VERTEX DOES NOT EXIST !\n";
		}
	}
	else
	{
		cout<<endl<<startVertex<<"STARTING VERTEX DOES NOT EXIST !\n";
	}
}

void Graph::display()
{
	graphvertex *vertexPtr;
	graphedge *edgePtr;
	vertexPtr=g->firstvertex;
	while(vertexPtr!=NULL)
	{
		edgePtr=vertexPtr->edgepointer;
		cout<<endl<<vertexPtr->name;
		while(edgePtr!=NULL)
		{
			cout<<" --> "<<edgePtr->destinationvertex->name<<"["<<edgePtr->weight<<"]";
			edgePtr=edgePtr->nextedge;
		}
		vertexPtr=vertexPtr->nextvertex;
	}
}

void Graph::Prims()
{
	int min,count=0;
	graphvertex *vertex,*tempvertex;
	graphedge *edge,*tempedge=NULL;
	 vertex = g->firstvertex;
	 g->firstvertex->inTree=1;

	 while(count < (g->vertices - 1) )		//till n-1 edges
	 {
		 min=9999;
		 vertex=g->firstvertex;
		 while(vertex != NULL)				//find minimum
		 {
			 if(vertex->inTree==1)
			 {
				 if(vertex->edgepointer!=NULL)
				 {
					 edge=vertex->edgepointer;
					 while(edge !=NULL)
					 {
						 if(edge->destinationvertex->inTree==0 &&  edge->weight < min)
						 {
							 min = edge->weight;
							 tempedge=edge;
							 tempvertex=vertex;		//source vertex
						 }
						 edge=edge->nextedge;
					 }
				 }
			 }
			 vertex=vertex->nextvertex;
		 }
		 tempedge->destinationvertex->inTree=1;
		 tempedge->inTree=1;

		 edge=tempedge->destinationvertex->edgepointer;
		 while(edge->destinationvertex->name != tempvertex->name)
		 {
			 edge=edge->nextedge;
		 }
		 edge->inTree=1;
		 count++;
	 }
}

void Graph::displayPrims()
{
	graphvertex *vertexPtr;
	graphedge *edgePtr;
	int cost=0;
	vertexPtr=g->firstvertex;

	while(vertexPtr!=NULL)
	{
		edgePtr=vertexPtr->edgepointer;
		cout<<endl<<vertexPtr->name;
		while(edgePtr!=NULL)
		{
			if(edgePtr->inTree==1)
			{
				cout<<" --> "<<edgePtr->destinationvertex->name<<"["<<edgePtr->weight<<"]";
				cost+=edgePtr->weight;
			}
			edgePtr=edgePtr->nextedge;
		}
		vertexPtr=vertexPtr->nextvertex;
	}
	cost=cost/2;
	cout<<"\nCOST OF MINIMUM SPANNIN TREE IS : "<<cost;
}



int main() {
	Graph g;
	int choice;
	while(1)
	{
		cout<<"\n\n\t\tMENU::";
		cout<<"\n\n\t(1)CREATE GRAPH";
		cout<<"\n\t(2)ADD EDGE";
		cout<<"\n\t(3)DISPLAY GRAPH";
		cout<<"\n\t(4)DISPLAY MINIMUM SPANNING TREE";
		cout<<"\n\t(5)EXIT";
		cout<<"\n\n\tENTER YOUR CHOICE : ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			g.createGraph();
			break;

		case 2:
			g.insertEdge();
			break;

		case 3:
			g.display();
			break;

		case 4:
			g.Prims();
			g.displayPrims();
			break;

		case 5:
			return 0;

		default:
			cout<<"\n\nINVALID CHOICE !!! ";
			break;
		}
	}
	return 0;
}

/*
 	 OUTPUT



		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 1

NEW GRAPH CREATED

ENTER NUMBER OF VERTICES : 6

VERTICES CREATED :   1  2  3  4  5  6

		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2
STARTING VERTEX : 1
DESTINATION VERTEX : 2
ENTER WEIGHT : 6


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2
STARTING VERTEX : 1
DESTINATION VERTEX : 3
ENTER WEIGHT : 1


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2
STARTING VERTEX : 1
DESTINATION VERTEX : 4
ENTER WEIGHT : 5


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2
STARTING VERTEX : 2
DESTINATION VERTEX : 3
ENTER WEIGHT : 5


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2
STARTING VERTEX : 2
DESTINATION VERTEX : 5
ENTER WEIGHT : 3


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2
STARTING VERTEX : 3
DESTINATION VERTEX : 4
ENTER WEIGHT : 5


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2
STARTING VERTEX : 3
DESTINATION VERTEX : 5
ENTER WEIGHT : 6


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2
STARTING VERTEX : 3
DESTINATION VERTEX : 6
ENTER WEIGHT : 4


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2
STARTING VERTEX : 4
DESTINATION VERTEX : 6
ENTER WEIGHT : 2


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2
STARTING VERTEX : 5
DESTINATION VERTEX : 6
ENTER WEIGHT : 6


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 3

1 --> 2[6] --> 3[1] --> 4[5]
2 --> 1[6] --> 3[5] --> 5[3]
3 --> 1[1] --> 2[5] --> 4[5] --> 5[6] --> 6[4]
4 --> 1[5] --> 3[5] --> 6[2]
5 --> 2[3] --> 3[6] --> 6[6]
6 --> 3[4] --> 4[2] --> 5[6]

		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 4

1 --> 3[1]
2 --> 3[5] --> 5[3]
3 --> 1[1] --> 2[5] --> 6[4]
4 --> 6[2]
5 --> 2[3]
6 --> 3[4] --> 4[2]
COST OF MINIMUM SPANNIN TREE IS : 15

		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 5

 */


