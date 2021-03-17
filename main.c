#include <stdio.h>
#include <string.h>

typedef unsigned char* byte_ptr;

void show_bytes(byte_ptr start, size_t length);

void show_int(int x);

void show_float(float x);

void show_long(long x);

void show_string(char* string);

int main(int argc, char* argv[])
{
    show_string("abcdef");

    return 0;
}

void show_bytes(byte_ptr start, size_t length)
{
    for (int i = 0; i < length; i++)
    {
        fprintf(stdout, "%.2x", *(start + i));

        if (i + 1 != length)
            fprintf(stdout, " ");
    }
    
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_ptr) &x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_ptr) &x, sizeof(float));
}

void show_long(long x)
{
    show_bytes((byte_ptr) &x, sizeof(long));
}

void show_string(char* string)
{
    show_bytes((byte_ptr) string, strlen(string));
}