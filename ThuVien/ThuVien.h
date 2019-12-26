#pragma once
#ifndef _THUVIEN_H
#define _THUVIEN_H

#include <vector>

#include "SachTiengViet.h"
#include "SachNgoaiVan.h"
#include "DocGia.h"
#include "PhieuMuonTra.h"

class ThuVien: public SachTiengViet, public SachNgoaiVan, public DocGia, public PhieuMuonTra
{
private:
	vector<SachTiengViet*> ds_Sach;
	vector<DocGia> ds_DocGia;
	vector<PhieuMuonTra> ds_PhieuMuonTra;
public:
	void ThemSach();
	void XoaSach();
    void SuaThongTinSach();
	void TimKiemSach();

	void ThemDocGia();
	void XoaDocGia();
	void SuaThongTinDocGia();
	void TimKiemDocGia();

	void LapPhieuMuonTra();
	void DanhSachDocGiaQuaHan();
public:
	void DocFile();

	void XuatFileSach();
	void XuatFileDocGia();
	void XuatFilePhieuMuonTraSach();
public:
	ThuVien();
	~ThuVien();
};

#endif // !_THUVIEN_H

