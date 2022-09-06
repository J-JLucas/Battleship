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

void clear(){
	system("clear");
	return;
}

class Player{
	public:
		int targetGrid[10][10] = {};
		int fleetGrid[10][10] = {};
		int fleetHP = 17;
		bool isDead = false;

/*
class Ship {
	public:
		//name goes here
		int hp = hp;
		//position goes here
		//head
		//hx
		//hy
		//tail
		//tx
		//ty
		bool isSunk = false;

};
*/

void printGrid(int grid[10][10], int turn, bool fleet) {
	//determines which heading
	if(fleet) {
		std::cout << "          FLEET HUD PLAYER " << turn << std::endl;
		
	}
	else {
		std::cout << "        TARGETING HUD PLAYER " << turn << std::endl;
	}

	//prints out a player grid hud
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

void playerSplash(int turn){
	clear();
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
  			"		PLAYER " << turn << "\n";
	getchar();
	clear();
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

bool playerTurn(){
	//draw player splash (enter to continue)
	//draw player hud
	//take coordinates
	//check cooridinates
	//update results
		//update targeting array
			//if hit:
			//update enemy ship array
			//update enemy ship health
			//is game over?
	//redraw updated player hud
	//prompt to end turn
	return false;
}


bool fire(int fgrid[10][10], int tgrid[10][10], int hp){
	char x;
	int y;
//	bool hit = false;

	std::cout << "Enter x coodinate: " << std::endl;
	std::cin >> x;
	std::cout << "Enter y coordinate: " << std::endl;
	std::cin >> y;
	std::cout << "("<< x << ',' << y << ") ... \n";
	getchar();

	// x-65 uses char as int, subtracts to start counting from 0, y is 1-10 so adjusts to 0-9
	x -= 65, y -= 1;
	if(fgrid[y][x] == 2) {
//		hit = true;
		fgrid[y][x] = 1;
		tgrid[y][x] = 1;
		return true;
	}
	else {
		tgrid[y][x] = -1;	
		return false;
	}
}

};
int main(void){

	bool gameover = false;
	int turn = 1;
	bool hit = false;
	
	// instantiate players	
	Player p1;
	Player p2;
	
	p1.placeShips(p1.fleetGrid);
	p2.placeShips(p2.fleetGrid);
	
	clear();	
	while(!gameover) {
		//PLAYER ONE'S TURN
		p1.playerSplash(turn);
		p1.printGrid(p1.targetGrid, turn, false);
		p1.printGrid(p1.fleetGrid, turn, true);

		hit = p1.fire(p2.fleetGrid,p1.targetGrid, p2.fleetHP);

		clear();
		p1.printGrid(p1.targetGrid, turn, false);
		p1.printGrid(p1.fleetGrid, turn, true);
		
		if (hit) {
			std::cout << "HIT!!!" << std::endl;
			p2.fleetHP--;
			hit = false;
		}
		else {
			std::cout << "MISS" << std::endl;
		}

		if(p2.fleetHP == 0) {
			gameover = true;
			std::cout << "GAME OVER... PLAYER 1 WINS!!!" << std::endl;
			return 0;
		}
		turn++;
		std::cout << "END TURN? (Y/Q)";
		getchar();


		// PLAYER TWO'S TURN
		p2.playerSplash(turn);
		p2.printGrid(p2.targetGrid, turn, false);
		p2.printGrid(p2.fleetGrid, turn, true);

		hit = p2.fire(p1.fleetGrid,p2.targetGrid, p1.fleetHP);

		clear();	
		p2.printGrid(p2.targetGrid, turn, false);
		p2.printGrid(p2.fleetGrid, turn, true);

		if (hit) {
			std::cout << "HIT!!!" << std::endl;
			p1.fleetHP--;
			hit = false;
		}
		else {
			std::cout << "MISS" << std::endl;
		}

		if(p1.fleetHP == 0) {
			gameover = true;
			std::cout << "GAME OVER... PLAYER 2 WINS!!!" << std::endl;
			return 0;
			}
		turn--;
		std::cout << "END TURN? (Y/Q)";
		getchar();
	}	
	return 0;
}
