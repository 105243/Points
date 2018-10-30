#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <iostream>
#include <QString>

using namespace std;

struct Point{
    float x;
    float y;
    char Name;
};

float distance(Point A, Point B);
float perimeter(Point Array[4]);
float area(Point Array[4]);

QString printQuad(Point Array[4]);

float distance(Point A, Point B) {
    int distance = sqrt(pow(B.x-A.x,2) + pow(B.y-A.y,2));
    return distance;
}

float perimeter(Point Array[4]) {
    float AB = distance(Array[0],Array[1]);
    float BC = distance(Array[1],Array[2]);
    float CD = distance(Array[2],Array[3]);
    float DA = distance(Array[0],Array[3]);

    float perimeter = AB+BC+CD+DA;
    return perimeter;
}

float area(Point Array[4]) {
    float AB = distance(Array[0],Array[1]);
    float BC = distance(Array[1],Array[2]);
    float CD = distance(Array[2],Array[3]);
    float DA = distance(Array[0],Array[3]);
    float K = sqrt(2)*AB;

    float p1 = (AB+BC+K)/2;
    float p2 = (CD+DA+K)/2;

    float area1 = sqrt(p1*(p1-AB)*(p1-BC)*(p1-K));
    float area2 = sqrt(p2 *(p2-CD)*(p2-DA)*(p2-K));
    float area3 = area1+area2;
    return area3;
}


int main()
{
    Point quadOne[4];
    Point quadPoints[4];


    quadOne[0].Name='A';
    quadOne[0].x=-0.0;
    quadOne[0].y=-0.0;

    quadOne[1].Name='B';
    quadOne[1].x=4.0;
    quadOne[1].y=-0.0;

    quadOne[2].Name='C';
    quadOne[2].x=4.0;
    quadOne[2].y=4.0;

    quadOne[3].Name='D';
    quadOne[3].x=-0.0;
    quadOne[3].y=4.0;

    quadPoints[0].Name='E';
    quadPoints[0].x=-10;
    quadPoints[0].y=-10;

    quadPoints[1].Name='F';
    quadPoints[1].x=10;
    quadPoints[1].y=-10;

    quadPoints[2].Name='G';
    quadPoints[2].x=10;
    quadPoints[2].y=10;

    quadPoints[3].Name='H';
    quadPoints[3].x=-10;
    quadPoints[3].y=10;

    QFile openfile("points.txt");
    if (openfile.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream writeStream(&openfile);
        writeStream << printQuad(quadOne);
        writeStream << printQuad(quadPoints);
        openfile.close();
        cout << "Open \"points.txt\" file in project bulid directory.";
    }
    return 0;
}




QString printQuad(Point Array[4])
{
    Point current;
    QString temp;
    QString qsRetVal = "Quadrilateral with points: ";
    for (int i=0; i < 4; i++) {
        current = Array[i];
        temp = "%1[%2;%3] ";
        temp = temp.arg(current.Name).arg(current.x).arg(current.y);
        qsRetVal.append(temp);
    }
    temp = "\r\nHas perimeter %1 and area %2\r\n";
    temp = temp.arg(perimeter(Array)).arg(area(Array));
    qsRetVal.append(temp);
    return qsRetVal;
}

