#ifndef PCGAME_PARSER_H
#define PCGAME_PARSER_H

#include <stdbool.h>
#include <stdint.h>

#include "../backend/game.h"

struct GameScreen {
  char32_t *body;
  char32_t *extraText;
};

struct GameScreenButton {
  char32_t *title;
  enum GameInputOutcome outcome;
  uint32_t newScreen; // Only used(and set correctly) if outcome == GotoScreen
};

bool LoadGameData(char *);
void UnloadGameData(void);

unsigned char *InitGameState(void);
size_t GetGameStateOffset(uint32_t, uint8_t);

uint32_t GetGameScreenCount(void);
bool GetGameScreen(uint32_t, struct GameScreen *);

bool GetGameScreenButton(uint32_t, uint8_t, struct GameScreenButton *);
uint8_t GetGameScreenButtonCount(uint32_t);
void FreeGameScreenButton(struct GameScreenButton *);

#endif // PCGAME_PARSER_H
