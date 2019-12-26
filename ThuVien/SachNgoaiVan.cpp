#include <iostream>
#include <fstream>
using namespace std;

#include "SachNgoaiVan.h"

string SachNgoaiVan::Get_ISBN()
{
	return _ISBN;
}

void SachNgoaiVan::Set_ISBN(const string x)
{
	_ISBN = x;
}

void SachNgoaiVan::Nhap()
{
	SachTiengViet::Nhap();

	cin.ignore();

	cout << "Nhap ma so tieu chuan quoc te(ISBN). ISBN co dang(vd: ISBN 0-306-40615-2)\n";

	string ma;
	do
	{
		cout << "Moi ban nhap 10 chu so cua ma: ";
		getline(cin, ma);

		if (ma.length() != 10)
			cout << "Khong hop le. Xin kiem tra lai!\n";

	} while (ma.length() != 10);

	string ISBN = "0-000-00000-0";

	ISBN[0] = ma[0];

	ISBN[2] = ma[1];
	ISBN[3] = ma[2];
	ISBN[4] = ma[3];

	ISBN[6] = ma[4];
	ISBN[7] = ma[5];
	ISBN[8] = ma[6];
	ISBN[9] = ma[7];
	ISBN[10] = ma[8];

	ISBN[12] = ma[9];

	Set_ISBN(ISBN);
}

void SachNgoaiVan::Xuat()
{
	SachTiengViet::Xuat();

	cout << "\nISBN " << _ISBN;
}

SachNgoaiVan::SachNgoaiVan()
{
}

SachNgoaiVan::~SachNgoaiVan()
{
}