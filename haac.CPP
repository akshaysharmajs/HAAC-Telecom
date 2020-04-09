#include<iostream>
#include<conio.h>
#include<algorithm>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main();

int countrec=0;

void listrecords();

struct postpaid * addpo(struct postpaid * r2,string n,string p,string d,int v,string sp,float oa);
struct prepaid * addpr(struct prepaid * r1,string n,string p,string d,int v,string sp,float oa);

char get;

struct subscriber
{

string phonenumber;

string name;

string type;

vector<string> v;
}s;
struct prepaid
{
   string name;
   string phonenumber;
   string calls;
   int sms;
   string data;
   string special;
   int validity;
   float outstanding_amount;
   struct prepaid * left;
   struct prepaid * right;
};
struct postpaid
{

    string name;
   string phonenumber;
   string calls ;
   int sms;
   string data;
   string special;
   int validity;
   float outstanding_amount;
   struct postpaid *left;
   struct postpaid *right;
};
struct prepaid *newpr(string n,string p,string d,int v,string sp,float oa)
{
 struct prepaid * temp=new prepaid;
  temp->name=n;
        temp->phonenumber=p;
        temp->data=d;
        temp->special=sp;
        temp->validity=v;
        temp->outstanding_amount=oa;
        temp->left=temp->right=NULL;
        return temp;
}
struct postpaid *newpo(string n,string p,string d,int v,string sp,float oa)
{
 struct postpaid * temp=new postpaid;
  temp->name=n;
        temp->phonenumber=p;
        temp->data=d;
        temp->special=sp;
        temp->validity=v;
        temp->outstanding_amount=oa;
        temp->left=temp->right=NULL;
        return temp;
}
struct prepaid *r1=newpr("default","00","00",0,"00",0);
struct postpaid * r2=newpo("default","00","00",0,"00",0);

void displaypackages(struct prepaid * r1,struct postpaid * r2,string p,string n,string type)
{

    cout<<"\nPress enter to get the list of available packages ";
  getch();
   system("cls");
   if (type=="prepaid")
   {
       cout<<"\n\nselect your package by entering the number corresponds to it";
       cout<<"\n\n1 : Rs49=3GB/day 4g data for 1 day and unlimited local,STD and Roaming calls";
       cout<<"\n\n2 : Rs199=1.4 GB/day 4g data for 28 day and unlimited local,STD and Roaming calls and 100 SMS/day";
       cout<<"\n\n3 : Rs448=1.4 GB/day 4g data for 82 days and unlimited local,STD and Roaming calls and 100 SMS/day";
       cout<<"\n\n4 : Rs499=2 GB/day 4g data for 82 days and unlimited local,STD and Roaming calls and 100 SMS/day";
       cout<<"\n\n5 : Rs219=1.4 GB/day 4g data for 28 days and unlimited local,STD and Roaming calls and 100 SMS/day and  UNLIMITED Hello tunes.t&c apply";
        cout<<endl;
       int i;
       cin>>i;
       cin.clear();
       fflush(stdin);
       switch(i)
       {
       case 1:
      r1=addpr(r1,n,p,"3GB",1,"n/a",49);break;
       case 2:
       r1= addpr(r1,n,p,"1.4GB/day",28,"n/a",199);break;
       case 3:
        r1=addpr(r1,n,p,"1.4GB/day",82,"n/a",448);break;
       case 4:
       r1= addpr(r1,n,p,"2GB/day",82,"n/a",499);break;
       case 5:
        r1=addpr(r1,n,p,"1.4/day",28,"UNLIMITED HELLO TUNES",219);break;
       default:
        cout<<"\n\nIncorrect input \n\nplease select from given options";
        getch();
        }




   }
   else if (type=="postpaid")
   {
      cout<<"\n\nselect your package by entering the number corresponds to it";
       cout<<"\n\n 1 : Rs399=40GB 3g/4g data with rollover and unlumited local ,std and roaming calls and AMAZON PRIME one year subscription";
       cout<<"\n\n 2 : Rs499=75GB 3g/4g data with rollover and unlumited local ,std and roaming calls and AMAZON PRIME one year subscription and NETFLIX 3 months subscription";
       cout<<"\n\n 3 : Rs649=90GB 3g/4g data with rollover and unlumited local ,std and roaming calls and AMAZON PRIME one year subscription and NETFLIX 3 months subscription";
                 int i;
       cin>>i;
       switch(i)
       {
       case 1:
        r2=addpo(r2,n,p,"40GB",30,"AMAZON PRIME one year subscription",399);break;
       case 2:
        r2=addpo(r2,n,p,"75GB",30,"AMAZON PRIME one year subscription and NETFLIX 3 months subscription",499);break;
       case 3:
        r2=addpo(r2,n,p,"90GB",30,"AMAZON PRIME one year subscription and NETFLIX 3 months subscription",649);break;

       default:
        cout<<"\n\nIncorrect input \n\nplease select from given options";
        getch();

       }


   }
  }

