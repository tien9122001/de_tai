#include "items.h"
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

bool items::isEmpty(stack_items s)
{
	return (s == NULL);
}
items* items::createNode(string phanLoai, int khoiLuong_T, string tenSanPham, int soLuong, double giaTri, int code_items)
{
	items* ptr = new items;
	ptr->phanLoai = phanLoai;
	ptr->tenSanPham = tenSanPham;
	ptr->soLuong = soLuong;
	ptr->giaTri = giaTri;
	ptr->code_items = code_items;
	return ptr;
}
void items::add_items(stack_items& s, string phanLoai, int khoiLuong_T, string tenSanPham, int soLuong, double giaTri, int code_items)
{
	items* ptr = createNode(phanLoai, khoiLuong_T, tenSanPham, soLuong, giaTri, code_items);
	if (!isEmpty(s))
	{
		s = ptr;
	}
	else
	{
		ptr->next = s;
		s = ptr;
	}
}
void items::read_items(fstream& ifstr, stack_items& s)
{
	string phanLoai;
	int khoiLuong_T;
	string tenSanPham;
	int soLuong;
	double giaTri;
	int code_items;
	getline(ifstr, phanLoai);
	ifstr >> khoiLuong_T;
	getline(ifstr, tenSanPham);
	ifstr >> soLuong;
	ifstr >> giaTri;
	ifstr >> code_items;
	items* ptr = createNode(phanLoai, khoiLuong_T, tenSanPham, soLuong, giaTri, code_items);
	if (s == NULL)
	{
		s = ptr;
	}
	else
	{
		ptr->next = s;
		s = ptr;
	}
}
void items::save_items(fstream& ofstr, stack_items& s)
{
	string phanLoai;
	int khoiLuong_T;
	string tenSanPham;
	int soLuong;
	double giaTri;
	int code_items;
	if (!isEmpty(s))
	{
		items* ptr = s;
		phanLoai = ptr->phanLoai;
		khoiLuong_T = ptr->khoiLuong_T;
		tenSanPham = ptr->tenSanPham;
		soLuong = ptr->soLuong;
		giaTri = ptr->giaTri;
		code_items = ptr->code_items;
		ofstr << phanLoai << endl << khoiLuong_T << endl << tenSanPham << endl << soLuong << endl << giaTri << endl << code_items;
		s = s->next;
		delete(ptr);
	}
}
void items::show_items(stack_items s)
{
	items* ptr = s;

	cout << setfill('=') << setw(80) << "=" << endl;
	cout << setfill(' ');
	cout << setw(30) << left << "Ten san pham " << setw(30) << left << "Khoi luong" << setw(30)
		<< setw(30) << "Phan loai " << setw(30) << left << "So luong" << setw(30) << left << "Gia tri " << setw(30) << left << "Code_items" << endl;
	cout << setfill('=') << setw(80) << "=" << endl;
	cout << setfill(' ');
	while (!isEmpty(s))
	{
		cout << setw(30) << left << ptr->tenSanPham << setw(30) << left << ptr->khoiLuong_T
			<< setw(30) << left << ptr->phanLoai << setw(30) << left << ptr->soLuong << setw(30) << left << ptr->giaTri 
			<< setw(30) << left << ptr->code_items << endl;
		if (isEmpty(s))
		{
			ptr = ptr->next;
		}
		else
			break;
	}
}
void items::delete_items(stack_items& s, string name)
{
	items* ptr = s;
	items* ptr1 = s->next;
	while (!isEmpty(ptr1))
	{
		if (s->tenSanPham == name)
		{
			items* ptr2 = ptr;
			s = s->next;
			delete(ptr2);
			cout << "Da xoa " << name << endl;
			break;
		}
		if (name == ptr1->tenSanPham)
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
void items::change_items(stack_items& s, string phanLoai, int khoiLuong, string tenSanPham, int soLuong, double giaTri, int code_items)
{
	items* ptr = s;
	while (!isEmpty(ptr))
	{
		if (ptr->tenSanPham == tenSanPham)
		{
			ptr->phanLoai = phanLoai;
			ptr->khoiLuong_T = khoiLuong;
			ptr->soLuong = soLuong;
			ptr->giaTri = giaTri;
			ptr->code_items = code_items;
			break;
		}
		ptr = ptr->next;
		if (isEmpty(ptr))
			cout << "Khong tim thay ten " << tenSanPham;

	}
}
