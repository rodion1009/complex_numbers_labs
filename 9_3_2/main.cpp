//4. Для заданной матрицы комплексных чисел A(n × n) найти C = (3.2 + 1.8·i) · A^t − A^2

#include <iostream>
#include <complex>
#include <fstream>

using namespace std;

int main(void) {

    ifstream input;
    input.open("/Users/rodion/Desktop/input.txt");
    
    int n;
    input >> n;
    cout << n << endl;
    
    complex<double> c1(3.2, 1.8);
    
    //Инициализация матрицы комплексных чисел
    complex<double> **A = new complex<double> *[n];
    for (int i = 0; i < n; i++) {
            A[i] = new complex<double> [n];
    }
    
    //Инициализация матрицы в квадрате
    complex<double> **AA = new complex<double> *[n];
    for (int i = 0; i < n; i++) {
        AA[i] = new complex<double> [n];
    }
    
    //Инициализация транспонированной матрицы
    complex<double> **At = new complex<double> *[n];
    for (int i = 0; i < n; i++) {
        At[i] = new complex<double> [n];
    }
    
    //Инициализация результирующей матрицы
    complex<double> **C = new complex<double> *[n];
    for (int i = 0; i < n; i++) {
        C[i] = new complex<double> [n];
    }
    
    //Заполнение матрицы из файла и вывод на экран
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input >> A[i][j];
            cout << A[i][j];
        }
        cout << endl;
    }
    
    //Возведение матрицы в квадрат
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AA[i][j] = 0;
            for (int k = 0; k < n; k++) {
                AA[i][j] += A[i][k] * A[k][j];
            }
        }
    }
    
    //Транспонирование матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            At[i][j] = A[j][i];
        }
    }
    
    cout << endl << "Получившаяся матрица: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = At[i][j] * c1;
            C[i][j] -= AA[i][j];
            cout << C[i][j];
        }
        cout << endl;
    }

    input.close();
    return 0;
}
