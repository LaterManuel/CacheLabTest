#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> // para std::fill

using namespace std;

const int MAX = 1500;

int main() {
    // Inicialización de la matriz A y vectores x, y.
    vector<vector<double>> A(MAX, vector<double>(MAX, 1.0));
    vector<double> x(MAX, 1.0);
    vector<double> y(MAX, 0.0);
    
    // Primer par de bucles: acceso por filas
    auto start_row = chrono::high_resolution_clock::now();
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            y[i] += A[i][j] * x[j];
        }
    }
    auto end_row = chrono::high_resolution_clock::now();
    auto time_row = chrono::duration_cast<chrono::milliseconds>(end_row - start_row).count();
    
    cout << "Tiempo acceso por filas: " << time_row << " ms para " << MAX << " dimensiones" << endl;
    
    // Reinicializar el vector y para la siguiente prueba.
    fill(y.begin(), y.end(), 0.0);
    
    // Segundo par de bucles: acceso por columnas
    auto start_col = chrono::high_resolution_clock::now();
    for (int j = 0; j < MAX; ++j) {
        for (int i = 0; i < MAX; ++i) {
            y[i] += A[i][j] * x[j];
        }
    }
    auto end_col = chrono::high_resolution_clock::now();
    auto time_col = chrono::duration_cast<chrono::milliseconds>(end_col - start_col).count();
    
    cout << "Tiempo acceso por columnas: " << time_col << " ms para "<< MAX << " dimensiones" << endl;
    
    return 0;
}
