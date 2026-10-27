#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "titles.h"

int saveGame(Game_state *game_state)
{
    FILE *file = fopen("campus_save.dat", "wb");

    if (file == NULL)
    {
        printf("Unable to create save file!\n");
        return 0;
    }

    fwrite(game_state, sizeof(Game_state), 1, file);

    fclose(file);

    printf("Game saved successfully!\n");
    return 1;
}

int loadGame(Game_state *game_state)
{
    FILE *file = fopen("campus_save.dat", "rb");

    if (file == NULL)
    {
        printf("No saved game found!\n");
        return 0;
    }

    fread(game_state, sizeof(Game_state), 1, file);

    fclose(file);

    printf("Game loaded successfully!\n");
    return 1;
}
