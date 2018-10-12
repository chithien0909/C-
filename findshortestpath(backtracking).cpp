#include<bits/stdc++.h>
#define fto(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
int x[1000];
int y[1000];
int Min;
int sum;
int n,k;
int flag[1000];
int maps[1000][1000];
void print(){
	fto(j,1,n-1){
		cout<<y[j]<<"->";
	}
	cout<<y[n]<<"\n";
}
void prints(){
	fto(j,1,n-1){
		cout<<x[j]<<"->";
	}
	cout<<x[n]<<"\n";
}
int summap(){
	sum=0;
	fto(j,1,n-1) sum+=maps[x[j]][x[j+1]];
	return sum;
}
void solve(int t,int i){
	fto(j,1,n){
		if(flag[j] && maps[t][j]!=9999){
			x[i]=j;
			if(i==n){
				int a=summap();
				prints();
				cout<<"Sum = "<<a<<"\n";
				if(Min>a){
					Min=a;
					fto(j,1,n) y[j]=x[j];
				}
			}
			else{
				flag[j]=0;
				solve(j,i+1);
				flag[j]=1;
		}
		}
	}
}
int main(){
	cout<<"Enter position start: ";
	cin>>k;
	freopen("map.txt","a+",stdin);
	cin>>n;
	Min=9999;
	fto(j,1,n)
		fto(m,1,n){
			cin>>maps[j][m];
			if(maps[j][m]==0) maps[j][m]=9999;
		}
	cout<<"Map: \n";
	fto(j,1,n){
		fto(m,1,n){
			if(maps[j][m]==9999) cout<<"0"<<"\t";
			else
			cout<<maps[j][m]<<"\t";
		}
		cout<<"\n";
	}
	fclose(stdin);
	x[1]=k;
	fto(j,1,n) flag[j]=1;
	flag[k]=0;
	solve(k,2);
	cout<<"Result: \n";
	print();
	cout<<"Min = "<<Min;
	return 0;
}
