#include <iostream>


float areaRectangulo(float* base, float* altura) {
    return (*base) * (*altura);
}

float areaTriangulo(float* base, float* altura) {
    return ((*base) * (*altura)) / 2.0f;
}

float areaCirculo(float* radio, float*) {
    return (*radio) * (*radio) * 3.1416f;
}

float areaCuadrado(float* lado, float*) {
    return (*lado) * (*lado);
}

// Función que recibe puntero a función, array de parámetros y array de nombres
void ejecutar(float (*funcion[])(float*, float*), float* parametros, const char* nombres[]) {
    // Definimos el número de figuras
    const int numFiguras = 4;  // Rectángulo, Triángulo, Círculo y Cuadrado
    
    for(int i = 0; i < numFiguras; i++) {
        // Usamos directamente la función del array
        std::cout << "Área del " << nombres[i] << ": ";
        
        // Llamamos a la función con los parámetros correctos
        std::cout << funcion[i](&parametros[i*2], &parametros[i*2+1]) << std::endl;
    }
}

int main() {
    // Definimos los parámetros para todas las figuras en un solo array
    float params[] = {5.0f, 3.0f,  // Rectángulo (base, altura)
                     5.0f, 3.0f,  // Triángulo (base, altura)
                     5.0f, 0.0f,  // Círculo (radio, placeholder)
                     5.0f, 5.0f}; // Cuadrado (lado, lado)

    // Definimos los nombres
    const char* nombres[] = {"Rectángulo", "Triángulo", "Círculo", "Cuadrado"};

    // Definimos el array de funciones
    float (*funciones[])(float*, float*) = {areaRectangulo, areaTriangulo, areaCirculo, areaCuadrado};

    // Ejecutamos todas las figuras usando un solo array de parámetros
    ejecutar(funciones, &params[0], nombres);

    return 0;
}
