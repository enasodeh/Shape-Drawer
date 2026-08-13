# Shape Drawer

A desktop GUI application built with **C++ and Qt** for creating, customising, storing, and navigating graphical shapes.

This project demonstrates object-oriented programming, GUI development, XML data handling, and software design patterns in C++.

## Features

* Create different graphical shapes, including:

  * Circle
  * Square
  * Ellipse
  * Rectangle
* Customise shape dimensions.
* Select pen width and pen colour.
* Select a fill colour.
* Render shapes using Qt's `QPainter`.
* Store multiple created shapes in memory.
* Navigate between stored shapes using **Previous** and **Next**.
* Load predefined shapes from an XML file.
* Back up and restore the collection of shapes.

## Technologies & Concepts

* **C++11**
* **Qt 5 / Qt Widgets**
* **QPainter**
* **XML / QDomDocument**
* **Object-Oriented Programming**
* **Inheritance & Polymorphism**
* **Singleton Design Pattern**
* **Memento Design Pattern**
* **Deep Copying / Object Cloning**
* **Qt Signals and Slots**

## Application Preview

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/dc55e7f8-c573-4860-871c-2a72eabc8185" />

## Object-Oriented Design

The application uses an abstract `Shape` base class with specialised classes for different shape types. Each derived class implements its own drawing behaviour, allowing the application to use **polymorphism** when rendering shapes.

Intermediate classes are used to represent shapes requiring either one or two dimensional properties.

## Design Patterns

### Singleton Pattern

`ShapeList` uses the **Singleton pattern** to provide a single shared collection of shapes throughout the application.

It manages adding shapes, tracking the currently displayed shape, navigating through the collection, and managing application state.

### Memento Pattern

The **Memento pattern** is used to back up and restore the application's shape collection.

`ShapeListMemento` creates independent copies of the stored shapes using their `clone()` methods, allowing a previous state of the collection to be restored.

## XML Data

The application reads predefined shape information from `shapes.xml`.

The XML data includes properties such as:

* Shape type
* Pen width
* Pen colour
* Fill colour
* Shape dimensions

The application parses this information and creates the corresponding C++ shape objects.

## Project Structure

```text
Shape-Drawer/
├── main.cpp
├── mainwindow.cpp
├── mainwindow.h
├── mainwindow.ui
├── drawingarea.cpp
├── drawingarea.h
├── shape.cpp
├── shape.h
├── shapelist.cpp
├── shapelist.h
├── shapelistmemento.cpp
├── shapelistmemento.h
├── shapes.xml
└── ShapeDrawer.pro
```

## Running the Project

1. Install **Qt** and Qt Creator.
2. Clone or download this repository.
3. Open `ShapeDrawer.pro` in Qt Creator.
4. Configure a compatible Qt Desktop kit.
5. Build the project.
6. Ensure `shapes.xml` is available to the application at runtime.
7. Run the application.

## What I Learned

Through this project, I gained practical experience in:

* Developing desktop GUI applications with C++ and Qt.
* Applying inheritance and polymorphism in an interactive application.
* Working with dynamically allocated objects.
* Implementing the Singleton and Memento design patterns.
* Creating deep copies of polymorphic objects.
* Reading and processing XML data.
* Working with Qt signals and slots.
* Rendering custom graphics using `QPainter`.

## About the Project

This application was originally developed as part of my Computer Science coursework. It was built incrementally, with this repository presenting the **final implementation**.
