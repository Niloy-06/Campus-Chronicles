#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "titles.h"

enum menu_card_reg
{
    reg_team_player = 1,
    display_team,
    elect_leader,
    remove_teammate,
    start_investigation
};

void title_reg()
{
    clear_screen();

    printf("\033[1;31m");
    printf("========================================\n");
    printf("         THE CAMPUS CHRONICLES          \n");
    printf("           Team Registration            \n");
    printf("========================================\n\n");
    printf("\033[0m");
}

void team_management(Game_state *game_state, int return_to_game)
{
    int choose;
    Game *game = &game_state->game;
    if(return_to_game == 0)
    {
        FILE *file = fopen("player_info.txt", "w");
        if(file != NULL)
        {
            fclose(file);
        }
    }
    while (1)
    {
        title_reg();

        printf("1. REGISTER YOUR TEAM\n");
        printf("2. DISPLAY TEAM\n");
        printf("3. ElECT TEAM LEADER\n");
        printf("4. REMOVE A TEAMMATE\n");
        printf("5. START INVESTIGATION\n");
        printf("Enter Your Choice:");

        scanf("%d", &choose);
        getchar();

        switch (choose)
        {
        case reg_team_player:
            registerPlayers(game);
            continue_btn();
            break;

        case display_team:
            if(return_to_game == 0) printf("Register first to display Team.\n");
            displayTeam(game);
            continue_btn();
            break;

        case elect_leader:
            electLeader(game);
            continue_btn();
            break;

        case remove_teammate:
            removeTeammate(game);
            continue_btn();
            break;

        case start_investigation:

            if (game->leaderIndex == -1)
            {
                printf("\nYou must elect a team leader first!\n");
                continue_btn();
            }
            else
            {
                printf("\nTeam ready!\n");
                Sleep(1000);
                if (return_to_game == 1)
                {
                    return;
                }
                else
                {

                    show_center_title("LET THE INVESTIGATION BEGIN!", 2000);
                    add_journal_entry("Young minds form a team of three.\nThey embark on a journey to uncover the mystery of missing key.");
                    game_menu(game_state);
                    return;
                }
            }

            break;

        default:
            printf(BOLD_RED "invalid choice, try again!" RESET);
            continue_btn();
        }
    }
}

void registerPlayers(Game *game)
{
    printf(BOLD_RED "N.B: PLAYER NAMES MUST CONTAIN ONLY ONE WORD.\n" RESET);
    int choice;
    printf("\nEnter Team Name: ");
    scanf("%s", game->teamName);
    game->playerCount = MAX_PLAYERS;
    game->leaderIndex = -1;
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        printf("\nEnter name of Player %d: ", i + 1);
        scanf("%s", game->players[i].name);
        printf("\nChoose a role:\n");
        printf("1. Analyst\n");
        printf("2. Explorer\n");
        printf("3. Detective\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
            strcpy(game->players[i].role, "Analyst");
        else if (choice == 2)
            strcpy(game->players[i].role, "Explorer");
        else
            strcpy(game->players[i].role, "Detective");

        game->players[i].votes = 0;
    }

    FILE *fileTeam;
    fileTeam = fopen("player_info.txt", "w");
    if(fileTeam == NULL)
    {
        printf("Opps! Something went wrong. Try again!\n");
        return;
    }
    fprintf(fileTeam, "========TEAM INFORMATION========\n");
    fprintf(fileTeam, "Team Name: %s\n",game->teamName);
    for(int i=0; i < game->playerCount; i++)
    {
        fprintf(fileTeam, "\n Player %d: %s\n",i + 1, game->players[i].name);
        fprintf(fileTeam, "Role: %s\n",game->players[i].role);
        if (game->leaderIndex == i)
            fprintf(fileTeam, "Status: Team Leader\n");
        else
            fprintf(fileTeam, "Status: Team Member\n");
    }
    if (game->leaderIndex == -1)
        fprintf(fileTeam, "\nTeam leader has not been elected yet.\n");

    fclose(fileTeam);

    printf("\nPlayer information saved successfully!\n");
    Sleep(1000);
    printf("Team Registration Complete.\n");
    getchar();
}

void displayTeam(Game *game)
{
    FILE *output;
    char line[200];
    output = fopen("player_info.txt", "r");
    if(output == NULL)
    {
        printf("No saved data Found!\n");
        printf("Please register your team first.\n");
        Sleep(2000);
        return;
    }
    while(fgets(line, sizeof(line), output) != NULL)
    {
        printf("%s", line);
    }
    fclose(output);
}

