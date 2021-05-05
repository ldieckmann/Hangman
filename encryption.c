#include <stdio.h>
/*This function does encrypt the wordlist textfile*/
int Encryption()
{
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
