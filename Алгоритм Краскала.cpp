#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int a,b;
	Edge() {}
	Edge (int x, int y) {
	a=x;
	b=y;
	}
};
int main() {
	int n,m;
	cin>>n>>m;
	vector <Edge> graph (m);
	vector <Edge> tree;
	vector <int> var (n);
	for (int i=0;i<n;i++) {
		var[i]=i;
	}
	for (int i=0;i<m;i++) {
		int x,y;
		cin>>x>>y;
		graph[i].a=x;
		graph[i].b=y;
	}
	for (int i=0;i<m;i++) {
		int x=graph[i].a;
		int y=graph[i].b;
		if (var[x]!=var[y]) {
			tree.push_back(graph[i]);
			int old_var=var[y];
			int new_var=var[x];
			for (int j=0;j<n;j++) {
				if ( var[j]==old_var) {
					var[j]=new_var;
				}
			}
		}
	}
	for (int i=0;i<n-1;i++) {
		cout<<tree[i].a<<" "<<tree[i].b;
		if (i!= n-2) cout<<endl;
	}
	return 0;
}
