#include<iostream>
#include<cmath>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect,Rect);

int main(){
	double x,y,w,h;
	cout << "Please input Rect 1 (x y w h): ";
	cin >> x>>y>>w>>h;
	Rect R1={x,y,w,h};
	cout << "Please input Rect 2 (x y w h): ";
	cin >> x>>y>>w>>h;
	Rect R2={x,y,w,h};
	cout << "Overlap area = ";
	cout << overlap(R1,R2)<<endl;
	return 0;
}
double overlap(Rect r1,Rect r2){
	double w1=r1.x+r1.w;
	double w2=r2.x+r2.w;
	double h1=r1.y+r1.h;
	double h2=r2.y+r2.h;
	double neww,newh;
	if(w1<r2.x) return 0;
	if(h1<r2.h) return 0;
	if(r1.x<=r2.x){
		if(w1<=w2){
			neww=abs(r2.x-w1);
		}
		else neww=abs(r2.x-w2);
	}
	else{
		if(w1<=w2){
			neww=abs(r1.x-w1);
		}
		else neww=abs(r1.x-w2);
	}

	
	if(r1.y<=r2.y){
		if(h1<=h2){
			newh=abs(r2.y-h1);
		}
		else newh=abs(r2.y-h2);
	}
	else{
		if(h1<=h2){
			newh=abs(r1.y-h1);
		}
		else newh=abs(r2.y-h2);
	}
	return neww*newh;
}