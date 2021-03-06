/********************************************/
/*                                          */
/*   GRAPHICS TABLES  -  WIN ICVGM v3.00    */
/*                                          */
/*        WARNING : RLE COMPRESSION         */
/*                                          */
/********************************************/

#include <coleco.h>

const byte NAMERLE[] = {
  0x83, 0x20, 0x08, 0x4C, 0x45, 0x56, 0x45, 0x4C, 0x20, 0x20, 0x30, 0x31, 0x84, 0x20, 0x01,
  0x0A, 0x02, 0x8A, 0x20, 0x03, 0x06, 0x50, 0x31, 0x20, 0x84, 0x30, 0x03, 0x20, 0x50, 0x32, 0x20,
  0x84, 0x30, 0x04, 0x20, 0x0A, 0x02, 0x20, 0x31, 0x82, 0x82, 0x01, 0x20, 0x37, 0x83, 0x86, 0x00,
  0x06, 0x92, 0x0A, 0x07, 0x02, 0x20, 0x95, 0x20, 0x82, 0x20, 0x20, 0xA7, 0x83, 0x20, 0x00, 0x06,
  0x92, 0x0A, 0x00, 0x02, 0x8A, 0x20, 0x02, 0x06, 0x0A, 0x01, 0x8F, 0x04, 0x03, 0x05, 0x02, 0x20,
  0x32, 0x83, 0x20, 0x00, 0x38, 0x83, 0x20, 0x02, 0x06, 0x0A, 0x02, 0x8F, 0x88, 0x01, 0x06, 0x02,
  0x8A, 0x20, 0x02, 0x06, 0x0A, 0x02, 0x8F, 0x88, 0x01, 0x06, 0x02, 0x8A, 0x20, 0x02, 0x06, 0x0A,
  0x02, 0x8F, 0x88, 0x03, 0x06, 0x02, 0x20, 0x33, 0x83, 0x20, 0x00, 0x39, 0x83, 0x20, 0x02, 0x06,
  0x0A, 0x02, 0x89, 0x88, 0x83, 0x87, 0x81, 0x88, 0x01, 0x06, 0x02, 0x8A, 0x20, 0x02, 0x06, 0x0A,
  0x02, 0x88, 0x88, 0x85, 0x87, 0x02, 0x88, 0x06, 0x02, 0x8A, 0x20, 0x02, 0x06, 0x0A, 0x02, 0x88,
  0x88, 0x86, 0x87, 0x03, 0x06, 0x02, 0x20, 0x34, 0x83, 0x20, 0x00, 0x30, 0x83, 0x20, 0x02, 0x06,
  0x0A, 0x02, 0x88, 0x88, 0x84, 0x87, 0x81, 0x88, 0x01, 0x06, 0x02, 0x8A, 0x20, 0x02, 0x06, 0x0A,
  0x02, 0x89, 0x88, 0x82, 0x87, 0x82, 0x88, 0x01, 0x06, 0x02, 0x8A, 0x20, 0x02, 0x06, 0x0A, 0x02,
  0x89, 0x88, 0x82, 0x87, 0x82, 0x88, 0x03, 0x06, 0x02, 0x20, 0x35, 0x83, 0x20, 0x00, 0x2A, 0x83,
  0x20, 0x02, 0x06, 0x0A, 0x02, 0x83, 0x88, 0x81, 0x87, 0x03, 0x89, 0x87, 0x81, 0x81, 0x83, 0x87,
  0x81, 0x88, 0x01, 0x06, 0x02, 0x8A, 0x20, 0x03, 0x06, 0x0A, 0x02, 0x88, 0x86, 0x87, 0x81, 0x81,
  0x84, 0x87, 0x02, 0x88, 0x06, 0x02, 0x8A, 0x20, 0x02, 0x06, 0x0A, 0x02, 0x82, 0x87, 0x81, 0x84,
  0x82, 0x87, 0x00, 0x86, 0x82, 0x87, 0x07, 0x82, 0x87, 0x87, 0x88, 0x06, 0x02, 0x20, 0x36, 0x83,
  0x20, 0x00, 0x23, 0x83, 0x20, 0x03, 0x06, 0x0A, 0x02, 0x88, 0x82, 0x87, 0x81, 0x84, 0x81, 0x87,
  0x00, 0x86, 0x82, 0x87, 0x81, 0x82, 0x81, 0x88, 0x03, 0x06, 0x02, 0x20, 0x8F, 0x88, 0x20, 0x03,
  0x06, 0x0A, 0x02, 0x88, 0x86, 0x87, 0x00, 0x86, 0x82, 0x87, 0x00, 0x82, 0x82, 0x88, 0x01, 0x06,
  0x02, 0x8A, 0x20, 0x02, 0x06, 0x0A, 0x02, 0x83, 0x88, 0x83, 0x87, 0x02, 0x86, 0x87, 0x87, 0x84,
  0x88, 0x01, 0x06, 0x02, 0x8A, 0x20, 0x02, 0x06, 0x0A, 0x02, 0x8F, 0x88, 0x01, 0x06, 0x02, 0x8A,
  0x20, 0x02, 0x06, 0x0A, 0x03, 0x8F, 0x08, 0x01, 0x07, 0x02, 0x8A, 0x20, 0x00, 0x06, 0x92, 0x0A,
  0x00, 0x02, 0x8A, 0x20, 0x00, 0x06, 0x84, 0x0A, 0x0A, 0x44, 0x55, 0x45, 0x4C, 0x49, 0x4E, 0x47,
  0x20, 0x54, 0x45, 0x54, 0x82, 0x0A, 0x00, 0x02, 0x8A, 0x20, 0x00, 0x06, 0xFF};

