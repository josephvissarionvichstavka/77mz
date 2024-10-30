//
// Created by 年 on 2024/10/30.
//

#ifndef INC_77MZ_MZ77AVATAR_H
#define INC_77MZ_MZ77AVATAR_H
#include <QLabel>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QPainter>
#include <QPixmap>

class MZ77Avatar : public QLabel{
public:
    MZ77Avatar(int size,QWidget * parent);
    void loadAvatarFromLocal(const QString & path);
    void loadAvatarFromNetwork(const QString & url);
    Q_OBJECT
private slots:
    void draw(QNetworkReply * reply);
};


#endif //INC_77MZ_MZ77AVATAR_H
