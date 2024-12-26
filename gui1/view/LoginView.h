#ifndef SRC_GUI_VIEW_LOGINVIEW_H_
#define SRC_GUI_VIEW_LOGINVIEW_H_

#include <QWidget>

#include "IBaseView.h"

namespace Ui {
class LoginUI;
}  // namespace Ui

namespace faith {

class LoginView : public IBaseView {
    Q_OBJECT
   public:
    LoginView(QWidget* parent = nullptr);
    ~LoginView() override;

   private:
    Ui::LoginUI* ui;

    void setupConnection() override;
};

}  // namespace faith

#endif  // SRC_GUI_VIEW_LOGINVIEW_H_