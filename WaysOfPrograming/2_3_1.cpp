#include <iostream>
using namespace std;
//背包问题
int N,V;//物品数量，包容量
// 假设最大容量V=10，物品个数N=3，物品大小w{3,4,5}，物品价值p{4,5,6}。
int C[3]={1,3,7};
int W[3]={5,4,5};
int max(int a,int b){
	if (a>b) return a;
	return b;
}
int maxVal(int i,int V){
	if (i<0)
	{
		return 0;
	}
	if(V<C[i]) return maxVal(i-1,V);
	return max(maxVal(i-1,V),maxVal(i-1,V-C[i])+W[i]);
}
int main(int argc, char const *argv[])
{
	int N=3;
	int V=10;
    cout<<maxVal(N-1,V)<<endl;
	return 0;
}
//啊哈哈哈!我用递归解决了0——1背包问题！！！！！