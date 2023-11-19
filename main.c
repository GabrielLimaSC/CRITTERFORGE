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

#include "keyboard.h"
#include "screen.h"
#include "timer.h"
#include <stdio.h>
#include <string.h>

// Variáveis fictícias para representar os Pokémon e seu estado
typedef struct {
  char name[20];
  char type[10];
  int health;
  int attack1;
  int attack2;
  int attack3;
  int attack4;
  int criticalattack;
  char critticaltype[10];
} Pokemon;

Pokemon choice1 = {"Charmander","Fire",    100, 15, 20, 10, 10, 25, "Grass"};
Pokemon choice2 = {"Squirtle",  "Water",   100, 15, 20, 10, 10, 25, "Fire" };
Pokemon choice3 = {"Bulbasaur", "Grass",   100, 15, 20, 10, 10, 25, "Water"};
Pokemon choice4 = {"Pikachu",   "Electric",100, 15, 20, 10, 10, 20, "Water"};

Pokemon playerPokemon; // Agora será escolhido pelo jogador
Pokemon enemyPokemon = {"Charmander", "Fire", 100, 15, 20, 10, 10, 25, "Grass"};

int choosePokemon() {
  // Desenha a tela de escolha de Pokémon
  screenSetColor(WHITE, BLACK);
  screenClear();
  screenInit(0);

  screenGotoxy(5, 5);
  printf("ESCOLHA SEU POKÉMON");

  screenGotoxy(5, 8);
  printf("[1] %s", choice1.name);
  screenGotoxy(5, 9);
  printf("[2] %s", choice2.name);
  screenGotoxy(5, 10);
  printf("[3] %s", choice3.name);
  screenGotoxy(5, 11);
  printf("[4] %s", choice4.name);

  screenUpdate();

  // Aguarda a entrada do jogador
  while (1) {
    if (keyhit()) {
      int key = readch();
      switch (key) {
      case '1':
        playerPokemon = choice1;
        return 1;
      case '2':
        playerPokemon = choice2;
        return 1;
      case '3':
        playerPokemon = choice3;
        return 1;
      case '4':
        playerPokemon = choice4;
        return 1;
      default:
        break;
      }
    }
  }
}

void processPlayerInput(int key) {
  // Lógica para processar a entrada do jogador
  switch (key) {
  case '1':
    // Lógica para o ataque
    if(strcmp(playerPokemon.critticaltype, enemyPokemon.type) == 1){
      enemyPokemon.health -= playerPokemon.attack3;
    }else{
      enemyPokemon.health -= playerPokemon.criticalattack;
    }
    break;
    
  case '2':
    // Lógica para o segundo ataque
    enemyPokemon.health -= playerPokemon.attack2;
    break;
    
  case '3':
    if(playerPokemon.critticaltype != enemyPokemon.type){
      enemyPokemon.health -= playerPokemon.attack3;
    }else{
      enemyPokemon.health -= playerPokemon.criticalattack;
    }
    break;
    
  case '4':
    // Lógica para o quarto ataque
    enemyPokemon.health -= playerPokemon.attack4;
    break;
  default:
    break;
  }
}

void drawBattleScreen() {
  // Limpa a tela e define as cores do texto e do fundo
  screenSetColor(WHITE, BLACK);
  screenClear();

  // Desenha as bordas da tela
  screenInit(2);

  // Desenha o campo de batalha
  screenGotoxy(5, 5);
  printf("BATALHA POKÉMON");

  // Desenha os Pokémon e suas informações
  screenGotoxy(5, 8);
  printf("Player: %s - Health: %d", playerPokemon.name, playerPokemon.health);

  screenGotoxy(5, 10);
  printf("Enemy: %s - Health: %d", enemyPokemon.name, enemyPokemon.health);

  // Desenha o menu de ataques
  screenGotoxy(5, 15);
  printf("Escolha um ataque %s:", playerPokemon.name);
  screenGotoxy(5, 17);
  printf("[1] %d", playerPokemon.attack1);
  screenGotoxy(5, 18);
  printf("[2] %d", playerPokemon.attack2);
  screenGotoxy(5, 19);
  printf("[3] %d", playerPokemon.attack3);
  screenGotoxy(5, 20);
  printf("[4] %d", playerPokemon.attack4);

  // Atualiza a tela imediatamente após o desenho
  screenUpdate();
}

int main() {
  // Inicializa as bibliotecas
  keyboardInit();
  screenInit(0);
  timerInit(1000);

  // Escolhe o Pokémon do jogador
  while (!choosePokemon()) {
    // Continua solicitando até que uma escolha válida seja feita
  }

  // Loop principal do jogo
  int gameOver = 0;
  while (!gameOver) {
    // Desenha a tela de batalha
    drawBattleScreen();

    // Aguarda a entrada do jogador
    int keyPressed = 0;
    while (!keyPressed) {
      if (keyhit()) {
        int key = readch();
        // Lógica para tratar a entrada do jogador
        processPlayerInput(key);

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

    // Lógica para atualizar o estado da batalha e verificar o fim do jogo
    if (playerPokemon.health <= 0 || enemyPokemon.health <= 0) {
      gameOver = 1;
      // Lógica para exibir mensagem de vitória ou derrota
    }
  }

  // Encerra as bibliotecas
  keyboardDestroy();
  screenDestroy();
  timerDestroy();

  return 0;
}
