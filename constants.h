#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

const int N=40;//地图横坐标范围1-N
const int M=40;//地图纵坐标范围1-M
const int MAX_PLAYER=40;//最多玩家数量，ID从1-MAX_PLAYER
const int MAX_FOOD=50;//刷新食物数量
const int FOOD_ROUND=5;//刷新食物回合数
const int EMPTY=0;//格子为空
const int FOOD=-1;//食物
const int INVALID_VALUE = -2; //操作非法时返回值
const int LEVEL_POINT=3;//升级能获得的点数
const int ARMOR_CONSTANT=10;//护甲常数。玩家实际受到伤害比例为ARMOR/(ARMOR_CONSTANT+ARMOR)
const int KILL_AWARD=3;//低等级玩家击杀高等级玩家时获得的奖励系数。奖励EXP=KILL_AWARD*DELTA_LEVEL
const int INITIAL_PROPERTY_POINT = 10;  //初始属性点
const int MAX_ROUND = 500; //游戏回合数

#endif // _CONSTANTS_H_
