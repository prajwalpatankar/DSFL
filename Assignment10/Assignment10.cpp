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

class Graph
{
    int vertices, edges, minCost;
    int graph[100][100];
    int minSpanTree[100][100];
    int inTree[100];
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
	int i,j;
	edges=0;
	minCost=0;
	for(i=0;i<100;i++)
	{
		inTree[i]=0;
		for(j=0;j<100;j++)
		{
			graph[i][j]=0;
			minSpanTree[i][j]=0;
		}
	}
}

void Graph::createGraph()
{
	int i;
	cout<<"\nEnter number of vertices : ";
	cin>>vertices;
	cout<<"\nVERTICES CREATED : ";
	for(i=1;i<=vertices;i++)
	{
		graph[i][0]=i;
		graph[0][i]=i;			//initialize original graph

		minSpanTree[i][0]=i;
		minSpanTree[0][i]=i;	//initialize minimum spanning tree

		cout<<i<<" ";
	}
}

void Graph::insertEdge()
{
	int source,destination,weight;
	cout<<"\nENTER SOURCE VERTEX : ";
	cin>>source;
	cout<<"ENTER DESTINATION VERTEX : ";
	cin>>destination;

	if(source!=destination)
	{
		if(source <= vertices && source > 0)
		{
			if(destination <= vertices && destination > 0)
			{
				if(graph[source][destination] == 0 || graph[destination][source] == 0)
				{
					cout<<"\nENTER WEIGHT OF THE EDGE : ";
					cin>>weight;
					graph[source][destination] = weight;
					graph[destination][source] = weight;
					edges++;
				}
				else
				{
					cout<<"\nEDGE ALREADY EXISTS ";
				}
			}
			else
			{
				cout<<"\nDESTINATION VERTEX DOES NOT EXIST";
			}
		}
		else
		{
			cout<<"\nSOURCE VERTEX DOES NOT EXIST";
		}
	}
	else
	{
		cout<<"\nSOURCE AND DESTINATION VERTEX CANNOT BE SAME !";
	}
}

void Graph::display()
{
	cout<<endl<<endl;
    for(int i = 0; i <= vertices; i++)
    {
        for(int j = 0; j <= vertices; j++)
        {
            cout<<"\t"<<graph[i][j];
        }
        cout<<endl;
    }
}

void Graph::Prims()
{
	int min=9999,i,j,u,v,count=0;		//u,v are vertices
	inTree[1]=1;
	while(count<vertices-1)
	{
		min=9999;
		for(i=1;i<=vertices;i++)
		{
			if(inTree[i]==1)	//if the vertex exists in the span tree
			{
				for(j=1;j<=vertices;j++)
				{
					if(graph[i][j]!=0 && graph[i][j]<min && inTree[j]==0)
					{
						min=graph[i][j];
						u=i;
						v=j;
					}
				}
			}	//end intree if, else goto next vertex
		}
		count++;
		minCost += graph[u][v];
		minSpanTree[u][v]=graph[u][v];
		minSpanTree[v][u]=graph[v][u];
		inTree[v]=1;
	}
}

void Graph::displayPrims()
{
	cout<<endl<<"\tMINIMUM SPANNING TREE USING PRIM'S ALGORITHM::\n\n";
    for(int i = 0; i <= vertices; i++)
    {
        for(int j = 0; j <= vertices; j++)
        {
            cout<<"\t"<<minSpanTree[i][j];
        }
        cout<<endl;
    }
    cout<<"\n\tTOTAL COST OF MINIMUM SPANNING TREE = "<<minCost;
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
	OUTPUT ::



		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 1

Enter number of vertices : 6

VERTICES CREATED : 1 2 3 4 5 6

		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 1
ENTER DESTINATION VERTEX : 2

ENTER WEIGHT OF THE EDGE : 6


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 1
ENTER DESTINATION VERTEX : 3

ENTER WEIGHT OF THE EDGE : 1


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 1
ENTER DESTINATION VERTEX : 4

ENTER WEIGHT OF THE EDGE : 5


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 2
ENTER DESTINATION VERTEX : 3

ENTER WEIGHT OF THE EDGE : 5


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 2
ENTER DESTINATION VERTEX : 5

ENTER WEIGHT OF THE EDGE : 3


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 3
ENTER DESTINATION VERTEX : 4

ENTER WEIGHT OF THE EDGE : 5


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 3
ENTER DESTINATION VERTEX : 5

ENTER WEIGHT OF THE EDGE : 6


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 3
ENTER DESTINATION VERTEX : 6

ENTER WEIGHT OF THE EDGE : 4


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 4
ENTER DESTINATION VERTEX : 6

ENTER WEIGHT OF THE EDGE : 2


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 5
ENTER DESTINATION VERTEX : 6

ENTER WEIGHT OF THE EDGE : 6


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 3


	0	1	2	3	4	5	6
	1	0	6	1	5	0	0
	2	6	0	5	0	3	0
	3	1	5	0	5	6	4
	4	5	0	5	0	0	2
	5	0	3	6	0	0	6
	6	0	0	4	2	6	0


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 4

	MINIMUM SPANNING TREE USING PRIM'S ALGORITHM::

	0	1	2	3	4	5	6
	1	0	0	1	0	0	0
	2	0	0	5	0	3	0
	3	1	5	0	0	0	4
	4	0	0	0	0	0	2
	5	0	3	0	0	0	0
	6	0	0	4	2	0	0


	TOTAL COST OF MINIMUM SPANNING TREE = 15


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY MINIMUM SPANNING TREE
	(5)EXIT

	ENTER YOUR CHOICE : 5

*/
