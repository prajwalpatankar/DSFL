/*============================================================================
 ROLL NO.  		   : 23245
 BATCH         	   : G-10
 ASSIGNMENT NO.	   : 5
 PROBLEM STATEMENT : IMPLEMENT BINARY SEARCH TREE TO PERFORM
 	 	 	 	 	 (1)INSERT
 	 	 	 	 	 (2)DELETE
 	 	 	 	 	 (3)SEARCH
 	 	 	 	 	 (4)MIRROR IMAGE
 	 	 	 	 	 (5)DISPLAY
 	 	 	 	 	 (6)DISPLAY LEVEL WISE
 	 	 	 	 	 (7)HEIGHT OF BINARY TREE
 ============================================================================*/

#include <iostream>
#include <string.h>
using namespace std;

class treenode
{
	struct node
	{
		int data;
		node *left;
		node *right;
	};
	node *root;

public:
		treenode();

		node* insert(int,node*);
		void insertcall();

		node *deletenode(node*,int);
		void deletecall();

		node* search(int);
		void searchcall();


		node* copy(node*);
		node* mirror(node*);
		void mirrorcall();

		void display(node*);
		void displaycall();

		void displaylevel(node*);
		void displaylevelcall();

		int height(node*);
		void heightcall();
};

treenode::treenode()
{
	root=NULL;
}

treenode::node* treenode::insert(int x,node *p)
{
	if(root==NULL)
	{
		root=new node();
		root->data=x;
		root->right=NULL;
		root->left=NULL;
		return root;
	}
	if(p==NULL)
	{
		p=new node();
		p->data=x;
		p->right=NULL;
		p->left=NULL;
		return p;

		cout<<"\nITEM INSERTED SUCCESSFULLY !\n";
	}
	else
	{
		if(x < p->data)
		{
			p->left=insert(x,p->left);
		}
		else if(x > p->data)
		{
			p->right=insert(x,p->right);
		}
		else
		{
			cout<<"DUPLICATION NOT ALLOWED";
		}
		return p;
	}
}
void treenode::insertcall()
{
	int x;
	cout<<"Enter Data for new node : ";
	cin>>x;
	insert(x,root);
}


treenode::node* treenode::deletenode(node *p,int key)
{
	node *temp;
	if(p==NULL)
	{
		cout<<"ITEM NO FOUND";
		return p;
	}
	if(key < p->data)
	{
		p->left=deletenode(p->left,key);
		return p;
	}
	else if(key > p->data)
	{
		p->right=deletenode(p->right,key);
		return p;
	}
	else
	{
		if(p->left == NULL && p->right == NULL)
		{
			delete p;
			cout<<"\nITEM DELETED SUCCESSFULLY !\n";
			return NULL;
		}
		else if(p->left == NULL)
		{
			temp=p;
			p=p->right;
			delete temp;
			cout<<"\nITEM DELETED SUCCESSFULLY !\n";
			return p;
		}
		else if(p->right == NULL)
		{
			temp=p;
			p=p->left;
			delete temp;
			cout<<"\nITEM DELETED SUCCESSFULLY !\n";
			return p;
		}
		else
		{
			temp=p->right;
			while(temp->left != NULL)
			{
				temp=temp->left;
			}
			p->data=temp->data;
			p->right=deletenode(p->right,temp->data);
			return p;
		}



	}
}
void treenode::deletecall()
{
	int key;
	cout<<"\nENTER ELEMENT TO DELETE : ";
	cin>>key;
	root=deletenode(root,key);
}



treenode::node* treenode::search(int x)
{
	node *p=root;
	while(p!=NULL)
	{
		if(x == p->data)
		{
			cout<<"ELEMENT FOUND !";
			return p;
		}
		else if(x < p->data)
		{
			p=p->left;
		}
		else if(x > p->data)
		{
			p=p->right;
		}
	}
	cout<<"\n\tDATA NOT FOUND\n";
}
void treenode::searchcall()
{
	node *p;
	int key;
	cout<<"\nENTER ELEMENT TO BE SEARCHED : ";
	cin>>key;
	p=search(key);
}




treenode::node* treenode::copy(node *p)
{
	node* temp=NULL;
	if(p!=NULL)
	{
		temp=new node();
		temp->data=p->data;
		temp->left=copy(p->left);
		temp->right=copy(p->right);
	}
	return temp;
}
treenode::node* treenode::mirror(node *original)
{
	node *p=copy(original);
	node *temp;
	if(p!=NULL)
	{
		temp=p->left;
		p->left=p->right;
		p->right=temp;
		p->left=mirror(p->left);
		p->right=mirror(p->right);
	}
	return p;
}
void treenode::mirrorcall()
{
	node *p;
	p=root;
	p=mirror(p);
	cout<<"\nMIRROR TREE IS AS FOLLOWS : \n";
	display(p);
}

