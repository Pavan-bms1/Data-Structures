#include<stdio.h>
#include<process.h>
int top=-1,size=0;
int push(int a[],int ele)
{
    if(top==(size-1)){
        printf("Stack overflow\n");
        return 0;
    }
    top++;
    a[top]=ele;
    printf("Element pushed\n");
    return 0;
}
int pop(int a[])
{

    if(top==-1){
        printf("stack underflow");
        return 0;
    }
    int retrive=a[top];
    top--;
    printf("Element poped is %d",retrive);
    return 0;
}
int display(int a[]){
    if(top==-1){
        printf("Stack empty\n");
        return 0;
    }
      printf("The array elements are:\n");
      for(int i=0;i<=top;i++){
          printf("%d\n",a[i]);
      }
      return 0;

}
int main()
{
    printf("enter the size of the array:");
    scanf("%d",&size);
    int a[size],ele;
    int choice;
    printf("Enter the choice:");
    while(1){
      printf("\n 1.push\n 2.pop\n 3.display\n 4.exit:\n");
      scanf("%d",&choice);
      switch(choice){
        case 1:printf("Enter the element:");
               scanf("%d",&ele);
               push(a,ele);
               break;
        case 2:pop(a);
               break;
        case 3:display(a);
               break;
        case 4:exit(0);
        default:printf("invalid choice");
                break;
      }
    }
    return 0;
}
