/*============================================================================
  ROLL NO.  		:23245
  BATCH         	: G-10
  ASSIGNMENT NO.	: 1
  PROBLEM STATEMENT	: Implement stack as an Abstract Data Type using
  	  	  	  	  	  Linked organization and use this Abstract Data
  	  	  	  	  	  Type for the conversion of
  	  	  	  	  	  (1)Infix expression to prefix expression
  	  	  	  	  	  (2)Infix expression to postfix expression
  	  	  	  	  	  (3)Evaluation of Prefix and postfix expressions.
  ============================================================================
*/

#include <iostream>
#include <algorithm>
#include "stack.h"
#include "stack.cpp"
using namespace std;

class expressions
{
	string exp,preexp,postexp;
	char c;

	public:	void getexpinfix();
			void getexpprefix();
			void getexppostfix();
			int priority(char);
			void InfixToPostfix();
			void InfixToPrefix();
			void evaluatepost();
			void evaluatepre();
			int validInfix();

};


int main() {

	expressions exp1;
	stack<char> s;
	int choice,i=0,j=0,type1;
	char output[30];

	do
	{
		cout<<"\n\t\tMENU::";
		cout<<"\n\t(1)Convert Infix Expression to Postfix Expression";
		cout<<"\n\t(2)Convert Infix Expression to Prefix Expression";
		cout<<"\n\t(3)Evaluate Prefix Expression";
		cout<<"\n\t(4)Evaluate Postfix Expression";
		cout<<"\n\t(5)EXIT";
		cout<<"\n\n\tEnter your Choice : ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			exp1.getexpinfix();
			exp1.InfixToPostfix();
			break;

		case 2:
			exp1.getexpinfix();
			exp1.InfixToPrefix();
			break;

		case 3:
			exp1.getexpprefix();
			exp1.evaluatepre();
			break;

		case 4:
			exp1.getexppostfix();
			exp1.evaluatepost();
			break;


		case 5: //EXIT
			return 0;

		default: //invalid
			cout<<"Invalid Choice !!!";
			break;
		}
	}while(1);
	return 0;
}

void expressions::getexpinfix()
{
	cout<<"\nEnter Infix expression : ";
	cin>>exp;
}

void expressions::getexpprefix()
{
	cout<<"\nEnter Prefix expression to evaluate: ";
	cin>>exp;
}

void expressions::getexppostfix()
{
	cout<<"\nEnter Postfix expression to evaluate: ";
	cin>>exp;
}


