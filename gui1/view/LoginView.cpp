#include "LoginView.h"

#include "../ui/ui_LoginUI.h"

using namespace faith;

LoginView::LoginView(QWidget* parent) : IBaseView(parent), ui(new Ui::LoginUI) {
    ui->setupUi(this);

    setupConnection();
}

LoginView::~LoginView() {
}

void LoginView::setupConnection() {
    connect(ui->LoginBtn, &QPushButton::clicked, this, [this]() {
        switchView(CONFIG_VIEW);
    });
}