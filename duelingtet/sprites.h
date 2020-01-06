extern const byte spritePatRLE[];
int showFrame(byte *sp, int x,int y,int f);

enum SpriteFrameType {
    FT_HURDLE,
    FT_RUN,
    FT_RUNEND=5,
    FT_JUMP,
    FT_REDBALLOON,
    FT_YELLOWBALLOON,
    FT_DISC,    // flying disc
    FT_SOCCERBALL,
    FT_VACUUM,
    FT_LOST,
    FT_WON,
};
/*

const byte const *frame[]={
	spriteAttr0,spriteAttr1,spriteAttr2,spriteAttr3,
    spriteAttr4,spriteAttr5,spriteAttr6,spriteAttr7,
    spriteAttr8,spriteAttr9,spriteAttr10,spriteAttr11,
    spriteAttr12,spriteAttr13,
};

int showFrame(byte *sp, int x,int y,int f)
{
	byte i;

	//byte *sp=(byte *)sprites;
	const byte *src=frame[f];

	byte basex=src[1],basey=src[0];

	for(i=0;src[i]!=0xd0;) {
		*sp=src[i]-basey+y; sp++; i++;
		*sp=src[i]-basex+x; sp++; i++;
		*(sp++)=src[i++];
		*(sp++)=src[i++];
	}
	return i>>2;
}
*/
