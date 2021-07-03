#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// number of students
int i = 0;
 
// Structure to store the student
struct sinfo {
    char fname[50];
    char lname[50];
    char fathername[50];
    int roll;
    int class;
    char sec[1];
    int percentage;
    int cid[10];
    char transport[50];
}  oneStud;

struct admin{
    char pwd[10];
    char login[10];
}adminStruct;

// Function to add the student
void addStudent()
{
    FILE *studFile=NULL;
    studFile = fopen("d:\\studdata.txt", "a");
   

    printf("\n\t\t\t**************************\n");
    printf("\t\t\tAdd the Students Details\n");
    printf("\t\t\t**************************\n");
    printf("\t\t\tFirst Name: ") ;
    scanf("%s", oneStud.fname);
    printf("\t\t\tLast Name: ");
    scanf("%s", oneStud.lname);
    printf("\t\t\tFather's Name: ");
    scanf("%s", oneStud.fathername);
    printf("\t\t\tRoll number: ");
    scanf("%d", &oneStud.roll);
    printf("\t\t\tClass: ");
    scanf("%d",&oneStud.class);
    printf("\t\t\tSection: ");
    scanf("%s", oneStud.sec);    
    printf("\t\t\tPercentage: ");
    scanf("%d", &oneStud.percentage);
    printf("\t\t\tEnter the course ID of each of the 5 courses : ");
    for (int j = 0; j < 5; j++) {
        scanf("%d", &oneStud.cid[j]);
    }
    printf("\t\t\tTransport details: ");
    scanf("%s",oneStud.transport);
   
    //printf("Writing to file %s\n", oneStud.fname );
    //fwrite(oneStud.fname, 6,  sizeof(char), studFile );
    fwrite (&oneStud, 1, sizeof(struct sinfo), studFile );
    fclose(studFile);

}// end of add data

//Function to find student by Father's name
void findFather_()
{
    char a[50];
    printf("\t\t\tEnter Father's name: ");
    scanf("%s", a);
    int flagFound = 0;
    FILE *studFile=NULL;
    studFile = fopen("d:\\studdata.txt", "r");
    while( fread(&oneStud,  sizeof(struct sinfo), 1 , studFile) >0 ) {
        if (strcasecmp(oneStud.fathername, a)==0)
        {
            printf("\t\t\t***********************\n");
            printf("\t\t\tThe Students Details are\n");
            printf("\t\t\t***********************\n");
            printf( "\t\t\tFirst name is %s\n", oneStud.fname);
            printf( "\t\t\tLast name is %s\n", oneStud.lname);
            printf( "\t\t\tFather's name is %s\n", oneStud.fathername);
       printf( "\t\t\tClass is %d\n ", oneStud.class);
            printf( "\t\t\tSection is %s\n", oneStud.sec);  
            printf( "\t\t\tRoll Number is %d\n ", oneStud.roll);
            printf( "\t\t\tThe Percentage is %d\n", oneStud.percentage);
            printf( "\t\t\tTransport is %s\n", oneStud.transport);
            printf( "\t\t\tThe course ID are ");
            for (int j = 0; j < 5; j++) {
                    printf(" %d \, ", oneStud.cid[j]);
            }
            flagFound=1;
       
        } // end of if
    } // end of while
    if ( flagFound == 0) {
            printf( "Invalid Father's name\n");
    }
} // end of find fathers name

