#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "titles.h"

enum menu_card_lobby
{
    new_game = 1,
    load_game,
    detectives_journal,
    About_game,
    back_to_prologue,
    Exit
};
enum about_game_insider
{
    game_overview = 1,
    game_feature,
    project_information,
    developers_credits,
    back_to_lobby
};
void starting_timer()
{
    for (int i = 3; i > 0; i--)
    {
        game_title();
        printf("Starting New Game in: [%d]\n", i);
        Sleep(1000);
    }

    game_title();
    printf("New Game initialized Successfully!");
    continue_btn();
}

void closing_timer()
{
    for (int i = 3; i > 0; i--)
    {
        game_title();
        printf("Exiting Game in: [%d]\n", i);
        Sleep(1000);
    }

    game_title();
    printf("Game closed Successfully!");
}
void reset_game_state(Game_state *game_state)
{
    *game_state = (Game_state){0};

    game_state->game.leaderIndex = -1;
}

void menu_opening(Game_state *game_state)
{
    int choose;

    while (1)
    {
        game_title();

        printf("1. START NEW GAME\n");
        printf("2. LOAD AND CONTINUE\n");
        printf("3. DETECTIVE'S JOURNAL\n");
        printf("4. ABOUT GAME\n");
        printf("5. BACK TO PROLOGUE\n");
        printf("6. EXIT GAME\n");
        printf("Enter Your Choice:");

        scanf("%d", &choose);
        getchar();

        switch (choose)
        {
        case new_game:
            starting_timer();
            clear_journal();
            clear_clue();
            add_journal_entry("The auditorium key is missing. It has to be found for the show to take place.");
            show_center_title("REGISTER YOUR TEAM BEFORE STARTING THE GAME", 2000);
            reset_game_state(game_state);
            team_management(game_state,0);

            break;

        case load_game:
            if(loadGame(game_state))
            {
                show_center_title("WELCOME BACK INVESTIGATORS", 2500);
                game_menu(game_state);
            }
            else
            {
                continue_btn();
            }
            break;

        case detectives_journal:
            show_center_title("DETECTIVE'S JOURNAL", 2000);
            display_journal();
            continue_btn();
            break;

        case About_game:
            show_center_title("GAME AND DEVELOPER INFORMATION", 1000);
            about_dev();
            break;

        case back_to_prologue:
            prologue();
            break;

        case Exit:
            closing_timer();
            return;

        default:
            printf(BOLD_RED "Wrong Input, Try Again!" RESET);
            continue_btn();
        }
    }
}

void print_txt_file(const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Could not open file: %s\n", filename);
        return;
    }

    char line[1024];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);

    }

    fclose(file);
}

void about_dev()
{
    int choice;
    while(1)
    {
        game_title();
        printf("1. GAME OVERVIEW\n");
        printf("2. GAME FEATURE\n");
        printf("3. PROJECT INFORMATION\n");
        printf("4. DEVELOPERS AND CREDITS\n");
        printf("5. BACK TO LOBBY\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch(choice)
        {
            case game_overview:
                clear_screen();
                print_txt_file("game_overview.txt");
                continue_btn();
                break;
            case game_feature:
                clear_screen();
                print_txt_file("game_feature.txt");
                continue_btn();
                break;
            case project_information:
                clear_screen();
                print_txt_file("project_info.txt");
                continue_btn();
                break;
            case developers_credits:
                clear_screen();
                print_txt_file("dev_credit.txt");
                continue_btn();
                break;
            case back_to_lobby:
                return;
            default:
                printf(BOLD_RED "Wrong Input, Try Again!" RESET);
                continue_btn();
        }
    }
}
