#ifndef TITLES_H_INCLUDED
#define TITLES_H_INCLUDED
#include <stdio.h>
#include <windows.h>
#define PRINT_STORY(text, delay);            \
do{                                          \
    for (int i = 0; text[i] != '\0'; i++)    \
    {                                        \
        printf("%c", text[i]);               \
        Sleep(delay);                        \
    }                                        \
} while (0)

#define BOLD_RED     "\033[1;31m"
#define RESET        "\033[0m"

#define MAX_PLAYERS 3
#define NAME_SIZE 50



typedef struct
{
    char name[NAME_SIZE];
    char role[20];
    int votes;
} Player;

typedef struct
{
    char teamName[NAME_SIZE];
    Player players[MAX_PLAYERS];
    int leaderIndex;
    int playerCount;
} Game;
typedef struct
{
    Game game;
    int game_progress;
    int decoder;
    int pocket_gate_check;
    int cafeteria_check;
    int academic_building_check;
    int padma_pukur_check;
    int it_park_check;
    int finale_trigger_check;
    int fin_init_check;
    int ending_check;
    int dead_end;

}Game_state;

//title_and_others.c
void clear_screen();
void game_title();
void show_center_title(const char *title, int seconds);
void prologue();
void continue_btn();
void prologue_opening();
void add_journal_entry(const char *entry);
void display_journal();
void add_clue_entry(const char *entry);
void display_clue();
void clear_journal();
void clear_clue();

//open_menu.c
void starting_timer();
void closing_timer();
void print_txt_file(const char *filename);
void about_dev();
void reset_game_state(Game_state *game_state);
void menu_opening(Game_state *game_state);

//team_manager.c
void title_reg();
void team_management(Game_state *game_state, int return_to_game);
void registerPlayers(Game *game);
void electLeader(Game *game);
void removeTeammate(Game *game);
void displayTeam(Game *game);

//game_menu.c
void game_menu(Game_state *game_state);

//location.c
void showMap();
void locationMenu(Game_state *game_state);

//finale.c
void finale_initiator(Game_state *game_state);
void conversation(Game_state *game_state);
void story();
void round_start(int round);
void wrestling_match(Game_state *game_state);

//crypto.c
void caesarCipherUpper(char text[], int k, int mode);
void happy_ending();
void victory_menu(Game_state *game_state);

int saveGame(Game_state *game_state);
int loadGame(Game_state *game_state);

//ac.c
void code_debugging(Game_state *game_state);
void debug_code();
void ac_char_choose(Game_state *game_state);
void cse_lab(Game_state *game_state);
//cafe.c
void cafe_char_choose(Game_state *game_state);
void naeem_riddle(Game_state *game_state);
void threeDoorsRiddle(Game_state *game_state);
void kabir_scrabble(Game_state *game_state);
void scrabble_game(Game_state *game_state);

//padma.c
void padma_char_choose(Game_state *game_state);
void julkarnine_gk(Game_state *game_state);
void gk_qna(Game_state *game_state);
void ahmed_iq(Game_state *game_state);
void iq_qna(Game_state *game_state);

//it.c
void park_char_choose(Game_state *game_state);
void piroz_deadend(Game_state *game_state);
void mahmud_riddle(Game_state *game_state);

//gate.c
void gate_char_choose(Game_state *game_state);
void ques_ans(Game_state *game_state);
void miraz_dialogue(Game_state *game_state);
void sudoku_game();
#endif // TITLES_H_INCLUDED
