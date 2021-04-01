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

	void errorChoice();     //0.��������

	void showAllMessage();  //1.��ʾ��ְ����Ϣ

	void addMessage();  //2.���ӽ�ְ����Ϣ

	void deleteMessage();  //3.ɾ����ְ����Ϣ

	void findMessage();  //4.���ҽ�ְ����Ϣ

	void modMessage();  //5.�޸Ľ�ְ����Ϣ

	void clearMessage();  //6.���������Ϣ

	void exitSystem();  //7.�˳�ϵͳ

private:
	// ϵͳ�е�����
	int _attendance;

	// ְ��ָ��
	People** _peopleArray;

	// ��־�ļ��Ƿ�Ϊ��
	bool _isEmpty;

	void saveInfo();


};

