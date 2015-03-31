#include "st09.h"
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;

st09::st09()
{
	srand(time(NULL));
    setIdentifier("GiHe");//Your name here
}

st09::~st09() {}

void st09::init()
{
	int i;
	for (i = 1; i <= 2; i++)
		increaseHealth();
    for (i = 1; i <= 1; i++)
    	increaseStrength();
    for (i = 1; i <= 6; i++)
    	increaseSpeed();
    increaseArmor();
}

int st09::assess(int i, int j)
{
	int temp = 100 - abs(i - 20) - abs(j - 20);
	return temp / 5;
}

void st09::play()
{
	static int round = 0;
	round++;
	double armorrate;
	if (round < 100) armorrate = 10.0 / (10.0 + round / 11.0);
	else armorrate = 10.0 / (10.0 + round / 16.0);
	armorrate = 1;
	int value[44][44];
	int i, j, k, l, d, sx, sy, q;
	int dx[5] = {0,-1,0,1,0};
	int dy[5] = {0,0,-1,0,1};
	
	
	//加点部分 
	static int pointround = 0;
	while (getPoint()) {
	pointround++;
	if (getSp() <= 15)
	{
		if (getPoint()) increaseHealth();
		if (getPoint()) increaseSpeed();
		if (pointround % 6 == 1) increaseHealth();
		else if (pointround % 6 == 2) increaseStrength();
		else if (pointround % 6 == 3) increaseHealth();
		else if (pointround % 6 == 4) increaseStrength();
		else if (pointround % 6 == 5) increaseArmor();
		else if (pointround % 6 == 0) increaseArmor();
	}
	else 
	if (getSp() <= 25)
	{
		if (getPoint()) increaseHealth();
		if (getPoint()) if (pointround % 3 <= 1) increaseSpeed();
						else increaseStrength();
		if (pointround % 6 == 1) increaseHealth();
		else if (pointround % 6 == 2) increaseStrength();
		else if (pointround % 6 == 3) increaseHealth();
		else if (pointround % 6 == 4) increaseStrength();
		else if (pointround % 6 == 5) increaseArmor();
		else if (pointround % 6 == 0) increaseArmor();
	}
	else {
		if (getPoint()) if (pointround % 2 == 1) increaseHealth();
						else increaseArmor();
		if (getPoint()) increaseStrength();
		if (pointround % 6 == 1) increaseStrength();
		else if (pointround % 6 == 2) increaseStrength();
		else if (pointround % 6 == 3) increaseSpeed();
		else if (pointround % 6 == 4) increaseStrength();
		else if (pointround % 6 == 5) increaseStrength();
		else if (pointround % 6 == 0) increaseArmor();
	}
	}
	
	//value[][] 表示每个下一步可能到达点对未来的局势的评估 
	memset(value, 0, sizeof(value));
	for (i = 1; i<= N ; i++) 
		for (j = 1; j <= M; j++) 
		if (askWhat(i, j) == EMPTY) {
			value[i][j] = 0;
			if (round > 100) {
				value[i][j] = 100 - abs(i - 20) - abs(j - 20);
				value[i][j] /= 5;
		    }
			for (k = 1; k <= N; k++)
				for (l = 1; l <= M; l++) 
				if (k != getX() || l != getY()){
					d = abs(k - i) + abs(l - j);
					if (d <= getSp()) {
						if (askWhat(k, l) == FOOD) value[i][j] += 2 * (assess(k, l));
						if (askWhat(k, l) > 0) {
							int id = askWhat(k, l);
							if (askHP(id) <= getAtt() * 2 * armorrate) value[i][j] += 3 * (assess(k, l));
							else value[i][j] += assess(k, l);
						}
					}
				}
		}
		
	//第一轮评估，一步之内就可以到达的所有点 
	sx = getX();
	sy = getY();
	bool p = false;
	int choicelv = 0, choicevalue = -1000000, x, y, ax, ay;
	for (i = N ; i > 0 ; i--)
	  for (j = M; j > 0 ; j--) {
		if (askWhat(i, j) == EMPTY){
			d = abs(i - sx) + abs(j - sy);
			if (d <= getSp()) {
				for(q = 1; q <= 4; q++) {
						int tx = i + dx[q], ty = j + dy[q];
						if (!(tx > 0 && tx <= N && ty >0 && ty <= M)) continue;
						//if ((dx && dy) || (!dx && !dy)) continue;
						if (!(tx != getX() || ty != getY())) continue;
						if (getHP() > getMaxHP() - 8)
						if (askWhat(tx, ty) > 0) {
							int id = askWhat(tx, ty);
							if (askHP(id) <= getAtt() * armorrate) {
								if (3 > choicelv || (3 == choicelv && value[i][j] > choicevalue)) {
									choicelv = 3;
									value[i][j] = choicevalue;
									x = i;
									y = j;
									ax = tx;
									ay = ty;
									p = true;
								}
							}
						}
						if (askWhat(tx, ty) == FOOD) {
							if (2 > choicelv || (choicelv == 2 && value[i][j] > choicevalue)) {
									choicelv = 2;
									value[i][j] = choicevalue;
									x = i;
									y = j;
									ax = tx;
									ay = ty;
									p = true;
							}
						}
						if (getHP() > getMaxHP() - 8)
						if (askWhat(tx, ty) > 0){
							int id = askWhat(tx, ty);
							if (askHP(id) <= getAtt() * 3 * armorrate) {
								if (1 > choicelv || (1 == choicelv && value[i][j] > choicevalue)) {
									choicelv = 1;
									value[i][j] = choicevalue;
									x = i;
									y = j;
									ax = tx;
									ay = ty;
									p = true;
								}
							}
						}
					}
			}
		}
	  }
    if (p) {
    	move(x, y);
    	attack(ax, ay);
    	return;
    }
    
    //一轮评估无结果 进行二轮评估 以value函数为准
    sx = getX();
	sy = getY();
	int posvalue = -1000000;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++) 
		if (askWhat(i, j) == EMPTY) {
			d = abs (i - sx) + abs(j - sy);
			if (d <= getSp()) {
				if (value[i][j] > posvalue) {
					posvalue = value[i][j];
					x = i; 
					y = j;
				}
			}
		}
	move(x, y);
	return;
}

void st09::revive(int& x,int& y) {
	int i, j, d, l, k;
	int ans = -1000000;
	x = 24, y = 24;
	for (i = 25; i <= N; i++)
		for (j = 25; j <= M; j++) 
		if (askWhat(i, j) == EMPTY){
			int temp = 0;
			for (k = 1; k <= N; k++)
				for (l = 1; l <= M; l++) {
					d = abs(k - i) + abs(j - l) - 1;
					if (d <= getSp())
					if (askWhat(k, l) == FOOD) temp++;
					if (askWhat(k, l) > 0) temp -= 2;
				}
			if (temp > ans) {
				ans = temp;
				x = i; y = j;
			}
		}
}
