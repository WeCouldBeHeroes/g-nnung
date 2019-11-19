#include "fragen.h"

QString fragen::getfrage(){
    int zahl = 1;
    QString nr= QString::fromStdString("frage") + QString::number(zahl) + QString::fromStdString("[6]");
    return nr;
}

fragen::fragen()
{

}
