#include "mainwindow.h"
#include "shapelist.h"

#include <QGridLayout>
#include <QLabel>
#include <QFile>
#include <QDomDocument>
#include <QMessageBox>
#include <QCoreApplication>

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Shape Drawer");

    shapeBox = new QComboBox;
    shapeBox->addItem("Circle");
    shapeBox->addItem("Square");
    shapeBox->addItem("Ellipse");
    shapeBox->addItem("Rectangle");

    penWidthBox = new QSpinBox;
    penWidthBox->setRange(1, 10);
    penWidthBox->setValue(3);

    penColourBox = new QComboBox;
    penColourBox->addItem("Black");
    penColourBox->addItem("Red");
    penColourBox->addItem("Blue");
    penColourBox->addItem("Green");

    fillColourBox = new QComboBox;
    fillColourBox->addItem("White");
    fillColourBox->addItem("Red");
    fillColourBox->addItem("Blue");
    fillColourBox->addItem("Green");
    fillColourBox->addItem("Yellow");
    fillColourBox->addItem("Black");

    property1Box = new QSpinBox;
    property1Box->setRange(10, 200);
    property1Box->setValue(100);

    property2Box = new QSpinBox;
    property2Box->setRange(10, 200);
    property2Box->setValue(50);

    createButton = new QPushButton("Create shape");
    previousButton = new QPushButton("Previous");
    nextButton = new QPushButton("Next");
    backupButton = new QPushButton("Backup State");
    restoreButton = new QPushButton("Restore State");

    drawingArea = new DrawingArea;

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(new QLabel("Shape"), 0, 0);
    layout->addWidget(shapeBox, 0, 1);

    layout->addWidget(new QLabel("Property 1"), 0, 2);
    layout->addWidget(property1Box, 0, 3);

    layout->addWidget(new QLabel("Pen width"), 1, 0);
    layout->addWidget(penWidthBox, 1, 1);

    layout->addWidget(new QLabel("Property 2"), 1, 2);
    layout->addWidget(property2Box, 1, 3);

    layout->addWidget(new QLabel("Pen colour"), 2, 0);
    layout->addWidget(penColourBox, 2, 1);

    layout->addWidget(new QLabel("Fill colour"), 3, 0);
    layout->addWidget(fillColourBox, 3, 1);

    layout->addWidget(createButton, 3, 3);

    layout->addWidget(drawingArea, 4, 0, 1, 4);

    layout->addWidget(previousButton, 5, 0);
    layout->addWidget(nextButton, 5, 3);

    layout->addWidget(backupButton, 6, 0, 1, 2);
    layout->addWidget(restoreButton, 6, 2, 1, 2);

    setLayout(layout);

    connect(createButton, SIGNAL(clicked()), this, SLOT(createShape()));
    connect(previousButton, SIGNAL(clicked()), this, SLOT(showPreviousShape()));
    connect(nextButton, SIGNAL(clicked()), this, SLOT(showNextShape()));
    connect(backupButton, SIGNAL(clicked()), this, SLOT(backupApplicationState()));
    connect(restoreButton, SIGNAL(clicked()), this, SLOT(restoreApplicationState()));

    loadShapesFromXML();
}

// Convert text colour into QColor
QColor MainWindow::getColour(QString colourName)
{
    if (colourName == "Black")
        return Qt::black;
    else if (colourName == "Red")
        return Qt::red;
    else if (colourName == "Blue")
        return Qt::blue;
    else if (colourName == "Green")
        return Qt::green;
    else if (colourName == "Yellow")
        return Qt::yellow;
    else if (colourName == "White")
        return Qt::white;
    else
        return Qt::white;
}

