#ifndef PIPE_H
#define PIPE_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef int pipe_t[2];

#define PIPE_READ 0
#define PIPE_WRITE 1


#define pipe_init(pipe_) {\
    pipe(pipe_); \
}

#define pipe_close(pipe_, stream_type) {\
    close(pipe_[stream_type]); \
}

#define pipe_read(pipe_, buffer) {\
    read(pipe_[PIPE_READ], buffer, sizeof(buffer)); \
}

#define pipe_write(pipe_, buffer) {\
    write(pipe_[PIPE_WRITE], &buffer, strlen(buffer) + 1); \
}

#endif