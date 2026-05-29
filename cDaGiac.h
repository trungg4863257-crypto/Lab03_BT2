#pragma once
#ifndef CDAGIAC_H
#define CDAGIAC_H

#include "cToaDo.h"

class DaGiac {
private:
	int n;
	ToaDo* dinh;

public:
	DaGiac();
	~DaGiac();

	void Nhap();
	void Xuat();

	float TinhChuVi();
	float TinhDienTich();

	void TinhTien();
	void Quay();
	void PhongTo();
	void ThuNho();

	void VeDaGiac();
};

#endif
