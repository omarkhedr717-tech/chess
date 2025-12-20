#include "header.h"

void CreateFile(char filename[]) {
    int i=0;
    while (true) {
        sprintf(filename, "savegame%d", i);
        FILE *fp = fopen(filename, "r");
        if (!fp){
            fp = fopen(filename, "w");
            fclose(fp);
            break;
        }
        else {
            fclose(fp);
            i++;
        }
    }
}

void UpdateFile(char filename[], char savegame[]) {
    FILE *fp = fopen(filename, "w");
    fputs(savegame, fp);
    fclose(fp);
}

int LoadFile(char filename[], char savegamefile[]) {
    int flagCreate=0;
    for (int i=0; filename[i]!='\0'; i++)
        {filename[i] = tolower(filename[i]);}

    FILE *fp = fopen(filename, "r");
    if (fp) {
        fgets(savegamefile, 100000, fp);
        fclose(fp);
        return 0;
    }
    else {
        printf("CREATE NEW ONE (1/0)?: \n");
        scanf(" %d",&flagCreate);
        if (flagCreate == 1) {
            CreateFile(filename);
            return 0;
        }
        return 1;
    }
}