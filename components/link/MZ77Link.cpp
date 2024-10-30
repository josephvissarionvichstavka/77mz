//
// Created by 年 on 2024/10/30.
//

#include "MZ77Link.h"

MZ77Link::MZ77Link(QWidget *parent) {
    setParent(parent);
    setTextFormat(Qt::RichText);
}

void MZ77Link::setLocalLink(const QString &url) {
    setStyleSheet("QLabel { font-size : 16px;color : lightpink;}");
    setText(url);
}

void MZ77Link::setNetworkLink(const QString &url) {
    setStyleSheet("QLabel { font-size : 16px;font-style: italic;color : lightgray;}");
    setText(url);
    setTextInteractionFlags(Qt::TextBrowserInteraction);
    connect(this , &QLabel::linkActivated , this , &MZ77Link::openLink);
}

void MZ77Link::openLink(const QString &link) {
    QDesktopServices::openUrl(QUrl(link));
}
