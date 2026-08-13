#include "shapelistmemento.h"

ShapeListMemento::ShapeListMemento(const QList<Shape*> &shapes)
{
    for (int i = 0; i < shapes.size(); i++)
    {
        savedShapes.append(shapes[i]->clone());
    }
}

ShapeListMemento::~ShapeListMemento()
{
    for (int i = 0; i < savedShapes.size(); i++)
    {
        delete savedShapes[i];
    }

    savedShapes.clear();
}

QList<Shape*> ShapeListMemento::getSavedShapes() const
{
    QList<Shape*> copiedShapes;

    for (int i = 0; i < savedShapes.size(); i++)
    {
        copiedShapes.append(savedShapes[i]->clone());
    }

    return copiedShapes;
}
