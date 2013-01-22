/*===========================================
        Space Duel - Initial Testing
		
		Based on GRRLIB (GX Version) Template
		    Minimum Code To Use GRRLIB
============================================*/
#include "Ship.h"

Ship::Ship(f32 Rc, f32 massc, f32 accc, f32 shieldMaxc, f32 ammoMaxc, u32 scolorc, u32 wcolorc) {
	R = Rc;
	mass = massc;
	accc = accc;
	shieldMax = shieldMaxc;
	shield = shieldMax;
	ammoMax = ammoMaxc;
	ammo = ammoMax;
	scolor = scolorc;
	wcolor = wcolorc;
	vx = 0;
	vy = 0;
	isAcc = false;
	
	srand(time(0));
	x = 100 + rand() % 540;
	y = 100 + rand() % 380;
	theta = rand() % 360;
}

f32 Ship::getX() {
	return x;
}

f32 Ship::getY() {
	return y;
}

f32 Ship::getVx() {
	return vx;
}

f32 Ship::getVy() {
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
	return ammo / ammoMax * 0xFFFFFFFF;
}

u32 Ship::getShieldColor() {
	return shield / shieldMax * 0xFFFFFFFF;
}

void Ship::thrust() {
	isAcc = true;
}

void Ship::rotate(int dir) {
	theta += dir;
}

void Ship::collide(f32 vx2, f32 vy2) {
	vx = vx2;
	vy = vy2;
}

void Ship::advance(f32 time) {
	x += vx * time;
	y += vy * time;
	vx += (int) isAcc * sin(theta * PI / 180) * time * 0.03;
	vy -= (int) isAcc * cos(theta * PI / 180) * time * 0.03;
	isAcc = false;
}