#include<stdio.h>
int main(){
    printf("\n=========================================");
    printf("\n\tRESULT PROCESSING");
    printf("\n=========================================");

    int no_of_stds;
    printf("\nEnter no of students : ");
    scanf("%d", &no_of_stds);

    float sub_marks[3];
    float avg;
    float sum;

    for(int i = 0; i < no_of_stds; i++) {
        sum = 0;
        printf("\nResult Processign For Student %d started", i+1);

        for(int j = 0; j < 3; j++) {

            label1:
            printf("\nEnter the %d Subject marks(0-100) for Student %d : ", j+1,i+1);
            scanf("%f", &sub_marks[j]);

            if(sub_marks[j] < 0 || sub_marks[j] > 100 ) {
                printf("\nINVALID INPUT[!]");
                goto label1;
            }
            sum+=sub_marks[j]; 
        }

        avg = sum / 3;
        

        switch ((int)avg / 10)
        {
        case 9:
        case 10:
            printf("\nGRADE A");
            break;
        case 8:
            printf("\nGRADE B");
            break;
        case 7:
            printf("\nGRADE C");
            break;
        case 6:
            printf("\nGRADE D");
            break;
        default:
            printf("\nGRADE F");
            break;
        }

        printf("\nTHE %d student has %s", i+1, (avg >= 60 && sub_marks[0] >= 40 && sub_marks[1] >= 40 && sub_marks[2] >= 40) ? "PASSED" : "FAILED");
    }

   

    return 0;
}