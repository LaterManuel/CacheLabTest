package main

import (
	"fmt"
	"time"
)

const N = 1024

func main() {
	A := make([]float64, N*N)
	B := make([]float64, N*N)
	C := make([]float64, N*N)

	// Inicialización
	for i := range A {
		A[i] = 1.0
		B[i] = 2.0
	}

	start := time.Now()

	// Multiplicación clásica
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			sum := 0.0
			for k := 0; k < N; k++ {
				sum += A[i*N+k] * B[k*N+j]
			}
			C[i*N+j] = sum
		}
	}

	elapsed := time.Since(start)
	fmt.Printf("Tiempo clásico: %s\n", elapsed)
}
