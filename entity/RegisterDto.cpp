//
// Created by 年 on 2024/10/30.
//

#include "RegisterDto.h"

const QString &RegisterDto::getPassword() const {
    return password;
}

void RegisterDto::setPassword(const QString &password) {
    RegisterDto::password = password;
}

const QString &RegisterDto::getEmail() const {
    return email;
}

void RegisterDto::setEmail(const QString &email) {
    RegisterDto::email = email;
}

const QString &RegisterDto::getName() const {
    return name;
}

void RegisterDto::setName(const QString &name) {
    RegisterDto::name = name;
}

const QString &RegisterDto::getAvatar() const {
    return avatar;
}

void RegisterDto::setAvatar(const QString &avatar) {
    RegisterDto::avatar = avatar;
}

const QString &RegisterDto::getCode() const {
    return code;
}

void RegisterDto::setCode(const QString &code) {
    RegisterDto::code = code;
}

QJsonObject RegisterDto::toJson() {
    QJsonObject object;
    object["password"]= password;
    object["code"] = code;
    object["email"] = email;
    object["avatar"] = avatar;
    object["name"] = name;
    return object;
}
