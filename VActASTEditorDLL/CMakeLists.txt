cmake_minimum_required(VERSION 3.26)
project(VActASTEditorDLL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME VActASTEditorDLL)
string(REPLACE "DLL" "" TARGET_NAME ${PROJECT_NAME})
set(OUT_DIR "${CMAKE_SOURCE_DIR}/Bin/$<CONFIG>/${CMAKE_VS_PLATFORM_NAME}")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(SYSTEM ${LLVM_INCLUDE_DIRS})
include_directories(SYSTEM ${CLANG_INCLUDE_DIRS})
find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)
add_definitions(${LLVM_DEFINITIONS})

add_library(${PROJECT_NAME} SHARED
    VActEditorAction.cpp
    VActEditorComment.cpp
    VActEditorGroup.cpp
    VActEditorInstance.cpp
    VActEditorConsumer.cpp
    VActEditorCursor.cpp
    VActEditorLink.cpp
    VActEditorNode.cpp
    VActEditorUI.cpp
    VActEditorVisitor.cpp
)

file(GLOB_RECURSE VACT_PUBLIC_HEADERS
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/*.h
)

file(GLOB_RECURSE VACT_PRIVATE_HEADERS
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

target_sources(${PROJECT_NAME} PUBLIC
        ${VACT_PUBLIC_HEADERS}
)

target_sources(${PROJECT_NAME} PRIVATE
        ${VACT_PRIVATE_HEADERS}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME ${TARGET_NAME}
    RUNTIME_OUTPUT_DIRECTORY  "${OUT_DIR}"
    LIBRARY_OUTPUT_DIRECTORY  "${OUT_DIR}"
    ARCHIVE_OUTPUT_DIRECTORY  "${OUT_DIR}"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    EDITOR_BUILD_DLL
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Include
)

target_link_libraries(${PROJECT_NAME}
    clangTooling
    clangFrontend
    clangASTMatchers
    clangRewrite
    clangAST
    clangBasic
    clangLex
    LLVMSupport
    LLVMOption
    LLVMCore
)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /GR)
endif()