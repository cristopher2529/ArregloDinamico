#include <cstdio>
#include <iostream>


//Probando el control de versiones
struct ArrayDin{
       int *num;   //Numero a introducir
       int cap;    //Capacidad del Array
       int tam;    //Tamanio ocupado en el Array
       long long int op;     //Cantidad de operaciones realizadas
       
       //Constructor
       ArrayDin(){
                  num=NULL;
                  cap=0;
                  tam=0;
                  op=0;
                  }
       //Desctructor
       ~ArrayDin(){
                   delete[] num;
                   }
       
       //introduce un nuevo numero al fin                
       void PushBackDoble(int x){
                        //Si el array esta lleno se agregara una posicion a la capacidad del array
                        if(tam==cap){
                                     cap=(cap==0)?1:cap*2;//se duplica la capacidad o se iguala a uno
                                int *temp= new int[cap];//se crea un el array a copiar
                                for(int i=0; i<tam ; i++){
                                    temp[i]=num[i];//se igualan los array
                                    op++;//se incremente la cantidad de operaciones
                                    }
                                delete[] num;
                                num=temp;
                            }
                            
                            num[tam]=x;//se introduce el nuevo numero al final
                            
                            //se imprime el numero introducido y la capacidad del array
                            printf("Introducjo: %d Capacidad: %d\n",num[tam],cap);
                            
                            tam++;
                       }
        
          //Elimina el ultimo dato del Array
          int PopBack(){
                        return num[--tam];
                       }
        
       };
int main (){
        using namespace std;    
    
        ArrayDin x;//se crea un nuevo obje
        
        //se introducen datos al Array
        x.PushBackDoble(1);
        x.PushBackDoble(2);
        x.PushBackDoble(3);
        x.PushBackDoble(5);
        x.PushBackDoble(6);
        
        printf("\nSe elimina el ultimo dato\n");
        //Se elimina el ultimo dato der Array
        x.PopBack();
        
          //Se imprime los datos del Array
          for(int i=0; i<x.tam ; i++){
                printf("%d\n",x.num[i]);
            }

        system("pause");
    }
