#include <iostream>
#include <cmath>
#include <windows.h>
#include "cDaGiac.h"

using namespace std;

DaGiac::DaGiac() {
	n = 0;
	dinh = NULL;
}

DaGiac::~DaGiac() {
	delete[] dinh;
}

/*
ham nhap so dinh va toa do cac dinh cua da giac 
input: n, dinh[i].iHoanh, dinh[i].iTung
*/
void DaGiac::Nhap() {
	cout << "Nhap so dinh: ";
	cin >> n;

	dinh = new ToaDo[n];

	for (int i = 0; i < n; i++) {
		cout << "Nhap dinh " << i + 1 << ": ";
		cin >> dinh[i].iHoanh >> dinh[i].iTung;
	}
}

/*
ham xuat toa do cac dinh cua da giac
output: (dinh[i].iHoanh, dinh[i].iTung)
*/
void DaGiac::Xuat() {
	for (int i = 0; i < n; i++) {
		cout << "(" << dinh[i].iHoanh << ", " << dinh[i].iTung << ") ";
	}
	cout << endl;
}

/*
ham tin chu vi cua da giac su dung cong thuc tinh khoang cach giua cac dinh lien ke
output: chu vi cua da giac
*/
float DaGiac::TinhChuVi() {
	float cv = 0;

	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;

		cv += sqrt(
			pow(dinh[j].iHoanh - dinh[i].iHoanh, 2) + pow(dinh[j].iTung - dinh[i].iTung, 2)
		);
	}

	cout << "\nChu vi cua da giac: " << cv << endl;
	return cv;
}

/*
ham tinh dien tich cua da giac su dung cong thuc Shoelace
output: dien tich cua da giac
*/
float DaGiac::TinhDienTich() {
	float s = 0;

	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;

		s += dinh[i].iHoanh * dinh[j].iTung;
		s -= dinh[j].iHoanh * dinh[i].iTung;
	}

	s = abs(s) / 2.0;

	cout << "\nDien tich cua da giac: " << s << endl;
	return s;
}

/*
ham tinh tien da giac theo vector (dx, dy)
input: dx, dy
output: toa do moi cua cac dinh sau khi tinh tien
*/
void DaGiac::TinhTien() {
	float dx, dy;
	cout << "\nNhap vector tinh tien (dx, dy): ";
	cin >> dx >> dy;

	for (int i = 0; i < n; i++) {
		dinh[i].iHoanh += dx;
		dinh[i].iTung += dy;
	}
	cout << "Da giac sau khi inh tien: ";
	Xuat();
}

/*
ham quay da giac quanh goc toa do (0, 0) theo chieu kim dong ho voi goc quay duoc nhap tu ban phim
input: goc quay (do)
output: toa do moi cua cac dinh sau khi quay
*/
void DaGiac::Quay() {
	float angle;
	cout << "\nNhap goc quay (do): ";
	cin >> angle;

	float rad = angle * 3.14159265 / 180;

	for (int i = 0; i < n; i++) {
		float x = dinh[i].iHoanh;
		float y = dinh[i].iTung;

		dinh[i].iHoanh = x * cos(rad) - y * sin(rad);
		dinh[i].iTung = x * sin(rad) + y * cos(rad);
	}
	cout << "Da giac sau khi quay: ";
	Xuat();
}

/*
ham phong to da giac theo ti le k
input: ti le k
output: toa do moi cua cac dinh sau khi phong to
*/
void DaGiac::PhongTo() {
	float k;
	cout << "\nNhap ti le phong to (k > 1): ";
	cin >> k;

	for (int i = 0; i < n; i++) {
		dinh[i].iHoanh *= k;
		dinh[i].iTung *= k;
	}
	cout << "Da giac sau khi phong to: ";
	Xuat();
}

/*
ham thu nho da giac theo ti le k
input: ti le k
output: toa do moi cua cac dinh sau khi thu nho
*/
void DaGiac::ThuNho() {
	float k;
	cout << "\nNhap ti le thu nho (k > 1): ";
	cin >> k;

	for (int i = 0; i < n; i++) {
		dinh[i].iHoanh /= k;
		dinh[i].iTung /= k;
	}
	cout << "Da giac sau khi thu nho: ";
	Xuat();
}

/*
ham ve da giac tren man hinh console
input: toa do cac dinh cua da giac
output: da giac duoc ve tren man hinh console
*/
void DaGiac::VeDaGiac() {
	if (n <= 1) return;

	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);

	int ox = 400, oy = 300;

	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;

		MoveToEx(hdc,
			ox + (int)dinh[i].iHoanh,
			oy - (int)dinh[i].iTung,
			NULL);

		LineTo(hdc,
			ox + (int)dinh[j].iHoanh,
			oy - (int)dinh[j].iTung);
	}

	ReleaseDC(hwnd, hdc);
}
