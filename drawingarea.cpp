#include "drawingarea.h"
#include <QPainter>

DrawingArea::DrawingArea(QWidget *parent)
    : QWidget(parent)
{
    shape = 0;
    setMinimumSize(300, 200);
}

void DrawingArea::setShape(Shape *newShape)
{
    shape = newShape;
    update();
}

void DrawingArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);

    if (shape != 0)
    {
        shape->draw(painter);
    }
}
