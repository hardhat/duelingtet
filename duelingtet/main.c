#include <coleco.h>
#include <getput1.h>

#include "minigames.h"

extern const byte bitmapColRLE[];
extern byte NAMERLE[];
extern byte SPATTERNRLE[];
extern byte PATTERNRLE[];
extern byte COLORRLE[];
extern byte SPRITESINIT[];
extern int SPRITESINITSIZE;

#define MAPLEFT 2
#define MAPTOP 5

char level;		// current level
#define MAX_LEVELTIMER 24*32
#define LEVELTIMER_SHIFT 5
int levelTimer;
int score;		// score/100
byte mapState[16*16];	// with tile state updates: one bit per tile.
int drawScreen;

#define NO_TILE 255
struct Player {
    unsigned int score;
    byte tile;
    byte lastTile,lastCol,lastRow;
    byte isAI;
    int newTargetTimer;
    byte targetX,targetY;
} player[2];

struct Tile {
	char width,height;
	char pattern[2];
	char color;
	char frame[8];
};

#define MAX_TILE 16
const struct Tile tile[MAX_TILE]={
	{ 4,1,{0xf},    0,{0x80,0x80,0x80,0x80,' ',' ',' ',' '}},		// cyan
	{ 3,2,{0x4,0x7},1,{' ',' ',0x81,' ',0x81,0x81,0x81,' '}},	// dark blue
	{ 3,2,{0x1,0x7},2,{0x82,' ',' ',' ',0x82,0x82,0x82,' '}},	// orange
	{ 2,2,{0x3,0x3},3,{0x83,0x83,' ',' ',0x83,0x83,' ',' '}},	// yellow
	{ 3,2,{0x6,0x3},4,{' ',0x84,0x84,' ',0x84,0x84,' ',' '}},	// green
	{ 3,2,{0x2,0x7},5,{' ',0x85,' ',' ',0x85,0x85,0x85,' '}},	// purple
	{ 3,2,{0x3,0x6},6,{0x86,0x86,' ',' ',' ',0x86,0x86,' '}},	// red

	{ 3,2,{0x7,0x1},1,{0x81,0x81,0x81,' ',0x81,' ',' ',' '}},	// dark blue
	{ 3,2,{0x7,0x4},2,{0x82,0x82,0x82,' ',' ',' ',0x82,' '}},	// orange
	{ 3,2,{0x7,0x2},5,{0x85,0x85,0x85,' ',' ',0x85,' ',' '}},	// purple

	{ 2,2,{0x3,0x1},3,{0x83,0x83,' ',' ',0x83,' ',' ',' '}},	// yellow
	{ 2,2,{0x3,0x2},3,{0x83,0x83,' ',' ',' ',0x83,' ',' '}},	// yellow
	{ 2,2,{0x1,0x3},3,{0x83,' ',' ',' ',0x83,0x83,' ',' '}},	// yellow
	{ 2,2,{0x2,0x3},3,{' ',0x83,' ',' ',0x83,0x83,' ',' '}},	// yellow

	{ 2,1,{0x3},    0,{0x80,0x80,' ',' ',' ',' ',' ',' '}},		// cyan
	{ 1,2,{0x1,0x1},0,{0x80,' ',' ',' ',0x80,' ',' ',' '}},		// cyan

};

#define MAXPIECE 12
#define MAX_PIECETIMER 32*12
#define MAX_NEWPIECETIMER 32
struct PieceTable {
	int status;	// where it is now
	char tile;	// what type of tile
} piece[MAXPIECE];
byte newPieceTimer;

void showtitle()
{
	screen_off();
	screen_mode_2_bitmap();
	show_picture(bitmapColRLE);
	screen_on();
}

void init()
{
	screen_off();
	screen_mode_2_bitmap();
	sprites_16x16();
    load_patternrle(PATTERNRLE);
    rle2vram(PATTERNRLE,0x800);
    rle2vram(PATTERNRLE,0x1000);
    load_colorrle(COLORRLE);
    rle2vram(COLORRLE,0x2800);
    rle2vram(COLORRLE,0x3000);
    load_spatternrle(SPATTERNRLE);
    load_namerle(NAMERLE);
	screen_on();
}

void newPlayer(int playerId)
{
    struct Player *p=player+playerId;

    p->score=0;
    p->lastTile=NO_TILE;
    p->tile=NO_TILE;
    p->isAI=0;
}

void newLevel()
{
    byte spat[32];
    int vaddr;
    int i;
    byte x,y;
    byte pos=0;
    byte mask;
    vaddr=0x3800+((level+9)<<5);
    get_vram(vaddr,spat,32);
    for(y=0;y<16;y++) {
        for(x=0;x<32;x+=16) {
            byte sp=spat[x+y];
            for(mask=128;mask>0;(mask>>=1)) {
               byte ch=(sp&mask)?0x87:0x88;
               mapState[pos++]=ch;
            }
        }
    }
    put_frame0(mapState,MAPLEFT,MAPTOP,16,16);

    for(i=0;i<MAXPIECE;i++) piece[i].status=0;

    levelTimer=MAX_LEVELTIMER;
    for(i=0;i<24;i++) put_char(31,i,171);

    print_at(11,0,str(level+1)+3);

    player[0].tile=NO_TILE;
    player[1].tile=NO_TILE;

    //play_sound(6); play_sound(7); // = Game Start
}

void clearSprites()
{
	int i;
	
	for(i=0;i<32;i++) {
		sprites[i].x=0;
		sprites[i].y=192;
		sprites[i].pattern=0;
		sprites[i].colour=0;
	}
}

void initSprites()
{
	clearSprites();
	
    sprites[0].x=16;
    sprites[0].y=48;
    sprites[0].colour=15;
    sprites[0].pattern=0;
    sprites[2].x=96;
    sprites[2].y=48;
    sprites[2].colour=1;
    sprites[2].pattern=0;
}

void newgame()
{
    int i;
    for(i=0;i<MAXPIECE;i++) {
        piece[i].status=0;
        piece[i].tile=0;
    }
	score=0;
    level=0;
    for(i=0;i<16*16;i++) {
        mapState[i]=0x87;
    }
    newLevel();

    newPlayer(0);
    newPlayer(1);
    player[1].isAI=1;

	initSprites();
}

void newPiece(int id)
{
    piece[id].status=MAX_PIECETIMER;
	piece[id].tile=rnd(0,MAX_TILE-1);
}

void updateSprites()
{
    signed char xx,yy;

    if(player[0].isAI==0) {
        if(joypad_1&UP) yy=-2;
        else if(joypad_1&DOWN) yy=2;
        else yy=0;
        if(joypad_1&LEFT) xx=-2;
        else if(joypad_1&RIGHT) xx=2;
        else xx=0;
        sprites[0].x+=xx;
        sprites[0].y+=yy;

        if(keypad_1<12) {
            int id=keypad_1;
            // grab the piece at this id.
            if(id==0) id=10; else if(id>9) id++;
            if(piece[id-1].status>0) {
                player[0].tile=piece[id-1].tile;
                piece[id-1].status=0;
            }
        }
    }

    if(player[1].isAI==0) {
        if(joypad_2&UP) yy=-2;
        else if(joypad_2&DOWN) yy=2;
        else yy=0;
        if(joypad_2&LEFT) xx=-2;
       else if(joypad_2&RIGHT) xx=2;
        else xx=0;
        sprites[2].x+=xx;
        sprites[2].y+=yy;

        if(keypad_2<12) {
            int id=keypad_2;
            // grab the piece at this id.
            if(id==0) id=10; else if(id>9) id++;
            if(piece[id-1].status>0) {
                player[1].tile=piece[id-1].tile;
                piece[id-1].status=0;
            }
        }
    }
}

