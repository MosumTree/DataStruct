#include <iostream>
using namespace std
double maxconstantmult(double *a,int length){
	double maxend=a[0];
	double minend=a[0];
	double maxresult=a[0];
	for (int i = 1; i < length; ++i)
	{
		end1=maxend*a[i];
		end2=minend*a[i];
		maxend=max(max(end1,end2),a[i]);
		minend=min(min(end1,end2),a[i]);
		maxresult=max(maxend,minend);
	}
}
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}