#ifndef SRC_GUI_VIEW_CONFIGVIEW_H_
#define SRC_GUI_VIEW_CONFIGVIEW_H_

#include <QWidget>

#include "IBaseView.h"

namespace Ui {
class ConfigurationUI;
}  // namespace Ui

namespace faith {

class ConfigView : public IBaseView {
    Q_OBJECT
   public:
    ConfigView(QWidget* parent = nullptr);
    ~ConfigView() override;

   private:
    Ui::ConfigurationUI* ui;

    void setupConnection() override;
};

}  // namespace faith

#endif  // SRC_GUI_VIEW_CONFIGVIEW_H_