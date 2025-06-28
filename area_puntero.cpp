//https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
#include <iostream>
using namespace std;

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

void ejecutar(float (*funcion[])(float*, float*), float* parametros, const char* nombres[]) {
    const int numFiguras = 4;
    for(int i = 0; i < numFiguras; i++) {
        cout << "Area del " << nombres[i]
             << " con " << parametros[i*2] << " y " << parametros[i*2+1] << " :" << endl;
        cout << funcion[i](&parametros[i*2], &parametros[i*2+1]) << endl;
    }
}

int main() {
 float parametros[] = {8.0f, 2.0f,   // Rectángulo (base, altura)
                      7.0f, 4.0f,   // Triángulo (base, altura)
                      3.0f, 0.0f,   // Círculo (radio, placeholder)
                      6.0f, 6.0f};  // Cuadrado (lado, lado)

    const char* nombres[] = {"Rectangulo", "Triangulo", "Circulo", "Cuadrado"};

    float (*funciones[])(float*, float*) = {areaRectangulo, areaTriangulo, areaCirculo, areaCuadrado};

    ejecutar(funciones, parametros, nombres);

    return 0;
}
