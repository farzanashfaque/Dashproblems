#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<io.h>
#include<process.h>

int deno[3];

void supplier()
 {
  ofstream fout;
  fout.open("Supply1",ios::out);
  int price;
  char ch,name[20];
  cout<<"Do you want to add a product?(Y/N)";
  cin>>ch;
  do
  {
   cout<<"\nEnter product name:";
   gets(name);
   cout<<"\nEnter price:";
   cin>>price;
   fout<<name<<"  "<<price;
   cout<<"\nDo you want to add another product?(Y/N)";
   cin>>ch;
  }
  while(ch=='Y');
  fout.close();
  exit(0);
 }

 void customer()
 {
  deno[0]=0;
  deno[1]=0;
  deno[2]=0;
  deno[3]=0;
  char name[10];
  int price,c;
  char ch;
  ifstream fin;
  fin.open("Supply1",ios::in,ios::beg);
  int i=1;
  while(!fin.eof())
  {
   fin>>name>>price;
   cout<<"\n"<<i<<"."<<name<<"  Price:"<<price;
   i++;
  }
  fin.close();
  cout<<"\nAccepted denominations: 1/5/10/25";
  do
  {
   cout<<"\nPlease insert money:\t";
   cin>>c;
   if(c==1)
    ++deno[0];
   else if(c==5)
    ++deno[1];
   else if(c==10)
    ++deno[2];
   else if(c==25)
    ++deno[3];
   cout<<"\nDo you want to add more money?(Y/N)";
   cin>>ch;
  }
  while(ch=='Y');
  cout<<"\n\nPlease select:";
 }



class vendingmachine
{
 public:
 void choose()
 {
  int choice;
  cout<<"\nPlease select your preferred choice:"
      <<"\n1.Customer"
      <<"\n2.Supplier\n";
  cin>>choice;
  if(choice==1)
   {
    customer();
   }
  else
   {
    supplier();
   }
 }
};

class money:public vendingmachine
{
 public:
 int total,change,price;
 char product[20];

 void calctotal()
 {
  total=0;
  total=deno[0]+(5*deno[1])+(10*deno[2])+(25*deno[3]);
 }

 void dispense()
 {
  int choice;
  cin>>choice;
  ifstream fin;
  fin.open("Supply1",ios::in,ios::beg);
  for(int i=1;i<=choice;i++)
  {
   fin>>product;
   fin>>price;
  }
  if(price>total)
  {
   int ch;
   cout<<"\nAmount insufficient"
       <<"\n1.Add more money"
       <<"\n2.Collect change"
       <<"\nPlease select";
   cin>>ch;
   if(ch==1)
    customer();
   else
    retchange();
  }
  else
  {
   cout<<"\nPlease collect "<<product;
   if((total-price)>0)
    retchange();
  }
  fin.close();
 }

 void retchange()
 {
  change=total-price;
  cout<<"\n\nPlease collect change of "<<change;
 }
};

void main()
{
 clrscr();
 cout<<"Welcome to XYZ vending machine";
 vendingmachine v;
 v.choose();
 money m;
 m.dispense();
 cout<<"\n\n"<<deno[0]<<"\t"<<deno[1]<<"\t"<<deno[2]<<"\t"<<deno[3];
 cout<<"\n"<<m.total<<"\n"<<m.price;
 getch();
}

