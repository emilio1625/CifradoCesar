cmake_minimum_required(VERSION 3.5)
project(ProyectoHuicho)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall")

set(SOURCE_FILES
        Codificar.c
        Codificar.h
        Decodificar.c
        Decodificar.h
)
add_executable(Codificar
        Codificar.c
        Codificar.h
)
add_executable(Decodificar
        Decodificar.c
        Decodificar.h
)
set_target_properties(Codificar Decodificar PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "C:\\Users\\Emilio\\ClionProjects\\ProyectoHuicho\\lib"
        LIBRARY_OUTPUT_DIRECTORY "C:\\Users\\Emilio\\ClionProjects\\ProyectoHuicho\\lib"
        RUNTIME_OUTPUT_DIRECTORY "C:\\Users\\Emilio\\ClionProjects\\ProyectoHuicho\\bin"
)