#ifndef PIPE_H
#define PIPE_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef int pipe_t[2];

#define PIPE_READ 0
#define PIPE_WRITE 1

/**
 * macro: pipe_init
 * Convert a timespec struct value to nanoseconds
 * @param pipe_, pipe_t variable
 */
#define pipe_init(pipe_) {\
    pipe(pipe_); \
}


/**
 * macro: pipe_close
 * close a  (read/write) pipes tream
 * @param pipe_, pipe_t variable
 * @param stream_type, READ or WRITE stream
 */
#define pipe_close(pipe_, stream_type) {\
    close(pipe_[stream_type]); \
}

/**
 * macro: pipe_read
 * read value from a buffer to a pipe stream
 * @param pipe_, pipe_t variable
 * @param buffer
 */
#define pipe_read(pipe_, buffer) {\
    read(pipe_[PIPE_READ], buffer, MAX_BUFFER_LENGTH); \
}

/**
 * macro: pipe_write
 * write value from a pipe stream to a buffer
 * @param pipe_, pipe_t variable
 * @param buffer
 */
#define pipe_write(pipe_, buffer) {\
    write(pipe_[PIPE_WRITE], &buffer, MAX_BUFFER_LENGTH); \
}

#endif