int expressions::priority(char ch)
{
	if( ch=='^')
	{
		return 4;
	}
	else if( ch=='*' || ch=='/' || ch=='%')
	{
		return 3;
	}
	else if( ch=='+' || ch=='-')
	{
		return 2;
	}
	else if( ch=='(' || ch==')')
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

void expressions::InfixToPostfix()
{
    stack<char> st;
    char c;
    int l,i,pri,valid;
    l = exp.length();

    valid=validInfix();
    if(valid==1)
    {
		for(i=0;i<l;i++)
		{
			//If an operator is scanned
			if(exp[i]=='*' || exp[i]=='/' || exp[i]=='%' || exp[i]=='^' || exp[i]=='+' || exp[i]=='-')
			{
				if(st.isEmpty()==0)
				{
					c=st.stacktop();
					pri=priority(c);
					if(exp[i]=='^')
					{
						while(st.isEmpty()==0 && (pri > priority(exp[i])))
						{
							c=st.pop();
							postexp += c;
						}
					}
					else
					{
						while(st.isEmpty()==0 && (pri >= priority(exp[i])))
						{
							c=st.pop();
							postexp += c;
						}
					}
				}
				st.push(exp[i]);

			}


			// If character is ( push it to the stack.
			else if(exp[i] == '(')
			{
				st.push('(');
			}

			// If character is  ) pop until ( occurs
			else if(exp[i] == ')')
			{
				while(st.stacktop() != '(')
				{
					c=st.pop();
				   postexp += c;
				}
				if(st.stacktop() == '(')
				{
					c=st.pop();
				}
			}

			// If character is operand
			else
			{
				postexp+=exp[i];
			}


		}

		//Pop all the remaining elements from the stack
		while(st.isEmpty()==0)
		{
			c = st.pop();
			postexp += c;
		}

		cout<<"\nPOSTFIX FOR OF THE EXPRESSION IS ::\n\t";
		cout<<postexp;
    }
    else
    {
    	cout<<"INVALID EXPRESSION !!!";
    }

	postexp.clear();
}


void expressions::InfixToPrefix()
{
    stack<char> st;
    char c;
    int l,i,k=0,pri,valid;
    l = exp.length();
    string postexp,preexp;;

    valid=validInfix();
    if(valid==1)
    {
		for(i=l-1;i>=0;i--)		//scan in reverse
		{
			//If an operator is scanned
			if(exp[i]=='*' || exp[i]=='/' || exp[i]=='%' || exp[i]=='^' || exp[i]=='+' || exp[i]=='-')
			{
				if(st.isEmpty()==0)
				{
					if(exp[i]=='^')
					{
						while((st.isEmpty()==0) && (priority(st.stacktop()) >= priority(exp[i])))
						{
							postexp += st.pop();

						}
					}
					else
					{
						while((st.isEmpty()==0) && (priority(st.stacktop()) > priority(exp[i])))
						{
							c=st.pop();
							postexp += c;
						}
					}
				}
				st.push(exp[i]);

			}


			// If character is ( push it to the stack.
			else if(exp[i] == ')')
			{
				st.push(')');
			}

			// If character is  ) pop until ( occurs
			else if(exp[i] == '(')
			{
				while(st.stacktop() != ')')
				{
					c=st.pop();
				   postexp += c;
				}
				if(st.stacktop() == ')')
				{
					c=st.pop();
				}
			}

			// If character is operand
			else
			{
				postexp+=exp[i];
			}
		}

		//Pop all the remaining elements from the stack
		while(st.isEmpty()==0)
		{
			c = st.pop();
			postexp += c;
		}

		reverse(postexp.begin(),postexp.end());
		preexp=postexp;

		cout<<"\nPREFIX FOR OF THE EXPRESSION IS ::\n\t";
		cout<<preexp;

    }
    else
    {
    	cout<<"INVALID EXPRESSION !";
    }
    preexp.clear();
}

void expressions::evaluatepost()
{
	int operand1,operand2,result,i,l,temp;
	stack<int> st;
	l=exp.length();

	for(i=0;i<l;i++)
    {
    	if(exp[i]=='(' || exp[i]==')')
    	{
    		cout<<"\n\nINVALID EXPRESSION!!\n\n";
    		return;
    	}
    	if( (exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z') )
 		{
    		cout<<"Enter Value of "<<exp[i]<<" = ";
    		cin>>exp[i];
    	}
    }


	for(i=0;i<l;i++)
	{
		//If an operator is scanned
		if(exp[i]=='*' || exp[i]=='/' || exp[i]=='%' || exp[i]=='^' || exp[i]=='+' || exp[i]=='-')
		{
			if(st.isEmpty()==1)				//invalid if empty stack
			{
				cout<<"\n\tINVALID EXPRESSION\n";
				return;
			}
			else
			{
				operand1=st.pop();			//else take operand
			}
			if(st.isEmpty()==1)				//invalid if empty stack
			{
				cout<<"\n\tINVALID EXPRESSION\n";
				return;
			}
			else
			{
				operand2=st.pop();			//else take operand
			}
			//evalations
			if(exp[i]=='*')
			{
				result=operand1*operand2;
				st.push(result);
			}
			else if(exp[i]=='/')
			{
				result=operand1/operand2;
				st.push(result);
			}
			else if(exp[i]=='%')
			{
				result=operand1%operand2;
				st.push(result);
			}
			else if(exp[i]=='^')
			{
				result=operand1^operand2;
				st.push(result);
			}
			else if(exp[i]=='+')
			{
				result=operand1+operand2;
				st.push(result);
			}
			else
			{
				result=operand1-operand2;
				st.push(result);
			}
		}
		else	//if operand is scanned
		{
			temp=exp[i]-48;
			st.push(temp);
		}
	}
	result=st.pop();
	if(st.isEmpty()==0)
	{
		cout<<"\n\tINVALID EXPRESSION\n";
		return;
	}
	else
	{
		cout<<"\nThe evaluation of the postix expression is:\n\t";
		cout<<result;
	}

}

void expressions::evaluatepre()
{
	int operand1,operand2,result,i,l,temp;
	stack<int> st;
	l=exp.length();

	for(i=0;i<l;i++)
    {
    	if(exp[i]=='(' || exp[i]==')')
    	{
    		cout<<"\n\nINVALID EXPRESSION!!\n\n";
    		return;
    	}
    	if( (exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z') )
 		{
    		cout<<"Enter Value of "<<exp[i]<<" = ";
    		cin>>exp[i];
    	}
    }

	for(i=l-1;i>=0;i--)		//scan in reverse
	{
		//If an operator is scanned
		if(exp[i]=='*' || exp[i]=='/' || exp[i]=='%' || exp[i]=='^' || exp[i]=='+' || exp[i]=='-')
		{
			if(st.isEmpty()==1)				//invalid if empty stack
			{
				cout<<"\n\tINVALID EXPRESSION\n";
				return;
			}
			else
			{
				operand1=st.pop();			//else take operand
			}
			if(st.isEmpty()==1)				//invalid if empty stack
			{
				cout<<"\n\tINVALID EXPRESSION\n";
				return;
			}
			else
			{
				operand2=st.pop();			//else take operand
			}
			//evaluations
			if(exp[i]=='*')
			{
				result=operand1*operand2;
				st.push(result);
			}
			else if(exp[i]=='/')
			{
				result=operand1/operand2;
				st.push(result);
			}
			else if(exp[i]=='%')
			{
				result=operand1%operand2;
				st.push(result);
			}
			else if(exp[i]=='^')
			{
				result=operand1^operand2;
				st.push(result);
			}
			else if(exp[i]=='+')
			{
				result=operand1+operand2;
				st.push(result);
			}
			else
			{
				result=operand1-operand2;
				st.push(result);
			}
		}
		else	//if operand is scanned
		{
			temp=exp[i]-48;
			st.push(temp);
		}
	}
	result=st.pop();
	if(st.isEmpty()==0)
	{
		cout<<"\n\tINVALID EXPRESSION\n";
		return;
	}
	else
	{
		cout<<"\nThe evaluation of the prefix expression is:\n\t";
		cout<<result;
	}
}

int expressions::validInfix()		//return -1 for invalid, 1 for valid
{
	int l=exp.length();
	int i,operators=0,operands=0,brackets=0;
	char c;

	for(i=0;i<l-1;i++)
	{
		if(exp[i]=='*' || exp[i]=='/' || exp[i]=='%' || exp[i]=='^' || exp[i]=='+' || exp[i]=='-')
		{
			if(exp[i+1]=='*' || exp[i+1]=='/' || exp[i+1]=='%' || exp[i+1]=='^' || exp[i+1]=='+' || exp[i+1]=='-')
			{
				return -1;
			}
			else
			{
				operators++;
			}
		}
		else if(exp[i]=='(')
		{
			brackets++;
		}
		else if(exp[i]==')')
		{
			brackets--;
		}
		else
		{
			if(exp[i+1]=='*' || exp[i+1]=='/' || exp[i+1]=='%' || exp[i+1]=='^' || exp[i+1]=='+' || exp[i+1]=='-' || exp[i+1]=='(' || exp[i+1]==')')
			{
				operands++;
			}
			else
			{
				return -1;
			}
		}
	}
	if(exp[i]=='*' || exp[i]=='/' || exp[i]=='%' || exp[i]=='^' || exp[i]=='+' || exp[i]=='-')
	{
		operators++;
	}
	else if(exp[i]=='(')
	{
		brackets++;
	}
	else if(exp[i]==')')
	{
		brackets--;
	}
	else
	{
		operands++;
	}

	if((operators+1==operands) && (brackets==0))
	{
		return 1;
	}
	return -1;

}



/*					OUTPUT

		MENU::
	(1)Convert Infix Expression to Postfix Expression
	(2)Convert Infix Expression to Prefix Expression
	(3)Evaluate Prefix Expression
	(4)Evaluate Postfix Expression
	(5)EXIT

	Enter your Choice : 1

Enter Infix expression : a/b^c+d*e-a*c

POSTFIX FOR OF THE EXPRESSION IS ::
	abc^/de*+ac*-
		MENU::
	(1)Convert Infix Expression to Postfix Expression
	(2)Convert Infix Expression to Prefix Expression
	(3)Evaluate Prefix Expression
	(4)Evaluate Postfix Expression
	(5)EXIT

	Enter your Choice : 2

Enter Infix expression : a/b^c+d*e-a*c

PREFIX FOR OF THE EXPRESSION IS ::
	-+/a^bc*de*ac
		MENU::
	(1)Convert Infix Expression to Postfix Expression
	(2)Convert Infix Expression to Prefix Expression
	(3)Evaluate Prefix Expression
	(4)Evaluate Postfix Expression
	(5)EXIT

	Enter your Choice : 3

Enter Prefix expression to evaluate: +6*+A39
Enter Value of A = 5

The evaluation of the prefix expression is:
	78
		MENU::
	(1)Convert Infix Expression to Postfix Expression
	(2)Convert Infix Expression to Prefix Expression
	(3)Evaluate Prefix Expression
	(4)Evaluate Postfix Expression
	(5)EXIT

	Enter your Choice : 4

Enter Postfix expression to evaluate: ABC+*DE/-
Enter Value of A = 5
Enter Value of B = 6
Enter Value of C = 2
Enter Value of D = 9
Enter Value of E = 4

The evaluation of the postix expression is:
	-40
		MENU::
	(1)Convert Infix Expression to Postfix Expression
	(2)Convert Infix Expression to Prefix Expression
	(3)Evaluate Prefix Expression
	(4)Evaluate Postfix Expression
	(5)EXIT

	Enter your Choice : 5

 */
