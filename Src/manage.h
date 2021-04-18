# include<stdio.h>
#include <fstream>
# include"people.h"

#define FILENAME "manageFile.txt"

// 系统中的人数
int _attendance;

// 职工指针
PeopleData** _peopleArray;

// 标志文件是否为空
bool _isEmpty;

extern void saveInfo();
extern int inSearch(int select, string data);
extern int getAttendance();
extern void initPeople();

int getAttendance() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //打开文件  读

	string name;		//姓名
	string sex;		//性别
	string birthday;	//出生年月
	string workData;	//工作年月
	string qualification;	//学历
	string duty;		//职务
	string address;	//住址
	string directory;	//电话

	int num = 0;

	while (ifs >> name && ifs >> sex && ifs >> birthday && ifs >> workData && ifs >> qualification && ifs >> duty && ifs >> address && ifs >> directory)
	{
		//统计人数变量
		num++;
	}

	return num;
}

void initPeople() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	string name;		//姓名
	string sex;		//性别
	string birthday;	//出生年月
	string workData;	//工作年月
	string qualification;	//学历
	string duty;		//职务
	string address;	//住址
	string directory;	//电话

	int index = 0;
	while (ifs >> name && ifs >> sex && ifs >> birthday && ifs >> workData && ifs >> qualification && ifs >> duty && ifs >> address && ifs >> directory) {
		//People* people = new People;
		PeopleData* people = new PeopleData;
		people->_name = name;
		people->_sex = sex;
		people->_birthday = birthday;
		people->_workData = workData;
		people->_qualification = qualification;
		people->_duty = duty;
		people->_address = address;
		people->_directory = directory;
		_peopleArray[index] = people;
		index++;
	}

	//关闭文件
	ifs.close();
}

void readData() {
	//1、文件不存在

	ifstream ifs;
	ifs.open(FILENAME, ios::in); // 读文件

	if (!ifs.is_open())
	{
		printf("文件不存在\n");
		//初始化属性
		//初始化记录人数
		_attendance = 0;
		//初始化数组指针 
		_peopleArray = NULL;
		//初始化文件是否为空
		_isEmpty = true;
		ifs.close();
		return;
	}

	//2、文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		printf("文件为空！\n");
		//初始化记录人数
		_attendance = 0;
		//初始化数组指针 
		_peopleArray = NULL;
		//初始化文件是否为空
		_isEmpty = true;
		ifs.close();
		return;
	}

	//3、文件存在，并且记录数据
	int num = getAttendance();
	printf("职工人数为：%d", num);
	_attendance = num;

	//开辟空间
	_peopleArray = new PeopleData*[_attendance];
	//将文件中的数据 ，存到数组中
	initPeople();



}

void showMenu()
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

void errorChoice()
{
	printf("错误输入\n");
	system("pause");
	exit(0);
}

void showAllMessage()
{
	if (_isEmpty) {
		printf("记录为空");
	}
	else {
	for (int i = 0; i < _attendance; i++)

		show(_peopleArray[i]);
	}

	//按任意键后清屏
	system("pause");
	system("cls");
}

