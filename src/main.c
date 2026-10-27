#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "titles.h"
int main(int argc, char *argv[])
{
    Game_state game_state = {0};
    game_state.game.leaderIndex = -1;

    srand(time(NULL));

    if (argc > 1 && strcmp(argv[1], "skip") == 0)
{
    game_state.pocket_gate_check = 1;
    game_state.cafeteria_check = 1;
    game_state.academic_building_check = 1;
    game_state.padma_pukur_check = 1;
    game_state.it_park_check = 1;

    game_state.game_progress = 70;

    printf("SKIP MODE ENABLED!\n");

    game_menu(&game_state);
}
else
{
    show_center_title("THE CAMPUS CHRONICLES", 3000);
    show_center_title("A MYSTERY UNFOLDS", 2000);
    prologue_opening();
    menu_opening(&game_state);
}

    show_center_title("GAME CLOSED", 3000);
    clear_screen();

    return 0;
}
