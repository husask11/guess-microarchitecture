
#if defined(__i386__)
unsigned double rdtsc(void);
#elif defined(__x86_64__)
unsigned long long timestamp(void);
void mfence(void);
#elif defined(__aarch64__)
void timing_init(void);
unsigned long long timestamp(void);
void mfence(void);
#endif
void mflush(void *addr);

