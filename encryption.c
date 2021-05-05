//#include "encryption.h"
//int main()
//{
//    char encFile[20] = "wordlist.txt";
//    char newencFile[20] = "wordlist.txt";
//    char decFile[20] = "wordlist.txt";
//    char newdecFile[20] = "wordlist.txt";
//
//    Encrypt(encFile, newencFile); //Call of the function which encrypts the wordlist file
//    Decrypt(decFile, newdecFile); //Call of the function which decrypts the wordlist file
//}
//
//int Encrypt(char * FILENAME, char * NEW_FILENAME)
//{
//    FILE *inFile;   //Declare inFile
//    FILE *outFile;  //Declare outFile
//    char Byte;
//    char newByte;
//    int n;
//    int i=0;
//
//    inFile = fopen(FILENAME,"rb");
//    outFile = fopen(NEW_FILENAME, "w");
//
//    if(inFile == NULL || outfile == NULL){
//        printf("Error in opening file");
//            return 1;
//    } else {
//        printf("\nFile Opened, Encrypting");
//        while(1){
//                while ( !feof( inFile ) ){
//                    Byte=fgetc(inFile);
//                    newByte=Byte+25;
//                    fputc(newByte,outFile);
//                }
//            printf("End of File");
//            break;
//        }
//        fclose(inFile);
//        fclose(outFile);
//    }
//}
//
//int Decrypt (char *FILENAME, char *NEW_FILENAME)
//{
//    FILE *inFile; //Declare inFile
//    FILE *outFile; //Declare outFile
//
//    char Byte;
//    char newByte;
//    int i=0;
//
//    inFile = fopen(FILENAME,"rb");
//    outFile = fopen(NEW_FILENAME, "w");
//
//    if(inFile == NULL || outfile == NULL){
//        printf("Error in opening file");
//        return 1;
//    } else {
//        printf("File Opened, Decrypting");
//        while(1){
//            printf(".");
//            while ( !feof( inFile ) ){
//                Byte=fgetc(inFile);
//                newByte=Byte-25;
//                fputc(newByte,outFile);
//            }
//            printf("End of File");
//            break;
//        }
//        fclose(inFile);
//        fclose(outFile);
//    }
//}
