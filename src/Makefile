CC = gcc

CFLAGS = -Wall -Wextra -std=c11

TARGET = CampusChronicles.exe

SRC = main.c \
      open_menu.c \
      game_menu.c \
      team_manager.c \
      locations.c \
      pocket_gate.c \
      cafeteria.c \
      academic_building.c \
      padma.c \
      it_park.c \
      Finale.c \
      Cryptography.c \
      save_load.c \
      titles_pro_misc.c

OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(OBJ) $(TARGET) 2>nul