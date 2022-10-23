#include <iostream>

using namespace std;

// [Reference]: https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function

const int SIZE = 2;

void updateArray(int* arr) {
    arr[0] = 1;
}

void updateMatrix(int matrix[][SIZE]) {
    matrix[0][0] = 1;
}

void print(int matrix[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[SIZE] = {};
    updateArray(arr);
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    cout << endl;

    int matrix[SIZE][SIZE] = {};
    print(matrix);
    updateMatrix(matrix);
    print(matrix);

    return 0;
}

