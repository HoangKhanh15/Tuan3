#include <stdio.h>
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
	scanf_s("%d", &Chon); // Dùng scanf để đơn giản hơn
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
		printf("\n\n");
	}
}

// Các hàm xử lý khác sẽ được thêm vào đây

void XuLyMenu(int Chon, int a[][MAX], int n, int m) {
	switch (Chon) {
	case 1:
		printf("-------Mang 2 chieu random----------\n");
		TaoMang2CNgauNhien(a, n, m);
		InMang(a, n, m);
		break;
	case 2:
		// Xử lý tổng của từng dòng
		break;
	case 3:
		// Xử lý phần tử lớn nhất của từng cột
		break;
	case 4:
		// Xử lý các phần tử thuộc các đường biên
		break;
	case 5:
		// Xử lý các phần tử cực đại
		break;
	case 6:
		// Xử lý các phần tử hoàng hậu
		break;
	case 7:
		// Xử lý các phần tử là điểm yên ngựa
		break;
	case 8:
		// Xử lý dòng chứa số chẵn
		break;
	case 9:
		// Xử lý sắp xếp các dòng theo thứ tự tăng dần
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
	scanf_s("%d", &n);
	printf("Nhap kich thuoc cot: ");
	scanf_s("%d", &m);

	while (1) { // Vòng lặp menu
		Chon = Menu();
		XuLyMenu(Chon, a, n, m);
	}

	return 0;
}
