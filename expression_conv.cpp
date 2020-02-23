 //============================================================================
// Name        : expression_conv.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include"stackAdt.h"
#include"stackAdt.cpp"

#include <iostream>
#include<iomanip>
using namespace std;

class expression    //class declaration
{
	char infix[20], postfix[20],prefix[20];

public:
	void scan_infix();
	void display(char,stackAdt<char>,char []);
	void infixtopostfix();
	int precedence(char);
	int associativity(char);
	void infixtoprefix();
	int eval_post();
	int eval_pre();
};

void expression::scan_infix()       //To take infix expression from user
{
	cout<<"\nEnter the infix expression:";
	cin>>infix;
}

void expression::display(char x,stackAdt<char> s,char exp[])   //to display stepwise stack and output content
{
	cout<<'\n'<<setw(-25)<<x<<"\t\t|"<<setw(15)<<s.peep()<<"\t|"<<setw(15)<<exp;
}

int expression::precedence(char s)     //to check precedence of operators
{
	if(s=='+' || s=='-')
	return 1;
	else if(s=='*' ||s=='/' || s=='%')
	return 2;
	else if(s=='^')
	return 3;

	return 0;
}

int expression::associativity(char s)     //to check associativity of operator
{
     if(s=='+' ||s=='-' ||s=='*' ||s=='/'|| s=='%')
    	 return 1;
     return 2;
}

void expression::infixtopostfix()     //to convert infix expression to postfix
{
   int i=0,j=0;
   stackAdt<char> s;        //character stack as variable

   	cout<<setw(-25)<<"\nInput character"<<"\t|"<<setw(15)<<"Stack"<<"\t|"<<setw(15)<<"Postfix";

   while(infix[i]!='\0')          //to scan infix expression till end
   {
	  if((infix[i] >='a' && infix[i] <='z')||(infix[i] >='A' && infix[i ]<='Z' ) || (infix[i] >='0' && infix[i] <='9')) //if operand add to postfix
	   {
		postfix[j]=infix[i];
		postfix[j+1]='\0';
		j++;
	   }
	  else if(infix[i]=='(')    //if left parenthesis ,push it to stack
       {
           s.push(infix[i]);
       }
       else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' ||infix[i]=='/' ||infix[i]=='^' || infix[i]=='%') //if operator
	   {
	   	   if(s.isempty())   //if stack is empty ,push operator on stack
	   	    s.push(infix[i]);
	   	   else if(precedence(infix[i]) > precedence(s.peep()) ||s.peep()=='(') //if precedence of operator is higher than precedence of operator which is at top of stack
	   	   {
	   	   	   s.push(infix[i]);
		   }
		   else if(precedence(infix[i]) <= precedence(s.peep()))
		   {
		   	   while(precedence(infix[i]) < precedence(s.peep()))//if precedence is lower than precedence of operator which is at top of stack
		   	   {
		   	   	postfix[j]=s.pop();    //add operator to postfix expression
		   	   	postfix[j+1]='\0';
		   	   	j++;
		   	   }
		   	   if(precedence(infix[i]) == precedence(s.peep())) //if precedence is equal to precedence of operator which is at top of stack,check associativity
				   {
						if(associativity(infix[i])==1)  // if associativity of operator is left to right,add it to
						{
							postfix[j]=s.pop();
							postfix[j+1]='\0';
							j++;
							s.push(infix[i]);
						}
						else                         //if associativity of operator is right to left,push it on stack
							s.push(infix[i]);
				   }
		   	   else
		   		   s.push(infix[i]);
		   }
	   }
       else if(infix[i]==')')   //if right parenthesis encountered
       {
    	   while(s.peep()!='(')  //pop operand till left parenthesis is on top of stack
    	   {
    		   postfix[j]=s.pop();
    		   postfix[j+1]='\0';
    		   j++;
    	   }
    	   s.pop();   //remove left parenthesis from stack
       }
	   display(infix[i],s,postfix);  //to display stepwise conversion
	   i++;
   }
   while(!s.isempty())   //if stack is not empty
   {
   	   if(s.peep()!='(')  //pop all operators except left parenthesis
   	   {
	       postfix[j]=s.pop();
	       postfix[j+1]='\0';
	       j++;
       }
   }
   cout<<"\n\nPostfix Expression::"<<postfix;
}

