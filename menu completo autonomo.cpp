#include<iostream>

void quitar_llantas(){

   std::cout<<"¿Que hizo?"<<std::endl;
   std::cout<<"Tiempo que realizo en cada acción:"<<std::endl;
   std::cout<<"Tiempo total: "<<std::endl;
   }

void poner_llantas(){

   std::cout<<"¿Que hizo?"<<std::endl;
   std::cout<<"Tiempo que realizo en cada acción:"<<std::endl;
   std::cout<<"Tiempo total: "<<std::endl;
   }
void limpiar_herramientas(){

   std::cout<<"¿Que hizo?"<<std::endl;
   std::cout<<"Tiempo que realizo en cada acción:"<<std::endl;
   std::cout<<"Tiempo total: "<<std::endl;
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


  std::cout<<"\n\nIngresando al teleoperado..."<<std::endl;
  return 0; 
}