#include <iostream>
#include "cDaGiac.h"

using namespace std;

int main() {
	DaGiac d;

	d.Nhap();
	d.Xuat();

	d.TinhChuVi();
	d.TinhDienTich();

	d.TinhTien();
	d.Xuat();

	d.Quay();
	d.Xuat();

	d.PhongTo();
	d.Xuat();

	d.ThuNho();
	d.Xuat();

	d.VeDaGiac();

	system("pause");
	return 0;
}
