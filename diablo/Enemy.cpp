//
//  Enemy.cpp
//  diablo
//
//  Created by Kosuke Takami on 13/09/06.
//
//

#include "Enemy.h"

Enemy::Enemy(){
    hp = new HitPoint();
    _connectType = 1;
    strength = new Strength(5);
    defense = new Defense(5);
    
    //CCLog("%s",CCString::createWithFormat("%d", hp->getCurrentHp())->getCString());
    //currentHpLabel = CCLabelTTF::create(CCString::createWithFormat("%d", hp->getCurrentHp())->getCString(), "arial", 8);
    //currentHpLabel->setPosition(ccp(54, 54));
    //this->addChild(currentHpLabel);
    
    //defenseLabel = CCLabelTTF::create(CCString::createWithFormat("%d", defense->getValue())->getCString(), "arial", 4);
    //defenseLabel->setPosition(ccp(54, 20));
    //this->addChild(defenseLabel);
    
    //strengthLabel = CCLabelTTF::create(CCString::createWithFormat("%d", strength->getValue())->getCString(), "arial", 4);
    //strengthLabel->setPosition(ccp(54, 0));
    //this->addChild(strengthLabel);
}

Enemy* Enemy::createWithSpriteFrameName(const char *pszSpriteFrameName){
    Enemy* sprite = new Enemy();
    
    sprite->_panelName = pszSpriteFrameName;
    if(sprite && sprite->initWithSpriteFrameName((sprite->_panelName + ".png").c_str())){
        sprite->_touchRect = *new CCRect();
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return NULL;
}

// override
void Enemy::setRemoved(Player* player){
    // hpが今回の攻撃で0を下回る時だけ_willRemovedをたてる。
    // プレイヤーからのダメージをどう知るか。// Enemyがplayerを知っている？
    if(hp->getCurrentHp() - player->getTotalDamage() <= 0){
        _willRemoved = true;
    }
}

// ダメージ増減ロジック
// つながっているパネルが剣敵A剣剣敵B剣とすると
// 剣敵まで来た時に、敵にダメージ
// 剣敵剣と来たときに、追加ダメージ
// 剣敵剣から敵に戻した時は、敵を回復


void Enemy::attack(Player* player){
    player->damage(strength->getValue());
}

Enemy::~Enemy(){
    delete strength;
    delete defense;
    delete hp;
}

