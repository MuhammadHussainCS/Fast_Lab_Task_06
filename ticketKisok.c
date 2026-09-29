#include <stdio.h>
#include<stdlib.h>
int main(){
    printf("\n************************************************");
    printf("\n\tTICKET BOOKING SYSTEM");
    printf("\n************************************************");
    int age,day_no;
    int show_category;
    float ticket_price = 0,discount = 0, payable_amount = 0;
    do {
    label1:
    printf("\nEnter Age : ");
    scanf("%d", &age);

    if(age == 0) {
        printf("\nBye Bye");
        exit(0);
    }

    if(age<0) {
        printf("\nInvalid input[!]\n");
        goto label1;
    }
    
    label2:
    printf("\nSelect Show Category : ");
    printf("\n1. A regular movie");
    printf("\n2. A 3D Movie");
    printf("\n3. A Premiere (first-day) show");
    printf("\nChoice : ");
    scanf("%d", &show_category); 
    
    if(show_category<1 || show_category>3) {
        printf("\nInavlid Input[!]");
        goto label2;
    }

    label3:
    printf("\nEnter Day Number : ");
    scanf("%d", &day_no);

    if(day_no<1 || day_no>31) {
        printf("\nInvalid Input[!]");
        goto label3;
    }

    printf("\n****************************************************");
    printf("\n\tRECEIPT GENERATOR");
    printf("\n****************************************************");
    switch (show_category)
        {
        case 1:
            printf("\nShow Category = REGULAR MOVIE");
            ticket_price = 500;
            printf("\nTicket BASE PRICE = %.2f" , ticket_price);
            break;
        case 2:
            ticket_price = 800;
            printf("\nShow Category = 3D MOVIE");
            printf("\nTicket BASE PRICE = %.2f" , ticket_price);
            break;
        case 3:
            printf("\nShow Category = Premiere (first-day) show.");
            ticket_price = 1200;
            printf("\nTicket BASE PRICE = %.2f" , ticket_price);
            break;
        }

        if(age<13) {
                discount = 0.30 * ticket_price;
                printf("\n30%% Discount applied due to age less than 13");
                printf("\nDiscount applied = %.2f", discount);
            } else if(age>=60) {
                discount = 0.20 * ticket_price;
                printf("\n20%% Discount applied due to age 60 or above");
                printf("\nDiscount applied = %.2f", discount);
            } else {
                discount = 0;
                printf("\nNo Discount is Applicable");
            }

            if((day_no % 5) == 0) {
                discount += 50;
                printf("\nRS. 50 Discount is applied more due to bonus day");
            } 
                
            payable_amount = ticket_price - discount;
            
            if(payable_amount<100) {
                payable_amount = 100;
            } 

            printf("\nPayable Amount = %.2f", payable_amount);

    } while(age != 0);

    return 0;
}