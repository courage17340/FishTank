#include "tank.h"
#include "game.h"

Tank::Tank(QWidget * parent):
    QWidget(parent),
    type(-1){
    connect(this,SIGNAL(customMouseMoveEvent(int,int)),SLOT(showxy(int,int)));
}

Tank::~Tank(){}

void Tank::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(0,0,603,603);
    painter.setPen(Qt::gray);
    for (int i = 0;i <= 600;i += 15) painter.drawLine(i,0,i,601);
    for (int i = 0;i <= 600;i += 75) painter.drawLine(i + 1,0,i + 1,601);
    for (int i = 0;i <= 600;i += 15) painter.drawLine(0,i,601,i);
    for (int i = 0;i <= 600;i += 75) painter.drawLine(0,i + 1,601,i + 1);
    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= M;j++)
            draw(i,j,cmp->askWhat(i,j),painter);
}

void Tank::draw(int p,int q,int k,QPainter & painter){
    int x = (p - 1) * 15,y = (q - 1) * 15;
    if (k == FOOD){
        painter.setPen(Qt::white);
        painter.setBrush(Qt::green);
        painter.drawRect(x + 3,y + 3,10,10);
        return;
    }
    if (k == 0) return;
    char s[10];
    cmp->trans(k,s);
    if (s == ui->lineEdit->text()){
        painter.setBrush(Qt::red);
        painter.setPen(Qt::black);
        painter.drawRect(x + 1,y + 1,14,14);
    }
    painter.setPen(Qt::black);
    painter.setBrush(Qt::white);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawEllipse(x + 1,y + 1,14,14);
    int hp = cmp->askHP(k);
    int mx = cmp->askMaxHP(k);
    x += 8;
    y += 8;
    int r = 7;
    QColor blue(0,0,255);
    QColor purple(160,32,240);
    QColor orange(255,97,0);
    QColor red(255,0,0);
    if (hp * 4 <= mx) painter.setPen(red);else
        if (hp * 2 <= mx) painter.setPen(orange);else
            if (hp * 4 <= mx * 3) painter.setPen(purple);else
                painter.setPen(blue);
    for (int i = x + 7 - 13 * hp / mx;i <= x + 6;i++){
        int w = sqrt(r * r - (i - x) * (i - x));
        painter.drawLine(x - w,y + i - x,x + w,y + i - x);
    }
}

void Tank::setHost(host * H){
    cmp = H;
}

void Tank::setUi(Ui::FishTank * u){
    ui = u;
}

void Tank::enterEvent(QEvent *){
    setMouseTracking(true);
}

void Tank::mouseMoveEvent(QMouseEvent *ev){
    customMouseMoveEvent(ev->x(),ev->y());
}

void Tank::showxy(int x,int y){
    x /= 15;
    y /= 15;
    x++;
    y++;
    if (x < 1 || y < 1 || x > N || y > M) return;
    char s[110],t[10];
    strcpy(s,"坐标:(");
    cmp->trans(x,t);
    strcat(s,t);
    strcat(s,",");
    cmp->trans(y,t);
    strcat(s,t);
    strcat(s,")\n");
    if (cmp->askWhat(x,y) == FOOD) strcat(s,"水藻");else
        if (cmp->askWhat(x,y) == EMPTY) strcat(s,"空白");else{
            cmp->trans(cmp->askWhat(x,y),t);
            strcat(s,"ID:");
            strcat(s,t);
            strcat(s," 玩家:");
            strcat(s,cmp->askName(x,y));
        }
    ui->label_5->setText(s);
}
