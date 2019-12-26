#include <iostream>
#include <fstream>
using namespace std;

#include "ThuVien.h"

void ThuVien::DocFile()
{
	//Đọc file sách
	ifstream fileSach("Sach.txt"); 

	if (fileSach.fail())
	{
		cout << "\nKhong mo duoc file Sach.txt !!!";
		return;
	}

	while (!fileSach.eof())
	{
		string str;
		getline(fileSach, str, '\n');

		if (str.compare("Sach Tieng Viet") == 0)
		{
			SachTiengViet* s = new SachTiengViet;

			s->Set_LoaiSach(1);
			
			string maSach;
			getline(fileSach, maSach, '\n');
			s->Set_MaSach(maSach);

			string tenSach;
			getline(fileSach, tenSach, '\n');
			s->Set_TenSach(tenSach);

			string tacGia;
			getline(fileSach, tacGia, '\n');
			s->Set_TacGia(tacGia);

			string nhaXuatBan;
			getline(fileSach, nhaXuatBan, '\n');
			s->Set_NhaXuatBan(nhaXuatBan);

			int giaSach;
			fileSach >> giaSach;
			s->Set_GiaSach(giaSach);

			ds_Sach.push_back(s);
		}
		else if (str.compare("Sach Ngoai Van") == 0)
		{
			SachNgoaiVan* s = new SachNgoaiVan;

			s->Set_LoaiSach(2);

			string maSach;
			getline(fileSach, maSach, '\n');
			s->Set_MaSach(maSach);

			string tenSach;
			getline(fileSach, tenSach, '\n');
			s->Set_TenSach(tenSach);

			string tacGia;
			getline(fileSach, tacGia, '\n');
			s->Set_TacGia(tacGia);

			string nhaXuatBan;
			getline(fileSach, nhaXuatBan, '\n');
			s->Set_NhaXuatBan(nhaXuatBan);

			string ISBN;
			getline(fileSach, ISBN, '\n');
			s->Set_ISBN(ISBN);

			int giaSach;
			fileSach >> giaSach;
			s->Set_GiaSach(giaSach);
			
			ds_Sach.push_back(s);
		}	
	}

	fileSach.close();

	//Đọc file đọc giả
	ifstream fileDocGia("DocGia.txt");

	if (fileDocGia.fail())
	{
		cout << "\nKhong mo duoc file DocGia.txt !!!";
		return;
	}

	while (!fileDocGia.eof())
	{
		DocGia dg;

		string ten;
		getline(fileDocGia, ten, '\n');
		dg.Set_HoTen(ten);

		string maDocGia;
		getline(fileDocGia, maDocGia, '\n');
		dg.Set_MaDocGia(maDocGia);

		string ngay;
		getline(fileDocGia, ngay, '/');

		string thang;
		getline(fileDocGia, thang, '/');

		string nam;
		getline(fileDocGia, nam, '\n');

		Ngay x;
		x.Set_Ngay(atoi(ngay.c_str()));
		x.Set_Thang(atoi(thang.c_str()));
		x.Set_Nam(atoi(nam.c_str()));

		dg.Set_NgaySinh(x);

		ds_DocGia.push_back(dg);

		string temp;
		getline(fileDocGia, temp, '\n');
	}

	fileDocGia.close();

	//Đọc file phiếu mượn trả sách.
	ifstream filePhieuMuonTra("PhieuMuonTra.txt");

	if (filePhieuMuonTra.fail())
	{
		cout << "\nKhong mo duoc file PhieuMuonTra.txt !!!";
		return;
	}

	while (!filePhieuMuonTra.eof())
	{
		PhieuMuonTra phieu;

		string docGia;
		getline(filePhieuMuonTra, docGia, '\n');
		phieu.Set_DocGiaMuon(docGia);

		string maSach;
		getline(filePhieuMuonTra, maSach, '\n');
		phieu.Set_MaSachMuon(maSach);

		int soLuong;
		filePhieuMuonTra >> soLuong;
		phieu.Set_SoLuong(soLuong);

		string ngayMuon;
		getline(filePhieuMuonTra, ngayMuon, '/');

		string thangMuon;
		getline(filePhieuMuonTra, thangMuon, '/');

		string namMuon;
		getline(filePhieuMuonTra, namMuon, '\n');

		Ngay x;
		x.Set_Ngay(atoi(ngayMuon.c_str()));
		x.Set_Thang(atoi(thangMuon.c_str()));
		x.Set_Nam(atoi(namMuon.c_str()));

		phieu.Set_NgayMuon(x);

		string ngayTra;
		getline(filePhieuMuonTra, ngayTra, '/');

		string thangTra;
		getline(filePhieuMuonTra, thangTra, '/');

		string namTra;
		getline(filePhieuMuonTra, namTra, '\n');

		Ngay y;
		y.Set_Ngay(atoi(ngayTra.c_str()));
		y.Set_Thang(atoi(thangTra.c_str()));
		y.Set_Nam(atoi(namTra.c_str()));

		phieu.Set_NgayTra(y);

		ds_PhieuMuonTra.push_back(phieu);

		string temp;
		getline(filePhieuMuonTra, temp, '\n');
	}

	filePhieuMuonTra.close();
}

