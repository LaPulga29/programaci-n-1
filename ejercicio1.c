#include <stdio.h>

int main() {
    int stock, cantidad, opcion, i;
    float precio, total_ganancias = 0, venta = 0;
    char nombre[30], id[30];
    
    // REGISTRO DEL PRODUCTO //

    printf("Ingrese el ID del producto: "); // ID
    scanf("%s", &id);

    do
    {
        printf("Ingrese el nombre del producto: "); // NOMBRE
        scanf("%s", nombre);
        for (i = 0; nombre[i] != '\0'; i++)
        {
            if ((nombre[i] < 'A' || nombre[i] > 'Z') && (nombre[i] < 'a' || nombre[i] > 'z'))
            {
                printf("Solo se permiten letras, intente nuevamente.\n");
                break;
            }
        }
    } while (nombre[i] != '\0');

    printf("Ingrese la cantidad inicial en stock: "); // STOCK
        scanf("%d", &stock);
            do{
                if (stock < 0)
                {
                    printf("No pueden ser valores negativos, intenta de nuevo.\n");
                    printf("Ingrese la cantidad inicial en stock: ");
                    scanf("%d", &stock);
                    
                }
            }while(stock < 0);

    printf("Ingrese el precio unitario del producto: "); // P. UNITARIO
    scanf("%f", &precio);
        do
        {
            if (precio <= 0)
            {
                printf("No pueden ser valores negativos, intenta de nuevo.\n");
                printf("Ingrese el precio unitario del producto: ");
                scanf("%f", &precio);
            }
        } while (precio < 0);

    do { // MENÚ DE OPCIONES 
        printf("\n\tMENU DE OPCIONES\t");
        printf("\n1. Ingresar producto \n"); 
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar informacion del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1: // INGRESAR PRODUCTO
            printf("Ingrese el ID del producto: ");
            scanf("%s", &id);

            do
            {
                printf("Ingrese el nombre del producto: "); // NOMBRE
                scanf("%s", nombre);
                for (i = 0; nombre[i] != '\0'; i++)
                {
                    if ((nombre[i] < 'A' || nombre[i] > 'Z') && (nombre[i] < 'a' || nombre[i] > 'z'))
                    {
                        printf("Solo se permiten letras, intente nuevamente.\n");
                        break;
                    }
                }
            } while (nombre[i] != '\0');

            printf("Ingrese la cantidad inicial en stock: ");
                scanf("%d", &stock);
                do{
                    if (stock < 0)
                    {
                        printf("No pueden ser valores negativos, intenta de nuevo.\n");
                        printf("Ingrese la cantidad inicial en stock: ");
                        scanf("%d", &stock);
                    }
                }while(stock < 0);
        
            printf("Ingrese el precio unitario del producto: ");
                scanf("%f", &precio);
                do
                {
                    if (precio <= 0)
                    {
                        printf("No pueden ser valores negativos, intenta de nuevo.\n");
                        printf("Ingrese el precio unitario del producto: ");
                        scanf("%f", &precio);
                    }
                } while (precio <= 0);
            break;

        case 2: // VENDER PRODUCTO
            do
            {
                printf("\nIngrese la cantidad a vender: ");
                scanf("%d", &cantidad);
                if (cantidad < 1)
                {
                    printf("No se puede ingresar cantidades negativas, ingrese nuevamente.");
                }
                if (cantidad > stock)
                {
                    printf("No se puede realizar la venta, no existe suficiente stock.");
                }
            } while (cantidad < 1 || cantidad > stock);

            venta = cantidad * precio; // CALCULAR PRECIO X VENTA
            printf ("El precio de esta venta es: %2.f\n", venta);
            total_ganancias = total_ganancias + venta; // ACUMULAR GANANCIAS
            stock = stock - cantidad; // RESTAR STOCK
            printf("El nuevo stock es: %d unidades.\n", stock); 
            if (stock == 0) // NO VENDER MAS DE LO POSIBLE
            {
                printf("El stock del producto se termino, reabastesca el producto\n");
            }
            break;

        case 3: // REABASTECER PRODUCTO
            cantidad = 0;
            printf("Ingrese la cantidad a agregar al stock: ");
            scanf("%d", &cantidad);
            stock = stock + cantidad; 
            printf("El nuevo stock del producto es: %d unidades. \n", stock);
            break;

        case 4: // INFO DEL PRODUCTO
            printf("\n\tInformacion del producto\t\n");
            printf("ID: %s\n", id);
            printf("Nombre: %s\n", nombre);
            printf("Stock disponible: %d unidades\n", stock);
            printf("Precio unitario: $%.2f\n", precio);
            break;

        case 5: // GANANCIAS POR VENTAS
            printf("Total de ganancias: $%.2f\n", total_ganancias);
            break;

        case 6: // SALIR 
            printf("\tSaliendo del programa :333\t\n");
            break;

        default: // NULL
            printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 6); // 6 OPCIONES
    return 0;
}