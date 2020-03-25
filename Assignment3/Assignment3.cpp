/*============================================================================
 ROLL NO.  		   : 23245
 BATCH         	   : G-10
 ASSIGNMENT NO.	   : 3
 PROBLEM STATEMENT : CREATE A BINARY TREE AND PERFORM THE FOLLOWING
 	 	 	 	 	 OPERATIONS ON IT
 	 	 	 	 	 (1)INSERT ELEMENT
 	 	 	 	 	 (2)DISPLAY TREE
 	 	 	 	 	 (3)DEPTH OF TREE
 	 	 	 	 	 (4)DISPLAY LEAF NODE
 	 	 	 	 	 (5)CREATE A COPY OF THE TREE
 ============================================================================*/

#include <iostream>
#include "stack.h"
#include "stack.cpp"
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

		treenode()				//constructor
		{
			root=NULL;
		}

		void insertnon(node *p)
		{
			node* newnode;
			int choice;
			if(p==NULL)
			{
				p=new node();
				cout<<"Enter Data for root node : ";
				cin>>p->data;
				p->right=NULL;
				p->left=NULL;
				root=p;
			}
			else
			{
				do
				{
					cout<<"Insert Node at Left or Right of ' "<<p->data<<" '?\n";
					cout<<"(1)Left\n(2)Right\nYour Choice : ";
					cin>>choice;
					if(choice==1)
					{
						if(p->left!=NULL)
						{
							p=p->left;
						}
						else
						{
							newnode=new node();
							cout<<"Enter Data for new node : ";
							cin>>newnode->data;
							newnode->left=NULL;
							newnode->right=NULL;
							p->left=newnode;
							break;
						}
					}
					else if(choice==2)
					{
						if(p->right!=NULL)
						{
							p=p->right;
						}
						else
						{
							newnode=new node();
							cout<<"Enter Data for new node : ";
							cin>>newnode->data;
							newnode->left=NULL;
							newnode->right=NULL;
							p->right=newnode;
							break;
						}
					}
					else
					{
						cout<<"INVALID CHOICE !!";
					}
				}while(1);
			}
		}

		node* insertrec(node *r1)
		{
			node *p;
			int choice;
			if(r1==NULL)
			{
				r1=new node();
				cout<<"Enter Data for node : ";
				cin>>r1->data;
				r1->right=NULL;
				r1->left=NULL;
				return r1;
			}
			else
			{
				p=r1;
				cout<<"Insert Node at Left or Right of ' "<<p->data<<" '?\n";
				cout<<"(1)Left\n(2)Right\nYour Choice : ";
				cin>>choice;
				if(choice==1)
				{
					if(p->left==NULL)
					{
						p->left=new node();
						p->left=NULL;
					}
					p->left=insertrec(p->left);
				}
				else if(choice==2)
				{
					if(p->right==NULL)
					{
						p->right=new node();
						p->right=NULL;
					}
					p->right=insertrec(p->right);
				}
				else
				{
					cout<<"Invalid Choice !!!\n";
					p=insertrec(p);
				}
			}
			return p;
		}

		void insert()
		{
			int choice;
			cout<<"\n\t\t\tInsert using : ";
			cout<<"\n\t\t\t\t(1)Non Recursive Algorithm";
			cout<<"\n\t\t\t\t(2)Recursive Algorithm";
			cout<<"\n\t\t\t\tEnter Choice : ";
			cin>>choice;
			if(choice==1)
			{
				insertnon(root);
			}
			else if(choice==2)
			{
				root=insertrec(root);
			}
			else
			{
				cout<<"INVALID CHOICE !!!\n\n";
			}
		}

		void displaynon(node *p)
		{
			if(p!=NULL)
			{
				displaynon(p->left);
				cout<<"  "<<p->data<<"  ";
				displaynon(p->right);
			}
		}

		void displayrec(node *p)
		{
			stack<node*> s;
			while(1)
			{
				while(p!=NULL)
				{
					s.push(p);
					p=p->left;
				}
				if(s.isEmpty())
				{
					return;
				}
				p=s.pop();
				cout<<"  "<<p->data<<"  ";
				p=p->right;
			}
		}


		void display()
		{
			int choice;
			if(root!=NULL)
			{
				cout<<"\n\t\t\tDisplay using : ";
				cout<<"\n\t\t\t\t(1)Non Recursive Algorithm";
				cout<<"\n\t\t\t\t(2)Recursive Algorithm";
				cout<<"\n\t\t\t\tEnter Choice : ";
				cin>>choice;
				if(choice==1)
				{
					cout<<"Inorder Traversal of the tree is :\n\n";
					displaynon(root);
				}
				else if(choice==2)
				{
					cout<<"Inorder Traversal of the tree is :\n\n";
					displayrec(root);
				}
				else
				{
					cout<<"INVALID CHOICE !!!\n\n";
				}
			}
			else
			{
				cout<<"\n\n\nTREE IS EMPTY !!";
			}
		}


		int countleaf(node *p)
		{
			if(p==NULL)
			{
				return 0;
			}
			if(p->left == NULL && p->right == NULL)
			{
				return 1;
			}
			else
			{
				return ( ( countleaf(p->left) ) + ( countleaf(p->right) ) );
			}
		}

		void leaves()
		{
			int leaf;
			leaf=countleaf(root);
			cout<<"NUMBER OF LEAVES IN THE TREE : "<<leaf<<endl;
		}

		node* copyrec(node *p)
		{
			node* temp=NULL;
			if(p!=NULL)
			{
				temp=new node();
				temp=p;
				temp->left=copyrec(p->left);
				temp->right=copyrec(p->right);
			}
			return temp;
		}

		void copy(treenode &t1)
		{
			root=copyrec(t1.root);
			cout<<"\nTree copied successfully!  ";
		}
};