void ThuVien::XuatFileSach()
{
	cout << "\n========== Danh sach sach cua thu vien ==========\n";

	for (int i = 0; i < ds_Sach.size(); i++)
	{
		if (ds_Sach[i]->Get_LoaiSach() == 1)
		{
			cout << "\nSach Tieng Viet";
		}
		else
		{
			cout << "\nSach Ngoai Van";
		}
		ds_Sach[i]->Xuat();
		cout << endl;
	}
}

void ThuVien::XuatFileDocGia()
{
	cout << "\n============ Danh sach doc gia cua thu vien ============\n";

	for (int i = 0; i < ds_DocGia.size(); i++)
	{
		ds_DocGia[i].Xuat();
		cout << endl;
	}
}

void ThuVien::XuatFilePhieuMuonTraSach()
{
	cout << "\n============ Danh sach phieu muon tra ============\n";

	for (int i = 0; i < ds_PhieuMuonTra.size(); i++)
	{
		cout << "\nMa doc gia: " << ds_PhieuMuonTra[i].Get_DocGiaMuon();
		ds_PhieuMuonTra[i].Xuat();
		cout << endl;
	}
}

void ThuVien::ThemSach()
{
	SachTiengViet* sach;

	string maSach;

	cin.ignore();
	cout << "\nNhap ma sach can them: ";
	getline(cin, maSach);

	for (int i = 0; i < ds_Sach.size(); i++)
	{
		if (maSach.compare(ds_Sach[i]->Get_MaSach()) == 0)
		{
			cout << "\nMa sach da ton tai!";
			return;
		}
	}

	int loai;
	do
	{
		cout << "Nhap loai sach(1.Sach Tieng Viet, 2.Sach Ngoai Van): ";
		cin >> loai;

		if (loai != 1 and loai != 2)
			cout << "Khong hop le. Xin vui long nhap lai!\n";

	} while (loai != 1 and loai != 2);

	if (loai == 1)
	{
		sach = new SachTiengViet;
		sach->Set_LoaiSach(1);
	}
	else
	{
		sach = new SachNgoaiVan;
		sach->Set_LoaiSach(2);
	}

	sach->Nhap();

	sach->Set_MaSach(maSach);

	ds_Sach.push_back(sach);
}

void ThuVien::XoaSach()
{
	cin.ignore();
	string maSach;
	cout << "\nNhap ma sach ma ban muon xoa: ";
	getline(cin, maSach);

	int check = 0;
	int vitri = -1;
	for (int i = 0; i < ds_Sach.size(); i++)
	{
		if (maSach.compare(ds_Sach[i]->Get_MaSach()) == 0)
		{
			check = 1;
			vitri = i;
			break;
		}
	}

	if (check == 0)
	{
		cout << "Khong ton tai sach nay trong danh sach. Xin kiem tra lai!\n";
		return;
	}

	SachTiengViet* p = ds_Sach[vitri];

	ds_Sach.erase(ds_Sach.begin() + vitri);

	cout << "Xoa thanh cong!\n";

	delete p;
}

