//
//  Level.cpp
//  diablo
//
//  Created by Kosuke Takami on 2013/09/30.
//
//

#include "Level.h"

Level::Level(){
    currentLevel = 1;
    exp = 0;
}

Level::~Level(){
}

int Level::addExp(int addedExp) {
    this->exp += addedExp;
    int nextLevel = LevelMaster::getLevel(this->currentLevel, this->exp);
    this->currentLevel = nextLevel;
    
    return nextLevel - this->currentLevel;
}

int Level::getCurrentLevel(){
    return currentLevel;
}

int Level::getCurrentExp(){
    return exp;
}