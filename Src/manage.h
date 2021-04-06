# include<stdio.h>
#include<iostream>
#include <fstream>
# include"people.h"

#define FILENAME "manageFile.txt"

// ϵͳ�е�����
int _attendance;

// ְ��ָ��
People** _peopleArray;
//PeopleData** _peopleArray;

// ��־�ļ��Ƿ�Ϊ��
bool _isEmpty;

//struct PeopleData
//{
//	std::string _name;		//����
//	std::string _sex;		//�Ա�
//	std::string _birthday;	//��������
//	std::string _workData;	//��������
//	std::string _qualification;	//ѧ��
//	std::string _duty;		//ְ��
//	std::string _address;	//סַ
//	std::string _directory;	//�绰
//};

extern void saveInfo();
extern int inSearch(int select, std::string data);
extern int getAttendance();
extern void initPeople();

int getAttendance() {
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in); //���ļ�  ��

	std::string name;		//����
	std::string sex;		//�Ա�
	std::string birthday;	//��������
	std::string workData;	//��������
	std::string qualification;	//ѧ��
	std::string duty;		//ְ��
	std::string address;	//סַ
	std::string directory;	//�绰

	int num = 0;

	while (ifs >> name && ifs >> sex && ifs >> birthday && ifs >> workData && ifs >> qualification && ifs >> duty && ifs >> address && ifs >> directory)
	{
		//ͳ����������
		num++;
	}

	return num;
}

void initPeople() {
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	std::string name;		//����
	std::string sex;		//�Ա�
	std::string birthday;	//��������
	std::string workData;	//��������
	std::string qualification;	//ѧ��
	std::string duty;		//ְ��
	std::string address;	//סַ
	std::string directory;	//�绰

	int index = 0;
	while (ifs >> name && ifs >> sex && ifs >> birthday && ifs >> workData && ifs >> qualification && ifs >> duty && ifs >> address && ifs >> directory) {
		People* people = new People;
		people->_name = name;
		people->_sex = sex;
		people->_birthday = birthday;
		people->_workData = workData;
		people->_qualification = qualification;
		people->_duty = duty;
		people->_address = address;
		people->_directory = directory;
		_peopleArray[index] = people;
		//std::cout << "name = " << name << std::endl;
		index++;
	}
	//�ر��ļ�
	ifs.close();
}

void readData() {
	//1���ļ�������

	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in); // ���ļ�

	if (!ifs.is_open())
	{
		std::cout << "�ļ�������" << std::endl;
		//��ʼ������
		//��ʼ����¼����
		_attendance = 0;
		//��ʼ������ָ�� 
		_peopleArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		_isEmpty = true;
		ifs.close();
		return;
	}

	//2���ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		std::cout << "�ļ�Ϊ�գ�" << std::endl;
		//��ʼ����¼����
		_attendance = 0;
		//��ʼ������ָ�� 
		_peopleArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		_isEmpty = true;
		ifs.close();
		return;
	}

	//3���ļ����ڣ����Ҽ�¼����
	int num = getAttendance();
	std::cout << "ְ������Ϊ�� " << num << std::endl;
	_attendance = num;

	//���ٿռ�
	_peopleArray = new People * [_attendance];
	//���ļ��е����� ���浽������
	initPeople();



}

void showMenu()
{
	// ��ʾ�˵�
	printf("%*c", 30, 0);
	printf("************************************************************\n");
	printf("%*c", 30, 0);
	printf("************************************************************\n");
	printf("%*c", 30, 0);
	printf("**********************��ְ������ϵͳ************************\n");
	printf("%*c", 30, 0);
	printf("**********************1.��ʾ��ְ����Ϣ**********************\n");
	printf("%*c", 30, 0);
	printf("**********************2.���ӽ�ְ����Ϣ**********************\n");
	printf("%*c", 30, 0);
	printf("**********************3.ɾ����ְ����Ϣ**********************\n");
	printf("%*c", 30, 0);
	printf("**********************4.���ҽ�ְ����Ϣ**********************\n");
	printf("%*c", 30, 0);
	printf("**********************5.�޸Ľ�ְ����Ϣ**********************\n");
	printf("%*c", 30, 0);
	printf("**********************6.���������Ϣ************************\n");
	printf("%*c", 30, 0);
	printf("**********************7.�˳�ϵͳ****************************\n");
	printf("%*c", 30, 0);
	printf("************************************************************\n\n\n");
	printf("%*c", 30, 0);
	printf("**********************(�������ѡ�����)************************\n");

}

void errorChoice()
{
	printf("��������\n");
	system("pause");
	exit(0);
}

void showAllMessage()
{
	//std::cout << "attendance = " << _attendance << std::endl;
	if (_isEmpty) {
		printf("��¼Ϊ��");
	}
	else {
		for (int i = 0; i < _attendance; i++)

			_peopleArray[i]->show();
	}

	//�������������
	system("pause");
	system("cls");
}

