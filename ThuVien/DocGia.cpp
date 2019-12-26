#include <iostream>
#include <fstream>
using namespace std;

#include "DocGia.h"

string DocGia::Get_HoTen()
{
	return _hoTen;
}

string DocGia::Get_MaDocGia()
{
	return _maDocGia;
}

Ngay DocGia::Get_NgaySinh()
{
	return _ngaySinh;
}

void DocGia::Set_HoTen(const string x)
{
	_hoTen = x;
}

void DocGia::Set_MaDocGia(const string x)
{
	_maDocGia = x;
}

void DocGia::Set_NgaySinh(const Ngay x)
{
	_ngaySinh = x;
}

void DocGia::Nhap()
{
	cin.ignore();
	cout << "Nhap ten doc gia: ";
	getline(cin, _hoTen);

	cout << "Nhap ma doc gia: ";
	getline(cin, _maDocGia);

	cout << "Nhap ngay sinh: ";
	_ngaySinh.Nhap();

}

void DocGia::Xuat()
{
	cout << "\nTen doc gia: " << _hoTen;
	cout << "\nMa doc gia: " << _maDocGia;
	cout << "\nNgay sinh: ";
	_ngaySinh.Xuat();
}

DocGia::DocGia()
{
}

DocGia::~DocGia()
{
}