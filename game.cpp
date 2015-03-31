#include <cstring>
#include <QString>

#include "game.h"

void host::renewScore(int ID){
    player[ID].Score = player[ID].Exp + player[ID].Kill * 5 - player[ID].Death * player[ID].Death / 5;
    char s[20];
    int k;
    for (k = 0;k < tot;k++) if (rank[k + 1] == ID) break;
    if (k >= tot) return;
    trans(player[ID].Score,s);
    ui->tableWidget->item(k,3)->setText(s);
}

void host::renewLevel(int ID){
    while (player[ID].Exp >= (player[ID].Level + 1) * (player[ID].Level + 2) / 2 - 1){
        player[ID].Level++;
        player[ID].Point += LEVEL_POINT;
    }
}

int host::damage(int a,int b) const{
    int x = player[a].Att;
    x = x * 10 / (ARMOR_CONSTANT + player[b].Ar);
    if (x < 0) x = 1;
    return x;
}

int host::max(int a,int b) const{
    return a > b ? a : b;
}

int host::abs(int x) const{
    return x > 0 ? x : -x;
}

int host::getPoint(int ID) const{
    return player[ID].Point;
}

int host::getLevel(int ID) const{
    return player[ID].Level;
}

int host::getExp(int ID) const{
    return player[ID].Exp;
}

int host::getX(int ID) const{
    return player[ID].X;
}

int host::getY(int ID) const{
    return player[ID].Y;
}

int host::getHP(int ID) const{
    return player[ID].HP;
}

int host::getMaxHP(int ID) const{
    return player[ID].maxHP;
}

int host::getAtt(int ID) const{
    return player[ID].Att;
}

int host::getSp(int ID) const{
    return player[ID].Sp;
}

int host::getAr(int ID) const{
    return player[ID].Ar;
}

int host::getID(int ID) const{
    return ID;
}

int host::getTotalPlayer() const{
    return tot;
}

int host::askWhat(int x, int y) const{
    if (x < 1 || x > N || y < 1 || y > M) return -2;
    return map[x][y];
}

int host::askHP(int ID) const{
    return player[ID].HP;
}

int host::askMaxHP(int ID) const{
    return player[ID].maxHP;
}

bool host::move(int ID,int x,int y){
    QString s;
    char t1[10];
    s = player[ID].identifier;
    trans(ID,t1);
    s = s + "(" + t1 + ")";
    trans(x,t1);
    s = s + " 准备移动到 (" + t1 + ",";
    trans(y,t1);
    s = s + t1 + ")\n";
    bool sta = 1;
    if (x < 1 || x > N || y < 1 || y > M) sta = 0;else
        if (map[x][y] != EMPTY) sta = 0;else
            if (player[ID].Moved || player[ID].Attacked) sta = 0;else
                if (abs(player[ID].X - x) + abs(player[ID].Y - y) > player[ID].Sp) sta = 0;
    if (sta) s = s + "操作成功!\n\n";else s = s + "操作失败!\n\n";
    text = s;
    if (!sta) return 0;
    int k;
    for (k = 0;k < tot;k++) if (rank[k + 1] == ID) break;
    trans(x,t1);
    ui->tableWidget->item(k,6)->setText(t1);
    trans(y,t1);
    ui->tableWidget->item(k,7)->setText(t1);
    int t = 0,x1 = player[ID].X,y1 = player[ID].Y,nx,ny;
    while (x1 != x){
        nx = x1;
        if (x1 < x) nx++;else nx--;
        map[x1][y1] = t;
        t = map[nx][y1];
        map[nx][y1] = ID;
        ui->widget->repaint();
        x1 = nx;
        int time1 = clock();
        while ((clock() - time1) * 10 <= ma->delay) QApplication::processEvents();
    }
    map[x1][y1] = t;
    while (y1 != y){
        ny = y1;
        if (y1 < y) ny++;else ny--;
        map[x1][y1] = t;
        t = map[x1][ny];
        map[x1][ny] = ID;
        ui->widget->repaint();
        y1 = ny;
        int time1 = clock();
        while ((clock() - time1) * 10 <= ma->delay) QApplication::processEvents();
    }
    map[x][y] = ID;
    player[ID].X = x;
    player[ID].Y = y;
    player[ID].Moved = 1;
    int time1 = clock();
    while (clock() - time1 <= ma->delay) QApplication::processEvents();
    return 1;
}

