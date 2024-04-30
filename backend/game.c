#include <stdbool.h>
#include <stdlib.h>

#include "consts.h"
#include "game.h"
#include "screens.h"
#include "../shared/parser.h"

// TODO: Move to GameOutput struct
static uint32_t ScreenID = INVALID_SCREEN_ID;

bool SetupGame(void) {
  if (!LoadGameData("GameData.json")) {
    return false;
  }

  ScreenID = MAIN_MENU_SCREEN_ID;
  return true;
}

// TODO: Add more screens
bool GetCurrentGameOutput(struct GameOutput *output) {
  if (!output) {
    return false;
  }

  if (!output->stateData) {
    output->stateData = InitGameState();
  }
  if (!output->stateData) {
    return false;
  }

  arena_reset(&output->arena);

  if (ScreenID == MAIN_MENU_SCREEN_ID) {
    return CreateMainMenuScreen(ScreenID, output);
  } else {
    return CreateScreen(ScreenID, output);
  }
}

enum GameInputOutcome HandleGameInput(uint32_t screenID, uint32_t inputID) {
  struct GameScreenButton button = {0};
  if (!HandleScreenInput(screenID, inputID, &button)) {
    return InvalidInput;
  }

  enum GameInputOutcome outcome = button.outcome;
  if (outcome == GotoScreen) {
    ScreenID = button.newScreen;
    outcome = GetNextOutput;
  }

  FreeGameScreenButton(&button);
  return outcome;
}

void CleanupGame(struct GameOutput *output) {
  arena_free(&output->arena);
  UnloadGameData();
  free(output->stateData);
  output->stateData = NULL;
}
