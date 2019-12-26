#include <iostream>
#include <fstream>
using namespace std;

#include "SachTiengViet.h"

string SachTiengViet::Get_MaSach()
{
	return _maSach;
}

string SachTiengViet::Get_TenSach()
{
	return _tenSach;
}

string SachTiengViet::Get_TacGia()
{
	return _tacGia;
}

string SachTiengViet::Get_NhaXuatBan()
{
	return _nhaXuatBan;
}

int SachTiengViet::Get_GiaSach()
{
	return _giaSach;
}

int SachTiengViet::Get_LoaiSach()
{
	return _loaiSach;
}

void SachTiengViet::Set_MaSach(const string x)
{
	_maSach = x;
}

void SachTiengViet::Set_TenSach(const string x)
{
	_tenSach = x;
}

void SachTiengViet::Set_TacGia(const string x)
{
	_tacGia = x;
}

void SachTiengViet::Set_NhaXuatBan(const string x)
{
	_nhaXuatBan = x;
}

void SachTiengViet::Set_GiaSach(const int x)
{
	_giaSach = x;
}

void SachTiengViet::Set_LoaiSach(const int x)
{
	_loaiSach = x;
}

void SachTiengViet::Nhap()
{
	cin.ignore();

	cout << "Nhap ten sach: ";
	getline(cin, _tenSach);

	cout << "Nhap tac gia: ";
	getline(cin, _tacGia);

	cout << "Nhap nha xuat ban: ";
	getline(cin, _nhaXuatBan);

	do
	{
		cout << "Nhap gia ban sach: ";
		cin >> _giaSach;

		if (_giaSach <= 0)
			cout << "Khong hop le. Xin kiem tra lai!\n";

	} while (_giaSach <= 0);
}

void SachTiengViet::Xuat()
{
	cout << "\nMa sach: " << _maSach;
	cout << "\nTen sach: " << _tenSach;
	cout << "\nTac gia: " << _tacGia;
	cout << "\nNha xuat ban: " << _nhaXuatBan;
	cout << "\nGia ban sach: " << _giaSach << " VND";
}

SachTiengViet::SachTiengViet()
{
}

SachTiengViet::~SachTiengViet()
{
}
