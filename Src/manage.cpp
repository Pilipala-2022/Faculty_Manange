#include "manage.h"
Manage::Manage()
{
	// 打开存储文件
}

Manage::~Manage()
{

}

void Manage::showMenu()
{
	// 显示菜单
	printf("%*c", 30, 0);
	printf("************************************************************\n");
	printf("%*c", 30, 0);
	printf("************************************************************\n");
	printf("%*c", 30, 0);
	printf("**********************教职工管理系统************************\n");
	printf("%*c", 30, 0);
	printf("**********************1.显示教职工信息**********************\n");
	printf("%*c", 30, 0);
	printf("**********************2.增加教职工信息**********************\n");
	printf("%*c", 30, 0);
	printf("**********************3.删除教职工信息**********************\n");
	printf("%*c", 30, 0);
	printf("**********************4.查找教职工信息**********************\n");
	printf("%*c", 30, 0);
	printf("**********************5.修改教职工信息**********************\n");
	printf("%*c", 30, 0);
	printf("**********************6.清除所有信息************************\n");
	printf("%*c", 30, 0);
	printf("**********************7.退出系统****************************\n");
	printf("%*c", 30, 0);
	printf("************************************************************\n\n\n");

}

void Manage::errorChoice(int fg)
{
	printf("0.错误输入\n");
}

void Manage::showAllMessage()
{
	printf("1.显示教职工信息\n");
}

void Manage::addMessage()
{
	printf("2.增加教职工信息\n");
}

void Manage::deleteMessage()
{
	printf("3.删除教职工信息\n");
}

void Manage::findMessage()
{
	printf("4.查找教职工信息\n");
}

void Manage::modMessage()
{
	printf("5.修改教职工信息\n");
}

void Manage::clearMessage()
{
	printf("6.清除所有信息\n");
}

void Manage::exitSystem()
{
	printf("7.退出系统\n");
}