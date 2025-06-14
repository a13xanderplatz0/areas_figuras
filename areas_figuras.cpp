#include <iostream>
#include <string>
#include <vector>


int areaRectangulo(int base, int altura) {
    return base * altura;
}

int areaTriangulo(int base, int altura) {
    return (base * altura) / 2;
}

int areaCirculo(int radio , int ) {
    return radio * radio * 3.1416;
}

int areaCuadrado(int lado, int ){
    return lado * lado;
}

// Funcion que recibe puntero a funcion, array de parametros y array de nombres
void ejecutar(int (*funcion)(int, int), int params[], std::string nombres[]) {
    
    std::cout << "Area del " << nombres[0] << ": ";
    
    // Llamamos a la funcion con los parametros
    std::cout << funcion(params[0], params[1]) << std::endl;
}

int main() {
    // Definimos los parametros para cada figura
    int paramsRectangulo[] = {5, 3};  // base y altura
    int paramsTriangulo[] = {5, 3};   // base y altura
    int paramsCirculo[] = {5, 0};     // radio y un 0 como placeholder
    int paramsCuadrado[]={5, 5};      // lado al cuadrado

    // Definimos los nombres
    std::string nombres[] = {"Rectángulo", "Triángulo", "Círculo", "Cuadrado"};

    // Ejecutamos para cada figura
    ejecutar(areaRectangulo, paramsRectangulo, nombres);
    ejecutar(areaTriangulo, paramsTriangulo, nombres + 1); // +1 para apuntar al siguiente nombre
    ejecutar(areaCirculo, paramsCirculo, nombres + 2);     // +2 para apuntar al siguiente nombre
    ejecutar(areaCuadrado, paramsCuadrado,nombres + 3);

    return 0;
}
