cmake_minimum_required(VERSION 3.5)

project(MalfunctionRequest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 1.10.5)
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(nlohmann_json GIT_REPOSITORY https://github.com/nlohmann/json.git
                         GIT_TAG v3.11.3)
FetchContent_MakeAvailable(nlohmann_json)

find_package(OpenSSL)

add_executable(MalfunctionRequest main.cpp)

target_link_libraries(MalfunctionRequest
    PRIVATE cpr::cpr
    PRIVATE nlohmann_json::nlohmann_json
    PRIVATE OpenSSL::SSL
)

include(GNUInstallDirs)
install(TARGETS MalfunctionRequest
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
