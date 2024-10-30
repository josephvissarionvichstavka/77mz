//
// Created by 年 on 2024/10/30.
//

#ifndef INC_77MZ_REGISTER_H
#define INC_77MZ_REGISTER_H
#include <QString>
#include <QWidget>
#include <QTimer>
#include <QFrame>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include "../../components/input/MZ77Input.h"
#include "../../components/button/MZ77Button.h"
#include "../../components/link/MZ77Link.h"
#include "../../components/upload/MZ77Upload.h"
#include "../../components/form/MZ77Form.h"
#include "../../utils/Result.h"
#include "../../entity/User.h"
#include "../../utils/MZ77Cantent.h"

class Register : public QWidget {
private:
    MZ77Form * from;
    QLabel * title;
    QLabel * description;
    QFrame * line;
    QLabel * avatarSelector;
    MZ77Input * name;
    MZ77Input * password;
    MZ77Input * email;
    MZ77Input * code;
    MZ77Button * codeButton;
    MZ77Button * _register;
    MZ77Upload * upload;
    QTimer * timer;
    int cutDownTime;
    int maxTime = 60;
public:
    static Register & getInstance () {
        static Register aRegister;
        return aRegister;
    }
    Q_OBJECT
private:
    Register();

private slots:
    void startTimer(); // 验证码
    void updateTimer(); // 验证码
    void gotoRegister();
    void gotoLogin(QNetworkReply *reply);
};


#endif //INC_77MZ_REGISTER_H
