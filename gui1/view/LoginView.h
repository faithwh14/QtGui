#ifndef SRC_GUI_VIEW_LOGINVIEW_H_
#define SRC_GUI_VIEW_LOGINVIEW_H_

#include <QWidget>

namespace Ui {
class LoginUI;
}  // namespace Ui

class LoginView : public QWidget {
    Q_OBJECT
   public:
    LoginView(QWidget* parent = nullptr);
    ~LoginView();

   private:
    Ui::LoginUI* ui;
};

#endif  // SRC_GUI_VIEW_LOGINVIEW_H_