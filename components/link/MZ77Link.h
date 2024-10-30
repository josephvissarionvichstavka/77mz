//
// Created by 年 on 2024/10/30.
//

#ifndef INC_77MZ_MZ77LINK_H
#define INC_77MZ_MZ77LINK_H
#include <QLabel>
#include <QDesktopServices>
#include <QUrl>
class MZ77Link : public QLabel{
public:
    MZ77Link(QWidget * parent);
    void setLocalLink(const QString & url);
    void setNetworkLink(const QString & url);
    Q_OBJECT
private slots:
    void openLink(const QString &link);
};


#endif //INC_77MZ_MZ77LINK_H
