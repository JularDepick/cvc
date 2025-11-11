/*函数相关规范约定
0. 函数按复杂度/调用频率/封装度的层级设定: 夸克函数 < 原子函数 < 交互函数
1. 只允许高层级函数调用低层级函数,同级函数禁止相互调用
2. 不期望有递归函数,最好用循环替代,除非递归深度浅且有必要需求 
3. 夸克函数应当编译到二进制文件中,原子函数和交互函数允许保存到外部依赖库DLL文件中,方便项目体量增大后的维护和运行效率提升 
4. 夸克函数和原子函数允许被代码 函数名() 显式地调用,交互函数不期望这么做,除非必需
5. 夸克函数和原子函数的命名采用驼峰命名法,以动词开头更佳,交互函数以 __关键字 格式命名
6. 夸克函数和原子函数分文件夹储存,头文件名称与函数名称保持一致
7. 交互函数最好定义在 function.h 中,不建议分文件定义 
8. 夸克函数和原子函数的引入顺序和交互函数的定义顺序无强制要求,但建议遵从文件名字典序或按功能模块排序,便于维护 
9. 交互函数不返回任何有效文本,定义为string的返回值类型仅仅是一个保留举措,方便可能的新架构或重构 
*/

//夸克函数 
#include "./quarkfunc/changeColor.h"
#include "./quarkfunc/checkConfig.h"
#include "./quarkfunc/checkReg.h"
#include "./quarkfunc/colorPrint.h"
#include "./quarkfunc/getHelpText.h"
#include "./quarkfunc/getRoot.h"
#include "./quarkfunc/getSimilarity.h"
#include "./quarkfunc/isOpt.h"
#include "./quarkfunc/logErr.h"
#include "./quarkfunc/showConfig.h"

//原子函数 
#include "atomfunc/guessCommand.h"


//交互函数 

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
//命令和无前参的选项执行逻辑几乎一致
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

