/*===========================================
        Space Duel - Initial Testing
		
		Based on GRRLIB (GX Version) Template
		    Minimum Code To Use GRRLIB
============================================*/
#include <stdlib.h>
#include <grrlib.h>
#include <math.h>

#define PI 3.14159265

class Ship {
		f32 x, y, vx, vy, theta, R, mass, acc, shield, shieldMax, ammo, ammoMax;
		u32 scolor, wcolor;
		bool isAcc;
	public:
		Ship(f32, f32, f32, f32, f32, u32, u32);
		f32 getX();
		f32 getY();
		f32 getVx();
		f32 getVy();
		f32 getTheta();
		f32 getR();
		u32 getScolor();
		u32 getWcolor();
		u32 getAccentColor();
		u32 getShieldColor();
		
		void thrust();
		void rotate(int);
		void collide(f32, f32);
		void advance(f32);
};