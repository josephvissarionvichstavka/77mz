//
// Created by 年 on 2024/10/30.
//

#include "MZ77Upload.h"

MZ77Upload::MZ77Upload(QWidget *parent) {
    setParent(parent);
    setText("<a href='http://localhost:8080/#/1' style='text-decoration: none;color:black;'>+</a>");
    resize(240,240);
    setStyleSheet("QLabel { "
                  "            background-color : #ffffff;"
                  "            border : 2px solid #303133; "
                  "            font-size : 160px;"
                  "            font-weight : hold;"
                  "            border-radius : 16px;"
                  "        }");
    deleteImage = new QPushButton("x" , this);
    deleteImage->setFixedSize(20,20);
    deleteImage->move(x() + width() - 20,y());
    deleteImage->setStyleSheet("QPushButton {"
                               "             font-size : 20px;"
                               "             font-weight : hold;"
                               "             border : 0;"
                               "             border-radius : 10px;"
                               "            background-color : #909399;"
                               "            color: #ffffff;"
                               "         }"
                               "         QPushButton:hover,QPushButton:pressed {"
                               "             background-color : #f56c6c;"
                               "            color : #ffffff;"
                               "         }");
    deleteImage->setVisible(false);
    setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    connect(this, &QLabel::linkActivated , this ,&MZ77Upload::fileSelector);
    connect(deleteImage , &QPushButton::clicked , this , &MZ77Upload::deleteFile);
}

void MZ77Upload::fileSelector() {
    QString fileName = QFileDialog::getOpenFileName(this, "头像选择" , "*.jpg;*.png");
    clear();
    QPixmap pixmap(fileName);
    setPixmap(pixmap.scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    deleteImage->setVisible(true);
}

void MZ77Upload::deleteFile() {
    deleteImage->setVisible(false);
    clear();
    setText("<a href='http://localhost:8080/#/1' style='text-decoration: none;color:black;'>+</a>");
}