bool host::attack(int ID,int x,int y){
    QString s;
    char t[10];
    bool sta = 1;
    s = text;
    s = s + player[ID].identifier + "(";
    trans(ID,t);
    s = s + t + ") 准备攻击";
    s = s + "位于(";
    trans(x,t);
    s = s + t + ",";
    trans(y,t);
    s = s + t + ")的 ";
    if (x < 1 || x > N || y < 1 || y > M || map[x][y] == 0) s = s + "空白";else
        if (map[x][y] == FOOD) s = s + "水藻";else
            s = s + player[map[x][y]].identifier;
    if (x < 1 || x > N || y < 1 || y > M) sta = 0;else
    if (abs(player[ID].X - x) + abs(player[ID].Y - y) != 1) sta = 0;else
    if (player[ID].Attacked) sta = 0;else
    if (map[x][y] == 0) sta = 0;
    if (sta) s = s + "\n操作成功!\n";else s = s + "\n操作失败!";
    text = s;
    if (!sta) return 0;
    if (map[x][y] == FOOD){
        map[x][y] = 0;
        player[ID].HP += max(2,player[ID].maxHP / 4);
        if (player[ID].HP > player[ID].maxHP) player[ID].HP = player[ID].maxHP;
        player[ID].Exp += 1;
    }else{
        player[map[x][y]].HP -= damage(ID,map[x][y]);
        if (player[map[x][y]].HP < 0) player[map[x][y]].HP = 0;
        if (player[map[x][y]].HP == 0){
            int k = map[x][y];
            map[x][y] = 0;
            player[k].X = -2;
            player[k].Y = -2;
            player[ID].Kill++;
            player[k].Death++;
            player[k].Dead = 1;
            player[k].Revive = 3;
            if (player[ID].Level < player[k].Level) player[ID].Exp += KILL_AWARD * (player[k].Level - player[ID].Level);
            player[ID].Exp += max(1,player[k].Level / 2);
            int kk = 0;
            while (rank[kk + 1] != k) kk++;
            renewSta(k,kk);
        }
    }
    renewLevel(ID);
    renewScore(ID);
    player[ID].Attacked = 1;
    ui->widget->repaint();
    return 1;
}

bool host::increaseHealth(int ID){
    if (player[ID].Point == 0) return 0;
    player[ID].Point--;
    player[ID].maxHP += 3;
    player[ID].HP += 3;
    return 1;
}

bool host::increaseStrength(int ID){
    if (player[ID].Point == 0) return 0;
    player[ID].Point--;
    player[ID].Att += 2;
    return 1;
}

bool host::increaseSpeed(int ID){
    if (player[ID].Point == 0) return 0;
    player[ID].Point--;
    player[ID].Sp++;
    return 1;
}

bool host::increaseArmor(int ID){
    if (player[ID].Point == 0) return 0;
    player[ID].Point--;
    player[ID].Ar++;
    return 1;
}


//下面是系统具体实现
void host::init(){
    srand(time(NULL));
    tot = 0;
    memset(map,0,sizeof(map));
}

void host::addFish(fish * f){
    b[++tot] = f;
    f->setHost(this);
}

void host::refreshFood(){
    int x,y,k = 0;
    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= M;j++) if (map[i][j] == FOOD) map[i][j] = 0;
    while (1){
        x = rand() % N + 1;
        y = rand() % M + 1;
        if (map[x][y] != EMPTY) continue;
        k++;
        map[x][y] = FOOD;
        if (k == MAX_FOOD) return;
    }
    ui->widget->repaint();
}

