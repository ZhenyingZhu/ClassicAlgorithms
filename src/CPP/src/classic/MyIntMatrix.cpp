#include <iostream>

using namespace std;

// [Source]: CTCI v5 Chapter 13.10

int** my2DMalloc(int row, int col) {
    int head = row * sizeof(int*);
    int data = row * col * sizeof(int);
    int **rowPt;
    if ( (rowPt = (int**)malloc(head + data)) == NULL )
        return NULL;

    int *buf = (int*)(rowPt + row); // since rowPt is int**, rowPt+1 means it moves a sizeof int* forward
    for (int i = 0; i < row; i++) {
        rowPt[i] = buf;
        buf += col * sizeof(int);
    }

    return rowPt;
}

int main() {
    int m = 2, n = 3;
    int **matrix = my2DMalloc(m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = i * n + j;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << "," << j << ": " << matrix[i][j] << endl;
        }
    }

    return 0;
}
