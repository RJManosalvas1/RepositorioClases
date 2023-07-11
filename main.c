#include <stdio.h>
#include <string.h>

#define MAX_INTENTOS 3
#define MAX_ASIENTOS_NORMAL 100
#define MAX_ASIENTOS_VIP 10
#define MAX_ASIENTOS_3D 20
#define MAX_ASIENTOS_NORMAL_2 100
#define MAX_ASIENTOS_VIP_2 10
#define MAX_ASIENTOS_3D_2 20
#define PRECIO_NORMAL 8.0
#define PRECIO_VIP 15.0
#define PRECIO_3D 12.0
#define DESCUENTO_1 0.05
#define DESCUENTO_2 0.1
#define DESCUENTO_3 0.15


int main() {
    //user y password
    char usuarios[3][10] = {"Roberto", "Jose", "Nicolas"};
    char contrasenas[3][10] = {"1234", "5678", "1357"};

    char usuario[10];
    char contrasena[10];
    int intentos = 0;
    int opcion;
    int entradas_vendidas = 0;
    float ingresos_generados = 0;
    int num;

    // Inicio de sesión
    while (intentos < MAX_INTENTOS) {
        printf("Inicio de sesión\n");
        printf("Usuario: ");
        scanf("%s", usuario);
        printf("Contraseña: ");
        scanf("%s", contrasena);
        intentos += 1;
        for (num = 0; num < 3; num++) {
            if (strcmp(usuario, usuarios[num]) == 0 && strcmp(contrasena, contrasenas[num]) == 0) {
                printf("Inicio de sesión exitoso\n");
                break;
            }
        if(intentos == MAX_INTENTOS);
        printf("Maximos intentos permitidos\n");
       
        }

        if (num < 3) {
            break;
        

        intentos++;
        
        }
        printf("Usuario o contraseña incorrectos, intento #%d\n", intentos);

    if (intentos == MAX_INTENTOS) {
        printf("Imposible ingresar\n");
        return 0;
    }
    }


    while (1) {
        printf("\nMenú principal\n");
        printf("1. Venta de Entradas\n");
        printf("2. Estadísticas de Ventas\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                {
                    int opcion_pelicula;
                    int num_entradas;
                    float costo_total = 0;

                    printf("\nVenta de Entradas\n");
                    printf("1. Frozen\n");
                    printf("2. Barbie\n");
                    printf("Ingrese la opción de película: ");
                    scanf("%d", &opcion_pelicula);

                    if (opcion_pelicula < 1 || opcion_pelicula > 2) {
                        printf("Opción no válida\n");
                        break;
                    }

                    char tipo_sala[10];
                    int max_asientos;
                    float precio_entrada;

                    printf("Tipo de sala (Normal, VIP, 3D): ");
                    scanf("%s", tipo_sala);

                    if(opcion_pelicula = 1){

                        if (strcmp(tipo_sala, "Normal") == 0) {
                            max_asientos = MAX_ASIENTOS_NORMAL;
                            precio_entrada = PRECIO_NORMAL;
                        } else if (strcmp(tipo_sala, "VIP") == 0) {
                            max_asientos = MAX_ASIENTOS_VIP;
                            precio_entrada = PRECIO_VIP;
                        } else if (strcmp(tipo_sala, "3D") == 0) {
                            max_asientos = MAX_ASIENTOS_3D;
                            precio_entrada = PRECIO_3D;
                        } else {
                            printf("Opcion invalida\n");
                            break;
                            }
                       
                        }
                        

                    if(opcion_pelicula = 2){

                        if (strcmp(tipo_sala, "Normal") == 0) {
                            max_asientos = MAX_ASIENTOS_NORMAL_2;
                            precio_entrada = PRECIO_NORMAL;
                        } else if (strcmp(tipo_sala, "VIP") == 0) {
                            max_asientos = MAX_ASIENTOS_VIP_2;
                            precio_entrada = PRECIO_VIP;
                        } else if (strcmp(tipo_sala, "3D") == 0) {
                            max_asientos = MAX_ASIENTOS_3D_2;
                            precio_entrada = PRECIO_3D;
                        } else {
                            printf("Opcion invalida\n");
                            break;
                        }
                    
                        }
                    printf("Número de entradas: ");
                    scanf("%d", &num_entradas);

                    if (num_entradas > max_asientos) {
                        printf("No hay suficientes asientos disponibles\n");
                        break;
                    }

                    costo_total = precio_entrada * num_entradas;

                    // Descuento
                    if (costo_total >= 40 && costo_total <= 80) {
                        costo_total -= costo_total * DESCUENTO_1;
                        printf("Tiene un descuento de 5 porciento");
                    } else if (costo_total > 80 && costo_total <= 120) {
                        costo_total -= costo_total * DESCUENTO_2;
                        printf("Tiene un descuento de 10 porciento");
                    } else if (costo_total > 120) {
                        costo_total -= costo_total * DESCUENTO_3;
                        printf("Tiene un descuento de 15 porciento");
                    }

                    printf("Costo total de la compra: %.2f\n", costo_total);

                    // Estadisticas

                    num_entradas = entradas_vendidas;
                    ingresos_generados = costo_total;
                  
                }
                break;
            case 2:
                printf("\nEstadísticas de Ventas\n");
                printf("Total de entradas vendidas: %d\n", entradas_vendidas);
                printf("Total de ingresos generados: %.2f\n", ingresos_generados);
                break;
            case 3:
                printf("Fin del programa\n");
                return 0;
            default:
                printf("Opción no válida\n");
                break;
        }
    }

    return 0;
}


    

    






            





            
       
























