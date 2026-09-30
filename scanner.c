#include<stdio.h>
int main(){
    printf("\n*****************************************************");
    printf("\n\tThe Coastal Freight Container Scanner");
    printf("\n*****************************************************");

    int no_of_containers;
    float container_weight;
    int cargo_type;

    label1:
    printf("\nENTER THE NUMBER OF CONTAINERS TO CHECK TODAY : ");
    scanf("%d", &no_of_containers);
    if(no_of_containers<0) {
        printf("\nINVALID INPUT[!]");
        goto label1;
    }

    for(int i = 1; i <= no_of_containers; i++) {
        
        int allowed = 0;

        label2:
        printf("\nEnter Container Weight : ");
        scanf("%f", &container_weight);
        if(container_weight<=0) {
            printf("\nINVALID INPUT[!]");
            goto label2;
        }

        label3:
        printf("\nEnter Cargo type");
        printf("\n1. GENERAL GOODS");
        printf("\n2. HAZARDOUS MATERIALS");
        printf("\n3. REFRIGERATED GOODS");
        printf("\nCHOICE : ");
        scanf("%d", &cargo_type);

        if(cargo_type < 1 || cargo_type > 3) {
            printf("\nINVALID INPUT[!]");
            goto label3;
        }

        switch (cargo_type)
        {
        case 1:
            if(container_weight <= 20000) {
                printf("\nPermisiion granted. You can load your container");
                allowed = 1;
            } else {
                printf("\nPermission denied due to Heavy Weight");
            }
            break;
        case 2:
            if(container_weight<=15000 && (i%2 != 0)) {
                printf("\nPermisiion granted. You can load your container");
                allowed = 1;
            } else {
                printf("\nPermission denied due to Heavy Weight/even place order");
            }
            break;
        case 3:
            if(container_weight<=18000) {
                printf("\nPermisiion granted. You can load your container");
                allowed = 1;
            } else {
                printf("\nPermission denied due to Heavy Weight");
            }
            break;
        default:
            printf("\nINVALID CHOICE[!]");
            break;
        }
        
        
        int remainder = (int)container_weight % 97;
        int  tracking_code = remainder % 100;
        printf("\nTRACKING CODE = %02d",tracking_code);
        
    }

    

    return 0;
}