#include "ekran.h"
#include <QPainter>
#include <QMouseEvent>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;


Ekran::Ekran(QWidget *parent)
    : QWidget{parent}
{
    im=QImage(1000, 1000, QImage::Format_RGB32);
    im.fill(0);
}

void Ekran::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawImage(0,0,im);
}

void Ekran::mouseMoveEvent(QMouseEvent *e)
{
    p2.x=e->pos().x();
    p2.y=e->pos().y();
    im.fill(0);
    int x,y;
    double alfa;
    int xo=(p1.x+p2.x)/2;
    int yo=(p1.y+p2.y)/2;
    int R1=(abs(p2.x-p1.x))/2;
    int R2=(abs(p2.y-p1.y))/2;
    int xold=R1*cos(0);
    int yold=R2*sin(0);
    for(int i=1;i<=N;i++)
    {
        alfa=2*M_PI*i/N;
        x=R1*cos(alfa);
        y=R2*sin(alfa);
        linia(x+xo,y+yo,xold+xo,yold+yo);
        xold=x;
        yold=y;

    }
    update();
}

void Ekran::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        p1.x=e->pos().x();
        p1.y=e->pos().y();
    }
}

void Ekran::drawPixel(int x,int y,int r,int g,int b)
{
    if((x<im.width()&&x>=0)&&(y<im.height()&&y>=0))
    {
        uchar *pix=im.scanLine(y)+4*x;
        pix[0]=r;
        pix[1]=g;
        pix[2]=b;
    }

}

void Ekran::linia(int x1,int y1,int x2,int y2)
{
    if(abs(y2-y1)<=abs(x2-x1))
        {
            float y=y1;
            float a=(float)(y2-y1)/(x2-x1);
            if(x1<x2)
            {
                for(int i=x1;i<=x2;i++)
                {
                    drawPixel(i+0.5,y+0.5,255,255,255);
                    y+=a;
                }
            }
            else
            {
                for(int i=x1;i>=x2;i--)
                {
                    drawPixel(i+0.5,y+0.5,255,255,255);
                    y-=a;
                }
            }

        }
        else
        {
            float x=x1;
            float a=(float)(x1-x2)/(y1-y2);
            if(y1<y2)
            {
                for(int i=y1;i<=y2;i++)
                {
                    drawPixel(x+0.5,i+0.5,255,255,255);
                    x+=a;
                }
            }
            else
            {
                for(int i=y1;i>=y2;i--)
                {
                    drawPixel(x+0.5,i+0.5,255,255,255);
                    x-=a;
                }
            }
        }
}

void Ekran::setValue(int a)
{
    N=a;
}