void addMessage()
{
	int add_num = 0;
	printf("������Ҫ��ӵ�����");
	//scanf_s("%d", &add_num);
	//printf("%d", add_num);
	std::cin >> add_num;
	if (add_num >= 0) {
		printf("�������Ϊ%d\n", add_num);

		// ��������Ժ������
		int new_num = _attendance + add_num;

		// ����ϵͳ���µ��������ٿռ�
		People** new_space = new People * [new_num];
		//PeopleData** new_space = new PeopleData * [new_num];

		//�Ƚ�ԭ�������ݿ������¿ռ�
		if (_peopleArray != NULL) {
			for (int i = 0; i < _attendance; i++) {
				new_space[i] = _peopleArray[i];
			}
		}

		// ���������
		for (int i = 0; i < add_num; i++) {

			People* people = new People;

			std::cout << "�������" << i + 1 << "λ��ְԱ������" << std::endl;
			std::cin >> people->_name;
			std::cout << "�������" << i + 1 << "λ��ְԱ���Ա�" << std::endl;
			std::cin >> people->_sex;
			std::cout << "�������" << i + 1 << "λ��ְԱ�ĳ�������" << std::endl;
			std::cin >> people->_birthday;
			std::cout << "�������" << i + 1 << "λ��ְԱ�Ĺ�������" << std::endl;
			std::cin >> people->_workData;
			std::cout << "�������" << i + 1 << "λ��ְԱ��ѧ��" << std::endl;
			std::cin >> people->_qualification;
			std::cout << "�������" << i + 1 << "λ��ְԱ��ְ��" << std::endl;
			std::cin >> people->_duty;
			std::cout << "�������" << i + 1 << "λ��ְԱ��סַ" << std::endl;
			std::cin >> people->_address;
			std::cout << "�������" << i + 1 << "λ��ְԱ�ĵ绰" << std::endl;
			std::cin >> people->_directory;

			//����Ϣ���浽������
			new_space[_attendance + i] = people;
		}

		// �ͷ�ԭ�пռ�
		delete[] _peopleArray;

		// �����¿ռ�ָ��
		_peopleArray = new_space;

		// ���½�ְ������
		_attendance = new_num;

		//�����ļ���־
		_isEmpty = false;

		std::cout << "�ɹ����" << add_num << "����ְ����Ϣ" << std::endl;

		// ��������
		saveInfo();
	}
	else {
		printf("�������ݴ���\n");
	}

	system("pause");
	system("cls");

}

void deleteMessage()
{
	if (_isEmpty)
	{
		std::cout << "��¼Ϊ�գ�" << std::endl;
	}
	else {
		std::cout << "��������ҵķ�ʽ��" << std::endl;
		std::cout << "1������������ " << std::endl;
		std::cout << "2�����绰���� " << std::endl;
		std::cout << "2����סַ���� " << std::endl;

		int select = 0;
		std::string data;
		std::cin >> select;
		if (select == 1) {
			//���ս�ְ������ɾ��
			std::cout << "��������Ҫɾ����ְ����������" << std::endl;
			std::cin >> data;
		}
		else if (select == 2) {
			//���ս�ְ���绰ɾ��
			std::cout << "��������Ҫɾ����ְ���ĵ绰��" << std::endl;
			std::cin >> data;
		}
		else if (select == 2) {
			//���ս�ְ��סַɾ��
			std::cout << "��������Ҫɾ����ְ���ĵ�ַ��" << std::endl;
			std::cin >> data;
		}

		int index = inSearch(select,data);

		if (index != -1) //˵��ְ�����ڣ�����Ҫɾ����indexλ���ϵ�ְ��
		{

			for (int i = index; i < _attendance - 1; i++)
			{
				//����ǰ��
				_peopleArray[i] = _peopleArray[i + 1];
			}
			_attendance--; //���������м�¼��Ա����
			//����ͬ�����µ��ļ���
			saveInfo();

			std::cout << "ɾ���ɹ���" << std::endl;
		}
		else
		{
			std::cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << std::endl;
		}
	}
	//�������������
	system("pause");
	system("cls");
}

void findMessage()
{
	if (_isEmpty)
	{
		std::cout << "��¼Ϊ�գ�" << std::endl;
	}
	else {
		std::cout << "��������ҵķ�ʽ��" << std::endl;
		std::cout << "1������������ " << std::endl;
		std::cout << "2�����绰���� " << std::endl;
		std::cout << "3����סַ���� " << std::endl;

		int select = 0;
		std::string data;
		std::cin >> select;
		if (select == 1) {
			//���ս�ְ������ɾ��
			std::cout << "��������Ҫɾ����ְ����������" << std::endl;
			std::cin >> data;
		}
		else if (select == 2) {
			//���ս�ְ���绰ɾ��
			std::cout << "��������Ҫɾ����ְ���ĵ绰��" << std::endl;
			std::cin >> data;
		}
		else if (select == 3) {
			//���ս�ְ��סַɾ��
			std::cout << "��������Ҫɾ����ְ���ĵ�ַ��" << std::endl;
			std::cin >> data;
		}

		int index = inSearch(select, data);

		if (index != -1)
		{
			//�ҵ�ְ��
			std::cout << "���ҳɹ�����ְ����Ϣ���£�" << std::endl;
			_peopleArray[index]->show();
		}
		else
		{
			std::cout << "����ʧ�ܣ����޴���" << std::endl;
		}
	}
	//�������������
	system("pause");
	system("cls");
}