void updatePiece()
{
    byte i;
    for(i=0;i<MAXPIECE;i++) {
        if(piece[i].status>0) piece[i].status--;
    }
    if(newPieceTimer>0) {
        newPieceTimer--;
    } else {
        if(levelTimer==0) return;   // game over
        newPieceTimer=MAX_NEWPIECETIMER;
        for(i=0;i<MAXPIECE;i++) {
            if(piece[i].status==0) break;
        }
        if(i<MAXPIECE) newPiece(i);
    }
}

int getMapState(int x,int y)
{
    if(x<0 || y<0 || x>15 || y>15) return 8;    // solid block for out of bounds
    return mapState[x+(y<<4)];
}

void setMapState(int x,int y,int tileNo)
{
    if(x<0 || y<0 || x>15 || y>15) return;    // out of bounds
    mapState[x+(y<<4)]=tileNo;
}

void drawTile(int x,int y,int tileNo)
{
	const struct Tile *t=tile+tileNo;
	int i,j;
	for(j=0;j<t->height;j++) {
		for(i=0;i<t->width;i++) {
			unsigned char p=t->pattern[j];
			if(p & (1<<i)) {
				put_char(i+x,j+y,128+tileNo);
			}
		}
	}
}

int fitsMapTile(int x,int y,int tileNo)
{
	const struct Tile *t=tile+tileNo;
	int i,j;
	for(j=0;j<t->height;j++) {
        unsigned char p=t->pattern[j];
		for(i=0;i<t->width;i++) {
			if(p & (1<<i)) {
                if(getMapState(i+x,j+y)!=0x87) return 0; // not empty space=no.
			}
		}
	}
	return 1;    // Yes.
}

void previewMapTile(int x,int y,int tileNo)
{
	const struct Tile *t=tile+tileNo;
	int color=t->color;
	int i,j;
	if(x<0 || y<0 || x+t->width>16 || y+t->height>16) return;   // clipping
	for(j=0;j<t->height;j++) {
		for(i=0;i<t->width;i++) {
			unsigned char p=t->pattern[j];
			if(p & (1<<i)) {
                if(getMapState(i+x,j+y)!=0x87) {
                    if(i+x<0 || j+y<0 || i+x>15 || j+y>15) continue;  // clipping
                    put_char(MAPLEFT+i+x,MAPTOP+j+y,0xb0+color);  // greyed
                } else {
                    put_char(MAPLEFT+i+x,MAPTOP+j+y,128+color);   // solid
                }
			}
		}
	}
}

void unpreviewMapTile(int x,int y,int tileNo)
{
	const struct Tile *t=tile+tileNo;
	int i,j;
	for(j=0;j<t->height;j++) {
		for(i=0;i<t->width;i++) {
			unsigned char p=t->pattern[j];
			if(p & (1<<i)) {
                if(i+x<0 || j+y<0 || i+x>15 || j+y>15) continue;  // clipping
                    put_char(MAPLEFT+i+x,MAPTOP+j+y,getMapState(i+x,j+y));  // current
			}
		}
	}
}

void setMapTile(int x,int y,int tileNo)
{
	const struct Tile *t=tile+tileNo;
	int color=t->color;
	int i,j;
	for(j=0;j<t->height;j++) {
		for(i=0;i<t->width;i++) {
			unsigned char p=t->pattern[j];
			if(p & (1<<i)) {
				put_char(MAPLEFT+i+x,MAPTOP+j+y,128+color);
				setMapState(i+x,j+y,0x80+color);
			}
		}
	}
}

void drawPlayerTile(int playerId)
{
    int tileNo;
    int mapX,mapY;
    struct Player *p=player+playerId;

    if(p->tile==NO_TILE) {
            print_at(playerId==0?3:12,1,str(p->score));
            return;
    }

    tileNo=p->tile;
    mapX=sprites[playerId<<1].x;
    mapY=sprites[playerId<<1].y;

    mapX>>=3;
    mapY>>=3;

    mapX-=MAPLEFT;
    mapY-=MAPTOP;
    if(tileNo==p->lastTile && mapX==p->lastCol && mapY==p->lastRow) return;

    if(p->lastTile!=NO_TILE) {
        unpreviewMapTile(p->lastCol,p->lastRow,p->lastTile);
    }
    previewMapTile(mapX,mapY,tileNo);
    p->lastTile=tileNo;
    p->lastCol=mapX;
    p->lastRow=mapY;
}

