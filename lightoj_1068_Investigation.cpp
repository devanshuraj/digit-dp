#include<bits/stdc++.h>
using namespace std;

int dp[15][92][92][2];
int dig[15];
int len;
int a,b,k;
int go(int idx,int mod1,int mod2,bool less)
{
	if(idx>len){
		return (mod1==0 and mod2==0);
	}
	int &ans=dp[idx][mod1][mod2][less];
	if(ans!=-1){
		return ans;
	}
	ans=0;
	int limit=9;
	if(!less){
		limit=dig[idx];
	}
	for(int i=0;i<=limit;i++){
		int tmod1=(mod1*10+i)%k;
		int tmod2=(mod2+i)%k;
		ans+=go(idx+1,tmod1,tmod2,(less|(i<limit)));
	}
	return ans;
}

int calc(int num)
{
	len=0;
	while(num)
	{
		dig[++len]=num%10;
		num/=10;
	}
	reverse(dig+1,dig+len+1);
	return go(1,0,0,0);
}

void testcases(int tc){

	memset(dp,-1,sizeof(dp));
	cin>>a>>b>>k;
	cout<<"Case "<<tc<<": ";
	int ans=0;
	if(k<90){
		ans=calc(b);
		memset(dp,-1,sizeof(dp));
		ans-=calc(a-1);
	}
	cout<<ans<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	int ct=1;
	while(T--){
		testcases(ct++);
	}
}
