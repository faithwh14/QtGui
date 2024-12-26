#ifndef SRC_GUI_VIEW_IBASEVIEW_H_
#define SRC_GUI_VIEW_IBASEVIEW_H_

#include <QWidget>

#include "gui/utils/constant.h"

namespace faith {

class IBaseView : public QWidget {
    Q_OBJECT
   public:
    IBaseView(QWidget* parent = nullptr) : QWidget(parent) {}
    virtual ~IBaseView() {}

   signals:
    void switchView(View);

   protected slots:
    virtual void setupConnection() = 0;
};

}  // namespace faith

#endif  // SRC_GUI_VIEW_IBASEVIEW_H_