//Function to find student by Father's name
void findFirstName_()
{
    char a[50];
    printf("\t\t\tEnter First name: ");
    scanf("%s", a);
    int flagFound = 0;
    FILE *studFile=NULL;
    studFile = fopen("d:\\studdata.txt", "r");
    while( fread(&oneStud,  sizeof(struct sinfo), 1 , studFile) >0 ) {
        if (strcasecmp(oneStud.fname, a)==0)
        {
            printf("\n\t\t\t***********************\n");
            printf("\t\t\tThe Students Details are\n");
            printf("\t\t\t***********************\n");
            printf( "\t\t\tFirst name is %s\n", oneStud.fname);
            printf( "\t\t\tLast name is %s\n", oneStud.lname);
            printf( "\t\t\tFather's name is %s\n", oneStud.fathername);
       printf( "\t\t\tClass is %d\n ", oneStud.class);
            printf( "\t\t\tSection is %s\n", oneStud.sec);  
            printf( "\t\t\tRoll Number is %d\n ", oneStud.roll);
            printf( "\t\t\tThe Percentage is %d\n", oneStud.percentage);
            printf( "\t\t\tTransport is %s\n", oneStud.transport);
            printf( "\t\t\tThe course ID are ");
            for (int j = 0; j < 5; j++) {
                    printf(" %d \, ", oneStud.cid[j]);
            }
            flagFound=1;
       
        } // end of if
    } // end of while
    if ( flagFound == 0) {
            printf( "Invalid first name\n");
    }
} // end of find First name

// Function to print the total
// number of students
void total()
{
    FILE *studFile=NULL;
    int cnt = 0;
    studFile = fopen("d:\\studdata.txt", "r");
    while( fread(&oneStud,  sizeof(struct sinfo), 1 , studFile) >0 ) {
        cnt ++;
    }
    fclose(studFile);
    printf("\t\t\t****************************************\n");
    printf("\t\t\tThe total number of students are %d\n",cnt);
    printf("\t\t\t*****************************************\n");
    printf("\n\t\t\t you can have a max of 60 students\n");
    printf("\t\t\tyou can have %d more students\n",60 - cnt);
}// end of total students

//To find maximum percentage and average

void marks(){

    int mClass=0 ,cnt=0;
    char mSection[2];

    printf("Enter the class(0 to 12):\n");

    scanf("%d", &mClass);

    printf("Enter the section(A, B, C or D):\n");
    scanf("%s", mSection);
    int c = 0, fndFlag = 0, totalMarks = 0, maxMarks = 0, minMarks = 0;
    FILE *studFile=NULL;
    studFile = fopen("d:\\studdata.txt", "r");
    while( fread(&oneStud,  sizeof(struct sinfo), 1 , studFile) >0 )
    {
        if (oneStud.class== mClass && strcasecmp(oneStud.sec,  mSection) == 0)
        {
   fndFlag =1;
       cnt++;
       if ( c==0)
            {
    minMarks = oneStud.percentage;
                c++;
            }// end of if
    totalMarks = totalMarks + oneStud.percentage;

   if (maxMarks < oneStud.percentage)
    maxMarks = oneStud.percentage;

        if ( minMarks > oneStud.percentage)
    minMarks = oneStud.percentage;
           
            fndFlag = 1;
        } // end of if comparison
    } // end of while
   
    if ( fndFlag ==1 ){
            printf("\t\t\t***********************\n");

            printf("\t\t\tThe Marks Analysis  is\n");

            printf("\t\t\t***********************\n");

            printf( "\t\t\tMaximum Marks is %d\n", maxMarks);

            printf( "\t\t\tMinimum Marks is %d\n", minMarks);

            printf( "\t\t\tAverage is  %d\n", totalMarks/cnt);

   }
    else
   {
             printf( "\t\t\tInvalid section or class\n");
   }

} // end of function marks

void findTransport_()
{
    char a[50];
    printf("Enter transport:\n");
    scanf("%s", a);
    int flagFound = 0;
    FILE *studFile=NULL;
    studFile = fopen("d:\\studdata.txt", "r");
    printf("\t\t\t***********************\n");
    printf("\t\t\tThe Students who travel by %s are\n", a);
    printf("\t\t\t***********************\n");
    printf("\t\t\tFirst Name\t\t Last Name \n");

    while( fread(&oneStud,  sizeof(struct sinfo), 1 , studFile) >0 ) {
        if (strcasecmp(oneStud.transport, a)==0)
        {
            printf( "\t\t\t%s", oneStud.fname);
            printf( "\t\t%s\n", oneStud.lname);
            flagFound=1;
       
        } // end of if
    } // end of while
    if ( flagFound == 0) {
            printf( "Invalid transport\n");
    }
} // end of find transport

