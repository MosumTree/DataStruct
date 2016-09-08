#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a[10]={89,1,23,12,6,2,7,8,9,13};
	int b[5]={};
	int max=a[0];
	int maxo=0;
	int jduge=1;
	int i = 5;
	for (int m = 0; m < 5; ++m)
	{
		b[m]=a[m];
		if (b[m]>max)
		{
			max=b[m];
			maxo=m;
		}
	}
	while(jduge){
	for (int m = 0; m < 5; ++m)
	{
		if (b[m]>max)
		{
			max=b[m];
			maxo=m;
		}
	}

    for (; i <=10; ++i)
    {
    	if (i==10)
    	{
    		for (int j = 0; j < 5; ++j)
    		{
    			cout<<b[j]<<",";
 
    		}
    		jduge=0;
    		break;
    	}
    	if (a[i]>=max)
    	;
        else{
        	max=a[i];
        	b[maxo]=max;
            i++;
        	break;
        }

    }
}
	return 0;
}