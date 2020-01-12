/********************************************/
/*  GRAPHICS TABLES
/*  MADE WITH CVPAINT 2
/********************************************/
#include <coleco.h>

const byte spritePatRLE[] = {
    0x81,0x00,0x09,0x07,0x08,0x10,0x10,0x23,0x27,0x2f,0x3f,0x3f,0x1f,0x82,0x0f,0x14,0x07,0x00,0x00,0xc0,0x20,0x20,0x10,0xf8,0xe0,0x30,0x70,0xf0,0xe0,0xe0,0xc0,0xc0,
    0x80,0x07,0x0f,0x0f,0x0a,0x85,0x17,0x82,0x16,0x03,0x10,0x33,0x3f,0xe0,0x82,0xf0,0x85,0x70,0x02,0x60,0xe0,0xe0,0x82,0xc0,0x03,0x07,0x0f,0x0f,0x0a,0x83,0x17,0x08,
    0x1b,0x1d,0x1d,0x1e,0x1f,0x1f,0x3f,0x3f,0xe0,0x82,0xf0,0x82,0x70,0x05,0xb0,0xd0,0xe0,0xd0,0xa0,0x60,0x82,0xc0,0x81,0x1f,0x00,0x3e,0x82,0x3d,0x81,0x39,0x07,0x3b,
    0x7b,0x73,0x73,0x7d,0x7f,0x7e,0x00,0x87,0xe0,0x84,0xc0,0x81,0xf0,0x10,0x00,0x1f,0x1f,0x0d,0x02,0x03,0x02,0x01,0x03,0x07,0x0f,0x0e,0x0f,0x07,0x03,0x05,0x00,0x82,
    0xe0,0x82,0xf0,0x19,0xe0,0xc0,0xa0,0x40,0xc0,0x40,0x80,0x60,0xe0,0x00,0x1f,0x1f,0x0f,0x03,0x03,0x01,0x06,0x06,0x07,0x0f,0x0e,0x1e,0x1c,0x3f,0x3f,0x00,0x82,0xe0,
    0x82,0xf0,0x05,0xf8,0x78,0x7c,0x78,0x78,0x7c,0x82,0x3f,0x0a,0x00,0x1f,0x1f,0x0f,0x03,0x03,0x01,0x07,0x06,0x07,0x0f,0x82,0x0e,0x02,0x07,0x00,0x00,0x83,0xe0,0x81,
    0xd0,0x86,0xf0,0x81,0xfc,0x03,0x00,0x7f,0x7f,0x3f,0x84,0x1f,0x00,0x3e,0x83,0x2e,0x81,0x37,0x02,0x00,0x80,0x80,0x8a,0x00,0x81,0xc0,0x13,0x00,0x1f,0x1f,0x1c,0x3c,
    0x7c,0x78,0x70,0xf0,0xf0,0xf1,0xf1,0x78,0x38,0x30,0x00,0x00,0xf0,0xf8,0xf8,0x82,0x78,0x81,0xf0,0x82,0xe0,0x81,0xf0,0x81,0x30,0x05,0x00,0x70,0x7c,0x7f,0x3f,0x31,
    0x88,0x30,0x83,0x00,0x04,0x80,0xe0,0xf8,0x7e,0x1e,0x88,0x0c,0x10,0x03,0x07,0x0f,0x1f,0x3f,0x7b,0x73,0x7d,0x3e,0x1d,0x0b,0x17,0x1f,0x1f,0x3f,0x3f,0xe0,0x87,0xf0,
    0x82,0xe0,0x83,0xc0,0x83,0x00,0x02,0x03,0x07,0x0f,0x84,0x1f,0x03,0x0f,0x07,0x01,0x03,0x83,0x00,0x0d,0x80,0xc0,0x60,0xb0,0xb0,0xf0,0xf0,0xe0,0xc0,0x80,0x00,0x80,
    0x01,0x01,0x85,0x00,0x82,0x01,0x0d,0x03,0x06,0x04,0x04,0x0c,0x00,0x00,0x80,0x40,0x60,0x60,0x40,0xc0,0x80,0x86,0x00,0x83,0x02,0x01,0x04,0x0c,0x82,0x08,0x02,0x0c,
    0x04,0x06,0x82,0x02,0x94,0x00,0x02,0x07,0x1f,0x7f,0x82,0xff,0x01,0x7f,0x1e,0x87,0x00,0x06,0xf0,0xbc,0xcc,0xfc,0xf8,0xf0,0xc0,0x88,0x00,0x0a,0x07,0x0c,0x1e,0x1b,
    0x33,0x3e,0x3e,0x33,0x3b,0x1f,0x07,0x84,0x00,0x18,0xe0,0x60,0xf0,0x98,0xb8,0x78,0xf0,0x30,0x60,0xe0,0xc0,0x00,0xf0,0xfc,0xfe,0xfe,0xff,0x7f,0x3f,0x1f,0x1f,0x0f,
    0x03,0x03,0x00,0x82,0x01,0x84,0x00,0x02,0x80,0xe0,0xe0,0x83,0xf0,0x03,0x70,0xfe,0xff,0xff,0x83,0x00,0x03,0x07,0x0f,0x1f,0x1f,0x84,0x3f,0x01,0x1f,0x07,0x84,0x00,
    0x0a,0xe0,0xe0,0xf0,0xf8,0xf8,0xf8,0xf0,0xf0,0xe0,0xe0,0xc0,0x8a,0x00,0x81,0x01,0x8d,0x00,0x0a,0xe0,0xf8,0x3c,0x0e,0x07,0x03,0xff,0xff,0x00,0x00,0x0f,0x82,0x04,
    0x00,0x0f,0x82,0x0c,0x81,0x00,0x83,0xff,0x81,0x00,0x04,0x8c,0x93,0x13,0x13,0x1f,0x82,0x13,0x81,0x00,0x83,0xff,0x81,0x00,0x00,0x73,0x86,0x31,0x81,0x00,0x83,0xff,
    0x81,0x00,0x86,0x80,0x02,0xf8,0x00,0x00,0x83,0xff,0x81,0x00,0x00,0x1c,0x82,0x0c,0x81,0x0d,0x03,0x0e,0x0c,0x00,0x00,0x83,0xff,0x81,0x00,0x00,0x63,0x84,0x66,0x03,
    0xe6,0x63,0x00,0x00,0x83,0xff,0x81,0x00,0x00,0xe7,0x85,0x33,0x02,0xe3,0x00,0x00,0x83,0xff,0x81,0x00,0x0f,0x18,0x98,0x98,0x58,0x58,0x38,0x38,0x18,0x00,0x00,0xff,
    0xff,0x00,0x00,0xff,0xff,0x87,0x00,0x81,0x3f,0x82,0x00,0x0d,0x60,0xe0,0xf0,0x70,0x38,0x38,0x1c,0x1c,0x0c,0x0e,0x0e,0xff,0xff,0x07,0xfe,0x00,0xfe,0x00,0xfe,0x00,
    0xfe,0x00,0xfe,0x00,0xfe,0x00,0xfe,0x00,0xfe,0x00,0xfe,0x00,0xfe,0x00,0x8a,0x00,0xff};


