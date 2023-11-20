/**
 * screen.h
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
 * Reference: https://en.wikipedia.org/wiki/ANSI_escape_code


#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <stdio.h>

// Terminal control sequences
#define ESC            "\033"
#define NORMALTEXT     "[0m"
#define BOLDTEXT       "[1m"
#define ITALICTEXT     "[3m"
#define BLINKTEXT      "[5m"
#define REVERSETEXT    "[7m"
#define HOMECURSOR     "[f"
#define SHOWCURSOR     "[?25h"
#define HIDECURSOR     "[?25l"
#define CLEARSCREEN    "[2J"

// BOX Drawing - Unix like terminals
#define BOX_ENABLE     "(0"
#define BOX_DISABLE    "(B"
#define BOX_VLINE      0x78
#define BOX_HLINE      0x71
#define BOX_UPLEFT     0x6C
#define BOX_UPRIGHT    0x6B
#define BOX_DWNLEFT    0x6D
#define BOX_DWNRIGHT   0x6A
#define BOX_CROSS      0x6E
#define BOX_TLEFT      0X74
#define BOX_TRIGHT     0X75
#define BOX_TUP        0X77
#define BOX_TDOWN      0X76

#define BOX_DIAMOND    0x60
#define BOX_BLOCK      0x61
#define BOX_DOT        0x7E

// screen constants
#define SCRSTARTX      3      // Initial and final screen positions for the game
#define SCRENDX        75     // It means the area that can be drawn
#define SCRSTARTY      1
#define SCRENDY        23

#define MINX           1      // min screen horizontal pos
#define MINY           1      // min screen vertical pos
#define MAXX           80     // max screen horizontal pos
#define MAXY           24     // max screen vertical pos

 * Screen Colors type

typedef enum {BLACK, RED, GREEN, BROWN, BLUE, MAGENTA, CYAN, LIGHTGRAY,
        DARKGRAY, LIGHTRED, LIGHTGREEN, YELLOW, LIGHTBLUE,
        LIGHTMAGENTA, LIGHTCYAN, WHITE} screenColor;



 * Move the cursor to position (0,0)

static inline void screenHomeCursor()
{
    printf("%s%s", ESC, HOMECURSOR);
}

 * Show the cursor

static inline void screenShowCursor()
{
    printf("%s%s", ESC, SHOWCURSOR);
}

 * Hide the cursor

static inline void screenHideCursor()
{
    printf("%s%s", ESC, HIDECURSOR);
}

 * Clear the screen

static inline void screenClear()
{
    screenHomeCursor();
    printf("%s%s", ESC, CLEARSCREEN);
}

 * Update screen imediatelly

static inline void screenUpdate() {
    fflush(stdout);
}

 * Set screen mode to "normal"

static inline void screenSetNormal()
{
    printf("%s%s", ESC, NORMALTEXT);
}

 * Set screen mode to "bold"

static inline void screenSetBold()
{
    printf("%s%s", ESC, BOLDTEXT);
}

 * Set screen mode to "blink"

static inline void screenSetBlink()
{
    printf("%s%s", ESC, BLINKTEXT);
}

 * Set screen mode to "reverse"

static inline void screenSetReverse()
{
    printf("%s%s", ESC, REVERSETEXT);
}

 * Enable BOX characters in terminal

static inline void screenBoxEnable()
{
    printf("%s%s", ESC, BOX_ENABLE);
}

 * Disable BOX characters in terminal

static inline void screenBoxDisable()
{
    printf("%s%s", ESC, BOX_DISABLE);
}

 * Clear the screen, set cursor to home position
 * and optionally draw borders on it.
 *
 * @param drawBorders if not zero, draw borders on screen.

void screenInit(int drawBorders);

 * Clear the screen and restores to initial state.

void screenDestroy();

 * Move cursor to position (x,y)
 * @param x x position
 * @param y y position


void screenGotoxy(int x, int y);

 * Define text colors
 * @param fg foreground color, can assume values from BLACK to WHITE
 * @param bg background color, can assume values from BLACK to LIGHTGRAY

void screenSetColor(screenColor fg, screenColor bg);

#endif  __SCREEN_H__

*/