bool host::cmp(int i,int j){
    if (player[i].Sp != player[i].Sp) return player[i].Sp > player[j].Sp;
    if (player[i].HP != player[j].HP) return player[i].HP < player[j].HP;
    if (player[i].Level != player[j].Level) return player[i].Level < player[j].Level;
    if (player[i].Score != player[j].Score) return player[i].Score < player[j].Score;
    return i < j;
}

void host::swap(int & a,int & b){
    int t = a;
    a = b;
    b = t;
}

void host::setUi(Ui::FishTank * u){
    ui = u;
}

bool host::cmp_s(int i,int j){
    if (player[i].Score != player[j].Score) return player[i].Score > player[j].Score;
    if (player[i].Exp != player[j].Exp) return player[i].Level > player[j].Level;
    if (player[i].Sp != player[j].Sp) return player[i].Sp > player[j].Sp;
    return i < j;
}

void host::trans(int x,char * s){
    int p = -1,y = 0,k = 0;
    if (x < 0){
        x = -x;
        s[++p] = '-';
    }
    if (x == 0) k = 1;
    while (x){
        y = y * 10 + x % 10;
        x /= 10;
        k++;
    }
    while (k--){
        s[++p] = y % 10 + '0';
        y /= 10;
    }
    s[p + 1] = 0;
}

void host::setMain(FishTank * m){
    ma = m;
}

char * host::askName(int x,int y){
    return player[map[x][y]].identifier;
}

void host::renewSta(int i,int k){
    char s[20];
    trans(i,s);
    ui->tableWidget->item(k,0)->setText(s);
    ui->tableWidget->item(k,1)->setText(player[i].identifier);
    ui->tableWidget->item(k,2)->setText(player[i].Dead ? "Dead" : "Alive");
    trans(player[i].Score,s);
    ui->tableWidget->item(k,3)->setText(s);
    trans(player[i].Level,s);
    ui->tableWidget->item(k,4)->setText(s);
    trans(player[i].Exp,s);
    ui->tableWidget->item(k,5)->setText(s);
    trans(player[i].X,s);
    ui->tableWidget->item(k,6)->setText(s);
    trans(player[i].Y,s);
    ui->tableWidget->item(k,7)->setText(s);
    trans(player[i].HP,s);
    ui->tableWidget->item(k,8)->setText(s);
    trans(player[i].maxHP,s);
    ui->tableWidget->item(k,9)->setText(s);
    trans(player[i].Att,s);
    ui->tableWidget->item(k,10)->setText(s);
    trans(player[i].Sp,s);
    ui->tableWidget->item(k,11)->setText(s);
    trans(player[i].Ar,s);
    ui->tableWidget->item(k,12)->setText(s);
    trans(player[i].Kill,s);
    ui->tableWidget->item(k,13)->setText(s);
    trans(player[i].Death,s);
    ui->tableWidget->item(k,14)->setText(s);
    ui->tableWidget->repaint();
}


void host::renewRank1(){
    for (int i = 1;i <= tot;i++) renewLevel(i);
    for (int i = 1;i <= tot;i++) renewScore(i);
    int t;
    for (int i = 1;i <= tot;i++) rank[i] = i;
    for (int i = 1;i < tot;i++)
        for (int j = i + 1;j <= tot;j++)
            if (!cmp_s(rank[i],rank[j])){
                t = rank[i];
                rank[i] = rank[j];
                rank[j] = t;
            }
    for (int k = 0;k < tot;k++){
        int i = rank[k + 1];
        renewSta(i,k);
    }
}

