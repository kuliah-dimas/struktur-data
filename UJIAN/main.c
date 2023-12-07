# include <stdio.h>
# define MAX 5

int queue_arr[MAX];
int rear = -1;
int front = -1;

main(){
    int pilihan;
	while(1){
	       printf("\n");
	       printf("+===================+ \n");
	       printf("|    Menu Utama     | \n");
	       printf("+===================+ \n");
	       printf("| 1. Insert Queue   | \n");
	       printf("| 2. Display Queue  | \n");
	       printf("| 3. Delete Queue   | \n");
	       printf("| 4. Quit           | \n");
	       printf("+===================+ \n");
	       printf("Masukkan Pilihan : ");
	       scanf("%d",&pilihan);
	       printf("\n");

	       switch(pilihan){
		     case 1 :
			      insert();
			      break;
		     case 2:
			      display();
			      break;
		     case 3:
			      del();
			      break;
		     case 4:
			      return;
		     default:
			      printf("Salah Memasukkan Pilihan tuh . . ! \n");
		  }
	     }
      }

del(){
    if (front == -1 || front > rear){
            printf("Queue Underflow\n");
    }else{
            printf("Element deleted from queue is : %d\n", queue_arr[front]);
            front=front+1;
        }
	 }

insert(){
    int added_item;
    if (rear == MAX-1)
        printf("Queue Overflow !! \n");
    else{
            if (front==-1) 
                front=0;
                printf("Masukkan Elemen Kedalam Queue : ");
                scanf("%d", &added_item);
                rear=rear+1;
                queue_arr[rear] = added_item ;
                }
        }


display(){
        int i;
        if (front == -1)
            printf("Queue Kosong !\n");
        else{
            printf("Queue  :\n");
            for(i=front; i <= rear; i++)
                printf("%d ",queue_arr[i]);
                printf("\n");
            }
        }
