# The Game Of Life

Реализация клеточного автомата "Игра Жизни" с использованием SDL2 для визуализации.

## Скриншоты
![Image](https://github.com/user-attachments/assets/f4acfc9b-a6a1-414a-9c79-b189c4ef3626)

## Особенности
- 🎮 Интерактивное управление: добавляйте/удаляйте клетки кликом мыши
- ⏯️ Управление симуляцией: запуск, пауза
- ⚙️ Настройка скорости симуляции

## Требования
- Компилятор с поддержкой C++17
- CMake ≥ 3.10
- Библиотеки SDL2 и SDL2_ttf

## Установка
```bash
# Клонировать репозиторий
git clone https://github.com/IanZaripov/The-Game-Of-Life.git
cd The-Game-Of-Life

# Создать папку для сборки
mkdir build
cd build

# Собрать проект
cmake ..
cmake --build .
