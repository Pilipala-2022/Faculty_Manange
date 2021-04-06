# include<stdio.h>
#include<iostream>
#include <fstream>
# include"src/people.h"

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
extern int inSearch(std::string name);

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
	printf("0.��������\n");
	system("pause");
	exit(0);
}

void showAllMessage()
{
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
		//���ս�ְ������ɾ��
		std::cout << "��������Ҫɾ����ְ���ı�ţ�" << std::endl;
		std::string name;
		std::cin >> name;

		int index = inSearch(name);

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
	printf("4.���ҽ�ְ����Ϣ\n");
}

void modMessage()
{
	printf("5.�޸Ľ�ְ����Ϣ\n");
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

int inSearch(std::string name) {

	int index = -1;

	for (int i = 0; i < _attendance; i++)
	{
		if (_peopleArray[i]->_name == name)
		{
			//�ҵ�ְ��
			index = i;

			break;
		}
	}

	return index;
}

