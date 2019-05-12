#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
void main()
{
 clrscr();
 char a[15],b[4];
 int c,n;
 cout<<"Enter regn number:";
 gets(a);
 cout<<"\nEnter n:";
 cin>>n;

 for(int i=8;i<=11;i++)
 {
  b[i-8]=a[i];
 }
 b[4]='\0';
 c=atoi(b);

 if(c+n<=9999)
 {
  for(int i=0;i<=7;i++)
  {
   cout<<a[i];
  }
  cout<<c+n;
 }

 else if(c+n>9999&&a[6]!='Z')
 {
  for(int i=0;i<=5;i++)
  {
   cout<<a[i];
  }
  cout<<++a[6]<<" ";
  if((c+n-10000)<10)
  {
   cout<<"000"<<c+n-10000;
  }
  else if((c+n-10000)<100&&(c+n-10000)>=10)
  {
   cout<<"00"<<c+n-10000;
  }
  else if((c+n-10000)<1000&&(c+n-10000)>=100)
  {
   cout<<"0"<<c+n-10000;
  }
  else
  {
   cout<<c+n-10000;
  }
 }

 else if(c+n>9999&&a[6]=='Z')
 {
  for(int i=0;i<=4;i++)
  {
   cout<<a[i];
  }
  cout<<++a[5]<<'A'<<" ";
  if((c+n-10000)<10)
  {
   cout<<"000"<<c+n-10000;
  }
  else if((c+n-10000)<100&&(c+n-10000)>=10)
  {
   cout<<"00"<<c+n-10000;
  }
  else if((c+n-10000)<1000&&(c+n-10000)>=100)
  {
   cout<<"0"<<c+n-10000;
  }
  else
  {
   cout<<c+n-10000;
  }
 }

 else if(c+n>9999&&a[5]=='Z'&&a[6]=='Z')
 {
  cout<<"\nInvalid Number";
 }
 getch();
}