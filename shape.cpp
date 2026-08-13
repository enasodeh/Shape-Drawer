#include "shape.h"

// Shape

Shape::Shape(int penWidth, QColor penColour, QColor fillColour)
{
    this->penWidth = penWidth;
    this->penColour = penColour;
    this->fillColour = fillColour;
}

void Shape::setPenWidth(int w)
{
    penWidth = w;
}

void Shape::setPenColour(QColor colour)
{
    penColour = colour;
}

void Shape::setFillColour(QColor colour)
{
    fillColour = colour;
}

int Shape::getPenWidth() const
{
    return penWidth;
}

QColor Shape::getPenColour() const
{
    return penColour;
}

QColor Shape::getFillColour() const
{
    return fillColour;
}

// Shape1Property

Shape1Property::Shape1Property(int p1,
                               int penWidth,
                               QColor penColour,
                               QColor fillColour)
    : Shape(penWidth, penColour, fillColour)
{
    property1 = p1;
}

void Shape1Property::setProperty1(int p1)
{
    property1 = p1;
}

int Shape1Property::getProperty1() const
{
    return property1;
}

// Shape2Property

Shape2Property::Shape2Property(int p1,
                               int p2,
                               int penWidth,
                               QColor penColour,
                               QColor fillColour)
    : Shape1Property(p1, penWidth, penColour, fillColour)
{
    property2 = p2;
}

void Shape2Property::setProperty2(int p2)
{
    property2 = p2;
}

int Shape2Property::getProperty2() const
{
    return property2;
}

// Circle

Circle::Circle(int radius,
               int penWidth,
               QColor penColour,
               QColor fillColour)
    : Shape1Property(radius, penWidth, penColour, fillColour)
{
}

void Circle::draw(QPainter &painter)
{
    painter.setPen(QPen(penColour, penWidth));
    painter.setBrush(QBrush(fillColour));

    int radius = property1;
    painter.drawEllipse(80, 50, radius * 2, radius * 2);
}

Shape* Circle::clone() const
{
    return new Circle(property1, penWidth, penColour, fillColour);
}

// Square

Square::Square(int side,
               int penWidth,
               QColor penColour,
               QColor fillColour)
    : Shape1Property(side, penWidth, penColour, fillColour)
{
}

void Square::draw(QPainter &painter)
{
    painter.setPen(QPen(penColour, penWidth));
    painter.setBrush(QBrush(fillColour));

    painter.drawRect(80, 50, property1, property1);
}

Shape* Square::clone() const
{
    return new Square(property1, penWidth, penColour, fillColour);
}

// Ellipse

Ellipse::Ellipse(int width,
                 int height,
                 int penWidth,
                 QColor penColour,
                 QColor fillColour)
    : Shape2Property(width, height, penWidth, penColour, fillColour)
{
}

void Ellipse::draw(QPainter &painter)
{
    painter.setPen(QPen(penColour, penWidth));
    painter.setBrush(QBrush(fillColour));

    painter.drawEllipse(80, 50, property1, property2);
}

Shape* Ellipse::clone() const
{
    return new Ellipse(property1, property2, penWidth, penColour, fillColour);
}

// Rectangle

Rectangle::Rectangle(int width,
                     int height,
                     int penWidth,
                     QColor penColour,
                     QColor fillColour)
    : Shape2Property(width, height, penWidth, penColour, fillColour)
{
}

void Rectangle::draw(QPainter &painter)
{
    painter.setPen(QPen(penColour, penWidth));
    painter.setBrush(QBrush(fillColour));

    painter.drawRect(80, 50, property1, property2);
}

Shape* Rectangle::clone() const
{
    return new Rectangle(property1, property2, penWidth, penColour, fillColour);
}
