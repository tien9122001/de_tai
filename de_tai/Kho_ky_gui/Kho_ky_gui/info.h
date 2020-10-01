#pragma once
#include<string>
#include"items.h"
#include<iostream>
#include<fstream>
using namespace std;

typedef class info* stack_info;
class info :public items
{
private:
	string name;
	string address;
	string phone;
	string cmnd;
	
public:
	info* createNode(string name, string address, string phone, string cmnd);
	bool isEmpty(stack_info s);
	void read_file(stack_info& s, fstream& fstr);
	void add_member(stack_info& s, string name, string address, string phone, string cmnd);
	void show_info(stack_info s);
	void save_info(stack_info& s, fstream& ofstr);
	void delete_info(stack_info& s, string name);
	void change_info(stack_info& s,string name, string address, string phone, string cmnd);



	
	info* next = NULL;
};



