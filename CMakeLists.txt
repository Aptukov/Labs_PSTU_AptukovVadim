cmake_minimum_required(VERSION 3.20)
project(PSTU_Labs LANGUAGES CXX)

# Общие настройки стандарта для всех лаб
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Подключаем папку первого семестра
add_subdirectory(semestr1)