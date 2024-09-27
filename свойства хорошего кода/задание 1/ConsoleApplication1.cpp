#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>

class Printable
{
public:
    virtual ~Printable() = default;
};

class TextPrintable : public Printable
{
public:
    virtual std::string printAsText() const = 0;
};

class HTMLPrintable : public Printable
{
public:
    virtual std::string printAsHTML() const = 0;
};

class JSONPrintable : public Printable
{
public:
    virtual std::string printAsJSON() const = 0;
};

class Data : public TextPrintable, public HTMLPrintable, public JSONPrintable
{
public:
    Data(std::string data) : data_(std::move(data)) {}

    std::string printAsHTML() const override
    {
        return "<html>" + data_ + "</html>";
    }

    std::string printAsText() const override
    {
        return data_;
    }

    std::string printAsJSON() const override
    {
        return "{ \"data\": \"" + data_ + "\"}";
    }

private:
    std::string data_;
};

void saveTo(std::ofstream& file, const TextPrintable& printable) {
    file << printable.printAsText();
}

void saveTo(std::ofstream& file, const JSONPrintable& printable) {
    file << printable.printAsJSON();
}

void saveTo(std::ofstream& file, const HTMLPrintable& printable) {
    file << printable.printAsHTML();
}

// Примеры использования:
// std::ofstream file("output.html");
// Data data("example");
// saveTo(file, data);

/*Объяснения
Разделение интерфейса : Теперь у нас есть три отдельных интерфейса для различных форматов(TextPrintable, HTMLPrintable, JSONPrintable), и классы, которые их реализуют, поддерживают только необходимые методы.Это позволяет более гибко добавлять новые форматы без необходимости вносить изменения в существующий код.

Открытость / Закрытость : Теперь можно легко расширять функциональность, добавляя новые классы, реализующие интерфейсы, без изменения существующих реализаций.

Подстановка Барбары Лисков : Как только классы реализуют свои интерфейсы, они могут гарантировать корректное поведение без выброса исключений — каждый интерфейс выполняется независимо от других.

Эти изменения делают Ваш код более модульным, гибким и поддерживаемым, соответствуя принципам SOLID.*/