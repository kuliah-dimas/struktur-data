#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

typedef struct node node;
node *pHead = NULL;

node *alokasiNodeBaru() {
    node *pNew = NULL;
    pNew = (node*)malloc(sizeof(node));
    return(pNew);
}

void tambahAwal(node *pNew) {
    printf("Masukkan bilangan: ");
    scanf("%d", &pNew->data);

    if (pHead == NULL) {
        pNew->prev = pHead;
        pNew->next = pHead;
        pHead = pNew;
    } else {
        pNew->prev = pHead;
        pNew->next = pHead;
        pHead->prev = pNew;
        pHead = pNew;
    }
}

void cetak() {
    node *pWalker = pHead;
    int i = 1;
    while (pWalker != NULL) {
        printf("Node ke-%d = %d\n", i, pWalker->data);
        i++;
        pWalker = pWalker->next;
    }
    printf("NULL\n");
}

void hapusAkhir() {
    node *pEnd;
    pEnd = pHead;
    while (pEnd->next != NULL) {
        pEnd = pEnd->next;
    }
    pEnd->prev->next=NULL;
    free(pEnd);
}


int main()
{
    node *pNew;
    int pilih, bil;
    do {
        system("cls");
        printf("------- MENU -------");
        printf("\n1. Tambah Awal");
        printf("\n2. Hapus Akhir");
        printf("\n3. Cetak");
        printf("\n4. Exit");
        printf("\nPilihan: ");
        scanf("%d", &pilih);

        if (pilih==1) {
            pNew=alokasiNodeBaru();
            tambahAwal(pNew);
        } else if (pilih == 2) {
            hapusAkhir();
        } else if (pilih == 3) {
            cetak();
            getch();
        }
    } while (pilih != 4);

    printf("\n");
    system("PAUSE");

    return 0;
}