/**
 * timer.h
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"


void timerInit(int valueMilliSec);

void timerDestroy();

void timerUpdateTimer(int valueMilliSec);

int timerTimeOver();

void timerPrint();

*/

/**
 * keyboard.h
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"


#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

void keyboardInit();

void keyboardDestroy();

int keyhit();

int readch();

#endif  __KEYBOARD_H__
*/

/**
 screen.h -

    void screenInit(int drawBorders); -

    Esta função inicializa a tela, O parâmetro drawBorders pode ser usado para
 desenhar para desenhar as bordas da tela. Se drawBorders for diferente de zero,
 as bordas serão desenhadas.

    void screenDestroy(); -

    Esta função limpa a tela e restaura o estado inicial.

    void screenGotoxy(int x, int y); -

    Esta função move o cursor para a posição (x,y).

    void screenSetColor(screenColor fg, screenColor bg); -

    Esta função define as cores do texto.
    O parâmetro fg define a cor do texto e o parâmetro bg define a cor do fundo.

 timer.h -

    void timerInit(int valueMilliSec); -

    Esta função inicializa o timer. O parâmetro valueMilliSec define o tempo em
 milisegundos.

    void timerDestroy(); -

    Esta função desativa o timer.

    void timerUpdateTimer(int valueMilliSec); -

    Esta função atualiza o timer. O parâmetro valueMilliSec define o tempo em
 milisegundos.

    int timerTimeOver(); -

    Esta função retorna 1 se o tempo definido pelo timer tiver expirado.
    Caso contrário, retorna 0.

    void timerPrint(); -

    Esta função imprime o tempo decorrido desde a última chamada da função
 timerInit().

 keyboard.h -

    void keyboardInit(); -

    Esta função inicializa o teclado.

    void keyboardDestroy(); -

    Esta função desativa o teclado.

    int keyhit(); -

    Esta função retorna 1 se uma tecla foi pressionada.
    Caso contrário, retorna 0.

    int readch(); -

    Esta função retorna o código da tecla pressionada.
    Se nenhuma tecla foi pressionada, retorna -1.

*/

/**
⠀⠀⠀⣀⠔⠒⠒⠂⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢰⢅⠀⠀⢀⣤⢄⢂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣾⡆⠀⠀⠀⢸⠼⡎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢀⢗⠂⠀⠀⡀⠈⢉⠅⠇⠀⠀⠀⠀⠀⠀⢠⣄⠀
⠀⠈⠢⣓⠔⣲⠖⡫⠊⡘⠀⠀⠀⠀⠀⠀⠲⡟⠙⡆
⠀⢀⢀⠠⠘⣇⠖⢄⠀⠉⠐⠠⢄⣀⡀⠀⠜⠀⠀⣁
⠘⣏⣀⣀⣀⠃⠀⠀⠑⣀⣀⣀⣰⠼⠇⠈⠄⠀⠈⡻
⠀⠁⠀⠀⢰⠀⠀⠀⠀⠠⠀⠡⡀⠀⠀⠀⠈⡖⠚⠀
⠀⠀⠀⡠⠘⠀⠀⠀⠀⢀⠆⠀⠐⡀⠀⡠⠊⣠⠀⠀
⠀⠀⢐⠀⠀⠁⡀⠀⠀⢀⠀⠀⠀⢨⠀⡠⡴⠂⠀⠀
⠀⢀⣨⣤⠀⠀⠐⠃⠐⠚⠢⠀⠀⠈⠑⠊⠀⠀⠀⠀
⠀⠘⠓⠋⠉⠁⠀⠀⠀⠀⠀⠓⢶⡾⠗⠀⠀⠀⠀⠀



  */ 

#include "keyboard.h"
#include "screen.h"
#include "timer.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
  char name[20];
  char type[10];
  int health;
  int attack1;
  int attack2;
  int attack3;
  int attack4;
  int criticalattack;
  char criticaltype[10];
} Pokemon;

