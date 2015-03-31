#include "st13.h"
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>

void st13::add(){
	int k;
	while (getPoint()) if (getLevel() <= 10){
		k = pt % 6;
		if (k == 2) increaseStrength();
		if ((k == 0 || k == 4) && getSp() <= 14) increaseSpeed();
		if (k == 1 || k == 3 || k == 5) increaseHealth();
		pt++;
	}
	else if (getLevel() <= 20){
		k = pt % 12;
		if (k == 0 || k == 3 || k == 6 || k == 8 || k == 10) increaseStrength();
		if (k == 1 || k == 4 || k ==7 || k == 11) increaseHealth();
		if ((k == 2 || k == 9) && getSp() <= 17) increaseSpeed();
		if (k == 5) increaseArmor();
		pt++;
	}else{
		k = pt % 12;
		if ((k == 7) && getAr() <= 20) increaseArmor();
		if (k == 0 || k == 2 || k == 5 || k ==8 || k == 11) increaseStrength();
		if (k == 1 || (k == 4 && getLevel() <= 35) || k == 6 || k == 9) increaseHealth();
		if ((k == 3 || k == 10) && getSp() <= 40) increaseSpeed();
		pt++;
	}
}

st13::st13(){
	srand(time(NULL));
	setIdentifier("courage");
	for (int i = 1;i <= MAX_PLAYER;i++) dam[i] = 1;
	pt = 0;
}

st13::~st13() {}

void st13::init(){
	for (int i=1;i<=1;i++) increaseStrength();
	for (int i=1;i<=2;i++) increaseHealth();
	for (int i=1;i<=7;i++) increaseSpeed();
}