struct prepaid* addpr(struct prepaid * r1,string n,string p,string d,int v,string sp,float oa )
{
    if(r1==NULL)
    {
      r1=newpr(n,p,d,v,sp,oa);

    }
     else if (r1->left ==NULL )
        r1->left=addpr(r1->left,n,p,d,v,sp,oa);
    else
       r1->right= addpr(r1->right,n,p,d,v,sp,oa);

 return r1;

}
struct postpaid * addpo(struct postpaid * r2,string n,string p,string d,int v,string sp,float oa )
{
    if(r2==NULL)
    {
      r2=newpo(n,p,d,v,sp,oa);

    }
      else if (r2->left ==NULL)
        r2->left=addpo(r2->left,n,p,d,v,sp,oa);

    else
       r2->right=addpo(r2->right,n,p,d,v,sp,oa);

    return r2;

}
void addrecords(struct prepaid * r1,struct postpaid * r2)
{

    fstream f;


  char test;

f.open("file.txt",std::ios_base::app);


  while(1)

  {

    system("cls");

    cout<<"\n Enter phone number:";

    cin>>s.phonenumber;
    if(s.v.empty())

        s.v.push_back(s.phonenumber);
    else
        {
           vector <string> ::iterator it;
           it = find (s.v.begin(), s.v.end(),s.phonenumber);
       if (it != s.v.end())

          {

           cout<<"\n-->Phone number already present in records ";
           cout<<"\n-->To see records press 'l'  or  to add phone number again press 'a' ";
           char ch;
           cin>>ch;
           switch(ch)
           {

           case 'l':
            listrecords();
           case 'a':
            continue;
           }
          }
          else
            s.v.push_back(s.phonenumber);



        }

    countrec++;

    cout<<"\n Enter name:";
cin.clear();
    fflush(stdin);

    cin>>s.name;

    cout<<"\n Enter the type of plan [prepaid/postpaid]:";
cin.clear();
fflush(stdin);
    cin>>s.type;


    displaypackages(r1,r2,s.phonenumber,s.name,s.type);

    f<<s.phonenumber<<"\t\t"<<s.name<<"\t\t"<<s.type<<endl;


    fflush(stdin);

    system("cls");

    cout<<"1 record successfully added";

    cout<<"\n Press esc key to exit, any other key to add other record:";

    test=getche();

    if(test==27)

      break;

  }

  f.close();

}

void listrecords()
{
  fstream f;

  int i;


  f.open("file.txt");

 if(!f)
{

    exit(0);
}

  system("cls");

  cout<<"Phone Number\t\tUser Name\t\tPlan\n";

  for(i=0;i<79;i++)

    cout<<"-";
  while(f>>s.phonenumber>>s.name>>s.type)

{
  cout<<"\n"<<s.phonenumber<<"\t\t"<<s.name<<"\t\t\t"<<s.type<<endl;
}

  cout<<"\n";

  for(i=0;i<79;i++)

    cout<<"-";

f.close();

getch();

}

void deleterecords()

{

  fstream f;

  ofstream t;

  int i=1;

 string phonenumber;

  t.open("temp.txt",std::ofstream::trunc);
f.open("file.txt");



  system("cls");


  cout<<"Enter the phone number to be deleted from the Database";

  fflush(stdin);


  cin>>phonenumber;




  while(f>>s.phonenumber>>s.name>>s.type)

  {


    if(s.phonenumber==phonenumber)

    {
        i=0;

    vector <string> ::iterator it;

    it = find (s.v.begin(), s.v.end(),s.phonenumber);

       s.v.erase(it);

        if(countrec>1)
    {
    continue;
    }
   else if(countrec==1)
{
    countrec=0;

  cout<<"The Number"<< phonenumber <<"Successfully Deleted!!!!";

    Sleep(2000);
}
}

    else

    t<<s.phonenumber<<"\t\t"<<s.name<<"\t\t"<<s.type<<endl;

  }
  if(i==1)

  {       system("cls");

    cout<<"Phone number "<<phonenumber<< "not found";

     f.close();

    t.close();
    remove("file.txt");

    rename("temp.txt","file.txt");

    getch();

   cout<<"PLEASE SEE THE RECORDS AGAIN\n\n\n\n";

    listrecords();

  }

 else{ countrec--;
        f.close();

  t.close();

  remove("file.txt");

  rename("temp.txt","file.txt");

  system("cls");

  cout<<"The Number"<< phonenumber <<"Successfully Deleted!!!!";

 }
  getch();

}

