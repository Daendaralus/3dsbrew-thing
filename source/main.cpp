#include <string.h>
#include <3ds.h>
#include <sf2d.h>
#include <chrono>
#include <stdio.h>
#include <time.h>
#include "Player.h"

#define LOGIC_FREQUENCY 60
#define CNSL_NLCLEAR "\n\x1b[K"
int update();
int input();
int render();
int counter = 0;
Point p1(100.0f, 100.0f);
Player pl1(p1);
int main()
{
	

	sf2d_init();
	sf2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0x00));
	pl1.setSize(100.0f);
	pl1.setMovSpd(1.0f);
	
	consoleInit(GFX_BOTTOM, NULL);
	using namespace std::chrono;
	auto timeNow = steady_clock::now();
	auto timeOld = timeNow;
	// Main loop
	while (aptMainLoop())
	{
		//if (input()==-1)
			//break;
		timeNow = steady_clock::now();
		if (duration_cast<milliseconds>(timeNow - timeOld) >= milliseconds(1000/LOGIC_FREQUENCY))
		{
			int err = update();
			if (err == -1)
				break;
			timeOld = timeNow;
		}
		render();
		
		sf2d_swapbuffers();
		//printf("\x1b[5;0H");
		//printf("counter = %d\n", counter);
		//u8* fb = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
		
		// Flush and swap framebuffers
		
	}

	sf2d_fini();
	return 0;
}

int render()
{
	pl1.draw();
	return 0;
}

int update()
{
	printf("\x1b[5;0HPosition: %f %f%sSize: %f%sSpeed: %f", pl1.getPosition().x, pl1.getPosition().y,CNSL_NLCLEAR, pl1.getSize(), CNSL_NLCLEAR, pl1.getMovSpd());

	u32 kDown = 0, kHeld = 0, kUp = 0;
	hidScanInput();
	kDown = hidKeysDown();
	kHeld = hidKeysHeld();
	kUp = hidKeysUp();
	
	if (kHeld & KEY_A)
		pl1.setSize(pl1.getSize() + 0.2f);
	if (kHeld & KEY_B)
		pl1.setSize(pl1.getSize() - 10.0f/60.0f);
	if (kHeld & KEY_Y)
		pl1.setMovSpd(pl1.getMovSpd() + 0.5f/60.0f);
	if (kHeld & KEY_X)
		pl1.setMovSpd(pl1.getMovSpd() - 0.5f / 60.0f);
	if (kHeld & KEY_CPAD_LEFT)
	{
		pl1.move(-1, 0);
	}
	if (kHeld & KEY_CPAD_RIGHT)
	{
		pl1.move(1, 0);
	}
	if (kHeld & KEY_CPAD_UP)
	{
		pl1.move(0, -1);
	}
	if (kHeld & KEY_CPAD_DOWN)
	{
		pl1.move(0, 1);
	}
	if (kHeld & KEY_START)
		return -1; // End Homebrew
	return 0;
}

int input()
{
	u32 kDown = 0, kHeld = 0, kUp = 0;
	hidScanInput();
	kDown = hidKeysDown();
	kHeld = hidKeysHeld();
	kUp = hidKeysUp();
	if (kDown & KEY_B)
	{
		printf("\x1b[2;0H");
		printf("key B pressed down!");
	}
	if (kHeld & KEY_A)
		counter++;
	if (kHeld & KEY_START)
		return -1; // End Homebrew
	return 0;
}