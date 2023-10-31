#include <iostream>
#include <ctime>
#include<Windows.h>

using namespace std;

template <typename T>
void initializeMatrix(T**& matrix, int size) {
    matrix = new T * [size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new T[size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = static_cast<T>(rand() % 100);
        }
    }
}

template <typename T>
void printMatrix(T** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
void findDiagonalMinMax(T** matrix, int size) {
    T max = matrix[0][0];
    T min = matrix[0][0];

    for (int i = 1; i < size; ++i) {
        if (matrix[i][i] > max) {
            max = matrix[i][i];
        }
        if (matrix[i][i] < min) {
            min = matrix[i][i];
        }
    }

    cout << "Max on the main diagonal: " << max << endl;
    cout << "Min on the main diagonal: " << min << endl;
}

template <typename T>
void sortRowsAscending(T** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            for (int k = 0; k < size - j - 1; ++k) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    T temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int size = 4;
    int** intMatrix = nullptr;
    double** doubleMatrix = nullptr;

    initializeMatrix(intMatrix, size);
    initializeMatrix(doubleMatrix, size);

    cout << "Initialized integer matrix:" << endl;
    printMatrix(intMatrix, size);
    findDiagonalMinMax(intMatrix, size);
    sortRowsAscending(intMatrix, size);
    cout << "Integer matrix with rows sorted in ascending order:" << endl;
    printMatrix(intMatrix, size);

    cout << "Initialized double matrix:" << endl;
    printMatrix(doubleMatrix, size);
    findDiagonalMinMax(doubleMatrix, size);
    sortRowsAscending(doubleMatrix, size);
    cout << "Double matrix with rows sorted in ascending order:" << endl;
    printMatrix(doubleMatrix, size);

    for (int i = 0; i < size; ++i) {
        delete[] intMatrix[i];
        delete[] doubleMatrix[i];
    }
    delete[] intMatrix;
    delete[] doubleMatrix;

    return 0;
}
