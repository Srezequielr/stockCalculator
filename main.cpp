#include <stdio.h>
#include <string.h>
#include <ctime>

typedef struct
{
    int id;
    char name[20];
    int costPrice;
    int profit;
    int finalPrice;
    int stock;
} Product;

typedef struct
{
    int productsList[10];
    int date;
} Sale;

typedef struct
{
    int profit;
    int cost;
} Params;

int menu()
{
    int option;
    printf("----- Menu principal -----\n");
    printf("1. Cargar productos\n");
    printf("2. Cargar ventas\n");
    printf("3. Modificar parametros\n");
    printf("4. Ver productos\n");
    printf("5. Modificar producto\n");
    printf("6. Ver ventas\n");
    printf("7. Modificar/cargar parametros\n");
    printf("Seleccionar opcion <salir con 0>: ");
    scanf("%d", &option);
    return option;
}

void addProduct(FILE *productos, int cost, int profit)
{
    Product prod;
    fpos_t x;
    printf("Ingresar nombre de producto (terminar con 0): ");
    gets(prod.name);
    while (strcmp((prod.name), "0"))
    {
        fseek(productos, 0, SEEK_END);
        fgetpos(productos, &x);
        int cod = (int)(x / sizeof(prod));
        prod.id = cod;
        printf("Ingrese costo del producto: ");
        scanf("%d", &prod.costPrice);
        printf("Ingrese stock del producto: ");
        scanf("%d", &prod.stock);
        prod.finalPrice = (prod.costPrice * (profit * 0.01)) + prod.costPrice + cost;
        prod.profit = (prod.costPrice * (profit * 0.01)) + prod.costPrice;
        fwrite(&prod, sizeof(Product), 1, productos);
        printf("El codigo del nuevo producto es: %d\n", prod.id);
        printf("Ingresar nombre de producto (terminar con 0): ");
        gets(prod.name);
    }
}

void addSale(FILE *sale){
    Sale sale;
    time_t t;
    t = time(NULL);
    struct tm *fecha;
    
    int band, i;
    printf("Ingresar venta, cancelar con 0; ");
    scanf("%d", band);
    while (band != 0)
    {
        
        for (i = 0; i < 10; i++)
        {
            
        }
        
        fecha = localtime(&t);
    }
    
}

int main()
{
    FILE *products, *sales;

    int option;

    products = fopen("products.dat", "w+");
    sales = fopen("sales.dat", "w+");

    if (products == NULL || sales == NULL)
    {
        printf("Algunos de los archivos no se abrio");
    }
    else
    {
        while ((option = menu()) != 0)
        {
            switch (option)
            {
            case 1:
                printf("Puse opcion 1\n");
                break;
            case 2:
                printf("Puse opcion 2\n");
                break;
            case 3:
                printf("Puse opcion 3\n");
                break;
            case 4:
                printf("Puse opcion 4\n");
                break;
            case 5:
                printf("Puse opcion 5\n");
                break;
            case 6:
                printf("Puse opcion 6\n");
                break;
            case 7:
                printf("Puse opcion 7\n");
                break;
            default:
                printf("Mandaste fruta\n");
                break;
            }
        }
    }
}