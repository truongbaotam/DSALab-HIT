//#include <iostream>
//using namespace std;
//
//int main() {
//    int n;
//    cout << "Nhap so phan tu n: "; cin >> n;
//    int a[100]; 
//
//    cout << "Nhap mang: ";
//    for (int i = 0; i < n; i++) cin >> a[i];
//
//    int min = a[0], max = a[0], tong = 0;
//    for (int i = 0; i < n; i++) {
//        if (a[i] < min) min = a[i];
//        if (a[i] > max) max = a[i];
//        tong += a[i];
//    }
//
//    cout << "Min: " << min << "\nMax: " << max << "\n";
//    cout << "Tong: " << tong << "\nTrung binh: " << (float)tong / n << "\n";
//    return 0;
//}