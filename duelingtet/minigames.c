#include<coleco.h>
#include<getput1.h>

#include "minigames.h"
#include "sprites.h"

extern const byte house_bitmapColBIGRUN[];
extern const byte house_bitmapPatBIGRUN[];
extern const byte track_bitmapColBIGRUN[];
extern const byte track_bitmapPatBIGRUN[];

byte activeMinigame;
byte minigameMode;

const char * minigameName[]={
    "NONE",
    "RED BALLOON",
    "HURDLES JUMP",
    "DISC THROW",
    "BALL KICK",
    "VACUUM",
    "BOXER PUNCH",
    "POPCORN SHAKE",
};

const char * minigameInstruction[]={
    "NONE",
    "UP TO CATCH THE RED BALLOON     AND DOWN TO AVOID THE YELLOW    BALOON",
    "USE LEFT FIRE TO JUMP THE       HURDLES",
    "UP AND DOWN THEN FIRE TO        THROW THE DISC FAR",
    "KICK THE BALL INTO THE          GOAL",
    "LEFT AND RIGHT TO VACUUM THE    FLOOR",
    "HOLD DOWN TO WIND UP THEN       PUNCH THE BOXER",
    "UP AND DOWN TO SHAKE THE        POPCORN",
};

byte lastJoypad1,lastJoypad2;

struct MinigameState minigameState[MAX_MINIGAMESTATE];

void setMinigameMode(int newMode)
{
    minigameMode=newMode;
}

const char *getMinigameName()
{
    return minigameName[activeMinigame];
}

const char *getMinigameInstruction()
{
    return minigameInstruction[activeMinigame];
}

void buildSpriteState(int count)
{
    int i;
    int offset;

    if(activeMinigame==MGT_NONE) {
        for(i=0;i<16;i++) {
            sprites[i].y=0xd0;
            sprites[i].x=0;
            sprites[i].pattern=0;
            sprites[i].colour=0;
        }
        return;
    }

    offset=0;
    for(i=0;i<count;i++) {
        byte *sp;
        sp=(byte *)(sprites+offset);
        offset+=showFrame(sp,minigameState[i].x,minigameState[i].y,minigameState[i].frame);
    }
    if(minigameMode==MM_WON) {
        offset+=showFrame((byte *)(sprites+offset),110,32,FT_WON);
    } else if(minigameMode==MM_LOST) {
        offset+=showFrame((byte *)(sprites+offset),110,32,FT_LOST);
    }
    while(offset<16) {
        sprites[offset].y=0xd0;
        offset++;
    }
}

void initRedBalloon()
{

}

void updateRedBalloon()
{

}

void initJumpHurdles()
{
    struct MinigameState *s=minigameState+0;
    s->x=32;    // MC
    s->y=105;
    s->state=0;
    s->frame=FT_RUN; // running
    s->frameTimer=1;
    s++;
    s->x=240;   // hurdle
    s->y=105;
    s->state=0;
    s->frame=FT_HURDLE;
}

void updateJumpHurdles()
{
    struct MinigameState *mc=minigameState+0;
    struct MinigameState *hurdle=minigameState+1;
    if(hurdle->x==0 || mc->x>240) {
        // game over
        activeMinigame=MGT_NONE;
    } else {
        hurdle->x-=1;
    }
    if(mc->state==0) {  // just running
        mc->x+=1;
        if(joypad_1&FIRE1 && !(lastJoypad1&FIRE1)) mc->state=0xf0; // jumping
        if(mc->frameTimer>0) {
            mc->frameTimer--;
        } else {
            mc->frame++;
            mc->frameTimer=1;
        }
        if(mc->frame>FT_RUNEND) mc->frame=FT_RUN;
        if(mc->x>hurdle->x-12 && mc->x<hurdle->x+12) {
            // collision: play_sound(SFX_OUCH);
            minigameMode=MM_LOST;
			hurdle->frame=FT_HURDLEFALL;
        }
    } else {    // jumping
        mc->x+=1;
        mc->y+=mc->state;
        mc->state+=2;
        if(mc->state>0x110) mc->state=0;    // done jump
        mc->frame=FT_JUMP;
        mc->frameTimer=1;
    }
    // Loss condition
    if(mc->x>hurdle->x-12 && mc->x<hurdle->x+12 && mc->y>82) {
        // collision: play_sound(SFX_OUCH);
        minigameMode=MM_LOST;
		hurdle->frame=FT_HURDLEFALL;
    }
    // Win condition
    if(minigameMode==MM_PLAY && mc->state==0 && mc->x>=hurdle->x+16) {
        minigameMode=MM_WON;
    }

    buildSpriteState(2);
}

void initThrowDisc()
{

}

void updateThrowDisc()
{

}

void initKickball()
{

}

void updateKickball()
{

}

void initVacuum()
{

}
void updateVacuum()
{

}

void initPunchBoxer()
{

}

void updatePunchBoxer()
{

}

void initShakePopcorn()
{

}
void updateShakePopcorn()
{

}

void pick_minigames()
{
	activeMinigame=rnd(1,7);
	activeMinigame=MGT_JUMPHURDLES;     // only one implemented for now.

    setMinigameMode(MM_INSTRUCTIONS);
}

void init_minigames()
{
    int i;

	setMinigameMode(MM_PLAY);
	screen_off();
	screen_mode_2_bitmap();
	sprites_16x16();

    for(i=0;i<16;i++) sprites[i].y=0xd0;
    updatesprites(0,16);

    if(activeMinigame<=MGT_KICKBALL) {
        brle2vram(track_bitmapPatBIGRUN,0x0000);
        brle2vram(track_bitmapColBIGRUN,0x2000);
    } else {
        brle2vram(house_bitmapPatBIGRUN,0x0000);
        brle2vram(house_bitmapColBIGRUN,0x2000);
    }

#if 0
    screen_mode_1_text();
    load_ascii();
    fill_color(0,0xf3,32);
    cls();
    print_at(2,3,(char *)minigameInstruction[activeMinigame]);
#endif
	load_spatternrle(spritePatRLE);

	lastJoypad1=0;
	lastJoypad2=0;

    switch(activeMinigame) {
    case MGT_REDBALLOON:
        initRedBalloon();
        break;
    case MGT_JUMPHURDLES:
        initJumpHurdles();
        break;
    case MGT_THROWDISC:
        initThrowDisc();
        break;
    case MGT_KICKBALL:
        initKickball();
        break;
    case MGT_VACUUM:
        initVacuum();
        break;
    case MGT_PUNCHBOXER:
        initPunchBoxer();
        break;
    case MGT_SHAKEPOPCORN:
        initShakePopcorn();
        break;
    }

	screen_on();
}

void update_minigames()
{
    switch(activeMinigame) {
    case MGT_REDBALLOON:
        updateRedBalloon();
        break;
    case MGT_JUMPHURDLES:
        updateJumpHurdles();
        break;
    case MGT_THROWDISC:
        updateThrowDisc();
        break;
    case MGT_KICKBALL:
        updateKickball();
        break;
    case MGT_VACUUM:
        updateVacuum();
        break;
    case MGT_PUNCHBOXER:
        updatePunchBoxer();
        break;
    case MGT_SHAKEPOPCORN:
        updateShakePopcorn();
        break;
    }
    lastJoypad1=joypad_1;
    lastJoypad2=joypad_2;
}

void draw_minigames()
{
    updatesprites(0,16);    // purely sprite based?
}

int is_minigame_done()
{
	return activeMinigame==MGT_NONE;	// all done
}

