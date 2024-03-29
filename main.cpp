#include <bits/stdc++.h>
using namespace std;
string lis[8];
string col[8]={"BFBFBF","FE4C61","F39C11","FFC116","52C41A","3498DB","9D3DCF","0E1D69"};
int cnt[8];
struct problem{
	string id,name;
};
vector<problem>p[8];
ifstream luogu("online.txt");
map<string,bool>havedone;
int main(){
    freopen("modified.txt","r",stdin);
    freopen("output.txt","w",stdout);
	string a,b,c;
	for(int i=0;i<8;i++)cin>>lis[i];
	while(cin>>a>>b>>c){
		for(int i=0;i<8;i++){
			if(c==lis[i])p[i].push_back((problem){a,b});
		}
	}
	while(luogu>>a){
		if(a[0]<'A'||a[0]>'Z'||a[0]=='N')continue;
		havedone[a]=1;
	}
	cout<<"| | | |\n|--|--|--|\n";
	for(int i=0;i<8;i++){
		for(int j=0;j<p[i].size();j++){
			bool flag=0;
			if(havedone.find(p[i][j].id)!=havedone.end())flag=1,cnt[i]++;
			cout<<"|[$";
			if(flag)cout<<"\\colorbox{#E1F2E1}{";
			cout<<"\\color{#";
			cout<<col[i];
			cout<<"}{\\texttt{";
			cout<<p[i][j].name;
			cout<<"}}";
			if(flag)cout<<"}";
			cout<<"$](";
			cout<<"https://www.luogu.com.cn/problem/";
			cout<<p[i][j].id;
			cout<<")";
			if(j%3==2)cout<<"|\n";
		}
		if(p[i].size()%3==1)cout<<"| | |\n";
		if(p[i].size()%3==2)cout<<"| |\n";
	}
	cout<<"\n$\\color{white}{";
	for(int i=0;i<8;i++){
		cout<<"\\colorbox{"<<col[i]<<"}{\\texttt{";
		cout<<cnt[i]<<"/"<<p[i].size();
		cout<<"}}";
	}cout<<"}$";
	return 0;
}

