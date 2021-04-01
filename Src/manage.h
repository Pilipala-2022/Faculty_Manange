#pragma once
# include <iostream>
#include <fstream>
# include"people.h"

#define FILENAME "manageFile.txt"


class Manage
{
public:
	Manage();

	~Manage();

	void showMenu();  

	void errorChoice();     //0.错误输入

	void showAllMessage();  //1.显示教职工信息

	void addMessage();  //2.增加教职工信息

	void deleteMessage();  //3.删除教职工信息

	void findMessage();  //4.查找教职工信息

	void modMessage();  //5.修改教职工信息

	void clearMessage();  //6.清除所有信息

	void exitSystem();  //7.退出系统

private:
	// 系统中的人数
	int _attendance;

	// 职工指针
	People** _peopleArray;

	// 标志文件是否为空
	bool _isEmpty;

	void saveInfo();


};

