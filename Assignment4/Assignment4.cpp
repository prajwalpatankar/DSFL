/*============================================================================
 ROLL NO.  		   : 23245
 BATCH         	   : G-10
 ASSIGNMENT NO.	   : 4
 PROBLEM STATEMENT : CONSTRUCT AN EXPRESSION TREE FROM PREFIX/POSTFIX
 	 	 	 	 	 EXPRESSION AND PERFORM RECRSIVE AND NON-RECURSIVE
 	 	 	 	 	 INORDER, PREODER AND POSTORDER TRAVERSALS
 ============================================================================*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct node
{
    char data;
    node *left, *right;
};
class expression
{
    char prefix[20], postfix[20], infix[20];
    node* root;
    int top;

public:
    void input(int);
    node* getroot(){ return root; }
    int validate(int);
    node* create_Post();
    void create_Pre();
    void inorder_withRec(node*);
    void preorder_withRec(node*);
    void postorder_withRec(node*);
    void inorder_withoutRec(node*);
    void preorder_withoutRec(node*);
    void postorder_withoutRec(node*);
};


int expression::validate(int x)
{
    int i = 0, opn = 0, opt = 0;
    if(x == 0)
    {
        for(;i<prefix[i]!='\0';i++)
        {
            if(prefix[i] == '+' || prefix[i] == '-' ||prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '%' || prefix[i] == '^' || prefix[i] == '$')
                opt++;
            else
                opn++;
        }

        if(opt != (opn-1))
            return 0;
        return 1;
    }
    else
    {
        for(;i<postfix[i]!='\0';i++)
        {
            if(postfix[i] == '+' || postfix[i] == '-' ||postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '%' || postfix[i] == '^' || postfix[i] == '$')
                opt++;
            else
                opn++;
        }

        if(opt != (opn-1))
            return 0;
        return 1;
    }
}
void expression::input(int x)
{
    if(x == 0)
    {
        while(1)
        {
            cout<<"\nEnter prefix expression: ";
            cin>>prefix;
            if(validate(x))
                break;
            else
                cout<<"\nWrong expression. Please enter again.";
        }
    }
    else
    {
        while(1)
        {
            cout<<"\nEnter postfix expression: ";
            cin>>postfix;
            if(validate(x))
                break;
            else
                cout<<"\nWrong expression. Please enter again.";
        }
    }
}

node* expression::create_Post()
{
    int i=0;
    node* temp, *t1, *t2;
    stack<node*> s;

    for(;postfix[i]!='\0';i++)
    {
        if(isalnum(postfix[i]))
        {
            temp = new node;
            temp->data = postfix[i];
            temp->left = temp->right = NULL;
            s.push(temp);
        }
        else
        {
            t2 = s.top();
            s.pop();
            t1 = s.top();
            s.pop();
            temp = new node;
            temp->data = postfix[i];
            temp->left = t1;
            temp->right = t2;
            s.push(temp);
        }
    }
    temp = s.top();
    s.pop();
    return temp;
}

void expression::inorder_withRec(node* t)
{
    if(t!=NULL)
    {
        inorder_withRec(t->left);
        cout<<" "<<t->data;
        inorder_withRec(t->right);
    }
}

void expression::preorder_withRec(node* t)
{
    if(t!=NULL)
    {
        cout<<" "<<t->data;
        preorder_withRec(t->left);
        preorder_withRec(t->right);
    }
}

void expression::postorder_withRec(node* t)
{
    if(t!=NULL)
    {
        postorder_withRec(t->left);
        postorder_withRec(t->right);
        cout<<" "<<t->data;
    }
}

void expression::inorder_withoutRec(node* t)
{
    node* temp = t;
    stack<node*> s;

    while(temp!=NULL)
    {
        s.push(temp);
        temp = temp->left;
    }

    while(!s.empty())
    {
        temp = s.top();
        s.pop();
        cout<<" "<<temp->data;
        temp = temp->right;
        while(temp!=NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
    }
}

void expression::preorder_withoutRec(node* t)
{
    node* temp = t;
    stack<node*> s;
    while(temp != NULL)
    {
        cout<<" "<<temp->data;
        s.push(temp);
        temp = temp->left;
    }

    while(!s.empty())
    {
        temp = s.top();
        s.pop();
        temp = temp->right;
        while(temp != NULL)
        {
            cout<<" "<<temp->data;
            s.push(temp);
            temp = temp->left;
        }
    }
}

void expression::postorder_withoutRec(node* t)
{
    node *t1, *temp = t;
    stack<node*> s, s1;

    while(temp!=NULL)
    {
        s.push(temp);
        s1.push(NULL);
        temp = temp->left;
    }

    while(!s.empty())
    {
        temp = s.top();
        s.pop();
        t1 = s1.top();
        s1.pop();
        if(t1 == NULL)
        {
            s.push(temp);
            s1.push((node*)1);
            temp = temp->right;
            while(temp!=NULL)
            {
                s.push(temp);
                s1.push(NULL);
                temp = temp->left;
            }

        }
        else
            cout<<" "<<temp->data;

    }


}
int main()
{
    int choice;
    expression exrtree;
    node* t;

    exrtree.input(1);
    t = exrtree.create_Post();

    while(1)
    {
        cout<<"\n\nChoose from the following: ";
        cout<<"\nRecursive Traversals: ";
        cout<<"\n1. Inorder Traversal.";
        cout<<"\n2. Preorder Traversal.";
        cout<<"\n3. Postorder Traversal.";
        cout<<"\nNon-Recursive Traversals: ";
        cout<<"\n4. Inorder Traversal.";
        cout<<"\n5. Preorder Traversal.";
        cout<<"\n6. Postorder Traversal.";
        cout<<"\n7. Exit.";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            	cout<<"\nInorder traversal (recursive):";
                exrtree.inorder_withRec(t);
                break;

            case 2:
            	cout<<"\nPreorder traversal(recursive):";
                exrtree.preorder_withRec(t);
                break;

            case 3:
            	cout<<"\nPostorder traversal (recursive):";
                exrtree.postorder_withRec(t);
                break;

            case 4:
            	cout<<"\nInorder traversal (non-recursive):";
                exrtree.inorder_withoutRec(t);
                break;

            case 5:
            	cout<<"\nPreorder traversal (non-recursive):";
                exrtree.preorder_withoutRec(t);
                break;

            case 6:
            	cout<<"\nPostorder traversal (non-recursive):";
                exrtree.postorder_withoutRec(t);
                break;

            case 7:
            	return 0;

            default:
            	cout<<"\nWrong choice. Please enter again.";
            	break;
        }
    }


    return 0;
}

/*
 	 	 OUTPUT


Enter postfix expression: ABC^/DE*+AC*+


Choose from the following:
Recursive Traversals:
1. Inorder Traversal.
2. Preorder Traversal.
3. Postorder Traversal.
Non-Recursive Traversals:
4. Inorder Traversal.
5. Preorder Traversal.
6. Postorder Traversal.
7. Exit.
Enter your choice: 1

Inorder traversal (recursive): A / B ^ C + D * E + A * C

Choose from the following:
Recursive Traversals:
1. Inorder Traversal.
2. Preorder Traversal.
3. Postorder Traversal.
Non-Recursive Traversals:
4. Inorder Traversal.
5. Preorder Traversal.
6. Postorder Traversal.
7. Exit.
Enter your choice: 2

Preorder traversal(recursive): + + / A ^ B C * D E * A C

Choose from the following:
Recursive Traversals:
1. Inorder Traversal.
2. Preorder Traversal.
3. Postorder Traversal.
Non-Recursive Traversals:
4. Inorder Traversal.
5. Preorder Traversal.
6. Postorder Traversal.
7. Exit.
Enter your choice: 3

Postorder traversal (recursive): A B C ^ / D E * + A C * +

Choose from the following:
Recursive Traversals:
1. Inorder Traversal.
2. Preorder Traversal.
3. Postorder Traversal.
Non-Recursive Traversals:
4. Inorder Traversal.
5. Preorder Traversal.
6. Postorder Traversal.
7. Exit.
Enter your choice: 4

Inorder traversal (non-recursive): A / B ^ C + D * E + A * C

Choose from the following:
Recursive Traversals:
1. Inorder Traversal.
2. Preorder Traversal.
3. Postorder Traversal.
Non-Recursive Traversals:
4. Inorder Traversal.
5. Preorder Traversal.
6. Postorder Traversal.
7. Exit.
Enter your choice: 5

Preorder traversal (non-recursive): + + / A ^ B C * D E * A C

Choose from the following:
Recursive Traversals:
1. Inorder Traversal.
2. Preorder Traversal.
3. Postorder Traversal.
Non-Recursive Traversals:
4. Inorder Traversal.
5. Preorder Traversal.
6. Postorder Traversal.
7. Exit.
Enter your choice: 6

Postorder traversal (non-recursive): A B C ^ / D E * + A C * +

Choose from the following:
Recursive Traversals:
1. Inorder Traversal.
2. Preorder Traversal.
3. Postorder Traversal.
Non-Recursive Traversals:
4. Inorder Traversal.
5. Preorder Traversal.
6. Postorder Traversal.
7. Exit.
Enter your choice: 7
 */
