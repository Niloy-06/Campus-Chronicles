#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "titles.h"
enum character
{
    ZAMAN = 1,
    HASNAT,
    EXIT_ACADEMY
};
void ac_char_choose(Game_state *game_state)
{
    while(1)
    {
        game_title();
        printf("Choose a Character to interact with:\n");
        printf("1. ZAMAN\n");
        printf("2. HASNAT\n");
        printf("3. EXIT CURRENT LOCATION\n");
        int selection;
        printf("Select: ");
        scanf("%d", &selection);
        getchar();
        switch(selection)
        {
        case ZAMAN:
            code_debugging(game_state);
            break;
        case HASNAT:
            cse_lab(game_state);
            break;
        case EXIT_ACADEMY:
            return;
        default:
            printf(BOLD_RED "\nInvalid choice. Try again!\n" RESET);
            continue_btn();
        }

    }
}
void cse_lab(Game_state *game_state)
{
    game_title();
    char cse1[] = "When you arrive at the CSE lab in the Academic Building, you find Hasnat.\nWhen you approach him, he asks, What are you looking for?\n";
    PRINT_STORY(cse1, 50);
    continue_btn();
    int choice;
    int yes_no;
    while(1)
    {
        game_title();
        printf("1. THE AUDITORIUM KEY SET IS MISSING. DO HAVE ANY CLUE ABOUT IT?\n");
        printf("2. THE AUDITORIUM KEY IS MISSING. WE NEED TO FIND IT FAST. CAN YOU HELP US?\n");
        printf("3. Exit CSE LAB\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch(choice)
        {
        case 1:
            printf("Hasnat: That's a big problem.I'm sorry, but I don't have any idea about it.\n");
            Sleep(3000);
            break;
        case 2:
            printf("Hasnat: If you are investigating something, I have made a device which might be helpful to you.\n");
            Sleep(1500);
            printf("Team: What is it?\n");
            Sleep(1000);
            char cse2[]="Hasnat: It is a device that can decipher encrypted message.\nIf you know which direction to shift and how many positions to shift,\nthe device can do it for you. I named it ENIGMA.\nWould you like to take it with you and test it?";
            PRINT_STORY(cse2, 50);
            Sleep(500);
            printf(BOLD_RED "\n\n      [YES]            [NO]      \n\n" RESET);
            printf("Enter 1 for YES or 0 for NO\n");
            scanf("%d", &yes_no);
            getchar();
            if(yes_no == 1 || yes_no == 0)
            {
            if(yes_no == 1)
            {
                game_state->decoder = yes_no;
                printf("YOU HAVE OBTAINED ENIGMA!\n");
                Sleep(1000);
            }
            else
            {
                game_state->decoder = yes_no;
                printf("YOU REFUSED THE ENIGMA!\n");
                Sleep(1000);
            }
            }
            else{
                printf(BOLD_RED "\nInvalid choice. Try again!\n" RESET);
                continue_btn();
            }
            break;
        case 3:
            return;
        default:
            printf(BOLD_RED "\nInvalid choice. Try again!\n" RESET);
            continue_btn();
        }
    }
}
void code_debugging(Game_state *game_state)
{
    char cd[] = "Zaman has been trying to debug a piece of code for a long time. Help him find the bug.\n";
    PRINT_STORY(cd,50);
    continue_btn();
    debug_code();
    game_title();
}
void debug_code()
{
    game_title();
    FILE *file;
    char line[200];
    int line_number = 1;
    int answer;
    int bug_line = 18;

    file = fopen("bug.txt", "r");

    if (file == NULL)
    {
        printf("Unable to open code file!\n");
        return;
    }

    printf("\n");
    printf("===========================================\n");
    printf("              DEBUG THE CODE\n");
    printf("===========================================\n\n");

    /* Display the code with line numbers */
    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%3d | %s", line_number, line);
        line_number++;
    }

    fclose(file);

    printf("\nWhich line contains the bug?\n");
    printf("Enter line number: ");
    scanf("%d", &answer);
    getchar();

    if (answer == bug_line)
    {
        show_center_title("YOU FOUND THE BUG", 1500);
        show_center_title("YOU WILL RECEIVE A CLUE SOON", 1500);
    }
    else
    {
        show_center_title("YOU DID NOT FIND THE BUG",1500);
        show_center_title("YOU WON'T RECEIVE ANY CLUE", 1500);
    }
}
