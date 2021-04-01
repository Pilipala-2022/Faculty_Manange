#include "manage.h"
Manage::Manage()
{
	// �򿪴洢�ļ�
}

Manage::~Manage()
{

}

void Manage::showMenu()
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

void Manage::errorChoice()
{
	printf("0.��������\n");
	system("pause");
	exit(0);
}

void Manage::showAllMessage()
{
	if (this ->_isEmpty) {
		printf("��¼Ϊ��");
	}
	else {
		for (int i = 0; i < this->_attendance; i++)
			//��̬
			this->_peopleArray[i]->show();
	}

	//�������������
	system("pause");
	system("cls");
}

void Manage::addMessage()
{
	int add_num = 0;
	printf("������Ҫ��ӵ�����");
	//scanf_s("%d", &add_num);
	//printf("%d", add_num);
	std::cin >> add_num;
	if (add_num >= 0) {
		printf("�������Ϊ%d\n", add_num);

		// ��������Ժ������
		int new_num = this->_attendance + add_num;

		// ����ϵͳ���µ��������ٿռ�
		People** new_space = new People * [new_num];

		//�Ƚ�ԭ�������ݿ������¿ռ�
		if (this->_peopleArray != NULL) {
			for (int i = 0; i < this->_attendance; i++) {
				new_space[i] = this->_peopleArray[i];
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
			new_space[this->_attendance + i] = people;
		}

		// �ͷ�ԭ�пռ�
		delete[] this->_peopleArray;

		// �����¿ռ�ָ��
		this->_peopleArray = new_space;

		// ���½�ְ������
		this->_attendance = new_num;

		//�����ļ���־
		this->_isEmpty = false;

		std::cout << "�ɹ����" << add_num << "����ְ����Ϣ" << std::endl;

		// ��������
		this->saveInfo();
	}
	else {
		printf("�������ݴ���\n");
	}
	//��������� �����ص��ϼ�Ŀ¼
	system("pause");
	system("cls");

}

void Manage::deleteMessage()
{
	if (this->_isEmpty)
	{
		std::cout << "��¼Ϊ�գ�" << std::endl;
	}
	else {
		//���ս�ְ������ɾ��
		std::cout << "��������Ҫɾ����ְ���ı�ţ�" << std::endl;
		std::string name;
		std::cin >> name;

		int index = this->inSearch(name);

		if (index != -1) //˵��ְ�����ڣ�����Ҫɾ����indexλ���ϵ�ְ��
		{

			for (int i = index; i < this->_attendance - 1; i++)
			{
				//����ǰ��
				this->_peopleArray[i] = this->_peopleArray[i + 1];
			}
			this->_attendance--; //���������м�¼��Ա����
			//����ͬ�����µ��ļ���
			this->saveInfo();

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

void Manage::findMessage()
{
	printf("4.���ҽ�ְ����Ϣ\n");
}

void Manage::modMessage()
{
	printf("5.�޸Ľ�ְ����Ϣ\n");
}

void Manage::clearMessage()
{
	printf("6.���������Ϣ\n");
}

void Manage::exitSystem()
{
	printf("7.�˳�ϵͳ\n");
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
			//�ҵ�ְ��
			index = i;

			break;
		}
	}

	return index;
}