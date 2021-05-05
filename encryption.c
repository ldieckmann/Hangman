#include <stdio.h>
/*This function does encrypt the wordlist textfile*/
int Encryption()
{
    char sourceFile[50] = "wordlist.txt", targetFile[53], ch; //char for wordlist textfile
    FILE* fs;
    fs = fopen (sourceFile, "r");
    if (fs == NULL)
    {
        printf ("Error while opening wordlist file!\n"); //prints an error is the wordlist file wasn't found
        return 1; //returns 1 if the wordlist file wasn't found
    }
    //Encryption algorithm
    sprintf (targetFile, "%s.ed", sourceFile);
    FILE* ft;
    ft = fopen (targetFile, "w");
    while ((ch = fgetc (fs)) != EOF)
        fputc (~ch, ft);
    fclose (fs);
    fclose (ft);
    remove (sourceFile); //removes the old wordlist.txt
    rename (targetFile, sourceFile); //renames the new encrypted file to wordlist.txt
    return 0; //returns 0 if the file was encrypted successfully
}
/*This function does encrypt the wordlist textfile*/
/*This function is NOT FINISHED !!*/

/*
int Decryption() {

    char sourceFile[50] = "wordlist.txt", targetFile[53], ch;
    FILE* fs;
    fs = fopen (sourceFile, "r");
    if (fs == NULL)
    {
        printf ("Error while opening wordlist file!\n");
        return 1;
    }
    sprintf (targetFile, "%s.ed", sourceFile);
    FILE* ft;
    ft = fopen (targetFile, "w");
    while ((ch = fgetc (fs)) != EOF)
        fputc (~ch, ft);
    fclose (fs);
    fclose (ft);
    remove (sourceFile);
    rename (targetFile, sourceFile);
    return 0;
}
*/

