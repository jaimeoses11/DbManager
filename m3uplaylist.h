#ifndef M3UPLAYLIST_H
#define M3UPLAYLIST_H

#include <QObject>

#include "channel.h"

class m3uPlayList
{
public:
    m3uPlayList(QString name);
public:
    void parseList();
public:
    QList<Channel> channels;
private:
    QString name;
};

#endif // M3UPLAYLIST_H
