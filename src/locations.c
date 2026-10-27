#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "titles.h"


void showMap()
{
    game_title();

    printf("\n\n");
    printf("=============================================\n");
    printf("                KUET CAMPUS MAP\n");
    printf("=============================================\n\n");

    printf("                 [1]POCKET GATE\n");
    printf("                       |\n");
    printf("                       |\n");
    printf(" [2] CAFETERIA ---- [3] ACADEMIC BUILDING\n");
    printf("                       |\n");
    printf("                       |\n");
    printf("        [4] PADMA PUKUR ---- [5] IT PARK\n");

    printf("\n=============================================\n");
}

void locationMenu(Game_state *game_state)
{
    int choice;

    while (1)
    {
        showMap();
        game_state->finale_trigger_check = game_state->pocket_gate_check + game_state->cafeteria_check + game_state->academic_building_check + game_state->padma_pukur_check + game_state->it_park_check;
        if(game_state->finale_trigger_check == 5)
        {
            char k2[] = "You have visited all locations. \nWould you like to proceed now?";
            PRINT_STORY(k2, 50);
            Sleep(500);
            printf(BOLD_RED "\n\n      [YES]            [NO]      \n\n" RESET);
            printf("Enter 1 to proceed or 0 to return to game menu.\n");
            int yesORno;
            scanf("%d", &yesORno);
            getchar();
            if(yesORno == 1)
            {
                if(game_state->fin_init_check == 0)
                {
                    add_clue_entry("MIRAZ: D SHIFTS LEFT TO BE A.");
                add_clue_entry("TWO WORDS MAKE THE ANSWER.");
                game_state->fin_init_check = 1;
                }

                finale_initiator(game_state);
                return;
            }
            else if(yesORno == 0)
            {
                return;
            }
            else
            {
                printf(BOLD_RED "\nInvalid input. Try again!\n" RESET);
                continue_btn();
            }

        }
        else
        {
            for(int i =0; i < 5; i++)
            {
                if(game_state->finale_trigger_check == i)
                {
                    printf("LOCATION VISITED : %d / 5\n", game_state->finale_trigger_check);
                }
            }
            printf("\nCHOOSE YOUR DESTINATION:\n");
            if(game_state->pocket_gate_check == 1)
            {
                printf("1. POCKET GATE       (VISITED)\n");
            }
            else
            {
                printf("1. POCKET GATE\n");
            }
            if(game_state->cafeteria_check == 1)
            {
                printf("2. CAFETERIA         (VISITED)\n");
            }
            else
            {
                printf("2. CAFETERIA\n");
            }

            if(game_state->academic_building_check == 1)
            {
                printf("3. ACADEMIC BUILDING (VISITED)\n");
            }
            else
            {
                printf("3. ACADEMIC BUILDING\n");
            }
            if(game_state->padma_pukur_check == 1)
            {
                printf("4. PADMA PUKUR       (VISITED)\n");
            }
            else
            {
                printf("4. PADMA PUKUR\n");
            }
            if(game_state->it_park_check == 1)
            {
                printf("5. IT PARK           (VISITED)\n");
            }
            else
            {
                printf("5. IT PARK\n");
            }
            printf("6. EXIT TO MENU\n");
            printf("\nCHOICE: ");

            scanf("%d", &choice);
            getchar();

            switch (choice)
            {
            case 1:
                show_center_title("TEAM TRAVELS TO POCKET GATE",1000);
                gate_char_choose(game_state);
                if (game_state->pocket_gate_check == 0)
                {
                    add_clue_entry("THE THIEF AND THE KEY ARE WITHIN THE CAMPUS. THE CLOCK IS TICKING!");
                    add_journal_entry("The team went to pocket gate. There, they got promise from Miraz that he will help.");
                    game_state->pocket_gate_check = 1;
                }
                break;

            case 2:
                show_center_title("TEAM TRAVELS TO CAFETERIA",1000);
                cafe_char_choose(game_state);
               if (game_state->cafeteria_check == 0)
                {
                    add_clue_entry("NAEEM: JEALOUSY IS A DANGEROUS THING! SOMETIMES IT LEADS PEOPLE TO DO UNIMAGINABLE THINGS.\nKABIR: THESE ARE NOT MERE JUMBLE WORDS. MAYBE A PLACE OF GREAT IMPORTANCE.");
                    add_journal_entry("The team went to cafeteria where they met with Naeem and Kabir.\n");
                    game_state->cafeteria_check = 1;
                }
                break;

            case 3:
                show_center_title("TEAM TRAVELS TO ACADEMIC BUILDING",1000);
                ac_char_choose(game_state);
           if (game_state->academic_building_check == 0)
                {
                    add_journal_entry("After visiting the academic building, a decoder can be obtained from Hasnat.");

                    game_state->academic_building_check = 1;
                }
                break;

            case 4:
                show_center_title("TEAM TRAVELS TO PADMA PUKUR",1000);
                padma_char_choose(game_state);
              if (game_state->padma_pukur_check == 0)
                {
                    add_clue_entry("JULKARNINE: IT IS A BIT ODD THAT SOMETHING LIKE THAT HAPPENED.\nI DID INDEED NOTICE SOMETHING ODD AROUND THESE PREMISES.\nAHMED: YOU ARE IN THE RIGHT DIRECTION.YOU HAVE THREE MEMBERS IN YOUR TEAM.\nMANY GAMES USE THE NUMBER THREE IN INTERESTING WAYS.");
                    add_journal_entry("The team traveled to Padma Pukur. There, they met Julkarnine and Ahmed who were practicing their GK and IQ skills\n");

                    game_state->padma_pukur_check = 1;
                }
                break;

            case 5:

                show_center_title("TEAM TRAVELS TO IT PARK",1000);
                park_char_choose(game_state);
                  if (game_state->it_park_check == 0)
                {
                    add_clue_entry("LEARN TO JUDGE PEOPLE AROUND YOU TO UNDERSTAND THEM BETTER!");
                    add_journal_entry("Team traveled to IT park in search of the missing key. There was definitely something strange about that place, or perhaps about the people there.");

                    game_state->it_park_check = 1;
                }
                if(game_state->dead_end == 1) return;
                break;

            case 6:
                printf("Returning to game menu....\n");
                return;

            default:
                printf(BOLD_RED "\nInvalid location. Try again!\n" RESET);
                continue_btn();
            }
        }
    }
}
