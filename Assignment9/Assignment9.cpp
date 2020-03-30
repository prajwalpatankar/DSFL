/*============================================================================
 ROLL NO.  		   : 23245
 BATCH         	   : G-10
 ASSIGNMENT NO.	   : 09
 PROBLEM STATEMENT : STORE DATA OF STUDENTS WITH TELEPHONE NO AND NAME IN THE
  	  	  	  	  	 STRUCTURE USING HASHING FUNCTION FOR TELEPHONE NUMBER
  	  	  	  	  	 AND IMPLEMENT CHAINING WITH AND WITHOUT REPLACEMENT.
 ============================================================================*/

#include <iostream>
using namespace std;

struct student
{
	string name;
	long phone;
	int flag;
	int chain;
};

class Hash
{
	student s[20];
	int size;

public:
	Hash();
	void createTable();
	void insertReplacement();
	void insertWOReplacement();
	void display();
};

Hash::Hash()
{
	size=0;
}

void Hash::createTable()
{
	cout<<"\nENTER SIZE OF THE TABLE : ";
	cin>>size;
	for(int i=0;i<size;i++)
	{
		s[i].flag=0;
		s[i].chain=-1;
	}
}

void Hash::insertWOReplacement()
{
	int i=0,j,loc;
	char name[30];
	long phone;

	cout<<"\nENTER NAME OF STUDENT : ";
	cin>>name;
	cout<<"\nENTER PHONE NUMBER : ";
	cin>>phone;

	loc = phone%size;		//hash function
	j=loc;

	while(i<size && s[j].flag==1)	//until table traversed or empty element
	{
		if( (s[j].phone % size) == (phone % size) )
		{
			break;			//similar element found
		}
		j=(j+1)%size;
		i++;
	}

	if(i==size)
	{
		cout<<"\nTABLE IS FULL !";
		return;
	}

	while( s[j].chain != -1 )	//traversing chain
	{
		j=s[j].chain;
	}

	loc=j;
	while(s[loc].flag)	//finding empty loc
	{
		loc=(loc+1)%size;
	}

	s[loc].name=name;
	s[loc].phone=phone;
	s[loc].flag=1;
	if(j!=loc)	//make chain
	{
		s[j].chain=loc;
	}
}


void Hash::insertReplacement()
{
	int i=0,j,loc;
	char name[30];
	long phone;

	cout<<"\nENTER NAME OF STUDENT : ";
	cin>>name;
	cout<<"\nENTER PHONE NUMBER : ";
	cin>>phone;

	loc = phone%size;		//hash function

	if(s[loc].flag==0)		//empty loc
	{
		s[loc].name=name;
		s[loc].phone=phone;
		s[loc].flag=1;
		return;
	}

	j=loc;
	while( i<size && s[j].flag==1)	//finding empty loc
	{
		j=(j+1)%size;
		i++;
	}
	if(i==size)
	{
		cout<<"\nTABLE IS FULL!";
		return;
	}

	if( (s[loc].phone % size) != loc ) //needs replacement(incorrect number
	{
		i= s[loc].phone % size;			//store temp loc
		while( s[i].chain != loc)		//finding previous link to incorrect number
		{
			i=s[i].chain;
		}

		//skip incorrect number, assign next value to chain
		s[i].chain=s[loc].chain;

		while(s[i].chain != -1)
		{
			i= s[i].chain;
		}
		s[i].chain=j;	//chain it the empty loc

		s[j].name = s[loc].name;
		s[j].phone = s[loc].phone;
		s[j].flag=1;

		s[loc].phone=phone;
		s[loc].name=name;
		s[loc].flag=1;
		s[loc].chain= -1;
	}
	else	//does not need replacement
	{
		s[j].phone=phone;
		s[j].name=name;
		s[j].flag=1;
		if(j!=loc)
		{
			while( s[loc].chain != -1)
			{
				loc=s[loc].chain;
			}
			s[loc].chain=j;
		}
	}
}

