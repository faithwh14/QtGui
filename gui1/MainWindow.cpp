#include "MainWindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , loginView(new LoginView(this))
    , configView(new ConfigView(this))
    , stack(new QStackedWidget(this)) {
    setWindowTitle("WenHao Application");
    resize(1500, 900);

    stack->addWidget(loginView);
    stack->addWidget(configView);

    stack->setCurrentIndex(0);

    setCentralWidget(stack);
}

MainWindow::~MainWindow() {
}
