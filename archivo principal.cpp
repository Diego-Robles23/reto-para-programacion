#include<iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include <string>
#include <locale.h>

//Todas las variables y constantes//
 double pesorobot = 50.0;
    const int tiempotot = 15;
    int tiempotr = 0;
    double distanciare = 1.0;
    double velocidadmotor = 0.7;
    char opcion;
    int tiempo_acumulado = 0;

//formula para calcular el tiempo en base a la distancia, peso y motor del robot//

double calculotiempo(double distancia, double velocidad, double peso){
    return std::abs(distancia)/(std::abs(velocidad)*(peso/50.0));
}

//Funcion que define el tiempo de cada movimiento//

void controlarobot(const std::string &accion, double distancia, double velocidad, double peso, int &tiempotr){
    double tiempo = calculotiempo(distancia, velocidad, peso);
    if (accion == "gira a la derecha" || accion== "gira a la izquierda" || accion== "deja herramientas" ){
        tiempo = 1.5;
    }
    else if (accion == "toma la llanta" || accion == "deja la llanta" || accion == "coloca la llanta" ){
        tiempo = 4.0;
    }
    else if (accion == "toma 3 herramientas"){
        tiempo = 7;
    }
    std::cout << "El robot " << accion << " durante " << tiempo << " segundos" << std::endl;
    tiempotr += static_cast<int>(tiempo);
    std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(1)));
}

//Las 3 funciones que realiza el autonomo//

void quitar_llantas(){

    controlarobot("avanza", distanciare, velocidadmotor, pesorobot, tiempotr);
    controlarobot("gira a la derecha", 0, 0.5, pesorobot, tiempotr);
    controlarobot("toma la llanta", 0, 0, pesorobot, tiempotr);
    controlarobot("gira a la derecha", 0, 0.5, pesorobot, tiempotr);
    controlarobot("avanza de regreso", distanciare, velocidadmotor, pesorobot, tiempotr);
    controlarobot("deja la llanta", 0, 0, pesorobot, tiempotr);

    int tiemporest = tiempotot - tiempotr;
    std::cout << "\ntiempo utilizado: " << tiempotr << " segundos" << std::endl;
    if (tiemporest > 0) {
        std::cout << "tiempo restante: " << tiemporest << " segundos." << std::endl;
    } else {
        std::cout << "el robot uso todo el tiempo" << std::endl;
    }


}

void poner_llantas(){

    controlarobot("gira a la izquierda", 0, 0.5, pesorobot, tiempotr);
    controlarobot("avanza", distanciare, velocidadmotor, pesorobot, tiempotr);
    controlarobot("toma la llanta", 0, 0, pesorobot, tiempotr);
    controlarobot("gira a la derecha", 0, 0.5, pesorobot, tiempotr);
    controlarobot("avanza", distanciare, velocidadmotor, pesorobot, tiempotr);
    controlarobot("gira a la derecha", 0, 0.5, pesorobot, tiempotr);
    controlarobot("coloca la llanta", 0, 0, pesorobot, tiempotr);
    controlarobot("gira a la izquierda", 0, 0.5, pesorobot, tiempotr);
    controlarobot("avanza de regreso", distanciare, velocidadmotor, pesorobot, tiempotr);



    int tiemporest = tiempotot - tiempotr;
    std::cout << "\ntiempo utilizado: " << tiempotr << " segundos" << std::endl;
    if (tiemporest > 0) {
        std::cout << "tiempo restante: " << tiemporest << " segundos." << std::endl;
    } else {
        std::cout << "el robot uso todo el tiempo" << std::endl;
    }

   }
void limpiar_herramientas(){

  controlarobot("avanza", distanciare, velocidadmotor, pesorobot, tiempotr);
  controlarobot("gira a la izquierda", 0, 0.5, pesorobot, tiempotr);
  controlarobot("avanza", distanciare, velocidadmotor, pesorobot, tiempotr);
  controlarobot("gira a la izquierda", 0, 0.5, pesorobot, tiempotr);
  controlarobot("toma 3 herramientas", 0, 0, pesorobot, tiempotr);
  controlarobot("gira a la izquierda", 0, 0.5, pesorobot, tiempotr);
  controlarobot("avanza de regreso", distanciare, velocidadmotor, pesorobot, tiempotr);
  controlarobot("deja herramientas", 0, 0.5, pesorobot, tiempotr);

    int tiemporest = tiempotot - tiempotr;
    std::cout << "\ntiempo utilizado: " << tiempotr << " segundos" << std::endl;
    if (tiemporest > 0) {
        std::cout << "tiempo restante: " << tiemporest << " segundos" << std::endl;
    } else {
        std::cout << "el robot uso todo el tiempo" << std::endl;
    }

   }   