void host::begin(){
    int x,y;
    pause = 0;
    played = 1;
    end = 0;
    if (ui->tableWidget->rowCount() < 10){
        for (int i = 1;i <= tot;i++) ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        for (int i = 0;i < tot;i++) ui->tableWidget->setRowHeight(i,20);
        for (int i = 0;i < ui->tableWidget->rowCount();i++)
            for (int j = 0;j < ui->tableWidget->columnCount();j++)
                ui->tableWidget->setItem(i,j,new QTableWidgetItem);
        ui->tableWidget->repaint();
    }
    memset(map,0,sizeof(map));
    bool f[tot + 1];
    memset(f,0,sizeof(f));
    int g[tot + 1];
    for (int i = 1;i <= tot;i++){
        int x = rand() % tot + 1;
        while (f[x]) x = rand() % tot + 1;
        f[x] = 1;
        g[i] = x;
    }
    for (int i = 1;i <= tot;i++) b[i]->ID = g[i];
    for (int i = 1;i <= tot;i++)
        for (int j = 1;j <= tot;j++)
            if (b[j]->ID == i) a[i] = b[j];
    
    for (int i = 1;i <= tot;i++) a[i]->ID = i;
    for (int i = 1;i <= tot;i++){
        player[i].Ar = player[i].Att = player[i].Death = player[i].Exp = player[i].HP = player[i].Kill = 0;
        player[i].Level = 1;
        player[i].Point = INITIAL_PROPERTY_POINT;
        player[i].maxHP = player[i].Score = player[i].Sp = player[i].Revive = 0;
        player[i].Dead = 0;
        while (1){
            x = rand() % N + 1;
            y = rand() % M + 1;
            if (map[x][y] != EMPTY) continue;
            map[x][y] = i;
            player[i].X = x;
            player[i].Y = y;
            break;
        }
    }
    for (int i = 1;i <= tot;i++) a[i]->init();
    for (int i = 1;i <= tot;i++) strcpy(player[i].identifier,a[i]->name);
    for (int r = 1;r <= MAX_ROUND;r++){
        char s[10],t[210]="<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">排行榜(第 ";
        trans(r,s);
        strcat(t,s);
        strcat(t," 轮)</span></p></body></html>");
        ui->label->setText(t);
        ui->label->repaint();
        renewRank1();
        if (r % FOOD_ROUND == 1){
            refreshFood();
            ui->widget->update();
        }
        for (int i = 1;i <= tot;i++) player[i].Moved = player[i].Attacked = 0;
        for (int i = 1;i <= tot;i++) if (!player[i].Dead){
            player[i].Exp++;
            renewLevel(i);
            renewScore(i);
        }
        if (r == 1) for (int j = 1;j <= tot;j++) list[j] = j;
        for (int j = 1;j < tot;j++)
            for (int k = j + 1;k <= tot;k++)
                if (!cmp(list[j],list[k])) swap(list[j],list[k]);
        for (int p = 1;p <= tot;p++){
            int i = list[p];
            if (player[i].Dead){
                player[i].Revive--;
                if (player[i].Revive == 0){
                    player[i].Dead = 0;
                    player[i].HP = max(2,player[i].maxHP / 4);
                    int x = 0,y = 0;
                    a[i]->revive(x,y);
                    if (x < 1 || x > N) x = rand() % N + 1;
                    if (y < 1 || y > M) y = rand() % M + 1;
                    while (map[x][y] != EMPTY){
                        x = rand() % N + 1;
                        y = rand() % M + 1;
                    }
                    player[i].X = x;
                    player[i].Y = y;
                    map[x][y] = i;
                }
            }
            text = "";
            if (!player[i].Dead){
                a[i]->play();
                if (!player[i].Moved){
                    trans(i,s);
                    QString p = "";
                    text = p + player[i].identifier + "(" + s + ")" + " 没有移动\n\n\n" + text;
                }
                if (!player[i].Attacked){
                    trans(i,s);
                    text = text + player[i].identifier + "(" + s + ")" + " 没有攻击\n";
                }
                ui->label_3->setText(text);
            }
            int k = 0;
            while (rank[k + 1] != i) k++;
            renewSta(i,k);
            ui->widget->repaint();
            int time1 = clock();
            while (clock() - time1 <= ma->delay) QApplication::processEvents();
            QApplication::processEvents();
            while (pause && !end) QApplication::processEvents();
            if (end){
                ma->close();
                return;
            }
        }
    }
    
    ui->widget->repaint();
    renewRank1();
    played = 0;
}
