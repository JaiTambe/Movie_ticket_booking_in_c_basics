#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int book(const char *filename, int lineNumber, int status)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 0;
    }

    // Open a temporary file for writing
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL)
    {
        perror("Error opening temporary file");
        fclose(file);
        return 0;
    }

    char buffer[1024];
    int currentLine = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {

        currentLine++;

        if (currentLine == lineNumber)
        {   
            int num;
            int lastNumber;
            char* token = strtok(buffer, " ");
            while (token != NULL) 
            {
                if (sscanf(token, "%d", &num) == 1)
                {
                    lastNumber = num;
                }
                token = strtok(NULL, " ");
            }
            int st=lastNumber;
            if (st==status)
            {
                printf("The seat number %d is already booked kindly book another seat\n",lineNumber);
                fclose(file);
                fclose(tempFile);
                remove("temp.txt");
                return 1;
            }
            fprintf(tempFile, " %d %d\n", lineNumber, status);
        } else
        {
            fprintf(tempFile, "%s", buffer);
        }
        
    }
    if (status==1)printf("The seat number %d is successfully booked\n\n",lineNumber);
    if (status==0)printf("The seat number %d is successfully cancelled\n\n",lineNumber);
    fclose(file);
    fclose(tempFile);
    
    // Remove the original file
    if (remove(filename) != 0)
    {
        perror("Error removing original file");
        return 0;
    }

    // Rename the temporary file to the original filename
    if (rename("temp.txt", filename) != 0)
    {
        perror("Error renaming temporary file");
        return 0;
    }


}
void display(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    char buffer[10];
    int currentLine = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        currentLine++;
        int num;
        int lastNumber = 0; // Initialize to 0 or another appropriate default value

    // Use sscanf to extract the last number from the line
        char* token = strtok(buffer, " ");
        while (token != NULL) 
        {
            if (sscanf(token, "%d", &num) == 1)
            {
                lastNumber = num;
            }
            token = strtok(NULL, " ");
        }
        int st=lastNumber;
        if (st == 0)
        {
            printf("%d\t", currentLine);
        } else {
            printf("*");
            printf("\t");
        }

        if (currentLine % 10 == 0)
        {
            printf("\n");
        }
    }

    fclose(file);
}

