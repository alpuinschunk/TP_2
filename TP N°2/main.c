#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define TRUE 1
#define FALSE 0
#define CANT 3

int main()
{
    int opcion=0;
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int contador=0;
    int order;


    Employee employee[CANT];
    initEmployees(employee,CANT);

    do
    {

        switch(menu())
        {
        case 1:
            addEmployee(employee,CANT,id,name, lastName, salary, sector);
            contador++;
            system("pause");
            break;
        case 2:
            if(contador==0)
            {
                printf("There is no employee loaded in the system\n\n");
            }
            else
            {
                modifyEmployee(employee,CANT,id);
            }
            system("pause");
            break;
        case 3:
            if(contador==0)
            {
                printf("There is no employee loaded in the system\n\n");
            }
            else
            {
                removeEmployee(employee,CANT,id);
            }
            system("pause");
            break;
        case 4:
            if(contador==0)
            {
                printf("There is no employee loaded in the system\\n");
            }
            else
            {
                sortEmployees(employee,CANT,order);
            }
            system("pause");
            break;
        case 5:
            printf("Leaving the program\n\n");
            opcion=5;
            system("pause");
            break;
        default:
            printf("Wrong option\n\n");
            system("pause");
            break;
        }
    }
    while(opcion!=5);

    return 0;
}
