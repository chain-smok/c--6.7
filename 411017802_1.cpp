#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct company{
   int adminlevel;
   int license_number;
   int keyvalue;
};
int main()
{
   int n,i,j;
   struct company employee[100001];
   struct company person;
   cin>>n;
   for(i=0;i<n;i++)
{
    scanf("%d",&employee[i].adminlevel);   
    scanf("%d",&employee[i].license_number);
    employee[i].keyvalue=i+1;
}
    for(i=0;i<n;i++){
       for(j=i+1;j<n;j++){
          if(employee[i].adminlevel>employee[j].adminlevel){
               person=employee[i];
               employee[i]=employee[j];
               employee[j]=person;
          }
       }
    }

    for(i=0;i<n;i++){
       for(j=i+1;j<n;j++){
          if(employee[i].license_number>employee[j].license_number){
               person=employee[i];
               employee[i]=employee[j];
               employee[j]=person;
          }
       }
    }

    for(i=0;i<n;i++){
       cout<<employee[i].keyvalue<<" ";
    }
}