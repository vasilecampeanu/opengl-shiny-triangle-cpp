cmake_minimum_required(VERSION 3.10)

set(This glad)

# Header files
set(HEADERS
    include/glad/glad.h
    include/KHR/khrplatform.h
)

# Source files
set(SOURCES
    src/glad.c
)

# Create the library
add_library(${This} STATIC ${SOURCES} ${HEADERS})

# Add the include directory
target_include_directories(${This} PUBLIC include)
