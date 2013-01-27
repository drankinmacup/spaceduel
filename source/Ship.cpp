/*===========================================
        Space Duel - Initial Testing
		
		Based on GRRLIB (GX Version) Template
		    Minimum Code To Use GRRLIB
============================================*/
#include "Ship.h"

Ship::Ship(f32 Rc, u32 scolorc, u32 wcolorc) {
	R = Rc;
	scolor = scolorc;
	wcolor = wcolorc;
	
	srand(time(0));
	x = (2 * (int) R) + rand() % (640 - 4 * (int) R);
	y = (2 * (int) R) + rand() % (480 - 4 * (int) R);
	theta = rand() % 360;
	
	mass = 100;
	acc = 0.3;
	bounce = 0.9;
	vx = 0;
	vy = 0;
	isAcc = false;
	
	shieldMax = 100;
	shield = shieldMax;
	shieldWait = 1000;
	shieldRecharge = 0.1;
	shieldTimer = 0;
	
	ammoMax = 100;
	ammo = ammoMax;
	ammoWait = 100;
	ammoRecharge = 100;
}

f32 Ship::getX() {
	return x;
}

f32 Ship::getY() {
	return y;
}

double Ship::getVx() {
	return vx;
}

double Ship::getVy() {
	return vy;
}

f32 Ship::getTheta() {
	return theta;
}

f32 Ship::getR() {
	return R;
}

u32 Ship::getScolor() {
	return scolor;
}

u32 Ship::getWcolor() {
	return wcolor;
}

u32 Ship::getAccentColor() {
	return 0xFFFFFF00 + (double) (ammo / ammoMax) * 0x000000FF;
}

u32 Ship::getShieldColor() {
	return 0xFFFFFF00 + (double) (shield / shieldMax) * 0x000000FF;
}

void Ship::thrust() {
	isAcc = true;
}

void Ship::rotate(int dir) {
	theta += dir;
}

void Ship::collide(f32 vx2, f32 vy2) {
	/*shield -= 0.5 * mass * (pow(pow(vx, 2) + pow(vy,2), 0.5) - pow(pow(bounce * vx, 2) + pow(bounce * vy,2), 0.5));
	if (shield < 0) {
		shield = 0;
		shieldTimer = 0;
	}*/
	vx = vx2;//bounce * vx2;
	vy = vy2;//bounce * vy2;
}

void Ship::advance(f32 time) {
	x += vx * time;
	y += vy * time;
	vx += (int) isAcc * sin(theta * PI / 180) * time * 0.03;
	vy -= (int) isAcc * cos(theta * PI / 180) * time * 0.03;
	isAcc = false;
	
	if (shield > 0) {
		shield += shieldRecharge;
		if (shield > shieldMax) {shield = shieldMax;}
	}
	else if (false) {//shield == 0) {
		if (shieldTimer >= shieldWait) {shield = shieldMax;}
		else {shieldTimer += time;}
	}
}