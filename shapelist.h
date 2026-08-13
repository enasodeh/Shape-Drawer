#ifndef SHAPELIST_H
#define SHAPELIST_H

#include <QList>
#include "shape.h"
#include "shapelistmemento.h"

class ShapeList
{
private:
    QList<Shape*> shapes;
    int currentIndex;

    static ShapeList *instance;
    ShapeListMemento *backup;

    ShapeList();

    void clearShapes();

public:
    static ShapeList* getInstance();

    ~ShapeList();

    void addShape(Shape *shape);

    Shape* getCurrentShape();
    Shape* getNextShape();
    Shape* getPreviousShape();
    Shape* getFirstShape();

    bool isEmpty() const;

    void backupState();
    bool restoreState();
};

#endif
