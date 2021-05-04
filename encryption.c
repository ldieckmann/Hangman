#include <stdio.h>
/*This function exists to encrypt or decrypt thhe wordlist textfiles at choice*/
int EncryptAndDecrypt()
{
    char encFile[200];
    char newencFile[200];
    char decFile[200];
    char newdecFile[200];

    int choice;

    printf("Enter 1 to Encrypt  / 2 to Decrypt");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        printf("Enter the Source Filename:  ");
        scanf("%s",encFile);
        printf("Enter the Destination Filename:   ");
        scanf("%s",newencFile);
        Encrypt(encFile, newencFile);
        break;
    case 2:
        printf("Enter the Source Filename:   ");
        scanf("%s",decFile);
        printf("Enter the Destination Filename:   ");
        scanf("%s",newdecFile);
        Decrypt(decFile, newdecFile);
        break;
    }
    return 0;
}
/*This function will encrypt the wordlist textfile*/
int Encrypt(char * FILENAME, char * NEW_FILENAME)
{
    FILE *inFile;   //Declare inFile
    FILE *outFile;  //Declare outFile
    char Byte;
    char newByte;
    int n;
    int i=0;

    inFile = fopen(FILENAME,"rb");
    outFile = fopen(NEW_FILENAME, "w");

    if(inFile == NULL || outfile == NULL){
        printf("Error in opening file");
            return 1;
    } else {
        printf("\nFile Opened, Encrypting");
        while(1){
                while ( !feof( inFile ) ){
                    Byte=fgetc(inFile);
                    newByte=Byte+25;
                    fputc(newByte,outFile);
                }
            printf("End of File");
            break;
        }
        fclose(inFile);
        fclose(outFile);
    }
}
/*This function will decrypt the wordlist textfile*/
int Decrypt (char *FILENAME, char *NEW_FILENAME)
{
    FILE *inFile; //Declare inFile
    FILE *outFile; //Declare outFile

    char Byte;
    char newByte;
    int i=0;

    inFile = fopen(FILENAME,"rb");
    outFile = fopen(NEW_FILENAME, "w");

    if(inFile == NULL || outfile == NULL){
        printf("Error in opening file");
        return 1;
    } else {
        printf("File Opened, Decrypting");
        while(1){
            printf(".");
            while ( !feof( inFile ) ){
                Byte=fgetc(inFile);
                newByte=Byte-25;
                fputc(newByte,outFile);
            }
            printf("End of File");
            break;
        }
        fclose(inFile);
        fclose(outFile);
    }
}
