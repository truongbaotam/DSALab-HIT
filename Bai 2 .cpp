//#include <iostream>
//#include <iomanip> 
//using namespace std;
//
//
//void nhanMaTran(int A[][10], int B[][10], int C[][10], int n) {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            C[i][j] = 0;
//            for (int k = 0; k < n; k++) C[i][j] += A[i][k] * B[k][j];
//        }
//    }
//}
//
//
//int dinhThuc3x3(int M[3][3]) {
//    return M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1])
//        - M[0][1] * (M[1][0] * M[2][2] - M[1][2] * M[2][0])
//        + M[0][2] * (M[1][0] * M[2][1] - M[1][1] * M[2][0]);
//}
//
//int main() {
//    int n = 3;
//    int A[10][10] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
//    int B[10][10] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
//    int C[10][10];
//
//    nhanMaTran(A, B, C, n);
//
//    cout << "Ket qua nhan hai ma tran:\n";
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) cout << setw(5) << C[i][j];
//        cout << "\n";
//    }
//
//    int M[3][3] = { {1, 2, 3}, {0, 1, 4}, {5, 6, 0} };
//    cout << "\nDinh thuc ma tran M (3x3): " << dinhThuc3x3(M) << "\n";
//    return 0;
//}