// Create new shape from GUI
void MainWindow::createShape()
{
    QString selectedShape = shapeBox->currentText();

    int penWidth = penWidthBox->value();
    int property1 = property1Box->value();
    int property2 = property2Box->value();

    QColor penColour = getColour(penColourBox->currentText());
    QColor fillColour = getColour(fillColourBox->currentText());

    Shape *newShape = 0;

    if (selectedShape == "Circle")
    {
        newShape = new Circle(property1, penWidth, penColour, fillColour);
    }
    else if (selectedShape == "Square")
    {
        newShape = new Square(property1, penWidth, penColour, fillColour);
    }
    else if (selectedShape == "Ellipse")
    {
        newShape = new Ellipse(property1, property2, penWidth, penColour, fillColour);
    }
    else if (selectedShape == "Rectangle")
    {
        newShape = new Rectangle(property1, property2, penWidth, penColour, fillColour);
    }

    if (newShape != 0)
    {
        ShapeList::getInstance()->addShape(newShape);
        drawingArea->setShape(newShape);
    }
}

// Show previous shape
void MainWindow::showPreviousShape()
{
    Shape *shape = ShapeList::getInstance()->getPreviousShape();

    if (shape != 0)
    {
        drawingArea->setShape(shape);
    }
}

// Show next shape
void MainWindow::showNextShape()
{
    Shape *shape = ShapeList::getInstance()->getNextShape();

    if (shape != 0)
    {
        drawingArea->setShape(shape);
    }
}

// Backup current application state
void MainWindow::backupApplicationState()
{
    ShapeList::getInstance()->backupState();

    QMessageBox::information(this,
                             "Backup",
                             "The current application state has been backed up.");
}

// Restore previous application state
void MainWindow::restoreApplicationState()
{
    bool restored = ShapeList::getInstance()->restoreState();

    if (!restored)
    {
        QMessageBox::warning(this,
                             "Restore",
                             "No backup state exists.");
        return;
    }

    Shape *firstShape = ShapeList::getInstance()->getFirstShape();

    if (firstShape != 0)
    {
        drawingArea->setShape(firstShape);
    }

    QMessageBox::information(this,
                             "Restore",
                             "The application state has been restored.");
}

// Load shapes from XML file
void MainWindow::loadShapesFromXML()
{
    QString filePath = QCoreApplication::applicationDirPath() + "/shapes.xml";
    QFile file(filePath);

    if (!file.exists())
    {
        QMessageBox::warning(this, "File Error", "shapes.xml file was not found.");
        return;
    }

    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "File Error", "Could not open shapes.xml.");
        return;
    }

    QDomDocument document;

    if (!document.setContent(&file))
    {
        QMessageBox::warning(this, "XML Error", "Could not read XML content.");
        file.close();
        return;
    }

    file.close();

    QDomElement root = document.documentElement();

    if (root.tagName() != "shapeList")
    {
        QMessageBox::warning(this,
                             "XML Error",
                             "Invalid XML file. Root element must be shapeList.");
        return;
    }

    QDomNode node = root.firstChild();

    while (!node.isNull())
    {
        QDomElement element = node.toElement();

        if (!element.isNull() && element.tagName() == "shape")
        {
            QString type = element.attribute("type");

            int penWidth = element.attribute("pw").toInt();
            QString penColourText = element.attribute("pc");
            QString fillColourText = element.attribute("fc");

            int property1 = element.attribute("p1").toInt();
            int property2 = element.attribute("p2").toInt();

            QColor penColour = getColour(penColourText);
            QColor fillColour = getColour(fillColourText);

            Shape *newShape = 0;

            if (type == "Circle")
            {
                newShape = new Circle(property1, penWidth, penColour, fillColour);
            }
            else if (type == "Square")
            {
                newShape = new Square(property1, penWidth, penColour, fillColour);
            }
            else if (type == "Ellipse")
            {
                newShape = new Ellipse(property1, property2, penWidth, penColour, fillColour);
            }
            else if (type == "Rectangle")
            {
                newShape = new Rectangle(property1, property2, penWidth, penColour, fillColour);
            }

            if (newShape != 0)
            {
                ShapeList::getInstance()->addShape(newShape);
            }
        }

        node = node.nextSibling();
    }

    Shape *firstShape = ShapeList::getInstance()->getFirstShape();

    if (firstShape != 0)
    {
        drawingArea->setShape(firstShape);
    }
}
