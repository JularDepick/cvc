bool isopt(string str) {
	if(str.size()<=2) {
		return 0;
	}
	if(str[0]=='-') {
		if(str[1]=='-') {
			return 1;
		}
	}
	return 0;
}
