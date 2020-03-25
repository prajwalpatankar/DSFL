/*============================================================================
 ROLL NO.  		   : 23245
 BATCH         	   : G-10
 ASSIGNMENT NO.	   : 7
 PROBLEM STATEMENT : REPRESENT ANY REAL WORLD GRAPH USING ADJACENCY LIST AND
 	 	 	 	 	 FIND THE MINIMUM SPANNING TREE USING KRUSKAL'S ALGORITHM
 ============================================================================*/

#include <iostream>
#include <queue>
using namespace std;

struct graphedge
{
	graphedge *nextedge;
	int inTree;
	int selected;
	int weight;
	struct graphvertex *destinationvertex;
};

struct graphvertex
{
	string name;
	int visited;
	int inTree;
	graphedge *nextedgepointer;
	graphvertex *nextvertexpointer;
};

struct graphhead
{
	int count;
	graphvertex *firstvertex;
};

class MinSpanTree
{
	graphhead *g;

public:
	MinSpanTree();
	void createGraph();
	void insertVertex();
	void insertEdge();
	void displayGraph();
	void Kruskal();
	void DisplayKruskal();
	int DFS(graphvertex*,string);
};

MinSpanTree::MinSpanTree()
{
	g=NULL;
}

void MinSpanTree::createGraph()
{
	g=new graphhead;
	g->count=0;
	g->firstvertex=NULL;
	cout<<"\nNEW GRAPH CREATED\n";
}

void MinSpanTree::insertVertex()
{
	graphvertex *newptr,*locptr;
	locptr=g->firstvertex;

	newptr=new graphvertex();
	cout<<"ENTER NAME : ";
	cin>>newptr->name;

	newptr->nextvertexpointer=NULL;
	newptr->nextedgepointer=NULL;

	if(g->count==0)
	{
		g->firstvertex=newptr;
	}
	else
	{
		while(locptr->nextvertexpointer!=NULL)
		{
			locptr=locptr->nextvertexpointer;
		}
		locptr->nextvertexpointer=newptr;
	}
	g->count++;
}

