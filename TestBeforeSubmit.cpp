#include<iostream>
using namespace std;
int main(){
    int a,b;
    for(a=0;a<200;a++){
        for (b=4; b < 200; ++b)
        {
            if (((0+a)%b==1)&&((23+a)%b==3)&&((-4+a)%b==0)&&((4+a)%b==2))
            {
                cout<<a<<" "<<b;
                return 0;
            }
            
        }
    }
    cout<<"NO!";
}