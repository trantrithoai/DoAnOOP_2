#pragma once
#ifndef _NGAY_H
#define _NGAY_H

class Ngay
{
private:
	int _ngay, _thang, _nam;
public:
	int Get_Ngay();
	int Get_Thang();
	int Get_Nam();

	void Set_Ngay(const int x);
	void Set_Thang(const int x);
	void Set_Nam(const int x);
public:
	int KiemTraNamNhuan();
	int KiemTraNgayHopLe();

	void Nhap();
	void Xuat();

	int TinhSoNgay(const Ngay x);
public:
	Ngay();
	~Ngay();
};

#endif // !_NGAY_H



