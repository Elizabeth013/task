#include <iostream>
using namespace std;

void swap(int &a, int &b, int &c) {
    int a1=a, b1=b, c1=c;
   // if(a>=b&&b>=c) nothing changes
   if(a>=c&&c>=b) {
   b=c1;
   c=b1;
   } else
   if(b>=a&&a>=c) {
   a=b1; 
   b=a1;
   } else
   if(b>=c&&c>=a) {
   a=b1;
   b=c1;
   c=a1;
   } else
   if(c>=a&&a>=b) {
   a=c1;
   b=a1;
   c=b1;
   } else
   if(c>=b&&b>=a) {
   a=c1;
   c=a1;
   }
}

int main() {
    int a,b,c;
    cout<<"Enter a, b, c: ";
    cin>>a>>b>>c;
    int *p1=&a,*p2=&b,*p3=&c;
    swap(*p1,*p2,*p3);
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}
