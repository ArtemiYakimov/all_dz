FROM ubuntu:latest

# Установите зависимости
RUN apt-get update && apt-get install -y g++ 

# Скопируйте исходный код
WORKDIR /app
COPY hello.cpp .

# Скомпилируйте код
RUN g++ -o hello hello.cpp

# Запустите программу
CMD ["./hello"]
