//
// Created by 年 on 2024/10/30.
//

#include "MZ77Input.h"
MZ77Input::MZ77Input( QWidget *parent) {
    setParent(parent);
    setFixedHeight(30);
    resize(240,30);
    setStyleSheet("QLineEdit {"
                  "             border-radius : 0;"
                  "             font-size: 16px;"
                  "             padding-left: 30;"
                  "             padding-right: 50;"
                  "             padding-top:6;"
                  "             padding-bottom:6;"
                  "             border-bottom:1px solid black;"
                  "             background:transparent;"
                  "         }");

    clearIcon = new QPushButton("X",this);
    clearIcon->setFixedSize(24,24);
    clearIcon->move(this->x() + this->width() - 30 , this->y() + 3);
    clearIcon->setStyleSheet("QPushButton {"
                             "             font-size : 16px;"
                             "             border : 0;"
                             "             border-radius : 12px;"
                             "             color : #303133;"
                             "         }"
                             "         QPushButton:hover,QPushButton:pressed {"
                             "             background-color : #303133;"
                             "             color : #ffffff;"
                             "         }");
    connect(this , &QLineEdit::textChanged , this ,&MZ77Input::clearText);
    clearIcon->setVisible(false);
    connect(clearIcon , &QPushButton::clicked , this , &MZ77Input::clearToButton);

    showPasswordIcon = new QPushButton("Q",this);
    showPasswordIcon->setFixedSize(24,24);
    showPasswordIcon->move(clearIcon->x() - 30,clearIcon->y());
    showPasswordIcon->setStyleSheet(clearIcon->styleSheet());
    showPasswordIcon->setVisible(false);
    connect(showPasswordIcon , &QPushButton::clicked , this , &MZ77Input::showPassword);

    leftIcon = new QLabel("Q" , this);
    leftIcon->setFixedSize(24,24);
    leftIcon->move(x() + 12, y() + 3);
    leftIcon->setStyleSheet("QLabel { font-size : 24px;font-weight:hold;background:transparent;}");


}

void MZ77Input::clearText(const QString &text) {

    clearIcon->setVisible(!text.isEmpty());
    showPasswordIcon->setVisible(!text.isEmpty() && echoMode() == QLineEdit::Password);
}

void MZ77Input::clearToButton() {
    this->clear();
}

void MZ77Input::showPassword() {
    if (echoMode() == QLineEdit::Password) {
        setEchoMode(QLineEdit::Normal);
        showPasswordIcon->setText("Q");
    } else {
        setEchoMode(QLineEdit::Password);
        showPasswordIcon->setText("O");
    }
}
