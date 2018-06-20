#include "widget.h"
#include <QPainter>
#include <iostream>
#include <QKeyEvent>
#include <cmath>
#include <QPushButton>
#include <QLabel>


Widget::Widget(QWidget *parent)
    : QWidget(parent)

{
    r=10;
    width_plate=100;
    height_plate=10;
    plate_speed=40;
    x=width()/2-width_plate-r+width_plate/2;
    y=height()-2*r-height_plate-1;
    alpha=M_PI+0.9;
    speed=1;
    count=5;
    x_plate=width()/2-width_plate;
    y_plate=height()-height_plate;
    m_move=false;
    width_block=width()/5;
    height_block=25;
    x_block1=0;
    x_block2=width()/5;
    x_block3=width()/5 + width()/5;
    x_block4=width()/5 + width()/5 + width()/5;
    x_block5=width()/5 + width()/5 + width()/5 + width()/5;
    y_block=150;
    string_win="Поздравляем!Победа!:3";
    string_game_over="Вы проиграли.";
    button->setGeometry(this->width()/2-20,this->height()/2,20,20);
    button->hide();
    QObject::connect(button,SIGNAL(clicked()),this,SLOT(close()));
    int_alpha=0;



}
void Widget::paintEvent(QPaintEvent * event)
{
 QPainter painter(this);
 painter.setBrush(Qt::red);
 painter.drawEllipse(x,y,2*r,2*r);
 painter.setBrush(Qt::green);
 painter.drawRect(x_plate,y_plate,width_plate,height_plate);
 painter.setBrush(Qt::blue);
 painter.drawRect(x_block1,y_block,width_block,height_block);
 painter.drawRect(x_block2,y_block,width_block,height_block);
 painter.drawRect(x_block3,y_block,width_block,height_block);
 painter.drawRect(x_block4,y_block,width_block,height_block);
 painter.drawRect(x_block5,y_block,width_block,height_block);

}
void Widget::keyPressEvent(QKeyEvent * event)
{
if(event->key()==Qt::Key_Left)
{if(x_plate>=0)
    x_plate-=plate_speed;}
if(event->key()==Qt::Key_Right)
{if(x_plate<width()-width_plate)
    x_plate+=plate_speed;}
 if(event->key()==Qt::Key_Up)
    {
    m_move=true;
 }

 repaint();
}
void Widget::keyReleaseEvent(QKeyEvent * event)
{


}
Widget::~Widget()
{

}
void Widget::Update()
{


      if(y>=height())
        {
            emit game_over1(string_game_over);
        }

       if(y<=0  || x<=0 || x>=width()-2*r || (y>=y_plate-2*r && x>=x_plate && x<=x_plate+width_plate))
        {
           if(y<=0)
           {if(x<width()/2)
                alpha+=2*M_PI-2*alpha;
            else
                alpha+=-2*M_PI+2*alpha;
           }
           if(x<=0)
           {

               if(y<height()/2)
                 alpha+=(2*M_PI-2*alpha);
               else
                 alpha+=(-2*M_PI+2*alpha);

           }
           if(x>=width()-2*r)
           {
               if(y>height()/2)
                   alpha+=2*M_PI-2*alpha;
               else
                   alpha+=-2*M_PI+2*alpha;
           }
           if(y>=y_plate-2*r && x>=x_plate && x<=x_plate+width_plate)
           {
                if(x>x_plate)
                  alpha+=2*M_PI-2*alpha;
                    else
                  alpha+=-2*M_PI+2*alpha;
           }
        }
       if(x_block1>=0 && x>=x_block1 && x<x_block1+width_block && y>= y_block && y<=y_block+height_block  )
        {
            x_block1=-500;
            alpha=M_PI-alpha;
              --count;
        }
       if(x_block2>0 && x>=x_block2 && x<x_block2+width_block && y>= y_block && y<=y_block+height_block  )
        {
            x_block2=-500;
            alpha=M_PI-alpha;
              --count;
        }
       if(x_block3>0 && x>=x_block3 && x<x_block3+width_block && y>= y_block && y<=y_block+height_block  )
        {
            x_block3=-500;
            alpha=M_PI-alpha;
              --count;
        }
       if(x_block4>0 && x>=x_block4 && x<x_block4+width_block && y>= y_block && y<=y_block+height_block  )
        {
            x_block4=-500;
            alpha=M_PI-alpha;
              --count;
        }
       if(x_block5>0 && x>=x_block5  && y>= y_block && y<=y_block+height_block  )
        {
            x_block5=-500;
            alpha=M_PI-alpha;
              --count;
        }
       if(m_move)
       {

        x+=speed*cos(alpha);
        y+=speed*sin(alpha);
        repaint();
       }

        if(count==0)
        {
            emit win1(string_win);
        }

        repaint();

}
void Widget::win(QString data)
{

    QLabel * win2=new QLabel(data,this);
    win2->setGeometry(this->width()/2-80,this->height()/2-20,150,20);
    speed=0;
    plate_speed=0;
    win2->show();
    button->show();

}
void Widget::game_over(QString  data)
{

    QLabel * game_over2=new QLabel(data,this);
    game_over2->setGeometry(this->width()/2-50,this->height()/2-20,100,20);
    speed=0;
    plate_speed=0;
    game_over2->show();
    button->show();
}
