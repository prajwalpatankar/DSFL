/*============================================================================
 ROLL NO.  		   : 23245
 BATCH         	   : G-10
 ASSIGNMENT NO.	   : 8
 PROBLEM STATEMENT : REPRESENT A GRAPH USING ADJACENCY MATRIX/ADJACENCY LIST
 	 	 	 	 	 AND FIND THE SHORTEST PATH USING DIJKSTRA'S ALGORITHM.
 ============================================================================*/

#include <iostream>
using namespace std;

class Graph
{
	int vertices, edges;
	int graph[100][100];
	int dist[100];
	int visited[100];
	int path[100][100];

public:
	Graph();
	void createGraph();
	void insertEdge();
	void display();
	void Dijkstra();
};

Graph::Graph()
{
	int i,j;
	edges=0;
	for(i=0;i<100;i++)
	{
		visited[i]=0;
		dist[i]=9999;
		for(j=0;j<100;j++)
		{
			graph[i][j]=0;
		}
	}
	dist[1]=0;
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
		graph[0][i]=i;
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

void Graph::Dijkstra()
{
	int minVertex,count=1,distance,i,j;
	cout<<"\nSHORTEST PATH USING DIJKSTRA'S ALGORITHM IS AS FOLLOWS ::\n";
	while(count<vertices)
	{
		j=0;
        minVertex = -1;
        for(i =1; i<=vertices; i++)
        {
            if( (minVertex == -1 || dist[i] < dist[minVertex]) && !visited[i])
            {
                minVertex = i;
            }
        }
        visited[minVertex] = 1;

        for(i=1; i<= vertices; i++)
        {
            if(graph[minVertex][i] != 0 && !visited[i])
            {
                distance = dist[minVertex] + graph[minVertex][i];
                if (distance < dist[i])
                {
                    dist[i] = distance;
                }
            }
        }
        count++;
	}
    cout<<endl<<endl;
    for(i = 1; i <= vertices; i++)
    {
        cout<<"1 --> "<<i<<"\t "<<dist[i]<<endl;
    }
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
		cout<<"\n\t(4)DISPLAY SHORTEST PATH";
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
			g.Dijkstra();
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

/* OUTPUT

		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY SHORTEST PATH
	(5)EXIT

	ENTER YOUR CHOICE : 1

Enter number of vertices : 5

VERTICES CREATED : 1 2 3 4 5

		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY SHORTEST PATH
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 1
ENTER DESTINATION VERTEX : 2

ENTER WEIGHT OF THE EDGE : 10


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY SHORTEST PATH
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 1
ENTER DESTINATION VERTEX : 3

ENTER WEIGHT OF THE EDGE : 22


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY SHORTEST PATH
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 1
ENTER DESTINATION VERTEX : 4

ENTER WEIGHT OF THE EDGE : 26


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY SHORTEST PATH
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 1
ENTER DESTINATION VERTEX : 5

ENTER WEIGHT OF THE EDGE : 6


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY SHORTEST PATH
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 2
ENTER DESTINATION VERTEX : 3

ENTER WEIGHT OF THE EDGE : 8


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY SHORTEST PATH
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 2
ENTER DESTINATION VERTEX : 4

ENTER WEIGHT OF THE EDGE : 9


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY SHORTEST PATH
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 2
ENTER DESTINATION VERTEX : 5

ENTER WEIGHT OF THE EDGE : 12


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY SHORTEST PATH
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 3
ENTER DESTINATION VERTEX : 4

ENTER WEIGHT OF THE EDGE : 5


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY SHORTEST PATH
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 3
ENTER DESTINATION VERTEX : 5

ENTER WEIGHT OF THE EDGE : 1


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY SHORTEST PATH
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER SOURCE VERTEX : 4
ENTER DESTINATION VERTEX : 5

ENTER WEIGHT OF THE EDGE : 10


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY SHORTEST PATH
	(5)EXIT

	ENTER YOUR CHOICE : 3


	0	1	2	3	4	5
	1	0	10	22	26	6
	2	10	0	8	9	12
	3	22	8	0	5	1
	4	26	9	5	0	10
	5	6	12	1	10	0


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY SHORTEST PATH
	(5)EXIT

	ENTER YOUR CHOICE : 4

SHORTEST PATH USING DIJKSTRA'S ALGORITHM IS AS FOLLOWS ::


1 --> 1	 0
1 --> 2	 10
1 --> 3	 7
1 --> 4	 12
1 --> 5	 6


		MENU::

	(1)CREATE GRAPH
	(2)ADD EDGE
	(3)DISPLAY GRAPH
	(4)DISPLAY SHORTEST PATH
	(5)EXIT

	ENTER YOUR CHOICE : 5

 */


