#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<process.h>
class lib
{
	public:
	char bname[100],aname[100],sc1[50],sc[50];
	int q,B,p;
	lib()
	{
		strcpy(bname,"NO BOOK NAME");
		strcpy(aname,"NO AUTHOR NAME");
		strcpy(sc,"NO BOOK ID");
		strcpy(sc1,"NO PUBLICATION NAME");
		q=0;
		B=0;
		p=0;
	}
	void pass();
	void get();
	void getdata();
	void student();
	void librarian();
	void issue();
	void booklist(int);
	int branch(int);
	void add();
	void see(int);
	void check(char[],int,int);
	void show(int);
	void issue_l();
	void issue_s();
};
void lib::get()
{
	int i;
	start:
	cout<<"\t --------- LIBRARY MANAGEMENT SYSTEM --------- \n ";
	cout<<"\n\t Please Choose Any Option To Login \n";
	cout<<"\n\t 1.Student \n\t 2.Librarian \n\t 3.Close Application \n ";
	cout<<"\n\t Enter Your Choice : ";
	cin>>i;
	if(i==1)
	{
		clrscr();
		student();
	}
	else if(i==2)
	pass();
	else if(i==3)
	exit(0);
	else
	{
		cout<<"Wrong Input.....\n Try again \n ";
		cout<<"Press any key to continue .......\n";
		getch();
		clrscr();
		goto start;
	}
}
void lib::pass()
{
	char pwd[9];
	cout<<"\nEnter librarian password\n";
	char ch;
	int i=0;
	while(1)
	{
		ch=getch();
		if(ch==13)
		break;
		pwd[i++]=ch;
		cout<<'*';
	}
	pwd[i]='\0';
	if(strcmp(pwd,"admin")==0)
	{
		cout<<"\n\n\tAccess enabled for LIBRARIAN.\n";
		cout<<"\nPress any key to continue.";
		getch();
		clrscr();
		librarian();
	}
	else
	{
		cout<<"\n\n\t\tIncorrect password. Press any key to continue.";
		getch();
		clrscr();
		get();
	}
}
void lib::add()
{
    char ch,st1[100];
    int b;
    clrscr();
    B=branch(2);
    clrscr();
    getdata();
    ofstream fout("Booksdata.txt",ios::app|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
    cout<<"\n\t Book added Successfully.\n";
    getch();
    clrscr();
    librarian();
}
void lib::see(int x)
  {
      int i,b,cont=0;
      char ch[100];
      clrscr();
      b=branch(x);
      ifstream fin("Booksdata.txt",ios::binary);
	if(!fin)
	{
	    cout<<"\n\t\tFile Not Found.\n";
	    cout<<"\n\t\t->Press any key to continue.....";
	    getch();
	    clrscr();
	    if(x==1)
	    student();
	    else
	    librarian();
	}
	clrscr();
	fin.read((char*)this,sizeof(*this));
	cout<<"\n\t\tEnter Book's Name : ";
	cin>>ch;
	clrscr();
	while(!fin.eof())
	{
		for(i=0;b==B&&q!=0&&bname[i]!='\0'&&ch[i]!='\0'&&(ch[i]==bname[i]||ch[i]==bname[i]+32);i++);
		if(bname[i]=='\0'&&ch[i]=='\0')
		{
			cout<<"\n\t\tBook Found :-\n";
			show(x);
			cont++;
			getch();
			clrscr();
			if(x==1)
			student();
			else
			librarian();
			break;
		}
		fin.read((char*)this,sizeof(*this));
	}
}
void lib::student()
{
	int i;
	cout<<"\n\t -------- WELCOME STUDENT --------\n";
	cout<<"\n\t Please Choose One Option :\n ";
	cout<<"\n\t 1.View Booklist \n\t 2.Search for a Book \n\t 3.Issue/Return Book \n\t 4.Go to Main Menu \n\t 5.To Exit The Application \n";
	cout<<"\n\t Enter Your Choice : ";
	cin>>i;
	if(i==1)
	booklist(1);
	else if(i==2)
	see(1);
	else if(i==3)
	issue();
	else if(i==4)
	{
		clrscr();
		get();
	}
	else if(i==5)
	exit(0);
	else
	{
		cout<<"\n\t WRONG INPUT ";
		getch();
		clrscr();
		student();
	}
}
void lib::issue_l()
{
	int i,b;
	ifstream fin("student.txt",ios::binary);
	clrscr();
	cout<<"\n\t\t->The Details are :-\n";
	fin.read((char*)this,sizeof(*this));
	i=0;
	while(!fin.eof())
	{
		i++;
		cout<<"\n\t\t---------- "<<i<<". ---------- \n";
		cout<<"\n\t\tStudent Name : "<<aname<<"\n\t\t"<<"Student's ID : "<<sc1<<"\n\t\t"<<"Book Name : "<<bname<<"\n\t\t"<<"Book's ID : "<<sc<<"\n\t\t";
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
	getch();
	clrscr();
	librarian();
}
void lib::issue_s()
{
	char st[50],st1[50];
	int i;
	int cont=0;
	clrscr();
	cout<<"\n\t\t->Please Enter Details :-\n";
	cout<<"\n\n\t\tEnter Student Name : ";
	cin>>st;
	cout<<"\n\n\t\tEnter Student's ID : ";
	cin>>st1;
	clrscr();
	ifstream fin("student.txt",ios::binary);
	fin.read((char*)this,sizeof(*this));
	cont=0;
	while(!fin.eof())
	{
	      for(i=0;sc1[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc1[i];i++);
	      if(sc1[i]=='\0'&&st1[i]=='\0')
	      {
		  cont++;
		  if(cont==1)
		  {
		      cout<<"\n\t\t->The Details are :-\n";
		      cout<<"\n\t\tStudent Name : "<<aname;
		      cout<<"\n\t\tStudent's ID : "<<sc1;
		  }
		  cout<<"\n\n\t\t--------> "<<cont<<". Book details <------\n";
		  cout<<"\n\t\tBook Name : "<<bname;
		  cout<<"\n\t\tBook's ID : "<<sc;
		  }
		      fin.read((char*)this,sizeof(*this));

	}
	fin.close();
	if(cont==0)
	cout<<"\n\t\tNo record found.";
	getch();
	clrscr();
	librarian();
}
void lib::librarian()
{
	int i;
	cout<<"\n\t -------> WELCOME LIBRARIAN <------- \n";
	cout<<"\n\t Please Choose One Option :\n";
	cout<<"\n\t 1.View Booklist \n\t 2.Search for a Book \n\t 3.Add a book \n\t 4.Issued book \n\t 5. Student who have issued book \n\t 6.Go to main menu \n\t 7.Close Application \n";
	cout<<"\n\t Enter Your Choice : ";
	cin>>i;
	switch(i)
	{
		case 1: booklist(2);
			break;
		case 2: see(2);
			break;
		case 3: add();
			break;
		case 4: issue_l();
			break;
		case 5: issue_s();
			break;
		case 6: clrscr();
			get();
			break;
		case 7: exit(0);
			break;
		default: cout<<"\n\t WRONG INPUT \n";
			getch();
			clrscr();
			librarian();
	}
}
void lib::getdata()
{
	int i;
	cout<<"\n\t Enter the details :: \n";
	cout<<"\n\t Enter the bookname :\n";
	cin>>bname;
	cout<<"\n\t Enter Author's name :\n";
	gets(aname);
	cout<<"\n\t Enter Publication name : \n";
	gets(sc1);
	cout<<"\n\t Enter Book's ID : \n";
	cin>>sc;
	cout<<"\n\t Enter Book's Price : \n";
	cin>>p;
	cout<<"\n\t Enter Book's Quantity : \n";
	cin>>q;
}
int lib::branch(int i)
{
      menu:
      cout<<"\n\t\t>>Please Choose one Branch :-\n";
      cout<<"\n\t\t1.COMPUTER  SCIENCE\n\n\t\t2.PHYSICS\n\n\t\t3.CHEMISTRY\n\n\t\t4.MATH\n\n\t\t5.ENGLISH\n\n\t\t6.IIT PREPARATION\n\n\t\t";
      cout<<"\n\t\tEnter your choice : ";
      cin>>i;
      switch(i)
      {
	  case 1: return 1;
	  case 2: return 2;
	  case 3: return 3;
	  case 4: return 4;
	  case 5: return 5;
	  case 6: return 6;
	  default : cout<<"\n\t\tPlease enter correct option :(";
		    getch();
		    goto menu;
      }
}
void lib::booklist(int i)
{
	int b,r=0;
	clrscr();
	b=branch(i);
	clrscr();
	ifstream fin("Booksdata.txt",ios::binary);
	if(!fin)
	cout<<"\n\t\tFile Not Found.";
	else
	{
		cout<<"\n\t    ------------ Book List ------------ \n\n";
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
		    if(b==B)
		    {
			if(q==0 && i==1)
			{
			}
			else
			   {
				r++;
				cout<<"\n\t\t---------> "<<r<<".<--------- \n";
				show(i);
			    }
		    }
		    fin.read((char*)this,sizeof(*this));
		}
	}
	cout<<"\n\t\tPress any key to continue.....";
	getch();
	clrscr();
	if(i==1)
	student();
	else
	librarian();
}
void lib::issue()
{
	char st[50],st1[20];
	int b,i,j,cont=0;
	clrscr();
	cout<<"\n\t\t->Please Choose one option :-\n";
	cout<<"\n\t\t1.Issue Book\n\n\t\t2.Return Book\n\n\t\t3.Go back to menu\n\n\t\tEnter Your Choice : ";
	cin>>i;
	if(i==1)
	{
		clrscr();
		b=branch(2);
		clrscr();
		cout<<"\n\t\t->Please Enter Details :-\n";
		cout<<"\n\t\tEnter Book Name : ";
		cin>>bname;
		cout<<"\n\t\tEnter Book's ID : ";
		cin>>sc;
		check(sc,b,1);
		cout<<"\n\t\tEnter Student Name : ";
		cin>>aname;
		cout<<"\n\t\tEnter Student's ID : ";
		cin>>sc1;
		ofstream fout("student.txt",ios::binary|ios::app);
		fout.write((char*)this,sizeof(*this));
		fout.close();
		cout<<"\n\n\t\tIssue Successfully.\n";
	}
	else if(i==2)
	{
		clrscr();
		b=branch(2);
		clrscr();
		cout<<"\n\t\t->Please Enter Details :-\n";
		cout<<"\n\t\tEnter Book's ID : ";
		cin>>st1;
		check(st1,b,2);
		cout<<"\n\n\t\tEnter Student's ID : ";
		cin>>st;
		ofstream fout("temp.txt",ios::app|ios::binary);
		ifstream fin("student.txt",ios::binary);
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			for(i=0;sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
			for(j=0;sc1[j]!='\0'&&st[j]!='\0'&&st[j]==sc1[j];j++);
			if(sc[i]=='\0'&&sc1[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0'&&cont==0)
			{
				cont++;
				fin.read((char*)this,sizeof(*this));
				cout<<"\n\t\tReturned successfully.";
			}
			else
			{
				fout.write((char*)this,sizeof(*this));
				fin.read((char*)this,sizeof(*this));
			}
		}
		fin.close();
		fout.close();
		getch();
		remove("student.txt");
		rename("temp.txt","student.txt");
	}
	else if(i==3)
	{
		clrscr();
		student();
	}
	else
	cout<<"\n\t\tWrong Input.\n";
	cout<<"\n\n\t\tPress any key to continue.....";
	getch();
	clrscr();
	student();
}
void lib::check(char st[],int b,int x)
{
    int i,cont=0;
    fstream fin("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
    fin.seekg(0);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
	for(i=0;b==B&&sc[i]!='\0'&&st[i]!='\0'&&st[i]==sc[i];i++);
	if(sc[i]=='\0'&&st[i]=='\0')
	{
	    cont++;
	    if(x==1)
	    {
		if(q==0)
			{
				cout<<"\n\t\t Book not available ";
				getch();
				clrscr();
				get();
			}
		else
		q--;
	    }
	    else
	    {
		q++;
	    }
	    fin.seekp(fin.tellp()-sizeof(*this));
	    fin.write((char*)this,sizeof(*this));
	    break;
	}
	fin.read((char*)this,sizeof(*this));
    }
    if(cont==0)
    {
	cout<<"\n\t\tBook not found.\n";
	cout<<"\n\n\t\tPress any key to continue.....";
	getch();
	clrscr();
	issue();
    }
    fin.close();
}

void lib::show(int i)
{
    cout<<"\n\t\tBook Name : "<<bname;
    cout<<"\n\t\tBook's Author Name : "<<aname;
    cout<<"\n\t\tBook's ID : "<<sc;
    cout<<"\n\t\tBook's Publication : "<<sc1;
    if(i==2)
    {
	cout<<"\n\t\tBook's Price : "<<p;
	cout<<"\n\t\tBook's Quantity : "<<q;
    }
}
void main()
{
	clrscr();
	lib obj;
	obj.get();
	getch();
}

