#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "titles.h"

enum
{
    thrust =1,
    Toss,
    parry,
    low_guard
};
void finale_initiator(Game_state *game_state)
{
    game_title();
    char k9[] ="You have explored all places and triggered the final location.\nCheck the clues and find the answer to the following question to reach the finale.\nYou have three attempts. Best of luck!\n";
    PRINT_STORY(k9, 50);
    Sleep(1000);
    int option;
    char answer[20];
    char real_answer[] = "SCIENCE BUILDING";
    int attempts = 0;
    while(1)
    {
        game_title();
        printf("1. SEE CLUES\n");
        printf("2. ANSWER THE QUESTION\n");
        printf("Enter Choice:");
        scanf("%d", &option);
        getchar();
        switch(option)
        {
        case 1: clear_screen();
            display_clue();
            continue_btn();
            break;
        case 2:

            if(attempts < 3)
            {
                game_title();
                printf("\nWhere is the key? (write the only the location in broad letters.)\n");
                printf("ENTER ANSWER: ");
                fgets(answer, sizeof(answer), stdin);
                answer[strcspn(answer, "\n")] = '\0';
                if(strcmp(real_answer, answer) == 0)
                {
                    show_center_title("CORRECT ANSWER! TEAM GOES TO FINAL LOCATION.", 3000);
                    conversation(game_state);
                    return;
                }
                else
                {
                    show_center_title("INCORRECT ANSWER! TRY AGAIN.", 2000);
                    attempts++;
                    break;
                }
            }
            else
            {
                show_center_title("NO ATTEMPTS LEFT! THINK ONE MORE TIME BEFORE TRYING.", 1500);
                return;
            }

        }
}
}
void story()
{
    game_title();
    char p_line[]= "The Team Rushes to SCIENCE BUILDING. Inside an abandoned room,\nthey discover something unexpected. What they see next catches them by surprise.\nthey finds their own classmate, MAHMUD, was standing in front of them.\nHe has a digital mini vault in his hand.";
    PRINT_STORY(p_line, 50);
    continue_btn();
}
void conversation(Game_state *game_state)
{
    char a1[]= "MAHMUD: All this time, I rehearsed as the anchor. And now you all just replaced me! I don't accept it.\n";
    char a2[]= "MAHMUD: Since I can't be a part of it, I won't let the function take off!\n";
    char a3[]="Team: Don't be absurd. Give us the key before it's too late!\n";
    char a4[]="MAHMUD: It's in this vault and you shall not have it!\nTake it yourself if you have the courage!\n";
    char a5[]="MAHMUD: What do you think i am doing here?\n";
    char a6[]="Team: So, it was you who stole the key?\n";
    char a7[]="MAHMUD: Yes. It has always been me!\n";
    story();
    int choice;
    while(1)
    {
        printf("1.TEAM: MAHMUD, WHAT ARE YOU DOING HERE?\n");
        printf("2.TEAM: SO IT WAS YOU WHO STOLE THE KEY?\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar();
        if(choice == 1)
        {
            PRINT_STORY(a5, 50);
            Sleep(500);
            PRINT_STORY(a6, 50);
            Sleep(500);
            PRINT_STORY(a7, 50);
            continue_btn();
            break;
        }
        else if(choice == 2)
        {
            PRINT_STORY(a7, 50);
            break;
        }
        else
        {
            printf(BOLD_RED "Invalid Input! Try Again.\n" RESET);
            continue_btn();
        }
    }
    while(1)
    {
        printf("1: WHY DID YOU DO IT?\n");
        printf("2: GIVE US THE KEY BEFORE IT IS TOO LATE!\n");
        printf("Enter your choice: ");

        scanf("%d",&choice);
        getchar();
        if(choice == 1)
        {

            PRINT_STORY(a1,50);
            PRINT_STORY(a2,50);
            continue_btn();

            PRINT_STORY(a3,50);
            PRINT_STORY(a4,50);
            continue_btn();
            show_center_title("THE FINAL SHOWDOWN", 2000);
            show_center_title("TEAM LEADER STARTS THE FIGHT AND SUFFLES EACH ROUND", 3000);
            wrestling_match(game_state);
        }
        else if(choice == 2)
        {
            PRINT_STORY(a4, 50);
            continue_btn();
            show_center_title("THE FINAL SHOWDOWN", 2000);
            show_center_title("TEAM LEADER STARTS THE FIGHT AND SUFFLES IN EACH ROUND", 3000);
            game_title();
            char s[] = "TOSS and THRUST are offensive attacks. they deal damage.\nPARRY and LOW GUARD are defensive move. They don't deal damage.\n";
            char k[] = "PARRY blocks THRUST and LOW GUARD blocks TOSS.\nTOSS consumes double might and deals large damage.\n";
            PRINT_STORY(s, 50);
            Sleep(500);
            PRINT_STORY(k, 50);
            continue_btn();
             wrestling_match(game_state);
        }
        else
        {
            printf(BOLD_RED "Invalid Input! Try Again." RESET);
            continue_btn();
        }

        return;
    }
}
void wrestling_match(Game_state *game_state)
{
    int playerWill= 50;
    int opponentWill= 50;
    int playerMight= 3;
    int opponentMight= 3;
    int round = 1;
    int playerMove, opponentMove;
    int damage;


    while(playerWill > 0 && opponentWill > 0)
    {
        round_start(round);
        game_title();
        printf("========================================\n");
        printf("          THE FINAL SHOWDOWN            \n");
        printf("========================================\n\n");
        printf("           Round %d Begins!\n", round);
        printf("YOUR FIGHTING WILL:       %d\n", playerWill);
        printf("OPPONENT FIGHTING WILL:   %d\n\n", opponentWill);

        printf("YOUR MIGHT:               %d / 3\n", playerMight);
        printf("OPPONENT MIGHT:           %d / 3\n", opponentMight);

        printf("\n----------------------------------------\n");

        printf("\nChoose your move:\n\n");
        printf("1. Thrust\n");
        printf("2. Toss      [Costs 2 Might]\n");
        printf("3. Parry\n");
        printf("4. Low Guard\n");

        printf("\nYour move: ");
        scanf("%d", &playerMove);
        getchar();

        if (playerMove < 1 || playerMove > 4)
        {
            printf(BOLD_RED "\nInvalid move! Try Again\n" RESET);
            continue_btn();
            continue;
        }
          if (playerMove == 2 && playerMight < 2)
        {
            printf("\nYou don't have enough Might to use Toss!\n");
            continue_btn();
            continue;
        }
          if (opponentMight >= 2)
        {
            opponentMove = rand() % 4 + 1;
        }
        else
        {
             opponentMove = rand() % 3 + 1;

            if (opponentMove == 2)
                opponentMove = 1;
        }
        if(playerMove == 2)
        {
            playerMight = playerMight - 2;
        }
        if(opponentMove == 2)
        {
            opponentMight = opponentMight -2;
        }
        if(playerMove == 1)
        {
            playerMight = playerMight - 1;
        }
        if(opponentMove == 1)
        {
            opponentMight = opponentMight - 1;
        }
        game_title();

        printf("========================================\n");
        printf("             ROUND %d                   \n", round);
        printf("========================================\n\n");

        printf("You chose: ");
        switch(playerMove)
        {
        case thrust:
            printf("THRUST\n");
            break;
        case Toss:
            printf("TOSS\n");
            break;
        case parry:
            printf("PARRY\n");
            break;
        case low_guard:
            printf("LOW GUARD\n");
            break;
        }
        printf("The opponent makes his move....\n");
        Sleep(1000);

        if(playerMove == 1)
        {
            if(opponentMove == 1)
            {
                printf("Both try to THRUST, but none gets the upper hand!\n");
                damage = 5;
                playerWill -= damage;
                opponentWill -= damage;
                printf("Both lose %d Fighting Will.\n", damage);
            }
            else if(opponentMove == 2)
            {
                damage = 20;
                playerWill = playerWill - damage;
                printf("Opponent TOSSES you up! THRUST is not effective!\n");
                printf("You lose %d Fighting Will.\n", damage);
            }
            else if(opponentMove == 3)
            {
                printf("Opponent PARRIES your THRUST! No damage dealt.");
            }
            else if(opponentMove == 4)
            {
                printf("Opponent used LOW GUARD, but cannot resist your THRUST!\n");
                damage = 10;
                opponentWill = opponentWill - damage;
                printf("Opponent loses %d Fighting Will.\n", damage);
            }
        }
      else if(playerMove == 2)
        {
            if(opponentMove == 1)
            {
                damage = 20;
                opponentWill = opponentWill - damage;
                printf("You TOSS him up! His THRUST is not effective!\n");
                printf("Opponent loses %d Fighting Will.\n", damage);
            }
            else if(opponentMove == 2)
            {
                printf("Both try to TOSS each other.\n");
                damage = 5;
                playerWill -= damage;
                opponentWill -= damage;
                printf("Both lose %d Fighting Will.\n", damage);
            }
            else if(opponentMove == 3)
            {
                printf("Opponent's PARRY could not resist your TOSS!\n");
                damage = 10;
                opponentWill -= damage;
                printf("Opponent loses %d Fighting Will.\n", damage);
            }
            else if(opponentMove == 4)
            {
                printf("Opponent blocks your TOSS with LOW GUARD!\n   NO damage was done.\n");
            }
        }
        else if(playerMove == 3)
        {
           if(opponentMove == 1)
            {
                printf("You PARRY the opponent's THRUST! NO damage dealt.\n");
            }
            else if(opponentMove == 2)
            {
                printf("Opponent TOSSES you up! PARRY could not block it.\n");
                damage = 10;
                playerWill -= damage;
                printf("You lose %d Fighting Will.\n", damage);
            }
            else if(opponentMove == 3)
            {
                printf("Both try to PARRY!\n");
                damage = 5;
                playerWill -= damage;
                opponentWill -= damage;
                printf("Both lose %d Fighting Will.\n", damage);
            }
            else if(opponentMove == 4)
            {
                printf("PARRY and LOW GUARD are defensive moves.\n      NO damage was done!\n");
            }
        }
        else if(playerMove == 4)
        {
            if(opponentMove == 1)
            {
              printf("You used LOW GUARD, but cannot resist the Opponent's THRUST!\n");
                damage = 10;
                playerWill -= damage;
                printf("You lose %d Fighting Will.\n", damage);
            }
             else if(opponentMove == 3)
            {
                printf("PARRY and LOW GUARD are for defense.\n      NO damage was done!\n");
            }
             else if(opponentMove == 2)
            {
                printf("YOU block the opponent's TOSS with LOW GUARD!\n   NO damage was done.\n");
            }
             else if(opponentMove == 4)
            {
                printf("Both used LOW GUARD!");
                damage = 5;
                playerWill -= damage;
                opponentWill -= damage;
                printf("Both lose %d Fighting Will.\n", damage);
            }
        }
        if (playerMight < 3)
            playerMight++;

        if (opponentMight < 3)
            opponentMight++;

         if (playerWill < 0)
            playerWill = 0;

        if (opponentWill < 0){
            opponentWill = 0;}

            printf("\n----------------------------------------\n");

        printf("YOUR FIGHTING WILL:       %d\n", playerWill);
        printf("OPPONENT FIGHTING WILL:   %d\n", opponentWill);

        printf("\nYOUR MIGHT:               %d / 3\n", playerMight);
        printf("OPPONENT MIGHT:           %d / 3\n", opponentMight);

        if (playerWill > 0 && opponentWill > 0)
        {
            continue_btn();
        }

        round++;
    }
    continue_btn();
    game_title();

    if (playerWill > 0 && opponentWill <= 0)
    {
        show_center_title("YOU WIN!", 1500);
        game_title();
        printf("========================================\n");
        printf("              YOU WIN!                  \n");
        printf("========================================\n\n");

        printf("You catch the opponent off balance...\n");
        printf("and throw him at one corner of the room!\n\n");
        Sleep(1500);
        printf("Mahmud tries to get back up. but he couldn't.\n");
        Sleep(1000);
        printf("MAHMUD: All right! Enough! You win!\n");
        Sleep(1000);
        printf("He finally hands the mini vault over to you.\n");
        Sleep(3000);
        victory_menu(game_state);
        return;

    }
    else if (playerWill <= 0)
    {
        show_center_title("YOU LOSE!", 1500);
        game_title();
        printf("========================================\n");
        printf("              YOU LOSE!                 \n");
        printf("========================================\n\n");

        printf("You lose your balance and fall down.\n\n");
        printf("You failed to obtain the vault from Mahmud.\n");
        printf("Let your other teammate try their luck!\n");
    }
    else
    {
        show_center_title("MATCH DRAW!", 1500);
        game_title();
        printf("========================================\n");
        printf("             MATCH DRAW!                \n");
        printf("========================================\n\n");

        printf("Neither fighter could defeat the other.\n");
        printf("Mahmud refuses to give you the vault.\n");
    }
}

void round_start(int round)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int width;
    int height;
    int text_length;
    int x;
    int y;
    clear_screen();

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    char message[50];
    sprintf(message, "ROUND %d STARTS!", round);
    text_length = strlen(message);
    x = (width - text_length)/2;
    y = height /2;

    COORD position;
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
    printf("%s", message);
    Sleep(2000);
}

