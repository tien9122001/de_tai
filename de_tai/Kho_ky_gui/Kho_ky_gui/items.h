#pragma once
#include<iostream>
#include<fstream>
using namespace std;
typedef class items* stack_items;
class items
{
private:
	string phanLoai;
	int khoiLuong_T;
	string tenSanPham;
	int soLuong;
	double giaTri;
	int code_items;
public:
	void add_items(stack_items& s, string phanLoai, int khoiLuong_T, string tenSanPham, int soLuong, double giaTri, int code_items);
	void show_items(stack_items s);
	bool isEmpty(stack_items s);
	items* createNode(string phanLoai, int khoiLuong_T, string tenSanPham, int soLuong, double giaTri, int code_items);
	void read_items(fstream& ifstr, stack_items& s);
	void save_items(fstream& ofstr, stack_items& s);
	void delete_items(stack_items& s, string name);
	void change_items(stack_items& s, string phanLoai, int khoiLuong, string tenSanPham, int soLuong, double giaTri, int code_items);
	items* next;
};

