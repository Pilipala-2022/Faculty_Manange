#pragma once
# include<string>
#include<iostream>
//class People
//{
//public:
//	std::string _name;		//姓名
//	std::string _sex;		//性别
//	std::string _birthday;	//出生年月
//	std::string _workData;	//工作年月
//	std::string _qualification;	//学历
//	std::string _duty;		//职务
//	std::string _address;	//住址
//	std::string _directory;	//电话
//
//	void show();
//};

struct PeopleData
{
	std::string _name;		//姓名
	std::string _sex;		//性别
	std::string _birthday;	//出生年月
	std::string _workData;	//工作年月
	std::string _qualification;	//学历
	std::string _duty;		//职务
	std::string _address;	//住址
	std::string _directory;	//电话
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