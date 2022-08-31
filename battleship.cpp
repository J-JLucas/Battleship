/* Battleship
 * clone game to learn C++
 * By Josh Lucas, Aug 30th 2022
 */

/* 1 - prompt 2 player or vs ai 
 * 2 - place ships (user placed eventually)
 * 3 - take turns taking shots and update ship hp
 * 4 - game ends when all of one player's ships have been sunk
*/

#include <iostream>

void printGrid(int grid[10][10]) {
	//prints out a player's complete hud
	std::cout << "     A  B  C  D  E  F  G  H  I  J  \n"
	   	     "   +------------------------------+\n";
	for(int i = 0; i < 10; i++){
		printf("%*d|", 3, i+1);
		for(int j = 0; j < 10; j++) {
			       	if(grid[i][j] == 1)
					std::cout << " X ";
				else if(grid[i][j] == 2)
					std::cout << " # ";
				else if(grid[i][j] ==  -1)
					std::cout << " O ";
				else
					std::cout << " ~ ";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "   +------------------------------+\n";

	return;
}

void placeShips(int grid[10][10]){
	//will eventually allow player to choose their own placement
	
	for(int i = 0; i < 5; i++) {
		grid[i][0] = 2;
	}
	for(int i = 0; i < 4; i++) {
		grid[6][i] = 2;
	}
	for(int i = 0; i < 3; i++) {
		grid[i][7] = 2;
	}
	for(int i = 0; i < 3; i++) {
		grid[i+5][8] = 2;
	}
	for(int i = 0; i < 2; i++) {
		grid[7][i] = 2;
	}
		
}

int fire(int fgrid[10][10], int tgrid[10][10], int hp){
	char x;
	int y;
//	bool hit = false;

	std::cout << "Enter x coodinate: ";
	std::cin >> x;
	std::cout << "Enter y coordinate: ";
	std::cin >> y;
	std::cout << "("<< x << ',' << y << ") ... ";

	// x-65 uses char as int, subtracts to start counting from 0, y is 1-10 so adjusts to 0-9
	x -= 65, y -= 1;
	if(fgrid[y][x] == 2) {
//		hit = true;
		fgrid[y][x] = 1;
		tgrid[y][x] = 1;
		std::cout << "HIT!!!" << std::endl;
		return --hp;
	}
	else {
		tgrid[y][x] = -1;	
		std::cout << "MISS" << std::endl;
		return hp;
	}
}


int main(void){
/*	int garbage = 0;	
	//Initialize Game
	system("clear");		//clears console window in linux
	std::cout << "\n\n\n\n\nPLAYER ONE\nPRESS ENTER" << std::endl;
	std::cin >> garbage;
	system("clear");		//clears console window in linux
	
*/	
	system("clear");
	bool gameover = false;

	//Player1
	int targetp1[10][10] = {};
	int fleetp1[10][10] = {};
	int p1hp = 17;

	//Player2
	int targetp2[10][10] = {};
	int fleetp2[10][10] = {};
	int p2hp = 17;

	placeShips(fleetp1);
	placeShips(fleetp2);
		
	std::cout << "\t  TARGETING HUD1 " << std::endl;
	printGrid(targetp1);

	std::cout << "\t  FLEET HUD " << std::endl;
	printGrid(fleetp1);

	while(!gameover) {

		p2hp = fire(fleetp2,targetp1, p2hp);
		
		std::cout << "\t  TARGETING HUD1 " << std::endl;
		printGrid(targetp1);
	
		std::cout << "\t  FLEET HUD " << std::endl;
		printGrid(fleetp1);


		if(p2hp == 0) {
			gameover = true;
			std::cout << "GAME OVER... YOU WIN!!!" << std::endl;
		}
	}
/*
	system("clear");
	std::cout << "\t  TARGETING HUD1 " << std::endl;
	printGrid(targetp1);

	std::cout << "\t  FLEET HUD " << std::endl;
	printGrid(fleetp1);
*/
	
/*	system("clear");		//clears console window in linux
	std::cout << "\n\n\n\n\nPLAYER TWO\nPRESS ENTER" << std::endl;
	std::cin >> garbage;
	system("clear");		//clears console window in linux

	std::cout << "\t  TARGETING HUD2 " << std::endl;
	printGrid(targetp2);

	std::cout << "\t  FLEET HUD " << std::endl;
	printGrid(fleetp2);
*/	
	return 0;
}
