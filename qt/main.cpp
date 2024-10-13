#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTcpSocket>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Создание экземпляра класса QSqlDatabase
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");

    // Открытие базы данных
    if (!db.open()) {
        qDebug() << "Ошибка подключения к базе данных:" << db.lastError().text();
        return -1;
    }
    qDebug() << "Подключение к базе данных успешно";

    // Пример использования QSqlQuery для выполнения SQL-запроса
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS test (id INTEGER PRIMARY KEY, name TEXT)")) {
        qDebug() << "Ошибка при создании таблицы:" << query.lastError().text();
    }

    // Создание экземпляра класса QTcpSocket
    QTcpSocket *socket = new QTcpSocket();
    socket->connectToHost("localhost", 8080);

    if (!socket->waitForConnected(3000)) {
        qDebug() << "Ошибка подключения к хосту:" << socket->errorString();
    } else {
        qDebug() << "Подключение к хосту успешно";

        // Здесь можно отправить или принять данные
        socket->write("Hello from client!");
        socket->flush();
    }

    // Освобождаем память
    delete socket;
    db.close();

    return a.exec();
}
