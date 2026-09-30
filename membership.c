#include<stdio.h>
int main(){
    int poolAccess = 1;
    int saunaAccess = 2;
    int personalTrainerAccess = 4;
    int allTimeAccess = 8;
    int currentAccess = 0;
    int current_hour;

    while(currentAccess != 9999) {
        label1:
        printf("\nEnter MEMBER Current Access value : ");
        scanf("%d", &currentAccess);

        if(currentAccess == 9999) {
            break;
        } else if(currentAccess<0 || currentAccess>15) {
            goto label1;
        }

        label2:
        printf("\nEnter Current time (24 hr format) : ");
        scanf("%d", &current_hour);

        if(current_hour<0 || current_hour>=24) {
            printf("\nINVALID INPUT[!]");
            goto label2;
        }

        if(current_hour>=22 || current_hour<6) {
            printf("\nLATE NIGHT MODE");

            if(currentAccess & allTimeAccess) {
                printf("MEMBER ENTRY IS ALLOWED");
            } else {
                printf("\nMEMBER HAVE NOT ALL TIME ACCESS PERMISSION");
            }
        } else {
            printf("\nSTANDARD MODE");

            if((currentAccess & poolAccess) || (currentAccess & saunaAccess) || (currentAccess & personalTrainerAccess)) {
                printf("\nMEMBER ENTRY IS ALLOWED");
            } else {
                printf("\nMEMBER HAS NO PERMISSION");
            }
        }

        
        if(currentAccess & personalTrainerAccess) {
            printf("\nMEMBER HAVE ACCESS TO PERSONAL TRAINER");
        } else {
            printf("\nMEMBER HAVE NOT ACCESS TO PERSONAL TRAINER");
        }
        
    }
    return 0;
}