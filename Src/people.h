#pragma once
# include<string>
#include<iostream>
using namespace std;

struct PeopleData
{
	string _name;		//姓名
	string _sex;		//性别
	string _birthday;	//出生年月
	string _workData;	//工作年月
	string _qualification;	//学历
	string _duty;		//职务
	string _address;	//住址
	string _directory;	//电话
};

void show(PeopleData* people) {
	std::cout << "姓名  " << people->_name
		<< "性别" << people->_sex
		<< "\t出生年月" << people->_birthday
		<< "\t工作年月" << people->_workData
		<< "\t学历" << people->_qualification
		<< "\t职务" << people->_duty
		<< "\t住址" << people->_address
		<< "\t电话" << people->_directory << std::endl;
}