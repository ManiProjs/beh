cmake_minimum_required(VERSION 3.15)
project(beh)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Enable optional WebP support
option(WITH_WEBP "Enable WebP support" ON)

if(WITH_WEBP)
    find_package(PkgConfig)
    if(PKG_CONFIG_FOUND)
        pkg_check_modules(WEBP libwebp)
        if(WEBP_FOUND)
            message(STATUS "WebP support enabled")
            add_definitions(-DWITH_WEBP)
            include_directories(${WEBP_INCLUDE_DIRS})
            link_directories(${WEBP_LIBRARY_DIRS})
        else()
            message(WARNING "libwebp not found. WebP support disabled.")
            set(WITH_WEBP OFF)
        endif()
    else()
        message(WARNING "pkg-config not found. WebP support disabled.")
        set(WITH_WEBP OFF)
    endif()
endif()

# Add source files
add_executable(beh
    src/main.cpp
)

# Link libraries
target_link_libraries(beh
    sfml-graphics
    sfml-window
    sfml-system
)

if(WITH_WEBP AND WEBP_FOUND)
    target_link_libraries(beh ${WEBP_LIBRARIES})
endif()

# Installer metadata
set(CPACK_PACKAGE_NAME "beh")
set(CPACK_PACKAGE_VENDOR "Mani Arasteh")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A simple image viewer that can be run from the command-line and a better alternative.")
set(CPACK_PACKAGE_VERSION "0.1.0")
set(CPACK_PACKAGE_CONTACT "mani.arasteh92@gmail.com")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")

# Set the install directory
install(TARGETS beh
        RUNTIME DESTINATION bin)

# Include CPack
include(CPack)
