#pragma once
#ifndef _PHIEUMUONTRA_H
#define _PHIEUMUONTRA_H

#include <vector>

#include "Ngay.h"

class PhieuMuonTra: public Ngay
{
private:
	string _maDocGiaMuon;
	string _maSachMuon;
	Ngay _ngayMuon, _ngayTra;
	int _soLuong;
public:
	string Get_DocGiaMuon();
	string Get_MaSachMuon();
	Ngay Get_NgayMuon();
	Ngay Get_NgayTra();
	int Get_SoLuong();

	void Set_DocGiaMuon(const string x);
	void Set_MaSachMuon(const string x);
	void Set_NgayMuon(const Ngay x);
	void Set_NgayTra(const Ngay x);
	void Set_SoLuong(const int x);
public:
	void Nhap();
	void Xuat();

	int TinhTienQuaHan();
public:
	PhieuMuonTra();
	~PhieuMuonTra();
};

#endif // !_PHIEUMUONTRA_H

