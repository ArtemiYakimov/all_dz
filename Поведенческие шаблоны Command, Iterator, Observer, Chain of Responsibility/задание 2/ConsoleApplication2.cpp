#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Observer {
public:
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
    virtual ~Observer() = default; // Virtual destructor for proper cleanup
};

class Observable {
private:
    std::vector<Observer*> observers_;

public:
    void addObserver(Observer* observer) {
        observers_.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        auto it = std::find(observers_.begin(), observers_.end(), observer);
        if (it != observers_.end()) {
            observers_.erase(it);
        }
    }

    void warning(const std::string& message) const {
        for (Observer* observer : observers_) {
            observer->onWarning(message);
        }
    }

    void error(const std::string& message) const {
        for (Observer* observer : observers_) {
            observer->onError(message);
        }
    }

    void fatalError(const std::string& message) const {
        for (Observer* observer : observers_) {
            observer->onFatalError(message);
        }
    }
};

class ConsoleWarningObserver : public Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << "Warning: " << message << std::endl;
    }
};

class FileErrorObserver : public Observer {
private:
    std::string filePath_;

public:
    FileErrorObserver(const std::string& filePath) : filePath_(filePath) {}

    void onError(const std::string& message) override {
        std::ofstream file(filePath_);
        if (file.is_open()) {
            file << "Error: " << message << std::endl;
            file.close();
        }
        else {
            std::cerr << "Unable to open file: " << filePath_ << std::endl;
        }
    }
};

class ConsoleAndFileFatalErrorObserver : public Observer {
private:
    std::string filePath_;

public:
    ConsoleAndFileFatalErrorObserver(const std::string& filePath) : filePath_(filePath) {}

    void onFatalError(const std::string& message) override {
        std::cout << "Fatal Error: " << message << std::endl;
        std::ofstream file(filePath_);
        if (file.is_open()) {
            file << "Fatal Error: " << message << std::endl;
            file.close();
        }
        else {
            std::cerr << "Unable to open file: " << filePath_ << std::endl;
        }
    }
};

int main() {
    Observable observable;

    ConsoleWarningObserver warningObserver;
    FileErrorObserver errorObserver("error.log");
    ConsoleAndFileFatalErrorObserver fatalErrorObserver("fatal_error.log");

    observable.addObserver(&warningObserver);
    observable.addObserver(&errorObserver);
    observable.addObserver(&fatalErrorObserver);

    observable.warning("This is a warning");
    observable.error("This is an error");
    observable.fatalError("This is a fatal error");

    return 0;
}