void sectionDetails_()
{
    char a[3];
    printf("Enter section (A,B,C or D): ");
    scanf("%s", a);
    int flagFound = 0;
    FILE *studFile=NULL;
    studFile = fopen("d:\\studdata.txt", "r");
    printf("\n\t\t\t***********************\n");
    printf("\t\t\tThe Students in section %s are\n", a);
    printf("\t\t\t***********************\n");
    printf("\t\t\tFirst Name\t\t Last Name \t\tRoll No. \t\tFathers Name \n");

    while( fread(&oneStud,  sizeof(struct sinfo), 1 , studFile) >0 ) {
        if (strcasecmp(oneStud.sec, a)==0)
        {
            printf( "\t\t\t%s", oneStud.fname);
            printf( "\t\t%-10s", oneStud.lname);
            printf( "\t\t%-10d", oneStud.roll);
            printf( "\t\t%-10s\n", oneStud.fathername);
            flagFound=1;
       
        } // end of if
    } // end of while
    if ( flagFound == 0) {
            printf( "Invalid transport\n");
    }
} // end of Section details

void deleteStudent_() {
    struct sinfo stud;
    FILE *studFile, *ft;
    int n;
    studFile = fopen("d:\\studdata.txt","r");
    ft = fopen("Temp.dat","w");

    printf("\n\t\t\tEnter roll of student to delete ");

    scanf("%d",&n);
    while( fread(&oneStud,  sizeof(struct sinfo), 1 , studFile) >0 ) {
        if (oneStud.roll!=n)
        {
            fwrite (&oneStud, 1, sizeof(struct sinfo), ft );
        }
    }

    fclose(studFile);
    fclose(ft);
    remove("d:\\studdata.txt");
    rename("Temp.dat","d:\\studdata.txt");
} // End of delete record

void updateStudent_() {
    struct sinfo stud;
    FILE *studFile, *ft;
    int n, choice, j;
    studFile = fopen("d:\\studdata.txt","r");
    ft = fopen("Temp.dat","w");

    printf("\n\t\t\tEnter roll of student to update :");

    scanf("%d",&n);

    while( fread(&oneStud,  sizeof(struct sinfo), 1 , studFile) >0 ) {
        if (oneStud.roll!=n)
        {
            fwrite (&oneStud, 1, sizeof(struct sinfo), ft );
        }
        else
        {
            printf("\n\t\t\tWhat do you want to update?\n");
            printf("\t\t\t1: Update Class and Section\n");
            printf("\t\t\t2: Update Transport details\n");
            printf("\t\t\t3: Update course ids\n");
            printf("\t\t\t4: Exit\n");
            printf("\t\t\tEnter you choice :");
            scanf("%d", &choice);
            switch(choice){
                case 1:
                    printf("\n\t\t\tEnter the class :");
                    scanf("%d", &oneStud.roll);
                    printf("\n\t\t\tEnter the section :");
                    scanf("%d", &oneStud.sec);
                    break;
                case 2:
                    printf("\n\t\t\tEnter the transport :");
                    scanf("%s", oneStud.transport);
                    break;
                case 3:
                    for ( j = 0 ; j<5; j++){
                        printf("\n\t\t\tEnter the courseid %d:", j);
                        scanf("%d", &oneStud.cid[j]);
           
                    }
                    break;
                case 4:
                    fclose(studFile);
                    fclose(ft);
                    return;

            }
            fwrite (&oneStud, 1, sizeof(struct sinfo), ft );
        }// end of if
    }// end of while
    

    fclose(studFile);
    fclose(ft);
    remove("d:\\studdata.txt");
    rename("Temp.dat","d:\\studdata.txt");
} // End of updateStudent_