void st13::play(){
	int k,f[4][2]={{1,0},{-1,0},{0,1},{0,-1}},x,y,p,q,p1,q1;
	double mx;
	bool flag=1;
	add();
	mx = 99999;
	p = q = p1 = q1 = 0;
	if (getHP() * 3 > getMaxHP() * 2) for (int i = 1;i <= N ;i++)
		for (int j = 1;j <= M;j++){
			if (abs(i - getX())+abs(j - getY()) > getSp()) continue;
			if (askWhat(i,j) == 0 || (i == getX() && j == getY()))
				for (int k = 0;k < 4;k++){
					x = i + f[k][0];
					y = j + f[k][1];
					if (x == getX() && y == getY()) continue;
					if (x < 1 || x > N || y < 1 || y > M) continue;
					if (askWhat(x,y) <= 0) continue;
					int ene = askWhat(x,y);
					if (askHP(ene) > getAtt() * dam[ene]) continue;
					flag=0;
					int rat = (double) askHP(ene) / (dam[ene] * getAtt());
					if (mx > rat){
						mx = rat;
						p = i;
						q = j;
						p1 = x;
						q1 = y;
					}
				}
			}
	if (!flag){
		if (p != getX() || q != getY()) move(p,q);
		int m = askWhat(p1,q1);
		int h1 = askHP(m);
		attack(p1,q1);
		int h2 = askHP(m);
		if (h2 && dam[m] > (double)(h1 - h2) / getAtt()) dam[m] = (double)(h1 - h2) / getAtt();
		add();
		return;
	}
	if (getLevel() < 15 || getHP() < 3 * getMaxHP() / 4) for (int i = 1;i <= N ;i++) if (flag)
		for (int j = 1;j <= M;j++) if (flag){
			if (abs(i - getX()) + abs(j - getY()) > getSp()) continue;
			if (askWhat(i,j) == 0)
				for (int k = 0;k < 4;k++){
					x = i + f[k][0];
					y = j + f[k][1];
					if (x < 1 || x > N || y < 1 || y > M || (askWhat(x,y) != -1)) continue;
					flag=0;
					move(i,j);
					attack(x,y);
					add();
					return ;
				}
			}
	mx = 99999;
	p = q = p1 = q1 = 0;
	if (flag) for (int i = 1;i <= N ;i++)
		for (int j = 1;j <= M;j++){
			if (abs(i - getX()) + abs(j - getY()) > getSp()) continue;
			if (askWhat(i,j) == 0 || (i == getX() && j == getY()))
				for (int k=0;k<4;k++){
					x = i + f[k][0];
					y = j + f[k][1];
					if (x == getX() && y == getY()) continue;
					if (x < 1 || x > N || y < 1 || y > M) continue;
					if (askWhat(x,y) <= 0) continue;
					int ene = askWhat(x,y);
					flag=0;
					if (mx > askHP(ene) / (dam[ene] * getAtt())){
						mx = askHP(ene) / (dam[ene] * getAtt());
						p = i;
						q = j;
						p1 = x;
						q1 = y;
					}
				}
			}
	if (!flag && (mx > 3 || mx < 1.2)) flag = 1;
	if (!flag){
		if (p != getX() || q != getY()) move(p,q);
		int m = askWhat(p1,q1);
		int h1 = askHP(m);
		attack(p1,q1);
		int h2 = askHP(m);
		if (h2 && dam[m] > (double)(h1 - h2) / getAtt()) dam[m] = (double)(h1 - h2) / getAtt();
		add();
		return;
	}
	if (flag) for (int i = 1;i <= N ;i++)
		for (int j = 1;j <= M;j++){
			if (abs(i - getX())+abs(j - getY()) > getSp()) continue;
			if (askWhat(i,j) == 0)
				for (int k = 0;k < 4;k++){
					x = i + f[k][0];
					y = j + f[k][1];
					if (x < 1 || x > N || y < 1 || y > M || (askWhat(x,y) != -1)) continue;
					flag=0;
					move(i,j);
					attack(x,y);
					add();
					return;
				}
			}
	add();
	int t=0;
	if (flag){
		int p[4] = {0},f[4][2] = {{1,1},{-1,-1},{1,-1},{-1,1}};
		for (int i = 1;i <= N;i++)
			for (int j = 1;j <= M;j++) if ((i != getX() || j != getY()) && askWhat(i,j)){
				int im = 1;
				if (askWhat(i,j) > 0) im = 5;
				if (i < getX())
					if (j < getY()) p[1] += im;else p[3] += im;
				else
					if (j < getY()) p[2] += im;else p[0] += im;
			}
		k = 0;
		for (int i = 1;i <= 3;i++) if (p[i] > p[k]) k = i;
		int x = getX() + getSp() / 2 * f[k][0];
		int y = getY() + getSp() / 2 * f[k][1];
		int step = 0;
		while (1){
			step++;
			if (step > 1000) break;
			if (0 < x && x <= N && 0 < y && y <= M && askWhat(x,y) == 0 && abs(getX() - x) + abs(getY() - y) <= getSp()){
				move(x,y);
				return;
			}
			x += (rand() % 3 - 1);
			y += (rand() % 3 - 1);
		}
		while (1){
			x = rand() % N;
			y = rand() % M;
			if (0 < x && x <= N && 0 < y && y <= M && askWhat(x,y) == 0 && abs(getX() - x) + abs(getY() - y) <= getSp()){
				move(x,y);
				return;
			}
		}
	}
}

void st13::revive(int& x,int& y){
	int xx,yy,i,j,f[4][2]={{1,0},{-1,0},{0,1},{0,-1}},t;
	t = 0;
	while (1){
		if (t > 100000) break;
		i = rand() % N + 1;
		j = rand() % M + 1;
		if (askWhat(i,j)) continue;
		for (int k = 0;k < 4;k++){
			xx = i + f[k][0];
			yy = j + f[k][1];
			if (0 < xx && xx <= N && 0 < yy && yy <= M && askWhat(xx,yy) == 0){
				x = xx;
				y = yy;
				return;
				}
		}
		t++;
	}
	while (1){
		x = rand() % N + 1;
		y = rand() % M + 1;
		if (askWhat(x,y)) continue;
		return;
	}
}
