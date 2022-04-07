/*

                             TOWER OF HANOI PUZZLE

*/
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
void menu();
void Result(int token);
void checker(int stk[],int disc,int a);
void display(int s1[],int n1,int s2[],int n2,int s3[],int n3,int a);
void Main();
int moveChooser();
void game(int discs);
void operationSelector(int ch);
int main()
{
    cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME..........."<<endl<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t THE TOWER OF HANOI PUZZLE"<<endl<<"\t\t\t\t\t\t";
    cout<<"\n\n\t\t\t\t\t THE TOWER OF HANOI GAME IS A PUZZLE INVENTED BY FRENCH MATHEMATICIAN EDUOUARD LUCAS IN 1883."<<"\n\t\t\t\t\t IT CONSISTS OF THREE TOWERS WITH n DISKS PLACED ONE OVER THE OTHER."<<"\n\t\t\t\t\t THE OBJECTIVE OF THE PUZZLE IS TO MOVE THE STACK TO ANOTHER TOWER FOLLOWING SOME SIMPLE RULES."<<endl<<"\n\n \t\t\t\t\t";;
    system("pause");
    menu();
    return 0;       
}

void menu()
{
	int choice;
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t"<<"TOWER OF HANOI PUZZLE"<<endl;
	cout<<"\t\t\t\t\t\t\t\t====================="<<endl;
	cout<<"\n\t\t\t\t\t\tCHOOSE OPERATION:"<<endl;
    cout<<"\t\t\t\t\t\t1 PLAY GAME"<<endl<<endl;
    cout<<"\t\t\t\t\t\tOTHER KEY TO EXIT"<<endl<<"\t\t\t\t\t\t";
    cin>>choice;
    operationSelector(choice);
}
void operationSelector(int ch)
{
	switch(ch)
	{
		case 1:
			Main();
			break;
        default:
        	exit(1);
        	break;
	}
}
void Main()
{
	int n;
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t"<<"TOWER OF HANOI PUZZLE"<<endl;
	cout<<"\t\t\t\t\t\t\t\t====================="<<endl;
	cout<<"\n\t\t\t\t\t\tENTER THE NUMBER OF INTEGERS TO BE PLACED IN THE ORIGINAL STACK(TOWER A):"<<endl<<"\t\t\t\t\t\t";
	cout<<"Discs = ";
	cin>>n;
	cout<<"\n\t\t\t\t\t\tYOU HAVE A MINIMUM OF "<<(pow(2,n)-1)<<" TRIALS AND THE GAME WILL BE OVER IN "<<(pow(2,n)-1+n)<<" TRIALS. "<<"\n\t\t\t\t\t\t"<<"YOU WILL WIN IF YOU SOLVE THE PUZZLE IN "<<(pow(2,n)-1)<<" TO "<<(pow(2,n)-1+n)<<" TRIALS. GOOD LUCK!"<<endl;
	cout<<"\n\t\t\t\t\t\t";
	system("pause");
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t"<<"TOWER OF HANOI PUZZLE"<<endl;
	cout<<"\t\t\t\t\t\t\t\t====================="<<endl;
	game(n);
}
void game(int discs)
{
    int stack1[discs],stack2[discs],stack3[discs];
    int top1=-1,top2=-1,top3=-1,min,max,resp;
    min=pow(2,discs)-1;
    max=pow(2,discs)-1+discs;
    for(int i=0;i<discs;i++)
	{
		top1++;
		stack1[i]=discs-i;
	}
	cout<<"\n\n\t\t\t\t\t\t INITIAL CONTENT: "<<endl;
			        display(stack1,top1,stack2,top2,stack3,top3,1);
			        display(stack1,top1,stack2,top2,stack3,top3,2);
			        display(stack1,top1,stack2,top2,stack3,top3,3);
	resp=moveChooser();
	int num=1;
	a:
      switch(resp)
	  {
	  	case 1:
        {
		  	if(top1==-1)
			  {
			  	cout<<"\n\t\t\t\t\t\tNO ELEMENT TO MOVE! TRY AGAIN. "<<endl;
                resp=moveChooser();
				goto a;		  	
			  }
            else
    	      {
 	      	       if(num>max)
					   {
                     	goto b;
					   }
					   
                   else
                   {
				 	  if(stack2[top2]<stack1[top1] && top2!=-1)
                      {
					    num++;
						cout<<"\n\t\t\t\t\t\tCAN'T MOVE A LARGER ELEMENT TO THE TOP OF A SMALLER ELEMENT, TRY AGAIN!"<<endl;
				 	    resp=moveChooser();
					    goto a;
                      }
                      else
                      {
       	               top2++;
					   stack2[top2]=stack1[top1];
					   cout<<"\n\t\t\t\t\t\t"<<stack1[top1]<<" MOVED TO STACK2 SUCCESSFULLY! ";
			           top1--;
			           if(num>=min)
			        	checker(stack3,discs,num);
			        cout<<"\n\n\t\t\t\t\t\t CURRENT CONTENT: "<<endl;
			        display(stack1,top1,stack2,top2,stack3,top3,1);
			        display(stack1,top1,stack2,top2,stack3,top3,2);
			        display(stack1,top1,stack2,top2,stack3,top3,3);
                       cout<<"\n\t\t\t\t\t\tYOU ARE LEFT WITH "<<(max-num)<<" TRIALS. ";
                       num++;
                        if(num>max)
					      goto b;
					   resp=moveChooser();
					   goto a;
					  }
				   }
				} 	
        }
        case 2:
		{
		      if(top1==-1)
			  {
			  	cout<<"\n\t\t\t\t\t\tNO ELEMENT TO MOVE! TRY AGAIN. "<<endl;
                resp=moveChooser();
				goto a;		  	
			  }
              else
    	      {
         	      	if(num>max)
					   {
                     	goto b;
					   }
                    else
					   {
					   	 if(stack3[top3]<stack1[top1] && top3!=-1)
                         {
					       num++;
						   cout<<"\n\t\t\t\t\t\tCAN'T MOVE A LARGER ELEMENT TO THE TOP OF A SMALLER ELEMENT, TRY AGAIN!"<<endl;
				 	       resp=moveChooser();
					       goto a;
                         }
                         else
                         {
				        	top3++;
					        stack3[top3]=stack1[top1];
                            cout<<"\n\t\t\t\t\t\t"<<stack1[top1]<<" MOVED TO STACK3 SUCCESSFULLY! ";
			                top1--;
			                if(num>=min)
			        	       checker(stack3,discs,num);
			        	    cout<<"\n\n\t\t\t\t\t\t CURRENT CONTENT: "<<endl;
            			        display(stack1,top1,stack2,top2,stack3,top3,1);
			                    display(stack1,top1,stack2,top2,stack3,top3,2);
                                display(stack1,top1,stack2,top2,stack3,top3,3);
                            cout<<"\n\t\t\t\t\t\tYOU ARE LEFT WITH "<<(max-num)<<" TRIALS. ";
				            num++;
				            if(num>max)
					          goto b;
					        resp=moveChooser();
					        goto a;
					      }
			        	}
			  } 		
		}
		case 3:
        {
		      if(top2==-1)
			  {
			  	cout<<"\n\t\t\t\t\t\tNO ELEMENT TO MOVE! TRY AGAIN. "<<endl;
                resp=moveChooser();
				goto a;		  	
			  }
              else
    	      {
      	      	   if(num>max)
					   {
        	             goto b;
			   		   }
					   else
					   {
					   	 if(stack1[top1]<stack2[top2] && top1!=-1)
                         {
					       num++;
						   cout<<"\n\t\t\t\t\t\tCAN'T MOVE A LARGER ELEMENT TO THE TOP OF A SMALLER ELEMENT, TRY AGAIN!"<<endl;
				 	       resp=moveChooser();
					       goto a;
                          }
                         else
                         {
					       top1++;
					       stack1[top1]=stack2[top2];
                           cout<<"\n\t\t\t\t\t\t"<<stack2[top2]<<" MOVED TO STACK1 SUCCESSFULLY! ";
			               top2--;
                            if(num>=min)
			        	    checker(stack3,discs,num);
			        	 cout<<"\n\n\t\t\t\t\t\t CURRENT CONTENT: "<<endl;
        			        display(stack1,top1,stack2,top2,stack3,top3,1);
		        	        display(stack1,top1,stack2,top2,stack3,top3,2);
			                display(stack1,top1,stack2,top2,stack3,top3,3);
                            cout<<"\n\t\t\t\t\t\tYOU ARE LEFT WITH "<<(max-num)<<" TRIALS. ";
					        num++;
					        if(num>max)
					          goto b;
					        resp=moveChooser();
					        goto a;
					      }
					   }
			 }	
        }
		case 4:
        {
        	if(top2==-1)
			  {
			  	cout<<"\n\t\t\t\t\t\tNO ELEMENT TO MOVE! TRY AGAIN. "<<endl;
                resp=moveChooser();
				goto a;		  	
			  }
            else
    	      {
    	      	    if(num>max)
					  {
                    	goto b;
					  }
					  else
					  {
                        if(stack3[top3]<stack2[top2] && top3!=-1)
                        {
					      num++;
						  cout<<"\n\t\t\t\t\t\tCAN'T MOVE A LARGER ELEMENT TO THE TOP OF A SMALLER ELEMENT, TRY AGAIN!"<<endl;
				 	      resp=moveChooser();
					      goto a;
                        }
                      else
                      {
					    top3++;
					    stack3[top3]=stack2[top2];
                        cout<<"\n\t\t\t\t\t\t"<<stack2[top2]<<" MOVED TO STACK3 SUCCESSFULLY! ";
			            top2--;
			            if(num>=min)
			        	  checker(stack3,discs,num);
			           cout<<"\n\n\t\t\t\t\t\t CURRENT CONTENT: "<<endl;
    			              display(stack1,top1,stack2,top2,stack3,top3,1);
	        		          display(stack1,top1,stack2,top2,stack3,top3,2);
			                  display(stack1,top1,stack2,top2,stack3,top3,3);
                        cout<<"\n\t\t\t\t\t\tYOU ARE LEFT WITH "<<(max-num)<<" TRIALS. ";
					    num++;
					    if(num>max)
					      goto b;
					    resp=moveChooser();
					    goto a;
					   }
				      } 	
			  }
        }
		case 5:
        {
			if(top3==-1)
			  {
			  	cout<<"\n\t\t\t\t\t\tNO ELEMENT TO MOVE! TRY AGAIN. "<<endl;
                resp=moveChooser();
				goto a;		  	
			  }
            else
    	      {
         	      	if(num>max)
                    {
                    	goto b;
                    }
					else
					{
                      if(stack1[top1]<stack3[top3] && top1!=-1)
                      {
					    num++;
						cout<<"\n\t\t\t\t\t\tCAN'T MOVE A LARGER ELEMENT TO THE TOP OF A SMALLER ELEMENT, TRY AGAIN!"<<endl;
				 	    resp=moveChooser();
					    goto a;
                      }
                      else
                      {
				       top1++;
					   stack1[top1]=stack3[top3];
                       cout<<"\n\t\t\t\t\t\t"<<stack3[top3]<<" MOVED TO STACK1 SUCCESSFULLY! ";
			           top3--;
			           if(num>=min)
			          	 checker(stack3,discs,num);
			            cout<<"\n\n\t\t\t\t\t\t CURRENT CONTENT: "<<endl;
     			        display(stack1,top1,stack2,top2,stack3,top3,1);
 	     		        display(stack1,top1,stack2,top2,stack3,top3,2);
		     	        display(stack1,top1,stack2,top2,stack3,top3,3);
                       cout<<"\n\t\t\t\t\t\tYOU ARE LEFT WITH "<<(max-num)<<" TRIALS. ";
					   num++;
					   if(num>max)
					      goto b;
					   resp=moveChooser();
					   goto a;
	    	           }
				     }
			   } 	
        }
		case 6:
        {
			if(top3==-1)
			  {
			  	cout<<"\n\t\t\t\t\t\tNO ELEMENT TO MOVE! TRY AGAIN. "<<endl;
                resp=moveChooser();
				goto a;	  	
			  }
            else
    	      {
        	      	if(num>max)
                    	goto b;
                    else
					{
                      if(stack2[top2]<stack3[top3] && top2!=-1)
                      {
					    num++;
						cout<<"\n\t\t\t\t\t\tCAN'T MOVE A LARGER ELEMENT TO THE TOP OF A SMALLER ELEMENT, TRY AGAIN!"<<endl;
				 	    resp=moveChooser();
					    goto a;
                      }
                      else
                      {
					   top2++;
					   stack2[top2]=stack3[top3];
                       cout<<"\n\t\t\t\t\t\t"<<stack3[top3]<<" MOVED TO STACK2 SUCCESSFULLY! ";
			           top3--;
			           if(num>=min)
			            	checker(stack3,discs,num);
			             cout<<"\n\n\t\t\t\t\t\t CURRENT CONTENT: "<<endl;
         			        display(stack1,top1,stack2,top2,stack3,top3,1);
		     	             display(stack1,top1,stack2,top2,stack3,top3,2);
			                 display(stack1,top1,stack2,top2,stack3,top3,3);
                       cout<<"\n\t\t\t\t\t\tYOU ARE LEFT WITH "<<(max-num)<<" TRIALS. ";
					   num++;
					   if(num>max)
					      goto b;
					   resp=moveChooser();
					   goto a;
					   }
			       	} 
			  }
        }
		default:
        {
        	cout<<"\n\t\t\t\t\t\tWRONG INPUT! TRY AGAIN"<<endl;
			resp=moveChooser();
			goto a;
		}	
	  }
	  b:
	  cout<<"\n\n\t\t\t\t\t THE GAME IS OVER! ";
	  cout<<"\n\t\t\t\t\tENTER ANY KEY TO SEE THE RESULT";
	  cout<<"\n\t\t\t\t\t";
	  system("pause");
	  system("cls");
      int amt=0;
	  for(int i=0;i<discs;i++)
	  {
	  	if(stack3[i]==discs-i)
	  		amt++;
	  }
	  if(amt==discs)
	  	Result(1);
	  else
	  	Result(0);
}
void checker(int stk3[],int disc,int a)
{
	int amt=0;
	char res;
      for(int i=0;i<disc;i++)
	  {
	  	if(stk3[i]==disc-i)
	  		amt++;
	  }
	  if(amt==disc)
	  {
	  	cout<<"\n\n\t\t\t\t\t\tCONGRATULATIONS! YOU WON..."<<endl<<"\n\t\t\t\t\t\tENJOY THE GAME? PRESS P TO PLAY AGAIN OR OTHER KEY TO EXIT."<<endl;
        cout<<"\n\t\t\t\t\t\t";
        cin>>res;
        if(res=='P' || res=='p')
        	menu();
		else
			exit(1);	
	  }
	  else
	     cout<<"\n\n\t\t\t\t\t\tTHE PUZZLE IS NOT SOLVED ON THE "<<a<<" th "<<" TRIAL , \n\t\t\t\t\t\tLOOKS LIKE THE GAME IS A LITTLE TRICKY FOR YOU..."<<endl;	
}
void Result(int token)
{
	char res;
	if(token==1)
	{
        cout<<"\n\n\t\t\t\t\t\tCONGRATULATIONS! YOU WON..."<<endl<<"\n\t\t\t\t\t\tENJOY THE GAME? PRESS ENTER TO PLAY AGAIN OR OTHER KEY TO EXIT."<<endl;
        cout<<"\n\t\t\t\t\t\t";
        cin>>res;
        if(res=='P' || res=='p')
		  menu();
	    else
			exit(1);	
	}
	else
	{
		cout<<"\n\t\t\t\t\t\tYOU LOSE! YOU MAY TRY AGAIN....."<<endl;
		cout<<"\n\t\t\t\t\t\t"<<endl;
		system("pause");
		menu();
	}
}

