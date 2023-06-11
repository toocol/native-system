#include "native_system.h"
#include <string>

REXPORT void* RCALL mmap_ffi(void* addr, size_t len, int prot, int flags,
                             int fildes, int64_t offset_type) {
  return mmap(addr, len, prot, flags, fildes, offset_type);
}

REXPORT int RCALL munmap_ffi(void* addr, size_t len) {
  return munmap(addr, len);
}

REXPORT int RCALL chsize_ffi(int file_handle, int32_t size) {
#ifdef _MSVC_LANG
  return _chsize(file_handle, size);
#else
  return ftruncate(file_handle, size);
#endif
}