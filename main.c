#include "mylib.h"

extern int status;
extern int lives;

int main() {
	REG_DISPCTL = MODE3 | BG2_ENABLE;

	while (1) {
		if (status == 0) {
			startUpPage();
		}
		if (status == 1) {
			drawBackground();
		}
		if (status == 2) {
			play();
		}
		if (status == 4) {
			winScreen();
		}
		if (status == 3) {
			gameOverScreen();
		}
	}
	return 0;
}
