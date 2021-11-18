#include <iostream>
using namespace std;

int fun(int *n) {
	int val;
	int a1, a2, a3, a4, n1=*n;
	a1 = (n1<<24)>>24;
	a2 = (n1<<16)>>24;
	a3 = (n1<<8)>>24;
	a4 = n1>>24;
	cout<<"0 byte: "<<a1<<endl<<"1 byte: "<<a2<<endl<<"2 byte: "<<a3<<endl<<"3 byte: "<<a4<<endl;
	val=(a3<<24)+(a2<<16)+(a1<<8)+a4;
    return val;
}

int main() {
   int n; 
   cout<<"Enter n=";
   cin>>n;
   cout<<fun(&n)<<endl;
   return 0;
}
