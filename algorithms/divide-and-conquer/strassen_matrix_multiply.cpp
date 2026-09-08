#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

// ฟังก์ชันสำหรับบวกเมทริกซ์
Matrix add(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

// ฟังก์ชันสำหรับลบเมทริกซ์
Matrix subtract(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] - B[i][j];
    return result;
}

// ฟังก์ชันสำหรับคูณเมทริกซ์ด้วย Strassen Algorithm
Matrix strassen(const Matrix &A, const Matrix &B) {
    int n = A.size();
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int mid = n / 2;

    // แบ่งเมทริกซ์ A และ B เป็น 4 ส่วน
    Matrix A11(mid, vector<int>(mid)), A12(mid, vector<int>(mid)), A21(mid, vector<int>(mid)), A22(mid, vector<int>(mid));
    Matrix B11(mid, vector<int>(mid)), B12(mid, vector<int>(mid)), B21(mid, vector<int>(mid)), B22(mid, vector<int>(mid));

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // คำนวณค่าช่วย M1 ถึง M7
    Matrix M1 = strassen(add(A11, A22), add(B11, B22));
    Matrix M2 = strassen(add(A21, A22), B11);
    Matrix M3 = strassen(A11, subtract(B12, B22));
    Matrix M4 = strassen(A22, subtract(B21, B11));
    Matrix M5 = strassen(add(A11, A12), B22);
    Matrix M6 = strassen(subtract(A21, A11), add(B11, B12));
    Matrix M7 = strassen(subtract(A12, A22), add(B21, B22));

    // คำนวณผลลัพธ์เมทริกซ์ C
    Matrix C11 = add(subtract(add(M1, M4), M5), M7);
    Matrix C12 = add(M3, M5);
    Matrix C21 = add(M2, M4);
    Matrix C22 = add(subtract(add(M1, M3), M2), M6);

    // รวมเมทริกซ์ย่อย C11, C12, C21, C22 เข้าด้วยกัน
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }

    return C;
}

// ฟังก์ชันแสดงเมทริกซ์
void printMatrix(const Matrix &M) {
    for (const auto &row : M) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // ตัวอย่างเมทริกซ์ 4x4
    Matrix A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    Matrix B = {
        {17, 18, 19, 20},
        {21, 22, 23, 24},
        {25, 26, 27, 28},
        {29, 30, 31, 32}
    };

    cout << "Matrix A:" << endl;
    printMatrix(A);

    cout << "Matrix B:" << endl;
    printMatrix(B);

    Matrix C = strassen(A, B);

    cout << "Result (A x B):" << endl;
    printMatrix(C);

    return 0;
}

