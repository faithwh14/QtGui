#include "ConfigView.h"

#include "../ui/ui_ConfigurationUI.h"

using namespace faith;

ConfigView::ConfigView(QWidget* parent) : IBaseView(parent), ui(new Ui::ConfigurationUI) {
    ui->setupUi(this);

    setupConnection();
}

ConfigView::~ConfigView() {
}

void ConfigView::setupConnection() {
    connect(ui->backBtn, &QPushButton::clicked, this, [this]() {
        switchView(LOGIN_VIEW);
    });
}