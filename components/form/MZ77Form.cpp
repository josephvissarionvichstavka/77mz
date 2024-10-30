//
// Created by 年 on 2024/10/30.
//

#include "MZ77Form.h"

MZ77Form::MZ77Form(QWidget *parent) {
    setParent(parent);
    resize(750,500);
    setStyleSheet("QWidget { border-radius : 25px;"
                  "                   background :rgba(255, 255, 255, 0.1);"
                  "                   border:5px solid rgba(255, 255, 255, 0.5);"
                  "                 }");
}
