#pragma once
# include<string>
#include<iostream>
class People
{
public:
	std::string _name;		//姓名
	std::string _sex;		//性别
	std::string _birthday;	//出生年月
	std::string _workData;	//工作年月
	std::string _qualification;	//学历
	std::string _duty;		//职务
	std::string _address;	//住址
	std::string _directory;	//电话

	void show();
};

