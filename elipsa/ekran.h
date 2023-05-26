#ifndef EKRAN_H
#define EKRAN_H

#include <QWidget>

struct colorAtPixel
{
    int x;
    int y;
    uchar red;
    uchar green;
    uchar blue;
};

struct coord
{
    int x;
    int y;
};

class Ekran : public QWidget
{
    Q_OBJECT
public:
        explicit Ekran(QWidget *parent = nullptr);
        void setValue(int);
        int N;
protected:
        void paintEvent(QPaintEvent *);
        void mouseMoveEvent(QMouseEvent *);
        void mousePressEvent(QMouseEvent *);
        void linia(int x1,int y1,int x2,int y2);
private:
        QImage im;
        void drawPixel(int x,int y, int r,int g,int b);
        coord p1;
        coord p2;
signals:

};

#endif // EKRAN_H
