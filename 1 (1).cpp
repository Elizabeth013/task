#include <iostream>
#include <string>
using namespace std;

bool cmp(string s1, string s2) { //s1>s2 true
    
	bool p=false;
    
    if(s1==s2) p=false; else
    {
        if(s1.length()==s2.length())
        {
            for(int i=0;i<s1.length();i++) {
            	if(s1[i]>s2[i])
            	{
            	    p=true;
            	    break;
            	}else {
                	if(s1[i]<s2[i]) break;
				}
        	}
    	}
        else {
            int stat=0;
            for(int i=0;i<s1.length()&&i<s2.length();i++) {
            	if(s1[i]>s2[i])
            	{
                	stat=1;
                	p=true;
                	break;
            	} else {
                	if(s1[i]<s2[i]) {stat=1;break;}
            	}
        	}
            if(stat==0) {
            	if (s1.length()>s2.length()) p=true;
			}           
        }
    }
    return p;   
}

void sort(int n, string *s) { //bubblesort
    for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
        	if(!cmp(s[i],s[j]))
        	{
            	string tmp;
            	tmp=s[i];
            	s[i]=s[j];
            	s[j]=tmp;
        	}
    	}
    }
}

int main() {
    int n;
    do{
    cout<<"Enter n=";
    cin>>n;
    } while (n<=0);
    
    string *s=new string[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Name "<<i+1<<": "; 
		cin>>s[i];
    }
    
    sort(n,s);
    for(int i=0;i<n;i++)  cout<<s[i]<<endl;
    delete [] s;
    return 0;
}
