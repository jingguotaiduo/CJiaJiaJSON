#include <iostream>
#include <fstream>
#include <Windows.h>
#include "nlohmann\json.hpp"
using namespace std;
using json = nlohmann::json;

// �ο� https://www.cnblogs.com/linuxAndMcu/p/14503341.html
int main()
{
	system("chcp 65001");
	std::ifstream f("config.json");// ��ȡһ��json�ļ���nlohmann���Զ�������������
	json data = json::parse(f);

	std::cout << data << std::endl;

	SetConsoleOutputCP(CP_UTF8);
	std::cout << u8"��ȡ�ļ���ɣ�" << std::endl;
	
	std::ofstream o("pretty.json");// �����ڲ鿴�ķ�ʽ��json����д�뵽�����ļ�
	o << std::setw(4) << data << std::endl;
	std::cout << u8"д���ļ���ɣ�" << std::endl;

	std::cout << data["map3d"]["basemaps"] << std::endl;

	string sendBuf = data.dump();
	std::cout << sendBuf << std::endl;
	std::cout << sendBuf.c_str() << std::endl;
	system("pause");
	return 0;
}