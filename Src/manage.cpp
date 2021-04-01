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
	printf("%*c", 30, 0);
	printf("**********************(输入序号选择操作)************************\n");

}

void Manage::errorChoice()
{
	printf("0.错误输入\n");
	system("pause");
	exit(0);
}

void Manage::showAllMessage()
{
	if (this ->_isEmpty) {
		printf("记录为空");
	}
	else {
		for (int i = 0; i < this->_attendance; i++)
			//多态
			this->_peopleArray[i]->show();
	}

	//按任意键后清屏
	system("pause");
	system("cls");
}

void Manage::addMessage()
{
	int add_num = 0;
	printf("请输入要添加的人数");
	//scanf_s("%d", &add_num);
	//printf("%d", add_num);
	std::cin >> add_num;
	if (add_num >= 0) {
		printf("添加人数为%d\n", add_num);

		// 计算添加以后的人数
		int new_num = this->_attendance + add_num;

		// 根据系统内新的人数开辟空间
		People** new_space = new People * [new_num];

		//先将原来的数据拷贝到新空间
		if (this->_peopleArray != NULL) {
			for (int i = 0; i < this->_attendance; i++) {
				new_space[i] = this->_peopleArray[i];
			}
		}

		// 添加新数据
		for (int i = 0; i < add_num; i++) {

			People* people = new People;

			std::cout << "请输入第" << i + 1 << "位新职员的姓名" << std::endl;
			std::cin >> people->_name;
			std::cout << "请输入第" << i + 1 << "位新职员的性别" << std::endl;
			std::cin >> people->_sex;
			std::cout << "请输入第" << i + 1 << "位新职员的出生年月" << std::endl;
			std::cin >> people->_birthday;
			std::cout << "请输入第" << i + 1 << "位新职员的工作年月" << std::endl;
			std::cin >> people->_workData;
			std::cout << "请输入第" << i + 1 << "位新职员的学历" << std::endl;
			std::cin >> people->_qualification;
			std::cout << "请输入第" << i + 1 << "位新职员的职务" << std::endl;
			std::cin >> people->_duty;
			std::cout << "请输入第" << i + 1 << "位新职员的住址" << std::endl;
			std::cin >> people->_address;
			std::cout << "请输入第" << i + 1 << "位新职员的电话" << std::endl;
			std::cin >> people->_directory;

			//将信息保存到数组中
			new_space[this->_attendance + i] = people;
		}

		// 释放原有空间
		delete[] this->_peopleArray;

		// 更改新空间指向
		this->_peopleArray = new_space;

		// 更新教职工人数
		this->_attendance = new_num;

		//更新文件标志
		this->_isEmpty = false;

		std::cout << "成功添加" << add_num << "名教职工信息" << std::endl;

		// 保存数据
		this->saveInfo();
	}
	else {
		printf("输入数据错误\n");
	}
	//按任意键后 清屏回到上级目录
	system("pause");
	system("cls");

}

void Manage::deleteMessage()
{
	if (this->_isEmpty)
	{
		std::cout << "记录为空！" << std::endl;
	}
	else {
		//按照教职工姓名删除
		std::cout << "请输入想要删除教职工的编号：" << std::endl;
		std::string name;
		std::cin >> name;

		int index = this->inSearch(name);

		if (index != -1) //说明职工存在，并且要删除掉index位置上的职工
		{

			for (int i = index; i < this->_attendance - 1; i++)
			{
				//数据前移
				this->_peopleArray[i] = this->_peopleArray[i + 1];
			}
			this->_attendance--; //更新数组中记录人员个数
			//数据同步更新到文件中
			this->saveInfo();

			std::cout << "删除成功！" << std::endl;
		}
		else
		{
			std::cout << "删除失败，未找到该职工" << std::endl;
		}
	}
		//按任意键后清屏
	system("pause");
	system("cls");
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

void Manage::saveInfo() {
	std::ofstream ofs;
	ofs.open(FILENAME, std::ios::out);

	for (int i = 0; i < this->_attendance; i++) {

		ofs
			<< this->_peopleArray[i]->_name << "  "
			<< this->_peopleArray[i]->_sex << "  "
			<< this->_peopleArray[i]->_birthday << "  "
			<< this->_peopleArray[i]->_workData << "  "
			<< this->_peopleArray[i]->_qualification << "  "
			<< this->_peopleArray[i]->_duty << "  "
			<< this->_peopleArray[i]->_address << "  "
			<< this->_peopleArray[i]->_directory << std::endl;
	}
	ofs.close();
}

int Manage::inSearch(std::string name) {

	int index = -1;

	for (int i = 0; i < this->_attendance; i++)
	{
		if (this->_peopleArray[i]->_name == name)
		{
			//找到职工
			index = i;

			break;
		}
	}

	return index;
}