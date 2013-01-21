/*===========================================
        Space Duel - Ship Object CCP
		Initial Testing
============================================*/
#include "Ship.h"


Ship::Ship(f32 imgsizec, f32 Rc, f32 shieldmaxc, f32 massc, f32 accc, u32 scolorc, u32 wcolorc) {
	imgsize = imgsizec;
	R = Rc;
	shieldmax = shieldmaxc;
	shield = shieldmax;
	mass = massc;
	acc = accc;
	scolor = scolorc;
	wcolor = wcolorc;
	srand(time(0));
	x = 100 + rand() % 440;
	y = 100 + rand() % 280;
	theta = rand() % 360;
	vx = 0;
	vy = 0;
	isAcc = false;
}
	

f32 Ship::getXdraw() {
	return x - imgsize * cos((theta + 45) * PI / 180);
}

f32 Ship::getYdraw() {

	return y - imgsize * sin((theta + 45) * PI / 180);
}

f32 Ship::getX() {
	return x;
}

f32 Ship::getY() {

	return y;
}

f32 Ship::getTheta() {
	return theta;
}

f32 Ship::getR() {
	return R;
}

f32 Ship::getShield() {
	return shield;
}

f32 Ship::getMass() {
	return mass;
}

f32 Ship::getVx() {
	return vx;
}

f32 Ship::getVy() {
	return vy;
}

u32 Ship::getSColor() {
	return scolor;
}

u32 Ship::getWColor() {
	return wcolor;
}

void Ship::thrust() {
	isAcc = true;
}

void Ship::rotate(int dir) {
	rotDir = dir;
}

void Ship::collide(f32 vx2, f32 vy2) {
	vy = vy2;
	vx = vx2;
}

int Ship::attacked(f32 damage) {
	if (shield > 0) {
		shield -= damage;
		if (shield <= 0) {
			shield = 0;
			return 1;
		}
		else { return 0;}
	}
	else { // (shield == 0)
		return 2;
	}
}

void Ship::advance(f32 time) {
	x += vx * time;
	y += vy * time;
	vx += (f32) isAcc * acc * time * sin(theta * PI / 180);
	vy -= (f32) isAcc * acc * time * cos(theta * PI / 180);
	theta += rotDir;
	rotDir = 0;
	isAcc = false;
}
