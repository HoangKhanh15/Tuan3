﻿#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int Menu() {
	int Chon;
	printf("\n\t\tMenu\n");
	printf("1. Tao va xuat ma tran\n");
	printf("2. Tong cua tung dong\n");
	printf("3. Phan tu lon nhat cua tung cot\n");
	printf("4. Xuat cac phan tu thuoc cac duong bien\n");
	printf("5. Xuat cac phan tu cuc dai\n");
	printf("6. Xuat cac phan tu hoang hau\n");
	printf("7. Xuat cac phan tu la diem yen ngua\n");
	printf("8. Xuat dong chi chua so chan\n");
	printf("9. Sap xep cac dong tang dan\n");
	printf("0. Thoat\n");
	printf("Nhap lua chon cua ban: ");
	scanf("%d", &Chon);
	return Chon;
}

void TaoMang2CNgauNhien(int a[][MAX], int n, int m) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % 100;
		}
	}
}

void InMang(int a[][MAX], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void TongCuaTungDong(int a[][MAX], int n, int m) {
	printf("Tong cua tung dong:\n");
	for (int i = 0; i < n; i++) {
		int tong = 0;
		for (int j = 0; j < m; j++) {
			tong += a[i][j];
		}
		printf("Tong dong %d: %d\n", i + 1, tong);
	}
}

void PhanTuLonNhatTungCot(int a[][MAX], int n, int m) {
	printf("Phan tu lon nhat cua tung cot:\n");
	for (int j = 0; j < m; j++) {
		int max = a[0][j];
		for (int i = 1; i < n; i++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
		printf("Cot %d: %d\n", j + 1, max);
	}
}

void DuongBien(int a[][MAX], int n, int m) {
	printf("Cac phan tu thuoc duong bien:\n");

	// Đường biên trên
	for (int j = 0; j < m; j++) {
		printf("%d ", a[0][j]);
	}

	// Đường biên phải
	for (int i = 1; i < n; i++) {
		printf("%d ", a[i][m - 1]);
	}

	// Đường biên dưới
	if (n > 1) {
		for (int j = m - 2; j >= 0; j--) {
			printf("%d ", a[n - 1][j]);
		}
	}

	// Đường biên trái
	if (m > 1) {
		for (int i = n - 2; i > 0; i--) {
			printf("%d ", a[i][0]);
		}
	}
	printf("\n");
}

void PhanTuCucDai(int a[][MAX], int n, int m) {
	int max = a[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
	}
	printf("Cac phan tu cuc dai:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == max) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

void PhanTuHoangHau(int a[][MAX], int n, int m) {
	printf("Cac phan tu hoang hau:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int isHoangHau = 1;
			for (int k = 0; k < m; k++) {
				if (a[i][k] >= a[i][j]) {
					continue;
				}
				isHoangHau = 0;
				break;
			}
			for (int k = 0; k < n; k++) {
				if (a[k][j] >= a[i][j]) {
					continue;
				}
				isHoangHau = 0;
				break;
			}
			if (isHoangHau) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

void DiemYenNgua(int a[][MAX], int n, int m) {
	printf("Cac phan tu diem yen ngua:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int minRow = 1, maxCol = 1;
			for (int k = 0; k < m; k++) {
				if (a[i][k] < a[i][j]) {
					minRow = 0;
					break;
				}
			}
			for (int k = 0; k < n; k++) {
				if (a[k][j] > a[i][j]) {
					maxCol = 0;
					break;
				}
			}
			if (minRow && maxCol) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

void DongChiChuaSoChan(int a[][MAX], int n, int m) {
	printf("Cac dong chi chua so chan:\n");
	for (int i = 0; i < n; i++) {
		int hasEven = 0;
		for (int j = 0; j < m; j++) {
			if (a[i][j] % 2 == 0) {
				hasEven = 1;
				break;
			}
		}
		if (hasEven) {
			for (int j = 0; j < m; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}

void SapXepDongTangDan(int a[][MAX], int n, int m) {
	printf("Sap xep cac dong tang dan:\n");
	for (int i = 0; i < n; i++) {
		// Sắp xếp dòng i theo thứ tự tăng dần
		for (int j = 0; j < m - 1; j++) {
			for (int k = j + 1; k < m; k++) {
				if (a[i][j] > a[i][k]) {
					int temp = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = temp;
				}
			}
		}
	}
	InMang(a, n, m);
}

void XuLyMenu(int Chon, int a[][MAX], int n, int m) {
	switch (Chon) {
	case 1:
		printf("-------Mang 2 chieu random----------\n");
		TaoMang2CNgauNhien(a, n, m);
		InMang(a, n, m);
		break;
	case 2:
		TongCuaTungDong(a, n, m);
		break;
	case 3:
		PhanTuLonNhatTungCot(a, n, m);
		break;
	case 4:
		DuongBien(a, n, m);
		break;
	case 5:
		PhanTuCucDai(a, n, m);
		break;
	case 6:
		PhanTuHoangHau(a, n, m);
		break;
	case 7:
		DiemYenNgua(a, n, m);
		break;
	case 8:
		DongChiChuaSoChan(a, n, m);
		break;
	case 9:
		SapXepDongTangDan(a, n, m);
		break;
	case 0:
		printf("Thoat chuong trinh.\n");
		exit(0);
	default:
		printf("Lua chon khong hop le!\n");
		break;
	}
}

int main() {
	int Chon, n, m;
	int a[MAX][MAX];

	printf("Nhap kich thuoc dong: ");
	scanf("%d", &n);
	printf("Nhap kich thuoc cot: ");
	scanf("%d", &m);

	while (1) { // Vòng lặp menu
		Chon = Menu();
		XuLyMenu(Chon, a, n, m);
	}

	return 0;
}
