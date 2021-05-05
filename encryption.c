#include <stdio.h>
/*This function exists to encrypt or decrypt the wordlist textfiles*/
int EncryptAndDecrypt()
{
    char encFile[20] = "wordlist.txt";
    char newencFile[20] = "wordlist.txt";
    char decFile[20] = "wordlist.txt";
    char newdecFile[20] = "wordlist.txt";

    Encrypt(encFile, newencFile); //Call of the function which encrypts the wordlist file
    Decrypt(decFile, newdecFile); //Call of the function which decrypts the wordlist file

}
/*This function will encrypt the wordlist textfile*/
int Encrypt(char * wordlist.txt, char * wordlist.txt)
{
    FILE *inFile;   //Declare inFile
    FILE *outFile;  //Declare outFile
    char Byte;
    char newByte;
    int n;
    int i=0;

    inFile = fopen(wordlist.txt,"rb");
    outFile = fopen(wordlist.txt, "w");

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
int Decrypt (char *wordlist.txt, char *wordlist.txt)
{
    FILE *inFile; //Declare inFile
    FILE *outFile; //Declare outFile

    char Byte;
    char newByte;
    int i=0;

    inFile = fopen(wordlist.txt,"rb");
    outFile = fopen(wordlist.txt, "w");

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
