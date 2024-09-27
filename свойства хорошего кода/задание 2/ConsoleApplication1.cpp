#include <fstream>
#include <string>
#include <stdexcept>

class IHTMLPrintable {
public:
    virtual ~IHTMLPrintable() = default;
    virtual std::string printAsHTML() const = 0;
};

class ITextPrintable {
public:
    virtual ~ITextPrintable() = default;
    virtual std::string printAsText() const = 0;
};

class IJSONPrintable {
public:
    virtual ~IJSONPrintable() = default;
    virtual std::string printAsJSON() const = 0;
};

class HTMLData : public IHTMLPrintable {
public:
    HTMLData(std::string data) : data_(std::move(data)) {}
    std::string printAsHTML() const override {
        return "<html>" + data_ + "</html>";
    }

private:
    std::string data_;
};

class TextData : public ITextPrintable {
public:
    TextData(std::string data) : data_(std::move(data)) {}
    std::string printAsText() const override {
        return data_;
    }

private:
    std::string data_;
};

class JSONData : public IJSONPrintable {
public:
    JSONData(std::string data) : data_(std::move(data)) {}
    std::string printAsJSON() const override {
        return "{ \"data\": \"" + data_ + "\"}";
    }

private:
    std::string data_;
};

void saveToHTML(std::ofstream& file, const IHTMLPrintable& printable) {
    file << printable.printAsHTML();
}

void saveToJSON(std::ofstream& file, const IJSONPrintable& printable) {
    file << printable.printAsJSON();
}

void saveToText(std::ofstream& file, const ITextPrintable& printable) {
    file << printable.printAsText();
}