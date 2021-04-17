# include<stdio.h>
#include<iostream>
#include <fstream>
# include"people.h"

#define FILENAME "manageFile.txt"

// ϵͳ�е�����
int _attendance;

// ְ��ָ��
//People** _peopleArray;
PeopleData** _peopleArray;

// ��־�ļ��Ƿ�Ϊ��
bool _isEmpty;

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
		printf("�ļ�������\n");
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
		printf("�ļ�Ϊ�գ�\n");
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
	printf("ְ������Ϊ��%d", num);
	_attendance = num;

	//���ٿռ�
	_peopleArray = new PeopleData*[_attendance];
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

		//_peopleArray[i]->show();
		show(_peopleArray[i]);
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
	//std::cin >> add_num;
	scanf_s("%d", &add_num);
	if (add_num >= 0) {
		printf("�������Ϊ%d\n", add_num);

		// ��������Ժ������
		int new_num = _attendance + add_num;

		// ����ϵͳ���µ��������ٿռ�
		//People** new_space = new People * [new_num];
		PeopleData** new_space = new PeopleData *[_attendance];
		//PeopleData** new_space = new PeopleData * [new_num];

		//�Ƚ�ԭ�������ݿ������¿ռ�
		if (_peopleArray != NULL) {
			for (int i = 0; i < _attendance; i++) {
				new_space[i] = _peopleArray[i];
			}
		}

		// ���������
		for (int i = 0; i < add_num; i++) {

			//People* people = new People;
			PeopleData *people = new PeopleData;

			printf("�������%dλ��ְԱ������", i+1);
			std::cin >> people->_name;

			printf("�������%dλ��ְԱ���Ա�", i + 1);
			std::cin >> people->_sex;

			printf("�������%dλ��ְԱ�ĳ�������", i + 1);
			std::cin >> people->_birthday;

			printf("�������%dλ��ְԱ�Ĺ�������", i + 1);
			std::cin >> people->_workData;

			printf("�������%dλ��ְԱ��ѧ��", i + 1);
			std::cin >> people->_qualification;

			printf("�������%dλ��ְԱ��ְ��", i + 1);
			std::cin >> people->_duty;

			printf("�������%dλ��ְԱ��סַ", i + 1);
			std::cin >> people->_address;

			printf("�������%dλ��ְԱ�ĵ绰", i + 1);
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

		printf("�ɹ����%d����ְ����Ϣ\n", add_num);

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
		printf("��¼Ϊ�գ�\n");
	}
	else {
		printf("��������ҵķ�ʽ��\n");
		printf("1������������ \n");
		printf("2�����绰���� \n");
		printf("3����סַ���� \n");

		int select = 0;
		std::string data;
		scanf_s("%d", &select);
		if (select == 1) {
			//���ս�ְ������ɾ��
			printf("��������Ҫɾ����ְ����������\n");
			std::cin >> data;
		}
		else if (select == 2) {
			//���ս�ְ���绰ɾ��
			printf("��������Ҫɾ����ְ���ĵ绰��\n");
			std::cin >> data;
		}
		else if (select == 2) {
			//���ս�ְ��סַɾ��
			printf("��������Ҫɾ����ְ���ĵ�ַ��\n");
			std::cin >> data;
		}
		int index = inSearch(select, data);
		if (index == -1) {
			printf("ɾ��ʧ�ܣ�δ�ҵ���ְ��");
		}
		while (index != -1) {

			for (int i = index; i < _attendance - 1; i++)
				{
					//����ǰ��
					_peopleArray[i] = _peopleArray[i + 1];
				}
			_attendance--; //���������м�¼��Ա����
			//����ͬ�����µ��ļ���
			saveInfo();

			index = inSearch(select, data);
			//std::cout << "ɾ���ɹ���" << std::endl;
			printf("ɾ���ɹ���\n");
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
		//std::cout << "��¼Ϊ�գ�" << std::endl;
		printf("��¼Ϊ�գ�");
	}
	else {
		printf("��������ҵķ�ʽ��\n");
		printf("1������������ \n");
		printf("2�����绰���� \n");
		printf("3����סַ���� \n");

		int select = 0;
		std::string data;
		std::cin >> select;
		if (select == 1) {
			//���ս�ְ������ɾ��
			printf("��������Ҫ���ҽ�ְ����������\n");
			std::cin >> data;
		}
		else if (select == 2) {
			//���ս�ְ���绰ɾ��
			printf("��������Ҫ���ҽ�ְ���ĵ绰��\n");
			std::cin >> data;
		}
		else if (select == 3) {
			//���ս�ְ��סַɾ��
			printf("��������Ҫ���ҽ�ְ���ĵ�ַ��\n");
			std::cin >> data;
		}

		int index = inSearch(select, data);
		
		if (index == -1)
			printf("����ʧ�ܣ����޴���\n");


		while (index != -1) {
			//�ҵ�ְ��
			printf("���ҳɹ�����ְ����Ϣ���£�\n");
			show(_peopleArray[index]);
			index = inSearch(select, data);
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
		printf("�ļ������ڻ��¼Ϊ�գ�\n");
	}
	else {
		printf("��������ҵķ�ʽ����\n");
		printf("1������������\n");
		printf("2�����绰����\n");
		printf("3����סַ����\n");

		int select = 0;
		std::string data;
		std::cin >> select;
		if (select == 1) {
			//���ս�ְ����������
			printf("��������Ҫ�޸ĵĽ�ְ����������\n");
			std::cin >> data;
		}
		else if (select == 2) {
			//���ս�ְ���绰����
			printf("��������Ҫ�޸ĵĽ�ְ���ĵ绰��\n");
			std::cin >> data;
		}
		else if (select == 3) {
			//���ս�ְ��סַɾ��
			printf("��������Ҫ�޸ĵĽ�ְ���ĵ�ַ��\n");
			std::cin >> data;
		}

		int index = inSearch(select, data);

		if (index != -1) {
			printf("��������Ҫ�޸ĵ���Ϣ�������������ѡ��\n");
			printf("1.����\n");
			printf("2.�Ա�\n");
			printf("3.��������\n");
			printf("4.��������\n");
			printf("5.ѧ��\n");
			printf("6.ְ��\n");
			printf("7.סַ\n");
			printf("8.�绰\n");

			int choice;
			std::string mod_data;
			std::cin >> choice;
			if (choice == 1) {
				printf("�������޸ĺ������\n");
				std::cin >> mod_data;
				_peopleArray[index]->_name = mod_data;
			}
			else if (choice == 2) {
				printf("�������޸ĺ���Ա�\n");
				std::cin >> mod_data;
				_peopleArray[index]->_sex = mod_data;
			}
			else if (choice == 3) {
				printf("�������޸ĺ�ĳ�������\n");
				std::cin >> mod_data;
				_peopleArray[index]->_birthday = mod_data;
			}
			else if (choice == 4) {
				printf("�������޸ĺ�Ĺ�������\n");
				std::cin >> mod_data;
				_peopleArray[index]->_workData = mod_data;
			}
			else if (choice == 5) {
				printf("�������޸ĺ��ѧ��\n");
				std::cin >> mod_data;
				_peopleArray[index]->_qualification = mod_data;
			}
			else if (choice == 6) {
				printf("�������޸ĺ��ְ��\n");
				std::cin >> mod_data;
				_peopleArray[index]->_duty = mod_data;
			}
			else if (choice == 7) {
				printf("�������޸ĺ��סַ\n");
				std::cin >> mod_data;
				_peopleArray[index]->_address = mod_data;
			}
			else if (choice == 8) {
				printf("�������޸ĺ�ĵ绰\n");
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
	printf("ȷ����գ�\n");
	printf("1��ȷ��\n");
	printf("2������\n");

	int select = 0;
	scanf_s("%d", &select);

	if (select == 1)
	{
		//����ļ�
		std::ofstream ofs(FILENAME, std::ios::trunc); // ɾ���ļ������´���
		ofs.close();

		if (_peopleArray != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < _attendance; i++)
			{
				delete _peopleArray;
				_peopleArray = NULL;
			}

			//ɾ����������ָ��
			delete[] _peopleArray;
			_peopleArray = NULL;
			_attendance = 0;
			_isEmpty = true;
		}

		printf("��ճɹ���\n");
	}

	system("pause");
	system("cls");
}

void exitSystem()
{
	system("pause");
	exit(0); // �˳�����
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

