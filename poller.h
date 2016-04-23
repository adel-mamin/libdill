/*

  Copyright (c) 2016 Martin Sustrik

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"),
  to deal in the Software without restriction, including without limitation
  the rights to use, copy, modify, merge, publish, distribute, sublicense,
  and/or sell copies of the Software, and to permit persons to whom
  the Software is furnished to do so, subject to the following conditions:
  The above copyright notice and this permission notice shall be included
  in all copies or substantial portions of the Software.
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
  IN THE SOFTWARE.

*/

#ifndef DILL_POLLER_INCLUDED
#define DILL_POLLER_INCLUDED

/* Timer clause. */
struct dill_tmcl {
    struct dill_clause cl;
    int64_t deadline;
};

/* Add timer to the list of active clauses. */
void dill_addtimer(struct dill_tmcl *tmcl, int id, int64_t deadline);

/* Wait for external events such as timers or file descriptors. If block is set
   to 0 the function will poll for events and return immediately. If it is set
   to 1 it will block until there's at least one event to process. */
void dill_poller_wait(int block);

/* Deallocates existing polling infrastructure and creates a new one.
   'parent' is a file descriptor that will signal in and/or err if the process
   is supposed to shut down. */
void dill_poller_postfork(int parent);

#endif