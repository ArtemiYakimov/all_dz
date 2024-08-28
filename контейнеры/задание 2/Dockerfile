# Stage 1: Build with GCC
FROM gcc:14.1.0 AS gcc-build

WORKDIR /app

COPY main.cpp /app/

RUN gcc -v -Wall -o fraction-app-gcc main.cpp -lstdc++

# Stage 2: Build with Clang
FROM clang AS clang-build

WORKDIR /app

COPY main.cpp /app/

RUN clang++ -v -Wall -o fraction-app-clang main.cpp -lstdc++

# Stage 3: Create the final image
FROM alpine:latest

WORKDIR /app

COPY --from=gcc-build /app/fraction-app-gcc /app/
COPY --from=clang-build /app/fraction-app-clang /app/

EXPOSE 8080

CMD ["./fraction-app-gcc"]
