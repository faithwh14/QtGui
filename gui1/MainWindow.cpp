#include "MainWindow.h"

#include <iostream>

using namespace faith;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), stack(new QStackedWidget(this)) {
    setWindowTitle("WenHao Application");
    resize(1500, 900);

    setupView();

    for (auto& view : views) {
        stack->addWidget(view.get());
    }

    stack->setCurrentIndex(LOGIN_VIEW);

    setCentralWidget(stack);
}

MainWindow::~MainWindow() {
}

void MainWindow::setupView() {
    views[LOGIN_VIEW] = std::make_unique<LoginView>(this);
    views[CONFIG_VIEW] = std::make_unique<ConfigView>(this);

    for (unsigned it = 0; it < views.size(); ++it) {
        connect(views[it].get(), &IBaseView::switchView, this, &MainWindow::setView);
    }
}

void MainWindow::setView(View view) {
    stack->setCurrentIndex(view);
}