void modMessage()
{
	if (_isEmpty)
	{
		std::cout << "�ļ������ڻ��¼Ϊ�գ�" << std::endl;
	}
	else {
		std::cout << "��������ҵķ�ʽ��" << std::endl;
		std::cout << "1������������ " << std::endl;
		std::cout << "2�����绰���� " << std::endl;
		std::cout << "3����סַ���� " << std::endl;

		int select = 0;
		std::string data;
		std::cin >> select;
		if (select == 1) {
			//���ս�ְ����������
			std::cout << "��������Ҫ�޸ĵĽ�ְ����������" << std::endl;
			std::cin >> data;
		}
		else if (select == 2) {
			//���ս�ְ���绰����
			std::cout << "��������Ҫ�޸ĵĽ�ְ���ĵ绰��" << std::endl;
			std::cin >> data;
		}
		else if (select == 3) {
			//���ս�ְ��סַɾ��
			std::cout << "��������Ҫ�޸ĵĽ�ְ���ĵ�ַ��" << std::endl;
			std::cin >> data;
		}

		int index = inSearch(select, data);

		if (index != -1) {
			std::cout << "��������Ҫ�޸ĵ���Ϣ" << std::endl;
			std::cout << "1.����" << std::endl;
			std::cout << "2.�Ա�" << std::endl;
			std::cout << "3.��������" << std::endl;
			std::cout << "4.��������" << std::endl;
			std::cout << "5.ѧ��" << std::endl;
			std::cout << "6.ְ��" << std::endl;
			std::cout << "7.סַ" << std::endl;
			std::cout << "8.�绰" << std::endl;

			int choice;
			std::string mod_data;
			std::cin >> choice;
			if (choice == 1) {
				std::cout << "�������޸ĺ������" << std::endl;
				std::cin >> mod_data;
				_peopleArray[index]->_name = mod_data;
			}
			else if (choice == 2) {
				std::cout << "�������޸ĺ���Ա�" << std::endl;
				std::cin >> mod_data;
				_peopleArray[index]->_sex = mod_data;
			}
			else if (choice == 3) {
				std::cout << "�������޸ĺ�ĳ�������" << std::endl;
				std::cin >> mod_data;
				_peopleArray[index]->_birthday = mod_data;
			}
			else if (choice == 4) {
				std::cout << "�������޸ĺ�Ĺ�������" << std::endl;
				std::cin >> mod_data;
				_peopleArray[index]->_workData = mod_data;
			}
			else if (choice == 5) {
				std::cout << "�������޸ĺ��ѧ��" << std::endl;
				std::cin >> mod_data;
				_peopleArray[index]->_qualification = mod_data;
			}
			else if (choice == 6) {
				std::cout << "�������޸ĺ��ְ��" << std::endl;
				std::cin >> mod_data;
				_peopleArray[index]->_duty = mod_data;
			}
			else if (choice == 7) {
				std::cout << "�������޸ĺ��סַ" << std::endl;
				std::cin >> mod_data;
				_peopleArray[index]->_address = mod_data;
			}
			else if (choice == 8) {
				std::cout << "�������޸ĺ�ĵ绰" << std::endl;
				std::cin >> mod_data;
				_peopleArray[index]->_directory = mod_data;
			}
		}

	}
	//�������������
	system("pause");
	system("cls");
}

void clearMessage()
{
	printf("6.���������Ϣ\n");
}

void exitSystem()
{
	printf("7.�˳�ϵͳ\n");
}

void saveInfo() {
	std::ofstream ofs;
	ofs.open(FILENAME, std::ios::out);

	for (int i = 0; i < _attendance; i++) {

		ofs
			<< _peopleArray[i]->_name << "  "
			<< _peopleArray[i]->_sex << "  "
			<< _peopleArray[i]->_birthday << "  "
			<< _peopleArray[i]->_workData << "  "
			<< _peopleArray[i]->_qualification << "  "
			<< _peopleArray[i]->_duty << "  "
			<< _peopleArray[i]->_address << "  "
			<< _peopleArray[i]->_directory << std::endl;
	}
	ofs.close();
}

int inSearch(int select, std::string data) {

	int index = -1;

	if (select == 1)
	{
		for (int i = 0; i < _attendance; i++)
		{
			if (_peopleArray[i]->_name == data)
			{
				//�ҵ�ְ��
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
				//�ҵ�ְ��
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
				//�ҵ�ְ��
				index = i;

				break;
			}
		}
	}



	return index;
}

