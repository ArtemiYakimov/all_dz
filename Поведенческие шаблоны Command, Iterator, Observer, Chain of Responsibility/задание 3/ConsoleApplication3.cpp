#include <iostream>
#include <fstream>
#include <exception>

enum class LogMessageType {
    Warning,
    Error,
    FatalError,
    Unknown
};

class LogMessage {
public:
    LogMessage(LogMessageType type, const std::string& message)
        : m_type(type), m_message(message) {}

    LogMessageType type() const { return m_type; }
    const std::string& message() const { return m_message; }

private:
    LogMessageType m_type;
    std::string m_message;
};

class LogHandler {
public:
    virtual ~LogHandler() = default;
    virtual void handle(const LogMessage& message) = 0;
    virtual void setNextHandler(std::unique_ptr<LogHandler>&& nextHandler) {
        m_nextHandler = std::move(nextHandler);
    }

protected:
    std::unique_ptr<LogHandler> m_nextHandler;
};

class FatalErrorHandler : public LogHandler {
public:
    void handle(const LogMessage& message) override {
        if (message.type() == LogMessageType::FatalError) {
            throw std::runtime_error(message.message());
        }
        else if (m_nextHandler) {
            m_nextHandler->handle(message);
        }
    }
};

class ErrorHandler : public LogHandler {
public:
    ErrorHandler(const std::string& filePath) : m_filePath(filePath) {}

    void handle(const LogMessage& message) override {
        if (message.type() == LogMessageType::Error) {
            std::ofstream file(m_filePath, std::ios::app);
            file << message.message() << std::endl;
        }
        else if (m_nextHandler) {
            m_nextHandler->handle(message);
        }
    }

private:
    std::string m_filePath;
};

class WarningHandler : public LogHandler {
public:
    void handle(const LogMessage& message) override {
        if (message.type() == LogMessageType::Warning) {
            std::cout << message.message() << std::endl;
        }
        else if (m_nextHandler) {
            m_nextHandler->handle(message);
        }
    }
};

class UnknownHandler : public LogHandler {
public:
    void handle(const LogMessage& message) override {
        if (message.type() == LogMessageType::Unknown) {
            throw std::runtime_error("Unhandled log message: " + message.message());
        }
    }
};

void log(LogHandler& handler, const LogMessage& message) {
    handler.handle(message);
}

int main() {
    std::unique_ptr<LogHandler> fatalErrorHandler = std::make_unique<FatalErrorHandler>();
    std::unique_ptr<LogHandler> errorHandler = std::make_unique<ErrorHandler>("errors.log");
    std::unique_ptr<LogHandler> warningHandler = std::make_unique<WarningHandler>();
    std::unique_ptr<LogHandler> unknownHandler = std::make_unique<UnknownHandler>();

    fatalErrorHandler->setNextHandler(std::move(errorHandler));
    errorHandler->setNextHandler(std::move(warningHandler));
    warningHandler->setNextHandler(std::move(unknownHandler));

    log(*fatalErrorHandler, LogMessage(LogMessageType::FatalError, "This is a fatal error."));
    log(*fatalErrorHandler, LogMessage(LogMessageType::Error, "This is an error."));
    log(*fatalErrorHandler, LogMessage(LogMessageType::Warning, "This is a warning."));
    log(*fatalErrorHandler, LogMessage(LogMessageType::Unknown, "This is an unknown message."));

    return 0;
}
