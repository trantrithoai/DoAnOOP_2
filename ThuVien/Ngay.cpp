#include <iostream>
using namespace std;

#include "Ngay.h"

int Ngay::Get_Ngay()
{
	return _ngay;
}

int Ngay::Get_Thang()
{
	return _thang;
}

int Ngay::Get_Nam()
{
	return _nam;
}

void Ngay::Set_Ngay(const int x)
{
	_ngay = x;
}

void Ngay::Set_Thang(const int x)
{
	_thang = x;
}

void Ngay::Set_Nam(const int x)
{
	_nam = x;
}

int Ngay::KiemTraNamNhuan()
{
	if (Get_Nam() % 100 == 0)
	{
		if (Get_Nam() % 400 == 0)
		{
			return 1;
		}
	}
	else if (Get_Nam() % 4 == 0)
	{
		return 1;
	}
}

int Ngay::KiemTraNgayHopLe()
{
	if (Get_Nam() < 1)
		return 0;


	switch (Get_Thang())
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (Get_Ngay() < 1 or Get_Ngay() > 31)
			return 0;
		break;
	case 4: case 6: case 9: case 11:
		if (Get_Ngay() < 1 or Get_Ngay() > 30)
			return 0;
		break;
	case 2:
		if (KiemTraNamNhuan() == 0)
		{
			if (Get_Ngay() < 1 or Get_Ngay() > 28)
				return 0;
		}
		else
		{
			if (Get_Ngay() < 1 or Get_Ngay() > 29)
				return 0;
		}
		break;
	default:
		return 0;
	}
	return 1;
}

void Ngay::Nhap()
{
	do
	{
		cout << "Nhap ngay: ";
		cin >> _ngay;

		cout << "Nhap thang: ";
		cin >> _thang;

		cout << "Nhap nam: ";
		cin >> _nam;

		if (KiemTraNgayHopLe() == 0)
			cout << "Ngay khong hop le!\n";

	} while (KiemTraNgayHopLe() == 0);
}

void Ngay::Xuat()
{
	cout << "Ngay " << _ngay << " thang " << _thang << " nam " << _nam;
}

int TinhNgay(int ngay, int thang, int nam)
{
	if (thang < 3)
	{
		nam--;
		thang += 12;
	}
	return 365 * nam + nam / 4 - nam / 100 + nam / 400 + (153 * thang - 457) / 5 + ngay - 306;
}

int Ngay::TinhSoNgay(const Ngay x)
{
	return TinhNgay(_ngay, _thang, _nam) - TinhNgay(x._ngay, x._thang, x._nam);
}

Ngay::Ngay()
{
}

Ngay::~Ngay()
{
}
