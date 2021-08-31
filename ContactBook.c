#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>



typedef struct contactBook
{
    char cName[20];
    char cMobile[12];
   
}CON;


void SortList(CON book[],int *iCount)
{
  CON temp;
  register int i=0,j=0,k=0;
  for(i=1;i<*iCount;i++)
  {
    for(j=0;j<*iCount-i;j++)
    {
     if(strcmp(book[j].cName,book[j+1].cName)>0)
     {
       temp=book[j];
       book[j]=book[j+1];
       book[j+1]=temp;
     }
    }
  }
}



void AddRecord(CON book[],int*iCount)
{
    int ch;
    
    
    printf("--------------------------------------------------------------------------\n");
    printf("                       ADD RECORD                                         \n");
    printf("--------------------------------------------------------------------------\n");
  
    printf("Enter the first name:\t");
    scanf("%s",book[*iCount].cName);
    
    
    printf("Enter the Mobile number:\t");
    scanf("%s",book[*iCount].cMobile);
    (*iCount)++;
   
    
   
    
    printf("Record entered successfully\n");
    
    printf("Do you want to enter more records(0 or 1):\t");
    scanf("%d",&ch);
    if(ch==1)
    {
        AddRecord(book,iCount);
        SortList(book ,iCount);
    }
    else
    {
       return;
    }

}





void ListRecord(CON book[],int *iCount)
{
  int i=0;
  
  printf(" \n\n                      Contact Book                                         \n");
  printf("--------------------------------------------------------------------------\n");

  printf("\n%-10s%-20s%-12s\n","S.NO","NAME","Mobile No.");
  printf("--------------------------------------------------------------------------\n");
  if(*iCount==0)
  {
     printf("Contact Book is Empty\n");
    
  }
  else
  {
   
  while(i<*iCount)
  {
      printf("%-10d%-20s%-12s\n",i+1,book[i].cName,book[i].cMobile);
      i++;
  }
  printf("--------------------------------------------------------------------------\n");

  printf("Total records available:%d\n",*iCount);

 }
 
}

void deleteRecord(CON book[],int *iCount)
{
 if(*iCount==0)
  {
     printf("Contact Book is Empty\n");
    
  }
  else
  {
   char temp[20];
   int i=0,n=0;
  /*printf("Enter the S.NO of the record  that you want to delete \n");
  scanf("%d",&iSNo);
 
  /*if(iSNo<=0||iSNo>*iCount)
  {
    printf("Invalid S.NO");
  }
  else
  {
  i=iSNo-1;
  while(i<*iCount)
  {
    book[i]=book[i+1];
    i++;
  }
  *iCount=*iCount-1;

 

  }
  }*/
  printf("Enter the Name which you want to delete \n");
  scanf("%s",temp);

 for(i=0;i<*iCount;i++)
 {
    if(_strcmpi(book[i].cName,temp)==0)
    {
          n=i;
          
         
    }
    
 
  }
  
  if(n==0)
  {
    printf("Invalid Name\n");
  }
  else
  {
  
  while(n<*iCount)
  {
    book[n]=book[n+1];
    n++;
  }
  *iCount=*iCount-1;
   printf("Record deleted Successfully\n");
  
  } 
  }
  
}

void SearchRecord(CON book[],int *iCount)
{
  if(*iCount==0)
  {
     printf("Contact Book is Empty\n");
    
  }
  else
  {
  int iChoice=0,i=0,iFound=0;
  char iKey[30];

 printf("1.Press 1 to search by Name\n");
 printf("2.Press 2 to search by Mobile\n");
 printf("Enter choice\n");
 scanf("%d",&iChoice);


 switch (iChoice)
 {
 case 1:
          printf("Enter the name of the Person\n");
          scanf("%s",iKey);
          while(i<*iCount)
          {
            if(_strcmpi(book[i].cName,iKey)==0)
            {
              printf("\n%-10s%-20s%-12s","S.NO","NAME","Mobile No.");
              printf("\n\n%-10d%-20s%-12s",i+1,book[i].cName,book[i].cMobile);
              iFound=1;
            }
            i++;
          }
          if(iFound==0)
          {
            printf("No records found\n");
          }
          else
          {
             printf("\n\nrecord found successfully\n");
          }
         break;
  case 2:
          printf("Enter the Mobile Number of the Person\n");
          scanf("%s",iKey);
          while(i<*iCount)
          {
            if(_strcmpi(book[i].cMobile,iKey)==0)
            {
              printf("\n%-10s%-20s%-12s","S.NO","NAME","Mobile No.");
              printf("\n\n%-10d%-20s%-12s",i+1,book[i].cName,book[i].cMobile);
              iFound=1;
            }
            i++;
          }
          if(iFound==0)
          {
            printf("No records found\n");
          }
          else
          {
             printf("\n\nrecord found successfully\n");
          }
         break;
 
 default:
        printf("Invalid input");
   break;
 }
  }
}




int main()
{
   int iChoice=0,iCount=0,i=1;
   CON book[50];
  
  while(i)
  {
   printf("--------------------------------------------------------------------------\n");
    printf("1.Press 1 to add record in phone book\n");
    printf("2.Press 2 to delete record\n");
    printf("3.Press 3 to list available records\n");
    printf("4.Press 4 to search a record\n");
    printf("5.Press 5 to exit\n");
    printf("--------------------------------------------------------------------------\n");
   
   printf("enter the choice\n");
   scanf("%d",&iChoice);


   switch(iChoice)
   {
       case 1:
                AddRecord(book,&iCount);
               // SortList(book,&iCount);
                break;
       case 2:
                deleteRecord(book,&iCount);
                break;
       case 3:
                ListRecord(book,&iCount);
                break;
      case 4:
                SearchRecord(book,&iCount);
                break;
      case 5:
                exit(1);
                break;
      default:
              printf("Invalid input\n");
              exit(1);

   }
   printf("\nDo you want to perform any operations(1/0):");
   scanf("%d",&i);

  }

  return 0;
}