#include <iostream>
#include <fstream>
using namespace std;

#include "ThuVien.h"

int  main()
{
	ThuVien KHTN;
	KHTN.DocFile();

	int luachon;
	do
	{
		system("cls");
		cout << "====================== MENU ======================\n";
		cout << "1.Xuat danh sach sach cua thu vien\n";
		cout << "2.Xuat danh sach doc gia cua thu vien\n";
		cout << "3.Xuat danh sach phieu muon tra sach cua thu vien\n\n";
		cout << "4.Them sach\n";
		cout << "5.Xoa sach\n";
		cout << "6.Sua sach\n";
		cout << "7.Tim kiem sach\n\n";
		cout << "8.Them doc gia\n";
		cout << "9.Xoa doc gia\n";
		cout << "10.Sua doc gia\n";
		cout << "11.Tim kiem doc gia\n\n";
		cout << "12.Lap phieu muon tra sach\n";
		cout << "13.Danh sach doc gia muon sach qua han\n";
		cout << "0.Thoat chuong trinh\n\n";

		cout << "Nhap lua chon: ";
		cin >> luachon;

		switch (luachon)
		{
		case 1:
			KHTN.XuatFileSach();
			break;
		case 2:
			KHTN.XuatFileDocGia();
			break;
		case 3:
			KHTN.XuatFilePhieuMuonTraSach();
			break;
		case 4:
			KHTN.ThemSach();
			break;
		case 5:
			KHTN.XoaSach();
			break;
		case 6:
			KHTN.SuaThongTinSach();
			break;
		case 7:
			KHTN.TimKiemSach();
			break;
		case 8:
			KHTN.ThemDocGia();
			break;
		case 9:
			KHTN.XoaDocGia();
			break;
		case 10:
			KHTN.SuaThongTinDocGia();
			break;
		case 11:
			KHTN.TimKiemDocGia();
			break;
		case 12:
			KHTN.LapPhieuMuonTra();
			break;
		case 13:
			KHTN.DanhSachDocGiaQuaHan();
			break;
		}
		system("pause");

	} while (luachon != 0);

	return 0;
}