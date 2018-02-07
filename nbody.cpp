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

	public:
	Particle(){
		rx = initPos();
		ry = initPos();
		vx = initPos();
		vy = initPos();
		mass = 1.98892e30*rand()*10 + 1e20;
	}
	double initPos(){
		return 1e18*exp(-1.8)*(.5 - rand());
	}

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
		double dx = this->rx - b.rx;
		double dy = this->ry - b.ry;
		double dist = sqrt(dx*dx + dy*dy);
		double F = (G*this->mass*b.mass)/(pow(dist,2)+pow(EPS,2));
		this->fx += F * dx/dist;
		this->fy += F * dy/dist;
		//MAYBE - depends how i do the actual simulation
		b.fx += F * dx/dist;
		b.fy += F * dy/dist;
	}
	void printParticle(){
		std::cout << mass << std::endl;
	}
};

int main(){
	Particle parts[N];
	srand(time(NULL));
	for(auto &p : parts)
		p.update();
	parts[1].printParticle();
}
