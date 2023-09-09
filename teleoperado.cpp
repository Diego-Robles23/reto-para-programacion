#include <iostream>
#include <string>
#include <chrono>

int main() {
    char opcion;
    int tiempo_acumulado = 0;

    while (tiempo_acumulado < 165) { 
        std::cout << "Elija un botón: a, b, c, d): " << std::endl;
        std::cout << "Boton a) Avanzar / Retroceder" << std::endl;
        std::cout << "Boton b) Girar Izquierda / Derecha" << std::endl;
        std::cout << "Boton c) Bajar / Subir la polea" << std::endl;
        std::cout << "Boton d) Abrir / Cerrar los brazos" << std::endl;
        std::cin >> opcion;

        if (opcion == 'a') {
            std::string accion;
            int tiempo;

            std::cout << "¿El robot avanza o retrocede?";
            std::cin >> accion;

            std::cout << "¿Por cuánto tiempo (en segundos)? ";
            std::cin >> tiempo;

            std::cout << "El robot " << accion << " durante " << tiempo << " segundos." << std::endl;

            tiempo_acumulado += tiempo;
        } else if (opcion == 'b') {
            std::string accion;
            int tiempo;

            std::cout << "¿¿El robot gira a la izquierda o a la derecha? ";
            std::cin >> accion;

            std::cout << "¿Por cuánto tiempo (en segundos)? ";
            std::cin >> tiempo;

            std::cout << "El robot giró " << accion << " durante " << tiempo << " segundos." << std::endl;

            tiempo_acumulado += tiempo;
        } else if (opcion == 'c') {
            std::string accion;
            int tiempo;

            std::cout << "¿Desea bajar o subir la polea? ";
            std::cin >> accion;

            std::cout << "¿Por cuánto tiempo (en segundos)? ";
            std::cin >> tiempo;

            std::cout << "El robot " << accion << " la polea durante " << tiempo << " segundos." << std::endl;

            tiempo_acumulado += tiempo;
        } else if (opcion == 'd') {
            std::string accion;
            int tiempo;

            std::cout << "¿Desea abrir o cerrar los brazos? ";
            std::cin >> accion;

            std::cout << "¿Por cuánto tiempo (en segundos)? ";
            std::cin >> tiempo;

            std::cout << "El robot " << accion << " la garra durante " << tiempo << " segundos." << std::endl;

            tiempo_acumulado += tiempo;
        } else {
            std::cout << "El botón no existe. Por favor, elija de nuevo." << std::endl;
        }

        if (tiempo_acumulado >= 135 && tiempo_acumulado < 165) { 
            std::cout << "--- Quedan 30 segundos, recomendamos dirigirte a la zona de salida ---" << std::endl;
        }
    }

    if (tiempo_acumulado >= 165) { 
        std::cout << "Se acabo el tiempo." << std::endl;
    }

    return 0;
}

