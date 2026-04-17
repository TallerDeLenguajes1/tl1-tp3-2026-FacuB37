#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct {
 int ProductoID; 
 int Cantidad; 
 char *TipoProducto; 
 float PrecioUnitario; 
}Producto;
typedef struct {
int ClienteID; 
char *NombreCliente; 
int CantidadProductosAPedir; 
Producto *Productos;
}cliente;

void CargarProductos(cliente* Cliente,int CantProductos);
float CalcularTotal(cliente Cliente,int CantProductos);
void MostrarCliente(cliente Cliente);

int main (){
    srand(time(NULL));
    int CantClientes=0;
    char* buff=(char *) malloc(100*sizeof(char));

    printf("cantidad de clientes:");
    scanf("%d",&CantClientes);
    

    cliente* Clientes= (cliente*)malloc(sizeof(cliente)*CantClientes);

    for(int i=0;i<CantClientes;i++){
        Clientes[i].ClienteID=i+1;
        printf("nombre del cliente %d:",i+1);
        scanf("%s",buff);
        Clientes[i].NombreCliente=(char*)malloc(sizeof(char)*(strlen(buff)+1));
        strcpy(Clientes[i].NombreCliente,buff);
        Clientes[i].CantidadProductosAPedir=1+rand()%5;
        Clientes[i].Productos=(Producto*)malloc(sizeof(Producto)*Clientes[i].CantidadProductosAPedir);
        CargarProductos(&Clientes[i],Clientes[i].CantidadProductosAPedir);
    };
    free (buff);

    for (int i = 0; i < CantClientes; i++) {
        MostrarCliente(Clientes[i]);
        free(Clientes[i].NombreCliente);
        free(Clientes[i].Productos);
    };
    free(Clientes);


}

void CargarProductos(cliente* Cliente,int CantProductos){
    for(int i=0;i<CantProductos;i++){
        Cliente->Productos[i].ProductoID=i+1;
        Cliente->Productos[i].Cantidad=1+rand()%10;
        Cliente->Productos[i].TipoProducto=TiposProductos[rand()%5];
        Cliente->Productos[i].PrecioUnitario=10+rand()%91;
    }
}

float CalcularTotal(cliente Cliente,int CantProductos){
    float total=0;
    for(int i=0;i<CantProductos;i++){
        total+=Cliente.Productos[i].Cantidad*Cliente.Productos[i].PrecioUnitario;
    };
    return (total);
}

void MostrarCliente(cliente Cliente) {
    printf("\nCliente %d - %s\n", Cliente.ClienteID, Cliente.NombreCliente);
    for (int i = 0; i < Cliente.CantidadProductosAPedir; i++) {
        printf("Producto %d: Cantidad=%d, Tipo=%s, Precio=%.2f\n",
               Cliente.Productos[i].ProductoID,
               Cliente.Productos[i].Cantidad,
               Cliente.Productos[i].TipoProducto,
               Cliente.Productos[i].PrecioUnitario);
    }
    float total = CalcularTotal(Cliente,Cliente.CantidadProductosAPedir);
    printf("Total del cliente: %.2f\n", total);
}