void Hash::display()
{
	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<"SR. NO.\tNAME\t\tPHONE\t\tNEXT LINK(CHIAN)"<<endl;
	cout<<"--------------------------------------------------------------------"<<endl;
	for(int i=0; i<size; i++)
	{
		if(s[i].flag!=0)
		{
			cout<<i+1<<"\t|"<<s[i].name<<"\t|"<<s[i].phone<<"\t|"<<s[i].chain<<endl;
		}
		else
		{
			cout<<i+1<<endl;
		}
	}
	cout<<"--------------------------------------------------------------------"<<endl;
}

int main() {
	Hash h;
	int choice;

	while(1)
	{
		cout<<"\n\n\t\tMENU::\n";
		cout<<"\n\t(1)CREATE HASH TABLE";
		cout<<"\n\t(2)INSERT ELEMENT BY CHAINING WITHOUT REPLACEMENT";
		cout<<"\n\t(3)INSERT ELEMENT BY CHAINING WITH REPLACEMENT";
		cout<<"\n\t(4)DISPLAY TABLE";
		cout<<"\n\t(5)EXIT\n";
		cout<<"\n\tENTER YOUR CHOICE : ";
		cin>>choice;

		switch(choice)
		{
		case 1:
			h.createTable();
			break;

		case 2:
			h.insertWOReplacement();
			break;

		case 3:
			h.insertReplacement();
			break;

		case 4:
			h.display();
			break;

		case 5:
			return 0;

		default:
			cout<<"\n\nINVALID CHOICE !";
			break;
		}
	}
	return 0;
}


