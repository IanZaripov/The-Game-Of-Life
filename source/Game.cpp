#include "Game.h"

using namespace std;

Game::Game(int width, int height) : cells(width, vector<bool>(height, false)) {}


bool Game::CheckCondition(const SDL_Event& event) const{
	int x = event.button.x / cell_size;
	int y = event.button.y / cell_size;
	if (x >= 0 && x < cells.size() && y >= 0 && y < cells[0].size()) {
		return true;
	}
	return false;
}

void Game::ToggleCell(int x, int y) {
	int gridx = x / cell_size;
	int gridy = y / cell_size;
	if (gridx >= 0 && gridx < cells.size() && gridy >= 0 && gridy < cells[0].size()) {
		cells[gridx][gridy] = !cells[gridx][gridy];
	}
}

bool Game::GetConditionOfCell(int x,int y) const{
	return cells[x][y];
}


const int Game::GetCellSize() const {
	return cell_size;
}

const int Game::GetWidth() const {
	return cells.size();
}

const int Game::GetHight() const {
	return cells[0].size();
}

int Game::CountNeighbors(const int x,const int y) {
	int alive_neighbors = 0;
	for (int i = 0; i < 8; i++) {
		int dx = x + deltax[i];
		int dy = y + deltay[i];
		if (dx >= 0 && dy >= 0 && 
			dx < cells.size() && dy < cells[0].size() 
			&& cells[dx][dy]) {
			alive_neighbors++;
		}
	}
	return alive_neighbors;
}

void Game::DoSimulation() {
	if (!is_simulation_Ranning) {
		return;
	}
	for (int x = 0; x < cells.size(); x++) {
		for (int y = 0; y < cells[0].size(); y++) {
			if (x == 0 || x == cells.size() - 1 || y == 0 || y == cells[0].size() - 1) {
				HandleCorners(x, y);
			}
			else {
				int cnt_neighbors = CountNeighbors(x, y);
				if (cells[x][y]) {
					if (cnt_neighbors != 2 && cnt_neighbors != 3) {
						cells[x][y] = false;
					}
				}
				else {
					if (cnt_neighbors == 3) {
						cells[x][y] = true;
					}
				}
			}
		}
	}
}

void Game::HandleCorners(const int x, const int y) {
	return;
}

void Game::Start() {
	is_simulation_Ranning = true;
}


void Game::Pause() {
	is_simulation_Ranning = false;
}

bool Game::IsSimulationRanning() const {
	return is_simulation_Ranning;
}