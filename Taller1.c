#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define PRECIO_LLANTAS 150
#define PRECIO_KIT_PASTILLAS 55
#define PRECIO_KIT_EMBRAGUE 180
#define PRECIO_FARO 70
#define PRECIO_RADIADOR 120


#define DESCUENTO_1 0.05
#define DESCUENTO_2 0.07
#define DESCUENTO_3 0.10

int validarCedula(char ci[11]) {
    int vector[10];

    if (strlen(ci) != 10) {
        return 0;
    }

    for (int i = 0; i < 10; i++) {
        int digito = ci[i] - '0';
        vector[i] = (i % 2 == 0) ? digito * 2 : digito;

        if (vector[i] > 9) {
            vector[i] -= 9;
        }
    }

    int suma = 0;
    for (int i = 0; i < 9; i++) {
        suma += vector[i];
    }

    int comprobador = (suma * 9) % 10;
    int ultimoDigito = ci[9] - '0';

    return (comprobador == ultimoDigito);
}

int main() {
    char nombre[30];
    char ci[11];
    char direccion[50];
    int num_Telefono;
    int Fecha;
    
    printf("VENTA DE REPUESTOS DE AUTOMÓVILES: \n");
    printf("Nombre y apellido: ");
    gets("%s", nombre);  
    
    int cedulaValida = 0;

    while (!cedulaValida) {
        printf("Número de cédula: ");
        scanf("%10s", ci);

        if (validarCedula(ci)) {
            cedulaValida = 1;
        } else {
            printf("La cédula ingresada no es válida. Intente de nuevo.\n");
        }
    }

    printf("Teléfono: ");
    scanf("%d", &num_Telefono);
    
    printf("Dirección: ");
    scanf("%49s", direccion);
    
    printf("Fecha: ");
    scanf("%d", &Fecha);

    char condicion[3];
    char producto[15];
    int cantidad[5] = {0};  
    int total_productos = 0;
    int total_precio = 0;

    printf("¿Desea comenzar a comprar? (si / no): ");
    scanf("%2s", condicion);

    if (strcmp(condicion, "si") == 0 || strcmp(condicion, "Si") == 0 || strcmp(condicion, "SI") == 0) {
        printf("Productos disponibles:\n");
        printf("Llantas\n");
        printf("Kit Pastillas\n");
        printf("Kit de Embrague\n");
        printf("Faro\n");
        printf("Radiador\n");

        while (total_productos < 5) {
            printf("Ingrese el nombre del producto: ");
            scanf("%14s", producto);

            if (strcmp(producto, "Llantas") == 0) {
                printf("Ingrese la cantidad que desea: ");
                scanf("%d", &cantidad[0]);
                total_productos += cantidad[0];
                total_precio += cantidad[0] * PRECIO_LLANTAS;
            } else if (strcmp(producto, "Kit_Pastillas") == 0) {
                printf("Ingrese la cantidad que desea: ");
                scanf("%d", &cantidad[1]);
                total_productos += cantidad[1];
                total_precio += cantidad[1] * PRECIO_KIT_PASTILLAS;
            } else if (strcmp(producto, "Kit_de_Embrague") == 0) {
                printf("Ingrese la cantidad que desea: ");
                scanf("%d", &cantidad[2]);
                total_productos += cantidad[2];
                total_precio += cantidad[2] * PRECIO_KIT_EMBRAGUE;
            } else if (strcmp(producto, "Faro") == 0) {
                printf("Ingrese la cantidad que desea: ");
                scanf("%d", &cantidad[3]);
                total_productos += cantidad[3];
                total_precio += cantidad[3] * PRECIO_FARO;
            } else if (strcmp(producto, "Radiador") == 0) {
                printf("Ingrese la cantidad que desea: ");
                scanf("%d", &cantidad[4]);
                total_productos += cantidad[4];
                total_precio += cantidad[4] * PRECIO_RADIADOR;
            } else {
                printf("Producto no reconocido. Intente de nuevo.\n");
            }
        }
    } else {
        printf("La compra no se ha iniciado.\n");
    }

    if (total_precio > 0) {
        if (total_precio <= 100) {
            printf("No hay descuento.\n");
        } else if (total_precio <= 500) {
            total_precio -= total_precio * DESCUENTO_1;
            printf("Tiene un descuento del 5%%.\n");
        } else if (total_precio < 1000) {
            total_precio -= total_precio * DESCUENTO_2;
            printf("Tiene un descuento del 7%%.\n");
        } else {
            total_precio -= total_precio * DESCUENTO_3;
            printf("Tiene un descuento del 10%%.\n");
        }
    }

    printf("VENTA DE REPUESTOS AUTOMÓVILES: \n");
    printf("Nombre:  %s \n", nombre);
    printf("Número de cedula: %s\n", ci);
    printf("Número de teléfono:  %d \n", num_Telefono);
    printf("Dirección: %s \n", direccion);
    printf("Fecha: %d \n", Fecha);
    printf("El precio total es: %d\n", total_precio);

    return 0;
}
