#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "titles.h"

void gate_char_choose(Game_state *game_state)
{
    while(1)
    {
        game_title();
        printf("Choose a Character to interact with:\n");
        printf("1. GATE KEEPER\n");
        printf("2. MIRAZ\n");

        printf("3. EXIT CURRENT LOCATION\n");
        int selection;
        printf("Select: ");
        scanf("%d", &selection);
        getchar();
        switch(selection)
        {
        case 1:
           ques_ans(game_state);
            break;

        case 2:
            miraz_dialogue(game_state);
            break;
        case 3:
            return;
        default:
            printf(BOLD_RED "\nInvalid choice. Try again!\n" RESET);
            continue_btn();
        }
    }
}
void ques_ans(Game_state *game_state)
{
    char ch[] = "Team asks a few question to the gate keeper, to know if the thief has left the campus.\n";
    PRINT_STORY(ch, 50);
    Sleep(1000);
    int choice;
    while(1)
    {
        game_title();
        printf("1. WHEN DID YOUR SHIFT BEGIN?\n");
        printf("2. DID YOU SEE ANYONE WITH A BIG SET OF KEYS?\n");
        printf("3. DID YOU SEE ANYONE NEW AND SUSPICIOUS?\n");
        printf("4. DON'T YOU GET BORED BY SITTING FOR THIS LONG?\n");
        printf("5. THANK YOU FOR ANSWERING.\n");
        printf("Enter your question: ");
        scanf("%d", &choice);
        getchar();
        switch(choice)
        {
        case 1:
            printf("GATE KEEPER: SINCE 8:00 AM.\n");
            Sleep(2000);
            break;
        case 2:
             printf("GATE KEEPER: NO I HAVEN'T. I WOULD'VE DEFINITELY NOTICED IF SOMEONE DID SO\n");
             Sleep(2000);
            break;
        case 3:
             printf("GATE KEEPER: NO. SUCH BIG SET OF KEYS WOULD SURELY MAKE NOISE WHEN PASSING THROUGH HERE\n");
             Sleep(2000);
            break;
        case 4:
             printf("GATE KEEPER: IT IS MY JOB. I AM ACCUSTOMED TO IT.\n");
             Sleep(2000);
            break;
        case 5: printf("GATE KEEPER: YOU ARE WELCOME\n");
        Sleep(2000);
            return;
            default:
                printf(BOLD_RED "\nInvalid choice. Try again!\n" RESET);
            continue_btn();
        }
    }
}
void miraz_dialogue(Game_state *game_state)
{
    game_title();
    char s1[] = "When you are at the pocket gate, you saw your good friend MIRAZ,\nentering the campus with a newspaper in his hand.\nHe looks fully concentrated into something.\n";
    char s2[] = "You grab him and pull him to a side. You snatch the paper from his hand.\n";
    char s3[] = "MIRAZ: What? Just let me finish the Sudoku first, then we will talk.\n"
    PRINT_STORY(s1, 50);
    PRINT_STORY(s2, 50);
    PRINT_STORY(s3, 50);
    continue_btn();
    show_center_title("SUDOKU CHALLENGE", 1500);
    sudoku_game();
    char s4[] = "Team tells Miraz about the current situation.\n";
    char s5[] = "MIRAZ: Don't worry, There is nothing that I cannot find about.\n You guys continue to investigate, i will inform you if I find any clue about it\n";
    PRINT_STORY(s4, 50);
    PRINT_STORY(s5, 50);
    continue_btn();
    show_center_title("CONTINUE YOUR INVESTIGATION", 2000);
    show_center_title("YOU WILL SEE NEW CLUE IN CLUE BOARD...", 2000);
    show_center_title("...ONCE MIRAZ FINDS THEM", 2000);
}

void sudoku_game()
{
    game_title();
    int *board;
    int *answer;
    int correct[8] = {2, 3, 3, 2, 2, 3, 3, 2};
    int i;
    int correct_count = 0;
    board = (int *)calloc(16, sizeof(int));
    /* Dynamically allocate space for player's answers */
    answer = (int *)calloc(8, sizeof(int));

    if (board == NULL || answer == NULL)
    {
        printf("Memory allocation failed!\n");
        free(board);
        free(answer);
        return;
    }
    /* Fixed numbers of the Sudoku */
    board[0]  = 1;
    board[3]  = 4;
    board[5]  = 4;
    board[6]  = 1;
    board[9]  = 1;
    board[10] = 4;
    board[12] = 4;
    board[15] = 1;
    printf("\n");
    printf("===========================================\n");
    printf("              SUDOKU PUZZLE\n");
    printf("===========================================\n\n");
    /* Display the Sudoku board */
    for (i = 0; i < 16; i++)
    {
        if (i % 4 == 0)
            printf("\n");
        if (board[i] == 0)
            printf("|   ");
        else
            printf("| %d ", board[i]);
        if (i % 4 == 3)
            printf("|");
    }
    printf("\n\n");
    printf("Fill the empty cells using numbers 1-4.\n");
    printf("Enter the numbers from left to right, top to bottom.\n\n");

    for (i = 0; i < 8; i++)
    {
        printf("Empty cell %d: ", i + 1);
        scanf("%d", &answer[i]);
    }
    for (i = 0; i < 8; i++)
    {
        if (answer[i] == correct[i])
        {
            correct_count++;
        }
    }
    if (correct_count == 8)
    {
        show_center_title("SUDOKU SOLVED!", 2000);
        game_title();
        printf("          SUDOKU SOLVED!\n");
        printf("          All answers are correct.\n");
    }
    else
    {
        show_center_title("WRONG SOLUTION!", 2000);
        game_title();
        printf("          WRONG SOLUTION!\n");
        printf("          Correct answers: %d/8\n", correct_count);
    }
    free(board);
    free(answer);
    getchar();
    continue_btn();
}