int main()
{
for (int i = 1; i < 4; i++)
{
    for (int j = 1; j < 4; j++)
    {
        char screen[2]; // Increased size to hold single digit and null terminator
        char time[2];   // Increased size to hold single digit and null terminator
        sprintf(screen, "%d", i);
        sprintf(time, "%d", j);
        char wf[10];
        strcpy(wf, screen);
        strcat(wf, time);
        FILE *f = fopen(strcat(wf, ".txt"), "w");
        const char *text = "Write this to the file";
        int s;
        int b = 0;
        for (s = 1; s <= 50; s++)
        {
            int tuple1 = s;
            int tuple2 = b;
            fprintf(f, " %d %d\n", tuple1, tuple2);
            }
        fclose(f); // Close the file, not the filename
        }
    }


    int choice;
    
    printf("\n\n\t Movie Ticket Booking System\n");
    printf("   ==========================================\n");
    printf("\n\t WELCOME TO BookMyTicket.com\n\n\n");
    int newticketprice=500;
    do
    {
        printf("===========================================\n");
        printf("  1- To edit price of ticket(only Admin)\n");
        printf("  2- For Reservation\n");
        printf("  3- Purchased Ticket Details\n");
        printf("  4- To Cancel Seat \n");
        printf("  5- Exit system\n");
        printf("===========================================\n\n\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Choice is 1:\n");
                printf("To edit price of ticket\n\n\n");
                
                printf("Before editing the price is : %d\n",newticketprice);
                char pass[10];
                char pask[10]="qwe";
                
                printf("Enter The Password :\n");
                scanf("%s",pass);
                if(strcmp(pass,pask)==0)
                {
                printf("Please enter new price\n");
                scanf("%d", &newticketprice);
                } else {
                    printf("The entered password is wrong!\n");
                    
                    }
                break;
            case 2:
                printf("                                             For Reservation                                         \n");
                printf("                                                MOVIES                                               \n");
                printf("      Movie name             Code        Language          Date              Screen     Shows      Time   \n\n\n");
                
                printf("    1) Bhool Bhulaiyaa 3      10           Hindi           12-11-2024           1          1       11:00 AM\n");
                printf("                                                                                1          2       03:00 PM\n");
                printf("                                                                                1          3       06:00 PM\n\n");
                
                printf("    2) Singham Again          20           Hindi           12-11-2024           2          1       11:00 AM\n");
                printf("                                                                                2          2       03:00 PM\n");
                printf("                                                                                2          3       06:00 PM\n\n");
                
                printf("    3) Venom                  30          English          12-11-2024           3          1       11:00 AM\n");
                printf("                                                                                3          2       03:00 PM\n");
                printf("                                                                                3          3       06:00 PM\n");
        
            
            
            
                int movieCode, screenNumber, showNumber;
            
                // Get user input
                printf("Enter movie code: \n");
                scanf("%d", &movieCode);
            
                printf("Enter screen number and show number:\n");
                scanf("%d%d", &screenNumber,&showNumber);
            
            
                 // * indicates movieName is pointer variable .it stores the memory address of another variable
                // gets movie name based on code
                char* movieName;
                switch (movieCode)
                {
                    case 10:
                        movieName = "Bhool Bhulaiyaa 3";
                        break;
                    case 20:
                        movieName = "Singham Again";
                        break;
                    case 30:
                        movieName = "Venom";
                        break;
                    default:
                        movieName = "Invaild Code!!!!";
                        break;
                }
            
            
                printf("Movie : %s\nScreen: %d\nShow  : %d\n", movieName, screenNumber, showNumber);
            
                char name[50];
                long long phoneNumber;
            
                // Get user input
                printf("Enter your name: \n");
                scanf("%s", name);
            
                printf("Enter your phone number: \n");
                scanf("%lld", &phoneNumber);
            
                // Print user information
                printf("\nName: %s\nPhone Number: %lld\n", name, phoneNumber);
            
            
                char xyz[20]; // Increased array size to accommodate the concatenated string
                sprintf(xyz, "%d%d.txt", screenNumber, showNumber); // Used sprintf to format the string
                display(xyz);
                int seat;
                printf("Enter number of seats: \n");
                scanf("%d",&seat);
                int seatnum;
                for(int i=1;i<=seat;i++)
                {
                    printf("Enter seat number:\n ");
                    scanf("%d",&seatnum);
                    int z=book(xyz,seatnum,1);
                    i=i-z;
                }
                break;
        
            case 3:
                char* timeM;
                switch (screenNumber)
                {
                    case 1:
                        timeM = "11:00 AM";
                        break;
                    case 2:
                        timeM = "03:00 PM";
                        break;
                    case 3:
                        timeM = "06:00 PM";
                        break;
                    default:
                        timeM = " Sorry no show avaliable ";
                        break;
                }
                int cgst,sgst;
                int number;
            
                int netamt=newticketprice*seat;
                

                if (newticketprice<=100)
                {
                    number=9;
                    cgst = 0.09 * netamt;
                    sgst = 0.09 * netamt;
                } 
                else 
                {
                    number=14;
                    cgst = 0.14 * netamt;
                    sgst = 0.14 * netamt;
                }

                int totalAmount=netamt+cgst+sgst;

            
            
                display(xyz);
                printf("\n\n\n                          MOVIE  TICKET      \n \n");
                printf("Name           : %s\n",name);
                printf("Mobile Number  : %lld\n",phoneNumber);
                printf("Movie          : %s\n",movieName);
                printf("Number of seats: %d\n", seat);
                
                printf("Screen         : %d\n",screenNumber);
                printf("Show           : %d\n",showNumber);
                printf("Time           : %s\n",timeM);
                printf("Net Amount     : ₹ %d\n",netamt);
                printf("SGST  %%%d      : ₹ %d\n",number,sgst);
                printf("CGST  %%%d      : ₹ %d\n",number,cgst);
                printf("Total Amount   : ₹ %d\n",totalAmount);
                
                break;
            
            case 4:
                int seatcan;
                int seatb;
                printf("Enter number of seats to be cancelled\n");
                scanf("%d",&seatcan);

                int rcgst,rsgst;
                int refundamta=newticketprice*seatcan;

                if (newticketprice<=100)
                {
                    number=9;
                    rcgst = 0.09 * refundamta;
                    rsgst = 0.09 * refundamta;
                } 
                else 
                {
                    number=14;
                    rcgst = 0.14 * refundamta;
                    rsgst = 0.14 * refundamta;
                }

                int refundamtb=refundamta+rcgst+rsgst;
                
        
                for(int i=1;i<=seatcan;i++)
                {
                    printf("Enter seat number\n");
                    scanf("%d",&seatb);
                    int z=book(xyz,seatb,0);
                    i=i-z;
                    
                }

                display(xyz);
                printf("\n\nName                    :  %s\n",name);
                printf("Mobile Number           :  %lld\n",phoneNumber);
                printf("Number of seat cancelled:  %d\n",seatcan);
                printf("SGST  %%%d               : ₹ %d\n",number,rsgst);
                printf("CGST  %%%d               : ₹ %d\n",number,rcgst);
                printf("The Refunded Amount is  : ₹ %d\n\n",refundamtb);

                break;
        
            case 5:
                printf("\t\t\tUPCOMING MOVIES\n");
                printf("\t\t******************************\n");
                printf("\t\tSalaar:Part 1 ceasefire\n\t\tKalki 2898 AD\n\t\tWelcome 3\n\t\tSingham 3\n");
                printf("\n\n\t\t\t Team Members :\n\n");
                printf("\t1) Jai \t 2) Chirag\t 3) Abhilash\t 4)Aditya");
                printf("\n\n\n\t\t\t-UNDER THE GUIDANACE OF\n\t\t\t Prof. Swati Sajjan\n");
                printf("\n\n\t\t Thank You Vist Again\n");
                printf("\t **********************************\n");
                break;
            
            default:
                printf("\n\n PLEASE CHOOSE CORRECT CHOICE\n");
                break;
        }
    }
    while(choice!=5);
    
}