void ThuVien::SuaThongTinSach()
{
	string maSach;
	cin.ignore();
	cout << "\nNhap ma sach ma ban muon sua: ";
	getline(cin, maSach);

	int check = 0;
	int vitri = -1;
	for (int i = 0; i < ds_Sach.size(); i++)
	{
		if (maSach.compare(ds_Sach[i]->Get_MaSach()) == 0)
		{
			check = 1;
			vitri = i;
			break;
		}
	}

	if (check == 0)
	{
		cout << "Khong ton tai sach nay trong danh sach. Xin kiem tra lai!\n";
		return;
	}

	cout << "MA SACH VA LOAI SACH LA KHONG THE THAY DOI\n";

	if (ds_Sach[vitri]->Get_LoaiSach() == 1)
	{
		SachTiengViet* sach = new SachTiengViet;
		sach->Set_LoaiSach(1);
		sach->Set_MaSach(maSach);

		int checkTenSach;
		do
		{
			cout << "Ban co muon sua ten sach hay khong(1.Co va 0.Khong): ";
			cin >> checkTenSach;

			if (checkTenSach != 0 and checkTenSach != 1)
				cout << "Khong hop le. Xin vui long nhap lai!\n";

		} while (checkTenSach != 0 and checkTenSach != 1);

		if (checkTenSach == 1)
		{
			string tenSach;
			cin.ignore();
			cout << "Nhap ten sach: ";
			sach->Set_TenSach(tenSach);
		}
		else
		{
			sach->Set_TenSach(ds_Sach[vitri]->Get_TenSach());
		}

		int checkTacGia;
		do
		{
			cout << "Ban co muon sua tac gia hay khong(1.Co va 0.Khong): ";
			cin >> checkTacGia;

			if (checkTacGia != 0 and checkTacGia != 1)
				cout << "Khong hop le. Xin vui long nhap lai!\n";

		} while (checkTacGia != 0 and checkTacGia != 1);

		if (checkTacGia == 1)
		{
			string tacGia;
			cin.ignore();
			cout << "Nhap tac gia: ";
			getline(cin, tacGia);
			sach->Set_TacGia(tacGia);
		}
		else
		{
			sach->Set_TacGia(ds_Sach[vitri]->Get_TacGia());
		}

		int checkNhaXuatBan;
		do
		{
			cout << "Ban co muon sua nha xuat ban hay khong(1.Co va 0.Khong): ";
			cin >> checkNhaXuatBan;

			if (checkNhaXuatBan != 0 and checkNhaXuatBan != 1)
				cout << "Khong hop le. Xin vui long nhap lai!\n";

		} while (checkNhaXuatBan != 0 and checkNhaXuatBan != 1);

		if (checkNhaXuatBan == 1)
		{
			string nhaXuatBan;
			cin.ignore();
			cout << "Nhap nha xuat ban: ";
			getline(cin, nhaXuatBan);
			sach->Set_NhaXuatBan(nhaXuatBan);
		}
		else
		{
			sach->Set_NhaXuatBan(ds_Sach[vitri]->Get_NhaXuatBan());
		}

		int checkGia;
		do
		{
			cout << "Ban co muon sua gia ban sach hay khong(1.Co va 0.Khong): ";
			cin >> checkGia;

			if (checkGia != 0 and checkGia != 1)
				cout << "Khong hop le. Xin vui long nhap lai!\n";

		} while (checkGia != 0 and checkGia != 1);

		if (checkGia == 1)
		{
			int gia;
			do
			{
				cout << "Nhap gia ban sach: ";
				cin >> gia;

				if (gia <= 0)
					cout << "Khong hop le. Xin kiem tra lai!\n";

			} while (gia <= 0);

			sach->Set_GiaSach(gia);
		}
		else
		{
			sach->Set_GiaSach(ds_Sach[vitri]->Get_GiaSach());
		}

		ds_Sach.push_back(sach);

		ds_Sach.erase(ds_Sach.begin() + vitri);
	}
	else
	{
		SachNgoaiVan* sach = new SachNgoaiVan;
		sach->Set_LoaiSach(2);
		sach->Set_MaSach(maSach);

		int checkTenSach;
		do
		{
			cout << "Ban co muon sua ten sach hay khong(1.Co va 0.Khong): ";
			cin >> checkTenSach;

			if (checkTenSach != 0 and checkTenSach != 1)
				cout << "Khong hop le. Xin vui long nhap lai!\n";

		} while (checkTenSach != 0 and checkTenSach != 1);

		if (checkTenSach == 1)
		{
			string tenSach;
			cout << "Nhap ten sach: ";
			cin.ignore();
			getline(cin, tenSach);
			sach->Set_TenSach(tenSach);
		}
		else
		{
			sach->Set_TenSach(ds_Sach[vitri]->Get_TenSach());
		}

		int checkTacGia;
		do
		{
			cout << "Ban co muon sua tac gia hay khong(1.Co va 0.Khong): ";
			cin >> checkTacGia;

			if (checkTacGia != 0 and checkTacGia != 1)
				cout << "Khong hop le. Xin vui long nhap lai!\n";

		} while (checkTacGia != 0 and checkTacGia != 1);

		if (checkTacGia == 1)
		{
			string tacGia;
			cout << "Nhap tac gia: ";
			cin.ignore();
			getline(cin, tacGia);
			sach->Set_TacGia(tacGia);
		}
		else
		{
			sach->Set_TacGia(ds_Sach[vitri]->Get_TacGia());
		}

		int checkNhaXuatBan;
		do
		{
			cout << "Ban co muon sua nha xuat ban hay khong(1.Co va 0.Khong): ";
			cin >> checkNhaXuatBan;

			if (checkNhaXuatBan != 0 and checkNhaXuatBan != 1)
				cout << "Khong hop le. Xin vui long nhap lai!\n";

		} while (checkNhaXuatBan != 0 and checkNhaXuatBan != 1);

		if (checkNhaXuatBan == 1)
		{
			string nhaXuatBan;
			cout << "Nhap nha xuat ban: ";
			cin.ignore();
			getline(cin, nhaXuatBan);
			sach->Set_NhaXuatBan(nhaXuatBan);
		}
		else
		{
			sach->Set_NhaXuatBan(ds_Sach[vitri]->Get_NhaXuatBan());
		}

		int checkGia;
		do
		{
			cout << "Ban co muon sua gia ban sach hay khong(1.Co va 0.Khong): ";
			cin >> checkGia;

			if (checkGia != 0 and checkGia != 1)
				cout << "Khong hop le. Xin vui long nhap lai!\n";

		} while (checkGia != 0 and checkGia != 1);

		if (checkGia == 1)
		{
			int gia;
			do
			{
				cout << "Nhap gia ban sach: ";
				cin >> gia;

				if (gia <= 0)
					cout << "Khong hop le. Xin kiem tra lai!\n";

			} while (gia <= 0);

			sach->Set_GiaSach(gia);
		}
		else
		{
			sach->Set_GiaSach(ds_Sach[vitri]->Get_GiaSach());
		}

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

		sach->Set_ISBN(ISBN);

		ds_Sach.push_back(sach);

		ds_Sach.erase(ds_Sach.begin() + vitri);
	}
}

