#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int front=-1,rear=-1,count=0;

int insert(int item)
{
    if(count==max){
        printf("queue overflow\n");
        return 0;
    }
    else if(front==-1){
        front++,rear++;
        queue[rear]=item;
        count++;
        return 0;
    }
    else{
        rear=(rear+1)%max;
        queue[rear]=item;
        count++;
        return 0;
    }
}

int delete(){
   if(front==-1){
    printf("queue underflow\n");
    return 0;
   }
   else if(front==rear)
   {
       printf("%d element was deleted\n",queue[rear]);
       front=-1,rear=-1;
       count--;
       return 0;
   }
   else{
    printf("%d element was deleted\n",queue[front]);
    front=(front+1)%max;
    count--;
    return 0;
   }
}
void display(){
    int z=front;
  if(count==0){
    printf("queue empty");
  }
  else{
        printf("The queue elements are:\n");
    for(int i=0;i<count;i++){
        {
            printf("%d\n",queue[z]);
            z=(z+1)%max;
        }
    }
  }
}
int main()
{
   int choice;
    while(1)
    {
        printf("Enter choice \n 1)insert \n 2)delete \n 3)display \n 4)exit:\n");
        scanf("%d",&choice);
       switch(choice){

         case 1:printf("Enter the element:");
                int item;
                scanf("%d",&item);
                insert(item);
                break;
         case 2:delete();
                break;
         case 3:display();
                break;
         case 4:exit(0);
         deafult:printf("invalid choice");
       }
    }

}

