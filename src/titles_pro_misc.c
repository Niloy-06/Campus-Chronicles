#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "titles.h"

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void game_title()
{
    clear_screen();

    printf(BOLD_RED);
    printf("========================================\n");
    printf("         THE CAMPUS CHRONICLES          \n");
    printf("========================================\n\n");
    printf(RESET);
}

void continue_btn()
{
    printf("\n[Press Enter to Continue]");
    fflush(stdout);

    char c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
void show_center_title(const char *title, int seconds)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    int width;
    int height;
    int text_length;
    int x;
    int y;

    clear_screen();

    GetConsoleScreenBufferInfo(
        GetStdHandle(STD_OUTPUT_HANDLE),
        &csbi
    );

    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    text_length = strlen(title);

    x = (width - text_length) / 2;
    y = height / 2;

    COORD position;

    position.X = x;
    position.Y = y;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        position
    );

    printf(BOLD_RED "%s" RESET, title);

    Sleep(seconds);
}

void prologue_opening()
{
    game_title();

    char e_line[] =
        "The biggest cultural festival of Khulna University of Engineering \n"
        "& Technology starts at sunset. Thousands of students are waiting...\n\n"
        "But in the afternoon, the MASTER KEY of the auditorium facilities mysteriously vanishes!\n"
        "Without it, the festival gates and stage control room cannot be opened.\n\n"
        " A mysterious message appears on the notice board:\n"
        "   Three clues are true. Two are traps. Find the key before sunset.\n\n"
        "Three young detective minds.\n"
        "One missing set of keys.\n"
        "One mystery waiting to be solved.\n\n"
        "Their quest begins now...\n";

    for (int i = 0; e_line[i] != '\0'; i++)
    {
        printf("%c", e_line[i]);
        Sleep(50);
    }
    // PRINT_STORY(e_line, 50);

    continue_btn();

}

void prologue()
{
    game_title();

    char e_line[] =
        "The biggest cultural festival of Khulna University of Engineering \n"
        "& Technology, starts at sunset. Thousands of students are waiting..\n\n"
        "But in afternoon, the MASTER KEY of the auditorium facilities mysteriously vanishes!\n"
        "Without it, the festival gates and stage control room cannot be opened.\n\n"
        " A mysterious message appears on the notice board:\n"
        "   Three clues are true. Two are traps. Find the key before sunset.\n\n"
        "Three young detective minds.\n"
        "One missing set of keys.\n"
        "One mystery waiting to be solved.\n\n"
        "Their quest begins now...\n";

    for (int i = 0; e_line[i] != '\0'; i++)
    {
        printf("%c", e_line[i]);
    }

    continue_btn();
}
void add_journal_entry(const char *entry)
{
    FILE *file = fopen("detectives_journal.txt", "a");

    if (file == NULL)
    {
        printf("Could not open journal file!\n");
        return;
    }
    fprintf(file, "\n", entry);
    fprintf(file, "%s\n\n", entry);

    fclose(file);
}
void display_journal()
{
    clear_screen();
    FILE *file = fopen("detectives_journal.txt", "r");

    if (file == NULL)
    {
        printf("Could not open journal file!\n");
        return;
    }

    char line[1024];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    fclose(file);
}
void add_clue_entry(const char *entry)
{
    FILE *file = fopen("clue.txt", "a");

    if (file == NULL)
    {
        printf("Could not open clue file!\n");
        return;
    }
    fprintf(file, "\n", entry);
    fprintf(file, "%s\n\n", entry);

    fclose(file);
}
void display_clue()
{
    clear_screen();
    FILE *file = fopen("clue.txt", "r");

    if (file == NULL)
    {
        printf("Could not open clue file!\n");
        return;
    }

    char line[1024];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    fclose(file);
}
void clear_journal()
{
    FILE *file = fopen("detectives_journal.txt", "w");

    if (file == NULL)
    {
        printf("Could not clear the file!\n");
        return;
    }

    fprintf(file, "===========================================\n");
    fprintf(file, "            DETECTIVE'S JOURNAL\n");
    fprintf(file, "===========================================\n");
    fclose(file);
}
void clear_clue()
{
    FILE *file = fopen("clue.txt", "w");

    if (file == NULL)
    {
        printf("Could not clear the file!\n");
        return;
    }

    fprintf(file, "===========================================\n");
    fprintf(file, "               CLUE BOARD\n");
    fprintf(file, "===========================================\n");
    fclose(file);
}
