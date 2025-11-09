#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int argc;
char** argv;

#include "./include/define.h"
#include "./include/const.h"
#include "./include/function.h"

int main(int _argc,char* _argv[]) {
	argc=_argc;
	argv=_argv;
	if(argc<=1) {
		/* SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x04); 
		cout<<"Error:"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
		cout<<"  Only allowed to run with commad [pyvc] on console!"<<endl;
		system("pause"); */
		cout<<help()<<endl;
		return 0;
	}
	if(argv[1][0]=='-') {
		if(argv[1][1]=='-') {
			cvcopt();
		} else {
			goto _analyse;
		}
	} else {
		_analyse:
		string (*fptr)()=nullptr;
		const int len=fvec.size();
		for(int i=0;i<len;i++) {
			if(fvec[i].fname==argv[1]) {
				fptr=fvec[i].fptr;
			}
		}
		if(fptr) {
			cout<<fptr()<<endl;
		} else {
			cout<<"Î´ÖªµÄÃüÁî: "<<argv[1]<<" !"<<endl;
		}
	}
	return 0;
}