void pr_pikachu() {
  printf(";-.          ___,\n");
  printf("  `.`\\_...._/`.-\"`\n");
  printf("    \\       /      ,\n");
  printf("    /()   () \\    .' `-._\n");
  printf("   |)  .    ()\\  /   _.'\n");
  printf("   \\  -'-     ,; '. <\n");
  printf("    ;.__     ,;|   > \\\n");
  printf("   / ,    / ,  |.-'.-'\n");
  printf("  (_/    (_/ ,;|.<`\n");
  printf("    \\    ,     ;-`\n");
  printf("     >   \\    /\n");
  printf("    (_,-'`> .'\n");
  printf("      (_,'\n");
}

Pokemon choice1 = {"Charmander", "Fire", 100, 15, 20, 10, 10, 25, "Grass"};
Pokemon choice2 = {"Squirtle", "Water", 100, 15, 20, 10, 10, 25, "Fire"};
Pokemon choice3 = {"Bulbasaur", "Grass", 100, 15, 20, 10, 10, 25, "Water"};
Pokemon choice4 = {"Pikachu", "Electric", 100, 15, 20, 10, 10, 20, "Water"};

typedef struct {
  char playerName[20];
  Pokemon pokemon;
} Player;

Player player1; // Chosen by player 1
Player player2; // Chosen by player 2

typedef struct {
  char playerName[20];
  int victories;
} PlayerStats;

void savePlayerStats(PlayerStats *winner) {
  FILE *file = fopen("player_stats.dat", "a");

  if (file == NULL) {
    // Se o arquivo não existir, cria um novo
    file = fopen("player_stats.dat", "w");
    if (file == NULL) {
      fprintf(stderr, "Erro ao criar o arquivo de estatísticas.\n");
      exit(1);
    }
  }

  fwrite(winner, sizeof(PlayerStats), 1, file);
  fclose(file);
}

void updatePlayerStats(PlayerStats *winner) {
  FILE *file = fopen("player_stats.dat", "r+");

  if (file == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo de estatísticas.\n");
    exit(1);
  }

  PlayerStats playerStats;
  int found = 0;

  while (fread(&playerStats, sizeof(playerStats), 1, file) == 1) {
    if (strcmp(playerStats.playerName, winner->playerName) == 0) {
      playerStats.victories++;
      found = 1;
      fseek(file, -sizeof(playerStats), SEEK_CUR);
      fwrite(&playerStats, sizeof(playerStats), 1, file);
      break;
    }
  }

  fclose(file);

  if (!found) {
    // Se o jogador não existir nas estatísticas, adiciona um novo registro
    playerStats.victories = 1;
    strncpy(playerStats.playerName, winner->playerName,
            sizeof(playerStats.playerName));

    // Reabre o arquivo para escrever o novo registro
    file = fopen("player_stats.dat", "a");
    if (file == NULL) {
      fprintf(stderr, "Erro ao abrir o arquivo de estatísticas.\n");
      exit(1);
    }

    fwrite(&playerStats, sizeof(playerStats), 1, file);
    fclose(file);
  }
}

void loadPlayerStats() {
  FILE *file = fopen("player_stats.dat", "r");

  if (file == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo de estatísticas.\n");
    exit(1);
  }

  PlayerStats playerStats;

  printf("\nEstatísticas de Jogadores:\n");

  while (fread(&playerStats, sizeof(PlayerStats), 1, file) == 1) {
    printf("Jogador: %s | Vitórias: %d\n", playerStats.playerName,
           playerStats.victories);
  }

  fclose(file);
}

void getPlayerName(char *name, int playerNumber) {
  screenSetColor(WHITE, BLACK);
  screenClear();
  screenInit(0);

  screenGotoxy(5, 5);
  printf("Digite o nome do Player %d: ", playerNumber);
  screenUpdate();

  int index = 0;
  char inputChar;

  // Modificação aqui - ler os caracteres diretamente com getchar
  while (1) {
    inputChar = getchar();
    if (inputChar == '\n' || index >= 19) {
      break;
    }
    name[index++] = inputChar;
    name[index] = '\0'; // Garante que a string esteja sempre terminada

    // Atualiza a tela com o nome digitado
    screenGotoxy(5, 7);
    printf("Nome: %s               ", name);
    screenGotoxy(5, 7);
    screenUpdate();
  }

  fflush(stdin);
}

