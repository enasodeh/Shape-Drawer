#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QWidget>
#include "shape.h"

class DrawingArea : public QWidget
{
    Q_OBJECT

private:
    Shape *shape;

public:
    explicit DrawingArea(QWidget *parent = 0);

    void setShape(Shape *newShape);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif
