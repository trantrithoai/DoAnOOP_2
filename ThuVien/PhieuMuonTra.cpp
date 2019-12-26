#include <iostream>
using namespace std;

#include "PhieuMuonTra.h"

string PhieuMuonTra::Get_DocGiaMuon()
{
	return _maDocGiaMuon;
}

string PhieuMuonTra::Get_MaSachMuon()
{
	return _maSachMuon;
}

Ngay PhieuMuonTra::Get_NgayMuon()
{
	return _ngayMuon;
}

Ngay PhieuMuonTra::Get_NgayTra()
{
	return _ngayTra;
}

int PhieuMuonTra::Get_SoLuong()
{
	return _soLuong;
}

void PhieuMuonTra::Set_DocGiaMuon(const string x)
{
	_maDocGiaMuon = x;
}

void PhieuMuonTra::Set_MaSachMuon(const string x)
{
	_maSachMuon = x;
}

void PhieuMuonTra::Set_NgayMuon(const Ngay x)
{
	_ngayMuon = x;
}

void PhieuMuonTra::Set_NgayTra(const Ngay x)
{
	_ngayTra = x;
}

void PhieuMuonTra::Set_SoLuong(const int x)
{
	_soLuong = x;
}

void PhieuMuonTra::Nhap()
{
	do
	{
		cout << "Nhap so luong sach: ";
		cin >> _soLuong;

		if (_soLuong < 1)
			cout << "Khong hop le. Xin vui long nhap lai!\n";

	} while (_soLuong < 1);

	cout << "Nhap ngay muon sach:\n";
	_ngayMuon.Nhap();

	int check = 0;
	do
	{
		cout << "Nhap ngay tra sach:\n";
		_ngayTra.Nhap();

		if (_ngayTra.Get_Nam() >= _ngayMuon.Get_Nam())
		{
			if (_ngayTra.Get_Thang() >= _ngayMuon.Get_Thang())
			{
				if (_ngayTra.Get_Ngay() >= _ngayMuon.Get_Ngay())
					check = 1;
			}
		}

		if (check == 0)
		{
			cout << "Ngay tra khong hop le. Xin vui long nhap lai!\n";
		}

	} while (check == 0);
}

void PhieuMuonTra::Xuat()
{
	cout << "\nMa sach muon: " << _maSachMuon;

	cout << "\nSo luong: " << _soLuong << " cuon sach";

	cout << "\nNgay muon sach: ";
	_ngayMuon.Xuat();

	cout << "\nNgay tra sach: ";
	_ngayTra.Xuat();
}

int PhieuMuonTra::TinhTienQuaHan()
{
	int ngay = _ngayTra.TinhSoNgay(_ngayMuon);

	if (ngay > 7)
	{
		return 10000 * (ngay - 7) * _soLuong;
	}
	return 0;
}

PhieuMuonTra::PhieuMuonTra()
{
}

PhieuMuonTra::~PhieuMuonTra()
{
}