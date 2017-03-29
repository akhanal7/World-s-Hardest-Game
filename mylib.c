#include "mylib.h"

unsigned short *videoBuffer = (unsigned short *)0x6000000;

void setPixel(int row, int col, unsigned short color) {
    videoBuffer[OFFSET(row, col, 240)] = color;
}


void drawRect(int row, int col, int width, int height, unsigned short color) {
    for (int i = 0; i < height; i++) {
        DMA[3].src = &color;
        DMA[3].dst = videoBuffer + OFFSET(row + i, col, 240);
        DMA[3].cnt = width | DMA_ON | DMA_SOURCE_FIXED;
    }
}

void drawImage3(int row, int col, int width, int height, const u16 *image) {
    for (int i = 0; i < height; i++) {
        DMA[3].src = image + OFFSET(i, 0, width);
        DMA[3].dst = videoBuffer + OFFSET((row + i), col, 240);
        DMA[3].cnt = width | DMA_ON;
    }
}

void drawChar(int row, int col, char ch, u16 color) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 6; j++) {
            if(fontdata_6x8[OFFSET(i, j, 6) + ch * 48]) {
				setPixel(row + i, col + j, color);
			}
        }
    }
}

void drawString(int row, int col, char *str, u16 color) {
	while(*str) {
		drawChar(row, col, *str++, color);
		col += 6;
	}
}

void waitForVblank() {
	while(SCANLINECOUNTER > 160);
	while(SCANLINECOUNTER < 160);
}
