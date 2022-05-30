#ifndef _INC_COMMON_datatypes_H
#define _INC_COMMON_datatypes_H

#include <stdbool.h>
#include <stdint.h>

#ifdef _WIN32

    #ifdef _WIN64
    #define ssize_t __int64
    #else
    #define ssize_t long
    #endif

/* Values for the second argument to access. These may be OR'd together.  */
#define R_OK    4       /* Test for read permission.  */
#define W_OK    2       /* Test for write permission.  */
// #define   X_OK    1       /* execute permission - unsupported in windows*/
#define F_OK    0       /* Test for existence.  */
    
#endif

    typedef float           float32_t;
    typedef double          float64_t;

    typedef unsigned char	byte;
    typedef char            sbyte;

#ifndef PATH_MAX
    #define PATH_MAX 250
#endif

// ========================================
// Definition of reserved values
// ----------------------------------------
#define UInt16_MAX      0xFFFF
#define UInt16_NOP      0xFFFF
#define UInt16_ANY      0xFFFF


#define UInt32_MAX      0xFFFFFFFF
#define UInt32_NOP      0xFFFFFFFF
#define UInt32_ANY      0xFFFFFFFF

#define UInt64_MAX      0xFFFFFFFFFFFFFFFF
#define UInt64_NOP      0xFFFFFFFFFFFFFFFF
#define UInt64_ANY      0xFFFFFFFFFFFFFFFF
// ========================================

#define PASS 1
#define FAIL 0

typedef uint32_t HResult;

#define HResult_Unknown 0
#define HResult_OK      1


#define HResult_FAILED              0x00100000
#define HResult_PARAM_NULL          0x00110000
#define HResult_PARAM_OUTRANGE      0x00120000
#define HResult_BUF_NOSPACE         0x00120001
#define HResult_FILE_NO_ACCESS      0x00130000
#define HResult_FILE_NOTEXISTS      0x00130001
#define HResult_FILE_CannotCreate   0x00130002
#define HResult_FILE_CannotOpen     0x00130004
#define HResult_FILE_CannotRead     0x00130008
#define HResult_FILE_CannotWrite    0x00130010
#define HResult_DIR_LOOKUP_FAILED   0x00130020
#define HResult_PATH_RetrieveFail   0x00130040
#define HResult_FILE_OPEN_FAIL      0x00130080
#define HResult_MODULE_NotFound     0x00140001
#define HResult_MODULE_LOAD_FAIL    0x00140002
#define HResult_SYMBLE_LOAD_FAIL    0x00140003

#define HResult_ALLOC_FAIL          0x00170000
#define HResult_DATA_INVALID        0x00180000
#define HResult_DATA_CONFLICT       0x00180001
#define HResult_NOT_SUPPORTED       0x00180001
#define HResult_OBJECT_IS_NULL      0x00190000
#define HResult_DECODE_FAIL         0x001B0000

// for serial-port
#define HResult_SERIAL_FAIL         0x7D000000
#define HResult_SERIAL_OpenFAIL     0x7D000001
#define HResult_SERIAL_GetStateFAIL 0x7D000002
#define HResult_SERIAL_SetStateFAIL 0x7D000003
#define HResult_SERIAL_SetTimeoutsFAIL 0x7D000004
#define HResult_SERIAL_InvalidHandle 0x7D000005
#define HResult_SERIAL_SendFAIL     0x7D000006

// MSDN Topic: Windows Sockets Error Codes
// MSDN Link: https://docs.microsoft.com/zh-cn/windows/win32/winsock/windows-sockets-error-codes-2
#define HResult_SOCKET_FAIL               0x7E000000
#define HResult_SOCKET_WSAEINTR           (0x7E000000 + 10004)
#define HResult_SOCKET_WSAEFAULT          (0x7E000000 + 10014)
#define HResult_SOCKET_WSAEWOULDBLOCK     (0x7E000000 + 10035)
#define HResult_SOCKET_WSAEINPROGRESS     (0x7E000000 + 10036)
#define HResult_SOCKET_WSAENOTSOCK        (0x7E000000 + 10038)
#define HResult_SOCKET_WSAENETDOWN        (0x7E000000 + 10050)
#define HResult_SOCKET_WSAEPROCLIM        (0x7E000000 + 10067)
#define HResult_SOCKET_WSASYSNOTREADY     (0x7E000000 + 10091)
#define HResult_SOCKET_WSAVERNOTSUPPORTED (0x7E000000 + 10092)
#define HResult_SOCKET_WSANOTINITIALISED  (0x7E000000 + 10093)
#define HResult_SOCKET_TypeNotSupported   0x7E000001
#define HResult_SOCKET_INVALID            0x7E000002
#define HResult_SOCKET_SetOptFailed       0x7E000003
#define HResult_SOCKET_BindFailed         0x7E000004

#define HResult_CUSTOM_7F_FAIL      0x7F000000

#define HResult_SQLite3OpenFail     0x00140001
#define HResult_SQLite3QueryFail    0x00150001
#define HResult_SQLite3QueryNULL    0x00150002
#define HResult_SQLite3ExecFailed   0x00150004
#define HResult_SQLite3PrepareErr   0x00150008

#define HResult_THREAD_CREATEFAIL   0x00210001
#define HResult_MUTEX_CREATEFAIL    0x00210002

#define HResult_FILE_READ_FAIL      0x00150000
#define HResult_FILE_WRITEFAIL      0x00160000
#define HResult_STRING_TOOLONG      0x001A0000
#define HResult_LOG_SETUP_FAIL      0x001C0000
#define HResult_CONFIG_FAIL         0x001D0000

#ifdef _WIN32
#include <io.h>
#   ifndef access
#       define access _access
#   endif
#   ifndef strncasecmp
#       define strncasecmp _strnicmp
#   endif
#   ifndef strcasecmp
#       define strcasecmp _stricmp
#   endif
#   ifndef strnicmp
#       define strnicmp _strnicmp
#   endif
#   ifndef strtok_r
#       define strtok_r strtok_s
#   endif
#   ifndef getcwd
#       define getcwd _getcwd
#   endif
#   ifndef stricmp
#       define stricmp _stricmp
#   endif
#endif

typedef HResult(*MappedFileHandle)(const byte* bytes, const size_t filesize, void* data);

#endif // !_INC_COMMON_datatypes_H
