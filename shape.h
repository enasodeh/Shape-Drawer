#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <QColor>

class Shape
{
protected:
    int penWidth;
    QColor penColour;
    QColor fillColour;

public:
    Shape(int penWidth = 1,
          QColor penColour = Qt::black,
          QColor fillColour = Qt::white);

    virtual ~Shape() {}

    void setPenWidth(int w);
    void setPenColour(QColor colour);
    void setFillColour(QColor colour);

    int getPenWidth() const;
    QColor getPenColour() const;
    QColor getFillColour() const;

    virtual void draw(QPainter &painter) = 0;
    virtual Shape* clone() const = 0;
};

class Shape1Property : public Shape
{
protected:
    int property1;

public:
    Shape1Property(int p1 = 50,
                   int penWidth = 1,
                   QColor penColour = Qt::black,
                   QColor fillColour = Qt::white);

    void setProperty1(int p1);
    int getProperty1() const;

    virtual void draw(QPainter &painter) = 0;
    virtual Shape* clone() const = 0;
};

class Shape2Property : public Shape1Property
{
protected:
    int property2;

public:
    Shape2Property(int p1 = 100,
                   int p2 = 50,
                   int penWidth = 1,
                   QColor penColour = Qt::black,
                   QColor fillColour = Qt::white);

    void setProperty2(int p2);
    int getProperty2() const;

    virtual void draw(QPainter &painter) = 0;
    virtual Shape* clone() const = 0;
};

class Circle : public Shape1Property
{
public:
    Circle(int radius,
           int penWidth,
           QColor penColour,
           QColor fillColour);

    void draw(QPainter &painter);
    Shape* clone() const;
};

class Square : public Shape1Property
{
public:
    Square(int side,
           int penWidth,
           QColor penColour,
           QColor fillColour);

    void draw(QPainter &painter);
    Shape* clone() const;
};

class Ellipse : public Shape2Property
{
public:
    Ellipse(int width,
            int height,
            int penWidth,
            QColor penColour,
            QColor fillColour);

    void draw(QPainter &painter);
    Shape* clone() const;
};

class Rectangle : public Shape2Property
{
public:
    Rectangle(int width,
              int height,
              int penWidth,
              QColor penColour,
              QColor fillColour);

    void draw(QPainter &painter);
    Shape* clone() const;
};

#endif
