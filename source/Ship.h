/*===========================================
        Space Duel - Ship Object Header
		Initial Testing
============================================*/
#include <grrlib.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

class Ship {
		f32 x, y, theta, vx, vy, imgsize, R, shield, shieldmax, acc, mass;
		u32 scolor, wcolor;
		bool isAcc;
		int rotDir;
	public:
		Ship(f32, f32, f32, f32, f32, u32, u32);
		
		f32 getXdraw();
		f32 getYdraw();
		f32 getX();
		f32 getY();
		f32 getTheta();
		f32 getR();
		f32 getShield();
		f32 getMass();
		f32 getVx();
		f32 getVy();
		u32 getSColor();
		u32 getWColor();
		
		void thrust();
		void rotate(int);
		void collide(f32, f32);
		int attacked(f32); //returns 0, 1, or 2 depending on shield of ship destroyed
		void advance(f32);
};