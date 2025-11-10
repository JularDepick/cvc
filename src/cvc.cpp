#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
//json.hpp 来源于 https://github.com/nlohmann/json/blob/develop/single_include/nlohmann/json.hpp
#include "./include/json.hpp"
using namespace std;

//参数信息全局映射副本 
int argc;
char** argv;
//命令运行状态返回(状态码+状态描述) //应该由具体函数维护
unsigned short echocode=0;
string echodesc="";
//执行结果 //应该由具体函数维护
string restext="";

//自定义头文件(部分) 
#include "./include/define.h"
#include "./include/const.h"
#include "./include/function.h"

int main(int _argc,char* _argv[]) {
	//参数信息映射到全局变量上 
	argc=_argc;
	argv=_argv;
	
	//判断参数基本情况 
	if(argc<=1) {
		//无参数默认输出帮助文档 
		cout<<help()<<endl;
		return 0;
	}
	
	//有第一个参数(即传入了命令名称)
	string cmdstr=argv[1];
	{	//查找该命令
		string (*fptr)()=nullptr;
		const int len=fvec.size();
		for(int i=0;i<len;i++) {
			if(fvec[i].fname==argv[1]) {
				//命令存在
				fptr=fvec[i].fptr;
				//执行 
				fptr(); 
			}
		}
		if(!fptr) {
			//没找到该命令
			echocode=(isopt(cmdstr)? _EROPT_:_ERCMD_);
		}
	}
	
	//运行状态码解析
	switch(echocode) {
		case _WELL_: {
			echodesc="";
			break;
		}
		case _EROPT_: {
			echodesc=("错误的选项" " " +cmdstr+" !\n");
			guess();
			break;
		}
		case _ERCMD_: {
			echodesc=("错误的命令" ": " +cmdstr+" !\n");
			guess();
			break;
		}
		case _MISSARG_: {
			echodesc=("缺失的参数" ": ");
			break;
		}
		case _OVERARG_: {
			echodesc=("过多的参数" ": ");
			break;
		}
		case _FERARG_: {
			echodesc=("错误的参数" ": ");
			break;
		}
		case _DENIED_: {
			echodesc=("禁止的操作" ": ");
			break;
		}
		default: {
			echodesc=("程序发生了未知错误,已加入到日志文件 cvc.log ,请上报开发者尝试修复" "!");
			//记入未知错误日志 Write in Unkown Error Log
			wtinuelog(); 
			break;
		}
	}
	
	//输出执行结果 
	cout<<echodesc<<restext<<endl;
	
	return 0;
}
