#include "mylib.h"
#include "winscreen.h"
#include "gameoverscreen.h"
#include "welcomescreen.h"
#include "background.h"
#include "spaceship.h"

int status = 0;
int x;
int y;
int winarea = 220;
int lives = 3;


/* Define Players Positions*/
players ironman = {75, 10, 1, 10, RED};
villans joker = {133, 37, 2, 10};
villans loki = {23, 62, 2, 10};
villans ultron = {133, 85, 2, 10};
villans venom = {23, 108, 2, 10};
villans magneto = {133, 131, 2, 10};
villans doom = {23, 154, 2, 10};
villans redskull = {133, 177, 2, 10};
villans goblin = {23, 200, 2, 10};

/* Define Boundries */
int enemylowerbound = 133;
int enemyupperbound = 18;
int enemyleftbound = 30;
int enemyrightbound = 205;

int playerleftbound = 0;
int playerrightbound = 239;
int playerupperbound = 53;
int playerlowerbound = 97;


void startUpPage() {
    drawImage3(0, 0, 240, 160, welcomescreen);
    if (KEY_DOWN_NOW(BUTTON_START)) {
        status = 1;
    }
}

void drawBackground() {
	drawImage3(0, 0, 240, 160, background);
	status = 2;
}

void play() {
	// Draw the Play Area
	drawRect(53, 0, 31, 54, GREEN);
	drawRect(53, 214, 26, 54, GREEN);
	drawRect(15, 30, 185, 130, WHITE);

	// Draw the players
	drawRect(ironman.row, ironman.col, ironman.size, ironman.size, ironman.color);
	//drawRect(joker.row, joker.col, joker.size, joker.size, joker.color);
	drawImage3(joker.row, joker.col, joker.size, joker.size, spaceship);
	drawImage3(loki.row, loki.col, loki.size, loki.size, spaceship);
	drawImage3(ultron.row, ultron.col, ultron.size, ultron.size, spaceship);
	drawImage3(venom.row, venom.col, venom.size, venom.size, spaceship);
	drawImage3(magneto.row, magneto.col, magneto.size, magneto.size, spaceship);
	drawImage3(doom.row, doom.col, doom.size, doom.size, spaceship);
	drawImage3(redskull.row, redskull.col, redskull.size, redskull.size, spaceship);
	drawImage3(goblin.row, goblin.col, goblin.size, goblin.size, spaceship);

	x = ironman.col;
	y = ironman.row;

	move();
	updateLives(lives);

	if (ironman.col >= winarea) {
		status = 4;
		lives = 3;
	}

	if (checkCollision(ironman.col, ironman.row, joker.col, joker.row, ironman.size, joker.size)) {
		lives--;
		updateLives(lives);
		if (lives == 2 || lives == 1) {
			ironman.row = 75;
			ironman.col = 10;
		} else if (lives == 0) {
			status = 3;
			lives = 3;
		}
	}
	if (checkCollision(ironman.col, ironman.row, loki.col, loki.row, ironman.size, loki.size)) {
		lives--;
		updateLives(lives);
		if (lives == 2 || lives == 1) {
			ironman.row = 75;
			ironman.col = 10;
		} else if (lives == 0) {
			status = 3;
			lives = 3;
		}
	}
	if (checkCollision(ironman.col, ironman.row, ultron.col, ultron.row, ironman.size, ultron.size)) {
		lives--;
		updateLives(lives);
		if (lives == 2 || lives == 1) {
			ironman.row = 75;
			ironman.col = 10;
		} else if (lives == 0) {
			status = 3;
			lives = 3;
		}
	}
	if (checkCollision(ironman.col, ironman.row, venom.col, venom.row, ironman.size, venom.size)) {
		lives--;
		updateLives(lives);
		if (lives == 2 || lives == 1) {
			ironman.row = 75;
			ironman.col = 10;
		} else if (lives == 0) {
			status = 3;
			lives = 3;
		}
	}
	if (checkCollision(ironman.col, ironman.row, magneto.col, magneto.row, ironman.size, magneto.size)) {
		lives--;
		updateLives(lives);
		if (lives == 2 || lives == 1) {
			ironman.row = 75;
			ironman.col = 10;
		} else if (lives == 0) {
			status = 3;
			lives = 3;
		}
	}
	if (checkCollision(ironman.col, ironman.row, doom.col, doom.row, ironman.size, doom.size)) {
		lives--;
		updateLives(lives);
		if (lives == 2 || lives == 1) {
			ironman.row = 75;
			ironman.col = 10;
		} else if (lives == 0) {
			status = 3;
			lives = 3;
		}
	}
	if (checkCollision(ironman.col, ironman.row, redskull.col, redskull.row, ironman.size, redskull.size)) {
		lives--;
		updateLives(lives);
		if (lives == 2 || lives == 1) {
			ironman.row = 75;
			ironman.col = 10;
		} else if (lives == 0) {
			status = 3;
			lives = 3;
		}
	}
	if (checkCollision(ironman.col, ironman.row, goblin.col, goblin.row, ironman.size, goblin.size)) {
		lives--;
		updateLives(lives);
		if (lives == 2 || lives == 1) {
			ironman.row = 75;
			ironman.col = 10;
		} else if (lives == 0) {
			status = 3;
			lives = 3;
		}
	}

	/* Retrun To Main Screen When The Select Button Is Pressed*/
	if (KEY_DOWN_NOW(BUTTON_SELECT)) {
		status = 0;
		lives = 3;
	}

	/* Reset The Position Of The Ironman If the Game Ends*/
	if (status == 4 || status == 0 || status == 3) {
		ironman.row = 75;
		ironman.col = 10;
	}

	waitForVblank();
}