void addMessage()
{
	int add_num = 0;
	printf("请输入要添加的人数");
	scanf_s("%d", &add_num);
	if (add_num >= 0) {
		printf("添加人数为%d\n", add_num);

		// 计算添加以后的人数
		int new_num = _attendance + add_num;

		// 根据系统内新的人数开辟空间
		PeopleData** new_space = new PeopleData *[_attendance];

		//先将原来的数据拷贝到新空间
		if (_peopleArray != NULL) {
			for (int i = 0; i < _attendance; i++) {
				new_space[i] = _peopleArray[i];
			}
		}

		// 添加新数据
		for (int i = 0; i < add_num; i++) {

			PeopleData *people = new PeopleData;

			printf("请输入第%d位新职员的姓名", i+1);
			cin >> people->_name;

			printf("请输入第%d位新职员的性别", i + 1);
			cin >> people->_sex;

			printf("请输入第%d位新职员的出生年月", i + 1);
			cin >> people->_birthday;

			printf("请输入第%d位新职员的工作年月", i + 1);
			cin >> people->_workData;

			printf("请输入第%d位新职员的学历", i + 1);
			cin >> people->_qualification;

			printf("请输入第%d位新职员的职务", i + 1);
			cin >> people->_duty;

			printf("请输入第%d位新职员的住址", i + 1);
			cin >> people->_address;

			printf("请输入第%d位新职员的电话", i + 1);
			cin >> people->_directory;

			//将信息保存到数组中
			new_space[_attendance + i] = people;
		}
		// 释放原有空间
		delete[] _peopleArray;

		// 更改新空间指向
		_peopleArray = new_space;

		// 更新教职工人数
		_attendance = new_num;

		//更新文件标志
		_isEmpty = false;

		printf("成功添加%d名教职工信息\n", add_num);

		// 保存数据
		saveInfo();
	}
	else {
		printf("输入数据错误\n");
	}

	system("pause");
	system("cls");

}

void deleteMessage()
{
	if (_isEmpty)
	{
		printf("记录为空！\n");
	}
	else {
		printf("请输入查找的方式：\n");
		printf("1、按姓名查找 \n");
		printf("2、按电话查找 \n");
		printf("3、按住址查找 \n");

		int select = 0;
		string data;
		scanf_s("%d", &select);
		if (select == 1) {
			//按照教职工姓名删除
			printf("请输入想要删除教职工的姓名：\n");
			cin >> data;
		}
		else if (select == 2) {
			//按照教职工电话删除
			printf("请输入想要删除教职工的电话：\n");
			cin >> data;
		}
		else if (select == 2) {
			//按照教职工住址删除
			printf("请输入想要删除教职工的地址：\n");
			cin >> data;
		}
		int index = inSearch(select, data);
		if (index == -1) {
			printf("删除失败，未找到该职工");
		}
		while (index != -1) {

			for (int i = index; i < _attendance - 1; i++)
				{
					//数据前移
					_peopleArray[i] = _peopleArray[i + 1];
				}
			_attendance--; //更新数组中记录人员个数
			//数据同步更新到文件中
			saveInfo();

			index = inSearch(select, data);
			printf("删除成功！\n");
		}

	}
	//按任意键后清屏
	system("pause");
	system("cls");
}

