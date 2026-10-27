#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "titles.h"

void padma_char_choose(Game_state *game_state)
{
    while(1)
    {
        game_title();
        printf("Choose a Character to interact with:\n");
        printf("1. JULKARNINE\n");
        printf("2. AHMED\n");
        printf("3. EXIT CURRENT LOCATION\n");
        int selection;
        printf("Select: ");
        scanf("%d", &selection);
        getchar();
        switch(selection)
        {
        case 1:
            julkarnine_gk(game_state);
            break;
        case 2:
            ahmed_iq(game_state);
            break;
        case 3:
            return;
        default:
            printf(BOLD_RED "\nInvalid choice. Try again!\n" RESET);
            continue_btn();
        }
    }
}
void julkarnine_gk(Game_state *game_state)
{
    game_title();
    char b1[] = "Team finds JULKARNINE and AHMED discussing something near the PADMA PUKUR. You interrupt them.\n";
    PRINT_STORY(b1, 50);
    Sleep(1000);
    char c1[] = "JULKARNINE: we were talking about general knowledge and IQ. It is good that you are here.\n";
    char c2[] = "JULKARNINE: why don't the three of you answer my three GK question?\n";
    PRINT_STORY(c1, 50);
    Sleep(500);
    PRINT_STORY(c2, 50);
    Sleep(500);
    int choice;
    while(1)
    {
    printf("1. SORRY BUT WE ARE IN A RUSH.\n");
    printf("2. SURE, WHY NOT!\n");
    printf("ENTER YOUR DECISION:");
    scanf("%d", &choice);
    getchar();
    switch(choice)
    {
         case 1:
                char b2[] = "Team : Sorry, we are in a rush.\nWe have been looking for the missing key of the auditorium.\nDo you know anything about it?\n";
                PRINT_STORY(b2, 50);
                char b3[] = "JULKARNINE: it is a bit odd that something like that happened. i indeed saw some abnormalities in this premises.\n";
                PRINT_STORY(b3, 50);
                continue_btn();
            return;
        case 2:
            show_center_title("ONLY THE FIRST ANSWER COUNTS", 1500);
            gk_qna(game_state);
            return;
        default:
            printf(BOLD_RED "\nInvalid choice. Try again!\n" RESET);
            continue_btn();
    }
    }

}
void gk_qna(Game_state *game_state)
{
    int score =0;
    game_title();
    int yes_no;
    char gk1[] = "JULKARNINE: The Padma Pukur looks quite beautiful today! Isn't LOTUS our national flower?\n";
    PRINT_STORY(gk1, 30);

            while(1)
            {
                printf(BOLD_RED "\n\n      [YES]            [NO]      \n\n" RESET);
            printf("Enter 1 for YES or 0 for NO\n");
            scanf("%d", &yes_no);
            getchar();
                if(yes_no == 1)
                {
                    show_center_title("WRONG ANSWER. OUR NATIONAL FLOWER IS WHITE WATER LILY", 2000);
                    break;
                }
                else if(yes_no == 0)
                {
                    show_center_title("RIGHT ANSWER. OUR NATIONAL FLOWER IS WHITE WATER LILY", 2000);
                    score++;
                  break;
                }
                else {
                    printf(BOLD_RED "\nInvalid choice. Try again!\n" RESET);
                continue_btn();
                }
            }
             int sultan;
    while(1)
    {
      game_title();
    char gk2[] = "JULKARNINE: Who founded independent BENGAL SULTANATE from DELHI SULTANATE?\n";
    PRINT_STORY(gk2, 30);

        printf("1. SHAMSUDDIN ILYAS SHAH\n");
        printf("1. FAKHRUDDIN MUBARAK SHAH\n");
        printf("1. FIRUZ SHAH TUGHLUQ\n");
        printf("Make your choice:");
        scanf("%d", &sultan);
        getchar();
        switch(sultan)
        {
            case 1: show_center_title("CORRECT ANSWER", 1000);
            score++;
            break;
            case 2: show_center_title("WRONG ANSWER", 1000);
            break;
            case 3: show_center_title("WRONG ANSWER", 1000);
            break;
            default:printf(BOLD_RED "\nInvalid choice. Try again!\n" RESET);
                continue_btn();
        }
if(sultan == 1) break;
    }
    game_title();
    char gk3[] ="JULKARNINE: What is the present name of CONSTANTINOPOLE?\n";
    PRINT_STORY(gk3, 30);
    while(1)
            {
                printf(BOLD_RED "\n\n      [ANATOLIA]            [ISTANBUL]      \n" RESET);
                printf(BOLD_RED "            [1]               [2]         \n\n" RESET);
                printf("Enter your choice: ");
            scanf("%d", &yes_no);
            getchar();
                if(yes_no == 1)
                {
                    show_center_title("WRONG ANSWER. IT IS ISTANBUL", 2000);
                    break;
                }
                else if(yes_no == 2)
                {
                    show_center_title("RIGHT ANSWER. IT IS ISTANBUL", 2000);
                    score++;
                  break;
                }
                else {
                    printf(BOLD_RED "\nInvalid choice. Try again!\n" RESET);
                continue_btn();
                }
            }
    game_title();
    printf("Your team scored %d/3\n", score);
    continue_btn();
     char b2[] = "Team : Sorry, we are in a rush.\nWe have been looking for the missing key of the auditorium.\nDo you know anything about it?\n";
                PRINT_STORY(b2, 50);
                char b3[] = "JULKARNINE: it is a bit odd that something like that happened. i indeed saw some abnormalities in this premises.\n";
                PRINT_STORY(b3, 50);
                continue_btn();
}
void ahmed_iq(Game_state *game_state)
{
    game_title();
    char b1[]="AHMED: Julkarnine prefers Gk and i prefer IQ. would you like to give it a go?\n";

    PRINT_STORY(b1, 50);
    Sleep(1000);
    int choice;
    while(1)
    {
    printf("1. SORRY BUT WE ARE IN A RUSH.\n");
    printf("2. SURE, WHY NOT!\n");
    printf("ENTER YOUR DECISION:");
    scanf("%d", &choice);
    getchar();
    switch(choice)
    {
         case 1:
                char b2[] = "Team : Sorry, we are in a rush.\nWe have been looking for the missing key of the auditorium.\nDo you know anything about it?\n";
                PRINT_STORY(b2, 50);
                char b3[] = "AHMED: You are in the right direction.You are three in number.\n That number is quite popular these days.\n";
                PRINT_STORY(b3, 50);
                continue_btn();
            return;
        case 2:
            show_center_title("ONLY THE FIRST ANSWER COUNTS", 1500);
            iq_qna(game_state);
            return;
        default:
            printf(BOLD_RED "\nInvalid choice. Try again!\n" RESET);
            continue_btn();
    }
    }
}

