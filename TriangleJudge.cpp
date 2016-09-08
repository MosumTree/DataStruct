#include <iostream>
using namespace std;
int main(){
	int a,b,c;
	while(true){
	cout<<"Please enter three sides of the triangle:";
	cin>>a>>b>>c;
	if (a+b>c&&a+c>b&&b+c>a)
	{
		if (a==b||a==c||b==c)
		{
			if (a==b&&b==c)
			{
				cout<<"It's an equilateral triangle."<<endl;//等边
			}
			else{
				cout<<"It's an isosceles triangle."<<endl;//等腰
			}
		}
		else{
			cout<<"It's a common triangle."<<endl;//普通
		}
	}
	else{
		cout<<"It's not a triangle."<<endl;//非三角形
	}
}
}