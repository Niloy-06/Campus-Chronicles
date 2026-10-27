#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "titles.h"

void caesarCipherUpper(char text[], int k, int mode)
{
    k = k % 26;
    if (mode == 0)
    {
        k = -k;
    }
    for (int i = 0; text[i] != '\0'; i++)
    {
        char ch = text[i];
        // Jodi character-ti uppercase letter hoy
        if (ch >= 'A' && ch <= 'Z')
        {
            text[i] = (ch - 'A' + k + 26) % 26 + 'A';
        }
        // Space ba onno punctuation oporibortito thakbe
    }
}
void happy_ending()
{
    game_title();
    char c1[] = "The team open the vault. The key is there!\n The group of young detectives delivers the key to the Cultural Team.\n Everyone shows their gratitude towards you.\n The Grand Show begins with majestic brilliance...\n";
    PRINT_STORY(c1, 50);
    continue_btn();
    show_center_title("THE END" , 2000);
    show_center_title("THE CAMPUS CHRONICLES",2000);
    show_center_title("DEVELOPED BY", 1000);
    show_center_title("ESHRAK HASAN NILOY", 2000);
    show_center_title("ARMAN RAFI", 2000);
    show_center_title("MOBASSHIRA SADIA SAKAL", 2000);
    show_center_title("THANK YOU FOR PLAYING!", 2000);
}
void victory_menu(Game_state *game_state)
{
    game_title();
    char b1[] = "Mahmud snickers...He says: Even if you have it, you will never open it in time.\n";
    char b2[] = "MAHMUD: The password is encrypted. And you have only three attempts!\n";
    char b3[] = "Everyone looks at the vault and sees the encryption [**********]\n";
    char b4[] = "ANALYST: We need a key number to decipher the password\n";
    PRINT_STORY(b1,50);
    Sleep(500);
    PRINT_STORY(b2,50);
    Sleep(500);
    PRINT_STORY(b3,50);
    Sleep(500);
    PRINT_STORY(b4,50);
    continue_btn();
    int choice;
    int attempts = 0;
    char password[20];
    char real_pass[] = "AUDITORIUM";
    char pass_attempt[20];
    while(1)
    {
        game_title();
        printf("1. SEE ENCRYPTED PASSWORD\n");
        printf("2. DEDUCE THE CLUES TO FIND THE KEY(NUMBER)\n");
        printf("3. USE ENIGMA TO CRACK THE PASSWORD\n");
        printf("4. SEE EXTRACTED PASSWORD\n");
        printf("5. ENTER PASSWORD IN THE VAULT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch(choice)
        {
        case 1:
            show_center_title("DXGLWRULXP", 2000);
            break;
        case 2:
            show_center_title("ENTERING CLUE BOX", 2000);
            clear_screen();
            display_clue();
            continue_btn();
        break;
        case 3:
            printf("Enter encrypted password: ");
            scanf("%s", password);
            printf("Enter the key number: ");
            int keyNumber, mode;
            scanf("%d", &keyNumber);
            printf("Press 0 for left shifting, press 1 for right shifting: ");
            scanf("%d", &mode);
            getchar();
            if(game_state->decoder == 1){
            caesarCipherUpper(password, keyNumber, mode);
            printf("The real PASSWORD is: %s\n", password);
            continue_btn();
            break;
            }
            else {
                printf("You should have taken the ENIGMA form CSE lab.\n");
                Sleep(1500);
                break;
            }

        case 4:
            printf("%s\n", password);
            continue_btn();
            break;
        case 5:
            if(attempts < 3){
            printf("ENTER PASSWORD: ");
            scanf("%s", pass_attempt);
            getchar();
            continue_btn();
            if(strcmp(real_pass, pass_attempt) == 0)
            {
                show_center_title("CORRECT PASSWORD! THE VAULT OPENS.", 3000);
                happy_ending();
                if(game_state->ending_check == 0)
                {
                    add_journal_entry("Team found the key in time. The cultural show took place with majestic brilliance.");
                    game_state->ending_check = 1;
                }

                return;
            }
            else
            {
                show_center_title("INCORRECT PASSWORD! TRY AGAIN.", 2000);
                attempts++;
                break;
            }
            }
            else
            {
                show_center_title("NO ATTEMPTS LEFT", 1500);
                show_center_title("THE VAULT IS LOCKED", 1500);
                return;
            }
        default:
            printf(BOLD_RED "\nInvalid Choice. Try again!\n" RESET);
            continue_btn();
        }
    }

}
