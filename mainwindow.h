#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include "drawingarea.h"

class MainWindow : public QWidget
{
    Q_OBJECT

private:
    QComboBox *shapeBox;
    QSpinBox *penWidthBox;
    QComboBox *penColourBox;
    QComboBox *fillColourBox;
    QSpinBox *property1Box;
    QSpinBox *property2Box;

    QPushButton *createButton;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QPushButton *backupButton;
    QPushButton *restoreButton;

    DrawingArea *drawingArea;

    QColor getColour(QString colourName);
    void loadShapesFromXML();

private slots:
    void createShape();
    void showPreviousShape();
    void showNextShape();
    void backupApplicationState();
    void restoreApplicationState();

public:
    MainWindow(QWidget *parent = 0);
};

#endif
