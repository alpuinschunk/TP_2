#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define TRUE 1
#define FALSE 0

int findEmployeeById(Employee* list, int len,int id)
{

    for(int i=0; i<len; i++)
    {
        if(list[i].id==id/*&&list[i].isEmpty==TRUE*/)
        {
            return i;
            break;
        }
    }
    return -1;
}


int printEmployees(Employee* list, int length)
{
    for(int i=0; i<length; i++)
    {
        if(!list[i].isEmpty)
        {
            printf("Id: %d Name: %s Lastname: %s Salary: %f Sector: %d\n\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }
    }
    return 0;
}

void printEmployee(Employee list)
{
    printf("Id: %d Name: %s Lastname: %s Salary: %.2f Sector: %d\n\n",list.id,list.name,list.lastName,list.salary,list.sector);
}


static int generarNextId()
{
    static int id=-1;
    id++;
    return id;
}

int initEmployees(Employee* list, int len)
{
    int retorno=0;

    if(list==NULL)
    {
        if(len<=0)
        {
            retorno = -1;
        }
    }
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty = TRUE;
    }

    return retorno;
}


int getFreeSpace(Employee list[], int len)
{
    int i;
    int retorno = -1;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int menu()
{
    int opcion=0;
    system("cls");
    printf("--MENU--\n\n");
    printf("1- HIGH\n");
    printf("2- MODIFY\n");
    printf("3- LOW\n");
    printf("4- SORT\n");
    printf("5- EXIT\n\n");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int found;
    int retorno=-1;

    if(len>0&&list!=NULL)
    {
        found = getFreeSpace(list,len);
        if(found !=-1)
        {
            if(!getValidString("Entrer name: ","Must enter only letters\n","Rango 3-30", name,3,30))
            {
                if(!getValidString("Enter lastname: ","Must enter only letters\n","Rango 3-30",lastName,3,30))
                {
                    if(!getValidFloat("Enter salary: ", "Must enter only numbers",&salary,1,999999))
                    {
                        if(!getValidInt("Enter sector: ", "Must enter only numbers from 1 to 10",&sector,1,10))
                        {
                            printf("New employee: %s %s\n\n",lastName,name);
                            strcpy(list[found].name,name);
                            strcpy(list[found].lastName,lastName);
                            list[found].salary=salary;
                            list[found].sector=sector;
                            list[found].id=generarNextId();//ID
                            list[found].isEmpty=FALSE;
                            retorno=0;
                        }
                    }
                }
            }
        }
        else
        {
            printf("There is not enough space\n\n");

        }
    }
    return retorno;
}

int modifyEmployee(Employee* list, int len, int id)
{
    printf("entro");
    int retorno=-1;
    int found;
    char modify;

    printf("Enter the ID you want to modify\n");
    scanf("%d",&id);

    found=findEmployeeById(list,len,id);

    if(found == -1)
    {
        printf("User not found\n");
    }
    else
    {
        printEmployee(list[found]);

        printf("Do you want to modify this user? s/n\n");
        fflush(stdin);
        scanf("%c",&modify);

        if(modify=='s')
        {
            int opcion=0;
            printf("--MENU--\n\n");
            printf("1- Name\n");
            printf("2- Lastname\n");
            printf("3- Salary\n");
            printf("4- Sector\n");
            printf("5- Exit\n\n");
            fflush(stdin);
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                getValidString("Entrer name: ","Must enter only letters\n","Rango 3-30", list[found].name,3,30);
                /*printf("Enter new name: \n");
                fflush(stdin);
                gets(list[found].name);*/
                break;
            case 2:
                getValidString("Entrer name: ","Must enter only letters\n","Rango 3-30",list[found].lastName,3,30);
                /*printf("Enter new lastname: \n");
                fflush(stdin);
                gets(list[found].lastName);*/
                break;
            case 3:
                getValidFloat("Enter salary: ", "Must enter only numbers",&list[found].salary,1,999999);

                /*printf("Enter new salary: \n");
                scanf("%f",&list[found].salary);*/
                break;
            case 4:
                getValidInt("Enter sector: ", "Must enter only numbers from 1 to 10",&list[found].sector,1,10);
                /*printf("Enter new sector: \n");
                scanf("%d",&list[found].sector);*/
                break;
            case 5:
                opcion=5;
                retorno=0;
                break;
            default:
                printf("Wrong option: \n");
                system("pause");
                break;
            }

        }
        else
        {
            printf("Cancelled modification\n\n");
        }
    }
    return retorno;
}

int removeEmployee(Employee* list, int len, int id)
{
    int found;
    char remove;


    printf("Enter the ID you want to delete\n");
    scanf("%d",&id);

    found=findEmployeeById(list,len,id);

    if(found <0)
    {
        printf("User not found\n");
    }
    else
    {
        printEmployee(list[found]);
        printf("Are you sure you want to delete this user? s/n\n");
        fflush(stdin);
        scanf("%c",&remove);

        if(remove=='s')
        {
            list[found].isEmpty=TRUE;
            printf("User delete\n\n");
        }
        else
        {
            printf("Cancelled\n\n");
        }
    }

    return -1;
}

int sortEmployees(Employee* list, int len, int order)
{
    Employee employee;

    printf("\n\n 1. Ordenar de manera ascendente. \n\n 2. Ordenar de manera descendente.\n\n Seleccione una opcion: ");
    fflush(stdin);
    scanf("%d",&order);

    if(order==1)///ASCENDENTE
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[i].lastName,list[j].lastName)<0)
                {
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }

                else if(strcmp(list[i].lastName, list[j].lastName) == 0 && list[j].sector>list[i].sector)
                {
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;

                }

            }
        }
    }

    else if(order==0)
    {
        for(int i=0; i<len-1; i++) ///DESCENDENTE
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[i].lastName,list[j].lastName)>0)
                {
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }

                else if(strcmp(list[i].lastName, list[j].lastName) == 0 && list[j].sector<list[i].sector)
                {
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }
            }
        }
    }

    averageSalary(list,len);
    printEmployees(list,len);

    return 0;

}

int averageSalary(Employee*list,int len)
{
    float average;
    int accountant=0;
    int accountantEmployees=0;
    int sum;


    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty=TRUE)
        {
            sum=sum+list[i].salary;
            accountant++;
            average=sum/accountant;
        }
    }

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==TRUE)
        {
            if(list[i].salary>accountant)
            {
                accountantEmployees++;
            }
        }
    }

    printf("Total and average salaries\n\n");
    printf("Total de salarios: %d\n",sum);
    printf("Promedio salarios: %d\n",accountant);
    printf("Empleados que superan el salario promedio: %d\n",accountantEmployees);
}


