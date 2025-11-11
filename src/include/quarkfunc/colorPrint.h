bool colorPrint(string target,unsigned short color=0x0407,string then="",ostream& fout=cout) {
	//参数color: 前两位代表高光颜色，后两位代表控制台原色，默认是黑底红字和黑底白字 
	if(!fout.good()) {
		return 1;
	}
	if(target.size()==0) {
		return 1;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color/256%256);
	fout<<target;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color%256);
	fout<<then;
	return 0;
}