void treenode::display(node *p)
{
	if(p!=NULL)
	{
		display(p->left);
		cout<<"  "<<p->data<<"  ";
		display(p->right);
	}
}
void treenode::displaycall()
{
	cout<<"Inorder Traversal of the tree is :\n\n";
	display(root);
}

void treenode::displaylevel(node *t)
{
	node* array[1000];
	int rear=0,head=0;
	cout<<"\n\nLEVEL WISE TRAVERSAL OF THE TREE IS : ";
	while(t!=NULL)
	{
		cout<<t->data<<"  ";
		if(t->left!=NULL)
		{
			array[rear++]=t->left;
		}
		if(t->right!=NULL)
		{
			array[rear++]=t->right;
		}
		if(rear==head)
		{
			t=NULL;
		}
		else
		{
			t=array[head++];
		}
	}
}
void treenode::displaylevelcall()
{
	displaylevel(root);
}


int treenode::height(node* root)
{
	int hleft,hright;
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		hleft=height(root->left)+1;
		hright=height(root->right)+1;
	}
	if(hleft>hright)
	{
		return hleft;
	}
	else
	{
		return hright;
	}
}
void treenode::heightcall()
{
	int h;
	h=height(root);
	cout<<"\n\nTHE HEIGHT O THE TRE IS :  "<<h<<endl<<endl;
}



int main() {
	treenode t;
	int choice;
	do
	{
		cout<<"\n\n\n\t\tMENU ::\n";
		cout<<"\n\t(1)INSERT NODE ON THE TREE";
		cout<<"\n\t(2)DISPLAY TREE";
		cout<<"\n\t(3)DELETE NODE ";
		cout<<"\n\t(4)SEARCH AN ELEMENT";
		cout<<"\n\t(5)DISPLAY MIRROR IMAGE OF THE TREE";
		cout<<"\n\t(6)DISPLAY LEVEL WISE";
		cout<<"\n\t(7)HEIGHT";
		cout<<"\n\t(8)EXIT";
		cout<<"\n\n\tENTER CHOICE : ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			t.insertcall();
			break;

		case 2:
			t.displaycall();
			break;

		case 3:
			t.deletecall();
			break;

		case 4:
			t.searchcall();
			break;

		case 5:
			t.mirrorcall();
			break;

		case 6:
			t.displaylevelcall();
			break;

		case 7:
			t.heightcall();
			break;

		case 8:
			return 0;

		default:
			cout<<"\n\n\tINVALID CHOICE !!!!\n";
			break;
		}
	}while(1);
	return 0;
}