void searchrecords()

{

  fstream f;

  string phonenumber;

  int flag=1;

f.open("file.txt");

  fflush(stdin);

  system("cls");

cout<<"Enter Phone Number to search in our database";

  cin>> phonenumber;

   while(f>>s.phonenumber>>s.name>>s.type)

  {
  cin.clear();

    if(s.phonenumber==phonenumber)

    {  system("cls");

      cout<<" Record Found ";

      cout<<"\n\nPhonenumber:"<<s.phonenumber<<"\nName:"<< s.name<<"\nPlamn:"<<s.type<<"\n";

      flag=0;

      break;

    }

    else if(flag==1)

    {  system("cls");

      cout<<"Requested Phone Number Not found in our database";

    }

  }

  getch();

  f.close();

}

void modifyrecords()

{
  fstream f;

  ofstream t;

 string  phonenumber;

 t.open("temp.txt",std::ofstream::trunc);

  f.open("file.txt");

  system("cls");

  cout<<"Enter phone number of the subscriber to modify:";

  cin>>phonenumber;

  fflush(stdin);

while( f>>s.phonenumber>>s.name>>s.type)

  {
    if(s.phonenumber==phonenumber)

    {   string p;
    p=s.phonenumber;
while(1)
    {

     system("cls");

      cout<<"\n Enter phone number:";

      cin>>s.phonenumber;
       if(s.v.empty())

       {

        s.v.push_back(s.phonenumber);
        break;}
    else
        {
           vector <string> ::iterator it;
           it = find (s.v.begin(), s.v.end(),s.phonenumber);
       if (it != s.v.end())

          {

           cout<<"\n-->Phone number already present in records ";
           cout<<"\n-->To see records press 'l'  or  to modify phone number again press 'm' ";
           char ch;
           cin>>ch;
           switch(ch)
           {

           case 'l':
            listrecords();
           case 'm':
            continue;
           }
          }
          else
           {

            s.v.push_back(s.phonenumber);
            break;}


        }
    }

      cout<<"\n Enter name: ";

      fflush(stdin);

    cin>>s.name;

      cout<<"\n Enter the type of plan [prepaid/postpaid]:";
      cin>>s.type;

         t<<s.phonenumber<<"\t\t"<<s.name<<"\t\t"<<s.type<<endl;
    }
    else
         t<<s.phonenumber<<"\t\t"<<s.name<<"\t\t"<<s.type<<endl;
  }

  f.close();

  t.close();
      remove("file.txt");

  rename("temp.txt","file.txt");

  system("cls");

  cout<<"The Number"<< phonenumber <<"Successfully Modified!!!!";
   getch();

   }
struct prepaid * prpay(prepaid * r1,string p,float amt)
{
    if(r1==NULL)
        return r1;
    queue<prepaid *> q;
    q.push(r1);
    int i=0;
    while(q.empty()==false)
    {


        prepaid * node=q.front();
        if(node->phonenumber==p )
        { i=1;
           node->outstanding_amount=node->outstanding_amount-amt;
            return node;
        }
        q.pop();
        if(node->left !=NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
    }
    if(i==0)
        cout<<"number not found ";
}
struct postpaid* popay(postpaid * r2,string p,float amt)
{int i=0;
    if(r2==NULL)
        return r2;
    queue<postpaid *> q;
    q.push(r2);

