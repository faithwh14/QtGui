#ifndef SRC_GUI_VIEW_MAINWINDOW_H_
#define SRC_GUI_VIEW_MAINWINDOW_H_

#include <QWidget>
#include <QStackedWidget>
#include <QObject>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMainWindow>

#include "view/LoginView.h"
#include "view/ConfigView.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

   private:
    LoginView* loginView;
    ConfigView* configView;
    QStackedWidget* stack;
};

#endif  // SRC_GUI_VIEW_MAINWINDOW_H_