package main

import (
	"fmt"
	"time"
)

const (
	N = 1024
	B = 128
)

func main() {
	A := make([]float64, N*N)
	Bm := make([]float64, N*N)
	C := make([]float64, N*N)

	// Inicialización
	for i := range A {
		A[i] = 1.0
		Bm[i] = 2.0
	}

	start := time.Now()

	// Multiplicación por bloques
	for ii := 0; ii < N; ii += B {
		for jj := 0; jj < N; jj += B {
			for kk := 0; kk < N; kk += B {
				for i := ii; i < ii+B; i++ {
					for j := jj; j < jj+B; j++ {
						sum := C[i*N+j]
						for k := kk; k < kk+B; k++ {
							sum += A[i*N+k] * Bm[k*N+j]
						}
						C[i*N+j] = sum
					}
				}
			}
		}
	}

	elapsed := time.Since(start)
	fmt.Printf("Tiempo bloques: %s\n", elapsed)
}
