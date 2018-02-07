#include <iostream>
#include <stdio.h>
#include <ctime>
#include <math.h>
#include <random>

#define N 100 //max value where O(n^2) is faster than O(n log n)
#define G 6.6726e-11
#define T 1e11

class Particle{
	double rx, ry;//position
	double vx, vy;//velocity
	double fx, fy;//force
	double mass;
	void update(){
		vx += T*fx/mass;
		vy += T*fy/mass;
		rx += T*vx;
		ry += T*vy;
	}
	void resetForce(){
		fx = 0.0;
		fy = 0.0;
	}
	void addForce(Particle b){
		double EPS = 2e3;//helps avoid infinity :shrug:
		double dx = this.rx - b.rx;
		double dy = this.ry - b.ry;
		double dist = sqrt(dx*dx + dy*dy);
		double F = (G*this.mass*b.mass)/(pow(dist,2)+pow(EPS,2));
		this.fx += F * dx/dist;
		this.fy += F * dy/dist;
		//MAYBE - depends how i do the actual simulation
		b.fx += F * dx/dist;
		a.fy += F * dy/dist;
	}
}
