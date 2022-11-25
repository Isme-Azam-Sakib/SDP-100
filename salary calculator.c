#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>
#include <math.h>h
#include <conio.h>

int main()
{
   //Required variables
   char loop, loop2,loop3, rank, name[150];
   int i, j, jyear=0, abs, wday=0, days, oday, salary=0, fine, base_ab;
   int a_other= 39750, a_base=75000 ;    //30000+4500+3750+1500  w/o bonus and increment
   int b_other= 26500, b_base=50000 ;    //20000+3000+2500+1000  w/o bonus and increment
   int c_other= 21200, c_base=40000 ;    //16000+2400+2000+800   w/o bonus and increment
   int d_other= 15900, d_base=30000 ;    //12000+1800+1500+600   w/o bonus and increment
   int e_other= 10600, e_base=20000 ;    //8000+1200+1000+400    w/o bonus and increment

   //date and time related
   time_t t = time(NULL);
   struct tm tm = *localtime(&t);
   printf("%d-%02d-%02d %02d:%02d:%02d\n\n",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
   int cday=tm.tm_mday;
   int cyear=tm.tm_year + 1900;
   int cmon=tm.tm_mon + 1;
   FILE *record;

   for(i=1; i<=cmon; i++){
      if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12){
         days= days+ 31;
         if(i==cmon){
            days=days-(31-cday);
         }
      } else if(i==2){
         days= days + 28;
         if(i==cmon){
            days=days-(28-cday);
         }
      } else {
         days= days+30;
         if(i==cmon){
            days=days-(30-cday);
         }
      }
   }

   int hij_day=days-11;
   int hij_mon=hij_day/29-7;


   //welcome message
   printf("Welcome to SALARY CALCULATOR\n\n");
   printf("*************  X  *************\n\n");

   //driver loop/code
   do
   {

      do
      {
         printf("Enter Name of the employee. E.g : John Doe.\n=> ");
         gets(name);
         if(name[0]=='\0'){
            printf("\nPlease Enter name.\n");
         }continue;
      }while(name[0]=='\0');

      do
      {
      printf("\nEnter office days for this month. E.g : 27\n=> ");
      scanf("%d", &oday);
         if(!(oday <=31)){
            printf("\nOffice days cannot be more than 31 days. Try again.");
         } continue;
      } while(!(oday <=31));

      do
      {
      printf("\nEnter active days of the your employee this month :E.g : 23\n=> ");
      scanf("%d", &wday);
         if(!(wday <=oday)){
            printf("\nActive days can't be more than office days. Try again.");
         } continue;
      } while(!(wday <=oday));

      /*
      do
      {
      printf("\nJoining year of employee : E.g : 2017\n=> ");
      scanf("%d",&jyear);
         if(!(jyear>=2010 && jyear<=cyear)){
            printf("\nInvalid Joining year. Company was established in 2010");
         } continue;
      } while(!(jyear>=2010 && jyear<=cyear));
      */

      abs=oday-wday; //absent days

      do
      {
      printf("\nEnter the rank of Employee. E.g : B \n=> ");
      scanf("%s",&rank);
         if(!(rank=='a' || rank=='b' || rank=='c' || rank=='d' || rank=='e' ||
              rank=='A' || rank=='B' || rank=='C' || rank=='D' || rank=='E')){
            printf("\nPlease enter employee's rank correctly");
         } continue;
      } while(!(rank=='a' || rank=='b' || rank=='c' || rank=='d' || rank=='e' ||
      rank=='A' || rank=='B' || rank=='C' || rank=='D' || rank=='E'));

      base_ab = oday*0.2;
      float wday1 = wday, oday1 = oday, atdn;
      atdn=(wday1/oday1)*100;
      void display(){
        printf("\nSalary for the given employee is : %d", salary-fine);
        printf("\nAttendance Percentage of the employee : %.2f", atdn);
        printf("\nAbsent : %d", abs);
        printf("\nFine : %d", fine);
      }

      //calculation of salary
      if(rank=='a' || rank=='A'){
         if(atdn>=80){
            fine=0;
         } else {
            fine=(abs-base_ab)*.03*a_base;
         }

         if(cmon==4){
            salary=a_base+(a_base*0.3)+a_other;
         } else {
            salary=a_base+a_other;
         }

         if(hij_mon==9 || hij_mon==12){
            salary=salary+a_base;
         } else {
            salary=salary+0;
         }

         do
         {
            printf("\nDisplay estimated salary for this year? Enter 'Yes' or 'No'\n=> ");
            scanf("%s", &loop3);
            if(loop3=='y'){
               int sal_year=(14*a_base)+(0.3*a_base)+a_other;
               printf("\nEstimated salary for this year: %d", sal_year);
               break;
            } else if(loop3=='n'){
               break;
            } else {
               printf("\nInvalid command. Please Re-enter command.");
            }
         } while(!(loop3=='y') || !(loop3=='n'));

      } else if (rank=='b' || rank=='B'){
         if(atdn>=80){
            fine=0;
         } else {
            fine=(abs-base_ab)*.03*b_base;
         }

         if(cmon==4){
            salary=b_base+(b_base*0.3)+b_other;
         } else {
            salary=b_base+b_other;
         }

         if(hij_mon==9 || hij_mon==12){
            salary=salary+b_base;
         } else {
            salary=salary+0;
         }

         do
         {
            printf("\nDisplay estimated salary for this year? Enter 'Yes' or 'No'\n=> ");
            scanf("%s", &loop3);
            if(loop3=='y'){
               int sal_year=(14*b_base)+(0.3*b_base)+b_other;
               printf("\nEstimated salary for this year: %d", sal_year);
               break;
            } else if(loop3=='n'){
               break;
            } else {
               printf("\nInvalid command. Please Re-enter command.");
            }
         } while(!(loop3=='y') || !(loop3=='n'));

      } else if (rank=='c' || rank=='C'){
         if(atdn>=80){
            fine=0;
         } else {
            fine=(abs-base_ab)*.03*c_base;
         }

         if(cmon==4){
            salary=c_base+(c_base*0.3)+c_other;
         } else {
            salary=c_base+c_other;
         }

         if(hij_mon==9 || hij_mon==12){
            salary=salary+c_base;
         } else {
            salary=salary+0;
         }

         do
         {
            printf("\nDisplay estimated salary for this year? Enter 'Yes' or 'No'\n=> ");
            scanf("%s", &loop3);
            if(loop3=='y'){
               int sal_year=(14*c_base)+(0.3*c_base)+c_other;
               printf("\nEstimated salary for this year: %d", sal_year);
               break;
            } else if(loop3=='n'){
               break;
            } else {
               printf("\nInvalid command. Please Re-enter command.");
            }
         } while(!(loop3=='y') || !(loop3=='n'));

      } else if(rank=='d' || rank=='D'){
         if(atdn>=80){
            fine=0;
         } else {
            fine=(abs-base_ab)*.03*d_base;
         }

         if(cmon==4){
            salary=d_base+(d_base*0.3)+d_other;
         } else {
            salary=d_base+d_other;
         }

         if(hij_mon==9 || hij_mon==12){ salary=salary+a_base; } else { salary=salary+0; }
         do
         {
            printf("\nDisplay estimated salary for this year? Enter 'Yes' or 'No'\n=> ");
            scanf("%s", &loop3);
            if(loop3=='y'){
               int sal_year=(14*d_base)+(0.3*d_base)+d_other;
               printf("\nEstimated salary for this year: %d", sal_year);
               break;
            } else if(loop3=='n'){
               break;
            } else {
               printf("\nInvalid command. Please Re-enter command.");
            }
         } while(!(loop3=='y') || !(loop3=='n'));

      } else if(rank=='e' || rank=='E'){
         if(atdn>=80){
            fine=0;
         } else {
            fine=(abs-base_ab)*.03*e_base;
         }

         if(cmon==4){
            salary=e_base+(e_base*0.3)+e_other;
         } else {
            salary=e_base+e_other;
         }

         if(hij_mon==9 || hij_mon==12){
            salary=salary+e_base;
         } else {
            salary=salary+0;
         }

         do
         {
            printf("\nDisplay estimated salary for this year? Enter 'Yes' or 'No'\n=> ");
            scanf("%s", &loop3);
            if(loop3=='y'){
               int sal_year=(14*e_base)+(0.3*e_base)+e_other;
               printf("\nEstimated salary for this year: %d", sal_year);
               break;
            } else if(loop3=='n'){
               break;
            } else {
               printf("\nInvalid command. Please Re-enter command.");
            }
         } while(!(loop3=='y') || !(loop3=='n'));

      }
      display();

      do{
      printf("\n\nSave this session? Enter 'Yes' or 'No'.=> ");
      scanf("%s",&loop2);
         if(loop2=='y')
            {
            record = fopen("Entry.txt", "a");
            fprintf(record, "Date and time: %d-%02d-%02d %02d:%02d:%02d",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fprintf(record, "\nName: %s", name);
            fprintf(record, "\nJoined in : %d", jyear);
            fprintf(record, "\nAbsent : %d days", abs);
            fprintf(record, "\nAttendance  : %f", atdn);
            fprintf(record, "\nFine : %d", fine);
            fprintf(record, "\nSalary : %d", salary);
            fprintf(record, "\n==========================================\n\n\n");
            break;
         } else if(loop2=='n')
         {
            printf("\nThis session wasn't saved.");
            break;
         } else {
            printf("\nInvalid command. Please Re-enter command.");
         }
      } while(!(loop2=='y') || !(loop2=='n'));

      printf("\n\nCalculate again?\nEnter 'Yes' or 'No'\n");
      scanf("%s",&loop);
      system("cls");

   }while (loop=='y');

   return 0;

   fclose(record);
}