void updateLives(int lives) {
	if (lives == 3) {
		drawString(3, 150, "LIVES: ", WHITE);
		drawString(3, 187, "3", GREEN);
	}
	if (lives == 2) {
		drawString(3, 150, "LIVES: ", WHITE);
		drawString(3, 187, "3 2" , YELLOW);
	}
	if (lives == 1) {
		drawString(3, 150, "LIVES: ", WHITE);
		drawString(3, 187, "3 2 1", RED);
	}
}

void gameOverScreen() {
    drawImage3(0, 0, 240, 160, gameoverscreen);
	if (KEY_DOWN_NOW(BUTTON_START)) {
		status = 0;
	}
}

void winScreen() {
    drawImage3(0, 0, 240, 160, winscreen);
	if (KEY_DOWN_NOW(BUTTON_START)) {
		status = 0;
	}
}

void move() {
    if (KEY_DOWN_NOW(BUTTON_UP)) {
        ironman.row = ironman.row - ironman.speed;
    }
    if (KEY_DOWN_NOW(BUTTON_DOWN)) {
        ironman.row = ironman.row + ironman.speed;
    }
    if (KEY_DOWN_NOW(BUTTON_RIGHT)) {
        ironman.col = ironman.col + ironman.speed;
    }
    if (KEY_DOWN_NOW(BUTTON_LEFT)) {
        ironman.col = ironman.col - ironman.speed;
    }


	/* Move The Villans*/
	if (joker.row >= enemylowerbound || joker.row <= enemyupperbound) {
		joker.speed = -joker.speed;
	}
	joker.row = joker.row + joker.speed;

	if (loki.row >= enemylowerbound || loki.row <= enemyupperbound) {
		loki.speed = -loki.speed;
	}
	loki.row = loki.row + loki.speed;

	if (ultron.row >= enemylowerbound || ultron.row <= enemyupperbound) {
		ultron.speed = -ultron.speed;
	}
	ultron.row = ultron.row + ultron.speed;

	if (venom.row >= enemylowerbound || venom.row <= enemyupperbound) {
		venom.speed = -venom.speed;
	}
	venom.row = venom.row + venom.speed;

	if (magneto.row >= enemylowerbound || magneto.row <= enemyupperbound) {
		magneto.speed = -magneto.speed;
	}
	magneto.row = magneto.row + magneto.speed;

	if (doom.row >= enemylowerbound || doom.row <= enemyupperbound) {
		doom.speed = -doom.speed;
	}
	doom.row = doom.row + doom.speed;

	if (redskull.row >= enemylowerbound || redskull.row <= enemyupperbound) {
		redskull.speed = -redskull.speed;
	}
	redskull.row = redskull.row + redskull.speed;

	if (goblin.row >= enemylowerbound || goblin.row <= enemyupperbound) {
		goblin.speed = -goblin.speed;
	}
	goblin.row = goblin.row + goblin.speed;

	/* Set The Right Boundries for Ironman*/
	if (ironman.col > playerrightbound - ironman.size + 1) {
		ironman.row = y;
		ironman.col = x;
	}
	if (ironman.row > playerlowerbound && ironman.col > enemyrightbound) {
		ironman.row = y;
		ironman.col = x;
	}
	if (ironman.row < playerupperbound && ironman.col > enemyrightbound) {
		ironman.row = y;
		ironman.col = x;
	}

	/* Set The Left Boundries for Ironman*/
	if (ironman.col < playerleftbound) {
		ironman.row = y;
		ironman.col = x;
	}
	if (ironman.row < playerupperbound && ironman.col < enemyleftbound) {
		ironman.row = y;
		ironman.col = x;

	}
	if (ironman.row > playerlowerbound && ironman.col < enemyleftbound) {
		ironman.row = y;
		ironman.col = x;
	}

	if (ironman.col < enemyrightbound && ironman.col > enemyleftbound && ironman.row > enemylowerbound) {
		ironman.row = y;
		ironman.col = x;
	}
	if (ironman.col < enemyrightbound && ironman.col > enemyleftbound && ironman.row < enemyupperbound) {
		ironman.row = y;
		ironman.col = x;
	}

	/* Set Boundries At The End Of Corners*/
	if (((ironman.col - 1 < enemyleftbound) && (ironman.row < playerupperbound))) {
		ironman.row = y;
		ironman.col = x;
	}
	if (((ironman.col - 1 < enemyleftbound) && (ironman.row > playerlowerbound))) {
		ironman.row = y;
		ironman.col = x;
	}
	if (((ironman.col + 1 > enemyrightbound) && (ironman.row < playerupperbound))) {
		ironman.row = y;
		ironman.col = x;
	}
	if(((ironman.col + 1 > enemyrightbound) && (ironman.row > playerlowerbound))) {
		ironman.row = y;
		ironman.col = x;
	}
}

int checkCollision(int icol, int irow, int vcol, int vrow, int isize, int vsize) {
	if ((irow <= vrow) && (icol + isize >= vcol) && (irow + isize >= vrow) && (icol <= vcol)) {
		return 1;
	} else if ((irow <= vrow + vsize) && (icol + isize >= vcol) && (irow + isize >= vrow + vsize) && (icol <= vcol)) {
		return 1;
	} else if ((irow <= vrow) && (icol + isize >= vcol + vsize) && (irow + isize >= vrow) && (icol <= vcol + vsize)) {
		return 1;
	} else if ((irow <= vrow + vsize) && (icol + isize >= vcol + vsize) && (irow + isize >= vrow + vsize) && (icol <= vcol + vsize)) {
		return 1;
	} else {
		return 0;
	}
}
