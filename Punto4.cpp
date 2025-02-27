#include <iostream>
#include <cmath>

// Definir la estructura de un punto en 2D
struct Point
{
    double x, y;
};

// Función para calcular la distancia entre dos puntos
/*Como puede modificar la declaración de la función para que sea mas eficiente en el manejo de memoria?
Teniendo en cuenta que solo necesita leer los valores, pero no modificarlos*/
double calcularDistancia(const Point p1,const Point p2)
{
    double x1, y1, x2, y2;
    double Distancia;
    x1 = p1.x; x2 = p2.x;
    y1 = p1.y; y2 = p2.y;
    Distancia = sqrt(pow((x1-x2),2) + pow((y1-y2),2));

    return Distancia;
}

// Función para leer las coordenadas de varios puntos
void leerPuntos(Point puntos[], int n)
{
    char respuesta;
    std::cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    std::cin >> respuesta;// Leer la respuesta del usuario

    // Completar: Verificar si la respuesta es 's' o 'n', tener en cuenta mayúsculas y minúsculas
    if (respuesta == 's')
    {
        // Completar: Leer las coordenadas de cada punto
        for (int i = 0; i < n; i ++)
        {
            std::cout << "Ingrese las coordenadas del punto " << i + 1 << " (x, y): " ;
            std::cout << "\nx: "; std::cin >> puntos[i].x;
            std::cout << "y: "; std::cin >> puntos[i].y;
        }
    }
    else if(respuesta == 'n')
    {
        // Usar puntos predeterminados
        std::cout << "Usando puntos predeterminados...\n";
        puntos[0] = {0, 0};  // Punto 1 (0, 0)
        puntos[1] = {3, 4};  // Punto 2 (3, 4)
        puntos[2] = {6, 8};  // Punto 3 (6, 8)
        puntos[3] = {9, 12}; // Punto 4 (9, 12)
    }
    else{
        std::cout<<"Su respuesta no esta en las posibilidades \n";
        exit(0);
    }//La ultima condición se da para evaluar la posibilidad de que se ponga un numero u otra letra, lo cual es incorrecto para las opciones propuestas
}

// Función para calcular la distancia más cercana desde un punto específico
double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, int &indiceMasCercano)
{
    float valor, distanciaMinima;
    distanciaMinima=calcularDistancia(puntos[0], pUsuario);
    for (int i = 0 ; i < n; i++){
    valor = calcularDistancia(puntos[i], pUsuario);
        if(valor < distanciaMinima){
            distanciaMinima = valor;
            indiceMasCercano = i;
        }
    }
    return distanciaMinima;

}

float Bono(Point puntos[], int n){
    int suma, total = 0;
    for (int i = 0 ; i < n - 1; i++){
        suma = calcularDistancia(puntos[i], puntos[i+1]);
            total += suma;
        }
    return total;
}


// Función para mostrar el punto más cercano y la distancia
void mostrarResultado(Point puntos[], int indiceMasCercano, double distancia)
{
    std::cout << "El punto más cercano es: (" << puntos[indiceMasCercano].x << ", " << puntos[indiceMasCercano].y << ")\n";
    std::cout << "La distancia al punto más cercano es: " << distancia << std::endl;
}

int main()
{
    int n, Sumadistancias;
    
    std::cout << "Ingrese el número de puntos (mínimo 2): ";
    // Leer el número de puntos
    std::cin >> n;

    if (n < 2)
    {
        std::cout << "Se necesitan al menos 2 puntos para calcular las distancias.\n";
        return 1;
    }

    Point puntos[n]; // Arreglo de estructuras para almacenar las coordenadas (x, y)

    // Leer los puntos (manual o predeterminado)
    leerPuntos(puntos, n);
    n = sizeof(puntos)/sizeof(puntos[0]); //Redefine el vector para el caso en el que no se ingresen los puntos manualmente


    // Ingresar el punto del usuario
    Point pUsuario;
    std::cout << "Ingrese las coordenadas del punto desde el que calcular la distancia (x, y): ";
    std::cout << "\nx: "; std::cin >> pUsuario.x; 
    std::cout << "y: "; std::cin >> pUsuario.y;

    // Calcular la distancia más cercana
    int indiceMasCercano = 0;
    double distancia;
    distancia = calcularDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);

    mostrarResultado(puntos, indiceMasCercano, distancia);
    
    Sumadistancias =Bono(puntos, n);
    std:: cout << "\nLa suma de distancias es: " << Sumadistancias << "\n";
    return 0;
}