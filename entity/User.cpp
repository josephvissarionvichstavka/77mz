//
// Created by 年 on 2024/10/30.
//

#include "User.h"

const QString &User::getUsername() const {
    return username;
}

void User::setUsername(const QString &username) {
    User::username = username;
}

const QString &User::getPassword() const {
    return password;
}

void User::setPassword(const QString &password) {
    User::password = password;
}

const QString &User::getEmail() const {
    return email;
}

void User::setEmail(const QString &email) {
    User::email = email;
}

const QString &User::getName() const {
    return name;
}

void User::setName(const QString &name) {
    User::name = name;
}

User::User() {

}

QJsonObject User::toJson() {
    QJsonObject object;
    object["username"] = username;
    object["password"] = password;
    object["email"] = email;
    object["name"] = name;
    return object;
}

User::User(const QJsonObject &object) {
    username = object["username"].toString();
    password = object["password"].toString();
    email = object["email"].toString();
    name = object["name"].toString();
}