void drawMap(int pass)
{
	int i;
	const char *blank="        ";
	const char *frame;

    // Free Piece Bar
    for(i=0;i<6;i++) {
        if(pass==0) {
            frame=blank;
            if(piece[i].status>0) frame=tile[piece[i].tile].frame;
            put_frame0(frame,22,1+3*i,4,2);
            put_char(21,2+3*i,0x8f+(piece[i].status>>4));
        }

        if(pass==1) {
            frame=blank;
            if(piece[i+6].status>0) frame=tile[piece[i+6].tile].frame;
            put_frame0(frame,27,1+3*i,4,2);
            put_char(26,2+3*i,0x8f+(piece[i+6].status>>4));
        }
    }

    if((levelTimer&31)==0) put_char(31,levelTimer>>LEVELTIMER_SHIFT,' ');
    if(levelTimer==MAX_LEVELTIMER-1) for(i=0;i<24;i++) put_char(31,i,171);

    if(pass==2) {
        /*
        print_at(21,19,str(piece[7].status));
        print_at(21,20,str(piece[7].tile));
        put_frame0(tile[piece[7].tile].frame,21,21,4,2);
        */

        /*
        print_at(21,19,str(player[1].tile));
        print_at(21,20,str(player[1].targetX));
        print_at(21,21,str(player[1].targetY));
        print_at(21,22,str(sprites[2].x)+2);
        print_at(21,23,str(sprites[2].y)+2);
        */
    }
    // Player placement
    drawPlayerTile(0);
    drawPlayerTile(1);
}

void setPlayerTileTarget(int playerNo,int tileNo)
{
    int count;
    int i,j;

    for(count=0;count<3;count++) {
        i=rnd(0,15-tile[tileNo].width);
        j=rnd(0,15-tile[tileNo].height);

        if(fitsMapTile(i,j,tileNo)) {
                player[playerNo].tile=tileNo;
                player[playerNo].targetX=(MAPLEFT+i)<<3;
                player[playerNo].targetY=(MAPTOP+j)<<3;
                return;
        }
    }
}

void updateAI(int playerNo,int pass)
{
    struct Player *p=player+playerNo;

    // try to place it
    if(p->newTargetTimer>0) {
		p->newTargetTimer--;
    } else if(p->lastTile == p->tile && p->lastTile!=NO_TILE) {
        if(fitsMapTile(p->lastCol,p->lastRow,p->lastTile)) {
            setMapTile(p->lastCol,p->lastRow,p->lastTile);
            p->score+=4;    // todo calculate
            p->tile=NO_TILE;
            p->newTargetTimer=60;
            levelTimer=MAX_LEVELTIMER;
            // Chime sound.
            return;
        }
    }

    // otherwise make it happen.
    if(p->tile==NO_TILE) {
        // Try to find a tile that'll work.
        int tileNo;
        int pieceNo=rnd(0,MAXPIECE-1);
        if(piece[pieceNo].status>0 && piece[pieceNo].status<MAX_PIECETIMER-60) {
            tileNo=piece[pieceNo].tile;

            setPlayerTileTarget(playerNo,tileNo);
            if(p->tile==tileNo) piece[pieceNo].status=0;
        }
        return;
    }
    // Moving pointer to the target x,y.
    if(p->targetX==sprites[playerNo+playerNo].x && p->targetY==sprites[playerNo+playerNo].y) p->tile=NO_TILE;   // try to pick a new one.

    if(p->newTargetTimer>0) return;
    if(pass==2) return;
    if(p->targetX<sprites[playerNo+playerNo].x) sprites[playerNo+playerNo].x--;
    if(p->targetX>sprites[playerNo+playerNo].x) sprites[playerNo+playerNo].x++;
    if(p->targetY<sprites[playerNo+playerNo].y) sprites[playerNo+playerNo].y--;
    if(p->targetY>sprites[playerNo+playerNo].y) sprites[playerNo+playerNo].y++;

    /*
    // speed demon
    sprites[playerNo+playerNo].x=p->targetX;
    sprites[playerNo+playerNo].y=p->targetY;
    */

}