int moveChooser()
{
	  int m;
      cout<<"\n\n\t\t\t\t\t\tUSE THE FOLLOWING INPUTS TO MOVE TOP ELEMENTS FROM ONE TO ANOTHER STACK:"<<endl;
	  cout<<"\n\t\t\t\t\t\t1 TO MOVE THE TOP ELEMENT FROM STACK 1 TO 2"<<endl;
	  cout<<"\n\t\t\t\t\t\t2 TO MOVE THE TOP ELEMENT FROM STACK 1 TO 3"<<endl;
	  cout<<"\n\t\t\t\t\t\t3 TO MOVE THE TOP ELEMENT FROM STACK 2 TO 1"<<endl;
	  cout<<"\n\t\t\t\t\t\t4 TO MOVE THE TOP ELEMENT FROM STACK 2 TO 3"<<endl;
	  cout<<"\n\t\t\t\t\t\t5 TO MOVE THE TOP ELEMENT FROM STACK 3 TO 1"<<endl;
	  cout<<"\n\t\t\t\t\t\t6 TO MOVE THE TOP ELEMENT FROM STACK 3 TO 2"<<endl;
	  cout<<"\n\t\t\t\t\t\t";
	  cin>>m;
	  return m;
}
void display(int s1[],int n1,int s2[],int n2,int s3[],int n3,int a)
{
	switch(a)
	{
		case 1:{
        	cout<<"\t\t\t\t\t\tSTACK 1(TOP TO BOTTOM)"<<endl<<"\t\t\t\t\t\t";
	        for(int i=n1;i>=0;i--)
		       cout<<s1[i]<<"  ";
		       cout<<endl;
		       break;
		        }
		case 2:{
			   cout<<"\t\t\t\t\t\tSTACK 2(TOP TO BOTTOM)"<<endl<<"\t\t\t\t\t\t";
	           for(int i=n2;i>=0;i--)
		         cout<<s2[i]<<"  ";
		       cout<<endl;
		       break;
        		}
		case 3:{
			    cout<<"\t\t\t\t\t\tSTACK 3(TOP TO BOTTOM)"<<endl<<"\t\t\t\t\t\t";
	            for(int i=n3;i>=0;i--)
		         cout<<s3[i]<<"  ";
		        cout<<endl;
		        break;
		       }
		default:
			;
    }
}