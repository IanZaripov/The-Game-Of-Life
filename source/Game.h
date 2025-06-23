#pragma once
#include <vector>
#include <SDL.h>

class Game {
public:
	Game(int width, int height);
	const int GetCellSize() const;
	bool GetConditionOfCell(int x,int y) const;
	void ToggleCell(int x, int y);
	bool CheckCondition(const SDL_Event& event) const;
	void Start();
	void Pause();
	void DoSimulation();
	bool IsSimulationRanning() const;
	const int GetWidth() const;
	const int GetHight() const;
private:
	std::vector<std::vector<bool>> cells;
	std::vector<int> deltax = { -1,-1,-1,0,0,1,1,1 };
	std::vector<int> deltay = { -1,0,1,-1,1,-1,0,1 };
	const int cell_size = 20;
	bool is_simulation_Ranning = false;
	int CountNeighbors(const int x,const int y);
	void HandleCorners(const int x, const int y);
};