void updatePlayer(int playerNo)
{
    struct Player *p=player+playerNo;

    if(joypad_1&FIRE1) {
        // try to place it
        if(p->lastTile == p->tile && p->lastTile!=NO_TILE) {
            if(fitsMapTile(p->lastCol,p->lastRow,p->lastTile)) {
                setMapTile(p->lastCol,p->lastRow,p->lastTile);
                p->score+=4;    // todo calculate
                p->tile=NO_TILE;
                levelTimer=MAX_LEVELTIMER;
                // Chime sound.
                //stop_sound(3); play_sound(2); play_sound(3); // = Swing
            } else {
                // otherwise buzz sound.
                //play_sound(4); // = hit
            }
        } else {
            // otherwise buzz sound.
            //play_sound(4); // = hit
        }
    }
}

void bonus_level()
{
	int i;
	
	pick_minigames();

	disable_nmi();
	screen_mode_1_text();
	fill_color(0,0xf3,32);
	load_ascii();
	clearSprites();
	updatesprites(0,31);

	cls();
	print_at(8,8,"GET READY PLAYER 1");
	print_at(8,10,(char *)getMinigameName());

	print_at(2,12,(char *)getMinigameInstruction());
    screen_on();
    enable_nmi();
    delay(120);

    init_minigames();

    while(is_minigame_done()==0) {
        update_minigames();

        disable_nmi();
        draw_minigames();
        enable_nmi();

        delay(1);
    }

	disable_nmi();
	screen_mode_1_text();
	fill_color(0,0xf3,32);
	load_ascii();
	clearSprites();
	updatesprites(0,31);
	cls();
	print_at(8,8,"LEVEL SUMMARY");
	print_at(8,10,(char *)getMinigameName());

	print_at(8,12,"BONUS POINTS EARNED:");
    screen_on();
    enable_nmi();

	for(i=0;i<120;i++) {
		print_at(0,13,str(get_minigame_score()*i/120));
		delay(1);
	}
	delay(60);

	player[0].score+=get_minigame_score();
}

void main()
{
	int pass=0;
#if 1
	disable_nmi();
	showtitle();
	enable_nmi();
	delay(120);
	//disable_nmi();
#endif


	disable_nmi();
	init();
	newgame();
	enable_nmi();
	//drawScreen=0x400;
	//screen(name_table1,name_table2);
	while(1) {
		disable_nmi();
        //print_at(0,0,"    LEVEL 01 ");
        updatesprites(0,3);
		drawMap(pass);
		pass++;
		if(pass==3) {
			//swap_screen();
			//drawScreen=0x400-drawScreen;
			pass=0;
		}

		enable_nmi();

		// update the state of the character.
		if(player[0].isAI==0) {
            updatePlayer(0);
        } else {
            updateAI(0,pass);
        }
		if(player[1].isAI==0) {
            updatePlayer(1);
        } else {
            updateAI(1,pass);
        }
		updateSprites();
		updatePiece();
        if(levelTimer>0) {
            levelTimer--;

            if(levelTimer==0) {
                if(level==16) {
                    print_at(5,3,"GAME OVER");
                    //play_sound(5); // = You lose
                } else {
                    //play_sound(1); // = You win
                }
            }
        }
        if(levelTimer==0 && level<16) {
            level++;
			
			if((level%5)==0) bonus_level();

			disable_nmi();
			init();
			initSprites();
			enable_nmi();
			
            newLevel();
        }

		delay(1);
	}
}

void nmi()
{

}

/*
const byte sound1[]={0xff};

const struct Sound {
	const byte *sound;
	byte *table;
} snd_table[]={
	{sound1,SOUNDAREA1},
};
*/
