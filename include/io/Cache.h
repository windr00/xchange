#ifndef _IO_CACHE_H_
#define _IO_CACHE_H_

#include "io/Buffer.h"
#include "base/EventEmitter.h"

namespace xchange {

namespace io {

    class Cache {
        public:
            Cache(uint64_t size);
            ~Cache();

            Buffer read(uint64_t len);
            int write(const Buffer &buff);

            uint64_t size() const {return size_;};
            uint64_t usableSize() const {return maxSize_-size();};
            uint64_t maxSize() const {return maxSize_;};
        private:
            uint8_t *data_;
            uint64_t size_;
            uint64_t maxSize_;
            uint64_t readIndex_, writeIndex_;
    };

}

}

#endif
