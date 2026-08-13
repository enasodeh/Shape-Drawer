#include "shapelist.h"

ShapeList* ShapeList::instance = 0;

ShapeList::ShapeList()
{
    currentIndex = -1;
    backup = 0;
}

ShapeList* ShapeList::getInstance()
{
    if (instance == 0)
    {
        instance = new ShapeList();
    }

    return instance;
}

ShapeList::~ShapeList()
{
    clearShapes();

    if (backup != 0)
    {
        delete backup;
        backup = 0;
    }
}

void ShapeList::clearShapes()
{
    for (int i = 0; i < shapes.size(); i++)
    {
        delete shapes[i];
    }

    shapes.clear();
    currentIndex = -1;
}

void ShapeList::addShape(Shape *shape)
{
    shapes.append(shape);
    currentIndex = shapes.size() - 1;
}

Shape* ShapeList::getCurrentShape()
{
    if (shapes.isEmpty())
    {
        return 0;
    }

    return shapes[currentIndex];
}

Shape* ShapeList::getNextShape()
{
    if (shapes.isEmpty())
    {
        return 0;
    }

    currentIndex++;

    if (currentIndex >= shapes.size())
    {
        currentIndex = 0;
    }

    return shapes[currentIndex];
}

Shape* ShapeList::getPreviousShape()
{
    if (shapes.isEmpty())
    {
        return 0;
    }

    currentIndex--;

    if (currentIndex < 0)
    {
        currentIndex = shapes.size() - 1;
    }

    return shapes[currentIndex];
}

Shape* ShapeList::getFirstShape()
{
    if (shapes.isEmpty())
    {
        return 0;
    }

    currentIndex = 0;
    return shapes[currentIndex];
}

bool ShapeList::isEmpty() const
{
    return shapes.isEmpty();
}

void ShapeList::backupState()
{
    if (backup != 0)
    {
        delete backup;
        backup = 0;
    }

    backup = new ShapeListMemento(shapes);
}

bool ShapeList::restoreState()
{
    if (backup == 0)
    {
        return false;
    }

    clearShapes();

    shapes = backup->getSavedShapes();

    if (shapes.isEmpty())
    {
        currentIndex = -1;
    }
    else
    {
        currentIndex = 0;
    }

    return true;
}