void MinSpanTree::insertEdge()
{
	graphvertex *from, *to;
	graphedge *temp,*temp2;
	string startVertex, endVertex;
	int weight;

	cout<<"STARTING VERTEX : ";
	cin>>startVertex;
	cout<<"\nDESTINATION VERTEX : ";
	cin>>endVertex;
	cout<<"\nENTER WEIGHT : ";
	cin>>weight;

	from=g->firstvertex;
	to=g->firstvertex;

	while(from != NULL && from->name != startVertex)
	{
		from=from->nextvertexpointer;
	}
	if(from != NULL)
	{

		while(to != NULL && to->name != endVertex)
		{
			to=to->nextvertexpointer;
		}
		if(to != NULL)
		{
			if(from != to)
			{
				temp=from->nextedgepointer;

				while(temp!=NULL && temp->destinationvertex->name != to->name)
				{
					temp=temp->nextedge;
				}
				if(temp==NULL)		//Duplicate not found
				{
					temp=from->nextedgepointer;			//u1 to u2
					if(temp == NULL)
					{
						temp=new graphedge();
						temp->weight=weight;
						from->nextedgepointer=temp;
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
						temp2->destinationvertex=to;
						temp2->nextedge=NULL;
						temp->nextedge=temp2;
					}

					temp=to->nextedgepointer;				//u2 to u1
					if(temp == NULL)
					{
						temp=new graphedge();
						temp->weight=weight;
						to->nextedgepointer=temp;
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

void MinSpanTree::displayGraph()
{
	graphvertex *vertexPtr;
	graphedge *edgePtr;
	vertexPtr=g->firstvertex;
	while(vertexPtr!=NULL)
	{
		edgePtr=vertexPtr->nextedgepointer;
		cout<<endl<<vertexPtr->name;
		while(edgePtr!=NULL)
		{
			cout<<" --> "<<edgePtr->destinationvertex->name<<"["<<edgePtr->weight<<"]";
			edgePtr=edgePtr->nextedge;
		}
		vertexPtr=vertexPtr->nextvertexpointer;
	}
}

void MinSpanTree::Kruskal()
{
	graphvertex *vertex,*minvertex,*tempvertex,*vertex1;
	graphedge *edge,*minedge,*tempedge;
	int minweight=99999,counter=1,cycle=0;
	vertex=g->firstvertex;

	while(vertex)						//clear variables
	{
		vertex->visited=0;
		vertex->inTree=0;
		edge=vertex->nextedgepointer;
		while(edge)
		{
			edge->selected=0;
			edge->inTree=0;
			edge=edge->nextedge;
		}
		vertex=vertex->nextvertexpointer;
	}


	while(counter < g->count)				//traverse downwards
	{
		vertex=g->firstvertex;
		minweight=99999;
		while(vertex)						//finding minimum
		{
			edge=vertex->nextedgepointer;
			while(edge)
			{
				if(edge->inTree != 1)
				{
					if(edge->weight < minweight)
					{
						minweight=edge->weight;
						minvertex=vertex;
						minedge=edge;
					}
				}
				edge=edge->nextedge;
			}
			vertex=vertex->nextvertexpointer;
		}									//min edge found

		if(minvertex->inTree==0 || minedge->destinationvertex->inTree==0)		//if anyone does not exist
		{
			minvertex->inTree=1;				//v1 to v2
			minedge->inTree=1;
			minedge->selected=1;

			tempvertex=minedge->destinationvertex;	//v2 to v1
			tempvertex->inTree=1;
			tempedge=tempvertex->nextedgepointer;
			while(tempedge->destinationvertex->name != minvertex->name)
			{
				tempedge=tempedge->nextedge;
			}
			tempedge->inTree=1;
			tempedge->selected=0;
		}
		else
		{
			vertex1=g->firstvertex;				//clear visited for all vertices again
			while(vertex1)
			{
				vertex1->visited=0;
				vertex1=vertex1->nextvertexpointer;
			}


			cycle=DFS(minvertex,minedge->destinationvertex->name);
			if(cycle==0)
			{
				minvertex->inTree=1;				//v1 to v2
				minedge->inTree=1;
				minedge->selected=1;

				tempvertex=minedge->destinationvertex;	//v2 to v1
				tempvertex->inTree=1;
				tempedge=tempvertex->nextedgepointer;
				while(tempedge->destinationvertex->name != minvertex->name)
				{
					tempedge=tempedge->nextedge;
				}
				tempedge->inTree=1;
				tempedge->selected=0;
			}
			else
			{
				counter--;			//edge not included
			}
		}
		counter++;
	}
}

int MinSpanTree::DFS(graphvertex *v,string name)
{
	int cycle=0;
	graphedge *e;
	v->visited=1;
	if(v->nextedgepointer != NULL)
	{
		e=v->nextedgepointer;
		while(e)
		{
			if(e->inTree==1)
			{
				if(e->destinationvertex->name == name)
				{
					return 1;
				}
				else
				{
					if(e->destinationvertex->visited ==0 )
					{
						cycle=DFS(e->destinationvertex,name);
					}
				}
			}
			e=e->nextedge;
		}
	}
	return cycle;
}

void MinSpanTree::DisplayKruskal()
{
	graphvertex *vertexPtr;
	graphedge *edgePtr;
	int cost=0;
	vertexPtr=g->firstvertex;
	while(vertexPtr!=NULL)
	{
		edgePtr=vertexPtr->nextedgepointer;
		cout<<endl<<vertexPtr->name;
		while(edgePtr!=NULL)
		{
			if(edgePtr->selected==1)
			{
				cout<<" --> "<<edgePtr->destinationvertex->name<<"["<<edgePtr->weight<<"]";
				cost+=edgePtr->weight;
			}
			edgePtr=edgePtr->nextedge;
		}
		vertexPtr=vertexPtr->nextvertexpointer;
	}
	cout<<"\nCOST OF MINIMUM SPANNIN TREE IS : "<<cost;
}



int main() {

	MinSpanTree g1;
	int choice;
	do
	{
		cout<<"\n\n\n\tMENU::\n";
		cout<<"\n\t(1)CREATE A NEW GRAPH";
		cout<<"\n\t(2)ADD A NEW VERTEX";
		cout<<"\n\t(3)ADD A NEW EDGE";
		cout<<"\n\t(4)DISPLAY GRAPH";
		cout<<"\n\t(5)DISPLAY MINIMUM SPANNING TREE";
		cout<<"\n\t(6)EXIT";
		cout<<"\n\n\t\tENTER OUR CHOICE : ";
		cin>>choice;
		switch(choice)
		{
		case 1 :
			g1.createGraph();
			break;

		case 2:
			g1.insertVertex();
			break;

		case 3:
			g1.insertEdge();
			break;

		case 4:
			g1.displayGraph();
			break;

		case 5:
			g1.Kruskal();
			g1.DisplayKruskal();
			break;

		case 6:
			return 0;

		default:
			cout<<"\n\nINVALID CHOICE !!";
			break;
		}

	}while(1);
	return 0;
}



/*		<----	OUTPUT    ---->
	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 1

NEW GRAPH CREATED

	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 2
ENTER NAME : 1

	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 2
ENTER NAME : 2

	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 2
ENTER NAME : 3

	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 2
ENTER NAME : 4

	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 2
ENTER NAME : 5

	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 2
ENTER NAME : 6

	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 3
STARTING VERTEX : 1

DESTINATION VERTEX : 2

ENTER WEIGHT : 6

	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 3
STARTING VERTEX : 1

DESTINATION VERTEX : 3

ENTER WEIGHT : 1

	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 3
STARTING VERTEX : 1

DESTINATION VERTEX : 4

ENTER WEIGHT : 5

	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 3
STARTING VERTEX : 2

DESTINATION VERTEX : 3

ENTER WEIGHT : 5

	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 3
STARTING VERTEX : 2

DESTINATION VERTEX : 5

ENTER WEIGHT : 3

	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 3
STARTING VERTEX : 3

DESTINATION VERTEX : 4

ENTER WEIGHT : 5

	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 3
STARTING VERTEX : 3

DESTINATION VERTEX : 5

ENTER WEIGHT : 6

	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 3
STARTING VERTEX : 3

DESTINATION VERTEX : 6

ENTER WEIGHT : 4

	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 3
STARTING VERTEX : 4

DESTINATION VERTEX : 5

ENTER WEIGHT : 2

	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 3
STARTING VERTEX : 5

DESTINATION VERTEX : 6

ENTER WEIGHT :6

	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 4

1 --> 2[6] --> 3[1] --> 4[5]
2 --> 1[6] --> 3[5] --> 5[3]
3 --> 1[1] --> 2[5] --> 4[5] --> 5[6] --> 6[4]
4 --> 1[5] --> 3[5] --> 5[2]
5 --> 2[3] --> 3[6] --> 4[2] --> 6[6]
6 --> 3[4] --> 5[6]


	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 5

1 --> 3[1] --> 4[5]
2 --> 5[3]
3 --> 6[4]
4 --> 5[2]
5
6
COST OF MINIMUM SPANNING TREE IS : 15


	MENU::

	(1)CREATE A NEW GRAPH
	(2)ADD A NEW VERTEX
	(3)ADD A NEW EDGE
	(4)DISPLAY GRAPH
	(5)DISPLAY MINIMUM SPANNING TREE
	(6)EXIT

		ENTER OUR CHOICE : 6

 */
