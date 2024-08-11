#include<stdio.h>
struct hospital
{
    int no,age;
    char name[20];
};
FILE *fp;
struct hospital h;
void add()
{
        fp = fopen("hosp","a");
        printf("\nEnter patient number  ");
        scanf("%d",&h.no);
        fflush(stdin);
        printf("\nEnter name ");
        scanf("%s",&h.name);
        printf("\nEnter age ");
        scanf("%d",&h.age);
        fwrite(&h,sizeof(struct hospital),1,fp);
        //fwrite(&h,sizeof(struct hospital),1,fp);
        printf("\nAccount data saved");
        fclose(fp);
   }
void show_patient()
{
    fp=fopen("hosp","r");
    while (fread(&h,sizeof(struct hospital),1,fp)==1)
   {
        printf("\npatient number is %d",h.no);
        printf("\nName  %s",h.name);
        printf("\nAge is %d",h.age);
        printf("\n ");
   }
}
void search()
{
    fp=fopen("hosp","r");
    int cd,flag=0;
    printf("\nSearch By ");
    printf("\n1. Number");
    printf("\n2. Name");
    printf("\n");
    printf("\nEnter choice  ");
    scanf("%d",&cd);
    if(cd==1)
    {
        printf("\nEnter number to search  ");
        scanf("%d",&cd);
        while (fread(&h,sizeof(struct hospital),1,fp)==1)
       // while(fread(&h,sizeof(h),1,fp)==1)
        {
            if(h.no==cd)
            {
                printf("\n_____________________________");
                printf("\n \n");
                printf("PATIENT INFORMATION FOUNDED!!");
                printf("\n_____________________________");
                printf("\n");

                printf("\nPatient number is %d",h.no);
                printf("\nPatient name is %s",h.name);
                printf("\nPatient age is %d",h.age);
                flag==1;
                printf("\n");
                printf("\n_____________________________");
                printf("\n \n");
            }
        }
                if(flag==0)
                    printf("\nPatient number %d not found",cd);
    }
    else if (cd==2)
    {
        char name[12];
        printf("\nEnter patient name to search  ");
        scanf("%s",&name);
        printf("\n");
    while (fread(&h,sizeof(struct hospital),1,fp)==1)
     //   while(fread(&h,sizeof(hospital),1,fp)==1)
{
    if (strcmpi(name,h.name)==0)
    {
              printf("\nPatient Information Found!!");
              printf("\n \n_______________________");
              printf("\nPatient number is %d",h.no);
              printf("\nPatient name is %s",h.name);
              printf("\nPatient age is %d ",h.age);
              printf("\n__________________________");
    }
}
    }
         if(flag==0)
                    printf("\nPatient not found",h.name);

              printf("\n__________________________");
               printf("\n");
}
void edit()
{
        fp=fopen("hosp","r+");
        int cd,pos=0;
        printf("\nEnter patient number ");
        scanf("%d",&cd);
        printf("\n");
    while (fread(&h,sizeof(struct hospital),1,fp)==1)
   {
       if(h.no==cd)
       {
         printf("\nEnter new number ");
        scanf("%d",&h.no);
        printf("\nEnter new Name ");
        scanf("%s",&h.name);
        printf("\nEnter new Age ");
        scanf("%d",&h.age);
        fseek(fp,pos,0);
        fwrite(&h,sizeof(struct hospital),1,fp);
        printf("\nPatient detiles updated ");
        printf("\n____________________________");
        printf("\n");
        printf("\n");
        break;

            pos=ftell(fp);
        }
        fclose(fp);

        if(h.no!=cd)
       {
            printf("\n");
            printf("PATIENT NOT FOUND");
            printf("\n");
            printf("\n________________________");
            printf("\n");

       }
        }
    }

void del()
{
    fp=fopen("hosp","r");
    FILE *fp1;
    fp1=fopen("temp","w");
    int cd;
    printf("\nEnter patient number to delete ");
    scanf("%d",&cd);
    while (fread(&h,sizeof (struct hospital),1,fp)==1)
    {
        if(cd!=h.no)
        {
            fwrite(&h,sizeof(struct hospital),1,fp1);
              //  printf("copied");
        }
    }
    printf("\nPatient information deleted ");
    printf("\n_____________________________");
    printf("\n");
 fclose(fp);
    fclose(fp1);
    remove("hosp");
    rename("temp","hosp");

}
/*int count ()
{
fp = fopen("hosp","r");
if(fp==NULL)
{
        fclose(fp);
        return 0;
}
else
{
    fseek(fp,0,2);
    int pos = ftell(fp);
    int cnt=pos/sizeof(h);
    fclose(fp);
    return(cnt);
}
}
*/
void home()
{
   int ch;
   do{
   printf("\n1. Add Patient Records ");
   printf("\n2. View Available Records ");
   printf("\n3. Search Patient by Name and Number ");
   printf("\n4. Edit Number");
   printf("\n5. Delete Patient Records");
   printf("\n6. Exit ");
   printf("\n_______________________");
   printf("\n");
   printf("\nEnter Choice - ");
   scanf("%d",&ch);
          system("cls");
    if (ch==1)
    add();
else if(ch==2)
show_patient();
    else if(ch==3)
        search();
        else if(ch==4)
            edit();
            else if(ch==5)
                del();
   }while(ch!=6);
}
void main()
{
  home();
}
