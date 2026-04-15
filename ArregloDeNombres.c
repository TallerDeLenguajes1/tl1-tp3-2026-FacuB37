#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MostrarPersonas(char* nombres[],int n);
char* BuscarNombrePorPalabra(char* nombres[],char* palabraClave,int n);
void BuscarNombrePorId(char* nombres[],int n);
int main(){
    char* nombres[5];
    char* buff;
    buff=(char*)malloc(sizeof(char)*100);
    for(int i=0; i<5; i++){
        printf("\nescriba un nombre:");
        scanf("%s",buff);
        nombres[i]=(char *)malloc(sizeof(char)*strlen(buff+1));
        strcpy(nombres[i],buff);
    
    };
    free(buff);
    MostrarPersonas(nombres,5);
    BuscarNombre(nombres,3);

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
