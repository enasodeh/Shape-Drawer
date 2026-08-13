#ifndef SHAPELISTMEMENTO_H
#define SHAPELISTMEMENTO_H

#include <QList>
#include "shape.h"

class ShapeListMemento
{
private:
    QList<Shape*> savedShapes;

public:
    ShapeListMemento(const QList<Shape*> &shapes);
    ~ShapeListMemento();

    QList<Shape*> getSavedShapes() const;
};

#endif