int choosePokemon(Player *player) {
  // Drawing the Pokémon selection screen
  screenSetColor(WHITE, BLACK);
  screenClear();
  screenInit(0);

  screenGotoxy(5, 5);
  printf("Vez do %s escolher o POKÉMON", player->playerName);

  screenGotoxy(5, 8);
  printf("[1] %s", choice1.name);
  screenGotoxy(5, 9);
  printf("[2] %s", choice2.name);
  screenGotoxy(5, 10);
  printf("[3] %s", choice3.name);
  screenGotoxy(5, 11);
  printf("[4] %s", choice4.name);

  screenUpdate();

  // Wait for player input
  while (1) {
    if (keyhit()) {
      int key = readch();
      switch (key) {
      case '1':
        player->pokemon = choice1;
        return 1;
      case '2':
        player->pokemon = choice2;
        return 1;
      case '3':
        player->pokemon = choice3;
        return 1;
      case '4':
        player->pokemon = choice4;
        return 1;
      default:
        break;
      }
    }
  }
}

void processPlayerInput(int key, Player *attacker, Player *defender) {
  // Logic to process player input
  switch (key) {
  case '1':
    if (strcmp(attacker->pokemon.criticaltype, defender->pokemon.type) == 0) {
      defender->pokemon.health -= attacker->pokemon.attack3;
    } else {
      defender->pokemon.health -= attacker->pokemon.criticalattack;
    }
    break;

  case '2':
    defender->pokemon.health -= attacker->pokemon.attack2;
    break;

  case '3':
    if (strcmp(attacker->pokemon.criticaltype, defender->pokemon.type) != 0) {
      defender->pokemon.health -= attacker->pokemon.attack3;
    } else {
      defender->pokemon.health -= attacker->pokemon.criticalattack;
    }
    break;

  case '4':
    defender->pokemon.health -= attacker->pokemon.attack4;
    break;
  default:
    break;
  }
}

void drawGameOverScreen(Player *currentPlayer, Player *opponent,
                        int *playAgain) {
  screenSetColor(RED, BLACK);
  screenClear();

  screenInit(0);

  screenGotoxy(5, 6);
  printf("GAME OVER");
  screenGotoxy(5, 8);
  printf("O GANHADOR FOI: %s", currentPlayer->playerName);

  screenGotoxy(5, 10);
  printf("Deseja jogar novamente? (S/N)");
  screenUpdate();

  char playAgainResponse;
  do {
    if (keyhit()) {
      playAgainResponse = readch();
    }
  } while (playAgainResponse != 'S' && playAgainResponse != 's' &&
           playAgainResponse != 'N' && playAgainResponse != 'n');

  if (playAgainResponse == 'S' || playAgainResponse == 's') {
    *playAgain = 1;
  } else {
    *playAgain = 0;
  }

  // Modificação para exibir o placar
  screenGotoxy(5, 12);
  printf("Pressione 'V' para ver o placar");
  screenUpdate();

  int keyPressed = 0;
  while (!keyPressed) {
    if (keyhit()) {
      char viewScoreboard = readch();
      if (viewScoreboard == 'V' || viewScoreboard == 'v') {
        loadPlayerStats(); // Exibe estatísticas após cada jogo
      }
      keyPressed = 1;
    }
  }
}

