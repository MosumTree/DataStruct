#include <iostream>
usin namespce std;
int main(int argc, char const *argv[])
{
	int T,N,M;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		cin>>N>>M;
		int *a=int [N];
		int *d=int [M];
		for (int i = 0; i < N; ++i)
		{
			cin>>a[i];
		}
		for (int i = 0; i < M; ++i)
		{
			cin>>d[i];
		}
	}
	return 0;
}