#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class enter
{
	public:
		string bname,aname;
		int login()
		{
			char id[10],ch;
			char pswrd[5];
			int c=0,i=0;
			label:if (c<3)
					{
						getch();
						system("cls");
						cout<<"User Id: "<<endl;
						cin>>id;
						fflush(stdin);
						if(strcmp(id,"yaswanth")==0)
							{
								system("cls");
								label1:if(c<3)
										{
											cout<<"\nPassword: ";
											fflush(stdin);
											for(i=0;i<5;i++)
											{
												if(i==4)
												pswrd[4]='\0';
												else
												{
													pswrd[i]=getch();
													cout<<"*";
												}
											}
											if(strcmp(pswrd,"9999")==0)
											{
												system("cls");
												cout<<"Successfully logged in!"<<endl;
												cout<<"PRESS ENTER TO START"<<endl;
												getch();
												system("cls");
												return 1;												
											}
											else
											{
												system("cls");
				             					cout<<"Wrong Password!"<<endl<<"Try Again!"<<endl;
				             					getch();
				           					    system("cls");
				             					c++;
				           					    goto label1;
											}
										}
										else
										{
											cout<<"Sorry! You Can't Try Anymore."<<endl;
											getch();
											exit(1);
										}
							}
							else
							{
								system("cls");
					     		cout<<"Wrong User ID!"<<endl<<"Try Again."<<endl;
							    c++;
			                    goto label;
							}	
					}
					else
 					{   
					    system("cls");
						cout<<"Sorry You Can't Try AnyMore.!"<<endl;
						exit(1);
					}	
		return 0;		 
		}
		
int get()
   {
 		int n;
		ofstream outfile;
        outfile.open("BOOKS.txt",ios::app);
		cout<<"=========================================="<<endl;
		cout<<"HOW MANY BOOKS DO YOU WANT TO ADD "<<endl;
		cin>>n;
		for(int i=0;i<n;i++)
		    {
		       cout<<"ENTER THE BOOK NAME:"<<endl;
		       cin>>bname;
		       cout<<"ENTER THE AUTHOR NAME:"<<endl;
		       cin>>aname;
		       
		       outfile<<bname<<"\t\t";  
	           outfile<<aname<<"\t\t";
	           outfile<<"\n";
		    }
		    outfile.close();   
	        }
		void in()
	{
			int o1;
			int n1;
			int k=0;
			int x=1,q=1,p=1;
			string search;
			ifstream infile;
			infile.open("BOOKS.txt",ios::in);
			lc:cout<<"================================================"<<endl;
			cout<<" 1.SEARCH A BOOK"<<endl;
			cout<<" 2.SHOW ALL AVAILABLE BOOKS"<<endl;
			cout<<" 3.EXIT"<<endl;
			cout<<"================================================="<<endl;
			cout<<"              SELECT YOUR OPTION"<<endl;
			cin>>o1;
			if(o1==1)
					{
						l: infile.seekg(0);
						cout<<"ENTER THE BOOK YOU WANT TO SEARCH"<<endl;
						cin>>search;
						int f=0;
						while(infile)
						{
							int i2;
							int o2;
							infile>>bname;
							infile>>aname;
							
							if(search.compare(bname)==0)
							{
								cout<<"      BOOK IS AVAILABLE"<<endl;
								cout<<"......SPECIFICATIONS OF THE BOOK....."<<endl;
								cout<<"BOOK: "<<bname<<endl;
								cout<<"AUTHOR: "<<aname<<endl;
								cout<<"------------------------------------------"<<endl;
								cout<<"DO YOU WANT TO SEARCH ANY OTHER BOOK?"<<endl;
								cout<<"1.YES      2.NO"<<endl;
								cin>>n1;
								if(n1==1)
								{
									goto l;
								}
								else if (n1==2)
								{
									goto lc;	
								}
								else
								{
								cout<<"INVALID INPUT"<<endl;
							}
								f++;
								break;
							}}
							if(f==0)
							{	
							int n2;
							cout<<"SORRY! THE BOOK IS NOT AVAILABLE."<<endl;
							cout<<"DO YOU WANT TO SEARCH ANY OTHER BOOK?"<<endl;
							cout<<"1.YES       2.NO"<<endl;
							cin>>n2;
							if(n2==1)
							{
								goto l;
							}
							else if(n2==2)
							{
								goto lc;
							}
							else
							cout<<"INVALID INPUT"<<endl;
							}
						}	
				else if(o1==2)
					{
						cout<<"AVAILABLE BOOKS ARE:"<<endl;
						cout<<"\n";
						cout<<"\n";
						cout<<"BOOK NAME\tBRAND NAME\t\n"<<endl;
						while(infile.eof()==0) 
						{
							string line;
							getline(infile,line);
						
							cout<<line<<endl;
						}
						
					}
				
				else if(n1==3)
					{
						cout<<"THANK YOU FOR VISITING US"<<endl;
						exit(1);
					}
					else
					{
							cout<<"INVALID INPUT"<<endl;
						}
						infile.close();	
			}
			void update()
			{
				string find,del;
				string gu;
				int j,len;
				fstream infile;
          	    infile.open("BOOK.txt",ios::out|ios::in);
			
			cout<<"================================================"<<endl;
			cout<<" 1.UPDATE DATA"<<endl;
			cout<<" 2.DELETE DATA"<<endl;
			cout<<" 3.GO BACK"<<endl;
			cout<<"================================================="<<endl;
			cout<<"             SELECT YOUR OPTION"<<endl;
			cin>>j;
		
			if(j==1)
			{
				lb:infile.seekg(0);
				cout<<"ENTER THE BOOK NAME YOU WANT TO UPDATE: "<<endl;
				cin>>find;
				len=find.length();
				cout<<len;
				 while(infile)  
	              { 
	                int v;
	                string temp;
	                infile>>temp;

	            	if(find.compare(temp)==0)
	            	{
	            	cout<<"BOOK IS AVAILABLE TO UPDATE"<<endl;
	            	cout<<"==========================================="<<endl;
	            	cout<<"   01.NAME"<<endl;
					cout<<"   02.AUTHOR"<<endl;
					cout<<"   05.GO BACK"<<endl;
					cout<<"==========================================="<<endl;
					cout<<"DO YOU WANT TO UPDATE?"<<endl;
					cout<<"1.yes   2.no"<<endl;
	            	cin>>v;
			        }
			    	if(v==1)
			    	{
			    		cout<<"ENTER THE NEW NAME:"<<endl;
			    		cin>>bname;
			    		cout<<"ENTER THE NEW BRAND NAME:"<<endl;
			    		cin>>aname;
			    		int k;
			    		int pos=infile.tellg();
			    		cout<<pos<<endl;
			    		infile.seekp((pos)-(len)-1,ios::beg);
			    		k=infile.tellp();
			    		infile.seekp(k);
			    		infile<<bname<<"\t\t";
			    		infile<<aname<<"\t\t";
			    		cout<<"SUCCESSFULLY UPDATED:"<<endl;
			    		break;
					}
					else
					{
						exit(1);
					}
				
			    }
			}
			
				if(j==2)
			{
				lb1:infile.seekg(0);
				
				cout<<"ENTER THE BOOK NAME YOU WANT TO DELETE: "<<endl;
				cin>>del;
				len=del.length();
				cout<<len;
				 while(infile)  
	              { 
	                int v1;
	                string temp1;
	                infile>>temp1;

	            	if(del.compare(temp1)==0)
	            	{
	            	cout<<"BOOK IS AVAILABLE TO DELETE:"<<endl;
	            	cout<<"==========================================="<<endl;
	            	cout<<"DO YOU WANT TO DELETE IT?"<<endl;
	            	cout<<"1.YES   2.NO"<<endl;
					cout<<"==========================================="<<endl;
				    
	            	cin>>v1;
			    	}
			    	else
			    	{
			    		cout<<"BOOK IS NOT AVAILABLE";
			    		break;
					}
			    	if(v1==1)
			    	{
			    		int k4;
			    		int pos=infile.tellg();
			    		cout<<pos<<endl;
			    	    infile.seekp((pos)-(len)-1,ios::beg);
			    		k4=infile.tellp();
			    		infile.seekp(k4);
			    		infile<<"     "<<"\t\t";
			    		infile<<"     "<<"\t\t";
			    		infile<<"     "<<"\t\t";
			    		infile<<"     "<<"\t\t";
			    	
			    		cout<<"SUCCESSFULLY DELETED:"<<endl;
			    		break;
					}
						if(v1==2)
			    	{
			    		goto lb1;
					}
						
				
			}
		
      }
	}

};

int main()
{
	enter object;
	object.login();
	int o;
	int g;
	cout<<"PRESS ENTER TO START"<<endl;
	system("cls");
	cout<<"                                           WELCOME TO BOOK WORLD"<<endl;
	cout<<"                                           ......................."<<endl;
kj:	cout<<"==================MAIN MENU================"<<endl;
	cout<<"   01.ADD BOOK"<<endl;
	cout<<"   02.VIEW BOOK DATA"<<endl;
	cout<<"   03.UPDATE AND DELETE BOOK DATA"<<endl;
	cout<<"   04.EXIT"<<endl;
	cout<<"==========================================="<<endl;
	cout<<"SELECT YOUR CHOICE"<<endl;
	cin>>o;
  if(o==1)
	{
	   object.get();
	   goto kj;
	}
  else if(o==2)
	{
		object.in();
		goto kj;
	}
  else if(o==3)
	{   
	    object.update();
		goto kj;
	}
	 else if(o==4)
	{   
	    cout<<"THANKYOU FOR VISITING US"<<endl;
		exit(1);
	}
  else
    {
    	cout<<"INVALID INPUT"<<endl;
    }
	return 0;
}