int main(){
 
  char opcion;
  std::cout<<"--AUTONOMO--"<<std::endl;
 
 do{  
  std::cout<<"1.- Quitar llantas "<<std::endl;
  std::cout<<"2.- Poner llantas "<<std::endl;
  std::cout<<"3.- Limpiar zona de herramientas "<<std::endl;
  std::cout<<"\nEscoga una de las tres opciones para realizar: "<<std::endl;
  std::cin>>opcion;

  if (opcion=='1'){
   quitar_llantas();
  }
  else if (opcion=='2'){
    poner_llantas();
  }
  else if (opcion=='3'){

    limpiar_herramientas();
  }
  else{
  std::cout<<"\nIngrese una opcion valida. "<<std::endl;
  }} while (opcion != '1' && opcion != '2' && opcion != '3');

  

  std::cout<<"\n\n--- Ingresando al teleoperado... ---\n\n"<<std::endl;
  while (tiempo_acumulado < 165) { 
      
        std::cout << "Elija un botón: a, b, c, d: " << std::endl;
        std::cout << "Boton a) Avanzar / Retroceder" << std::endl;
        //boton a) Controlador Spark max conectado al puerto 16//

        std::cout << "Boton b) Girar Izquierda / Derecha" << std::endl;
        //boton b) Controlador Spark max conectado al puerto 17//

        std::cout << "Boton c) Bajar / Subir la polea" << std::endl;
        //boton c) Controlador Spark max conectado al puerto 10//

        std::cout << "Boton d) Abrir / Cerrar los brazos" << std::endl;
        //boton d) Controlador Spark max conectado al puerto 11//
        std::cin >> opcion;

        if (opcion == 'a') {
            std::string accion;
            int tiempo;

            std::cout << "\n¿El robot avanza o retrocede? \n";
            std::cin >> accion;

            std::cout << "¿Por cuánto tiempo (en segundos)? \n";
            std::cin >> tiempo;

            std::cout << "El robot " << accion << " durante " << tiempo << " segundos" << std::endl;

            tiempo_acumulado += tiempo;
        } else if (opcion == 'b') {
            std::string accion;
            int tiempo;

            std::cout << "\n¿El robot gira a la izquierda o a la derecha? \n";
            std::cin >> accion;

            std::cout << "¿Por cuánto tiempo (en segundos)? \n";
            std::cin >> tiempo;

            std::cout << "El robot giró a la " << accion << " durante " << tiempo << " segundos" << std::endl;

            tiempo_acumulado += tiempo;
        } else if (opcion == 'c') {
            std::string accion;
            int tiempo;

            std::cout << "\n¿Desea bajar o subir la polea? \n";
            std::cin >> accion;

            std::cout << "¿Por cuánto tiempo (en segundos)? \n";
            std::cin >> tiempo;

            std::cout << "El robot hizo " << accion << " la polea durante " << tiempo << " segundos" << std::endl;

            tiempo_acumulado += tiempo;
        } else if (opcion == 'd') {
            std::string accion;
            int tiempo;

            std::cout << "\n¿Desea abrir o cerrar los brazos? \n";
            std::cin >> accion;

            std::cout << "¿Por cuánto tiempo (en segundos)? \n";
            std::cin >> tiempo;

            std::cout << "El robot hizo " << accion << " la garra durante " << tiempo << " segundos" << std::endl;

            tiempo_acumulado += tiempo;
        } else {
            std::cout << "El botón no existe. Por favor, elija de nuevo." << std::endl;
        }

        int tiempo_restante = 165 - tiempo_acumulado;
        std::cout << "Te sobran " << tiempo_restante << " segundos\n\n" << std::endl;
    
        if (tiempo_acumulado >= 135 && tiempo_acumulado < 165) { 
            std::cout << "--- Quedan 30 segundos, recomendamos dirigirte a la zona de salida ---" << std::endl;
        }
    }

    if (tiempo_acumulado >= 165) { 
        std::cout << "Se acabó el tiempo." << std::endl;
    }
    
  return 0; 
}