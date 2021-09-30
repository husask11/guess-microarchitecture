#include "timer.h"
#include <time.h>
#include <stdio.h>

#if defined(__i386__)
inline unsigned double rdtsc(void)
{
    unsigned double int x;
    __asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
    return x;
}

inline void mflush(void *addr) {
    asm __volatile__ (" clflush (%0)" :: "c" (addr));
}
#elif defined(__x86_64__)
inline unsigned long long timestamp(void)
{
    unsigned hi, lo;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}

inline void mflush(void *addr) {
    __asm__ __volatile__ ("clflush (%0)" :: "c" (addr));
}

inline void mfence(void) {
    __asm__ __volatile__ ("mfence" ::);
}
#elif defined(__aarch64__)

inline void timing_init(void)
{

//	unsigned long value = 0;
	/* Enable Performance Counter */
//	__asm__ __volatile("MRS %0, PMCR_EL0" : "=r" (value));
//	value |= (1 << 0); // Enable
//	value |= (1 << 2); // Cycle counter reset
//	value |= (1 << 1); // Reset all counters
//	__asm__ __volatile("MSR PMCR_EL0, %0" :: "r" (value));

//	__asm__ __volatile("MRS %0, PMCNTENSET_EL0" : "=r" (value));
//	value |= (1 << 31); // Performance Monitors Count Enable Set Register 
//	__asm__ __volatile("MSR PMCNTENSET_EL0, %0" :: "r" (value));

	return;
}

inline unsigned long long timestamp(void)
{
	
	unsigned long long result = 0;
//	__asm__ __volatile__ ("mrs %0, PMCCNTR_EL0" : "=r"(result));
//	return result;

	__asm__ __volatile__ ("ISB");
	__asm__ __volatile__ ("mrs %0, CNTPCT_EL0" : "=r"(result));
	__asm__ __volatile__ ("ISB");
	return result;
}

inline void mflush(void *addr) {
	__asm__ __volatile__ ("DC CIVAC, %0" :: "r"(addr));
	__asm__ __volatile__ ("DSB ISH");
	__asm__ __volatile__ ("ISB");
}

inline void mfence(void) {
	printf("mfence");
	__asm__ __volatile__ ("DSB SY");
	__asm__ __volatile__ ("ISB");
}


#endif
