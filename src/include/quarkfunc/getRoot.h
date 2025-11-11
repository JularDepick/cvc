string getRoot() { 
	//从注册表获取
	//查找 HKEY_LOCAL_MACHINE
	HKEY hkey=nullptr;
	long code=RegOpenKeyExA(HKEY_LOCAL_MACHINE,_REGPATH_,0,KEY_READ,&hkey);
	if(!code) {
		string rootstr="";
		DWORD pathsize=2048;
		rootstr.resize(pathsize);
		long code1=RegQueryValueExA(hkey,"",NULL,NULL,(unsigned char*)(rootstr.data()),&pathsize);
		if(!code) {
			return rootstr;
		}
	}
	return _0_;
} 

