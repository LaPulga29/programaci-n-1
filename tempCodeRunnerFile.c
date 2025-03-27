#include <stdio.h>

int main() {
    char nombre[30];
    int i;

    do {
        printf("Ingrese el nombre del producto: ");
        scanf("%s", nombre);  

       
        for (i = 0; nombre[i] != '\0'; i++) {
            if ((nombre[i] < 'A' || nombre[i] > 'Z') && (nombre[i] < 'a' || nombre[i] > 'z')) {
                printf("Solo se permiten letras, intente nuevamente.\n");
                break;
            }
        }
    } while (nombre[i] != '\0');

    printf("Nombre válido: %s\n", nombre);
    return 0;
}

for (size_t i = 0; i < count; i++)
{
    /* code */
}
