//
// Created by 年 on 2024/10/30.
//

#include "Register.h"
#include "../../entity/RegisterDto.h"
#include "../login/Login.h"

Register::Register(){
    this->setFixedSize(1250,680);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(R"(F:\app\77mz\icons\background.jpg)")));
    setPalette(palette);
    setStyleSheet("color:#ffffff;");

    from = new MZ77Form(this);
    from->move(250,50);
    title = new QLabel("欢迎注册77MZ", this);
    title->setStyleSheet("QLabel{font-size:32px;font-weight:hold;color:#409eff;}");
    title->move(from->x() , from->y() + 10);
    title->setFixedSize(750,50);
    title->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

    description = new QLabel("兄弟你好香,让我闻闻!!!", this);
    description->setStyleSheet("QLabel{font-size:24px;font-weight:500;color:#409eff;}");
    description->setAlignment(title->alignment());
    description->move(title->x(),title->y()+title->height());
    description->setFixedSize(750,30);

    line = new QFrame(this);
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    line->move(622,150);
    line->setFixedSize(6,350);

    name = new MZ77Input(this);
    name->setPlaceholderText("请输入名字");
    name->move(line->x() + 30,line->y() + 40);
    name->setFixedWidth(320);

    password = new MZ77Input(this);
    password->setPlaceholderText("请输入密码");
    password->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    password->move(name->x(),name->y() + name->height() + 30);
    password->setFixedWidth(320);

    email = new MZ77Input(this);
    email->setPlaceholderText("请输入邮箱号");
    email->move(password->x() , password->y() + password->height() +30);
    email->setFixedWidth(320);

    code = new MZ77Input(this);
    code->setPlaceholderText("请输入验证码");
    code->move(email->x() , email->y() + email->height() + 30);
    code->setMaxLength(6);
    code->setFixedWidth(320);

    codeButton = new MZ77Button(this);
    codeButton->setText("获取验证码");
    codeButton->move(code->x() + code->width() - 135, code->y() - 15);
    codeButton->resize(120,40);
    connect(codeButton , &QPushButton::clicked , this , &Register::startTimer);
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer , &QTimer::timeout , this , &Register::updateTimer);

    _register = new MZ77Button(this);
    _register->setText("注册");
    _register->move(code->x() -20 , code->y() + code->height() + 50);
    _register->setFixedSize(360,40);
    connect(_register , &QPushButton::clicked , this , &Register::gotoRegister);

    avatarSelector = new QLabel("头像选择",this);
    avatarSelector->setStyleSheet(description->styleSheet());
    avatarSelector->move(from->x() , line->y() + 30);
    avatarSelector->setFixedSize(375 , 30);
    avatarSelector->setAlignment(description->alignment());

    upload = new MZ77Upload(this);
    upload->move(avatarSelector->x() + 60 , avatarSelector->y() + avatarSelector->height() + 30);

}

void Register::startTimer() {
    cutDownTime = maxTime; // 默认60秒
    codeButton->setText(QString("剩余时间(%1)秒").arg(cutDownTime));
    codeButton->setEnabled(false);
    timer->start();
}

void Register::updateTimer() {
    if (cutDownTime > 0) {
        --cutDownTime;
        codeButton->setText(QString("剩余时间(%1)秒").arg(cutDownTime));
    } else {
        timer->stop();
        cutDownTime = maxTime;
        codeButton->setText("获取验证码");
        codeButton->setEnabled(true);
    }
}

void Register::gotoRegister() {
    RegisterDto * dto = new RegisterDto;
    dto->setPassword(password->text());
    dto->setName(name->text());
    dto->setCode(code->text());
    dto->setEmail(email->text());
    QJsonObject object = dto->toJson();
    QJsonDocument document(object);
    QByteArray data = document.toJson();
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    QNetworkRequest request((QUrl(USER_REGISTER)));
    connect(manager , &QNetworkAccessManager::finished , this , &Register::gotoLogin);
    manager->post(request , data);
}

void Register::gotoLogin(QNetworkReply * reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray res = reply->readAll();
        QJsonDocument resDoc = QJsonDocument::fromJson(res);
        if (!resDoc.isNull() && resDoc.isObject()) {
            QJsonObject resObj = resDoc.object();
            Result<User> result = Result<User>::jsonToResult(resObj);
            if (result.getCode() == ResultCode::success) {
                Login::getInstance().show();
            } else {
                qDebug() << result.getMessage();
            }
        } else {
            qDebug() << "错误：" << reply->error();
        }
    } else {
        qDebug() << "异常:" << reply->error();
    }
}