void ThuVien::TimKiemSach()
{
	cin.ignore();
	string maSach;
	cout << "\nNhap ma sach ma ban muon tim kiem: ";
	getline(cin, maSach);

	int check = 0;
	int vitri = -1;
	for (int i = 0; i < ds_Sach.size(); i++)
	{
		if (maSach.compare(ds_Sach[i]->Get_MaSach()) == 0)
		{
			check = 1;
			vitri = i;
			break;
		}
	}

	if (check == 0)
	{
		cout << "Khong ton tai sach nay trong danh sach. Xin kiem tra lai!\n";
		return;
	}
	else
	{
		ds_Sach[vitri]->Xuat();
	}
}

void ThuVien::ThemDocGia()
{
	DocGia dg;

	cin.ignore();
	string maDocGia;
	cout << "\nNhap ma doc gia: ";
	getline(cin, maDocGia);

	for (int i = 0; i < ds_DocGia.size(); i++)
	{
		if (maDocGia.compare(ds_DocGia[i].Get_MaDocGia()) == 0)
		{
			cout << "Ma doc gia da ton tai!\n";
			return;
		}
	}
	string hoTen;
	cout << "Nhap ten doc gia: ";
	getline(cin, hoTen);
	dg.Set_HoTen(hoTen);

	cout << "Nhap ngay sinh\n";
	Ngay ngaySinh;
	ngaySinh.Nhap();
	dg.Set_NgaySinh(ngaySinh);

	dg.Set_MaDocGia(maDocGia);

	ds_DocGia.push_back(dg);
}

void ThuVien::XoaDocGia()
{
	cin.ignore();
	string maDocGia;
	cout << "\nNhap ma doc gia ma ban muon xoa: ";
	getline(cin, maDocGia);

	int check = 0;
	int vitri = -1;
	for (int i = 0; i < ds_DocGia.size(); i++)
	{
		if (maDocGia.compare(ds_DocGia[i].Get_MaDocGia()) == 0)
		{
			check = 1;
			vitri = i;
			break;
		}
	}

	if (check == 0)
	{
		cout << "Khong ton tai doc gia nay trong danh sach. Xin kiem tra lai!\n";
		return;
	}

	ds_DocGia.erase(ds_DocGia.begin() + vitri);

	cout << "Da xoa thanh cong!\n";
}

