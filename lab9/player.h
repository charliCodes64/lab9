#ifndef PLAYERH
#define PLAYERH
class player
{
public:
	player(int HEIGHT);
	~player();
	void DrawPlayer();
	void MoveUp();
	void MoveDown(int HEIGHT);
	void MoveLeft();
	void MoveRight();
	int getBoundX(){return boundx;}
	int getBoundY(){return boundy;}
	int getX(){return x;}
	int getY(){return y;}
	void removeLife() { lives--; imageSwitch++; }//added to index through images by 1 each time player is hit
	int imageSwitch;
	void numOfHits(int amount); 
	int getScore();
	int getLives();
private:
	int x;
	int y;
	int lives;
	int speed;
	int boundx;
	int boundy;
	int score;

	ALLEGRO_BITMAP* images[5];
	ALLEGRO_BITMAP* image;
};
#endif
