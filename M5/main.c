#include <stdio.h>
#define max 5

int queue_arr[max];
int rear = -1;
int front = -1;

main(){
    int choice;
    while(1){
        printf("\n");
        printf("+===============+ \n ");
        printf("     MENU UTAMA   \n ");
        printf("+===============+ \n ");
        printf(" 1. Insert Queue  \n ");
        printf(" 2. Display Queue \n ");
        printf(" 3. Delete Queue  \n ");
        printf(" 4. Quit          \n ");
        printf("+===============+ \n ");
        printf("Masukkan pilihan : ");
        scanf("%d",&choice);
        printf("\n");

        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                del();
                break;
            case 4:
                break;
            default:
                printf("Salah memasukkan pilihan \n");
        }      
        
    }
}

del(){
    if (front == -1 || front > rear){
        printf("Queue Underflow \n");
    }else{
        printf("Elemen deleted from queue is : %d\n", queue_arr[front]);
        front=front+1;
    }
}

insert(){
    int added_item;
    if (rear == max-1)
        printf("Queue Overflow !! \n");
    else{
        if (front==-1)
            front=0;
            printf("Masukkan elemen kedalam Queue : ");
            scanf("%d", &added_item);
            rear=rear+1;
            queue_arr[rear] = added_item;
        }
}

display(){
    int i;
    if (front == -1)
        printf("Queue kosong ! \n");
    else{
        printf("Queue : \n");
        for(i=front;i<= rear;i++)
            printf("%d", queue_arr[i]);
            printf("\n");
    }
}
