#include "m3uplaylist.h"

#include <QFile>
#include <QStringList>

m3uPlayList::m3uPlayList(QString name)
{
    this->name = name;
}

void m3uPlayList::parseList()
{
    QStringList playList;
    QFile file(name);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString str = QString(file.readAll());
        playList = str.split("\n");

        int size = playList.count();
        channels.clear();
        Channel ch;
        for(int i=0;i<size;i++)
        {
            if(playList.at(i).contains("#EXTINF"))
            {
                ch.name = playList.at(i).split(", ").at(1);
                auto s = playList.at(i);
            }
            else if(playList.at(i).contains("acestream://"))
            {
                ch.url = playList.at(i).split("//").at(1);
                channels.append(ch);
            }
        }
    }
}