main()
{
    int choice, count;
    char userpwd[10], userLogin[10];
    FILE *adminFile;
   

    // check admin login
    /*adminFile = fopen("d:\\admin.txt", "w");
    printf("Enter User Id : ");
    scanf("%s", &adminStruct.login);
    printf("Enter Password : ");
    scanf("%s", &adminStruct.pwd);
    fwrite(&adminStruct,  sizeof(struct admin), 1 , adminFile) ;
    fclose(adminFile);
    */
    adminFile = fopen("d:\\admin.txt", "r");
    fread(&adminStruct,  sizeof(struct admin), 1 , adminFile) ;
    fclose(adminFile);

    //clrscr();
    system("clear");
    printf("\t\t\t**********************************\n");
    printf("\t\t\tEnter User Id : ");
    scanf("%s", userLogin);
    printf("\t\t\tEnter Password : ");
    scanf("%s", userpwd);
    printf("\t\t\t**********************************\n");
   
    if ( strcmp(adminStruct.pwd, userpwd) == 0 && strcmp(adminStruct.login, userLogin) == 0 )
    {


    }
    else{
        printf("LOGIN ID/ PASSWORD ARE INVALID!");
        return 1;
    }    

    FILE *studFile=NULL;
    studFile = fopen("d:\\studdata.txt", "r");
    if (studFile == NULL) {
        i =0;
    }
    else
    {
        while( fread(&oneStud,  sizeof(struct sinfo), 1 , studFile) >0 ) {
        /*printf("READ DATA%s", oneStud.fname);
        printf("READ DATA%s", oneStud.lname);
        printf("READ DATA%s", oneStud.fathername);
        printf("READ DATA%d", oneStud.class);
        printf("READ DATA%s", oneStud.sec);
        printf("READ percentage%d", oneStud.percentage);
        printf("READ transport%s", oneStud.transport);
        printf("READ rollno%d", oneStud.roll);
        printf("READ cid1%d", oneStud.cid[0]);
        printf("READ DATA%d", oneStud.cid[1]);
        printf("READ DATA%d", oneStud.cid[2]);
        */
            i = i + 1;
        } // End of while
        fclose(studFile);
    }
   
    while(1)
    {
            printf("\n\t\t\t**********************************\n");
            printf("\t\t\tWelcome!\n");
            printf("\t\t\tSelect what you want to do\n");
            printf("\t\t\t-------------------------------\n");
            printf("\t\t\t1. Add the Student Details\n");
            printf("\t\t\t2. Find Student By Father's name \n");
            printf("\t\t\t3. Find the Student by First Name\n");
            printf("\t\t\t4. Find the Students in a particular section\n");
            printf("\t\t\t5. Find the Total number of Students \n");
            printf("\t\t\t6. Marks statistics\n");
            printf("\t\t\t7. Transport Records\n");
            printf("\t\t\t8. Delete a student\n");
            printf("\t\t\t9. Update a student\n");
           
            printf("\t\t\t10. Exit\n");
            printf("\n\t\t\t**********************************\n\n");
            printf("\t\t\tEnter your choice number  :  ");
            scanf("%d", &choice);
            printf("\n\t\t\t**********************************\n\n");
            switch (choice)
            {
                case 1:
                    addStudent();
                    break;
                case 2:
                    findFather_();
                    break;
                case 3:
                    findFirstName_();
                    break;
                case 4:
                    sectionDetails_();
                    break;
                case 5:
                    total();
                    break;
                case 6:
                    marks();
                    break;
                case 7:
                    findTransport_();
                    break;
                case 8:
                    deleteStudent_();
                    break;
                case 9:
                    updateStudent_();
                    break;
                case 10:
                    return 1;
            }
    }
}