void electLeader(Game *game)
{
    if (game->playerCount < 2)
    {
        printf("\nAt least 2 players are required to elect a leader.\n");
        return;
    }

    // Reset all votes
    for (int i = 0; i < game->playerCount; i++)
    {
        game->players[i].votes = 0;
    }

    printf("\n========================================\n");
    printf("             TEAM ELECTION              \n");
    printf("========================================\n");

    // Each player votes
    for (int i = 0; i < game->playerCount; i++)
    {
        int vote;

        printf("\n%s, cast your vote:\n", game->players[i].name);

        for (int j = 0; j < game->playerCount; j++)
        {
            printf("%d. %s\n", j + 1, game->players[j].name);
        }

        while (1)
        {
            printf("Enter player number: ");
            scanf("%d", &vote);

            if (vote >= 1 && vote <= game->playerCount)
            {
                break;
            }

            printf(BOLD_RED "Invalid choice! Please try again.\n" RESET);
        }

        game->players[vote - 1].votes++;
    }

    // Find player with highest votes
    int highestVotes = -1;
    int leader = -1;
    int tie = 0;

    for (int i = 0; i < game->playerCount; i++)
    {
        if (game->players[i].votes > highestVotes)
        {
            highestVotes = game->players[i].votes;
            leader = i;
            tie = 0;
        }
        else if (game->players[i].votes == highestVotes)
        {
            tie = 1;
        }
    }

    // Handle tie
    if (tie)
    {
        printf("\nThe election resulted in a tie!\n");
        printf("Please run the election again.\n");
        Sleep(2000);

        for (int i = 0; i < game->playerCount; i++)
        {
            game->players[i].votes = 0;
        }

        return;
    }

    game->leaderIndex = leader;

    printf("\n========================================\n");
    printf("          ELECTION COMPLETE!            \n");
    printf("========================================\n");
    printf("Team Leader: %s\n", game->players[leader].name);
    printf("Votes: %d\n", game->players[leader].votes);

    // Update saved file
    FILE *fileTeam = fopen("player_info.txt", "w");

    if (fileTeam == NULL)
    {
        printf("\nWarning: Could not update player_info.txt\n");
        return;
    }

    fprintf(fileTeam, "========TEAM INFORMATION========\n");
    fprintf(fileTeam, "Team Name: %s\n", game->teamName);

    for (int i = 0; i < game->playerCount; i++)
    {
        fprintf(fileTeam, "\nPlayer %d: %s\n",
                i + 1, game->players[i].name);

        fprintf(fileTeam, "Role: %s\n",
                game->players[i].role);

        if (game->leaderIndex == i)
            fprintf(fileTeam, "Status: Team Leader\n");
        else
            fprintf(fileTeam, "Status: Team Member\n");
    }

    fclose(fileTeam);
    getchar();
}
void removeTeammate(Game *game)
{
    if (game->playerCount <= 1)
    {
        printf("\nYou cannot remove the last team member.\n");
        Sleep(2000);
        return;
    }

    printf("\n========================================\n");
    printf("           REMOVE TEAMMATE              \n");
    printf("========================================\n");

    for (int i = 0; i < game->playerCount; i++)
    {
        printf("%d. %s", i + 1, game->players[i].name);

        if (i == game->leaderIndex)
            printf(" [TEAM LEADER]");

        printf("\n");
    }

    int choice;

    while (1)
    {
        printf("\nEnter player number to remove: ");
        scanf("%d", &choice);
        getchar();
        if (choice >= 1 && choice <= game->playerCount)
            break;

        printf("Invalid choice! Try again.\n");
        continue_btn();
    }

    int removeIndex = choice - 1;


    if (removeIndex == game->leaderIndex)
    {
        printf("\nThe Team Leader cannot be removed.\n");
        printf("Elect another leader first.\n");
        Sleep(3000);
        return;
    }

    printf("\n%s has been removed from the team.\n",
           game->players[removeIndex].name);

    for (int i = removeIndex; i < game->playerCount - 1; i++)
    {
        game->players[i] = game->players[i + 1];
    }

    game->playerCount--;

    if (game->leaderIndex > removeIndex)
    {
        game->leaderIndex--;
    }
    FILE *fileTeam = fopen("player_info.txt", "w");

    if (fileTeam == NULL)
    {
        printf("\nWarning: Could not update player_info.txt\n");
        return;
    }

    fprintf(fileTeam, "========TEAM INFORMATION========\n");
    fprintf(fileTeam, "Team Name: %s\n", game->teamName);

    for (int i = 0; i < game->playerCount; i++)
    {
        fprintf(fileTeam, "\nPlayer %d: %s\n",
                i + 1, game->players[i].name);

        fprintf(fileTeam, "Role: %s\n",
                game->players[i].role);

        if (game->leaderIndex == i)
            fprintf(fileTeam, "Status: Team Leader\n");
        else
            fprintf(fileTeam, "Status: Team Member\n");
    }

    fclose(fileTeam);

    printf("\nTeam information updated successfully.\n");
}

