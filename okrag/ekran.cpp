#include "ekran.h"
#include <QPainter>
#include <QMouseEvent>
#include <cstdio>
#include <cstdlib>
#include <cmath>



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
    im.fill(0);
    p2.y=e->pos().y();
    R=sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2));
    xe=ceil(R/sqrt(2));
    for(int x=0;x<=xe;x++)
    {
        y=sqrt(pow(R,2)-pow(x,2))+0.5;
        drawPixel(x+p1.x,y+p1.y,255,255,255);
        drawPixel(y+p1.x,x+p1.y,255,255,255);
        drawPixel(-x+p1.x,y+p1.y,255,255,255);
        drawPixel(y+p1.x,-x+p1.y,255,255,255);
        drawPixel(-x+p1.x,-y+p1.y,255,255,255);
        drawPixel(-y+p1.x,-x+p1.y,255,255,255);
        drawPixel(x+p1.x,-y+p1.y,255,255,255);
        drawPixel(-y+p1.x,x+p1.y,255,255,255);
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
