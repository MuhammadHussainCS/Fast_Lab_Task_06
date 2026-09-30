#include <stdio.h>

int main() {
    int light = 1;
    int water_heater = 2;
    int air_conditioner = 4;
    int camera = 8;
    int current_status;
    printf("\n+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*");
    printf("\n\t\tThe Hillcrest Apartments Smart Utility Panel\n");
    printf("+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*+=*");

    
    
    int shift_done;
    int choice;
    do {
        printf("\nDo shift done ?(-1 = done)/(anynumber except -1 = not done) : ");
        scanf("%d", &shift_done);

        if(shift_done == -1) {
            printf("\nExiting the program");
            break;
        }

        label1:
        printf("\nEnter current status of appliances : ");
        scanf("%d", &current_status);

        if(current_status>15 || current_status<0) {
        printf("\nInvalid Input[!]");
        goto label1;
        }
        
        label2:
        printf("\nSelect Choice : ");
        printf("\n1. WATER HEATER ON");
        printf("\n2. AirConditioner OFF");
        printf("\n3. Flip the main lights");
        printf("\n4. Camera Report");
        printf("\nChoice : ");

        scanf("%d", &choice);

        if(choice < 1 || choice > 4) {
            printf("\nInvalid Input[!]");
            goto label2;
        }
        
        switch (choice)
        {
        case 1:
            if(current_status & water_heater) {
                printf("\nWater Heater is already ON");
            } else {
                current_status = current_status + water_heater;
                printf("\nWater heater  is Now ON");
            }
            break;
        case 2://1 1 1 1
               //1 0 1 1
               //-------
               //1 0 1 1 = 11
            if(current_status & air_conditioner) {
                current_status = current_status & ~(air_conditioner);
                printf("\nAir conditioner is now OFF");
            } else {
                printf("\nAir conditioner is already OFF");
            }
            break;
        case 3:
        // 1 1 1 0 = 14 |   // 0 1 0 1 = 5
        // 0 0 0 1      |   // 0 0 0 1
        //--------      |   //---------
        // 1 1 1 1 = 15 |   // 0 1 0 0 = 4
            current_status = current_status ^ light;
            printf("\nLight Status has been toggled\n");
            if(current_status & light) {
                printf("\nCurrent Status Of Light = ON");
            } else {
                printf("\nCurrent Status Of Light = OFF");
            }
            break;

        case 4:
            if(current_status & camera) {
                printf("\nSecurity Camera is ON");
            } else {
                printf("\nSecurity Camera is OFF");
            }
        default:
            printf("\nInvalid Choice[!]");
            break;
        }        

        printf("\nCurrent status = %d", current_status);

        if((current_status & water_heater) && (current_status & air_conditioner)) {
            printf("\nWARNING[!].Water heater and Air conditioner both are ON");
        }

    } while(shift_done != -1);

    return 0;
}