const byte PATTERNRLE[] = {
  0x8D, 0x00, 0x8B, 0x03, 0x8B, 0x00, 0x81, 0xFF, 0x85, 0x00, 0x8B, 0xC0, 0x85, 0x00, 0x81,
  0xFF, 0xFE, 0x00, 0xC6, 0x00, 0x07, 0x18, 0x3C, 0x3C, 0x18, 0x00, 0x00, 0x18, 0x00, 0x82, 0x66,
  0x84, 0x00, 0x81, 0x66, 0x20, 0xFF, 0x66, 0xFF, 0x66, 0x66, 0x00, 0x18, 0x3E, 0x60, 0x3C, 0x06,
  0x7C, 0x18, 0x00, 0xFF, 0x81, 0xB9, 0xA5, 0xB9, 0xA5, 0x81, 0xFF, 0x3C, 0x66, 0x3C, 0x38, 0x67,
  0x66, 0x3F, 0x00, 0x06, 0x0C, 0x18, 0x84, 0x00, 0x01, 0x0C, 0x18, 0x82, 0x30, 0x04, 0x18, 0x0C,
  0x00, 0x30, 0x18, 0x82, 0x0C, 0x08, 0x18, 0x30, 0x00, 0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x82,
  0x00, 0x81, 0x18, 0x02, 0x7E, 0x18, 0x18, 0x85, 0x00, 0x81, 0x18, 0x00, 0x30, 0x83, 0x00, 0x00,
  0x7E, 0x88, 0x00, 0x81, 0x18, 0x81, 0x00, 0x09, 0x06, 0x0C, 0x18, 0x30, 0x60, 0xC0, 0x00, 0xFE,
  0xC6, 0xC6, 0x82, 0xE6, 0x03, 0xFE, 0x00, 0x38, 0x38, 0x82, 0x18, 0x81, 0x3C, 0x2C, 0x00, 0xFE,
  0x06, 0x06, 0xFE, 0xC0, 0xC0, 0xFE, 0x00, 0xFC, 0x0C, 0x0C, 0x7E, 0x0E, 0x0E, 0xFE, 0x00, 0xC0,
  0xC0, 0xC6, 0xC6, 0xFE, 0x06, 0x06, 0x00, 0xFE, 0xC0, 0xC0, 0xFE, 0x06, 0x06, 0xFE, 0x00, 0xFC,
  0xCC, 0xC0, 0xFE, 0xC6, 0xC6, 0xFE, 0x00, 0xFE, 0xC6, 0x0C, 0x18, 0x82, 0x38, 0x0C, 0x00, 0x7E,
  0x66, 0x66, 0xFE, 0xE6, 0xE6, 0xFE, 0x00, 0xFE, 0xC6, 0xC6, 0xFE, 0x82, 0x0E, 0x82, 0x00, 0x03,
  0x18, 0x00, 0x00, 0x18, 0x83, 0x00, 0x0C, 0x18, 0x00, 0x00, 0x18, 0x30, 0x00, 0x0C, 0x18, 0x30,
  0x60, 0x30, 0x18, 0x0C, 0x82, 0x00, 0x02, 0x7E, 0x00, 0x7E, 0x82, 0x00, 0x0E, 0x30, 0x18, 0x0C,
  0x06, 0x0C, 0x18, 0x30, 0x00, 0x3C, 0x66, 0x06, 0x0C, 0x18, 0x00, 0x18, 0x88, 0x00, 0x03, 0x7E,
  0x66, 0x66, 0x7E, 0x82, 0xE6, 0x11, 0x00, 0xFC, 0xCC, 0xCC, 0xFE, 0xC6, 0xC6, 0xFE, 0x00, 0xFE,
  0xCE, 0xCE, 0xC0, 0xC0, 0xC6, 0xFE, 0x00, 0xFC, 0x84, 0xE6, 0x0D, 0xFC, 0x00, 0xFE, 0xC0, 0xC0,
  0xF8, 0xE0, 0xE0, 0xFE, 0x00, 0xFE, 0xE0, 0xE0, 0xF8, 0x82, 0x60, 0x08, 0x00, 0xFE, 0xC6, 0xC0,
  0xC0, 0xCE, 0xC6, 0xFE, 0x00, 0x82, 0xC6, 0x00, 0xFE, 0x82, 0xE6, 0x00, 0x00, 0x82, 0x18, 0x83,
  0x38, 0x0C, 0x00, 0x3E, 0x0C, 0x0C, 0x0E, 0xCE, 0xCE, 0xFE, 0x00, 0xC6, 0xCC, 0xD8, 0xFE, 0x82,
  0xE6, 0x00, 0x00, 0x82, 0x60, 0x82, 0xE0, 0x05, 0xFE, 0x00, 0xC6, 0xEE, 0xFE, 0xD6, 0x82, 0xC6,
  0x04, 0x00, 0xE6, 0xF6, 0xDE, 0xCE, 0x82, 0xE6, 0x03, 0x00, 0xFE, 0xC6, 0xC6, 0x82, 0xCE, 0x05,
  0xFE, 0x00, 0xFE, 0xC6, 0xC6, 0xFE, 0x82, 0xE0, 0x01, 0x00, 0xFE, 0x83, 0xC6, 0x06, 0xCE, 0xFE,
  0x0F, 0xFC, 0xE6, 0xE6, 0xFC, 0x82, 0xCE, 0x0B, 0x00, 0xFE, 0xC6, 0xC0, 0xFE, 0x06, 0xE6, 0xFE,
  0x00, 0x7E, 0x18, 0x18, 0x83, 0x38, 0x00, 0x00, 0x82, 0xC6, 0x82, 0xCE, 0x01, 0xFE, 0x00, 0x84,
  0xC6, 0x02, 0x6C, 0x38, 0x00, 0x83, 0xC6, 0x0E, 0xD6, 0xFE, 0xEE, 0x00, 0xC6, 0xC6, 0x6C, 0x38,
  0x6C, 0xC6, 0xC6, 0x00, 0xC6, 0xC6, 0x6C, 0x83, 0x38, 0x07, 0x00, 0xFE, 0xCC, 0x18, 0x30, 0x60,
  0xC6, 0xFE, 0xFE, 0x00, 0xFE, 0x00, 0xAA, 0x00, 0x86, 0x01, 0x00, 0xFF, 0x86, 0x01, 0x00, 0xFF,
  0x86, 0x01, 0x00, 0xFF, 0x86, 0x01, 0x00, 0xFF, 0x86, 0x01, 0x00, 0xFF, 0x86, 0x01, 0x00, 0xFF,
  0x86, 0x01, 0x00, 0xFF, 0x86, 0x01, 0x88, 0xFF, 0xBE, 0x00, 0x00, 0x3C, 0x85, 0x00, 0x81, 0x3C,
  0x84, 0x00, 0x82, 0x3C, 0x83, 0x00, 0x83, 0x3C, 0x82, 0x00, 0x84, 0x3C, 0x81, 0x00, 0x85, 0x3C,
  0x00, 0x00, 0xFE, 0x3C, 0x8F, 0x3C, 0x83, 0x00, 0x1A, 0x70, 0x30, 0x10, 0x00, 0x40, 0xE0, 0xF0,
  0xF0, 0x70, 0x30, 0x10, 0x00, 0x40, 0xE0, 0xF0, 0xFE, 0x7C, 0x38, 0x10, 0x00, 0x44, 0xEE, 0xFE,
  0xFE, 0x7C, 0x38, 0x10, 0xA0, 0x00, 0x86, 0x01, 0x00, 0xFF, 0x86, 0x01, 0x00, 0xFF, 0x86, 0x01,
  0x00, 0xFF, 0x86, 0x01, 0x00, 0xFF, 0x86, 0x01, 0x00, 0xFF, 0x86, 0x01, 0x00, 0xFF, 0x86, 0x01,
  0x00, 0xFF, 0x86, 0x01, 0x00, 0xFF, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xC3, 0x00,
  0xFF};

