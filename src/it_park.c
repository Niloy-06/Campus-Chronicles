#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "titles.h"

void park_char_choose(Game_state *game_state)
{
    while(1)
    {
        game_title();
        printf("Choose a Character to interact with:\n");
        printf("1. MAHMUD\n");
        printf("2. PIROZ\n");

        printf("3. EXIT CURRENT LOCATION\n");
        int selection;
        printf("Select: ");
        scanf("%d", &selection);
        getchar();
        switch(selection)
        {
        case 1:mahmud_riddle(game_state);
            break;

        case 2:
            piroz_deadend(game_state);
           if(game_state->dead_end == 1) return;
           else break;
        case 3:
            return;
        default:
            printf(BOLD_RED "\nInvalid choice. Try again!\n" RESET);
            continue_btn();
        }
    }
}
void piroz_deadend(Game_state *game_state)
{
    game_title();
    char p1[] = "When team reaches IT PARK, they meet Piroz at the entrance.\nHe looks at you from afar and hides a silver box into his backpack.\n";
    char p2[] = "The team of investigators approaches him hastily.\nTeam: Have you seen anyone acting suspicious nearby?\n";
    char p3[] = "PIROZ: what happened? Why are you three in such a rush?\n";
    char p4[] = "The auditorium key is missing. Someone must have stolen it.\n";
    char p5[] = "Piroz thinks for a moment and smiles...He looks around, then smirks again.\n";
    char p6[] ="PIROZ: You are in luck! I did see someone running toward the construction area with a set of keys in his hand.\n It must be the thief who wants to sabotage our program tonight.\nYou must find him. I have faith in you guys!\n";
    PRINT_STORY(p1, 50);
    PRINT_STORY(p2, 50);
    PRINT_STORY(p3, 50);
    PRINT_STORY(p4, 50);
    PRINT_STORY(p5, 50);
    PRINT_STORY(p6, 50);
    continue_btn();
    char p7[] = "Would you go beyond the IT building and venture into the construction area?";
    PRINT_STORY(p7, 40);
    int yes_no;
    int no_yes;
    while(1)
            {
                printf(BOLD_RED "\n\n      [YES]            [NO]      \n" RESET);
                printf(BOLD_RED "       [1]            [2]         \n\n" RESET);
                printf("Enter your choice: ");
                scanf("%d", &yes_no);
                getchar();
                if(yes_no == 1)
                {
                    printf("ARE YOU SURE ABOUT THIS?");
                    printf(BOLD_RED "\n\n      [YES]            [NO]      \n" RESET);
                    printf(BOLD_RED "       [1]            [2]         \n\n" RESET);
                    printf("Enter your choice: ");
                    scanf("%d", &no_yes);
                    getchar();
                    if(no_yes == 1)
                    {
                        show_center_title("TEAM GOES INTO THE CONSTRUCTION SITE", 2500);
                        show_center_title("THE THREE OF YOU KEEP SEARCHING THE AREA", 2500);
                        show_center_title("THEN YOU THREE SEARCH SEPARATELY", 2500);
                        show_center_title("THE SUN FINALLY SETS", 2500);
                        show_center_title("THE SHOWTIME IS HERE", 2500);
                        show_center_title("YET THE KEY WAS NOT FOUND", 2500);
                        show_center_title("YOU FAILED TO FIND THE KEY", 2500);
                        show_center_title("GAME OVER", 3000);
                        if (game_state->dead_end == 0)
                        {
                          add_journal_entry("YOU SHOULD NOT HAVE TRUSTED PIROZ!");
                          game_state->dead_end = 1;
                        }
                        return;
                    }
                    else if(no_yes == 2)
                    {
                        show_center_title("YOU CHOOSE NOT TO TRUST HIM", 1500);
                        break;
                    }
                    else {
                    printf(BOLD_RED "\nInvalid choice. Try again!\n" RESET);
                continue_btn();
                }

                }
                else if(yes_no == 2)
                {
                show_center_title("YOU CHOOSE NOT TO TRUST HIM", 1500);
                  break;
                }
                else {
                    printf(BOLD_RED "\nInvalid choice. Try again!\n" RESET);
                continue_btn();
                }
            }
}
void mahmud_riddle(Game_state *game_state)
{
    char r1[] = "When the team reaches the road leading to IT PARK, they meet MAHMUD.\n";
    char r2[] = "Team: Where are you going, Mahmud? Mahmud staggers...\nMAHMUD: Nowhere, No, I mean I was going for the auditorium.\nThe show is starting soon.\n";
    char r3[] = "Team: Are you still sad about anchor-ship? We tried our best to give you the position.\nYou were our best choice, but there are some things that are beyond our control.\n";
    char r4[] = "MAHMUD: I know. You don't have to feel sorry about it.\nBy the way, where are you three going?\n";
    char r5[] = "Team: The auditorium key is missing. We need to find it soon.\n";
    char r6[] = "MAHMUD: OH! That is a big problem. Then you should be on your way, I won't disturb you guys.\n";
    char r7[] = "Team nods and starts towards IT PARK again.\nMAHMUD: I wish I could help you too.\nBest of luck! I hope you find it soon.\n";
    PRINT_STORY(r1, 60);
    PRINT_STORY(r2, 60);
    continue_btn();
    PRINT_STORY(r3, 60);
    PRINT_STORY(r4, 60);
    continue_btn();
    PRINT_STORY(r5, 60);
    PRINT_STORY(r6, 60);
    PRINT_STORY(r7, 60);
    continue_btn();
    show_center_title("YOU REACH NEAR THE IT BUILDING", 1000);
}