void iq_qna(Game_state *game_state)
{
 int score =0;
 int answer_one = 0;
    game_title();
    char iq1[] ="AHMED: A father divides 800tk between his two sons.\nThe elder son gets 100tk more than the younger one.\nHow much does the younger sibling get?\n" ;
    PRINT_STORY(iq1, 30);
    printf("Your Answer: ");
    scanf("%d", &answer_one);
    getchar();
    if(answer_one == 350)
    {
        show_center_title("CORRECT ANSWER",1000);
        score++;
    }
    else
    {
        show_center_title("INCORRECT ANSWER",1000);
    }
    game_title();
    int answer_two = 0;
    char iq2[] = "AHMED: what is the next number of the series: 2, 6, 12, 20, 30, ?\n";
    PRINT_STORY(iq2, 30);
    printf("Your Answer: ");
    scanf("%d", &answer_two);
    getchar();
    if(answer_two == 42)
    {
        show_center_title("CORRECT ANSWER", 1000);
        score++;
    }
    else
    {
        show_center_title("INCORRECT ANSWER", 1000);
    }
    game_title();
    int answer_three = 0;
    while(1){
    char iq3[] = "FIND THE RELATION -> BOOK : READING :: FORK : ?\n";
    char iq3_1[] = "[1] Writing\n[2] Eating\n[3] Cooking\n[4] Cutting\n";
    PRINT_STORY(iq3, 30);
    PRINT_STORY(iq3_1, 30);
    printf("Your Answer: ");
    scanf("%d", &answer_three);
    getchar();
    if(answer_three == 2)
    {
        show_center_title("CORRECT ANSWER",1000);
        score++;
        break;
    }
    else
    {
        show_center_title("INCORRECT ANSWER", 1000);
        break;
    }
    }
    game_title();
    printf("Your team scored %d/3\n", score);
    continue_btn();
    char b2[] = "Team : Sorry, we are in a rush.\nWe have been looking for the missing key of the auditorium.\nDo you know anything about it?\n";
                PRINT_STORY(b2, 50);
                char b3[] = "AHMED: You are in the right direction.You are three in number.\n That number is quite popular these days.\n";
                PRINT_STORY(b3, 50);
                continue_btn();
}
