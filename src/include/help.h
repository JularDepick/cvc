string help() {
	return R"(
Usage:
  cvc <command> [options]
Commands:
  --help					查看cvc帮助文档
  --version					查看cvc程序版本
  --root					查看cvc程序安装路径
  --support					查看cvc支持的编程语言 
  --check					检查cvc注册表配置完整性
  --cfg						打开IDE配置文件(cvc_record.json)
  --list					列出已配置的IDE记录 
  add [langname] [version]			添加一条空白的新IDE记录
  fix [langname] [version] [key] [newvalue] 	修改目标编程语言的IDE记录键值 
  search --evar					自动搜索环境变量中可能的IDE配置
  show [langname]				查看目标编程语言的IDE记录 
  show [langname] [version]			查看目标版本编程语言的IDE记录 
  switch [langname] [version]			切换到目标编程语言的IDE版本(需正确配置cvc_record.json)
  )";
}
