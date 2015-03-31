#ifndef FISH_H
#define FISH_H

#include "constants.h"
#include "game.h"
class host;
class fish{
    friend class host;
private:
    int ID;
    host * computer;
    char name[20];
public:
    
    void setHost(host *);
    void setIdentifier(const char*);//设置AI标识符
    int getPoint() const;//返回当前玩家剩余点数
    int getLevel() const;//返回当前玩家等级
    int getExp() const;//返回当前玩家经验
    int getX() const;//返回当前玩家横坐标
    int getY() const;//返回当前玩家纵坐标
    int getHP() const;//返回当前玩家生命值
    int getMaxHP() const;//返回当前玩家生命上限
    int getAtt() const;//返回当前玩家攻击力
    int getSp() const;//返回当前玩家速度
    int getAr() const;//返回当前玩家护甲
    int getID() const;//获取玩家ID
    int getTotalPlayer() const;//获取玩家总人数
    int askWhat(int x, int y) const;//返回地图某个位置内容（玩家ID或FOOD或EMPTY或INVALID_VALUE）
    int askHP(int) const;//询问某个玩家ID当前血量
    bool move(int,int);//移动到某个位置（返回操作成功与否，下同）
    bool attack(int,int);//攻击某个位置
    bool increaseHealth();//增加Health属性
    bool increaseStrength();//增加Strength属性
    bool increaseSpeed();//增加Speed属性
    bool increaseArmor(); //增加Armor属性
    //以上函数仅由系统实现，供AI调用

    virtual void init() = 0;//初始化函数，每一局重新开始将调用
    virtual void play() = 0;//行动函数，每回合行动将调用
    virtual void revive(int&,int&) = 0;//复活时调用，参数传回选择复活位置（若不合法则随机）
    //以上函数仅由继承AI实现

    fish();//构造函数，AI需在其中调用一次setIdentifier函数，将标示符作为参数传入
    virtual ~fish();//析构函数
    //以上函数由系统与AI共同实现
};

//可自行增加所需函数及变量，但需保证上面每个函数的完整与可调用

//不要使用全局变量!!!

#endif
