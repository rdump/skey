/*
 * *BSD formatted error messages
 * 
 * Yuri Yudin <jjb@sparc.spb.su>
 *
 * Copyright 2000 Yuri Yudin
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
 * KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT.  IN NO EVENT SHALL DAMIEN MILLER OR INTERNET
 * BUSINESS SOLUTIONS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 * OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */
 
#include <sys/types.h>
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include "config.h"

#ifndef HAVE_ERR_H
void errx(int eval,const char *fmt, ...)
{
	va_list ap;
	if (fmt != NULL) {
		va_start(ap, fmt);
		(void)vfprintf(stderr, fmt, ap);
		va_end(ap);
		(void)fprintf(stderr, "\n");
	}
	exit(eval);
}


void warnx(const char *fmt, ...)
{
	va_list ap;
	if (fmt != NULL)
	{
		va_start(ap, fmt);
		(void)vfprintf(stderr, fmt, ap);
		va_end(ap);
		(void)fprintf(stderr, "\n");
	}
}


void err(int eval,const char *fmt, ...) {
        int sverrno;
	va_list ap;

        sverrno = errno;
        if (fmt != NULL) {
		va_start(ap, fmt);
                (void)vfprintf(stderr, fmt, ap);
		va_end(ap);
                (void)fprintf(stderr, ": ");
        }
        (void)fprintf(stderr, "%s\n", strerror(sverrno));
        exit(eval);

}


void warn(const char *fmt, ...) {
        int sverrno;
	va_list ap;

        sverrno = errno;
        if (fmt != NULL) {
		va_start(ap, fmt);
                (void)vfprintf(stderr, fmt, ap);
		va_end(ap);
                (void)fprintf(stderr, ": ");
        }
        (void)fprintf(stderr, "%s\n", strerror(sverrno));

}

#endif