void findMessage()
{
	if (_isEmpty)
	{
		printf("记录为空！");
	}
	else {
		printf("请输入查找的方式：\n");
		printf("1、按姓名查找 \n");
		printf("2、按电话查找 \n");
		printf("3、按住址查找 \n");

		int select = 0;
		string data;
		cin >> select;
		if (select == 1) {
			//按照教职工姓名删除
			printf("请输入想要查找教职工的姓名：\n");
			cin >> data;
		}
		else if (select == 2) {
			//按照教职工电话删除
			printf("请输入想要查找教职工的电话：\n");
			cin >> data;
		}
		else if (select == 3) {
			//按照教职工住址删除
			printf("请输入想要查找教职工的地址：\n");
			cin >> data;
		}

		int index = inSearch(select, data);
		
		if (index == -1)
			printf("查找失败，查无此人\n");

		//找到职工
		printf("查找成功！该职工信息如下：\n");
		show(_peopleArray[index]);
		index = inSearch(select, data);
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}

void modMessage()
{
	if (_isEmpty)
	{
		printf("文件不存在或记录为空！\n");
	}
	else {
		printf("请输入查找的方式：！\n");
		printf("1、按姓名查找\n");
		printf("2、按电话查找\n");
		printf("3、按住址查找\n");

		int select = 0;
		string data;
		cin >> select;
		if (select == 1) {
			//按照教职工姓名查找
			printf("请输入需要修改的教职工的姓名：\n");
			cin >> data;
		}
		else if (select == 2) {
			//按照教职工电话查找
			printf("请输入需要修改的教职工的电话：\n");
			cin >> data;
		}
		else if (select == 3) {
			//按照教职工住址删除
			printf("请输入需要修改的教职工的地址：\n");
			cin >> data;
		}

		int index = inSearch(select, data);

		if (index != -1) {
			printf("请输入需要修改的信息（根据下列序号选择）\n");
			printf("1.姓名\n");
			printf("2.性别\n");
			printf("3.出生年月\n");
			printf("4.工作年月\n");
			printf("5.学历\n");
			printf("6.职务\n");
			printf("7.住址\n");
			printf("8.电话\n");

			int choice;
			string mod_data;
			cin >> choice;
			if (choice == 1) {
				printf("请输入修改后的姓名\n");
				cin >> mod_data;
				_peopleArray[index]->_name = mod_data;
			}
			else if (choice == 2) {
				printf("请输入修改后的性别\n");
				cin >> mod_data;
				_peopleArray[index]->_sex = mod_data;
			}
			else if (choice == 3) {
				printf("请输入修改后的出生年月\n");
				cin >> mod_data;
				_peopleArray[index]->_birthday = mod_data;
			}
			else if (choice == 4) {
				printf("请输入修改后的工作年月\n");
				cin >> mod_data;
				_peopleArray[index]->_workData = mod_data;
			}
			else if (choice == 5) {
				printf("请输入修改后的学历\n");
				cin >> mod_data;
				_peopleArray[index]->_qualification = mod_data;
			}
			else if (choice == 6) {
				printf("请输入修改后的职务\n");
				cin >> mod_data;
				_peopleArray[index]->_duty = mod_data;
			}
			else if (choice == 7) {
				printf("请输入修改后的住址\n");
				cin >> mod_data;
				_peopleArray[index]->_address = mod_data;
			}
			else if (choice == 8) {
				printf("请输入修改后的电话\n");
				cin >> mod_data;
				_peopleArray[index]->_directory = mod_data;
			}
		}

	}
	//按任意键后清屏
	system("pause");
	system("cls");
}

void clearMessage()
{
	printf("确定清空？\n");
	printf("1、确定\n");
	printf("2、返回\n");

	int select = 0;
	scanf_s("%d", &select);

	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc); // 删除文件后重新创建
		ofs.close();

		if (_peopleArray != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < _attendance; i++)
			{
				delete _peopleArray;
				_peopleArray = NULL;
			}

			//删除堆区数组指针
			delete[] _peopleArray;
			_peopleArray = NULL;
			_attendance = 0;
			_isEmpty = true;
		}

		printf("清空成功！\n");
	}

	system("pause");
	system("cls");
}

void exitSystem()
{
	system("pause");
	exit(0); // 退出程序
}

void saveInfo() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < _attendance; i++) {

		ofs
			<< _peopleArray[i]->_name << "  "
			<< _peopleArray[i]->_sex << "  "
			<< _peopleArray[i]->_birthday << "  "
			<< _peopleArray[i]->_workData << "  "
			<< _peopleArray[i]->_qualification << "  "
			<< _peopleArray[i]->_duty << "  "
			<< _peopleArray[i]->_address << "  "
			<< _peopleArray[i]->_directory << endl;
	}
	ofs.close();
}

int inSearch(int select, string data) {

	int index = -1;

	if (select == 1)
	{
		for (int i = 0; i < _attendance; i++)
		{
			if (_peopleArray[i]->_name == data)
			{
				//找到职工
				index = i;

				break;
			}
		}
	}
	else if (select == 2) {
		for (int i = 0; i < _attendance; i++)
		{
			if (_peopleArray[i]->_directory == data)
			{
				//找到职工
				index = i;

				break;
			}
		}
	}
	else if (select == 3) {
		for (int i = 0; i < _attendance; i++)
		{
			if (_peopleArray[i]->_address == data)
			{
				//找到职工
				index = i;

				break;
			}
		}
	}



	return index;
}

