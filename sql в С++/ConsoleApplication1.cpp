#include <iostream>
#include <string>
#include <vector>
#include <pqxx/pqxx>

// Класс для управления клиентами
class ClientManager {
private:
    pqxx::connection connection;

public:
    ClientManager() : connection("dbname=mydb user=myuser password=mypassword hostaddr=127.0.0.1 port=5432") {
        // Подключение к базе данных
        if (connection.is_open()) {
            std::cout << "Успешное подключение к базе данных!" << std::endl;
        }
        else {
            std::cout << "Ошибка подключения к базе данных!" << std::endl;
        }
    }

    void createDatabaseStructure() {
        // Создание структуры БД (таблицы)
        pqxx::work txn(connection);
        txn.exec("CREATE TABLE IF NOT EXISTS clients ("
            "id SERIAL PRIMARY KEY,"
            "first_name VARCHAR(50) NOT NULL,"
            "last_name VARCHAR(50) NOT NULL,"
            "email VARCHAR(100) NOT NULL,"
            "phones VARCHAR(100)[]"
            ")");
        txn.commit();
        std::cout << "Структура БД создана!" << std::endl;
    }

    void addClient(const std::string& firstName, const std::string& lastName, const std::string& email) {
        // Добавление нового клиента
        pqxx::work txn(connection);
        std::string query = "INSERT INTO clients (first_name, last_name, email) VALUES ('" + firstName + "', '" + lastName + "', '" + email + "')";
        txn.exec(query);
        txn.commit();
        std::cout << "Новый клиент добавлен!" << std::endl;
    }

    void addPhoneForClient(int clientId, const std::string& phone) {
        // Добавление телефона для существующего клиента
        pqxx::work txn(connection);
        std::string query = "UPDATE clients SET phones = array_append(phones, '" + phone + "') WHERE id = " + std::to_string(clientId);
        txn.exec(query);
        txn.commit();
        std::cout << "Телефон добавлен для клиента с ID " << clientId << std::endl;
    }

    void updateClientData(int clientId, const std::string& firstName, const std::string& lastName, const std::string& email) {
        // Изменение данных о клиенте
        pqxx::work txn(connection);
        std::string query = "UPDATE clients SET first_name = '" + firstName + "', last_name = '" + lastName + "', email = '" + email + "' WHERE id = " + std::to_string(clientId);
        txn.exec(query);
        txn.commit();
        std::cout << "Данные клиента с ID " << clientId << " обновлены!" << std::endl;
    }

    void removePhoneForClient(int clientId, const std::string& phone) {
        // Удаление телефона у существующего клиента
        pqxx::work txn(connection);
        std::string query = "UPDATE clients SET phones = array_remove(phones, '" + phone + "') WHERE id = " + std::to_string(clientId);
        txn.exec(query);
        txn.commit();
        std::cout << "Телефон удален у клиента с ID " << clientId << std::endl;
    }

    void removeClient(int clientId) {
        // Удаление существующего клиента
        pqxx::work txn(connection);
        std::string query = "DELETE FROM clients WHERE id = " + std::to_string(clientId);
        txn.exec(query);
        txn.commit();
        std::cout << "Клиент с ID " << clientId << " удален!" << std::endl;
    }

    void findClient(const std::string& searchData) {
        // Поиск клиента по данным (имени, фамилии, email или телефону)
        pqxx::work txn(connection);
        std::string query = "SELECT * FROM clients WHERE first_name = '" + searchData + "' OR last_name = '" + searchData + "' OR email = '" + searchData + "' OR phones @> ARRAY['" + searchData + "']";
        pqxx::result result = txn.exec(query);
        txn.commit();

        if (result.empty()) {
            std::cout << "Клиент не найден!" << std::endl;
        }
        else {
            std::cout << "Найденные клиенты:" << std::endl;
            for (const auto& row : result) {
                std::cout << "ID: " << row["id"].as<int>() << std::endl;
                std::cout << "Имя: " << row["first_name"].as<std::string>() << std::endl;
                std::cout << "Фамилия: " << row["last_name"].as<std::string>() << std::endl;
                std::cout << "Email: " << row["email"].as<std::string>() << std::endl;
                std::vector<std::string> phones = row["phones"].as<std::vector<std::string>>();
                std::cout << "Телефоны: ";
                for (const auto& phone : phones) {
                    std::cout << phone << ", ";
                }
                std::cout << std::endl;
            }
        }
    }
};

int main() {
    ClientManager clientManager;
    clientManager.createDatabaseStructure();

    // Пример использования методов
    clientManager.addClient("John", "Doe", "john.doe@example.com");
    clientManager.addPhoneForClient(1, "123456789");
    clientManager.updateClientData(1, "John", "Smith", "john.smith@example.com");
    clientManager.removePhoneForClient(1, "123456789");
    clientManager.removeClient(1);
    clientManager.findClient("John");

    return 0;
}