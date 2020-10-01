#include "info.h"

#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

bool info::isEmpty(stack_info s)
{
	return (s == NULL);
}
info* info::createNode(string name, string address, string phone, string cmnd)
{
	info* p = new info;
	p->name = name;
	p->address = address;
	p->phone = phone;
	p->cmnd = cmnd;
	p->next = NULL;
	return p;

}
void info::read_file(stack_info& s, fstream& fstr)
{
	do
	{
		string name;
		string address;
		string phone;
		string cmnd;
		getline(fstr, name);
		getline(fstr, address);
		getline(fstr, phone);
		getline(fstr, cmnd);
		if (name == "")
			break;
		info* ptr = createNode(name, address, phone, cmnd);
		if (isEmpty(s))
		{
			s = ptr;
		}
		else
		{
			ptr->next = s;
			s = ptr;
		}
		
		
	} while (!fstr.eof());

}
void info::add_member(stack_info& s, string name, string address, string phone, string cmnd)
{
	info* ptr = createNode(name, address, phone, cmnd);
	if (isEmpty(s))
	{
		s = ptr;
	}
	else
	{
		ptr->next = s;
		s = ptr;
	}
}
void info::show_info(stack_info s)
{
	info* ptr = s;

	cout << setfill('=') << setw(80) << "=" << endl;
	cout << setfill(' ');
	cout << setw(25) << left << "Ten" << setw(25) << left << "Dia chi" << setw(25)
		<< setw(15) << "SDT" << setw(25) << left << "CMND" << endl;
	cout << setfill('=') << setw(80) << "=" << endl;
	cout << setfill(' ');
	while(!isEmpty(s))
	{
		cout << setw(25) << left << ptr->name << setw(25) << left << ptr->address
			<< setw(15) << left << ptr->phone << setw(25) << ptr->cmnd << endl;
		if (isEmpty(s))
		{
			ptr = ptr->next;
		}
		else
			break;
	}
	
}
void info::save_info(stack_info& s, fstream& ofstr)
{
	while (!isEmpty(s))
	{
		info* ptr = s;
		string name = ptr->name;
		string address = ptr->address;
		string phone = ptr->phone;
		string cmnd = ptr->cmnd;
		ofstr << name << endl << address << endl << phone << endl << cmnd << endl;
		s = s->next;
		delete(ptr);
	}
}
void info::delete_info(stack_info& s, string name)
{
	info* ptr = s;
	info* ptr1 = s->next;
	while (!isEmpty(ptr1))
	{
		if (s->name == name)
		{
			info* ptr2 = ptr;
			s = s->next;
			delete(ptr2);
			cout << "Da xoa " << name << endl;
			break;
		}
		if (name == ptr1->name)
		{
			ptr->next = ptr1->next;
			delete(ptr1);
			cout << "Da xoa " << name << endl;
			break;
		}
		ptr = ptr->next;
		ptr1 = ptr1->next;
		if (isEmpty(ptr))
		{
			cout << "Khong tim thay ten " << name << endl;
		}
	}
}
void info::change_info(stack_info& s,string name, string address, string phone, string cmnd)
{
	info* ptr = s;
	while (!isEmpty(ptr))
	{
		if (ptr->name == name)
		{
			ptr->address = address;
			ptr->phone = phone;
			ptr->cmnd = cmnd;
			break;
		}
		ptr=ptr->next;
		if (isEmpty(ptr))
			cout << "Khong tim thay ten " << name;

	}
}