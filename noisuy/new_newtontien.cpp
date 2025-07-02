#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define MAX 100

// Hàm g(x) nếu cần dùng công thức hàm f(x)
double f(double x) {
    return pow(2, x) / (x * x + 1);
}

// Giai thừa
int gt(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * gt(n - 1);
}

int main() {
    int n;
    double x[MAX], y[MAX], delta[MAX][MAX];
    double xp, h, p, ketqua, p_tich;

    // Nhập số điểm và bảng (x, y)
    cout << "Nhap so diem n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];

        cout << "y[" << i << "] = ";
        cin >> y[i];

        delta[i][0] = y[i];  // Sai phân cấp 0
    }

    // Kiểm tra xem x có cách đều không
    h = x[1] - x[0];
    for (int i = 1; i < n - 1; i++) {
        if (fabs((x[i + 1] - x[i]) - h) > 1e-6) {
            cout << "Loi: cac moc x khong cach deu!\n";
            return 1;
        }
    }

    // Tính bảng sai phân tiến
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            delta[i][j] = delta[i + 1][j - 1] - delta[i][j - 1];
        }
    }

    // In bảng sai phân
    cout << "\nBang sai phan tien:\n";
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << "x = " << x[i] << ":\t";
        for (int j = 0; j < n - i; j++) {
            cout << fixed << setprecision(6) << delta[i][j] << "\t";
        }
        cout << endl;
    }

    // Nhập giá trị cần nội suy
    cout << "\nNhap gia tri x can noi suy: ";
    cin >> xp;

    // Tính p = (xp - x0) / h
    p = (xp - x[0]) / h;

    // Áp dụng công thức nội suy Newton tiến
    ketqua = delta[0][0]; // Term đầu tiên
    p_tich = 1.0;

    for (int i = 1; i < n; i++) {
        p_tich *= (p - (i - 1));
        ketqua += (p_tich * delta[0][i]) / gt(i);
    }

    cout << fixed << setprecision(6);
    cout << "\n=> Gia tri noi suy tai x = " << xp << " la y = " << ketqua << endl;

    return 0;
}
