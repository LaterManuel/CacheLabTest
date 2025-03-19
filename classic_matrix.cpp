#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int N = 1024; 

int main() {
    vector<double> A(N*N, 1.0); 
    vector<double> B(N*N, 2.0); 
    vector<double> C(N*N, 0.0);

    auto start = high_resolution_clock::now();

    // Multiplicación clásica
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            double sum = 0.0;
            for (int k = 0; k < N; ++k) {
                sum += A[i*N + k] * B[k*N + j];
            }
            C[i*N + j] = sum;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    
    cout << "Tiempo clásico: " << duration.count() << " ms" << endl;
    return 0;
}