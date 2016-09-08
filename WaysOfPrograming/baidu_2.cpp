//没有对负数处理的大数类
#include <iostream> 
#include <cstring>
#include <cstdio>
#include <iomanip> 
#include <algorithm> 
using namespace std;
int f(int n)
{
int dp[3] = { 1, 1 };
if (n < 2)
{
return 1;
}
for (int i = 2; i <= n; i++)
{
dp[2] = dp[0] + dp[1];
dp[0] = dp[1];
dp[1] = dp[2];
}
return dp[2];
}


int main(int argc, char const *argv[])
{
	BigNum a,b;
	while(cin>>a>>b){			
			cout<<a<<" "<<b<<endl;
	}

}
