
void remove_char(const char *src, char *dest, char to_remove) {
    while (*src) {
        if (*src != to_remove) {
            *dest = *src;
            dest++;
        }
        src++;
    }
    *dest = '\0'; // Null-terminate the new string
}
