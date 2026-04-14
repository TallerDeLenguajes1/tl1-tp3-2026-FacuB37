#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarPersonas(char* nombres[],int n);
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
    mostrarPersonas(nombres,5);
    return 0;
} 

void mostrarPersonas(char* nombres[],int n){
    for(int i =0;i<n;i++){
        printf("\n%s",nombres[i]);
    }
}