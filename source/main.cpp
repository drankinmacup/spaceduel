/*===========================================
        Space Duel - Initial Testing
		
		Based on GRRLIB (GX Version) Template
		    Minimum Code To Use GRRLIB
============================================*/
#include <grrlib.h>

#include <stdlib.h>
#include <wiiuse/wpad.h>
#include <math.h>

#include <sstream> //for num to string

#include "Ship.h"

#define PI 3.14159265

#include "classicbody_png.h"
#include "classicaccent_png.h"
#include "classicshield_png.h"





int const screenW = 640;
int const screenH = 480;

int main(int argc, char **argv) {
    // Initialise the Graphics & Video subsystem
    GRRLIB_Init();
	
	GRRLIB_texImg *clbody = GRRLIB_LoadTexture(classicbody_png);
	GRRLIB_texImg *claccent = GRRLIB_LoadTexture(classicaccent_png);
	GRRLIB_texImg *clshield = GRRLIB_LoadTexture(classicshield_png);

    // Initialise the Wiimotes
    WPAD_Init();
	
	Ship p1ship(45.25483400, 30, 100, 100, .1, 0x00FFFFFF, 0xFFFFFFFF);

    // Loop forever
    while(1) {

        WPAD_ScanPads();  // Scan the Wiimotes
		u16 buttonsDown = WPAD_ButtonsHeld(0);
		if (buttonsDown & WPAD_BUTTON_RIGHT) { p1ship.rotate(1);}
		if (buttonsDown & WPAD_BUTTON_LEFT) { p1ship.rotate(-1);}
		//if (buttonsDown & WPAD_BUTTON_DOWN) { yship++;}
		if (buttonsDown & WPAD_BUTTON_UP) { p1ship.thrust();}
		//if (buttonsDown & WPAD_BUTTON_2) { rship++;}
		//if (buttonsDown & WPAD_BUTTON_1) { rship--;}

        // If [HOME] was pressed on the first Wiimote, break out of the loop
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)  break;

		//p1ship.collide(p1ship.getVx(), p1ship.getVy());

        // Draw ship	
		/*
		if (p1ship.getX() < 0) {
			p1ship.collide(p1ship.getVx(), p1ship.getVy());
		} /*
		if (p1ship.getY() - p1ship.getR() <= 0 || p1ship.getY() + p1ship.getR() >= screenH) {
			p1ship.collide(p1ship.getVx(), -1 * p1ship.getVy());
		} */
		
		
		p1ship.advance(1);
		
		
		GRRLIB_DrawImg(p1ship.getXdraw(), p1ship.getYdraw(), clbody, p1ship.getTheta(), 1, 1, p1ship.getSColor());
		GRRLIB_DrawImg(p1ship.getXdraw(), p1ship.getYdraw(), claccent, p1ship.getTheta(), 1, 1,  0xFFFFFFFF);
		//GRRLIB_DrawImg(100, 100, clbody, 0, 1, 1, 0xFFFFFFFF);

        GRRLIB_Render();  // Render the frame buffer to the TV
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}
