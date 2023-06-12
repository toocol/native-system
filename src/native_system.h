#ifndef _NATIVE_SYSTEM_H
#define _NATIVE_SYSTEM_H

#ifdef __APPLE__
#define REXPORT __attribute__((visibility("default")))
#define RCALL __attribute__((cdecl))
#else
#define REXPORT __declspec(dllexport)
#define RCALL __stdcall
#endif

extern "C" {
#ifdef _MSVC_LANG
#include <unistd.h>
#include <windows.h>
#else
#include <sys/param.h>
#include <unistd.h>
#endif
#include <sys/mman.h>

REXPORT void* RCALL mmap_ffi(void* addr, size_t len, int prot, int flags,
                             int fildes, int64_t offset_type);

REXPORT int RCALL munmap_ffi(void* addr, size_t len);

REXPORT int RCALL chsize_ffi(int file_handle, int32_t size);
}
#endif