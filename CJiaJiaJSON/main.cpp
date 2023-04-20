#include <iostream>
#include <fstream>
#include <Windows.h>
#include "nlohmann\json.hpp"
using namespace std;
using json = nlohmann::json;

// 参考 https://www.cnblogs.com/linuxAndMcu/p/14503341.html
int main()
{
	system("chcp 65001");
	std::ifstream f("config.json");// 读取一个json文件，nlohmann会自动解析其中数据
	json data = json::parse(f);

	std::cout << data << std::endl;

	SetConsoleOutputCP(CP_UTF8);
	std::cout << u8"读取文件完成！" << std::endl;
	
	std::ofstream o("pretty.json");// 以易于查看的方式将json对象写入到本地文件
	o << std::setw(4) << data << std::endl;
	std::cout << u8"写入文件完成！" << std::endl;

	std::cout << data["map3d"]["basemaps"] << std::endl;

	string sendBuf = data.dump();
	std::cout << sendBuf << std::endl;
	std::cout << sendBuf.c_str() << std::endl;
	system("pause");
	return 0;
}