void drawBattleScreen(Player *currentPlayer, Player *opponent) {
  // Clear the screen and set text and background colors
  screenSetColor(WHITE, BLACK);

  // Draw the screen borders
  screenInit(2);

  // Draw the battlefield
  screenGotoxy(5, 5);
  printf("BATALHA POKÉMON");
  // Draw Pokémon and their information for the current player
  screenGotoxy(5, 8);
  printf("%s: %s - Vida: %d", currentPlayer->playerName,
         currentPlayer->pokemon.name, currentPlayer->pokemon.health);

  // Draw Pokémon and their information for the opponent
  screenGotoxy(5, 10);
  printf("%s: %s - Vida: %d", opponent->playerName, opponent->pokemon.name,
         opponent->pokemon.health);

  // Draw the attack menu
  screenGotoxy(5, 15);
  printf("Escolha um ataque %s:", currentPlayer->playerName);
  screenGotoxy(5, 17);
  printf("[1] %d", currentPlayer->pokemon.attack1);
  screenGotoxy(5, 18);
  printf("[2] %d", currentPlayer->pokemon.attack2);
  screenGotoxy(5, 19);
  printf("[3] %d", currentPlayer->pokemon.attack3);
  screenGotoxy(5, 20);
  printf("[4] %d", currentPlayer->pokemon.attack4);

  // Update the screen immediately after drawing
  screenUpdate();
}

/**
void charmander() {
    printf("⠀⠀⣀⠔⠒⠒⠂⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⢰⢅⠀⠀⢀⣤⢄⢂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⣾⡆⠀⠀⠀⢸⠼⡎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⢀⢗⠂⠀⠀⡀⠈⢉⠅⠇⠀⠀⠀⠀⠀⠀⢠⣄⠀\n");
    printf("⠀⠈⠢⣓⠔⣲⠖⡫⠊⡘⠀⠀⠀⠀⠀⠀⠲⡟⠙⡆\n");
    printf("⠀⢀⢀⠠⠘⣇⠖⢄⠀⠉⠐⠠⢄⣀⡀⠀⠜⠀⠀⣁\n");
    printf("⠘⣏⣀⣀⣀⠃⠀⠀⠑⣀⣀⣀⣰⠼⠇⠈⠄⠀⠈⡻\n");
    printf("⠀⠁⠀⠀⢰⠀⠀⠀⠀⠠⠀⠡⡀⠀⠀⠀⠈⡖⠚⠀\n");
    printf("⠀⠀⠀⡠⠘⠀⠀⠀⠀⢀⠆⠀⠐⡀⠀⡠⠊⣠⠀⠀\n");
    printf("⠀⠀⢐⠀⠀⠁⡀⠀⠀⢀⠀⠀⠀⢨⠀⡠⡴⠂⠀⠀\n");
    printf("⠀⢀⣨⣤⠀⠀⠐⠃⠐⠚⠢⠀⠀⠈⠑⠊⠀⠀⠀⠀\n");
    printf("⠀⠘⠓⠋⠉⠁⠀⠀⠀⠀⠀⠓⢶⡾⠗⠀⠀⠀⠀⠀\n");

}

void squirtle() {
    printf("⠀⠀⠀⠀⠀⣀⠤⠤⠤⠤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⡰⠋⠀⠀⠀⠀⠀⠀⠡⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⢠⠁⢰⣴⠀⠀⠀⠀⣿⡇⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⢀⣸⠀⠈⠙⠃⣀⣀⡀⣤⡄⢸⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⢰⠃⠉⠁⠂⢦⣀⢀⡀⠤⠤⣥⣌⡀⠀⠈⠱⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠘⠦⡀⠀⠀⠀⠈⡄⠂⠉⠀⣀⠵⢵⡒⠠⢴⡋⠉⢑⠖⠦⢄⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠈⠲⢤⣤⣴⡥⢄⡨⠋⠀⠒⢄⡑⣄⠀⠈⠄⠀⠀⠀⠈⡝⢀⣀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠈⢿⣿⣿⣆⡇⠀⠀⠊⠉⠉⡆⠈⠢⣶⣀⡀⢀⡰⠋⠀⠀⠉⠑⡄\n");
    printf("⠀⠀⠀⠀⠀⠀⢿⣿⣿⣔⠀⠠⡀⠀⢀⡇⠀⠀⠠⣇⠈⢹⠀⠀⡀⠀⠀⠀⠘⡄\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠙⠛⢿⣿⣿⣿⣿⣶⣶⢆⠀⠀⠈⠉⠈⢄⠀⠀⠀⠂⠀⢀⠇\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠁⠀⠀⠑⠦⣄⠀⠀⠀⠁⠀⠈⠀⢀⠎⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠓⠒⠲⠖⠒⠊⠁⠀⠀\n");

}


void bulbasour() {
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣀⡀⠈⡖⡤⠄⠀\n");
    printf("⠀⠀⢀⡀⠀⠀⠀⡐⠁⠀⠀⠠⠐⠂⠀⠁⠀⠀⠀⠀\n");
    printf("⠀⠰⡁⠐⢉⣉⣭⡍⠁⠂⠉⠘⡀⠀⠀⠀⠀⠂⠡⠀\n");
    printf("⢀⣊⠀⡄⠻⠿⠋⠀⠀⠀⠀⠀⢃⠀⠀⠀⠀⠀⠀⢀\n");
    printf("⡎⣾⠀⠁⣴⡆⠀⠡⢺⣿⣆⠀⢠⢱⣄⠀⠀⠀⠀⠈\n");
    printf("⡑⠟⠀⠀⠀⠀⠀⢀⣸⡿⠟⠀⠀⠈⢿⣿⡦⡀⠀⡰\n");
    printf("⠙⠔⠦⣤⣥⣤⣤⣤⡤⠆⠀⠀⠀⠀⢀⢀⠀⠈⠎⠀\n");
    printf("⠀⠀⠈⣰⡋⢉⠉⠁⠒⠂⢇⢠⡆⠀⠸⢴⣿⠀⠘⠀\n");
    printf("⠀⠀⠘⡿⠃⠀⠨⠒⢆⣸⣿⠁⠀⡠⡇⠈⠋⠀⠰⠀\n");
    printf("⠀⠀⠀⠛⠒⠒⠁⠀⠈⠷⡤⠤⠐⠀⠘⠒⠒⠖⠁⠀\n");

}

*/

