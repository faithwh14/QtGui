#ifndef SRC_GUI_VIEW_MAINWINDOW_H_
#define SRC_GUI_VIEW_MAINWINDOW_H_

#include <memory>
#include <array>

#include <QWidget>
#include <QStackedWidget>
#include <QObject>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMainWindow>

#include "view/LoginView.h"
#include "view/ConfigView.h"

#include "utils/constant.h"

namespace faith {

class MainWindow : public QMainWindow {
    Q_OBJECT
   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

   private:
    void setView(View view);
    void setupView();

    std::array<std::unique_ptr<IBaseView>, MAX_VIEW> views;
    QStackedWidget* stack;
};

}  // namespace faith

#endif  // SRC_GUI_VIEW_MAINWINDOW_H_