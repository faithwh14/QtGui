#include "LoginView.h"

#include "../ui/ui_LoginUI.h"

LoginView::LoginView(QWidget* parent) : QWidget(parent), ui(new Ui::LoginUI) {
    ui->setupUi(this);
}

LoginView::~LoginView() {
}