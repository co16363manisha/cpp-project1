#include <iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int marks_credit(int &);
int practical_credit(int &);
int main()
{int a; char str[20][20];char ch;int marks;int arr;int arrays;int pum=0;int t=0;int sum;int cre;int credit;int r;float s;float o=0.0;
  cout<<"we are going to calculate your cgpa so enter your details correctly "<<endl<<endl;
  cout<<"do you want to calculate SGPA or CGPA"<<endl<<"enter 1 for SGPA"<<endl<<"enter 2 for CGPA"<<endl;
  r=getche();
  if (r=='1')
  {
  cout<<"enter the no. of subjects"<<endl;
  cin>>a;
  for (int i=0;i<a;i++)
{
cout<<endl<<"enter the name of the subject"<<endl;cin>>str[i];cout<<"enter the marks" <<endl<<"marks=  "; cin>>marks;cout<<" enter the credits"<<endl;cin>>arr;
  arr;sum=marks_credit(marks );
 pum=pum+ (sum*arr);
 if(sum>=1)
{

 t=t+arr;}
 else
  {

    t=t+0;}
 cout<<"do it has a prctical too  y/n";
 ch=getche();
 int p=0;
if (ch=='y'){
cout<<endl<<"enter the marks in practical" << endl;
cin>>  arrays;
 cre= practical_credit(arrays);
 credit=(cre*2);
pum=pum+credit;
if (cre>=1)
 {t=t+2;}
else
{t=t+0;}


}}

s=(float)pum/t;cout<<"sum is"<<pum<<endl<<"t is"<<endl<<t<<endl<< "sgpa is"<<s;
}
else
    {
 for(int  i=0;i<=1;i++)
 { cout<<"enter the no. of subjects"<<endl;
  cin>>a;
    for (int i=0;i<a;i++)
{
cout<<endl<<"enter the name of the subject, marks  and credits"<<endl;
 cin>>str[i]>>  marks>> arr;sum=marks_credit(marks );
 pum=pum+ (sum*arr);
 if(sum>=1)
{

 t=t+arr;}
 else
  {

    t=t+0;}
 cout<<"do it has a prctical too  y/n";
 ch=getche();
 int p=0;
if (ch=='y'){
cout<<endl<<"enter the marks in practical" << endl;
cin>>  arrays;
 cre= practical_credit(arrays);
 credit=(cre*2);
pum=pum+credit;
if (cre>=1)
 {t=t+2;}
else
{t=t+0;}


}
s=(float)pum/t;



}o=o+s;

}}

 cout<<endl<<"CGPA  is "<<o/2;
return 0;
}
int marks_credit(int & marks)
{ int a;
    if (marks>=90)
    {
    a=10;
    }
 else if (marks>=80)
        {
        a=9;
        }
 else if(marks>=70 )
  {
  a=8;
     }
 else if (marks>=60)
 { a=7;   }
 else if (marks>=50)
 {  a=6; }
 else if (marks>=45)
 { a=5;  }
 else if (marks>=40)
 {a=4;}
 else {marks=0;}
return (a);
 }
 int practical_credit(int & arrays)
 { int b;
    if (arrays>=45)
    {
    b=10;
    }
 else if (arrays>=40)
        {
        b=9;
        }
 else if(arrays>=35 )
  {
  b=8;
     }
 else if (arrays>=30)
 { b=7;   }
 else if (arrays>=25)
 {  b=6; }
 else if (arrays>=20)
 { b=5;  }
 else if (arrays>=15)
 {b=4;}
 else {arrays=0;}
return (b);




 }

