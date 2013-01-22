/*===========================================
        Space Duel - Initial Testing
		
		Based on GRRLIB (GX Version) Template
		    Minimum Code To Use GRRLIB
============================================*/
#include <grrlib.h>

#include <stdlib.h>
#include <wiiuse/wpad.h>

#include "Ship.h"

#include "classicbody_png.h"
#include "classicaccent_png.h"
#include "classicshield_png.h"

#define IMGSIZE 64

int const screenW = 640;
int const screenH = 480;
f32 const scale = 0.2;  // Scales size of ships since the resolution is small

int main(int argc, char **argv) {
    // Initialise the Graphics & Video subsystem
    GRRLIB_Init();
	
	GRRLIB_texImg *clbody = GRRLIB_LoadTexture(classicbody_png);
	GRRLIB_texImg *claccent = GRRLIB_LoadTexture(classicaccent_png);
	GRRLIB_texImg *clshield = GRRLIB_LoadTexture(classicshield_png);
	GRRLIB_SetMidHandle(clbody, true);
	GRRLIB_SetMidHandle(claccent, true);
	GRRLIB_SetMidHandle(clshield, true);
	
    // Initialize the Wiimotes
    WPAD_Init();
	
	Ship p1ship(56 * scale, 100, 0.3, 100, 100, 0xFF00FFFF, 0xFFFFFFFF);

    // Loop forever
    while(1) {
	
		// Check for controller input
        WPAD_ScanPads();  // Scan the Wiimotes
		u16 buttonsDown = WPAD_ButtonsHeld(0);  // Checks if any buttons are held (tutorials did it this way)
		if (buttonsDown & WPAD_BUTTON_RIGHT) { p1ship.rotate(1);}
		if (buttonsDown & WPAD_BUTTON_LEFT) { p1ship.rotate(-1);}
		if (buttonsDown & WPAD_BUTTON_UP) { p1ship.thrust();}

        // If [HOME] was pressed on the first Wiimote, break out of the loop
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)  break;
	
		
		if ((p1ship.getX() - p1ship.getR()) < 0 || (p1ship.getX() + p1ship.getR()) > screenW) {
			p1ship.collide(-1 * p1ship.getVx(), p1ship.getVy());
		}
		if ((p1ship.getY() - p1ship.getR()) < 0 || (p1ship.getY() + p1ship.getR()) > screenH) {
			p1ship.collide(p1ship.getVx(), -1 * p1ship.getVy());
		}
		
		p1ship.advance(1);
		
		// Draw everything (adding the 3rd line breaks the program)
		GRRLIB_DrawImg(p1ship.getX(), p1ship.getY(), clbody, p1ship.getTheta(), scale, scale, p1ship.getScolor());
		GRRLIB_DrawImg(p1ship.getX(), p1ship.getY(), claccent, p1ship.getTheta(), scale, scale, 0xFFFFFFFF);
		GRRLIB_DrawImg(p1ship.getX(), p1ship.getY(), clshield, 0, 2 * p1ship.getR() / IMGSIZE, 2 * p1ship.getR() / IMGSIZE, 0xFFFFFFFF);
		//GRRLIB_(p1ship.getX(), p1ship.getY(), R, 0xFFFFFFFF, true);
		
        GRRLIB_Render();  // Render the frame buffer to the TV
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}