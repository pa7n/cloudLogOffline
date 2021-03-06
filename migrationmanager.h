#ifndef MIGRATIONMANAGER_H
#define MIGRATIONMANAGER_H

#include <QSettings>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVersionNumber>

class migrationManager
{
public:
    migrationManager();
private:
    QSqlQuery selectQuery;

    bool updateDatabaseVersion(QString Version);
    bool insertDatabaseVersion(QString Version);


    // Migration Methods:
    void from_1_0_3_to_1_0_4();
};

#endif // MIGRATIONMANAGER_H
