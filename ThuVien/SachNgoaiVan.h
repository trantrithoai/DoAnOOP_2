#pragma once
#ifndef _SACHNGOAIVAN_H
#define _SACHNGOAIVAN_H

#include "SachTiengViet.h"

class SachNgoaiVan: public SachTiengViet
{
private:
	string _ISBN;
public:
	string Get_ISBN();
	void Set_ISBN(const string x);
public:
	void Nhap();
	void Xuat();

	//void GhiFile();
public:
	SachNgoaiVan();
	~SachNgoaiVan();
};

#endif // !_SACHNGOAIVAN_H

