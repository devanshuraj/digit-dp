#include<bits/stdc++.h>
using namespace std;
#define int long long
const int off=200;
int dig[20];
int dp[20][200+200][2][2];

int go(int idx,int sum,bool less,bool add)
{
	if(idx==0){
		return sum==1;
	}
	int &ans=dp[idx][sum+off][less][add];
	if(ans!=-1)return ans;
	ans=0;
	int lim=9;
	if(!less)lim=dig[idx];
	for(int i=0;i<=lim;i++){
		if(add)ans+=go(idx-1,sum+i,(less|(i<lim)),add^1);
		else ans+=go(idx-1,sum-i,(less|(i<lim)),add^1);
	}
	return ans;
}

int f(int num)
{
	int len=0;
	while(num){
		dig[++len]=num%10;
		num/=10;
	}
	bool t=len%2==0;
	return go(len,0,0,t);
}

void testcases(){
	int a,b;
	cin>>a>>b;
	memset(dp,-1,sizeof(dp));
	int ans=f(b);
	memset(dp,-1,sizeof(dp));
	if(a>0)ans-=f(a-1);
	cout<<ans<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--){
		testcases();
	}
}