int main() {
  int playAgain = 1;

  while (playAgain) {
    keyboardInit();
    screenInit(0);
    timerInit(1000);

    memset(&player1, 0, sizeof(Player));
    memset(&player2, 0, sizeof(Player));

    getPlayerName(player1.playerName, 1);
    getPlayerName(player2.playerName, 2);

    while (!choosePokemon(&player1)) {
      // Continua solicitando até que uma escolha válida seja feita
    }

    while (!choosePokemon(&player2)) {
      // Continua solicitando até que uma escolha válida seja feita
    }

    int gameOver = 0;
    Player *currentPlayer = &player1;
    Player *opponent = &player2;

    while (!gameOver) {
      drawBattleScreen(currentPlayer, opponent);

      int keyPressed = 0;
      while (!keyPressed) {
        if (keyhit()) {
          int key = readch();
          processPlayerInput(key, currentPlayer, opponent);
          keyPressed = 1;
        }

        if (timerTimeOver()) {
          // Lógica para atualizar a tela durante a batalha
          // (por exemplo, animações, atualizações de estado, etc.)
          // ...

          // Atualiza a tela imediatamente após as alterações
          screenUpdate();
        }
      }

      if (currentPlayer == &player1) {
        currentPlayer = &player2;
        opponent = &player1;
      } else {
        currentPlayer = &player1;
        opponent = &player2;
      }

      if (player1.pokemon.health <= 0 || player2.pokemon.health <= 0) {
        gameOver = 1;

        Player *winner;
        if (player1.pokemon.health <= 0) {
          winner = &player2;
        } else {
          winner = &player1;
        }

        // Salva as estatísticas do vencedor
        savePlayerStats(
            &(PlayerStats){.playerName = winner->playerName, .victories = 0});
        updatePlayerStats(winner); // Atualizar estatísticas
        loadPlayerStats();         // Exibir estatísticas após cada jogo

        // Desenha a tela de game over
        drawGameOverScreen(winner, opponent, &playAgain);
      }
    }

    keyboardDestroy();
    screenDestroy();
    timerDestroy();
  }

  return 0;
}
