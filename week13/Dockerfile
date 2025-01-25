# Используем базовый образ Ubuntu для сборки C++ приложений
FROM ubuntu:20.04

# Устанавливаем переменную окружения для предотвращения интерактивных запросов в процессе установки
ENV DEBIAN_FRONTEND=noninteractive

# Обновляем пакеты и устанавливаем необходимые зависимости
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    make \
    g++ \
    libssl-dev \
    libspdlog-dev \
    git \
    wget \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Устанавливаем рабочую директорию внутри контейнера
WORKDIR /workspace

# Копируем все содержимое из week13 в контейнер
COPY . /workspace
COPY src/config.cfg src/config.cfg