const byte COLORRLE[] = {
  0x87, 0xF1, 0x90, 0xFC, 0x00, 0xEC, 0x8D, 0xFC, 0x9F, 0x1C, 0x87, 0x41, 0x87, 0x4C, 0xFE,
  0x41, 0xA8, 0x41, 0xFE, 0xF1, 0xFE, 0xF1, 0xFE, 0xF1, 0xDA, 0xF1, 0xFE, 0x41, 0xFE, 0x41, 0xA9,
  0x41, 0x87, 0xE7, 0x87, 0xE4, 0x87, 0xE9, 0x87, 0xEA, 0x87, 0xE3, 0x87, 0xED, 0x87, 0xE6, 0x8F,
  0xE1, 0xB7, 0x41, 0xBF, 0x61, 0xBF, 0xB1, 0xBF, 0x21, 0x9F, 0x61, 0x9F, 0x41, 0x3F, 0xE7, 0xE1,
  0xE7, 0xE1, 0xE7, 0xE1, 0xE7, 0xE7, 0xE4, 0xE1, 0xE4, 0xE1, 0xE4, 0xE1, 0xE4, 0xE4, 0xE9, 0xE1,
  0xE9, 0xE1, 0xE9, 0xE1, 0xE9, 0xE9, 0xEA, 0xE1, 0xEA, 0xE1, 0xEA, 0xE1, 0xEA, 0xEA, 0xE3, 0xE1,
  0xE3, 0xE1, 0xE3, 0xE1, 0xE3, 0xE3, 0xED, 0xE1, 0xED, 0xE1, 0xED, 0xE1, 0xED, 0xED, 0xE6, 0xE1,
  0xE6, 0xE1, 0xE6, 0xE1, 0xE6, 0xE6, 0xE1, 0xEE, 0xE1, 0xEE, 0xE1, 0xEE, 0xE1, 0xE1, 0xFE, 0x41,
  0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0xC3, 0x41, 0xFF};

