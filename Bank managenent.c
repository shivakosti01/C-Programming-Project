#include<stdio.h>
struct account
{
    char name[20];
    int no;
    float amount;
};
FILE *fp;
struct account a;
void create()
{
   fp=fopen("Atm.text","a");
   printf("\nEnter account number  ");
   scanf("%d",&a.no);
   fflush(stdin);
   printf("\nEnter name ");
   gets(a.name);
   printf("\nEnter amount ");
   scanf("%f",&a.amount);
   fwrite(&a,sizeof(struct account),1,fp);
   printf("\nAccount data saved");
   fclose(fp);
   printf("\n");
   printf("\n___________________________");
   printf("\n");
  }
void withdrow()
{
    fp=fopen("Atm.text","r+");
    int no;
    int amo;
    printf("\nEnter account number ");
    scanf("%d",&no);
    printf("\nEnter amount ");
    scanf("%d",&amo);
    while(fread(&a,sizeof(struct account),1,fp)==1)
    {
        if(no==a.no)
        {
         printf("\nYour courent balance is Rs.%f",a.amount);
         a.amount-=amo;
         printf("\nRemaining blance is %.1f",a.amount);
        }
    }
}
void deposite()
{
    fp=fopen("Atm.text","r");
    int no;
    int amo;
    printf("\nEnter account number ");
    scanf("%d",&no);
    printf("\nEnter amount ");
    scanf("%d",&amo);
    while(fread(&a,sizeof(struct account),1,fp)==1)
    {
        if(no==a.no)
        {
         printf("\nYour courent balance is Rs.%f",a.amount);
         a.amount+=amo;
         printf("\nRemaining blance is %.1f",a.amount);


        }
    }
}
void show_blance()
{
    fp=fopen("Atm.text","r");
int no;
printf("\nEnter account number ");
scanf("%d",&no);
   while (fread(&a,sizeof(struct account),1,fp)==1)
     {
         if(no==a.no)
         printf("Your courent balance is %.1f",a.amount);
    }
}
void show_costmers()
{
    fp=fopen("Atm.text","r");
   while (fread(&a,sizeof(struct account),1,fp)==1)
   {
        printf("\nAccount number is %d",a.no);
        printf("\nName is %s",a.name);
        printf("\nAmount is %.2f",a.amount);
        printf("\n ");
   }
}
void modify()
{
        fp=fopen("Atm.text","r+");
        int no,pos=0;
        float amo;
        printf("\nEnter account number ");
        scanf("%d",&no);
        while (fread(&a,sizeof(struct account),1,fp)==1)
        {
                     if(no==a.no)
                     {
                           printf("\nEnter account number ");
                           scanf("%d",&no);
                           printf("\nEnter amount ");
                           scanf("%d",&amo);
                           fseek (fp,pos,0);

                     }
        }

}
void home()
  {    int ch;

     do {

         printf("\n1. Create account ");
         printf("\n2. Withdrow ");
         printf("\n3. Deposite ");
         printf("\n4. Show Costmers ");
         printf("\n5. Show Blance ");
         printf("\n6. Exit");
        printf("\n");
        printf("\nEnter choise ");
        scanf("%d",&ch);
        printf("\n");
        printf("\n_____________________");
        system("cls");
               if(ch==1)
        create();
              else if (ch==4)
        show_costmers();
              else if (ch==5)
        show_blance();
              else if(ch==2)
        withdrow();
              else if(ch==3)
        deposite();
  }while(ch!=6);
  }
  void main()
  {
      home();
  }


