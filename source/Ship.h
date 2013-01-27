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
		f32 x, y, theta, R, mass, acc, bounce;
		double vx, vy;
		f32 ammo, ammoMax, ammoWait, ammoRecharge, ammoTimer;
		f32 shield, shieldMax, shieldWait, shieldRecharge, shieldTimer;
		u32 scolor, wcolor;
		bool isAcc;
	public:
		Ship(f32, u32, u32);
		f32 getX();
		f32 getY();
		double getVx();
		double getVy();
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