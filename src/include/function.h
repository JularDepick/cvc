#include "help.h"
#include "cmdcolor.h"
#include "getroot.h"
#include "isopt.h"
#include "checkcfg.h"
#include "showcfg.h"
//引入的为辅助函数 

//选项处理单独作一个函数 
string cvcopt() {
	const string opt=argv[1];
	if(opt=="--help") {
		cout<<help()<<endl;
	} else
	if(opt=="--version") {
		cout<<"cvc "<<_VERSION_<<" from "<<getroot()<<"\n@Copyright: "<<_COPYRIGHT_ <<endl;
	} else
	if(opt=="--root") { 
		cout<<getroot()<<endl;
	} else
	if(opt=="--support") {
		cout<<"当前cvc版本支持的编程语言有: "<<_SUPPORT_<<endl;
	} else
	if(opt=="--check") {
		checkcfg();
	} else
	if(opt=="--cfg") {
		string cmdstr="start ";
		cmdstr+=getroot();
		cmdstr+="\\cvc_record.json";
		cout<<cmdstr<<endl;
		system(cmdstr.data());
	} else
	if(opt=="--list") {
		showcfgs();
	}
	//有效选项到此为止 
	  else
	if(!argv[1][2]) {
		cout<<help()<<endl;
	}
	else {
		cout<<"没有这个选项: "<<argv[1]<<" !"<<endl;
	}
	return "";
}



//以下函数均为关键字操作函数 

string add() {
	return "";
}

string fix() {
	return "";
}

string search() {
	return "";
}

string show() {
	return "";
}

string _switch() {
	return "";
}

struct fun {
	string fname;  //函数关键字 
	string (*fptr)();  //函数指针
};
const vector<fun> fvec={
	{"add",&add},
	{"fix",&fix},
	{"search",&search},
	{"show",&show},
	{"switch",&_switch}
};

