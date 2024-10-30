//
// Created by 年 on 2024/10/30.
//

#include "LoginDto.h"

const QString &LoginDto::getUsername() const {
    return username;
}

void LoginDto::setUsername(const QString &username) {
    LoginDto::username = username;
}

const QString &LoginDto::getPassword() const {
    return password;
}

void LoginDto::setPassword(const QString &password) {
    LoginDto::password = password;
}

QJsonObject LoginDto::toJson() {
    QJsonObject object;
    object["username"] = username.toStdString().c_str();
    object["password"] = password.toStdString().c_str();
    return object;
}