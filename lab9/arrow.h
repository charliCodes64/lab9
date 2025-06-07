#include "player.h"
#include "ghost.h"

class Arrow
{
public:
	Arrow();
	~Arrow();
	int getNumOfGhostHit();
	void DrawArrow();
	void FireArrow(player &Player);
	void UpdateArrow(int WIDTH);
	void CollideArrow(ghost ghosts[], int cSize, player& player);
private:
	int x;
	int y;
	bool live;
	int speed;
	int numOfGhostHit;
	ALLEGRO_BITMAP *image;
};

