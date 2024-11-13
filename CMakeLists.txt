cmake_minimum_required(VERSION 3.10)
project(BankingSystem)

# Specify the C++ standard
set(CMAK_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Add source files
set(SOURCES
    src/main.cpp
)

# Add the executable
add_executable(BankingSystem ${SOURCES})  # You can use 'BankingSystem' or 'MyCppProject' here
