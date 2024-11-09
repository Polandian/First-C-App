#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

FILE *fptr;

void writeToFile(char fileName[15], char fileText[50]){ //This is a function basically
    fptr = fopen(fileName, "w");
    fprintf(fptr, fileText);
    fclose(fptr);
    //End
    printf("\n\nText written successfully!\nCheck the file called %s.", fileName);
}

int main(){
    char userName[20];
    char userPassword[50];

    fptr = fopen("_USER-DATA.malloc", "r");

    if(fptr == NULL){ //If a save does not exist
        fclose(fptr);

        printf("Yo!\nI saw you are not logged in on our system!\nLets do that! Enter ya name: ");
        fgets(userName, sizeof(userName), stdin);

        printf("\nAlright! Yo account is named %s. Now, lets add some password to it: ", userName);
        fgets(userPassword, sizeof(userPassword), stdin);

        char userDataMalloc[70];
        sprintf(userDataMalloc, "%s%s", userName, userPassword);
        writeToFile("_USER-DATA.malloc", userDataMalloc);
    }
    else{
        int i; //i for for loop
        char userData[2][50]; //gets all user data (2)
        
        fptr = fopen("_USER-DATA.malloc", "r"); //start reading the file
        for(i = 0; i < sizeof(fptr); i++){
            fgets(userData[i], 100, fptr); //write all data to userData line by line
        }

        strcpy(userName, userData[0]);    //set userName
        strcpy(userPassword, userData[1]);//set userPassword

        printf("\nYou are already logged in!\n\nYour name is: %sYour password is: %s", userName, userPassword);
        fclose(fptr);
    }
    return 0;
}