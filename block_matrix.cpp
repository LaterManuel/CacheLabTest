#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int N = 1024;      
const int BLOCK_SIZE = 128; 
int main() {
    vector<double> A(N*N, 1.0);
    vector<double> B(N*N, 2.0); 
    vector<double> C(N*N, 0.0);

    auto start = high_resolution_clock::now();

    // Multiplicación por bloques 
    for (int ii = 0; ii < N; ii += BLOCK_SIZE) {       
        for (int jj = 0; jj < N; jj += BLOCK_SIZE) {   
            for (int kk = 0; kk < N; kk += BLOCK_SIZE) { 
                for (int i = ii; i < min(ii + BLOCK_SIZE, N); ++i) {
                    for (int j = jj; j < min(jj + BLOCK_SIZE, N); ++j) {
                        double sum = C[i*N + j];
                        for (int k = kk; k < min(kk + BLOCK_SIZE, N); ++k) {
                            sum += A[i*N + k] * B[k*N + j];
                        }
                        C[i*N + j] = sum;
                    }
                }
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    
    cout << "Tiempo bloques: " << duration.count() << " ms" << endl;
    return 0;
}