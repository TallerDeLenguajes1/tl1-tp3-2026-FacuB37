#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MostrarPersonas(char* nombres[],int n);
char* BuscarNombrePorPalabra(char* nombres[],char* palabraClave,int n);
void BuscarNombrePorId(char* nombres[],int n);
int main(){
    char* nombres[5];
    char* buff;
    int cant=5;
    buff=(char*)malloc(sizeof(char)*100);
    for(int i=0; i<cant; i++){
        printf("\nescriba un nombre:");
        scanf("%s",buff);
        nombres[i]=(char *)malloc(sizeof(char)*(strlen(buff)+1));
        strcpy(nombres[i],buff);

    };
    free(buff);
    MostrarPersonas(nombres,cant);
    int opcion,opcionValida=0,id;
    char* nombre=(char*)malloc(sizeof(char)*100);
    while(opcionValida==0){
        printf("\nElija opcion (1: buscar por id, 2: buscar por nombre): ");
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                opcionValida=1;
                printf("\ningrese id:");
                scanf("%d",&id);
                BuscarNombrePorId(nombres,id);
                break;
            case 2:
                opcionValida=1;
                printf("\ningrese nombre:");
                scanf("%s",nombre);
                printf("%s",BuscarNombrePorPalabra(nombres,nombre,cant));
                free(nombre);
                break;
            default:
                break;
            }   
    }
    for(int i =0;i<cant;i++){
        free(nombres[i]);
    };

    return 0;
} 


void MostrarPersonas(char* nombres[],int n){
    for(int i =0;i<n;i++){
        printf("\n[%d]:%s",i,nombres[i]);
    }
}

void BuscarNombrePorId(char* nombres[],int n){
    if(n<=4 &&n>=0){
        printf("\n%s",nombres[n]);
    }else{
        printf ("no se encontro el valor buscado");
    }
}

char* BuscarNombrePorPalabra(char* nombres[],char* palabraClave,int n){
    for(int i=0;i<n;i++){
        if(strstr(nombres[i],palabraClave)){
            return(nombres[i]);
        }
    }
    return ("-1");
}