void expression::infixtoprefix()
{
	int i=0,j=0,l;
	stackAdt<char> s;
	char infix_rev[20],prefix_rev[20];
	prefix_rev[0]='\0';
   	cout<<setw(-25)<<"\nInput character"<<"\t|"<<setw(15)<<"Stack"<<"\t|"<<setw(15)<<"Prefix";
	while(infix[i]!='\0')
	{
		i++;
	}
	l=i;
	i=0;
	while(infix[i]!='\0')
	{
		infix_rev[l-i-1]=infix[i];
		i++;
	}
	i=0;
	while(infix_rev[i]!='\0')
	   {
		  if((infix_rev[i] >='a' && infix_rev[i] <='z')||(infix_rev[i] >='A' && infix_rev[i]<='Z' )|| (infix_rev[i] >='0' && infix_rev[i] <='9'))
		   {
			prefix_rev[j]=infix_rev[i];
			prefix_rev[j+1]='\0';
			j++;
		   }
		  else if(infix_rev[i]==')')
	       {
	           s.push(infix_rev[i]);
	       }
	       else if(infix_rev[i]=='+' || infix_rev[i]=='-' || infix_rev[i]=='*' ||infix_rev[i]=='/' ||infix_rev[i]=='^' || infix_rev[i]=='%')
		   {
		   	   if(s.isempty())
		   	    s.push(infix_rev[i]);
		   	   else if(precedence(infix_rev[i]) > precedence(s.peep()) ||s.peep()==')')
		   	   {
		   	   	   s.push(infix_rev[i]);
			   }
			   else if(precedence(infix_rev[i]) <= precedence(s.peep()))
			   {
			   	   while(precedence(infix_rev[i]) < precedence(s.peep()))
			   	   {
			   		prefix_rev[j]=s.pop();
			   		prefix_rev[j+1]='\0';
			   	   	j++;
			   	   }

			   	   if(precedence(infix_rev[i]) == precedence(s.peep()))
					   {
							if(associativity(infix_rev[i])==1)
							{
								prefix_rev[j]=s.pop();
								prefix_rev[j+1]='\0';
								j++;
								s.push(infix_rev[i]);
							}
							else
								s.push(infix_rev[i]);
					   }
			   	   else
			   		s.push(infix_rev[i]);
			   }
		   }
	       else if(infix_rev[i]=='(')
	       {
	    	   while(s.peep()!=')')
	    	   {
	    		   prefix_rev[j]=s.pop();
	    		   prefix_rev[j+1]='\0';
	    		   j++;
	    	   }
	    	   s.pop();
	       }
		   display(infix_rev[i],s,prefix_rev);
		   i++;
	   }
	   while(!s.isempty())
	   {
	   	  if(s.peep()!=')')
	   	  {//if input is digits
		   prefix_rev[j]=s.pop();
		   prefix_rev[j+1]='\0';
		   j++;
	      }
	   }
	   i=0;
	   while(prefix_rev[i]!='\0')
	   i++;
	   l=i;
	i=0;
	while(prefix_rev[i]!='\0')
		{
			prefix[l-i-1]=prefix_rev[i];
			i++;
		}
       prefix[i]='\0';
    cout<<"\n\nPrefix Expression::"<<prefix;
}

