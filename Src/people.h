#pragma once
# include<string>
#include<iostream>
using namespace std;

struct PeopleData
{
	string _name;		//����
	string _sex;		//�Ա�
	string _birthday;	//��������
	string _workData;	//��������
	string _qualification;	//ѧ��
	string _duty;		//ְ��
	string _address;	//סַ
	string _directory;	//�绰
};

void show(PeopleData* people) {
	std::cout << "����  " << people->_name
		<< "�Ա�" << people->_sex
		<< "\t��������" << people->_birthday
		<< "\t��������" << people->_workData
		<< "\tѧ��" << people->_qualification
		<< "\tְ��" << people->_duty
		<< "\tסַ" << people->_address
		<< "\t�绰" << people->_directory << std::endl;
}