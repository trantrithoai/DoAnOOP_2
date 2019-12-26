#pragma once
#ifndef _SACHTIENGVIET_H
#define _SACHTIENGVIET_H

#include <string>
using namespace std;

class SachTiengViet
{
private:
	string _maSach;
	string _tenSach;
	string _tacGia;
	string _nhaXuatBan;
	int _giaSach;

	int _loaiSach; // 1.Sách Tiếng Việt, 2.Sách Ngoại Văn
public:
	string Get_MaSach();
	string Get_TenSach();
	string Get_TacGia();
	string Get_NhaXuatBan();
	int Get_GiaSach();
	int Get_LoaiSach();

	void Set_MaSach(const string x);
	void Set_TenSach(const string x);
	void Set_TacGia(const string x);
	void Set_NhaXuatBan(const string x);
	void Set_GiaSach(const int x);
	void Set_LoaiSach(const int x);
public:
	virtual void Nhap();
	virtual void Xuat();

	//virtual void GhiFile();
public:
	SachTiengViet();
	virtual~SachTiengViet();
};

#endif // !_SACHTIENGVIET_H

