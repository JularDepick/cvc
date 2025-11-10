//引入的为辅助函数(可以被()显式地调用) 
#include "help.h"
#include "cmdcolor.h"
#include "getroot.h"
#include "isopt.h"
#include "checkcfg.h"
#include "showcfg.h"
#include "colorprint.h"
#include "error.h"
#include "guess.h"
#include "wtinuelog.h"

/*选项处理
string cvcopt() {
	const string opt=argv[1];
	if(opt=="") {
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
*/

//以下定义函数是交互设计的,不期望被()显式地调用,他们不返回任何有效文本,定义为string返回值类型仅仅是一个保留举措 

string __help() {
	return _0_;
}

string __version() {
	return _0_;
}

string __root() {
	return _0_;
}

string __support() {
	return _0_;
}

string __check() {
	return _0_;
}

string __cfg() {
	return _0_;
}

string __list() {
	return _0_;
}

string __add() {
	return _0_;
}

string __fix() {
	return _0_;
}

string __search() {
	return _0_;
}

string __show() {
	return _0_;
}

string __switch() {
	return _0_;
}

struct afun {
	//函数关键字(命令名称) 
	string fname;
	//函数指针
	string (*fptr)();
};
const vector<afun> fvec={
	{"--help",
		&__help},
	{"--version",
		&__version},
	{"--root",
		&__root},
	{"--support",
		&__support},
	{"--check",
		&__check},
	{"--cfg",
		&__cfg},
	{"--list",
		&__list},
	{"add",
		&__add},
	{"fix",
		&__fix},
	{"search",
		&__search},
	{"show",
		&__show},
	{"switch",
		&__switch}
};

