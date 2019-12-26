#pragma once
#ifndef _DOCGIA_H
#define _DOCGIA_H

#include <string>

#include "Ngay.h"

class DocGia: public Ngay
{
private:
	string _hoTen;
	string _maDocGia;
	Ngay _ngaySinh;
public:
	string Get_HoTen();
	string Get_MaDocGia();
	Ngay Get_NgaySinh();

	void Set_HoTen(const string x);
	void Set_MaDocGia(const string x);
	void Set_NgaySinh(const Ngay x);
public:
	void Nhap();
	void Xuat();
public:
	DocGia();
	~DocGia();
};

#endif // !_DOCGIA_H

