#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int Menu() {
	int Chon;
	printf("\n\t\tMenu\n");
	printf("1. Tao va xuat ma tran\n");
	printf("2. Xuat cac phan tu tren duong cheo chinh\n");
	printf("3. Xuat cac phan tu thuoc duong cheo song song voi duong cheo chinh\n");
	printf("4. Tim phan tu max thuoc tam giac tren cua duong cheo chinh\n");
	printf("5. Sap xep ma tran tang dan theo kieu zic-zac\n");
	printf("6. Sap xep duong cheo chinh tang dan tu tren xuong duoi\n");
	printf("0. Thoat\n");
	printf("Nhap lua chon cua ban: ");
	scanf("%d", &Chon);
	return Chon;
}

void TaoMang2CNgauNhien(int a[][MAX], int n) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 100;
		}
	}
}

void InMang(int a[][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
void XuatDuongCheoChinh(int a[][MAX], int n) {
	printf("Cac phan tu tren duong cheo chinh:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i][i]);
	}
	printf("\n");
}

void XuatDuongCheoPhu(int a[][MAX], int n) {
	printf("Cac phan tu thuoc duong cheo song song voi duong cheo chinh:\n");
	for (int k = 1; k < n; k++) {
		printf("Cheo phu tren dong %d: ", k);
		for (int i = 0, j = k; j < n; i++, j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
		printf("Cheo phu tren cot %d: ", k);
		for (int i = k, j = 0; i < n; i++, j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
void TimMaxTamGiacTrenCheoChinh(int a[][MAX], int n) {
	int max = a[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
	}
	printf("Phan tu lon nhat thuoc tam giac tren cua duong cheo chinh: %d\n", max);
}
void XuLyMenu(int Chon, int a[][MAX], int n) {
	switch (Chon) {
	case 1:
		printf("-------Mang 2 chieu random----------\n\n");
		TaoMang2CNgauNhien(a, n);
		InMang(a, n);
		break;
	case 2:
		XuatDuongCheoChinh(a, n);
		break;
		
	case 3:
		XuatDuongCheoPhu(a, n);
		break;
		
	case 4:
		TimMaxTamGiacTrenCheoChinh(a, n);
		break;
	case 5:
		
	case 6:
		
	case 0:
		printf("Thoat chuong trinh.\n");
		exit(0);
	default:
		printf("Lua chon khong hop le!\n");
		break;
	}
}

int main() {
	int Chon, n;
	int a[MAX][MAX];

	do {
		printf("Nhap kich thuoc ma tran vuong (>= 5): ");
		scanf_s("%d", &n);
	} while (n < 5);

	while (1) { // Vòng lặp menu
		Chon = Menu();
		XuLyMenu(Chon, a, n);
	}

	return 0;
}
