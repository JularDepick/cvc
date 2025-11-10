//版权信息 
#define _COPYRIGHT_ "https://github.com/JularDepick"
//版本信息 
#define _VERSION_ "1.0.0"
//注册表路径(原则上只操作 HKEY_LOCAL_MACHINE 根项)
#define _REGPATH_ "SOFTWARE\\Wencue\\cvc\\" _VERSION_
//支持的编程语言 
#define _SUPPORT_ "python,c,cpp"
//UI文本的宏定义,方便翻译成不同语言的版本 
#include "./UItextdefine.h"

//执行成功 
#define _WELL_ 0
//错误的选项 
#define _EROPT_ 1
//错误的命令 
#define _ERCMD_ 2
//缺少参数 
#define _MISSARG_ 3
//参数过多 
#define _OVERARG_ 4
//无效参数 
#define _FERARG_ 5
//权限不足 
#define _DENIED_ 6

//保留返回值
#define _0_ "" 