/*


		MENU::

	(1)CREATE HASH TABLE
	(2)INSERT ELEMENT BY CHAINING WITHOUT REPLACEMENT
	(3)INSERT ELEMENT BY CHAINING WITH REPLACEMENT
	(4)DISPLAY TABLE
	(5)EXIT

	ENTER YOUR CHOICE : 1

ENTER SIZE OF THE TABLE : 10


		MENU::

	(1)CREATE HASH TABLE
	(2)INSERT ELEMENT BY CHAINING WITHOUT REPLACEMENT
	(3)INSERT ELEMENT BY CHAINING WITH REPLACEMENT
	(4)DISPLAY TABLE
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER NAME OF STUDENT : PRAJWAL

ENTER PHONE NUMBER : 9898989805


		MENU::

	(1)CREATE HASH TABLE
	(2)INSERT ELEMENT BY CHAINING WITHOUT REPLACEMENT
	(3)INSERT ELEMENT BY CHAINING WITH REPLACEMENT
	(4)DISPLAY TABLE
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER NAME OF STUDENT : RAAGHAV

ENTER PHONE NUMBER : 9898989872


		MENU::

	(1)CREATE HASH TABLE
	(2)INSERT ELEMENT BY CHAINING WITHOUT REPLACEMENT
	(3)INSERT ELEMENT BY CHAINING WITH REPLACEMENT
	(4)DISPLAY TABLE
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER NAME OF STUDENT : ANIKET

ENTER PHONE NUMBER : 9898989868


		MENU::

	(1)CREATE HASH TABLE
	(2)INSERT ELEMENT BY CHAINING WITHOUT REPLACEMENT
	(3)INSERT ELEMENT BY CHAINING WITH REPLACEMENT
	(4)DISPLAY TABLE
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER NAME OF STUDENT : SPARSH

ENTER PHONE NUMBER : 9898989869


		MENU::

	(1)CREATE HASH TABLE
	(2)INSERT ELEMENT BY CHAINING WITHOUT REPLACEMENT
	(3)INSERT ELEMENT BY CHAINING WITH REPLACEMENT
	(4)DISPLAY TABLE
	(5)EXIT

	ENTER YOUR CHOICE : 2

ENTER NAME OF STUDENT : SALONI

ENTER PHONE NUMBER : 9898989851


		MENU::

	(1)CREATE HASH TABLE
	(2)INSERT ELEMENT BY CHAINING WITHOUT REPLACEMENT
	(3)INSERT ELEMENT BY CHAINING WITH REPLACEMENT
	(4)DISPLAY TABLE
	(5)EXIT

	ENTER YOUR CHOICE : 4
--------------------------------------------------------------------
SR. NO.	NAME	PHONE		NEXT LINK(CHIAN)
--------------------------------------------------------------------
1
2	|SALONI		|9898989851	|-1
3	|RAAGHAV	|9898989872	|-1
4
5
6	|PRAJWAL	|9898989805	|-1
7
8
9	|ANIKET		|9898989868	|-1
10	|SPARSH		|9898989869	|-1
--------------------------------------------------------------------


		MENU::

	(1)CREATE HASH TABLE
	(2)INSERT ELEMENT BY CHAINING WITHOUT REPLACEMENT
	(3)INSERT ELEMENT BY CHAINING WITH REPLACEMENT
	(4)DISPLAY TABLE
	(5)EXIT

	ENTER YOUR CHOICE : 3

ENTER NAME OF STUDENT : VIDHI

ENTER PHONE NUMBER : 9898989899


		MENU::

	(1)CREATE HASH TABLE
	(2)INSERT ELEMENT BY CHAINING WITHOUT REPLACEMENT
	(3)INSERT ELEMENT BY CHAINING WITH REPLACEMENT
	(4)DISPLAY TABLE
	(5)EXIT

	ENTER YOUR CHOICE : 3

ENTER NAME OF STUDENT : TANMAY

ENTER PHONE NUMBER : 9898989844


		MENU::

	(1)CREATE HASH TABLE
	(2)INSERT ELEMENT BY CHAINING WITHOUT REPLACEMENT
	(3)INSERT ELEMENT BY CHAINING WITH REPLACEMENT
	(4)DISPLAY TABLE
	(5)EXIT

	ENTER YOUR CHOICE : 3

ENTER NAME OF STUDENT : ATHARV

ENTER PHONE NUMBER : 9898989807


		MENU::

	(1)CREATE HASH TABLE
	(2)INSERT ELEMENT BY CHAINING WITHOUT REPLACEMENT
	(3)INSERT ELEMENT BY CHAINING WITH REPLACEMENT
	(4)DISPLAY TABLE
	(5)EXIT

	ENTER YOUR CHOICE : 3

ENTER NAME OF STUDENT : MRUNAL

ENTER PHONE NUMBER : 9898989833


		MENU::

	(1)CREATE HASH TABLE
	(2)INSERT ELEMENT BY CHAINING WITHOUT REPLACEMENT
	(3)INSERT ELEMENT BY CHAINING WITH REPLACEMENT
	(4)DISPLAY TABLE
	(5)EXIT

	ENTER YOUR CHOICE : 3

ENTER NAME OF STUDENT : HARSH

ENTER PHONE NUMBER : 9898989877


		MENU::

	(1)CREATE HASH TABLE
	(2)INSERT ELEMENT BY CHAINING WITHOUT REPLACEMENT
	(3)INSERT ELEMENT BY CHAINING WITH REPLACEMENT
	(4)DISPLAY TABLE
	(5)EXIT

	ENTER YOUR CHOICE : 4
--------------------------------------------------------------------
SR. NO.	NAME	PHONE		NEXT LINK(CHIAN)
--------------------------------------------------------------------
1	|VIDHI		|9898989899	|-1
2	|SALONI		|9898989851	|-1
3	|RAAGHAV	|9898989872	|-1
4	|MRUNAL		|9898989833	|-1
5	|TANMAY		|9898989844	|-1
6	|PRAJWAL	|9898989805	|-1
7	|HARSH		|9898989877	|-1
8	|ATHARV		|9898989807	|6
9	|ANIKET		|9898989868	|-1
10	|SPARSH		|9898989869	|0
--------------------------------------------------------------------


		MENU::

	(1)CREATE HASH TABLE
	(2)INSERT ELEMENT BY CHAINING WITHOUT REPLACEMENT
	(3)INSERT ELEMENT BY CHAINING WITH REPLACEMENT
	(4)DISPLAY TABLE
	(5)EXIT

	ENTER YOUR CHOICE : 5
 */
