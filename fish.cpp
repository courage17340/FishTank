#include <cstring>

#include "fish.h"

void fish::setHost(host * h){
    computer = h;
}

void fish::setIdentifier(const char * s){
    strcpy(name,s);
}

int fish::getPoint() const{
    return computer->getPoint(ID);
}

int fish::getLevel() const{
    return computer->getLevel(ID);
}

int fish::getExp() const{
    return computer->getExp(ID);
}

int fish::getX() const{
    return computer->getX(ID);
}

int fish::getY() const{
    return computer->getY(ID);
}

int fish::getHP() const{
    return computer->getHP(ID);
}

int fish::getMaxHP() const{
    return computer->getMaxHP(ID);
}

int fish::getAtt() const{
    return computer->getAtt(ID);
}

int fish::getSp() const{
    return computer->getSp(ID);
}

int fish::getAr() const{
    return computer->getAr(ID);
}

int fish::getID() const{
    return ID;
}

int fish::getTotalPlayer() const{
    return computer->getTotalPlayer();
}

int fish::askWhat(int x, int y) const{
    return computer->askWhat(x,y);
}

int fish::askHP(int ID) const{
    return computer->getHP(ID);
}

bool fish::move(int x, int y){
    return computer->move(ID,x,y);
}

bool fish::attack(int x,int y){
    return computer->attack(ID,x,y);
}

bool fish::increaseArmor(){
    return computer->increaseArmor(ID);
}

bool fish::increaseHealth(){
    return computer->increaseHealth(ID);
}

bool fish::increaseSpeed(){
    return computer->increaseSpeed(ID);
}

bool fish::increaseStrength(){
    return computer->increaseStrength(ID);
}

fish::fish(){}

fish::~fish(){
    delete this;
}
