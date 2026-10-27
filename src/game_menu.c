#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "titles.h"

enum main_menu_card
{
    go_to_location = 1,
    Team_manager,
    clue_board,
    inventory,
    instructions,
    save_game,
    back_to_opening
};

void game_menu(Game_state *game_state)
{
    int choice;

    while (1)
    {
        showMap();
        game_state->game_progress = 20 + (game_state->finale_trigger_check * 10);
        if(game_state->finale_trigger_check == 5 && game_state->ending_check == 1)
        {
            game_state->game_progress = 100;
        }
        printf("CURRENT GAME PROGRESSION: %d%%\n", game_state->game_progress);

        printf("1. GO TO LOCATIONS\n");
        printf("2.TEAM MANAGEMENT\n");
        printf("3.CLUE BOARD\n");
        printf("4.INVENTORY\n");
        printf("5.INSTRUCTIONS\n");
        printf("6.SAVE CURRENT GAME\n");
        printf("7.BACK TO LOBBY\n");
        printf("Enter Your Choice:");

        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case go_to_location:

            if(game_state->dead_end == 1)
            {
                show_center_title("What is the point of visiting now? It is already past show-time.", 3000);
                break;
            }
            else{
            printf("Select a Location to Investigate!\n");
            Sleep(1000);
            printf("Remember, anything can be a clue!\n");
            Sleep(1000);
            locationMenu(game_state);
            break;
            }
        case Team_manager:
            show_center_title("ONLY LEADER CAN MANAGE THE TEAM.", 1500);
            team_management(game_state,1);
            break;
        case clue_board:
            show_center_title("CLUE BOARD", 1500);
            clear_screen();
            display_clue();
            continue_btn();
            break;

        case inventory:
            show_center_title("INVENTORY", 1500);
                game_title();
            if(game_state->decoder)
            {

                printf("ENIGMA is stored in your inventory!\nYou can use it in the time of need.\n");
                continue_btn();
            }
            else {
                printf("You don't have anything in your inventory yet!\nTry obtaining something first.\n");
                continue_btn();
            }
            break;

        case instructions:
            show_center_title("INSTRUCTIONS", 1500);
            game_title();

            print_txt_file("instructions.txt");
            continue_btn();
            break;

        case save_game:
            saveGame(game_state);
            show_center_title("GAME SAVED", 2000);
            break;

        case back_to_opening:
            show_center_title("RETURNING TO LOBBY..", 1500);
            Sleep(1000);

            // Return to the function that opened game_menu().
            return;

        default:
            printf(BOLD_RED "invalid choice, try again!" RESET);
            continue_btn();
        }
    }
}
