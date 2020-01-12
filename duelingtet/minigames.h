enum MiniGameType { MGT_NONE, MGT_REDBALLOON, MGT_JUMPHURDLES, MGT_THROWDISC, MGT_KICKBALL, MGT_VACUUM, MGT_PUNCHBOXER, MGT_SHAKEPOPCORN};
byte activeMinigame;
enum MiniGameMode { MM_INSTRUCTIONS, MM_COUNTDOWN, MM_PLAY, MM_WON, MM_LOST};

extern byte lastJoypad;

struct MinigameState {
    byte x,y;   // where is the character
    int state;
    byte frame;
    byte frameTimer;
};

#define MAX_MINIGAMESTATE 3
extern struct MinigameState minigameState[];

// Interface for the game engine
void pick_minigames();
void init_minigames();
void update_minigames();
void draw_minigames();
int is_minigame_done();
const char *getMinigameName();
const char *getMinigameInstruction();

// Helper functions for minigames to use
void setMinigameMode(int newMode);
void buildSpriteState(int count);
