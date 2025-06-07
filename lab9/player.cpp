#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"


player::~player()
{
	for (int i = 0; i < 5; i++) {//loop though each image as deconstruct is called and removes it
		if (images[i]) {
			al_destroy_bitmap(images[i]);
		}
	}
}

player::player(int HEIGHT)
{
	/*image = al_load_bitmap("Kirby0.png");
	x = 20;
	y = HEIGHT / 2;
	lives = 5;
	speed = 7;
	boundx = al_get_bitmap_width(image);
	boundy = al_get_bitmap_height(image);
	score = 0;*/
	images[0] = al_load_bitmap("kirby0.png");
	images[1] = al_load_bitmap("kirby1.png");
	images[2] = al_load_bitmap("kirby2.png");
	images[3] = al_load_bitmap("kirby3.png");
	images[4] = al_load_bitmap("kirby4.png");

	lives = 4;
	image = images[0];

	x = 20;
	y = HEIGHT / 2;
	speed = 7;
	boundx = al_get_bitmap_width(image);
	boundy = al_get_bitmap_height(image);
	score = 0;
}

void player::numOfHits(int amount) {//used to hold the amout of time player hits ghost
	score += amount;
}

int player::getScore(){//used to call score into main
	return score;
}

int player::getLives() {//used to call lives left into main
	return lives;
}

void player::DrawPlayer()
{
	int imageSwap = 5 - lives - 1;
	if (imageSwap < 0) imageSwap = 0;
	if (imageSwap > 4) imageSwap = 4;

	if (images[imageSwap]) {
		al_draw_bitmap(images[imageSwap], x, y, 0);
	}
}

void player::MoveUp()
{
	y -= speed;
	if (y < 0)
		y = 0;
}

void player::MoveDown(int HEIGHT)
{
	y += speed;
	if (y > HEIGHT - 48)  
		y = HEIGHT - 48;
}

void player::MoveLeft()
{
	x -= speed;
	if (x < 0)
		x = 0;
}

void player::MoveRight()
{
	x += speed;
	if (x > 300)
		x = 300;
}