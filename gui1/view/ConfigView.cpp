#include "ConfigView.h"

#include "../ui/ui_ConfigurationUI.h"

ConfigView::ConfigView(QWidget* parent) : QWidget(parent), ui(new Ui::ConfigurationUI) {
    ui->setupUi(this);
}

ConfigView::~ConfigView() {
}