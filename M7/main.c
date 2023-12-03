#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
void inputData(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\n\n\t ENTER THE ELEMENT [%d] :: ", i);
        scanf("%d", &a[i]);
    }
}
void printData(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("\t%d", a[i]);
}
void selectSort(int a[], int n)
{
    int i, j, temp, min;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[min] > a[j])
                min = j;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        printf("\n\n\t Iterasi %d :: ", i);
        printData(a, n);
    }
}

int main()
{
    int a[20], n;
    printf("\n\n\t ENTER THE DATA LENGTH :: ");
    scanf("%d", &n);
    inputData(a, n);
    printf("\n\n\t THE DATA ELEMENTS ARE :: ");
    printData(a, n);
    selectSort(a, n);
    printf("\n\n\t THE SELECTION SORTED LIST IS :: ");
    printData(a, n);
    getch();
}
