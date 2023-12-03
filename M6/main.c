#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *kiri;
    struct Node *kanan;
};

void tambah(struct Node **root, int databaru)
{
    if ((*root) == NULL)
    {
        struct Node *baru = (struct Node *)malloc(sizeof(struct Node));
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        (*root) = baru;
        printf("Data Bertambah!\n");
    }
    else if (databaru < (*root)->data)
    {
        tambah(&(*root)->kiri, databaru);
    }
    else if (databaru > (*root)->data)
    {
        tambah(&(*root)->kanan, databaru);
    }
    else if (databaru == (*root)->data)
    {
        printf("Data Sudah Ada!\n");
    }
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d\n", root->data);
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->kiri);
        printf("%d\n", root->data);
        inOrder(root->kanan);
    }
}

void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->kiri);
        postOrder(root->kanan);
        printf("%d\n", root->data);
    }
}

int main()
{
    char pil, tny, tnyl;
    int terus = 1;
    struct Node *pohon;
    pohon = NULL;
    int data;
    while (terus)
    {
    menu:
        system("clear"); // if windows, using "cls". If macos or linux using "clear"
        printf("MENU\n");
        printf("1. Tambah\n");
        printf("2. Lihat Pre-Order\n");
        printf("3. Lihat In-Order\n");
        printf("4. Lihat Post-Order\n");
        printf("5. Hapus Semua Data\n");
        printf("6. Exit\n\n");
        printf("\n====================================\n");
        printf("Pilihan Anda [1..6]: ");
        pil = ' ';
        while (!(pil >= '1' && pil <= '6'))
        {
            pil = getchar();
        }

        switch (pil)
        {
        case '1':
            printf("Data baru: ");
            scanf("%d", &data);
            tambah(&pohon, data);
            break;
        case '2':
            if (pohon != NULL)
            {
                preOrder(pohon);
            }
            else
            {
                printf("Masih kosong\n");
            }
            break;
        case '3':
            if (pohon != NULL)
            {
                inOrder(pohon);
            }
            else
            {
                printf("Masih kosong\n");
            }
            break;
        case '4':
            if (pohon != NULL)
            {
                postOrder(pohon);
            }
            else
            {
                printf("Masih kosong\n");
            }
            break;
        case '5':
            printf("Apakah anda yakin untuk menghapus [y/n]?");
            scanf("%s", &tnyl);
            if (tnyl == 'y' || tnyl == 'Y')
            {
                printf("Data dihapus!");
                free(pohon);
                pohon = NULL;
            }
            else
            {
                goto menu;
            }
            break;
        case '6':
            printf("Apakah anda yakin untuk keluar [y/n]? ");
            scanf("%s", &tny);
            if (tny == 'y' || tny == 'Y')
            {
                printf("Anda keluar dari program\n");
                exit(0);
            }
            else
            {
                goto menu;
            }
        default:
            terus = 0;
            break;
        }

        if (pil != '6')
        {
            getchar();
        }
        getchar();
    }

    return 0;
}
