#include <iostream>
using namespace std;

int main() {
	int n,v1,v2,a,b,min_cost=0;
	int matrix[10][10];
	int arr[100]={0};
	int arr_index=0;
	int visit[10]={0};
	cout<<"How many vertices?";
	cin>>n;
	cout<<"Enter the adjacency matrix"<<endl;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			cin>>matrix[i][j];
			if (matrix[i][j]==0) matrix[i][j]=1000; 
		}
	}
	visit[1]=1;
	int k=1,min=1000;
	while (k<n) {
	for (int i=0;i<n;i++) {
		for (int j=1;j<n;j++) {
			if (matrix[i][j]<min) {
				if (visit[i]!=0) {
					min=matrix[i][j];
					v1=a=i;
					v2=b=j;
				}
				if (visit[v1]==0 || visit[v2]==0) {
					arr[arr_index]=b;
					arr_index++;
					k++;
					min_cost=min_cost+min;
					visit[b]=1;
				}	
			}
		}
	}	
	matrix[a][b]=matrix[b][a]=1000;
	}
	cout<<1<<"->";
	for (int i=0;i<n-1;i++) {
		cout<<arr[i];
		if (i<n-2) cout<<"->";
	}
	cout<<"Minimum cost"<<min_cost;
	return 0;
}