    while(q.empty()==false)
    {


        postpaid * node=q.front();
        if(node->phonenumber==p )
        { i=1;
              node->outstanding_amount=node->outstanding_amount-amt;

            return node;
        }
        q.pop();
        if(node->left !=NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
    }
    if(i==0)
        cout<<"number not found ";
}

void payment(struct prepaid * r1,struct postpaid * r2)

{

  fstream f;

 string phonenumber;

  float amt;

  int i;

  f.open("file.txt");

  system("cls");

    string p;

    cout<<"\nEnter your phone number for payment\n";

    cin>>phonenumber;

  cout<<"Enter \n\n'pr' : if you are a prepaid user\n\n'po' : if you are a postpaid user ";

   cin>>p;



  while(f>>s.phonenumber>>s.name>>s.type)

  {

    if(s.phonenumber==phonenumber)

    {

      system("cls");

      cout<<"\n Phone No.:"<<s.phonenumber;

      cout<<"\n Name:"<<s.name;

      cout<<"\n Current plan:"<<s.type;

      cout<<"\n";


      for(i=0;i<79;i++)

        cout<<"-";

      cout<<"\n\nEnter amount of payment: ";

         fflush(stdin);

      cin>>amt;

   if(p=="pr")
   {
       prpay(r1,phonenumber,amt);
    }
   else if(p=="po")
    {
        popay(r2,phonenumber,amt);
    }



    }


system("cls");

  cout<<"THANK YOU "<<s.name <<" FOR YOUR TIMELY PAYMENTS";
  Sleep(2000);
    break;

    }



  system("cls");

  cout<<"THANK YOU "<<s.name <<" FOR YOUR TIMELY PAYMENTS";

  f.close();

}
void prsearch(prepaid * r1,string p)
{
    if(r1==NULL)
        return;
    queue<prepaid *> q;
    q.push(r1);
    int i=0;
    while(q.empty()==false)
    {


        prepaid * node=q.front();
        if(node->phonenumber==p )
        { i=1;
          cout<<"Record found";
          Sleep(1000);
          system("cls");
          cout<<"YOUR ACCOUNT INFO \n-----------------";
            cout<<"\n\nPhone number : "<<node->phonenumber;
            cout<<"\nName : "<<node->name;
            cout<<"\nBalance Calls : "<<"unlimited calls";
            cout<<"\nBalance SMS : "<<"100";
            cout<<"\nData balance : "<<node->data;
            cout<<"\nSpecial subscription : "<<node->special;
            cout<<"\nValidity of pack : "<<node->validity<<" days";
            cout<<"\nYour outstanding amount : Rs"<<node->outstanding_amount;
            getch();
            return;
        }
        q.pop();
        if(node->left !=NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
    }
    if(i==0)
        cout<<"Record not found ";
}
void posearch(postpaid * r2,string p)
{int i=0;
    if(r2==NULL)
        return;
    queue<postpaid *> q;
    q.push(r2);

    while(q.empty()==false)
    {


        postpaid * node=q.front();
        if(node->phonenumber==p )
        { i=1;
          cout<<"Record found";
          Sleep(1000);
          system("cls");
          cout<<"YOUR ACCOUNT INFO \n-----------------";
            cout<<"\n\nPhone number : "<<node->phonenumber;
            cout<<"\nName : "<<node->name;
            cout<<"\nBalance Calls : "<<"unlimited calls";
            cout<<"\nBalance SMS : "<<"100";
            cout<<"\nData balance : "<<node->data;
            cout<<"\nSpecial subscription : "<<node->special;
            cout<<"\nValidity of pack : "<<node->validity<<" days";
            cout<<"\nYour outstanding amount : Rs"<<node->outstanding_amount;
            getch();
            return;
        }
        q.pop();
        if(node->left !=NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
    }
    if(i==0)
        cout<<"Record not found ";
}
void displayac(struct prepaid * r1,struct postpaid * r2)
{
   system("cls");
    string ph,p;
    cout<<"\nEnter your phone number\n";
    cin>>ph;
  cout<<"Enter \n\n'pr' : if you are a prepaid user\n\n'po' : if you are a postpaid user ";
   cin>>p;
   system("cls");
   if(p=="pr")
    prsearch(r1,ph);
   else if(p=="po")
    posearch(r2,ph);
}
int main()

{
    int password;

 string phonenumber;

  char choice;

  system("cls");
   s.v.clear();
  fstream f("file.txt");
  while(f>>s.phonenumber>>s.name>>s.type)
    s.v.push_back(s.phonenumber);

  f.close();

  cout<<"\n\n\n\n\n\n\n\n\n*************************************";

  cout<<"\n--- WELCOME TO THE HAAC TELECOM ---";

  cout<<"\n************************************";

  Sleep(2000);
  cout<<"\n\n\n\n\n\npress enter to continue..";

  getch();

    system("cls");

  while (1)

  {

    system("cls");

    cout<<"\n enter\n A : for adding new records.\n L : for list of records";

    cout<<"\n M : for modifying records.\n P : for payment";

    cout<<"\n S : for searching records.";

    cout<<"\n I : for Account Info.";

    cout<<"\n D : for deleting records.\n E : for exit\n";

    choice=getche();

    choice=toupper(choice);

    switch(choice)

    {

      case 'P':

        payment(r1,r2);break;

      case 'A':

        addrecords(r1,r2);break;

      case 'L':

        listrecords();break;

      case 'M':

        modifyrecords();break;

      case 'S':

        searchrecords();break;

      case 'I':

        displayac(r1,r2);break;

      case 'D':

        deleterecords();break;

      case 'E':

        system("cls");

        cout<<"THANK YOU";

        cout<<"\n\nFOR USING OUR SERVICE";

        Sleep(2000);

        exit(0);

        break;

      default:

        system("cls");

        cout<<"Incorrect Input";

        cout<<"\nAny key to continue";

        getch();

    }

  }
return 0;
}
