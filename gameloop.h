#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <mainwindow.h>
#include <QObject>
#include <question.h>

class GameLoop : public QObject
{
    Q_OBJECT

public:
    GameLoop(MainWindow *mainWindow);
    void init();

private:
    MainWindow* mainWindow;
    int rundenfragen[15];
    int round = 0;
    void gameloop(int round,bool lost = false);
    void gameEnd(bool lost);
    void askQuestion(int round);
    virtual ~GameLoop();
    Question getQuestion(int round);

    QString fragen[20][6] = {
        {"Wie viele Weihnachtsbäume werden in Deutschland pro Jahr verkauft?","30Mio","40Mio","5Mio","10Mio","2"},
        {"Wie viele Liter Bier werden in Deutschland pro Kopf jährlich getrunken?","100l","200l","50l","10l","1"},
        {"Wie viele Einkerbungen hat ein Golfball?","254","100","145","365","4"},
        {"Wie lange dauert der 30-jährige Krieg?","1 Jahr","30 Jahre","15 Jahre","20 Jahre","2"},
        {"Wer wurde im Jahre 2019 vom DJMag zum besten DJ des Jahres gekürt?","Fritz","Dimitri Vegas and Like Mike","Rihanna","Hardwell","2"},
        {"Wie heißt der Satz des Pythagoras?","a2+b2=c2","c2+d2=e2","a2-b2=c2","b2+o2=t2","1"},
        {"Wie viele Knochen hat der menschliche Körper?","144","187","214","420","3"},
        {"Wofür stehen die olympischen Ringe?","Audi + Mercedes","Kontinente","wichtigsten Länder","EU","2"},
        {"Wie lange dauerte der Hundertjährige Krieg?","100","124","130","116","4"},
        {"Wie lange dauerte der Bau des Kölner Doms?","632","850","156","1002","1"},
        {"Wann wurde das iPhone vorgestellt?","2009","2010","2007","2000","3"},
        {"Wie lang ist eine Meile?","1609m","2105m","1543m","1854m","1"},
        {"Mit wie vielen Nachbarländern teilt Deutschland sich eine Grenze?","12","9","15","7","2"},
        {"In welchem Jahr wurde der Euro eingeführt?","1999","2002","2001","2004","2"},
        {"Wann wurde der Fußball in Deutschland eingeführt?","1874","1780","1912","1785","1"},
        {"Wie werden die aktuellen Klima-Demonstrationen auch bezeichnet?","Fridays for Future","Dienstag für Diesel","Holidays for Hubraum","Monday for Motors","1"},
        {"Wie viele Buchstaben hat das hawaiianische Alphabet?","150","12","56","80","2"},
        {"Kranplätze müssen .. ",".. verdichtet sein!",".. abgemessen sein!",".. groß genug sein!",".. abgesperrt sein!","1"},
        {"Welche ist die grlßte Stadt der Welt?","Berlin","Paris","Moskau","Mexiko-Stadt","4"},
        {"Gibt es in einer Teefabrik Kaffeepausen?","Lost","Bruder?!","Ah ja","Nein","2"}
    };

public slots:
    void startButtonPress();
    void success(bool status);

};

#endif // GAMELOOP_H