int main() {
	int choice;
	treenode tree,tree2;
	do
	{
		cout<<"\n\n\n\t\t\tMENU ::";
		cout<<"\n\t(1)Insert Node in the tree";
		cout<<"\n\t(2)Display Tree";
		cout<<"\n\t(3)Number of leaves in the tree";
		cout<<"\n\t(4)Copy Tree";
		cout<<"\n\t(5)EXIT";
		cout<<"\n\t\tEnter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			tree.insert();
			break;

		case 2:
			tree.display();
			break;

		case 3:
			tree.leaves();
			break;

		case 4:
			tree2.copy(tree);
			tree2.display();
			break;

		case 5:
			return 0;

		default:
			cout<<"\n\nINVALID CHOICE !!!";
			break;
		}
	}while(1);
	return 0;
}


/*
 	 	 	 	 OUTPUT

			MENU ::
	(1)Insert Node in the tree
	(2)Display Tree
	(3)Number of leaves in the tree
	(4)Copy Tree
	(5)EXIT
		Enter Your Choice : 1

			Insert using :
				(1)Non Recursive Algorithm
				(2)Recursive Algorithm
				Enter Choice : 1
Enter Data for root node : 50



			MENU ::
	(1)Insert Node in the tree
	(2)Display Tree
	(3)Number of leaves in the tree
	(4)Copy Tree
	(5)EXIT
		Enter Your Choice : 1

			Insert using :
				(1)Non Recursive Algorithm
				(2)Recursive Algorithm
				Enter Choice : 2
Insert Node at Left or Right of ' 50 '?
(1)Left
(2)Right
Your Choice : 2
Enter Data for node : 60



			MENU ::
	(1)Insert Node in the tree
	(2)Display Tree
	(3)Number of leaves in the tree
	(4)Copy Tree
	(5)EXIT
		Enter Your Choice : 1

			Insert using :
				(1)Non Recursive Algorithm
				(2)Recursive Algorithm
				Enter Choice : 1
Insert Node at Left or Right of ' 50 '?
(1)Left
(2)Right
Your Choice : 40
INVALID CHOICE !!Insert Node at Left or Right of ' 50 '?
(1)Left
(2)Right
Your Choice : 1
Enter Data for new node : 40



			MENU ::
	(1)Insert Node in the tree
	(2)Display Tree
	(3)Number of leaves in the tree
	(4)Copy Tree
	(5)EXIT
		Enter Your Choice : 1

			Insert using :
				(1)Non Recursive Algorithm
				(2)Recursive Algorithm
				Enter Choice : 1
Insert Node at Left or Right of ' 50 '?
(1)Left
(2)Right
Your Choice : 2
Insert Node at Left or Right of ' 60 '?
(1)Left
(2)Right
Your Choice : 1
Enter Data for new node : 55



			MENU ::
	(1)Insert Node in the tree
	(2)Display Tree
	(3)Number of leaves in the tree
	(4)Copy Tree
	(5)EXIT
		Enter Your Choice : 1

			Insert using :
				(1)Non Recursive Algorithm
				(2)Recursive Algorithm
				Enter Choice : 1
Insert Node at Left or Right of ' 50 '?
(1)Left
(2)Right
Your Choice : 2
Insert Node at Left or Right of ' 60 '?
(1)Left
(2)Right
Your Choice : 2
Enter Data for new node : 70



			MENU ::
	(1)Insert Node in the tree
	(2)Display Tree
	(3)Number of leaves in the tree
	(4)Copy Tree
	(5)EXIT
		Enter Your Choice : 1

			Insert using :
				(1)Non Recursive Algorithm
				(2)Recursive Algorithm
				Enter Choice : 1
Insert Node at Left or Right of ' 50 '?
(1)Left
(2)Right
Your Choice : 1
Insert Node at Left or Right of ' 40 '?
(1)Left
(2)Right
Your Choice : 1
Enter Data for new node : 25



			MENU ::
	(1)Insert Node in the tree
	(2)Display Tree
	(3)Number of leaves in the tree
	(4)Copy Tree
	(5)EXIT
		Enter Your Choice : 1

			Insert using :
				(1)Non Recursive Algorithm
				(2)Recursive Algorithm
				Enter Choice : 1
Insert Node at Left or Right of ' 50 '?
(1)Left
(2)Right
Your Choice : 2
Insert Node at Left or Right of ' 60 '?
(1)Left
(2)Right
Your Choice : 1
Insert Node at Left or Right of ' 55 '?
(1)Left
(2)Right
Your Choice : 1
Enter Data for new node : 51



			MENU ::
	(1)Insert Node in the tree
	(2)Display Tree
	(3)Number of leaves in the tree
	(4)Copy Tree
	(5)EXIT
		Enter Your Choice : 2

			Display using :
				(1)Non Recursive Algorithm
				(2)Recursive Algorithm
				Enter Choice : 1
Inorder Traversal of the tree is :

  25    40    50    51    55    60    70


			MENU ::
	(1)Insert Node in the tree
	(2)Display Tree
	(3)Number of leaves in the tree
	(4)Copy Tree
	(5)EXIT
		Enter Your Choice : 3
NUMBER OF LEAVES IN THE TREE : 3



			MENU ::
	(1)Insert Node in the tree
	(2)Display Tree
	(3)Number of leaves in the tree
	(4)Copy Tree
	(5)EXIT
		Enter Your Choice : 4

Tree copied successfully!
			Display using :
				(1)Non Recursive Algorithm
				(2)Recursive Algorithm
				Enter Choice : 1
Inorder Traversal of the tree is :

  25    40    50    51    55    60    70


			MENU ::
	(1)Insert Node in the tree
	(2)Display Tree
	(3)Number of leaves in the tree
	(4)Copy Tree
	(5)EXIT
		Enter Your Choice : 5

 */