int expression::eval_post()  //to evaluate postfix expression
{
   int i=0,a,b,n;
   stackAdt<int> s;        //integer stack as variable
   infixtopostfix();
   while(postfix[i]!='\0')   //to scan till end of postfix expression
   {
   	   if((postfix[i] >='a' && postfix[i] <='z') ||(postfix[i] >='A' && postfix[i] <='Z')) //if operator, take its value from user
   	   {
   		    cout<<"\nEnter the value of "<<postfix[i]<<":";
   		    cin>>n;
   		    s.push(n);         //push it to stack
   	   }
   	   else if((postfix[i] >='0' && postfix[i] <='9'))  //if input is digits
   	   {
   		   s.push(postfix[i]-48);  //push its value to stack
   	   }
   	   else
   	    {
   	    	a=s.pop();   //take second operand
   	    	b=s.pop();   //take first operand
   	        switch (postfix[i])
   	        {
   	        	case '+':s.push(b+a);    //perform addition and push result on stack
   	        	         break;
   	        	case '-':s.push(b-a);    //perform subtraction and push result on stack
   	        	         break;
   	            case '*':s.push(b*a);    //perform multiplication and push result on stack
   	                     break;
   	            case '/':s.push(b/a);    //perform divison and push result on stack
   	        	         break;
   	        	case '%':s.push(b%a);    //calculate modulus and push result on stack
   	        	         break;
   	        	case '^':s.push(b^a);    //calculate exponent and push result on stack
   	        	         break;
		    }
		}
   	   i++;
   }
   return s.pop();   //result of given expression
}

int expression::eval_pre()   //to evaluate prefix expression
{
	int i=0,a,b,l,n;
	char prefix_rev[20];
   stackAdt<int> s;         //integer stack as variable
   infixtoprefix();
   while(prefix[i]!='\0')    //calculate length of prefix expression
   i++;
   l=i;
   i=0;
   while(prefix[i]!='\0')     //reverse the prefix expression
		{
			prefix_rev[l-i-1]=prefix[i];
			i++;
		}
       prefix_rev[i]='\0';

   i=0;
   while(prefix_rev[i]!='\0')  //to scan till end of reverse of prefix expression
   {
	  if((prefix_rev[i] >='a' && prefix_rev[i] <='z') || (prefix_rev[i] >='A' && prefix_rev[i] <='Z')) //if operator, take its value from user
	  {
		  cout<<"\nEnter the value of "<<prefix_rev[i]<<":";
		  cin>>n;
		  s.push(n);   //push it to stack
	  }
	  else if(prefix_rev[i] >='0' && prefix_rev[i] <='9')  //if input is digits
   	   s.push(prefix_rev[i]-48);   //push its value to stack

   	   else
   	    {
   	    	a=s.pop();    //take first operand
   	    	b=s.pop();    //take second operand
   	        switch (prefix_rev[i])
   	        {
   	        	case '+':s.push(a+b);   //perform addition and push result on stack
   	        	         break;
   	        	case '-':s.push(a-b);   //perform subtraction and push result on stack
   	        	         break;
   	            case '*':s.push(a*b);   //perform multiplication and push result on stack
   	                     break;
   	            case '/':s.push(a/b);   //perform divison and push result on stack
   	        	         break;
   	        	case '%':s.push(a%b);   //calculate modulus and push result on stack
   	        	         break;
   	        	case '^':s.push(a^b);   //calculate exponent and push result on stack
   	        	         break;
		    }
		}
   	   i++;
   }
   return s.pop();   //result of given expression
}

int main()  //menudriven code
{
   expression e1;
   int n,ch;

   do
   {
   	cout<<"\n\n*****MENU*****";
   	cout<<"\n\t1.Infix to Postfix Coversion";
   	cout<<"\n\t2.Infix to Prefix Coversion";
        cout<<"\n\t3.Postfix Evaluation";
        cout<<"\n\t4.Prefix Evaluation";
        cout<<"\n\t5.Exit";
        cout<<"\nEnter choice:";
        cin>>ch;

	    switch(ch)
	    {
	    	case 1:
	    		e1.scan_infix();     //for Infix to Postfix Coversion
	   			e1.infixtopostfix();
	   			break;

	   		case 2:
	   			e1.scan_infix();     //for Infix to Prefix Coversion
	   			e1.infixtoprefix();
	   			break;

	   		case 3:
	   			e1.scan_infix();   //for Postfix Evaluation
	  			 n=e1.eval_post();
	   			cout<<"\nOutput of Given Expression="<<n;
	   			break;

	   		case 4:
	   			e1.scan_infix();   //for Prefix Evaluation
	   			n=e1.eval_pre();
	  			cout<<"\nOutput of Given Expression="<<n;
	  			 break;
		}

   }while(ch!=5);
}
