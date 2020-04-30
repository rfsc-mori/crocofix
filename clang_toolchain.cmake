if(APPLE)
    set(CLANG_ROOT "/usr")
else()
    set(CLANG_ROOT "/clang_10.0.0")
endif()

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_COMPILER             "${CLANG_ROOT}/bin/clang")
set(CMAKE_C_FLAGS                "-Wall")
set(CMAKE_C_FLAGS_DEBUG          "-g")
set(CMAKE_C_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
set(CMAKE_C_FLAGS_RELEASE        "-O3 -DNDEBUG")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")

set(CMAKE_CXX_COMPILER             "${CLANG_ROOT}/bin/clang++")
set(CMAKE_CXX_FLAGS                "-Wall -ftemplate-backtrace-limit=0")
set(CMAKE_CXX_FLAGS_DEBUG          "-g")
set(CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE        "-O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

add_definitions(-Wno-error=suggest-override)
add_definitions(-Wno-unknown-warning-option)
add_definitions(-Wno-overloaded-virtual)
add_definitions(-Wno-unneeded-internal-declaration)
add_definitions(-Wno-unused-private-field)
add_definitions(-Wno-pessimizing-move)
add_definitions(-Wno-mismatched-tags)
add_definitions(-Wno-delete-non-abstract-non-virtual-dtor)
add_definitions(-D _WCHAR_T=int)