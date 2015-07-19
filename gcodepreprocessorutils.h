#ifndef GCODEPREPROCESSORUTILS_H
#define GCODEPREPROCESSORUTILS_H

#include <QObject>

class GcodePreprocessorUtils : public QObject
{
    Q_OBJECT
public:    
    static QString overrideSpeed(QString command, double speed);
    static QString removeComment(QString command);
    static QString parseComment(QString command);
    static QString truncateDecimals(int length, QString command);
    static QString removeAllWhitespace(QString command);
    static QList<QString> parseCodes(QList<QString> args, char code);
    static QList<int> parseGCodes(QString command);
    static QList<int> parseMCodes(QString command);
    static QList<QString> splitCommand(QString command);
    static double parseCoord(QList<QString> argList, char c);
    static QVector3D updatePointWithCommand(QVector3D initial, double x, double y, double z, bool absoluteMode);
    static QVector3D updatePointWithCommand(QList<QString> commandArgs, QVector3D initial, bool absoluteMode);
    static QVector3D updatePointWithCommand(QString command, QVector3D initial, bool absoluteMode);
    static QVector3D convertRToCenter(QVector3D start, QVector3D end, double radius, bool absoluteIJK, bool clockwise);
    static QVector3D updateCenterWithCommand(QList<QString> commandArgs, QVector3D initial, QVector3D nextPoint, bool absoluteIJKMode, bool clockwise);
    static QString generateG1FromPoints(QVector3D start, QVector3D end, bool absoluteMode, int precision);
    static double getAngle(QVector3D start, QVector3D end);
    static double calculateSweep(double startAngle, double endAngle, bool isCw);
    static QList<QVector3D> generatePointsAlongArcBDring(QVector3D start, QVector3D end, QVector3D center, bool clockwise, double R, double minArcLength, double arcSegmentLength);
    static QList<QVector3D> generatePointsAlongArcBDring(QVector3D p1, QVector3D p2, QVector3D center, bool isCw, double radius, double startAngle, double sweep, int numPoints);
signals:

public slots:

};

#endif // GCODEPREPROCESSORUTILS_H