const byte spriteAttr0[] = {
    0x69,0xa1,0x24,0x0f,0xd0};

const byte spriteAttr1[] = {
    0x78,0x6f,0x0c,0x06,0x58,0x72,0x00,0x09,0x68,0x70,0x04,0x05,0xd0};

const byte spriteAttr2[] = {
    0x79,0x6e,0x10,0x06,0x59,0x71,0x00,0x09,0x69,0x6f,0x08,0x05,0xd0};

const byte spriteAttr3[] = {
    0x78,0x6e,0x14,0x06,0x58,0x71,0x00,0x09,0x68,0x6f,0x04,0x05,0xd0};

const byte spriteAttr4[] = {
    0x78,0x6e,0x18,0x06,0x58,0x71,0x00,0x09,0x68,0x6f,0x28,0x05,0xd0};

const byte spriteAttr5[] = {
    0x79,0x71,0x1c,0x06,0x59,0x72,0x00,0x09,0x69,0x70,0x04,0x05,0xd0};

const byte spriteAttr6[] = {
    0x7a,0x6e,0x20,0x06,0x59,0x72,0x00,0x09,0x6a,0x70,0x28,0x05,0xd0};

const byte spriteAttr7[] = {
    0x53,0x7a,0x2c,0x08,0x65,0x7a,0x30,0x0f,0xd0};

const byte spriteAttr8[] = {
    0x5d,0x4d,0x2c,0x0a,0x6f,0x4e,0x34,0x0f,0xd0};

const byte spriteAttr9[] = {
    0x75,0x7e,0x38,0x03,0xd0};

const byte spriteAttr10[] = {
    0x7b,0x7b,0x3c,0x0f,0x7a,0x7b,0x44,0x01,0xd0};

const byte spriteAttr11[] = {
    0x5e,0x66,0x40,0x08,0x4e,0x58,0x48,0x06,0xd0};

const byte spriteAttr12[] = {
    0x19,0x5a,0x4c,0x01,0x19,0x6a,0x50,0x01,0xd0};

const byte spriteAttr13[] = {
    0x16,0x68,0x54,0x01,0x16,0x78,0x58,0x01,0xd0};

const byte spriteAttr14[] = {
    0x83,0x8c,0x5c,0x0f,0xd0};


const byte const *frame[]={
	spriteAttr0,spriteAttr1,spriteAttr2,spriteAttr3,
    spriteAttr4,spriteAttr5,spriteAttr6,spriteAttr7,
    spriteAttr8,spriteAttr9,spriteAttr10,spriteAttr11,
    spriteAttr12,spriteAttr13,spriteAttr14,
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