const byte SPATTERNRLE[] = {
  0x81, 0xFC, 0x06, 0xF0, 0xF8, 0xDC, 0xCE, 0x07, 0x03, 0x01, 0x8D, 0x00, 0x03, 0x80, 0xC0,
  0xE0, 0x40, 0x84, 0x00, 0x86, 0xFE, 0x98, 0x00, 0x86, 0xFE, 0x88, 0x00, 0x86, 0xFE, 0x88, 0x00,
  0x86, 0xFE, 0x00, 0x00, 0x86, 0xFE, 0x90, 0x00, 0x86, 0xFE, 0x00, 0x00, 0x86, 0xFE, 0x00, 0x00,
  0x86, 0xFE, 0x88, 0x00, 0x86, 0xFE, 0x88, 0x00, 0x86, 0xFE, 0x00, 0x00, 0x86, 0xFE, 0x88, 0x00,
  0x86, 0xFE, 0x00, 0x00, 0x86, 0xFE, 0x00, 0x00, 0x86, 0xFE, 0x00, 0x00, 0x86, 0xFE, 0x00, 0x00,
  0x86, 0xFE, 0x88, 0x00, 0x86, 0xFE, 0x00, 0x00, 0x86, 0xFE, 0x00, 0x00, 0x86, 0xFE, 0x00, 0x00,
  0x86, 0xFE, 0x00, 0x00, 0x86, 0xFE, 0x85, 0x00, 0x00, 0x01, 0x82, 0x03, 0x00, 0x01, 0x8A, 0x00,
  0x00, 0xC0, 0x82, 0xE0, 0x00, 0xC0, 0x87, 0x00, 0x0B, 0x60, 0x73, 0x3F, 0x1F, 0x3F, 0x7F, 0x7F,
  0x3F, 0x1F, 0x3F, 0x73, 0x60, 0x82, 0x00, 0x0D, 0x0C, 0x1C, 0xB8, 0xF0, 0xF0, 0xF6, 0xFF, 0xFF,
  0xF6, 0xF0, 0xF0, 0xB8, 0x1C, 0x0C, 0x85, 0x00, 0x06, 0x0F, 0x18, 0x70, 0xF8, 0xFF, 0xF8, 0x70,
  0x88, 0x00, 0x06, 0x03, 0x06, 0x3C, 0x7C, 0xFC, 0x7C, 0x38, 0x8C, 0x00, 0x82, 0xFF, 0x02, 0x7F,
  0x1F, 0x07, 0x83, 0x00, 0x0B, 0x1C, 0x3E, 0x3F, 0x3C, 0x1C, 0x3E, 0xFE, 0xFF, 0xFF, 0xFE, 0xFC,
  0xF8, 0x84, 0x00, 0x81, 0x06, 0x82, 0x00, 0x81, 0x0F, 0x01, 0x07, 0x03, 0x86, 0x00, 0x81, 0x60,
  0x82, 0x00, 0x81, 0xF0, 0x01, 0xE0, 0xC0, 0x89, 0x00, 0x05, 0x7F, 0xFF, 0xBF, 0x3F, 0x2F, 0x27,
  0x82, 0x20, 0x0B, 0x10, 0x18, 0x1E, 0x3F, 0x38, 0x70, 0x70, 0xF0, 0xF0, 0xE0, 0xE0, 0xA0, 0x83,
  0x20, 0x81, 0x00, 0x00, 0x06, 0x82, 0x07, 0x03, 0x03, 0x01, 0x00, 0x6C, 0x82, 0x7C, 0x01, 0x38,
  0x10, 0x82, 0x00, 0x83, 0xC0, 0x03, 0x80, 0x00, 0x00, 0x6C, 0x82, 0x7C, 0x08, 0x38, 0x10, 0x00,
  0x00, 0x07, 0x0C, 0x19, 0x31, 0x21, 0x83, 0x20, 0x09, 0x30, 0x10, 0x18, 0x0C, 0x07, 0x00, 0x00,
  0xE0, 0xF0, 0xF8, 0x82, 0xFC, 0x00, 0x3C, 0x82, 0x04, 0x0B, 0x0C, 0x18, 0x30, 0xE0, 0x00, 0xFF,
  0x7E, 0x3E, 0x1F, 0x0E, 0x06, 0x03, 0x86, 0x01, 0x08, 0x07, 0x0F, 0xFF, 0x7E, 0x7C, 0xF8, 0x70,
  0x60, 0xC0, 0x86, 0x80, 0x05, 0xF0, 0xF8, 0x00, 0x00, 0x7F, 0xC0, 0x82, 0x80, 0x83, 0xFF, 0x00,
  0x70, 0x85, 0x00, 0x04, 0xC0, 0x60, 0x20, 0x30, 0x18, 0x83, 0xFF, 0x00, 0x0E, 0x85, 0x00, 0x0C,
  0x3F, 0x7F, 0xE0, 0xEC, 0x0F, 0x1F, 0x12, 0x32, 0x3F, 0x32, 0x32, 0x7F, 0x7F, 0x82, 0x00, 0x0D,
  0xFC, 0xFE, 0x07, 0x37, 0xF0, 0xF8, 0x48, 0x4C, 0xFC, 0x4C, 0x4C, 0xFE, 0xFE, 0x00, 0x84, 0x03,
  0x00, 0x07, 0x89, 0x0F, 0x84, 0x00, 0x00, 0x80, 0x89, 0xC0, 0x09, 0x00, 0x60, 0xF0, 0xF8, 0x7C,
  0x3E, 0x1F, 0x0F, 0x07, 0x03, 0x87, 0x00, 0x33, 0x18, 0x3C, 0x3C, 0x18, 0x00, 0x80, 0x80, 0xC0,
  0xE0, 0x70, 0x38, 0x1C, 0x08, 0x00, 0x00, 0x07, 0x0F, 0x1F, 0x07, 0x07, 0x0E, 0x0C, 0x1C, 0x1F,
  0x3F, 0x38, 0x78, 0x70, 0xF8, 0x00, 0x00, 0x80, 0x80, 0xC0, 0xC0, 0xE0, 0xE0, 0x60, 0x70, 0xF0,
  0xF8, 0x38, 0x3C, 0x1C, 0x3E, 0x00, 0x01, 0x03, 0x03, 0x01, 0x3F, 0x3F, 0x82, 0x07, 0x84, 0x06,
  0x81, 0x00, 0x05, 0x80, 0xC0, 0xC0, 0x80, 0xFC, 0xFC, 0x82, 0xE0, 0x84, 0x60, 0x81, 0x00, 0x05,
  0x01, 0x03, 0x03, 0x01, 0x3F, 0x3F, 0x82, 0x07, 0x01, 0x0F, 0x1F, 0x82, 0x06, 0x81, 0x00, 0x05,
  0x80, 0xC0, 0xC0, 0x80, 0xFC, 0xFC, 0x82, 0xE0, 0x01, 0xF0, 0xF8, 0x82, 0x60, 0x81, 0x00, 0x04,
  0x75, 0x25, 0x27, 0x25, 0x25, 0x83, 0x00, 0x0B, 0x7E, 0x43, 0x73, 0x42, 0x42, 0x7A, 0x00, 0x70,
  0x40, 0x60, 0x40, 0x70, 0x83, 0x00, 0x06, 0x5C, 0x56, 0xD2, 0xD2, 0x56, 0x7C, 0x00, 0xFF};

const int SPRITESINITSIZE = 104;

const byte SPRITESINIT[] = {
  204, 0, 0, 15,
  204, 0, 4, 15,
  204, 0, 8, 15,
  204, 0, 12, 15,
  204, 0, 16, 15,
  204, 0, 20, 15,
  204, 0, 24, 15,
  204, 0, 28, 15,
  204, 0, 32, 15,
  204, 0, 36, 15,
  204, 0, 40, 15,
  204, 0, 44, 15,
  204, 0, 48, 15,
  204, 0, 52, 15,
  204, 0, 56, 15,
  204, 0, 60, 15,
  204, 0, 64, 15,
  204, 0, 68, 15,
  204, 0, 72, 15,
  204, 0, 76, 15,
  204, 0, 80, 15,
  204, 0, 84, 15,
  204, 0, 88, 15,
  204, 0, 92, 15,
  204, 0, 96, 15,
  204, 0, 100, 15};
