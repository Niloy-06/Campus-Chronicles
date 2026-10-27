#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "titles.h"

void cafe_char_choose(Game_state *game_state)
{
    while(1)
    {
        game_title();
        printf("Choose a Character to interact with:\n");
        printf("1. KABIR\n");
        printf("2. NAEEM\n");
        printf("3. EXIT CURRENT LOCATION\n");
        int selection;
        printf("Select: ");
        scanf("%d", &selection);
        getchar();
        switch(selection)
        {
        case 1:
            kabir_scrabble(game_state);
            break;
        case 2:
            naeem_riddle(game_state);
            break;
        case 3:
            return;
        default:
            printf(BOLD_RED "\nInvalid choice. Try again!\n" RESET);
            continue_btn();
        }

    }
}

void naeem_riddle(Game_state *game_state)
{
    char a1[] = "Naeem was sitting at a corner table, solving some discrete math problems.\nHe see you and calls you over. The team approaches him.\n";
    char a2[] = "NAEEM: I heard you three are looking for the missing key.\n help me with this problem and i might give you some information about it.\n";
    PRINT_STORY(a1, 50);
    Sleep(500);
    PRINT_STORY(a2, 50);
    Sleep(500);
    continue_btn();
    int choice;
    while(1)
    {
    printf("1. I DO NOT HAVE TIME FOR THIS!\n");
    printf("2. LETS DO IT\n");
    printf("ENTER YOUR DECISION:");
    scanf("%d", &choice);
    getchar();
    switch(choice)
    {
         case 1:

            return;
        case 2:
            threeDoorsRiddle(game_state);
            return;
        default:
            printf(BOLD_RED "\nInvalid location. Try again!\n" RESET);
            continue_btn();
    }
    }
 }

void threeDoorsRiddle(Game_state *game_state)
{
     int choice;
     int attempts = 0;
    while(1)
    {
    game_title();
    printf("\n===========================================\n");
    printf("              THE THREE DOORS\n");
    printf("===========================================\n\n");

    printf("Three students are standing beside three doors.\n\n");

    printf("Student A: \"The key is behind Door 1.\"\n");
    printf("Student B: \"The key is not behind Door 1.\"\n");
    printf("Student C: \"The key is not behind Door 3.\"\n\n");

    printf("You are told that EXACTLY ONE student is lying.\n\n");

    printf("Which door contains the key?\n\n");

    printf("[1] Door 1\n");
    printf("[2] Door 2\n");
    printf("[3] Door 3\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    getchar();
   if(attempts <= 3){
    if (choice == 2)
    {
        show_center_title("CORRECT ANSWER", 1500);
        printf("\nCorrect!\n");
        printf("The key is behind Door 2.\n\n");

        printf("A: FALSE\n");
        printf("B: TRUE\n");
        printf("C: TRUE\n\n");

        printf("Exactly one student is lying.\n");
        printf("The team has solved the puzzle!\nNaeem tells you something. You can see it from clue board.\n");

        return;
    }
    else if (choice == 1)
    {
        show_center_title("WRONG ANSWER", 1500);
        printf("\nWrong answer!\n");
        printf("If the key were behind Door 1:\n\n");

        printf("A: TRUE\n");
        printf("B: FALSE\n");
        printf("C: TRUE\n\n");
        attempts++;
        printf("That gives TWO truthful students, not exactly one liar.\n");
    }
    else if (choice == 3)
    {
        show_center_title("WRONG ANSWER", 1500);
        printf("\nWrong answer!\n");
        printf("If the key were behind Door 3:\n\n");
        attempts++;
        printf("A: FALSE\n");
        printf("B: TRUE\n");
        printf("C: FALSE\n\n");

        printf("That gives TWO lying students.\n");
    }
    else
    {
        printf(BOLD_RED "\nInvalid choice! No attempts consumed.\n" RESET);
        continue_btn();
    }
   }
   else
   {
                show_center_title("NO ATTEMPTS LEFT", 1500);
                show_center_title("THE VAULT IS LOCKED", 1500);
                return;
   }
    }
    Sleep(2000);
}
void kabir_scrabble(Game_state *game_state)
{
    int yes_no;
    char a3[] = "Your team finds Kabir looking for more people to play JUMBLE WORDS. He waves at you.\n";
    char a4[] = "KABIR: Care to join a round of JUMBLE WORDS with me?\n";
        PRINT_STORY(a3, 50);
        PRINT_STORY(a4, 50);
        Sleep(500);

            while(1)
            {
                 printf(BOLD_RED "\n\n      [YES]            [NO]      \n\n" RESET);
            printf("Enter 1 for YES or 0 for NO\n");
            scanf("%d", &yes_no);
            getchar();
                if(yes_no == 1)
                {
                    scrabble_game(game_state);
                    return;
                }
                else if(yes_no == 0)
                {
                    return;
                }
                else {
                    printf(BOLD_RED "\nInvalid choice. Try again!\n" RESET);
                continue_btn();
                }
            }
}
void scrabble_game(Game_state *game_state)
{
    char let_p1[] = "CINSCEE";
    char p1_try[20];
    char p1_word[] = "SCIENCE";
    char let_p2[] = "ALEFIN";
    char p2_try[20];
    char p2_word[] = "FINALE";
    char let_p3[] = "GNIDBULI";
    char p3_try[20];
    char p3_word[] = "BUILDING";
    char a5[] = "Kabir shakes the alphabets pouch and randomly gives all of you letters.\nYou need to make a meaningful word using those letters.\nEnter your answer in uppercase.\n";
    PRINT_STORY(a5, 50);
    continue_btn();
    game_title();
    printf("%s, your turn:\n", game_state->game.players[0].name);
    printf("YOUR LETTERS: %s\n", let_p1);
    printf("MAKE WORD: ");
    scanf("%s", p1_try);
    if(strcmp(p1_try, p1_word)== 0)
    {
        show_center_title("RIGHT ANSWER", 1000);
    }
    else
    {
        show_center_title("WRONG ANSWER", 1000);
    }
    game_title();
    printf("%s, your turn:\n", game_state->game.players[1].name);
    printf("YOUR LETTERS: %s\n", let_p2);
    printf("MAKE WORD: ");
    scanf("%s", p2_try);
    if(strcmp(p2_try, p2_word)== 0)
    {
        show_center_title("RIGHT ANSWER", 1000);
    }
    else
    {
        show_center_title("WRONG ANSWER", 1000);
    }
    game_title();
    printf("%s, your turn:\n", game_state->game.players[2].name);
    printf("YOUR LETTERS: %s\n", let_p3);
    printf("MAKE WORD: ");
    scanf("%s", p3_try);
    getchar();
    if(strcmp(p3_word, p3_word)== 0)
    {
        show_center_title("RIGHT ANSWER", 1000);
    }
    else
    {
        show_center_title("WRONG ANSWER", 1000);
    }
    game_title();
    printf("A new clue has been found!\n");
    continue_btn();
}
