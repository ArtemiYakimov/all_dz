#include <iostream>
#include <fstream>
#include <string>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class ConsoleLogCommand : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class FileLogCommand : public LogCommand {
public:
    FileLogCommand(const std::string& filePath) : m_filePath(filePath) {}

    void print(const std::string& message) override {
        std::ofstream file(m_filePath, std::ios::app); // открываем файл в режиме добавления
        file << message << std::endl; // записываем сообщение в файл
        file.close(); // закрываем файл
    }

private:
    std::string m_filePath;
};

void print(LogCommand& logCommand, const std::string& message) {
    logCommand.print(message);
}

int main() {
    ConsoleLogCommand consoleCommand;
    print(consoleCommand, "Hello, console!");

    FileLogCommand fileCommand("log.txt");
    print(fileCommand, "Hello, file!");

    return 0;
}
