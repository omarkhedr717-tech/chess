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

void UpdateFile(char filename[], char savegame[], int promotion_hist[], int draw_hist) {
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "%s\n", savegame);
    for(int i = 0; i < 16; i++)
        fprintf(fp, "%d", promotion_hist[i]);
    fprintf(fp, "%d", draw_hist);
    fclose(fp);
}

int LoadFile(char filename[], char savegamefile[], int promotion_hist[], int *draw_hist) {
    int flagCreate=0;
    for (int i=0; filename[i]!='\0'; i++)
        {filename[i] = tolower(filename[i]);}

    FILE *fp = fopen(filename, "r");
    if (fp) {
    fgets(savegamefile, 100000, fp);
        for(int i = 0; i < 16; i++)
            fscanf(fp,"%1d", &promotion_hist[i]);
    fscanf(fp,"%d", draw_hist);
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