void ThuVien::SuaThongTinDocGia()
{
	cin.ignore();
	string maDocGia;
	cout << "\nNhap ma doc gia ma ban muon sua thong tin: ";
	getline(cin, maDocGia);

	int check = 0;
	int vitri = -1;
	for (int i = 0; i < ds_DocGia.size(); i++)
	{
		if (maDocGia.compare(ds_DocGia[i].Get_MaDocGia()) == 0)
		{
			check = 1;
			vitri = i;
			break;
		}
	}

	if (check == 0)
	{
		cout << "Khong ton tai doc gia nay trong danh sach. Xin kiem tra lai!\n";
		return;
	}

	cout << "MA DOC GIA LA KHONG THE THAY DOI\n";

	int checkHoTen;
	do
	{
		cout << "Ban co muon thay doi ten doc gia(1.Co va 0.Khong): ";
		cin >> checkHoTen;

		if (checkHoTen != 0 and checkHoTen != 1)
			cout << "Khong hop le. Xin vui long nhap lai!\n";

	} while (checkHoTen != 0 and checkHoTen != 1);

	if (checkHoTen == 1)
	{
		string hoTen;
		cin.ignore();
		cout << "Nhap ho ten doc gia: ";
		getline(cin, hoTen);

		ds_DocGia[vitri].Set_HoTen(hoTen);
	}

	int checkNgaySinh;
	do
	{
		cout << "Ban co muon thay doi ngay sinh doc gia khong(1.Co va 0.Khong): ";
		cin >> checkNgaySinh;

		if (checkNgaySinh != 1 and checkNgaySinh != 0)
			cout << "Khong hop le. Xin vui long nhap lai!\n";

	} while (checkNgaySinh != 1 and checkNgaySinh != 0);

	if (checkNgaySinh == 1)
	{
		Ngay news;
		news.Nhap();
		ds_DocGia[vitri].Set_NgaySinh(news);
	}
}

void ThuVien::TimKiemDocGia()
{
	cin.ignore();
	string maDocGia;
	cout << "\nNhap ma doc gia ma ban muon tim kiem: ";
	getline(cin, maDocGia);

	int check = 0;
	int vitri = -1;
	for (int i = 0; i < ds_DocGia.size(); i++)
	{
		if (maDocGia.compare(ds_DocGia[i].Get_MaDocGia()) == 0)
		{
			check = 1;
			vitri = i;
			break;
		}
	}

	if (check == 0)
	{
		cout << "Khong ton tai doc gia nay trong danh sach. Xin kiem tra lai!\n";
		return;
	}

	ds_DocGia[vitri].Xuat();
}

void ThuVien::LapPhieuMuonTra()
{
	PhieuMuonTra phieu;

	cin.ignore();
	string maDocGia;
	cout << "\nNhap ma doc gia ma ban muon lap phieu: ";
	getline(cin, maDocGia);

	int checkMaDocGia = 0;
	int vitri = -1;
	for (int i = 0; i < ds_DocGia.size(); i++)
	{
		if (maDocGia.compare(ds_DocGia[i].Get_MaDocGia()) == 0)
		{
			checkMaDocGia = 1;
			vitri = i;
			break;
		}
	}

	if (checkMaDocGia == 0)
	{
		cout << "Khong ton tai doc gia nay trong danh sach. Xin kiem tra lai!\n";
		return;
	}

	phieu.Set_DocGiaMuon(maDocGia);

	string maSach;
	cout << "Nhap ma sach ma ban muon lap phieu: ";
	getline(cin, maSach);

	int checkMaSach = 0;
	for (int i = 0; i < ds_Sach.size(); i++)
	{
		if (maSach.compare(ds_Sach[i]->Get_MaSach()) == 0)
		{
			checkMaSach = 1;
			break;
		}
	}

	if (checkMaSach == 0)
	{
		cout << "Khong ton tai sach nay trong danh sach. Xin kiem tra lai!\n";
		return;
	}

	phieu.Set_MaSachMuon(maSach);

	phieu.Nhap();

	ds_PhieuMuonTra.push_back(phieu);
}

void ThuVien::DanhSachDocGiaQuaHan()
{
	cout << "DANH SACH DOC GIA MUON SACH QUA HAN\n";

	for (int i = 0; i < ds_PhieuMuonTra.size(); i++)
	{
		string maSach = ds_PhieuMuonTra[i].Get_MaSachMuon();
		int tien = 0;

		for (int j = 0; j < ds_Sach.size(); j++)
		{
			if (maSach.compare(ds_Sach[j]->Get_MaSach()) == 0)
			{
				if (ds_Sach[j]->Get_LoaiSach() == 1)
				{
					tien = ds_PhieuMuonTra[i].TinhTienQuaHan();
				}
				else
				{
					tien = 2 * ds_PhieuMuonTra[i].TinhTienQuaHan();
				}
				break;
			}
		}

		if (tien != 0)
		{
			ds_PhieuMuonTra[i].Xuat();
			cout << "\nTien phat: " << tien << " VND\n";
		}
	}
}

ThuVien::ThuVien()
{
}

ThuVien::~ThuVien()
{
	for (int i = 0; i < ds_Sach.size(); i++)
	{
		delete ds_Sach[i];
	}
}
