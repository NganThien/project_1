#include <iostream>
#include <cmath>

using namespace std;

int CT[10];
int n = 4;
int GTTN[10], kq;
int max1, max2, maxmoi1 = 0, maxmoi2 = 0;
int A[5], B[5];

// Khoi tao quan the
void Taoquanthe(int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap ca the thu " << i << ": ";
        cin >> CT[i];
    }
}

// Tinh gia tri thich nghi
void Giatrithichnghi(int n) {
    int gttn;
    for (int i = 0; i < n; i++) {
        gttn = (1000 - (CT[i] * CT[i] - 64));
        GTTN[i] = gttn;
    }
}

// Kiem tra gia tri thich nghi
int Kiemtra(int n) {
    for (int i = 0; i < n; i++) {
        if (GTTN[i] == 1000)
            return (CT[i]);
    }
    return 0;
}

// Tim ca the lai, chon loc lay 2 gia tri dau tien
void Timcathelai() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (GTTN[i] < GTTN[j]) {
                int tmp = GTTN[i];
                GTTN[i] = GTTN[j];
                GTTN[j] = tmp;
            }
        }
    }
    max1 = sqrt(1064 - GTTN[0]);
    max2 = sqrt(1064 - GTTN[1]);
}

// Lai ca the moi voi nhau tao quan the moi
void Laicathe() {
    for (int i = 0; i < 5; i++) {
        A[i] = 0;
        B[i] = 0;
    }
    while (max1 != 0) {
        for (int j = 0; j < 5; j++) {
            A[j] = max1 % 2;
            max1 = max1 / 2;
        }
    }
    while (max2 != 0) {
        for (int k = 0; k < 5; k++) {
            B[k] = max2 % 2;
            max2 = max2 / 2;
        }
    }
    for (int l = 4; l > 1; l--) {
        int tmp = A[l];
        A[l] = B[l];
        B[l] = tmp;
    }
    for (int m = 4; m > 0; m--) {
        maxmoi1 = maxmoi1 + A[m] * pow(2, m);
        maxmoi2 = maxmoi2 + B[m] * pow(2, m);
    }
}

// Tao quan the moi
void Taoquanthemoi() {
    CT[0] = max1;
    CT[1] = max2;
    CT[2] = maxmoi1;
    CT[3] = maxmoi2;
}

int main() {
    cout << "Giai phuong trinh: x^2 = 64 bang thuat toan di truyen." << endl;
    cout << "Tao quan the co 4 ca the." << endl;
    Taoquanthe(n);
    Giatrithichnghi(n);
    kq = Kiemtra(n);
    while (kq == 0) {
        Timcathelai();
        Laicathe();
        Taoquanthemoi();
        Giatrithichnghi(n);
        kq = Kiemtra(n);
    }
    cout << "Ket qua phuong trinh la: " << kq << endl;
    return 0;
}
