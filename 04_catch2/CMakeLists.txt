#минимальная версия cmake
cmake_minimum_required(VERSION 3.10)
#имя проекта
project(demoVendorCatch2)
#добавляем поддиректорию, в которой будет catch2
add_subdirectory(catch2)
#добавляем цель - приложение, у которого исходник с единственным приложением
add_executable(test_dz01 mylist.cpp dz01.cpp)
add_executable(test_dz02 mylist.cpp dz02.cpp)
#линкуемся к catch2, в котором уже есть main
target_link_libraries(test_dz01 PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)
target_link_libraries(test_dz02 PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)