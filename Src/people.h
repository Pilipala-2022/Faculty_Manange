#pragma once
# include<string>
#include<iostream>
//class People
//{
//public:
//	std::string _name;		//����
//	std::string _sex;		//�Ա�
//	std::string _birthday;	//��������
//	std::string _workData;	//��������
//	std::string _qualification;	//ѧ��
//	std::string _duty;		//ְ��
//	std::string _address;	//סַ
//	std::string _directory;	//�绰
//
//	void show();
//};

struct PeopleData
{
	std::string _name;		//����
	std::string _sex;		//�Ա�
	std::string _birthday;	//��������
	std::string _workData;	//��������
	std::string _qualification;	//ѧ��
	std::string _duty;		//ְ��
	std::string _address;	//סַ
	std::string _directory;	//�绰
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