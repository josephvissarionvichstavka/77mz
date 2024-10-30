//
// Created by 年 on 2024/10/30.
//

#include "MZ77Avatar.h"

MZ77Avatar::MZ77Avatar(int size, QWidget *parent) {
    setParent(parent);
    resize(size , size);
    setStyleSheet("QLabel {border-radius : 50px;background:#f0f0f0;}");
}

void MZ77Avatar::loadAvatarFromLocal(const QString &path) {
    QPixmap pixmap(path);
    pixmap = pixmap.scaled(width(),height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QPixmap avatarPic(pixmap.size());
    avatarPic.fill(Qt::transparent);
    QPainter painter(&avatarPic);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(pixmap));
    painter.drawEllipse(0, 0, pixmap.width(),pixmap.height());
    setPixmap(avatarPic);
}

void MZ77Avatar::loadAvatarFromNetwork(const QString &url) {
    auto * manager = new QNetworkAccessManager(this);
    connect(manager , &QNetworkAccessManager::finished ,this, &MZ77Avatar::draw);
    manager->get(QNetworkRequest(QUrl(url)));
}

void MZ77Avatar::draw(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QPixmap pix;
        pix.loadFromData(data);
        pix = pix.scaled(width(),height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        QPixmap avatarPic(pix.size());
        avatarPic.fill(Qt::transparent);
        QPainter painter(&avatarPic);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(pix));
        painter.drawEllipse(0, 0, pix.width(),pix.height());
        setPixmap(avatarPic);
    } else {
        qDebug() << "错误：" << reply->error();
    }
    reply->deleteLater();
}
