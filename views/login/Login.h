//
// Created by 年 on 2024/10/30.
//

#ifndef INC_77MZ_LOGIN_H
#define INC_77MZ_LOGIN_H
#include <QWidget>
#include <QIcon>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
#include "../../components/input/MZ77Input.h"
#include "../../components/button/MZ77Button.h"
#include "../../components/avatar/MZ77Avatar.h"
#include "../../components/link/MZ77Link.h"
#include "../../utils/Result.h"
#include "../../entity/LoginDto.h"
#include "../../utils/MZ77Cantent.h"
#include "../../entity/User.h"

class Login : public QWidget{
public:
    Q_OBJECT
private:
    Login();
    MZ77Input * username;
    MZ77Input * password;
    MZ77Button * login;
    MZ77Avatar * avatar;
    QLabel * title;
    MZ77Link * forgetPassword;
    MZ77Link * registerMz77;
private slots:
    void clickLogin();
    void textChangeToAvatar(const QString & input);
    void gotoLogin(QNetworkReply * reply);
    void gotoRegister();
public:
    static Login & getInstance(){
        static Login login;
        return login;
    }

};


#endif //INC_77MZ_LOGIN_H