/*
 	 	 OUTPUT



		MENU ::

	(1)INSERT NODE ON THE TREE
	(2)DISPLAY TREE
	(3)DELETE NODE
	(4)SEARCH AN ELEMENT
	(5)DISPLAY MIRROR IMAGE OF THE TREE
	(6)DISPLAY LEVEL WISE
	(7)HEIGHT
	(8)EXIT

	ENTER CHOICE : 1
Enter Data for new node : 10



		MENU ::

	(1)INSERT NODE ON THE TREE
	(2)DISPLAY TREE
	(3)DELETE NODE
	(4)SEARCH AN ELEMENT
	(5)DISPLAY MIRROR IMAGE OF THE TREE
	(6)DISPLAY LEVEL WISE
	(7)HEIGHT
	(8)EXIT

	ENTER CHOICE : 1
Enter Data for new node : 5



		MENU ::

	(1)INSERT NODE ON THE TREE
	(2)DISPLAY TREE
	(3)DELETE NODE
	(4)SEARCH AN ELEMENT
	(5)DISPLAY MIRROR IMAGE OF THE TREE
	(6)DISPLAY LEVEL WISE
	(7)HEIGHT
	(8)EXIT

	ENTER CHOICE : 1
Enter Data for new node : 15



		MENU ::

	(1)INSERT NODE ON THE TREE
	(2)DISPLAY TREE
	(3)DELETE NODE
	(4)SEARCH AN ELEMENT
	(5)DISPLAY MIRROR IMAGE OF THE TREE
	(6)DISPLAY LEVEL WISE
	(7)HEIGHT
	(8)EXIT

	ENTER CHOICE : 1
Enter Data for new node : 2



		MENU ::

	(1)INSERT NODE ON THE TREE
	(2)DISPLAY TREE
	(3)DELETE NODE
	(4)SEARCH AN ELEMENT
	(5)DISPLAY MIRROR IMAGE OF THE TREE
	(6)DISPLAY LEVEL WISE
	(7)HEIGHT
	(8)EXIT

	ENTER CHOICE : 1
Enter Data for new node : 4



		MENU ::

	(1)INSERT NODE ON THE TREE
	(2)DISPLAY TREE
	(3)DELETE NODE
	(4)SEARCH AN ELEMENT
	(5)DISPLAY MIRROR IMAGE OF THE TREE
	(6)DISPLAY LEVEL WISE
	(7)HEIGHT
	(8)EXIT

	ENTER CHOICE : 1
Enter Data for new node : 6



		MENU ::

	(1)INSERT NODE ON THE TREE
	(2)DISPLAY TREE
	(3)DELETE NODE
	(4)SEARCH AN ELEMENT
	(5)DISPLAY MIRROR IMAGE OF THE TREE
	(6)DISPLAY LEVEL WISE
	(7)HEIGHT
	(8)EXIT

	ENTER CHOICE : 1
Enter Data for new node : 10
DUPLICATION NOT ALLOWED


		MENU ::

	(1)INSERT NODE ON THE TREE
	(2)DISPLAY TREE
	(3)DELETE NODE
	(4)SEARCH AN ELEMENT
	(5)DISPLAY MIRROR IMAGE OF THE TREE
	(6)DISPLAY LEVEL WISE
	(7)HEIGHT
	(8)EXIT

	ENTER CHOICE : 1
Enter Data for new node : 11



		MENU ::

	(1)INSERT NODE ON THE TREE
	(2)DISPLAY TREE
	(3)DELETE NODE
	(4)SEARCH AN ELEMENT
	(5)DISPLAY MIRROR IMAGE OF THE TREE
	(6)DISPLAY LEVEL WISE
	(7)HEIGHT
	(8)EXIT

	ENTER CHOICE : 2
Inorder Traversal of the tree is :

  2    4    5    6    10    11    15


		MENU ::

	(1)INSERT NODE ON THE TREE
	(2)DISPLAY TREE
	(3)DELETE NODE
	(4)SEARCH AN ELEMENT
	(5)DISPLAY MIRROR IMAGE OF THE TREE
	(6)DISPLAY LEVEL WISE
	(7)HEIGHT
	(8)EXIT

	ENTER CHOICE : 3

ENTER ELEMENT TO DELETE : 5

ITEM DELETED SUCCESSFULLY !



		MENU ::

	(1)INSERT NODE ON THE TREE
	(2)DISPLAY TREE
	(3)DELETE NODE
	(4)SEARCH AN ELEMENT
	(5)DISPLAY MIRROR IMAGE OF THE TREE
	(6)DISPLAY LEVEL WISE
	(7)HEIGHT
	(8)EXIT

	ENTER CHOICE : 2
Inorder Traversal of the tree is :

  2    4    6    10    11    15


		MENU ::

	(1)INSERT NODE ON THE TREE
	(2)DISPLAY TREE
	(3)DELETE NODE
	(4)SEARCH AN ELEMENT
	(5)DISPLAY MIRROR IMAGE OF THE TREE
	(6)DISPLAY LEVEL WISE
	(7)HEIGHT
	(8)EXIT

	ENTER CHOICE : 4

ENTER ELEMENT TO BE SEARCHED : 10
ELEMENT FOUND !


		MENU ::

	(1)INSERT NODE ON THE TREE
	(2)DISPLAY TREE
	(3)DELETE NODE
	(4)SEARCH AN ELEMENT
	(5)DISPLAY MIRROR IMAGE OF THE TREE
	(6)DISPLAY LEVEL WISE
	(7)HEIGHT
	(8)EXIT

	ENTER CHOICE : 5

MIRROR TREE IS AS FOLLOWS :
  15    11    10    6    4    2


		MENU ::

	(1)INSERT NODE ON THE TREE
	(2)DISPLAY TREE
	(3)DELETE NODE
	(4)SEARCH AN ELEMENT
	(5)DISPLAY MIRROR IMAGE OF THE TREE
	(6)DISPLAY LEVEL WISE
	(7)HEIGHT
	(8)EXIT

	ENTER CHOICE : 6


LEVEL WISE TRAVERSAL OF THE TREE IS : 10  6  15  2  11  4


		MENU ::

	(1)INSERT NODE ON THE TREE
	(2)DISPLAY TREE
	(3)DELETE NODE
	(4)SEARCH AN ELEMENT
	(5)DISPLAY MIRROR IMAGE OF THE TREE
	(6)DISPLAY LEVEL WISE
	(7)HEIGHT
	(8)EXIT

	ENTER CHOICE : 7


THE HEIGHT O THE TRE IS :  4




		MENU ::

	(1)INSERT NODE ON THE TREE
	(2)DISPLAY TREE
	(3)DELETE NODE
	(4)SEARCH AN ELEMENT
	(5)DISPLAY MIRROR IMAGE OF THE TREE
	(6)DISPLAY LEVEL WISE
	(7)HEIGHT
	(8)EXIT

	ENTER CHOICE : 8

 */
