CMAKE_MINIMUM_REQUIRED (VERSION 3.14)
PROJECT (TTC_Backend_Solution C)

# Using C11
# Reference: [1] https://cmake.org/cmake/help/latest/variable/CMAKE_C_STANDARD.html
# Reference: [2] https://cmake.org/cmake/help/latest/manual/cmake-compile-features.7.html#manual:cmake-compile-features(7)
# Reference: [3] https://cmake.org/cmake/help/latest/prop_tgt/C_STANDARD.html#prop_tgt:C_STANDARD
SET (CMAKE_C_STANDARD 11)

MESSAGE (STATUS "Solution: " ${CMAKE_PROJECT_NAME})
MESSAGE (STATUS "Dev-Root BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE (STATUS "Dev-Root SOURCE dir " ${PROJECT_SOURCE_DIR})

SET (REPO_Dev_DIR ${PROJECT_SOURCE_DIR}/../../)
MESSAGE (STATUS "REPO_Dev_DIR: " ${REPO_Dev_DIR})

# Check Operating System type
MESSAGE(STATUS "CMAKE_SYSTEM_NAME : ${CMAKE_SYSTEM_NAME}")
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    ADD_DEFINITIONS( -D _LINUX )
    ADD_DEFINITIONS( -D __GNU__ )
    ADD_DEFINITIONS( -D __linux__ )
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    ADD_DEFINITIONS( -D _WIN32 )
    ADD_DEFINITIONS( -D _CRT_SECURE_NO_WARNINGS )
    # ADD_DEFINITIONS( -D HAVE_VLD )
    ADD_DEFINITIONS( -D USE_UNIXem )
ELSE ()
    MESSAGE(STATUS "Detecting OS platform : (other) : ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

SET(EXECUTABLE_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/../bin)
SET(LIBRARY_OUTPUT_PATH     ${PROJECT_BINARY_DIR}/../lib)

# For Windows OS: Prompt to require CMAKE_BUILD_TYPE parameter in [Debug, Release]
IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    IF (CMAKE_BUILD_TYPE MATCHES Debug)
        MESSAGE( ">>> CMake in Debug mode! <<<" )
    ELSEIF (CMAKE_BUILD_TYPE MATCHES Release)
        MESSAGE( ">>> CMake in Release mode! <<<" )
    ELSE()
        MESSAGE( STATUS "=========================================================================" )
        MESSAGE( STATUS "Please provide CMAKE_BUILD_TYPE command line parameter." )
        MESSAGE( STATUS "For Example:" )
        MESSAGE( STATUS "--- For Debug ----" )
        MESSAGE( STATUS "    cmake -G \"Visual Studio 17 2022\" -A x64 -DCMAKE_BUILD_TYPE=Debug ." )
        MESSAGE( STATUS "    cmake --build . --config Debug" )
        MESSAGE( STATUS "--- For Release ----" )
        MESSAGE( STATUS "    cmake -G \"Visual Studio 17 2022\" -A x64 -DCMAKE_BUILD_TYPE=Release ." )
        MESSAGE( STATUS "    cmake --build . --config Release" )
        MESSAGE( STATUS "=========================================================================" )
        MESSAGE( FATAL_ERROR "" )
    ENDIF (CMAKE_BUILD_TYPE MATCHES Debug)
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Windows")

# To Set the TargetDir variable
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    SET (EXE_TARGET_DIR ${EXECUTABLE_OUTPUT_PATH})
    SET (LIB_TARGET_DIR ${LIBRARY_OUTPUT_PATH})
    SET (DPIntegration_LIB_DIR ${REPO_Dev_DIR}Resource/Modules/DP_Integration_Lib/Linux_StaticLib/x64/Debug)
    SET (CUnit_LIB_DIR /opt/CUnit )
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    SET (CUnit_LIB_DIR $ENV{CUnitRoot} )
    IF (CMAKE_BUILD_TYPE MATCHES Debug)
        SET (EXE_TARGET_DIR ${EXECUTABLE_OUTPUT_PATH}/Debug)
        SET (LIB_TARGET_DIR ${LIBRARY_OUTPUT_PATH}/Debug)
        # SET (DPIntegration_LIB_DIR ${REPO_Dev_DIR}Resource/Modules/DP_Integration_Lib/WIN32_DLL/x64/Debug)
    ELSEIF (CMAKE_BUILD_TYPE MATCHES Release)
        SET (EXE_TARGET_DIR ${EXECUTABLE_OUTPUT_PATH}/Release)
        SET (LIB_TARGET_DIR ${LIBRARY_OUTPUT_PATH}/Release)
        # SET (DPIntegration_LIB_DIR ${REPO_Dev_DIR}Resource/Modules/DP_Integration_Lib/WIN32_DLL/x64/Release)
    ELSE()
        MESSAGE( FATAL_ERROR "Failed to set ${EXE_TARGET_DIR} and ${LIB_TARGET_DIR}" )
    ENDIF (CMAKE_BUILD_TYPE MATCHES Debug)
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")
MESSAGE( STATUS "EXE_TARGET_DIR: " ${EXE_TARGET_DIR})
MESSAGE( STATUS "LIB_TARGET_DIR: " ${LIB_TARGET_DIR})


MESSAGE(STATUS "")
MESSAGE(STATUS "=========================================================")
MESSAGE(STATUS "| Global - Common     (Source code and Libraries) BEGIN |")
MESSAGE(STATUS "=========================================================")
MESSAGE(STATUS "")

INCLUDE_DIRECTORIES(
    ../../Code
    ../../Code/Utilities
    ../../Code/Utilities/Tools/TMSrcImport
)


MESSAGE(STATUS "")
MESSAGE(STATUS "=========================================================")
MESSAGE(STATUS "| Global - Common     (Source code and Libraries) END   |")
MESSAGE(STATUS "=========================================================")
MESSAGE(STATUS "")


