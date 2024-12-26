#ifndef SRC_GUI_VIEW_CONFIGVIEW_H_
#define SRC_GUI_VIEW_CONFIGVIEW_H_

#include <QWidget>

namespace Ui {
class ConfigurationUI;
}  // namespace Ui

class ConfigView : public QWidget {
    Q_OBJECT
   public:
    ConfigView(QWidget* parent = nullptr);
    ~ConfigView();

   private:
    Ui::ConfigurationUI* ui;
};

#endif  // SRC_GUI_VIEW_CONFIGVIEW_H_