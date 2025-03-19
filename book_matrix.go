package main

import (
	"fmt"
	"time"
)

const MAX = 1500

func main() {
	// Inicialización de la matriz A y de los vectores x e y.
	A := make([][]float64, MAX)
	for i := range A {
		A[i] = make([]float64, MAX)
		for j := range A[i] {
			A[i][j] = 1.0
		}
	}

	x := make([]float64, MAX)
	for i := range x {
		x[i] = 1.0
	}

	// Inicializamos el vector y para la primera prueba.
	y := make([]float64, MAX)

	// Primer par de bucles: acceso por filas.
	startRow := time.Now()
	for i := 0; i < MAX; i++ {
		for j := 0; j < MAX; j++ {
			y[i] += A[i][j] * x[j]
		}
	}
	elapsedRow := time.Since(startRow)
	fmt.Printf("Tiempo acceso por filas: %d ms para %d dimensiones\n", elapsedRow.Milliseconds(), MAX)

	// Reinicializamos el vector y para la siguiente prueba.
	for i := range y {
		y[i] = 0.0
	}

	// Segundo par de bucles: acceso por columnas.
	startCol := time.Now()
	for j := 0; j < MAX; j++ {
		for i := 0; i < MAX; i++ {
			y[i] += A[i][j] * x[j]
		}
	}
	elapsedCol := time.Since(startCol)
	fmt.Printf("Tiempo acceso por columnas: %d ms para %d dimensiones\n", elapsedCol.Milliseconds(), MAX)

}
