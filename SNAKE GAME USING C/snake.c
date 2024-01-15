// Simple Snake Game in C

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>

int i, j, height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;

// Function to generate the fruit within the boundary
void setup() {
	gameover = 0;
	x = height / 2;
	y = width / 2;

	// Generate random fruit coordinates
label1:
	fruitx = rand() % 20;
	if (fruitx == 0)
		goto label1;

label2:
	fruity = rand() % 20;
	if (fruity == 0)
		goto label2;

	score = 0;
}

// Function to draw the boundaries
void draw() {
	system("cls");  // Clear the console

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
				printf("#");
			} else {
				if (i == x && j == y)
					printf("0");  // Snake head
				else if (i == fruitx && j == fruity)
					printf("*");  // Fruit
				else
					printf(" ");  // Empty space
			}
		}
		printf("\n");
	}

	// Print the score
	printf("Score: %d\n", score);
	printf("Press X to quit the game");
}

// Function to take input
void input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			flag = 1;  // Left
			break;
		case 's':
			flag = 2;  // Down
			break;
		case 'd':
			flag = 3;  // Right
			break;
		case 'w':
			flag = 4;  // Up
			break;
		case 'x':
			gameover = 1;  // Quit game
			break;
		}
	}
}

// Function for the logic behind each movement
void logic() {
	sleep(0.01);  // Pause to control speed

	switch (flag) {
	case 1:
		y--;
		break;
	case 2:
		x++;
		break;
	case 3:
		y++;
		break;
	case 4:
		x--;
		break;
	default:
		break;
	}

	// Game over conditions
	if (x < 0 || x > height || y < 0 || y > width)
		gameover = 1;

	// If snake reaches the fruit, update the score
	if (x == fruitx && y == fruity) {
	label3:
		fruitx = rand() % 20;
		if (fruitx == 0)
			goto label3;

	label4:
		fruity = rand() % 20;
		if (fruity == 0)
			goto label4;

		score += 10;
	}
}

// Main function
void main() {
	// Game setup
	setup();

	// Game loop
	while (!gameover) {
		// Function Calls
		draw();
		input();
		logic();
	}
}
