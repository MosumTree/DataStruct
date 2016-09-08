#include <iostream>
#include <windows.h>
using namespace std;
int main(int argc, char const *argv[])
{
	const DWORD busytime=10;
	const DWORD idletime=busytime;
	long startTime=0;
	while(true){
		DWORD startTime=GetTickCount();
		while(GetTickCount()-startTime<=busytime);
		Sleep(idletime);
	}
}