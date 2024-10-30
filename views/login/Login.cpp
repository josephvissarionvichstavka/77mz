//
// Created by 年 on 2024/10/30.
//

#include "Login.h"
#include "../register/Register.h"


Login::Login() {
    QIcon icon(R"(../../icons/icon.jpg)");
    setWindowIcon(icon);
    setWindowTitle("77MZ聊天室");
    setFixedSize(300,400);
    setStyleSheet("background:#ffffff;");
    QFont font;
    font.setFamily("Microsoft YaHei");
    setFont(font);
    title = new QLabel("用户登录",this);
    title->setFixedWidth(300);
    title->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    title->setStyleSheet("QLabel {font-size:28px;font-weight:hold;color:#409eff;}");
    title->move(0,20);

    avatar = new MZ77Avatar(100,this);
    avatar->move(title->x() + 100,title->y() + title->height() + 20);

    username = new MZ77Input(this);
    username->setPlaceholderText("用户名");
    username->move(title->x() + 30 , avatar->y() + avatar->height() + 20);
    connect(username , &QLineEdit::textChanged , this , &Login::textChangeToAvatar);

    password = new MZ77Input(this);
    password->setEchoMode(QLineEdit::Password);
    password->setPlaceholderText("密码");
    password->move(username->x() , username->y() + username->height() + 20);

    login = new MZ77Button(this);
    login->setText("登录");
    login->move(password->x() - 15 , password->y() + password->height() + 20);
    connect(login , &QPushButton::clicked , this, &Login::clickLogin);

    forgetPassword = new MZ77Link(this);
    forgetPassword->setNetworkLink("<a href='http://localhost:8080/#' style='text-decoration: none;color:lightgray;'>忘记密码</a>");
    forgetPassword->move(login->x() + login->width() / 2 - 94, login->y() + login->height() + 30);

    registerMz77 = new MZ77Link(this);
    registerMz77->setLocalLink("<a href='#' style='text-decoration: none;color:lightpink;'>注册账号</a>");
    registerMz77->move(login->x() + login->width() / 2 + 30, forgetPassword->y());
    connect(registerMz77, &QLabel::linkActivated , this , &Login::gotoRegister);
}

void Login::clickLogin() {
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    connect(manager , &QNetworkAccessManager::finished , this , &Login::gotoLogin);
    QNetworkRequest request((QUrl(USER_LOGIN)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    LoginDto * dto = new LoginDto;
    dto->setUsername(username->text());
    dto->setPassword(password->text());
    QJsonObject object = dto->toJson();
    QJsonDocument document(object);
    QByteArray data = document.toJson();
    manager->post(request, data);
}

void Login::textChangeToAvatar(const QString &input) {
    if (input.size() == 10) {
        avatar->loadAvatarFromLocal(R"(F:\app\77mz\icons\icon.jpg)");
    } else {
        avatar->clear();
    }
}

void Login::gotoLogin(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray res = reply->readAll();
        QJsonDocument resDoc = QJsonDocument::fromJson(res);
        if (!resDoc.isNull() && resDoc.isObject()) {
            QJsonObject resObj = resDoc.object();
            Result<User> result = Result<User>::jsonToResult(resObj);
            if (result.getCode() == ResultCode::success) {
                // TODO
            } else if (result.getCode() == ResultCode::error) {
                username->clear();
                password->clear();
            }
        } else {
            qDebug() << "错误：" << reply->error();
        }
    } else {
        qDebug() << "异常:" << reply->error();
    }
}

void Login::gotoRegister() {
    Register::getInstance().show();
    hide();
}
