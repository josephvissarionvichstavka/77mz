//
// Created by 年 on 2024/10/30.
//

#include "MZ77Button.h"

MZ77Button::MZ77Button(QWidget *parent) {
    setParent(parent);
    resize(270,40);
    setStyleSheet("QPushButton {"
                  "                border-radius : 20px;"
                  "                border : 1px solid #409eff;"
                  "            background-color : transparent;"
                  "            color: #409eff;"
                  "         }"
                  "         QPushButton:hover,QPushButton:pressed {"
                  "            background-color : #409eff;"
                  "            color : #ffffff;"
                  "         }");
}
