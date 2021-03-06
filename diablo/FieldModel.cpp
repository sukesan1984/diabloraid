//
//  FieldModel.cpp
//  diablo
//
//  Created by Kosuke Takami on 2013/10/12.
//
//

#include "FieldModel.h"


static int WIDTH  = 5; //Fieldの横幅
static int HEIGHT = 5; //Fieldの縦幅


FieldModel::FieldModel(){
}

FieldModel::~FieldModel(){
}

int FieldModel::getWidth(){
    return WIDTH;
}

int FieldModel::getHeight(){
    return HEIGHT;
}

void FieldModel::set(int x, int y, int panelId){
    CCAssert((x >=0 && x <= WIDTH && y <= HEIGHT && y >= 0), "x, y must be from 0 to max Size");
    
    CCDictionary* _dictionary = (CCDictionary*) this->objectForKey(x);
    if(_dictionary != NULL){
        _dictionary->setObject(CCInteger::create(panelId), y);
    } else {
        _dictionary = CCDictionary::create();
        _dictionary->retain();
        this->setObject((CCObject*) _dictionary, x);
        _dictionary->setObject(CCInteger::create(panelId), y);
    }
}

int FieldModel::get(int x, int y){
    CCAssert((x >=0 && x <= WIDTH && y <= HEIGHT && y >= 0), "x, y must be from 0 to max Size");
    
    CCDictionary* _dictionary = (CCDictionary*) this->objectForKey(x);
    if(_dictionary != NULL){
        CCInteger* panelId = (CCInteger*) _dictionary->objectForKey(y);
        if(panelId){
            return panelId->getValue();
        }
    }
    //セットされていない時は-1を返す。
    return -1;
}

FieldModel* FieldModel::create(){
    FieldModel* pRet = new FieldModel();
    if (pRet != NULL)
    {
        pRet->autorelease();
    }
    return pRet;
}

void FieldModel::setMockData(){
    for(int i = 0; i <= WIDTH; i++){
        for( int j = 0; j <= HEIGHT; j++){
            this->set(i, j, (rand() % 6));
        }
    }
}