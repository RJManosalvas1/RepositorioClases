#include <stdio.h>

int fib (int num) {
    if (num <= 1) {
        return num;
    }

    int a = 0;
    int b = 1;
    int i;

    for (int i = 2; i <= num; i++) {
        i = a + b;
        a = b;
        b = i;
    }

    return b;
}

int main() {
    int num;
    printf("Ingrese un número: \n");
    scanf("%d", &num);

    if (num < 0) {
        printf("No se puede calcular con números negativos.\n");
    } 
    else {
        int resultado = fib(num);
        printf("El número de Fibonacci de %d es %d\n", num, resultado);
    }

    return 0;
}
