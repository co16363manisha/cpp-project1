#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

struct student
{
 char id[7] ;
 int a,b,c;

};
void input()
{
fstream fp;
fp.open("studet.txt",ios::app);
struct student s[3];

for(int i=0;i<3;i++)
{
  cout<<"enter id::"<<endl;
  cin>>s[i].id;
  cout<<"enter dob::"<<endl;
  cin>>s[i].a>>s[i].b>>s[i].c;

}
fp.close();
}
void display()
{ struct student s[3];
 fstream fp;
 fp.open("student.txt",ios::in);
 for(int i=0;i<3; i++)

 {
     fp.read((char*) &s[i], sizeof(s[i]));
  cout<<"id is "<<s[i].id<<endl;
  cout<<" dob is"<<s[i].a<<"/"<<s[i].b<<"/"<<s[i].c<<endl;

 }
 fp.close();
}

void soo()
{
    struct student s[3], r[3], t;
    fstream fp;
    fp.open("student.txt", ios::in);
    for(int i =0; i<3 ;i++)
    {   getline(fp,r[i].id);
        getline(fp,r[i].a);
        getline(fp,r[i].b);
        getline(fp,r[i].c);
        cout<<r[i].id<<endl;
        cout<<r[i].a<<endl;
    }
     /*int j;
    for(int i=1; i<3; i++)
    { for(j=0; j<2; j++)
       {
           int k=0;
          k=strcmp(r[j].id, r[j+1].id);
          if(k>0)

           {
            t= r[j];
            r[j]= r[j+1];
            r[j+1]= t;

          }
      }
    }
      for(int k=0; k<3;k++)
      { cout<<"id : "<<r[k].id<<endl;
        cout<<" \t dob :"<<r[k].a<<"/"<<r[k].b<<"/"<<s[k].c<<endl;
     }*/
     fp.close();
}

int main()
{
  input();
  display();
  soo();
}
