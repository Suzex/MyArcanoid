#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT
private :
    double speed_place,x,y,alpha,speed,r,x_plate, y_plate,plate_speed,width_plate,height_plate,x_block1,x_block2,x_block3,x_block4,x_block5,y_block,width_block,height_block,count;
    bool m_move;
    QString string_win;
    QString string_game_over;
    QPushButton * button=new QPushButton("OK",this);
    int int_alpha;

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent * event);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
public slots:
   void Update();
   void win(QString);
   void game_over(QString);
signals:
    void win1(QString);
    void game_over1(QString);
};

#endif // WIDGET_H
