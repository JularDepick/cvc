string changeColor(unsigned int code=0x07,bool global=1) {
	//改变控制台颜色，有全局(默认)和局部(到下一次调用为止)两种选择 
	if(global) {
		if(code==0x07) {
			system("color 07");
		} else {
			const unsigned short a=code/16%16;
			const unsigned short b=code%16;
			string cmdstr="color ";
			cmdstr+=Hexs[a];
			cmdstr+=Hexs[b];
			system(cmdstr.data());
		}
	} else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),code);
	}
	return _0_;
} 
