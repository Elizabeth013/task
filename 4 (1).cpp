#include <iostream>
using namespace std;

void fun(int *n, int *k) {
    (*k)++;
    if(*k==1) cout<<"Hello world! I was born !!!"<<endl;
    else
    if(*k<=*n) cout<<"I'm alive"<<endl;
    else
    cout<<"Bye, bye, dear, I'm already asleep..."<<endl;
    
}

int main() {
   int *k=new int ;
   *k=0;
   int *n=new int;
   cout<<"Life duration: ";
   cin>>*n;
   int *p=new int;
   cout<<"How many function calls?";
   cin>>*p;
   for(int i=0;i<*p;i++) fun(n,k);
   delete p;
   delete k;
   delete n;
   return 0;
}
