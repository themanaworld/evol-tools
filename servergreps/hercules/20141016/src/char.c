# 1 "../../../server-code/src/char/char.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../../../server-code/src/char/char.c"
# 23 "../../../server-code/src/char/char.c"
# 1 "../../../server-code/src/config/core.h" 1
# 90 "../../../server-code/src/config/core.h"
# 1 "../../../server-code/src/config/./renewal.h" 1
# 91 "../../../server-code/src/config/core.h" 2
# 1 "../../../server-code/src/config/./secure.h" 1
# 92 "../../../server-code/src/config/core.h" 2
# 1 "../../../server-code/src/config/./classes/general.h" 1
# 93 "../../../server-code/src/config/core.h" 2




# 1 "../../../server-code/src/config/./const.h" 1
# 62 "../../../server-code/src/config/./const.h"
 typedef short defType;
# 98 "../../../server-code/src/config/core.h" 2
# 24 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/char/char.h" 1
# 24 "../../../server-code/src/char/char.h"
# 1 "../../../server-code/src/common/hercules.h" 1
# 24 "../../../server-code/src/common/hercules.h"
# 1 "../../../server-code/src/common/cbasetypes.h" 1
# 116 "../../../server-code/src/common/cbasetypes.h"
# 1 "/usr/include/inttypes.h" 1 3 4
# 25 "/usr/include/inttypes.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 361 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 410 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 411 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 362 "/usr/include/features.h" 2 3 4
# 385 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 386 "/usr/include/features.h" 2 3 4
# 26 "/usr/include/inttypes.h" 2 3 4

# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdint.h" 1 3 4
# 9 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdint.h" 3 4
# 1 "/usr/include/stdint.h" 1 3 4
# 26 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wchar.h" 1 3 4
# 27 "/usr/include/stdint.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 28 "/usr/include/stdint.h" 2 3 4
# 36 "/usr/include/stdint.h" 3 4

# 36 "/usr/include/stdint.h" 3 4
typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;

typedef long int int64_t;







typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

typedef unsigned int uint32_t;



typedef unsigned long int uint64_t;
# 65 "/usr/include/stdint.h" 3 4
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;

typedef long int int_least64_t;






typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;

typedef unsigned long int uint_least64_t;
# 90 "/usr/include/stdint.h" 3 4
typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
# 103 "/usr/include/stdint.h" 3 4
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
# 119 "/usr/include/stdint.h" 3 4
typedef long int intptr_t;


typedef unsigned long int uintptr_t;
# 134 "/usr/include/stdint.h" 3 4
typedef long int intmax_t;
typedef unsigned long int uintmax_t;
# 10 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdint.h" 2 3 4
# 28 "/usr/include/inttypes.h" 2 3 4






typedef int __gwchar_t;
# 266 "/usr/include/inttypes.h" 3 4





typedef struct
  {
    long int quot;
    long int rem;
  } imaxdiv_t;
# 290 "/usr/include/inttypes.h" 3 4
extern intmax_t imaxabs (intmax_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern imaxdiv_t imaxdiv (intmax_t __numer, intmax_t __denom)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern intmax_t strtoimax (const char *__restrict __nptr,
      char **__restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));


extern uintmax_t strtoumax (const char *__restrict __nptr,
       char ** __restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));


extern intmax_t wcstoimax (const __gwchar_t *__restrict __nptr,
      __gwchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));


extern uintmax_t wcstoumax (const __gwchar_t *__restrict __nptr,
       __gwchar_t ** __restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));
# 432 "/usr/include/inttypes.h" 3 4

# 117 "../../../server-code/src/common/cbasetypes.h" 2

# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/limits.h" 1 3 4
# 34 "/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/limits.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/syslimits.h" 1 3 4






# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/limits.h" 1 3 4
# 168 "/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/limits.h" 3 4
# 1 "/usr/include/limits.h" 1 3 4
# 143 "/usr/include/limits.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 1 3 4
# 160 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/local_lim.h" 1 3 4
# 38 "/usr/include/x86_64-linux-gnu/bits/local_lim.h" 3 4
# 1 "/usr/include/linux/limits.h" 1 3 4
# 39 "/usr/include/x86_64-linux-gnu/bits/local_lim.h" 2 3 4
# 161 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 2 3 4
# 144 "/usr/include/limits.h" 2 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/posix2_lim.h" 1 3 4
# 148 "/usr/include/limits.h" 2 3 4
# 169 "/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/limits.h" 2 3 4
# 8 "/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/syslimits.h" 2 3 4
# 35 "/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/limits.h" 2 3 4
# 119 "../../../server-code/src/common/cbasetypes.h" 2
# 1 "/usr/include/time.h" 1 3 4
# 29 "/usr/include/time.h" 3 4








# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 38 "/usr/include/time.h" 2 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/time.h" 1 3 4
# 42 "/usr/include/time.h" 2 3 4
# 55 "/usr/include/time.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;







typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
# 121 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 1 3 4
# 122 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;
# 56 "/usr/include/time.h" 2 3 4



typedef __clock_t clock_t;



# 73 "/usr/include/time.h" 3 4


typedef __time_t time_t;



# 91 "/usr/include/time.h" 3 4
typedef __clockid_t clockid_t;
# 103 "/usr/include/time.h" 3 4
typedef __timer_t timer_t;
# 120 "/usr/include/time.h" 3 4
struct timespec
  {
    __time_t tv_sec;
    __syscall_slong_t tv_nsec;
  };








struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;


  long int tm_gmtoff;
  const char *tm_zone;




};








struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };


struct sigevent;





typedef __pid_t pid_t;
# 186 "/usr/include/time.h" 3 4



extern clock_t clock (void) __attribute__ ((__nothrow__ , __leaf__));


extern time_t time (time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));


extern double difftime (time_t __time1, time_t __time0)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));





extern size_t strftime (char *__restrict __s, size_t __maxsize,
   const char *__restrict __format,
   const struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));

# 221 "/usr/include/time.h" 3 4
# 1 "/usr/include/xlocale.h" 1 3 4
# 27 "/usr/include/xlocale.h" 3 4
typedef struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
} *__locale_t;


typedef __locale_t locale_t;
# 222 "/usr/include/time.h" 2 3 4

extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     const char *__restrict __format,
     const struct tm *__restrict __tp,
     __locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
# 236 "/usr/include/time.h" 3 4



extern struct tm *gmtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));



extern struct tm *localtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));





extern struct tm *gmtime_r (const time_t *__restrict __timer,
       struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));



extern struct tm *localtime_r (const time_t *__restrict __timer,
          struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));





extern char *asctime (const struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));


extern char *ctime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));







extern char *asctime_r (const struct tm *__restrict __tp,
   char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));


extern char *ctime_r (const time_t *__restrict __timer,
        char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));




extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;




extern char *tzname[2];



extern void tzset (void) __attribute__ ((__nothrow__ , __leaf__));



extern int daylight;
extern long int timezone;





extern int stime (const time_t *__when) __attribute__ ((__nothrow__ , __leaf__));
# 319 "/usr/include/time.h" 3 4
extern time_t timegm (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));


extern time_t timelocal (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));


extern int dysize (int __year) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 334 "/usr/include/time.h" 3 4
extern int nanosleep (const struct timespec *__requested_time,
        struct timespec *__remaining);



extern int clock_getres (clockid_t __clock_id, struct timespec *__res) __attribute__ ((__nothrow__ , __leaf__));


extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) __attribute__ ((__nothrow__ , __leaf__));


extern int clock_settime (clockid_t __clock_id, const struct timespec *__tp)
     __attribute__ ((__nothrow__ , __leaf__));






extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       const struct timespec *__req,
       struct timespec *__rem);


extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) __attribute__ ((__nothrow__ , __leaf__));




extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,
    timer_t *__restrict __timerid) __attribute__ ((__nothrow__ , __leaf__));


extern int timer_delete (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));


extern int timer_settime (timer_t __timerid, int __flags,
     const struct itimerspec *__restrict __value,
     struct itimerspec *__restrict __ovalue) __attribute__ ((__nothrow__ , __leaf__));


extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     __attribute__ ((__nothrow__ , __leaf__));


extern int timer_getoverrun (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));





extern int timespec_get (struct timespec *__ts, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 430 "/usr/include/time.h" 3 4

# 120 "../../../server-code/src/common/cbasetypes.h" 2
# 140 "../../../server-code/src/common/cbasetypes.h"

# 140 "../../../server-code/src/common/cbasetypes.h"
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef int8_t sint8;
typedef int16_t sint16;
typedef int32_t sint32;
typedef int64_t sint64;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
# 196 "../../../server-code/src/common/cbasetypes.h"
typedef long int ppint;
typedef long int ppint8;
typedef long int ppint16;
typedef long int ppint32;

typedef unsigned long int ppuint;
typedef unsigned long int ppuint8;
typedef unsigned long int ppuint16;
typedef unsigned long int ppuint32;





# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 149 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 3 4

# 149 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 3 4
typedef long int ptrdiff_t;
# 328 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 3 4
typedef int wchar_t;
# 426 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 3 4
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
# 211 "../../../server-code/src/common/cbasetypes.h" 2
# 227 "../../../server-code/src/common/cbasetypes.h"

# 227 "../../../server-code/src/common/cbasetypes.h"
typedef intptr_t intptr;
typedef uintptr_t uintptr;







  typedef int64 sysint;
  typedef uint64 usysint;
# 305 "../../../server-code/src/common/cbasetypes.h"
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdbool.h" 1 3 4
# 306 "../../../server-code/src/common/cbasetypes.h" 2
# 395 "../../../server-code/src/common/cbasetypes.h"
# 1 "/usr/include/ctype.h" 1 3 4
# 28 "/usr/include/ctype.h" 3 4

# 39 "/usr/include/ctype.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 36 "/usr/include/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/endian.h" 1 3 4
# 37 "/usr/include/endian.h" 2 3 4
# 60 "/usr/include/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 29 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 2 3 4






# 1 "/usr/include/x86_64-linux-gnu/bits/byteswap-16.h" 1 3 4
# 36 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 2 3 4
# 44 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4

# 44 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
static __inline unsigned int
__bswap_32 (unsigned int __bsx)
{
  return __builtin_bswap32 (__bsx);
}
# 108 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{
  return __builtin_bswap64 (__bsx);
}
# 61 "/usr/include/endian.h" 2 3 4
# 40 "/usr/include/ctype.h" 2 3 4






enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
# 79 "/usr/include/ctype.h" 3 4
extern const unsigned short int **__ctype_b_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern const __int32_t **__ctype_tolower_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern const __int32_t **__ctype_toupper_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 104 "/usr/include/ctype.h" 3 4






extern int isalnum (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isalpha (int) __attribute__ ((__nothrow__ , __leaf__));
extern int iscntrl (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isdigit (int) __attribute__ ((__nothrow__ , __leaf__));
extern int islower (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isgraph (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isprint (int) __attribute__ ((__nothrow__ , __leaf__));
extern int ispunct (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isspace (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isupper (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isxdigit (int) __attribute__ ((__nothrow__ , __leaf__));



extern int tolower (int __c) __attribute__ ((__nothrow__ , __leaf__));


extern int toupper (int __c) __attribute__ ((__nothrow__ , __leaf__));








extern int isblank (int) __attribute__ ((__nothrow__ , __leaf__));


# 150 "/usr/include/ctype.h" 3 4
extern int isascii (int __c) __attribute__ ((__nothrow__ , __leaf__));



extern int toascii (int __c) __attribute__ ((__nothrow__ , __leaf__));



extern int _toupper (int) __attribute__ ((__nothrow__ , __leaf__));
extern int _tolower (int) __attribute__ ((__nothrow__ , __leaf__));
# 271 "/usr/include/ctype.h" 3 4
extern int isalnum_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isalpha_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int iscntrl_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isdigit_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int islower_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isgraph_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isprint_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int ispunct_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isspace_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isupper_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isxdigit_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));

extern int isblank_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));



extern int __tolower_l (int __c, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int tolower_l (int __c, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));


extern int __toupper_l (int __c, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int toupper_l (int __c, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
# 347 "/usr/include/ctype.h" 3 4

# 396 "../../../server-code/src/common/cbasetypes.h" 2
# 417 "../../../server-code/src/common/cbasetypes.h"
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 98 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;
# 418 "../../../server-code/src/common/cbasetypes.h" 2
# 25 "../../../server-code/src/common/hercules.h" 2
# 25 "../../../server-code/src/char/char.h" 2
# 1 "../../../server-code/src/common/core.h" 1
# 25 "../../../server-code/src/common/core.h"
# 1 "../../../server-code/src/common/db.h" 1
# 90 "../../../server-code/src/common/db.h"

# 90 "../../../server-code/src/common/db.h"
enum DBReleaseOption {
 DB_RELEASE_NOTHING = 0x0,
 DB_RELEASE_KEY = 0x1,
 DB_RELEASE_DATA = 0x2,
 DB_RELEASE_BOTH = DB_RELEASE_KEY|DB_RELEASE_DATA,
};
# 117 "../../../server-code/src/common/db.h"
enum DBType {
 DB_INT,
 DB_UINT,
 DB_STRING,
 DB_ISTRING,
 DB_INT64,
 DB_UINT64,
};
# 148 "../../../server-code/src/common/db.h"
enum DBOptions {
 DB_OPT_BASE = 0x00,
 DB_OPT_DUP_KEY = 0x01,
 DB_OPT_RELEASE_KEY = 0x02,
 DB_OPT_RELEASE_DATA = 0x04,
 DB_OPT_RELEASE_BOTH = DB_OPT_RELEASE_KEY|DB_OPT_RELEASE_DATA,
 DB_OPT_ALLOW_NULL_KEY = 0x08,
 DB_OPT_ALLOW_NULL_DATA = 0x10,
};
# 169 "../../../server-code/src/common/db.h"
union DBKey {
 int i;
 unsigned int ui;
 const char *str;
 char *mutstr;
 int64 i64;
 uint64 ui64;
};
# 186 "../../../server-code/src/common/db.h"
enum DBDataType {
 DB_DATA_INT,
 DB_DATA_UINT,
 DB_DATA_PTR,
};
# 201 "../../../server-code/src/common/db.h"
struct DBData {
 enum DBDataType type;
 union {
  int i;
  unsigned int ui;
  void *ptr;
 } u;
};
# 220 "../../../server-code/src/common/db.h"
typedef struct DBData (*DBCreateData)(union DBKey key, va_list args);
# 237 "../../../server-code/src/common/db.h"
typedef int (*DBApply)(union DBKey key, struct DBData *data, va_list args);
# 250 "../../../server-code/src/common/db.h"
typedef int (*DBMatcher)(union DBKey key, struct DBData data, va_list args);
# 264 "../../../server-code/src/common/db.h"
typedef int (*DBComparator)(union DBKey key1, union DBKey key2, unsigned short maxlen);
# 276 "../../../server-code/src/common/db.h"
typedef uint64 (*DBHasher)(union DBKey key, unsigned short maxlen);
# 290 "../../../server-code/src/common/db.h"
typedef void (*DBReleaser)(union DBKey key, struct DBData data, enum DBReleaseOption which);
# 304 "../../../server-code/src/common/db.h"
struct DBIterator {
# 314 "../../../server-code/src/common/db.h"
 struct DBData *(*first)(struct DBIterator *self, union DBKey *out_key);
# 325 "../../../server-code/src/common/db.h"
 struct DBData *(*last)(struct DBIterator *self, union DBKey *out_key);
# 336 "../../../server-code/src/common/db.h"
 struct DBData *(*next)(struct DBIterator *self, union DBKey *out_key);
# 347 "../../../server-code/src/common/db.h"
 struct DBData *(*prev)(struct DBIterator *self, union DBKey *out_key);
# 357 "../../../server-code/src/common/db.h"
 
# 357 "../../../server-code/src/common/db.h" 3 4
_Bool 
# 357 "../../../server-code/src/common/db.h"
     (*exists)(struct DBIterator *self);
# 372 "../../../server-code/src/common/db.h"
 int (*remove)(struct DBIterator *self, struct DBData *out_data);






 void (*destroy)(struct DBIterator *self);

};







struct DBMap {
# 400 "../../../server-code/src/common/db.h"
 struct DBIterator *(*iterator)(struct DBMap *self);
# 409 "../../../server-code/src/common/db.h"
 
# 409 "../../../server-code/src/common/db.h" 3 4
_Bool 
# 409 "../../../server-code/src/common/db.h"
     (*exists)(struct DBMap *self, union DBKey key);
# 418 "../../../server-code/src/common/db.h"
 struct DBData *(*get)(struct DBMap *self, union DBKey key);
# 438 "../../../server-code/src/common/db.h"
 unsigned int (*getall)(struct DBMap *self, struct DBData **buf, unsigned int max, DBMatcher match, ...);
# 456 "../../../server-code/src/common/db.h"
 unsigned int (*vgetall)(struct DBMap *self, struct DBData **buf, unsigned int max, DBMatcher match, va_list args);
# 472 "../../../server-code/src/common/db.h"
 struct DBData *(*ensure)(struct DBMap *self, union DBKey key, DBCreateData create, ...);
# 486 "../../../server-code/src/common/db.h"
 struct DBData *(*vensure)(struct DBMap *self, union DBKey key, DBCreateData create, va_list args);
# 499 "../../../server-code/src/common/db.h"
 int (*put)(struct DBMap *self, union DBKey key, struct DBData data, struct DBData *out_data);
# 511 "../../../server-code/src/common/db.h"
 int (*remove)(struct DBMap *self, union DBKey key, struct DBData *out_data);
# 525 "../../../server-code/src/common/db.h"
 int (*foreach)(struct DBMap *self, DBApply func, ...);
# 537 "../../../server-code/src/common/db.h"
 int (*vforeach)(struct DBMap *self, DBApply func, va_list args);
# 553 "../../../server-code/src/common/db.h"
 int (*clear)(struct DBMap *self, DBApply func, ...);
# 567 "../../../server-code/src/common/db.h"
 int (*vclear)(struct DBMap *self, DBApply func, va_list args);
# 584 "../../../server-code/src/common/db.h"
 int (*destroy)(struct DBMap *self, DBApply func, ...);
# 599 "../../../server-code/src/common/db.h"
 int (*vdestroy)(struct DBMap *self, DBApply func, va_list args);







 unsigned int (*size)(struct DBMap *self);







 enum DBType (*type)(struct DBMap *self);







 enum DBOptions (*options)(struct DBMap *self);

};
# 745 "../../../server-code/src/common/db.h"
struct db_interface {
# 758 "../../../server-code/src/common/db.h"
enum DBOptions (*fix_options) (enum DBType type, enum DBOptions options);
# 768 "../../../server-code/src/common/db.h"
DBComparator (*default_cmp) (enum DBType type);
# 778 "../../../server-code/src/common/db.h"
DBHasher (*default_hash) (enum DBType type);
# 797 "../../../server-code/src/common/db.h"
DBReleaser (*default_release) (enum DBType type, enum DBOptions options);
# 808 "../../../server-code/src/common/db.h"
DBReleaser (*custom_release) (enum DBReleaseOption which);
# 834 "../../../server-code/src/common/db.h"
struct DBMap *(*alloc) (const char *file, const char *func, int line, enum DBType type, enum DBOptions options, unsigned short maxlen);







union DBKey (*i2key) (int key);







union DBKey (*ui2key) (unsigned int key);







union DBKey (*str2key) (const char *key);







union DBKey (*i642key) (int64 key);







union DBKey (*ui642key) (uint64 key);







struct DBData (*i2data) (int data);







struct DBData (*ui2data) (unsigned int data);







struct DBData (*ptr2data) (void *data);
# 907 "../../../server-code/src/common/db.h"
int (*data2i) (struct DBData *data);
# 916 "../../../server-code/src/common/db.h"
unsigned int (*data2ui) (struct DBData *data);
# 925 "../../../server-code/src/common/db.h"
void* (*data2ptr) (struct DBData *data);






void (*init) (void);







void (*final) (void);
};


struct linkdb_node {
 struct linkdb_node *next;
 struct linkdb_node *prev;
 void *key;
 void *data;
};

typedef void (*LinkDBFunc)(void* key, void* data, va_list args);


void linkdb_insert (struct linkdb_node** head, void *key, void* data);
void linkdb_replace (struct linkdb_node** head, void *key, void* data);
void* linkdb_search (struct linkdb_node** head, void *key);
void* linkdb_erase (struct linkdb_node** head, void *key);
void linkdb_final (struct linkdb_node** head);
void linkdb_vforeach(struct linkdb_node** head, LinkDBFunc func, va_list ap);
void linkdb_foreach (struct linkdb_node** head, LinkDBFunc func, ...);

void db_defaults(void);


extern struct db_interface *DB;
# 26 "../../../server-code/src/common/core.h" 2
# 34 "../../../server-code/src/common/core.h"
enum server_types {
 SERVER_TYPE_UNKNOWN = 0x0,
 SERVER_TYPE_LOGIN = 0x1,
 SERVER_TYPE_CHAR = 0x2,
 SERVER_TYPE_MAP = 0x4,
};


enum E_CORE_ST {
 CORE_ST_STOP = 0,
 CORE_ST_RUN,
 CORE_ST_LAST
};


enum cmdline_options {
 CMDLINE_OPT_NORMAL = 0x0,
 CMDLINE_OPT_PARAM = 0x1,
 CMDLINE_OPT_SILENT = 0x2,
 CMDLINE_OPT_PREINIT = 0x4,
};
typedef 
# 55 "../../../server-code/src/common/core.h" 3 4
       _Bool 
# 55 "../../../server-code/src/common/core.h"
            (*CmdlineExecFunc)(const char *name, const char *params);
struct CmdlineArgData {
 unsigned int pluginID;
 unsigned int options;
 char *name;
 char shortname;
 CmdlineExecFunc func;
 char *help;
};

struct cmdline_interface {
 struct { int _max_; int _len_; struct CmdlineArgData *_data_; } args_data;

 void (*init) (void);
 void (*final) (void);
 
# 70 "../../../server-code/src/common/core.h" 3 4
_Bool 
# 70 "../../../server-code/src/common/core.h"
     (*arg_add) (unsigned int pluginID, const char *name, char shortname, CmdlineExecFunc func, const char *help, unsigned int options);
 int (*exec) (int argc, char **argv, unsigned int options);
 
# 72 "../../../server-code/src/common/core.h" 3 4
_Bool 
# 72 "../../../server-code/src/common/core.h"
     (*arg_next_value) (const char *name, int current_arg, int argc);
 const char *(*arg_source) (struct CmdlineArgData *arg);
};

struct core_interface {
 int arg_c;
 char **arg_v;

 int runflag;
 char *server_name;
 enum server_types server_type;



 void (*shutdown_callback)(void);
};






extern void cmdline_args_init_local(void);
extern int do_init(int,char**);
extern void set_server_type(void);
extern void do_abort(void);
extern int do_final(void);







void cmdline_defaults(void);


extern struct core_interface *core;
extern struct cmdline_interface *cmdline;
# 26 "../../../server-code/src/char/char.h" 2

# 1 "../../../server-code/src/common/mmo.h" 1
# 225 "../../../server-code/src/common/mmo.h"
struct hplugin_data_store;

enum item_types {
 IT_HEALING = 0,
 IT_UNKNOWN,
 IT_USABLE,
 IT_ETC,
 IT_WEAPON,
 IT_ARMOR,
 IT_CARD,
 IT_PETEGG,
 IT_PETARMOR,
 IT_UNKNOWN2,
 IT_AMMO,
 IT_DELAYCONSUME,
 IT_CASH = 18,
 IT_MAX
};




enum quest_state {
 Q_INACTIVE,
 Q_ACTIVE,
 Q_COMPLETE,
};


struct quest {
 int quest_id;
 unsigned int time;
 int count[3];
 enum quest_state state;
};

struct item {
 int id;
 short nameid;
 short amount;
 unsigned int equip;
 char identify;
 char refine;
 char attribute;
 short card[4];
 unsigned int expire_time;
 char favorite;
 unsigned char bound;
 uint64 unique_id;
};


enum equip_pos {
 EQP_NONE = 0x000000,
 EQP_HEAD_LOW = 0x000001,
 EQP_HEAD_MID = 0x000200,
 EQP_HEAD_TOP = 0x000100,
 EQP_HAND_R = 0x000002,
 EQP_HAND_L = 0x000020,
 EQP_ARMOR = 0x000010,
 EQP_SHOES = 0x000040,
 EQP_GARMENT = 0x000004,
 EQP_ACC_L = 0x000008,
 EQP_ACC_R = 0x000080,
 EQP_COSTUME_HEAD_TOP = 0x000400,
 EQP_COSTUME_HEAD_MID = 0x000800,
 EQP_COSTUME_HEAD_LOW = 0x001000,
 EQP_COSTUME_GARMENT = 0x002000,

 EQP_AMMO = 0x008000,
 EQP_SHADOW_ARMOR = 0x010000,
 EQP_SHADOW_WEAPON = 0x020000,
 EQP_SHADOW_SHIELD = 0x040000,
 EQP_SHADOW_SHOES = 0x080000,
 EQP_SHADOW_ACC_R = 0x100000,
 EQP_SHADOW_ACC_L = 0x200000,
};

struct point {
 unsigned short map;
 short x,y;
};

enum e_skill_flag
{
 SKILL_FLAG_PERMANENT,
 SKILL_FLAG_TEMPORARY,
 SKILL_FLAG_PLAGIARIZED,
 SKILL_FLAG_UNUSED,
 SKILL_FLAG_PERM_GRANTED,


 SKILL_FLAG_REPLACED_LV_0,
};

enum e_mmo_charstatus_opt {
 OPT_NONE = 0x0,
 OPT_SHOW_EQUIP = 0x1,
 OPT_ALLOW_PARTY = 0x2,
};

enum e_item_bound_type {
 IBT_NONE = 0x0,
 IBT_MIN = 0x1,
 IBT_ACCOUNT = 0x1,
 IBT_GUILD = 0x2,
 IBT_PARTY = 0x3,
 IBT_CHARACTER = 0x4,
 IBT_MAX = 0x4,
};

enum {
 OPTION_NOTHING = 0x00000000,
 OPTION_SIGHT = 0x00000001,
 OPTION_HIDE = 0x00000002,
 OPTION_CLOAK = 0x00000004,
 OPTION_FALCON = 0x00000010,
 OPTION_RIDING = 0x00000020,
 OPTION_INVISIBLE = 0x00000040,
 OPTION_ORCISH = 0x00000800,
 OPTION_WEDDING = 0x00001000,
 OPTION_RUWACH = 0x00002000,
 OPTION_CHASEWALK = 0x00004000,
 OPTION_FLYING = 0x00008000,
 OPTION_XMAS = 0x00010000,
 OPTION_TRANSFORM = 0x00020000,
 OPTION_SUMMER = 0x00040000,
 OPTION_DRAGON1 = 0x00080000,
 OPTION_WUG = 0x00100000,
 OPTION_WUGRIDER = 0x00200000,
 OPTION_MADOGEAR = 0x00400000,
 OPTION_DRAGON2 = 0x00800000,
 OPTION_DRAGON3 = 0x01000000,
 OPTION_DRAGON4 = 0x02000000,
 OPTION_DRAGON5 = 0x04000000,
 OPTION_HANBOK = 0x08000000,
 OPTION_OKTOBERFEST = 0x10000000,
# 372 "../../../server-code/src/common/mmo.h"
 OPTION_DRAGON = OPTION_DRAGON1|OPTION_DRAGON2|OPTION_DRAGON3|OPTION_DRAGON4|OPTION_DRAGON5,
 OPTION_COSTUME = OPTION_WEDDING|OPTION_XMAS|OPTION_SUMMER|OPTION_HANBOK|OPTION_OKTOBERFEST,
};

struct s_skill {
 unsigned short id;
 unsigned char lv;
 unsigned char flag;
};

struct script_reg_state {
 unsigned int type : 1;
 unsigned int update : 1;
};

struct script_reg_num {
 struct script_reg_state flag;
 int value;
};

struct script_reg_str {
 struct script_reg_state flag;
 char *value;
};


struct status_change_data {
 unsigned short type;
 int val1, val2, val3, val4;
 int tick;
};

struct storage_data {
 int storage_amount;
 struct item items[600];
};

struct guild_storage {
 int dirty;
 int guild_id;
 short storage_status;
 short storage_amount;
 struct item items[600];
 unsigned short lock;
};

struct s_pet {
 int account_id;
 int char_id;
 int pet_id;
 short class_;
 short level;
 short egg_id;
 short equip;
 short intimate;
 short hungry;
 char name[(23 + 1)];
 char rename_flag;
 char incubate;
};

struct s_homunculus {
 char name[(23 + 1)];
 int hom_id;
 int char_id;
 short class_;
 short prev_class;
 int hp,max_hp,sp,max_sp;
 unsigned int intimacy;
 short hunger;
 struct s_skill hskill[43];
 short skillpts;
 short level;
 unsigned int exp;
 short rename_flag;
 short vaporize;
 int str;
 int agi;
 int vit;
 int int_;
 int dex;
 int luk;

 int str_value;
 int agi_value;
 int vit_value;
 int int_value;
 int dex_value;
 int luk_value;

 int8 spiritball;
};

struct s_mercenary {
 int mercenary_id;
 int char_id;
 short class_;
 int hp, sp;
 unsigned int kill_count;
 unsigned int life_time;
};

struct s_elemental {
 int elemental_id;
 int char_id;
 short class_;
 uint32 mode;
 int hp, sp, max_hp, max_sp, matk, atk, atk2;
 short hit, flee, amotion, def, mdef;
 int life_time;
};

struct s_friend {
 int account_id;
 int char_id;
 char name[(23 + 1)];
};

struct hotkey {

 unsigned int id;
 unsigned short lv;
 unsigned char type;



};

struct mmo_charstatus {
 int char_id;
 int account_id;
 int partner_id;
 int father;
 int mother;
 int child;

 unsigned int base_exp,job_exp;
 int zeny;
 int bank_vault;

 short class_;
 unsigned int status_point,skill_point;
 int hp,max_hp,sp,max_sp;
 unsigned int option;
 short manner;
 unsigned char karma;
 short hair,hair_color,clothes_color,body;
 int party_id,guild_id,pet_id,hom_id,mer_id,ele_id;
 int fame;


 int arch_faith, arch_calls;
 int spear_faith, spear_calls;
 int sword_faith, sword_calls;

 short weapon;
 short shield;
 short head_top,head_mid,head_bottom;
 short robe;

 char name[(23 + 1)];
 unsigned int base_level,job_level;
 short str,agi,vit,int_,dex,luk;
 unsigned char slot,sex;

 uint32 mapip;
 uint16 mapport;

 struct point last_point,save_point,memo_point[3];
 struct item inventory[100],cart[100];
 struct storage_data storage;
 struct s_skill skill[1478];

 struct s_friend friends[40];

 struct hotkey hotkeys[38];

 
# 549 "../../../server-code/src/common/mmo.h" 3 4
_Bool 
# 549 "../../../server-code/src/common/mmo.h"
     show_equip, allow_party;
 unsigned short rename;
 unsigned short slotchange;

 time_t delete_date;


 unsigned short mod_exp,mod_drop,mod_death;

 unsigned char font;

 uint32 uniqueitem_counter;

 unsigned char hotkey_rowshift;
};

typedef enum mail_status {
 MAIL_NEW,
 MAIL_UNREAD,
 MAIL_READ,
} mail_status;

struct mail_message {
 int id;
 int send_id;
 char send_name[(23 + 1)];
 int dest_id;
 char dest_name[(23 + 1)];
 char title[40];
 char body[200];

 mail_status status;
 time_t timestamp;

 int zeny;
 struct item item;
};

struct mail_data {
 short amount;
 
# 589 "../../../server-code/src/common/mmo.h" 3 4
_Bool 
# 589 "../../../server-code/src/common/mmo.h"
     full;
 short unchecked, unread;
 struct mail_message msg[30];
};

struct auction_data {
 unsigned int auction_id;
 int seller_id;
 char seller_name[(23 + 1)];
 int buyer_id;
 char buyer_name[(23 + 1)];

 struct item item;

 char item_name[50];
 short type;

 unsigned short hours;
 int price, buynow;
 time_t timestamp;
 int auction_end_timer;
};

struct party_member {
 int account_id;
 int char_id;
 char name[(23 + 1)];
 unsigned short class_;
 unsigned short map;
 unsigned short lv;
 unsigned leader : 1,
          online : 1;
};

struct party {
 int party_id;
 char name[(23 + 1)];
 unsigned char count;
 unsigned exp : 1,
    item : 2;
 struct party_member member[12];
};

struct map_session_data;
struct guild_member {
 int account_id, char_id;
 short hair,hair_color,gender,class_,lv;
 uint64 exp;
 int exp_payper;
 short online,position;
 char name[(23 + 1)];
 struct map_session_data *sd;
 unsigned char modified;
};

struct guild_position {
 char name[(23 + 1)];
 int mode;
 int exp_mode;
 unsigned char modified;
};

struct guild_alliance {
 int opposition;
 int guild_id;
 char name[(23 + 1)];
};

struct guild_expulsion {
 char name[(23 + 1)];
 char mes[40];
 int account_id;
};

struct guild_skill {
 int id,lv;
};

struct channel_data;
struct guild {
 int guild_id;
 short guild_lv, connect_member, max_member, average_lv;
 uint64 exp;
 unsigned int next_exp;
 int skill_point;
 char name[(23 + 1)],master[(23 + 1)];
 struct guild_member member[(16 +10*6)];
 struct guild_position position[20];
 char mes1[60],mes2[120];
 int emblem_len,emblem_id;
 char emblem_data[2048];
 struct guild_alliance alliance[16];
 struct guild_expulsion expulsion[32];
 struct guild_skill skill[15];


 unsigned short save_flag;

 short *instance;
 unsigned short instances;

 struct channel_data *channel;
 struct hplugin_data_store *hdata;
};

struct guild_castle {
 int castle_id;
 int mapindex;
 char castle_name[(23 + 1)];
 char castle_event[(23 + 1)];
 int guild_id;
 int economy;
 int defense;
 int triggerE;
 int triggerD;
 int nextTime;
 int payTime;
 int createTime;
 int visibleC;
 struct {
  unsigned visible : 1;
  int id;
 } guardian[8];
 int* temp_guardians;
 int temp_guardians_max;
};

struct fame_list {
 int id;
 int fame;
 char name[(23 + 1)];
};

enum fame_list_type {
 RANKTYPE_BLACKSMITH = 0,
 RANKTYPE_ALCHEMIST = 1,
 RANKTYPE_TAEKWON = 2,
 RANKTYPE_PK = 3,
};






enum guild_basic_info {
 GBI_EXP = 1,
 GBI_GUILDLV,
 GBI_SKILLPOINT,





 GBI_SKILLLV,
};

enum {
 GMI_POSITION = 0,
 GMI_EXP,
 GMI_HAIR,
 GMI_HAIR_COLOR,
 GMI_GENDER,
 GMI_CLASS,
 GMI_LEVEL,
};

enum guild_permission {
 GPERM_INVITE = 0x01,
 GPERM_EXPEL = 0x10,
 GPERM_ALL = GPERM_INVITE|GPERM_EXPEL,
 GPERM_MASK = GPERM_ALL,
};

enum {
 GD_SKILLBASE=10000,
 GD_APPROVAL=10000,
 GD_KAFRACONTRACT=10001,
 GD_GUARDRESEARCH=10002,
 GD_GUARDUP=10003,
 GD_EXTENSION=10004,
 GD_GLORYGUILD=10005,
 GD_LEADERSHIP=10006,
 GD_GLORYWOUNDS=10007,
 GD_SOULCOLD=10008,
 GD_HAWKEYES=10009,
 GD_BATTLEORDER=10010,
 GD_REGENERATION=10011,
 GD_RESTORE=10012,
 GD_EMERGENCYCALL=10013,
 GD_DEVELOPMENT=10014,
 GD_MAX,
};


enum {
 JOB_NOVICE,
 JOB_SWORDMAN,
 JOB_MAGE,
 JOB_ARCHER,
 JOB_ACOLYTE,
 JOB_MERCHANT,
 JOB_THIEF,
 JOB_KNIGHT,
 JOB_PRIEST,
 JOB_WIZARD,
 JOB_BLACKSMITH,
 JOB_HUNTER,
 JOB_ASSASSIN,
 JOB_KNIGHT2,
 JOB_CRUSADER,
 JOB_MONK,
 JOB_SAGE,
 JOB_ROGUE,
 JOB_ALCHEMIST,
 JOB_BARD,
 JOB_DANCER,
 JOB_CRUSADER2,
 JOB_WEDDING,
 JOB_SUPER_NOVICE,
 JOB_GUNSLINGER,
 JOB_NINJA,
 JOB_XMAS,
 JOB_SUMMER,
 JOB_MAX_BASIC,

 JOB_NOVICE_HIGH = 4001,
 JOB_SWORDMAN_HIGH,
 JOB_MAGE_HIGH,
 JOB_ARCHER_HIGH,
 JOB_ACOLYTE_HIGH,
 JOB_MERCHANT_HIGH,
 JOB_THIEF_HIGH,
 JOB_LORD_KNIGHT,
 JOB_HIGH_PRIEST,
 JOB_HIGH_WIZARD,
 JOB_WHITESMITH,
 JOB_SNIPER,
 JOB_ASSASSIN_CROSS,
 JOB_LORD_KNIGHT2,
 JOB_PALADIN,
 JOB_CHAMPION,
 JOB_PROFESSOR,
 JOB_STALKER,
 JOB_CREATOR,
 JOB_CLOWN,
 JOB_GYPSY,
 JOB_PALADIN2,

 JOB_BABY,
 JOB_BABY_SWORDMAN,
 JOB_BABY_MAGE,
 JOB_BABY_ARCHER,
 JOB_BABY_ACOLYTE,
 JOB_BABY_MERCHANT,
 JOB_BABY_THIEF,
 JOB_BABY_KNIGHT,
 JOB_BABY_PRIEST,
 JOB_BABY_WIZARD,
 JOB_BABY_BLACKSMITH,
 JOB_BABY_HUNTER,
 JOB_BABY_ASSASSIN,
 JOB_BABY_KNIGHT2,
 JOB_BABY_CRUSADER,
 JOB_BABY_MONK,
 JOB_BABY_SAGE,
 JOB_BABY_ROGUE,
 JOB_BABY_ALCHEMIST,
 JOB_BABY_BARD,
 JOB_BABY_DANCER,
 JOB_BABY_CRUSADER2,
 JOB_SUPER_BABY,

 JOB_TAEKWON,
 JOB_STAR_GLADIATOR,
 JOB_STAR_GLADIATOR2,
 JOB_SOUL_LINKER,

 JOB_GANGSI,
 JOB_DEATH_KNIGHT,
 JOB_DARK_COLLECTOR,

 JOB_RUNE_KNIGHT = 4054,
 JOB_WARLOCK,
 JOB_RANGER,
 JOB_ARCH_BISHOP,
 JOB_MECHANIC,
 JOB_GUILLOTINE_CROSS,

 JOB_RUNE_KNIGHT_T,
 JOB_WARLOCK_T,
 JOB_RANGER_T,
 JOB_ARCH_BISHOP_T,
 JOB_MECHANIC_T,
 JOB_GUILLOTINE_CROSS_T,

 JOB_ROYAL_GUARD,
 JOB_SORCERER,
 JOB_MINSTREL,
 JOB_WANDERER,
 JOB_SURA,
 JOB_GENETIC,
 JOB_SHADOW_CHASER,

 JOB_ROYAL_GUARD_T,
 JOB_SORCERER_T,
 JOB_MINSTREL_T,
 JOB_WANDERER_T,
 JOB_SURA_T,
 JOB_GENETIC_T,
 JOB_SHADOW_CHASER_T,

 JOB_RUNE_KNIGHT2,
 JOB_RUNE_KNIGHT_T2,
 JOB_ROYAL_GUARD2,
 JOB_ROYAL_GUARD_T2,
 JOB_RANGER2,
 JOB_RANGER_T2,
 JOB_MECHANIC2,
 JOB_MECHANIC_T2,

 JOB_BABY_RUNE = 4096,
 JOB_BABY_WARLOCK,
 JOB_BABY_RANGER,
 JOB_BABY_BISHOP,
 JOB_BABY_MECHANIC,
 JOB_BABY_CROSS,

 JOB_BABY_GUARD,
 JOB_BABY_SORCERER,
 JOB_BABY_MINSTREL,
 JOB_BABY_WANDERER,
 JOB_BABY_SURA,
 JOB_BABY_GENETIC,
 JOB_BABY_CHASER,

 JOB_BABY_RUNE2,
 JOB_BABY_GUARD2,
 JOB_BABY_RANGER2,
 JOB_BABY_MECHANIC2,

 JOB_SUPER_NOVICE_E = 4190,
 JOB_SUPER_BABY_E,

 JOB_KAGEROU = 4211,
 JOB_OBORO,
 JOB_REBELLION = 4215,

 JOB_MAX,
};




enum {
 SEX_FEMALE = 0,
 SEX_MALE,
 SEX_SERVER
};

enum weapon_type {
 W_FIST,
 W_DAGGER,
 W_1HSWORD,
 W_2HSWORD,
 W_1HSPEAR,
 W_2HSPEAR,
 W_1HAXE,
 W_2HAXE,
 W_MACE,
 W_2HMACE,
 W_STAFF,
 W_BOW,
 W_KNUCKLE,
 W_MUSICAL,
 W_WHIP,
 W_BOOK,
 W_KATAR,
 W_REVOLVER,
 W_RIFLE,
 W_GATLING,
 W_SHOTGUN,
 W_GRENADE,
 W_HUUMA,
 W_2HSTAFF,
 MAX_SINGLE_WEAPON_TYPE,

 W_DOUBLE_DD,
 W_DOUBLE_SS,
 W_DOUBLE_AA,
 W_DOUBLE_DS,
 W_DOUBLE_DA,
 W_DOUBLE_SA,
 MAX_WEAPON_TYPE,
};

enum ammo_type {
 A_ARROW = 1,
 A_DAGGER,
 A_BULLET,
 A_SHELL,
 A_GRENADE,
 A_SHURIKEN,
 A_KUNAI,
 A_CANNONBALL,
 A_THROWWEAPON,
};

enum e_char_server_type {
 CST_NORMAL = 0,
 CST_MAINTENANCE = 1,
 CST_OVER18 = 2,
 CST_PAYING = 3,
 CST_F2P = 4,
};

enum e_pc_reg_loading {
 PRL_NONE = 0x0,
 PRL_CHAR = 0x1,
 PRL_ACCL = 0x2,
 PRL_ACCG = 0x4,
 PRL_ALL = 0xFF,
};




enum zh_char_ask_name_type {
 CHAR_ASK_NAME_BLOCK = 1,
 CHAR_ASK_NAME_BAN = 2,
 CHAR_ASK_NAME_UNBLOCK = 3,
 CHAR_ASK_NAME_UNBAN = 4,
 CHAR_ASK_NAME_CHANGESEX = 5,
 CHAR_ASK_NAME_CHARBAN = 6,
 CHAR_ASK_NAME_CHARUNBAN = 7,
 CHAR_ASK_NAME_CHANGECHARSEX = 8,
};




enum hz_char_ask_name_answer {
 CHAR_ASK_NAME_ANS_DONE = 0,
 CHAR_ASK_NAME_ANS_NOTFOUND = 1,
 CHAR_ASK_NAME_ANS_GMLOW = 2,
 CHAR_ASK_NAME_ANS_OFFLINE = 3,
};
# 28 "../../../server-code/src/char/char.h" 2

enum E_CHARSERVER_ST {
 CHARSERVER_ST_RUNNING = CORE_ST_LAST,
 CHARSERVER_ST_SHUTDOWN,
 CHARSERVER_ST_LAST
};

struct char_session_data {
 
# 36 "../../../server-code/src/char/char.h" 3 4
_Bool 
# 36 "../../../server-code/src/char/char.h"
     auth;
 int account_id, login_id1, login_id2, sex;
 int found_char[9];
 time_t unban_time[9];
 char email[40];
 time_t expiration_time;
 int group_id;
 uint8 char_slots;
 uint32 version;
 uint8 clienttype;
 char pincode[4+1];
 uint32 pincode_seed;
 uint16 pincode_try;
 uint32 pincode_change;
 char new_name[(23 + 1)];
 char birthdate[10+1];
};

struct online_char_data {
 int account_id;
 int char_id;
 int fd;
 int waiting_disconnect;
 short server;
 int pincode_enable;
};

struct mmo_map_server {
 int fd;
 uint32 ip;
 uint16 port;
 int users;
 struct { int _max_; int _len_; uint16 *_data_; } maps;
};





enum inventory_table_type {
 TABLE_INVENTORY,
 TABLE_CART,
 TABLE_STORAGE,
 TABLE_GUILD_STORAGE,
};

struct char_auth_node {
 int account_id;
 int char_id;
 uint32 login_id1;
 uint32 login_id2;
 uint32 ip;
 int sex;
 time_t expiration_time;
 int group_id;
 unsigned changing_mapservers : 1;
};




struct char_interface {
 struct mmo_map_server server[2];
 int login_fd;
 int char_fd;
 struct DBMap *online_char_db;
 struct DBMap *char_db_;
 char userid[(23 + 1)];
 char passwd[(23 + 1)];
 char server_name[20];
 uint32 ip;
 uint16 port;
 int server_type;
 int new_display;

 char *CHAR_CONF_NAME;
 char *NET_CONF_NAME;
 char *SQL_CONF_NAME;
 char *INTER_CONF_NAME;

 int (*waiting_disconnect) (int tid, int64 tick, int id, intptr_t data);
 int (*delete_char_sql) (int char_id);
 struct DBData (*create_online_char_data) (union DBKey key, va_list args);
 void (*set_account_online) (int account_id);
 void (*set_account_offline) (int account_id);
 void (*set_char_charselect) (int account_id);
 void (*set_char_online) (int map_id, int char_id, int account_id);
 void (*set_char_offline) (int char_id, int account_id);
 int (*db_setoffline) (union DBKey key, struct DBData *data, va_list ap);
 int (*db_kickoffline) (union DBKey key, struct DBData *data, va_list ap);
 void (*set_login_all_offline) (void);
 void (*set_all_offline) (int id);
 void (*set_all_offline_sql) (void);
 struct DBData (*create_charstatus) (union DBKey key, va_list args);
 int (*mmo_char_tosql) (int char_id, struct mmo_charstatus* p);
 int (*memitemdata_to_sql) (const struct item items[], int max, int id, int tableswitch);
 int (*mmo_gender) (const struct char_session_data *sd, const struct mmo_charstatus *p, char sex);
 int (*mmo_chars_fromsql) (struct char_session_data* sd, uint8* buf);
 int (*mmo_char_fromsql) (int char_id, struct mmo_charstatus* p, 
# 134 "../../../server-code/src/char/char.h" 3 4
                                                                _Bool 
# 134 "../../../server-code/src/char/char.h"
                                                                     load_everything);
 int (*mmo_char_sql_init) (void);
 
# 136 "../../../server-code/src/char/char.h" 3 4
_Bool 
# 136 "../../../server-code/src/char/char.h"
     (*char_slotchange) (struct char_session_data *sd, int fd, unsigned short from, unsigned short to);
 int (*rename_char_sql) (struct char_session_data *sd, int char_id);
 int (*check_char_name) (char * name, char * esc_name);
 int (*make_new_char_sql) (struct char_session_data *sd, const char *name_, int str, int agi, int vit, int int_, int dex, int luk, int slot, int hair_color, int hair_style);
 int (*divorce_char_sql) (int partner_id1, int partner_id2);
 int (*count_users) (void);
 int (*mmo_char_tobuf) (uint8* buffer, struct mmo_charstatus* p);
 void (*mmo_char_send099d) (int fd, struct char_session_data *sd);
 void (*mmo_char_send_ban_list) (int fd, struct char_session_data *sd);
 void (*mmo_char_send_slots_info) (int fd, struct char_session_data* sd);
 int (*mmo_char_send_characters) (int fd, struct char_session_data* sd);
 int (*char_married) (int pl1, int pl2);
 int (*char_child) (int parent_id, int child_id);
 int (*char_family) (int cid1, int cid2, int cid3);
 void (*disconnect_player) (int account_id);
 void (*authfail_fd) (int fd, int type);
 void (*request_account_data) (int account_id);
 void (*auth_ok) (int fd, struct char_session_data *sd);
 void (*ping_login_server) (int fd);
 int (*parse_fromlogin_connection_state) (int fd);
 void (*auth_error) (int fd, unsigned char flag);
 void (*parse_fromlogin_auth_state) (int fd);
 void (*parse_fromlogin_account_data) (int fd);
 void (*parse_fromlogin_login_pong) (int fd);
 void (*changesex) (int account_id, int sex);
 int (*parse_fromlogin_changesex_reply) (int fd);
 void (*parse_fromlogin_account_reg2) (int fd);
 void (*parse_fromlogin_ban) (int fd);
 void (*parse_fromlogin_kick) (int fd);
 void (*update_ip) (int fd);
 void (*parse_fromlogin_update_ip) (int fd);
 void (*parse_fromlogin_accinfo2_failed) (int fd);
 void (*parse_fromlogin_accinfo2_ok) (int fd);
 int (*parse_fromlogin) (int fd);
 int (*request_accreg2) (int account_id, int char_id);
 void (*global_accreg_to_login_start) (int account_id, int char_id);
 void (*global_accreg_to_login_send) (void);
 void (*global_accreg_to_login_add) (const char *key, unsigned int index, intptr_t val, 
# 173 "../../../server-code/src/char/char.h" 3 4
                                                                                       _Bool 
# 173 "../../../server-code/src/char/char.h"
                                                                                            is_string);
 void (*read_fame_list) (void);
 int (*send_fame_list) (int fd);
 void (*update_fame_list) (int type, int index, int fame);
 int (*loadName) (int char_id, char* name);
 void (*parse_frommap_datasync) (int fd);
 void (*parse_frommap_skillid2idx) (int fd);
 void (*map_received_ok) (int fd);
 void (*send_maps) (int fd, int id, int j);
 void (*parse_frommap_map_names) (int fd, int id);
 void (*send_scdata) (int fd, int aid, int cid);
 void (*parse_frommap_request_scdata) (int fd);
 void (*parse_frommap_set_users_count) (int fd, int id);
 void (*parse_frommap_set_users) (int fd, int id);
 void (*save_character_ack) (int fd, int aid, int cid);
 void (*parse_frommap_save_character) (int fd, int id);
 void (*select_ack) (int fd, int account_id, uint8 flag);
 void (*parse_frommap_char_select_req) (int fd);
 void (*change_map_server_ack) (int fd, const uint8 *data, 
# 191 "../../../server-code/src/char/char.h" 3 4
                                                          _Bool 
# 191 "../../../server-code/src/char/char.h"
                                                               ok);
 void (*parse_frommap_change_map_server) (int fd);
 void (*parse_frommap_remove_friend) (int fd);
 void (*char_name_ack) (int fd, int char_id);
 void (*parse_frommap_char_name_request) (int fd);
 void (*parse_frommap_change_email) (int fd);
 void (*ban) (int account_id, int char_id, time_t *unban_time, short year, short month, short day, short hour, short minute, short second);
 void (*unban) (int char_id, int *result);
 void (*ask_name_ack) (int fd, int acc, const char* name, int type, int result);
 int (*changecharsex) (int char_id, int sex);
 void (*parse_frommap_change_account) (int fd);
 void (*parse_frommap_fame_list) (int fd);
 void (*parse_frommap_divorce_char) (int fd);
 void (*parse_frommap_ragsrvinfo) (int fd);
 void (*parse_frommap_set_char_offline) (int fd);
 void (*parse_frommap_set_all_offline) (int fd, int id);
 void (*parse_frommap_set_char_online) (int fd, int id);
 void (*parse_frommap_build_fame_list) (int fd);
 void (*parse_frommap_save_status_change_data) (int fd);
 void (*send_pong) (int fd);
 void (*parse_frommap_ping) (int fd);
 void (*map_auth_ok) (int fd, int account_id, struct char_auth_node* node, struct mmo_charstatus* cd);
 void (*map_auth_failed) (int fd, int account_id, int char_id, int login_id1, char sex, uint32 ip);
 void (*parse_frommap_auth_request) (int fd, int id);
 void (*parse_frommap_update_ip) (int fd, int id);
 void (*parse_frommap_request_stats_report) (int fd);
 void (*parse_frommap_scdata_update) (int fd);
 void (*parse_frommap_scdata_delete) (int fd);
 int (*parse_frommap) (int fd);
 int (*search_mapserver) (unsigned short map, uint32 ip, uint16 port);
 int (*mapif_init) (int fd);
 uint32 (*lan_subnet_check) (uint32 ip);
 void (*delete2_ack) (int fd, int char_id, uint32 result, time_t delete_date);
 void (*delete2_accept_actual_ack) (int fd, int char_id, uint32 result);
 void (*delete2_accept_ack) (int fd, int char_id, uint32 result);
 void (*delete2_cancel_ack) (int fd, int char_id, uint32 result);
 void (*delete2_req) (int fd, struct char_session_data* sd);
 void (*delete2_accept) (int fd, struct char_session_data* sd);
 void (*delete2_cancel) (int fd, struct char_session_data* sd);
 void (*send_account_id) (int fd, int account_id);
 void (*parse_char_connect) (int fd, struct char_session_data* sd, uint32 ipl);
 void (*send_map_info) (int fd, int i, uint32 subnet_map_ip, struct mmo_charstatus *cd);
 void (*send_wait_char_server) (int fd);
 int (*search_default_maps_mapserver) (struct mmo_charstatus *cd);
 void (*parse_char_select) (int fd, struct char_session_data* sd, uint32 ipl);
 void (*creation_failed) (int fd, int result);
 void (*creation_ok) (int fd, struct mmo_charstatus *char_dat);
 void (*parse_char_create_new_char) (int fd, struct char_session_data* sd);
 void (*delete_char_failed) (int fd, int flag);
 void (*delete_char_ok) (int fd);
 void (*parse_char_delete_char) (int fd, struct char_session_data* sd, unsigned short cmd);
 void (*parse_char_ping) (int fd);
 void (*allow_rename) (int fd, int flag);
 void (*parse_char_rename_char) (int fd, struct char_session_data* sd);
 void (*parse_char_rename_char2) (int fd, struct char_session_data* sd);
 void (*rename_char_ack) (int fd, int flag);
 void (*parse_char_rename_char_confirm) (int fd, struct char_session_data* sd);
 void (*captcha_notsupported) (int fd);
 void (*parse_char_request_captcha) (int fd);
 void (*parse_char_check_captcha) (int fd);
 void (*parse_char_delete2_req) (int fd, struct char_session_data* sd);
 void (*parse_char_delete2_accept) (int fd, struct char_session_data* sd);
 void (*parse_char_delete2_cancel) (int fd, struct char_session_data* sd);
 void (*login_map_server_ack) (int fd, uint8 flag);
 void (*parse_char_login_map_server) (int fd, uint32 ipl);
 void (*parse_char_pincode_check) (int fd, struct char_session_data* sd);
 void (*parse_char_pincode_window) (int fd, struct char_session_data* sd);
 void (*parse_char_pincode_change) (int fd, struct char_session_data* sd);
 void (*parse_char_pincode_first_pin) (int fd, struct char_session_data* sd);
 void (*parse_char_request_chars) (int fd, struct char_session_data* sd);
 void (*change_character_slot_ack) (int fd, 
# 261 "../../../server-code/src/char/char.h" 3 4
                                           _Bool 
# 261 "../../../server-code/src/char/char.h"
                                                ret);
 void (*parse_char_move_character) (int fd, struct char_session_data* sd);
 int (*parse_char_unknown_packet) (int fd, uint32 ipl);
 int (*parse_char) (int fd);
 int (*broadcast_user_count) (int tid, int64 tick, int id, intptr_t data);
 int (*send_accounts_tologin_sub) (union DBKey key, struct DBData *data, va_list ap);
 int (*send_accounts_tologin) (int tid, int64 tick, int id, intptr_t data);
 int (*check_connect_login_server) (int tid, int64 tick, int id, intptr_t data);
 int (*online_data_cleanup_sub) (union DBKey key, struct DBData *data, va_list ap);
 int (*online_data_cleanup) (int tid, int64 tick, int id, intptr_t data);
 void (*sql_config_read) (const char* cfgName);
 void (*config_dispatch) (char *w1, char *w2);
 int (*config_read) (const char* cfgName);
};


extern int char_name_option;
extern char char_name_letters[];
extern 
# 279 "../../../server-code/src/char/char.h" 3 4
      _Bool 
# 279 "../../../server-code/src/char/char.h"
           char_gm_read;
extern int autosave_interval;
extern int save_log;
extern char db_path[];
extern char char_db[256];
extern char scdata_db[256];
extern char cart_db[256];
extern char inventory_db[256];
extern char charlog_db[256];
extern char storage_db[256];
extern char interlog_db[256];
extern char skill_db[256];
extern char memo_db[256];
extern char guild_db[256];
extern char guild_alliance_db[256];
extern char guild_castle_db[256];
extern char guild_expulsion_db[256];
extern char guild_member_db[256];
extern char guild_position_db[256];
extern char guild_skill_db[256];
extern char guild_storage_db[256];
extern char party_db[256];
extern char pet_db[256];
extern char mail_db[256];
extern char auction_db[256];
extern char quest_db[256];
extern char homunculus_db[256];
extern char skill_homunculus_db[256];
extern char mercenary_db[256];
extern char mercenary_owner_db[256];
extern char ragsrvinfo_db[256];
extern char elemental_db[256];
extern char acc_reg_num_db[32];
extern char acc_reg_str_db[32];
extern char char_reg_str_db[32];
extern char char_reg_num_db[32];

extern int guild_exp_rate;
extern int log_inter;

void char_load_defaults(void);
void char_defaults(void);


extern struct char_interface *chr;
# 25 "../../../server-code/src/char/char.c" 2

# 1 "../../../server-code/src/char/HPMchar.h" 1
# 28 "../../../server-code/src/char/HPMchar.h"
# 1 "../../../server-code/src/common/HPM.h" 1
# 29 "../../../server-code/src/common/HPM.h"
# 1 "../../../server-code/src/common/HPMi.h" 1
# 24 "../../../server-code/src/common/HPMi.h"
# 1 "../../../server-code/src/common/console.h" 1
# 25 "../../../server-code/src/common/console.h"
# 1 "../../../server-code/src/common/mutex.h" 1
# 26 "../../../server-code/src/common/mutex.h"
typedef struct ramutex ramutex;
typedef struct racond racond;







ramutex *ramutex_create(void);






void ramutex_destroy(ramutex *m);






void ramutex_lock(ramutex *m);
# 58 "../../../server-code/src/common/mutex.h"

# 58 "../../../server-code/src/common/mutex.h" 3 4
_Bool 
# 58 "../../../server-code/src/common/mutex.h"
    ramutex_trylock(ramutex *m);






void ramutex_unlock(ramutex *m);







racond *racond_create(void);






void racond_destroy(racond *c);
# 89 "../../../server-code/src/common/mutex.h"
void racond_wait(racond *c, ramutex *m, sysint timeout_ticks);
# 99 "../../../server-code/src/common/mutex.h"
void racond_signal(racond *c);
# 108 "../../../server-code/src/common/mutex.h"
void racond_broadcast(racond *c);
# 26 "../../../server-code/src/common/console.h" 2
# 1 "../../../server-code/src/common/spinlock.h" 1
# 31 "../../../server-code/src/common/spinlock.h"
# 1 "../../../server-code/src/common/atomic.h" 1
# 110 "../../../server-code/src/common/atomic.h"
static __attribute__((always_inline)) inline int64 InterlockedExchangeAdd64(volatile int64 *addend, int64 increment){
 return __sync_fetch_and_add(addend, increment);
}

static __attribute__((always_inline)) inline int32 InterlockedExchangeAdd(volatile int32 *addend, int32 increment){
 return __sync_fetch_and_add(addend, increment);
}

static __attribute__((always_inline)) inline int64 InterlockedIncrement64(volatile int64 *addend){
 return __sync_add_and_fetch(addend, 1);
}

static __attribute__((always_inline)) inline int32 InterlockedIncrement(volatile int32 *addend){
 return __sync_add_and_fetch(addend, 1);
}

static __attribute__((always_inline)) inline int64 InterlockedDecrement64(volatile int64 *addend){
 return __sync_sub_and_fetch(addend, 1);
}

static __attribute__((always_inline)) inline int32 InterlockedDecrement(volatile int32 *addend){
 return __sync_sub_and_fetch(addend, 1);
}

static __attribute__((always_inline)) inline int64 InterlockedCompareExchange64(volatile int64 *dest, int64 exch, int64 cmp){
 return __sync_val_compare_and_swap(dest, cmp, exch);
}

static __attribute__((always_inline)) inline int32 InterlockedCompareExchange(volatile int32 *dest, int32 exch, int32 cmp){
 return __sync_val_compare_and_swap(dest, cmp, exch);
}

static __attribute__((always_inline)) inline int64 InterlockedExchange64(volatile int64 *target, int64 val){
 return __sync_lock_test_and_set(target, val);
}

static __attribute__((always_inline)) inline int32 InterlockedExchange(volatile int32 *target, int32 val){
 return __sync_lock_test_and_set(target, val);
}
# 32 "../../../server-code/src/common/spinlock.h" 2

# 1 "../../../server-code/src/common/thread.h" 1
# 26 "../../../server-code/src/common/thread.h"
typedef struct rAthread rAthread;
typedef void* (*rAthreadProc)(void*);

typedef enum RATHREAD_PRIO {
 RAT_PRIO_LOW = 0,
 RAT_PRIO_NORMAL,
 RAT_PRIO_HIGH
} RATHREAD_PRIO;
# 45 "../../../server-code/src/common/thread.h"
rAthread *rathread_create(rAthreadProc entryPoint, void *param);
# 58 "../../../server-code/src/common/thread.h"
rAthread *rathread_createEx(rAthreadProc entryPoint, void *param, size_t szStack, RATHREAD_PRIO prio);
# 68 "../../../server-code/src/common/thread.h"
void rathread_destroy(rAthread *handle);
# 79 "../../../server-code/src/common/thread.h"
rAthread *rathread_self(void);
# 90 "../../../server-code/src/common/thread.h"
int rathread_get_tid(void);
# 101 "../../../server-code/src/common/thread.h"

# 101 "../../../server-code/src/common/thread.h" 3 4
_Bool 
# 101 "../../../server-code/src/common/thread.h"
    rathread_wait(rAthread *handle, void **out_exitCode);
# 110 "../../../server-code/src/common/thread.h"
void rathread_prio_set(rAthread *handle, RATHREAD_PRIO prio);







RATHREAD_PRIO rathread_prio_get(rAthread *handle);
# 128 "../../../server-code/src/common/thread.h"
void rathread_yield(void);

void rathread_init(void);
void rathread_final(void);
# 34 "../../../server-code/src/common/spinlock.h" 2
# 47 "../../../server-code/src/common/spinlock.h"
typedef struct SPIN_LOCK{
  volatile int32 lock;
  volatile int32 nest;

  volatile int32 sync_lock;
} __attribute__((aligned(64))) SPIN_LOCK;




static __attribute__((always_inline)) inline void InitializeSpinLock(SPIN_LOCK *lck){
  lck->lock = 0;
  lck->nest = 0;
  lck->sync_lock = 0;
}

static __attribute__((always_inline)) inline void FinalizeSpinLock(SPIN_LOCK *lck){
  return;
}





static __attribute__((always_inline)) inline void EnterSpinLock(SPIN_LOCK *lck){
  int tid = rathread_get_tid();



  do { if(InterlockedCompareExchange((&lck->sync_lock), 1, 0) == 0) break; rathread_yield(); } while( 1);
  if(InterlockedCompareExchange(&lck->lock, tid, tid) == tid){
    InterlockedIncrement(&lck->nest);
    do { InterlockedExchange((&lck->sync_lock), 0); } while(0);
    return;
  }

  do { InterlockedExchange((&lck->sync_lock), 0); } while(0);


  while(1){
   if(InterlockedCompareExchange(&lck->lock, tid, 0) == 0){
    InterlockedIncrement(&lck->nest);
    return;
   }
   rathread_yield();
  }

}


static __attribute__((always_inline)) inline void LeaveSpinLock(SPIN_LOCK *lck){
  int tid = rathread_get_tid();

  do { if(InterlockedCompareExchange((&lck->sync_lock), 1, 0) == 0) break; rathread_yield(); } while( 1);

  if(InterlockedCompareExchange(&lck->lock, tid, tid) == tid){
   if(InterlockedDecrement(&lck->nest) == 0)
     InterlockedExchange(&lck->lock, 0);
  }

  do { InterlockedExchange((&lck->sync_lock), 0); } while(0);
}
# 27 "../../../server-code/src/common/console.h" 2



struct Sql;
# 41 "../../../server-code/src/common/console.h"
typedef void (*CParseFunc)(char *line);
# 56 "../../../server-code/src/common/console.h"
enum CONSOLE_PARSE_ENTRY_TYPE {
 CPET_UNKNOWN,
 CPET_FUNCTION,
 CPET_CATEGORY,
};

struct CParseEntry {
 char cmd[20];
 int type;
 union {
  CParseFunc func;
  struct { int _max_; int _len_; struct CParseEntry * *_data_; } children;
 } u;
};

struct console_input_interface {


 SPIN_LOCK ptlock;
 rAthread *pthread;
 volatile int32 ptstate;
 ramutex *ptmutex;
 racond *ptcond;

 struct { int _max_; int _len_; struct CParseEntry * *_data_; } command_list;
 struct { int _max_; int _len_; struct CParseEntry * *_data_; } commands;

 struct Sql *SQL;

 void (*parse_init) (void);
 void (*parse_final) (void);
 int (*parse_timer) (int tid, int64 tick, int id, intptr_t data);
 void *(*pthread_main) (void *x);
 void (*parse) (char* line);
 void (*parse_sub) (char* line);
 int (*key_pressed) (void);
 void (*load_defaults) (void);
 void (*parse_list_subs) (struct CParseEntry *cmd, unsigned char depth);
 void (*addCommand) (char *name, CParseFunc func);
 void (*setSQL) (struct Sql *SQL_handle);



};

struct console_interface {
 void (*init) (void);
 void (*final) (void);
 void (*display_title) (void);
 void (*display_gplnotice) (void);

 struct console_input_interface *input;
};


void console_defaults(void);


extern struct console_interface *console;
# 25 "../../../server-code/src/common/HPMi.h" 2

# 1 "../../../server-code/src/common/showmsg.h" 1
# 29 "../../../server-code/src/common/showmsg.h"
struct config_setting_t;
# 89 "../../../server-code/src/common/showmsg.h"
enum msg_type {
 MSG_NONE,
 MSG_STATUS,
 MSG_SQL,
 MSG_INFORMATION,
 MSG_NOTICE,
 MSG_WARNING,
 MSG_DEBUG,
 MSG_ERROR,
 MSG_FATALERROR
};

struct showmsg_interface {
 
# 102 "../../../server-code/src/common/showmsg.h" 3 4
_Bool 
# 102 "../../../server-code/src/common/showmsg.h"
     stdout_with_ansisequence;
 int silent;
 int console_log;
 char timestamp_format[20];

 void (*init) (void);
 void (*final) (void);

 void (*clearScreen) (void);
 int (*showMessageV) (const char *string, va_list ap);

 void (*showMessage) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showStatus) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showSQL) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showInfo) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showNotice) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showWarning) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showDebug) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showError) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showFatalError) (const char *, ...) __attribute__((format(printf, 1, 2)));
 void (*showConfigWarning) (struct config_setting_t *config, const char *string, ...) __attribute__((format(printf, 2, 3)));
};
# 140 "../../../server-code/src/common/showmsg.h"
void showmsg_defaults(void);


extern struct showmsg_interface *showmsg;
# 27 "../../../server-code/src/common/HPMi.h" 2

struct Sql;
struct script_state;
struct AtCommandInfo;
struct socket_data;
struct map_session_data;
struct hplugin_data_store;




struct hplugin_info {
 char* name;
 enum server_types type;
 char* version;
 char* req_version;
};

struct s_HPMDataCheck {
 char *name;
 unsigned int size;
 int type;
};



enum hp_event_types {
 HPET_INIT,
 HPET_FINAL,
 HPET_READY,
 HPET_POST_FINAL,
 HPET_PRE_INIT,
 HPET_MAX,
};

enum HPluginPacketHookingPoints {
 hpClif_Parse,
 hpChrif_Parse,
 hpParse_FromMap,
 hpParse_FromLogin,
 hpParse_Char,
 hpParse_FromChar,
 hpParse_Login,

 hpPHP_MAX,
};

enum HPluginHookType {
 HOOK_TYPE_PRE,
 HOOK_TYPE_POST,
};




enum HPluginDataTypes {
 HPDT_UNKNOWN,
 HPDT_SESSION,
 HPDT_MSD,
 HPDT_NPCD,
 HPDT_MAP,
 HPDT_INSTANCE,
 HPDT_GUILD,
 HPDT_PARTY,
 HPDT_MOBDB,
 HPDT_MOBDATA,
 HPDT_ITEMDATA,
 HPDT_BGDATA,
 HPDT_AUTOTRADE_VEND,
};


enum HPluginConfType {
 HPCT_BATTLE,
 HPCT_LOGIN,
 HPCT_CHAR,
 HPCT_CHAR_INTER,
 HPCT_MAP_INTER,
 HPCT_LOG,
 HPCT_SCRIPT,
 HPCT_MAX,
};
# 220 "../../../server-code/src/common/HPMi.h"
struct HPMi_interface {

 unsigned int pid;

 void (*event[HPET_MAX]) (void);
 
# 225 "../../../server-code/src/common/HPMi.h" 3 4
_Bool 
# 225 "../../../server-code/src/common/HPMi.h"
     (*addCommand) (char *name, 
# 225 "../../../server-code/src/common/HPMi.h" 3 4
                                _Bool 
# 225 "../../../server-code/src/common/HPMi.h"
                                     (*func)(const int fd, struct map_session_data* sd, const char* command, const char* message,struct AtCommandInfo *info));
 
# 226 "../../../server-code/src/common/HPMi.h" 3 4
_Bool 
# 226 "../../../server-code/src/common/HPMi.h"
     (*addScript) (char *name, char *args, 
# 226 "../../../server-code/src/common/HPMi.h" 3 4
                                           _Bool 
# 226 "../../../server-code/src/common/HPMi.h"
                                                (*func)(struct script_state *st), 
# 226 "../../../server-code/src/common/HPMi.h" 3 4
                                                                                  _Bool 
# 226 "../../../server-code/src/common/HPMi.h"
                                                                                       isDeprecated);
 void (*addCPCommand) (char *name, CParseFunc func);

 void (*addToHPData) (enum HPluginDataTypes type, uint32 pluginID, struct hplugin_data_store **storeptr, void *data, uint32 classid, 
# 229 "../../../server-code/src/common/HPMi.h" 3 4
                                                                                                                                    _Bool 
# 229 "../../../server-code/src/common/HPMi.h"
                                                                                                                                         autofree);
 void *(*getFromHPData) (enum HPluginDataTypes type, uint32 pluginID, struct hplugin_data_store *store, uint32 classid);
 void (*removeFromHPData) (enum HPluginDataTypes type, uint32 pluginID, struct hplugin_data_store *store, uint32 classid);

 
# 233 "../../../server-code/src/common/HPMi.h" 3 4
_Bool 
# 233 "../../../server-code/src/common/HPMi.h"
     (*addPacket) (unsigned short cmd, unsigned short length, void (*receive)(int fd), unsigned int point, unsigned int pluginID);

 
# 235 "../../../server-code/src/common/HPMi.h" 3 4
_Bool 
# 235 "../../../server-code/src/common/HPMi.h"
     (*AddHook) (enum HPluginHookType type, const char *target, void *hook, unsigned int pID);
 void (*HookStop) (const char *func, unsigned int pID);
 
# 237 "../../../server-code/src/common/HPMi.h" 3 4
_Bool 
# 237 "../../../server-code/src/common/HPMi.h"
     (*HookStopped) (void);

 
# 239 "../../../server-code/src/common/HPMi.h" 3 4
_Bool 
# 239 "../../../server-code/src/common/HPMi.h"
     (*addArg) (unsigned int pluginID, char *name, 
# 239 "../../../server-code/src/common/HPMi.h" 3 4
                                                   _Bool 
# 239 "../../../server-code/src/common/HPMi.h"
                                                        has_param, CmdlineExecFunc func, const char *help);

 
# 241 "../../../server-code/src/common/HPMi.h" 3 4
_Bool 
# 241 "../../../server-code/src/common/HPMi.h"
     (*addConf) (unsigned int pluginID, enum HPluginConfType type, char *name, void (*parse_func) (const char *key, const char *val), int (*return_func) (const char *key));

 void (*addPCGPermission) (unsigned int pluginID, char *name, unsigned int *mask);

 struct Sql *sql_handle;
};
# 30 "../../../server-code/src/common/HPM.h" 2
# 44 "../../../server-code/src/common/HPM.h"
# 1 "/usr/include/dlfcn.h" 1 3 4
# 24 "/usr/include/dlfcn.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 25 "/usr/include/dlfcn.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/bits/dlfcn.h" 1 3 4
# 28 "/usr/include/dlfcn.h" 2 3 4
# 52 "/usr/include/dlfcn.h" 3 4





# 56 "/usr/include/dlfcn.h" 3 4
extern void *dlopen (const char *__file, int __mode) __attribute__ ((__nothrow__));



extern int dlclose (void *__handle) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern void *dlsym (void *__restrict __handle,
      const char *__restrict __name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
# 82 "/usr/include/dlfcn.h" 3 4
extern char *dlerror (void) __attribute__ ((__nothrow__ , __leaf__));
# 188 "/usr/include/dlfcn.h" 3 4

# 45 "../../../server-code/src/common/HPM.h" 2
# 64 "../../../server-code/src/common/HPM.h"
# 1 "/usr/include/string.h" 1 3 4
# 27 "/usr/include/string.h" 3 4





# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 33 "/usr/include/string.h" 2 3 4









extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));






extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));





extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 92 "/usr/include/string.h" 3 4
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


# 123 "/usr/include/string.h" 3 4


extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

# 162 "/usr/include/string.h" 3 4
extern int strcoll_l (const char *__s1, const char *__s2, __locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));

extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    __locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));




extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 206 "/usr/include/string.h" 3 4

# 231 "/usr/include/string.h" 3 4
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 258 "/usr/include/string.h" 3 4
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


# 277 "/usr/include/string.h" 3 4



extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 310 "/usr/include/string.h" 3 4
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 337 "/usr/include/string.h" 3 4
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));




extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
# 392 "/usr/include/string.h" 3 4


extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));

# 422 "/usr/include/string.h" 3 4
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__))

                        __attribute__ ((__nonnull__ (2)));
# 440 "/usr/include/string.h" 3 4
extern char *strerror_l (int __errnum, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));





extern void __bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern void bcopy (const void *__src, void *__dest, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 484 "/usr/include/string.h" 3 4
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 512 "/usr/include/string.h" 3 4
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 529 "/usr/include/string.h" 3 4
extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 552 "/usr/include/string.h" 3 4
extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));


extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
# 639 "/usr/include/string.h" 3 4

# 65 "../../../server-code/src/common/HPM.h" 2




# 68 "../../../server-code/src/common/HPM.h"
struct hplugin {
 void * dll;
 unsigned int idx;
 char *filename;
 struct hplugin_info *info;
 struct HPMi_interface *hpi;
};




struct hpm_symbol {
 const char *name;
 void *ptr;
};




struct hplugin_data_entry {
 uint32 pluginID;
 uint32 classid;
 struct {
  unsigned int free : 1;
 } flag;
 void *data;
};




struct hplugin_data_store {
 enum HPluginDataTypes type;
 struct { int _max_; int _len_; struct hplugin_data_entry * *_data_; } entries;
};

struct HPluginPacket {
 unsigned int pluginID;
 unsigned short cmd;
 short len;
 void (*receive) (int fd);
};

struct HPMFileNameCache {
 const char *addr;
 char *name;
};


struct HPConfListenStorage {
 unsigned int pluginID;
 char key[40];
 void (*parse_func) (const char *key, const char *val);
 int (*return_func) (const char *key);
};


struct HPM_interface {

 unsigned int version[2];
 
# 128 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 128 "../../../server-code/src/common/HPM.h"
     off;
 
# 129 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 129 "../../../server-code/src/common/HPM.h"
     hooking;

 
# 131 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 131 "../../../server-code/src/common/HPM.h"
     force_return;

 struct { int _max_; int _len_; struct hplugin * *_data_; } plugins;
 struct { int _max_; int _len_; struct hpm_symbol * *_data_; } symbols;

 struct { int _max_; int _len_; struct HPluginPacket *_data_; } packets[hpPHP_MAX];

 struct {

  int count;
  struct HPMFileNameCache *data;
 } filenames;

 struct { int _max_; int _len_; struct HPConfListenStorage *_data_; } config_listeners[HPCT_MAX];

 struct { int _max_; int _len_; char * *_data_; } cmdline_load_plugins;

 void (*init) (void);
 void (*final) (void);
 struct hplugin * (*create) (void);
 struct hplugin * (*load) (const char* filename);
 void (*unload) (struct hplugin* plugin);
 
# 153 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 153 "../../../server-code/src/common/HPM.h"
     (*exists) (const char *filename);
 
# 154 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 154 "../../../server-code/src/common/HPM.h"
     (*iscompatible) (char* version);
 void (*event) (enum hp_event_types type);
 void *(*import_symbol) (char *name, unsigned int pID);
 void (*share) (void *value, const char *name);
 void (*config_read) (void);
 char *(*pid2name) (unsigned int pid);
 unsigned char (*parse_packets) (int fd, int packet_id, enum HPluginPacketHookingPoints point);
 void (*load_sub) (struct hplugin *plugin);
 
# 162 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 162 "../../../server-code/src/common/HPM.h"
     (*addhook_sub) (enum HPluginHookType type, const char *target, void *hook, unsigned int pID);

 
# 164 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 164 "../../../server-code/src/common/HPM.h"
     (*parseConf) (const char *w1, const char *w2, enum HPluginConfType point);
 
# 165 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 165 "../../../server-code/src/common/HPM.h"
     (*getBattleConf) (const char* w1, int *value);

 
# 167 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 167 "../../../server-code/src/common/HPM.h"
     (*DataCheck) (struct s_HPMDataCheck *src, unsigned int size, int version, char *name);
 void (*datacheck_init) (const struct s_HPMDataCheck *src, unsigned int length, int version);
 void (*datacheck_final) (void);

 void (*data_store_create) (struct hplugin_data_store **storeptr, enum HPluginDataTypes type);
 void (*data_store_destroy) (struct hplugin_data_store **storeptr);
 
# 173 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 173 "../../../server-code/src/common/HPM.h"
     (*data_store_validate) (enum HPluginDataTypes type, struct hplugin_data_store **storeptr, 
# 173 "../../../server-code/src/common/HPM.h" 3 4
                                                                                               _Bool 
# 173 "../../../server-code/src/common/HPM.h"
                                                                                                    initialize);

 
# 175 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 175 "../../../server-code/src/common/HPM.h"
     (*data_store_validate_sub) (enum HPluginDataTypes type, struct hplugin_data_store **storeptr, 
# 175 "../../../server-code/src/common/HPM.h" 3 4
                                                                                                   _Bool 
# 175 "../../../server-code/src/common/HPM.h"
                                                                                                        initialize);
};


# 178 "../../../server-code/src/common/HPM.h" 3 4
_Bool 
# 178 "../../../server-code/src/common/HPM.h"
cmdline_arg_loadplugin (const char *name, const char *params);

extern struct HPM_interface *HPM;

void hpm_defaults(void);
# 29 "../../../server-code/src/char/HPMchar.h" 2

struct hplugin;


# 32 "../../../server-code/src/char/HPMchar.h" 3 4
_Bool 
# 32 "../../../server-code/src/char/HPMchar.h"
    HPM_char_data_store_validate(enum HPluginDataTypes type, struct hplugin_data_store **storeptr, 
# 32 "../../../server-code/src/char/HPMchar.h" 3 4
                                                                                                   _Bool 
# 32 "../../../server-code/src/char/HPMchar.h"
                                                                                                        initialize);

void HPM_char_plugin_load_sub(struct hplugin *plugin);

void HPM_char_do_final(void);

void HPM_char_do_init(void);
# 27 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/char/geoip.h" 1
# 29 "../../../server-code/src/char/geoip.h"
struct s_geoip {
 unsigned char *cache;
 
# 31 "../../../server-code/src/char/geoip.h" 3 4
_Bool 
# 31 "../../../server-code/src/char/geoip.h"
     active;
};





struct geoip_interface {
 struct s_geoip *data;
 const char* (*getcountry) (uint32 ipnum);
 void (*final) (
# 41 "../../../server-code/src/char/geoip.h" 3 4
               _Bool 
# 41 "../../../server-code/src/char/geoip.h"
                    shutdown);
 void (*init) (void);
};


void geoip_defaults(void);


extern struct geoip_interface *geoip;
# 28 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/char/int_auction.h" 1
# 28 "../../../server-code/src/char/int_auction.h"
struct DBMap;




struct inter_auction_interface {
 struct DBMap *db;
 int (*count) (int char_id, 
# 35 "../../../server-code/src/char/int_auction.h" 3 4
                           _Bool 
# 35 "../../../server-code/src/char/int_auction.h"
                                buy);
 void (*save) (struct auction_data *auction);
 unsigned int (*create) (struct auction_data *auction);
 int (*end_timer) (int tid, int64 tick, int id, intptr_t data);
 void (*delete_) (struct auction_data *auction);
 void (*fromsql) (void);
 int (*parse_frommap) (int fd);
 int (*sql_init) (void);
 void (*sql_final) (void);
};


void inter_auction_defaults(void);


extern struct inter_auction_interface *inter_auction;
# 29 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/char/int_elemental.h" 1
# 29 "../../../server-code/src/char/int_elemental.h"
struct inter_elemental_interface {
 void (*sql_init) (void);
 void (*sql_final) (void);
 int (*parse_frommap) (int fd);
};


void inter_elemental_defaults(void);


extern struct inter_elemental_interface *inter_elemental;
# 30 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/char/int_guild.h" 1
# 27 "../../../server-code/src/char/int_guild.h"
enum {
 GS_BASIC = 0x0001,
 GS_MEMBER = 0x0002,
 GS_POSITION = 0x0004,
 GS_ALLIANCE = 0x0008,
 GS_EXPULSION = 0x0010,
 GS_SKILL = 0x0020,
 GS_EMBLEM = 0x0040,
 GS_CONNECT = 0x0080,
 GS_LEVEL = 0x0100,
 GS_MES = 0x0200,
 GS_MASK = 0x03FF,
 GS_BASIC_MASK = (GS_BASIC | GS_EMBLEM | GS_CONNECT | GS_LEVEL | GS_MES),
 GS_REMOVE = 0x8000,
};




struct inter_guild_interface {
 struct DBMap *guild_db;
 struct DBMap *castle_db;
 unsigned int exp[50];

 int (*save_timer) (int tid, int64 tick, int id, intptr_t data);
 int (*removemember_tosql) (int account_id, int char_id);
 int (*tosql) (struct guild *g, int flag);
 struct guild* (*fromsql) (int guild_id);
 int (*castle_tosql) (struct guild_castle *gc);
 struct guild_castle* (*castle_fromsql) (int castle_id);
 
# 57 "../../../server-code/src/char/int_guild.h" 3 4
_Bool 
# 57 "../../../server-code/src/char/int_guild.h"
     (*exp_parse_row) (char* split[], int column, int current);
 int (*CharOnline) (int char_id, int guild_id);
 int (*CharOffline) (int char_id, int guild_id);
 int (*sql_init) (void);
 int (*db_final) (union DBKey key, struct DBData *data, va_list ap);
 void (*sql_final) (void);
 int (*search_guildname) (const char *str);
 
# 64 "../../../server-code/src/char/int_guild.h" 3 4
_Bool 
# 64 "../../../server-code/src/char/int_guild.h"
     (*check_empty) (struct guild *g);
 unsigned int (*nextexp) (int level);
 int (*checkskill) (struct guild *g, int id);
 int (*calcinfo) (struct guild *g);
 int (*sex_changed) (int guild_id, int account_id, int char_id, short gender);
 int (*charname_changed) (int guild_id, int account_id, int char_id, char *name);
 int (*parse_frommap) (int fd);
 int (*leave) (int guild_id, int account_id, int char_id);
 int (*broken) (int guild_id);
};


void inter_guild_defaults(void);


extern struct inter_guild_interface *inter_guild;
# 31 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/char/int_homun.h" 1
# 29 "../../../server-code/src/char/int_homun.h"
struct inter_homunculus_interface {
 int (*sql_init) (void);
 void (*sql_final) (void);
 int (*parse_frommap) (int fd);
};


void inter_homunculus_defaults(void);


extern struct inter_homunculus_interface *inter_homunculus;
# 32 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/char/int_mail.h" 1
# 26 "../../../server-code/src/char/int_mail.h"
struct item;
struct mail_data;
struct mail_message;




struct inter_mail_interface {
 int (*sql_init) (void);
 void (*sql_final) (void);
 int (*parse_frommap) (int fd);
 int (*fromsql) (int char_id, struct mail_data* md);
 int (*savemessage) (struct mail_message* msg);
 
# 39 "../../../server-code/src/char/int_mail.h" 3 4
_Bool 
# 39 "../../../server-code/src/char/int_mail.h"
     (*loadmessage) (int mail_id, struct mail_message* msg);
 
# 40 "../../../server-code/src/char/int_mail.h" 3 4
_Bool 
# 40 "../../../server-code/src/char/int_mail.h"
     (*DeleteAttach) (int mail_id);
 void (*sendmail) (int send_id, const char* send_name, int dest_id, const char* dest_name, const char* title, const char* body, int zeny, struct item *item);
};


void inter_mail_defaults(void);


extern struct inter_mail_interface *inter_mail;
# 33 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/char/int_mercenary.h" 1
# 26 "../../../server-code/src/char/int_mercenary.h"
struct mmo_charstatus;




struct inter_mercenary_interface {
 
# 32 "../../../server-code/src/char/int_mercenary.h" 3 4
_Bool 
# 32 "../../../server-code/src/char/int_mercenary.h"
     (*owner_fromsql) (int char_id, struct mmo_charstatus *status);
 
# 33 "../../../server-code/src/char/int_mercenary.h" 3 4
_Bool 
# 33 "../../../server-code/src/char/int_mercenary.h"
     (*owner_tosql) (int char_id, struct mmo_charstatus *status);
 
# 34 "../../../server-code/src/char/int_mercenary.h" 3 4
_Bool 
# 34 "../../../server-code/src/char/int_mercenary.h"
     (*owner_delete) (int char_id);
 int (*sql_init) (void);
 void (*sql_final) (void);
 int (*parse_frommap) (int fd);
};


void inter_mercenary_defaults(void);


extern struct inter_mercenary_interface *inter_mercenary;
# 34 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/char/int_party.h" 1
# 28 "../../../server-code/src/char/int_party.h"
struct DBMap;


enum {
 PS_CREATE = 0x01,
 PS_BASIC = 0x02,
 PS_LEADER = 0x04,
 PS_ADDMEMBER = 0x08,
 PS_DELMEMBER = 0x10,
 PS_BREAK = 0x20,
};

struct party_data {
 struct party party;
 unsigned int min_lv, max_lv;
 int family;
 unsigned char size;
};




struct inter_party_interface {
 struct party_data *pt;
 struct DBMap *db;
 int (*check_lv) (struct party_data *p);
 void (*calc_state) (struct party_data *p);
 int (*tosql) (struct party *p, int flag, int index);
 struct party_data* (*fromsql) (int party_id);
 int (*sql_init) (void);
 void (*sql_final) (void);
 struct party_data* (*search_partyname) (const char *str);
 int (*check_exp_share) (struct party_data *p);
 int (*check_empty) (struct party_data *p);
 int (*parse_frommap) (int fd);
 int (*leave) (int party_id,int account_id, int char_id);
 int (*CharOnline) (int char_id, int party_id);
 int (*CharOffline) (int char_id, int party_id);
};


void inter_party_defaults(void);


extern struct inter_party_interface *inter_party;
# 35 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/char/int_pet.h" 1
# 26 "../../../server-code/src/char/int_pet.h"
struct s_pet;




struct inter_pet_interface {
 struct s_pet *pt;
 int (*tosql) (const struct s_pet *p);
 int (*fromsql) (int pet_id, struct s_pet* p);
 int (*sql_init) (void);
 void (*sql_final) (void);
 int (*delete_) (int pet_id);
 int (*parse_frommap) (int fd);
};


void inter_pet_defaults(void);


extern struct inter_pet_interface *inter_pet;
# 36 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/char/int_quest.h" 1
# 29 "../../../server-code/src/char/int_quest.h"
struct inter_quest_interface {
 int (*parse_frommap) (int fd);
};


void inter_quest_defaults(void);


extern struct inter_quest_interface *inter_quest;
# 37 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/char/int_storage.h" 1
# 26 "../../../server-code/src/char/int_storage.h"
struct storage_data;
struct guild_storage;




struct inter_storage_interface {
 int (*tosql) (int account_id, struct storage_data* p);
 int (*fromsql) (int account_id, struct storage_data* p);
 int (*guild_storage_tosql) (int guild_id, const struct guild_storage *p);
 int (*guild_storage_fromsql) (int guild_id, struct guild_storage* p);
 int (*sql_init) (void);
 void (*sql_final) (void);
 int (*delete_) (int account_id);
 int (*guild_storage_delete) (int guild_id);
 int (*parse_frommap) (int fd);
};


void inter_storage_defaults(void);


extern struct inter_storage_interface *inter_storage;
# 38 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/char/inter.h" 1
# 30 "../../../server-code/src/char/inter.h"
struct Sql;




struct inter_interface {
 struct Sql *sql_handle;
 const char* (*msg_txt) (int msg_number);
 
# 38 "../../../server-code/src/char/inter.h" 3 4
_Bool 
# 38 "../../../server-code/src/char/inter.h"
     (*msg_config_read) (const char *cfg_name, 
# 38 "../../../server-code/src/char/inter.h" 3 4
                                               _Bool 
# 38 "../../../server-code/src/char/inter.h"
                                                    allow_override);
 void (*do_final_msg) (void);
 const char* (*job_name) (int class_);
 void (*vmsg_to_fd) (int fd, int u_fd, int aid, char* msg, va_list ap);
 void (*msg_to_fd) (int fd, int u_fd, int aid, char *msg, ...) __attribute__((format(printf, 4, 5)));
 void (*savereg) (int account_id, int char_id, const char *key, unsigned int index, intptr_t val, 
# 43 "../../../server-code/src/char/inter.h" 3 4
                                                                                                 _Bool 
# 43 "../../../server-code/src/char/inter.h"
                                                                                                      is_string);
 int (*accreg_fromsql) (int account_id,int char_id, int fd, int type);
 int (*config_read) (const char* cfgName);
 int (*vlog) (char* fmt, va_list ap);
 int (*log) (char* fmt, ...);
 int (*init_sql) (const char *file);
 int (*mapif_init) (int fd);
 int (*check_ttl_wisdata_sub) (union DBKey key, struct DBData *data, va_list ap);
 int (*check_ttl_wisdata) (void);
 int (*check_length) (int fd, int length);
 int (*parse_frommap) (int fd);
 void (*final) (void);
};


extern unsigned int party_share_level;

void inter_defaults(void);


extern struct inter_interface *inter;
# 39 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/char/loginif.h" 1
# 26 "../../../server-code/src/char/loginif.h"
struct char_session_data;




struct loginif_interface {
 void (*init) (void);
 void (*final) (void);
 void (*reset) (void);
 void (*check_shutdown) (void);
 void (*on_disconnect) (void);
 void (*on_ready) (void);
 void (*block_account) (int account_id, int flag);
 void (*ban_account) (int account_id, short year, short month, short day, short hour, short minute, short second);
 void (*unban_account) (int account_id);
 void (*changesex) (int account_id);
 void (*auth) (int fd, struct char_session_data* sd, uint32 ipl);
 void (*send_users_count) (int users);
 void (*connect_to_server) (void);
};


void loginif_defaults(void);


extern struct loginif_interface *loginif;
# 40 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/char/mapif.h" 1
# 26 "../../../server-code/src/char/mapif.h"
struct WisData;




struct mapif_interface {
 void (*ban) (int id, unsigned int flag, int status);
 void (*server_init) (int id);
 void (*server_destroy) (int id);
 void (*server_reset) (int id);
 void (*on_disconnect) (int id);
 void (*on_parse_accinfo) (int account_id, int u_fd, int u_aid, int u_group, int map_fd);
 void (*char_ban) (int char_id, time_t timestamp);
 int (*sendall) (const unsigned char *buf, unsigned int len);
 int (*sendallwos) (int sfd, unsigned char *buf, unsigned int len);
 int (*send) (int fd, unsigned char *buf, unsigned int len);
 void (*send_users_count) (int users);
 void (*auction_message) (int char_id, unsigned char result);
 void (*auction_sendlist) (int fd, int char_id, short count, short pages, unsigned char *buf);
 void (*parse_auction_requestlist) (int fd);
 void (*auction_register) (int fd, struct auction_data *auction);
 void (*parse_auction_register) (int fd);
 void (*auction_cancel) (int fd, int char_id, unsigned char result);
 void (*parse_auction_cancel) (int fd);
 void (*auction_close) (int fd, int char_id, unsigned char result);
 void (*parse_auction_close) (int fd);
 void (*auction_bid) (int fd, int char_id, int bid, unsigned char result);
 void (*parse_auction_bid) (int fd);
 
# 54 "../../../server-code/src/char/mapif.h" 3 4
_Bool 
# 54 "../../../server-code/src/char/mapif.h"
     (*elemental_create) (struct s_elemental *ele);
 
# 55 "../../../server-code/src/char/mapif.h" 3 4
_Bool 
# 55 "../../../server-code/src/char/mapif.h"
     (*elemental_save) (const struct s_elemental *ele);
 
# 56 "../../../server-code/src/char/mapif.h" 3 4
_Bool 
# 56 "../../../server-code/src/char/mapif.h"
     (*elemental_load) (int ele_id, int char_id, struct s_elemental *ele);
 
# 57 "../../../server-code/src/char/mapif.h" 3 4
_Bool 
# 57 "../../../server-code/src/char/mapif.h"
     (*elemental_delete) (int ele_id);
 void (*elemental_send) (int fd, struct s_elemental *ele, unsigned char flag);
 void (*parse_elemental_create) (int fd, const struct s_elemental *ele);
 void (*parse_elemental_load) (int fd, int ele_id, int char_id);
 void (*elemental_deleted) (int fd, unsigned char flag);
 void (*parse_elemental_delete) (int fd, int ele_id);
 void (*elemental_saved) (int fd, unsigned char flag);
 void (*parse_elemental_save) (int fd, const struct s_elemental *ele);
 int (*guild_created) (int fd, int account_id, struct guild *g);
 int (*guild_noinfo) (int fd, int guild_id);
 int (*guild_info) (int fd, struct guild *g);
 int (*guild_memberadded) (int fd, int guild_id, int account_id, int char_id, int flag);
 int (*guild_withdraw) (int guild_id, int account_id, int char_id, int flag, const char *name, const char *mes);
 int (*guild_memberinfoshort) (struct guild *g, int idx);
 int (*guild_broken) (int guild_id, int flag);
 int (*guild_message) (int guild_id, int account_id, const char *mes, int len, int sfd);
 int (*guild_basicinfochanged) (int guild_id, int type, const void *data, int len);
 int (*guild_memberinfochanged) (int guild_id, int account_id, int char_id, int type, const void *data, int len);
 int (*guild_skillupack) (int guild_id, uint16 skill_id, int account_id);
 int (*guild_alliance) (int guild_id1, int guild_id2, int account_id1, int account_id2, int flag, const char *name1, const char *name2);
 int (*guild_position) (struct guild *g, int idx);
 int (*guild_notice) (struct guild *g);
 int (*guild_emblem) (struct guild *g);
 int (*guild_master_changed) (struct guild *g, int aid, int cid);
 int (*guild_castle_dataload) (int fd, int sz, const int *castle_ids);
 int (*parse_CreateGuild) (int fd, int account_id, const char *name, const struct guild_member *master);
 int (*parse_GuildInfo) (int fd, int guild_id);
 int (*parse_GuildAddMember) (int fd, int guild_id, const struct guild_member *m);
 int (*parse_GuildLeave) (int fd, int guild_id, int account_id, int char_id, int flag, const char *mes);
 int (*parse_GuildChangeMemberInfoShort) (int fd, int guild_id, int account_id, int char_id, int online, int lv, int class_);
 int (*parse_BreakGuild) (int fd, int guild_id);
 int (*parse_GuildMessage) (int fd, int guild_id, int account_id, const char *mes, int len);
 int (*parse_GuildBasicInfoChange) (int fd, int guild_id, int type, const void *data, int len);
 int (*parse_GuildMemberInfoChange) (int fd, int guild_id, int account_id, int char_id, int type, const char *data, int len);
 int (*parse_GuildPosition) (int fd, int guild_id, int idx, const struct guild_position *p);
 int (*parse_GuildSkillUp) (int fd, int guild_id, uint16 skill_id, int account_id, int max);
 int (*parse_GuildDeleteAlliance) (struct guild *g, int guild_id, int account_id1, int account_id2, int flag);
 int (*parse_GuildAlliance) (int fd, int guild_id1, int guild_id2, int account_id1, int account_id2, int flag);
 int (*parse_GuildNotice) (int fd, int guild_id, const char *mes1, const char *mes2);
 int (*parse_GuildEmblem) (int fd, int len, int guild_id, int dummy, const char *data);
 int (*parse_GuildCastleDataLoad) (int fd, int len, const int *castle_ids);
 int (*parse_GuildCastleDataSave) (int fd, int castle_id, int index, int value);
 int (*parse_GuildMasterChange) (int fd, int guild_id, const char* name, int len);
 void (*homunculus_created) (int fd, int account_id, const struct s_homunculus *sh, unsigned char flag);
 void (*homunculus_deleted) (int fd, int flag);
 void (*homunculus_loaded) (int fd, int account_id, struct s_homunculus *hd);
 void (*homunculus_saved) (int fd, int account_id, 
# 103 "../../../server-code/src/char/mapif.h" 3 4
                                                  _Bool 
# 103 "../../../server-code/src/char/mapif.h"
                                                       flag);
 void (*homunculus_renamed) (int fd, int account_id, int char_id, unsigned char flag, const char *name);
 
# 105 "../../../server-code/src/char/mapif.h" 3 4
_Bool 
# 105 "../../../server-code/src/char/mapif.h"
     (*homunculus_create) (struct s_homunculus *hd);
 
# 106 "../../../server-code/src/char/mapif.h" 3 4
_Bool 
# 106 "../../../server-code/src/char/mapif.h"
     (*homunculus_save) (const struct s_homunculus *hd);
 
# 107 "../../../server-code/src/char/mapif.h" 3 4
_Bool 
# 107 "../../../server-code/src/char/mapif.h"
     (*homunculus_load) (int homun_id, struct s_homunculus* hd);
 
# 108 "../../../server-code/src/char/mapif.h" 3 4
_Bool 
# 108 "../../../server-code/src/char/mapif.h"
     (*homunculus_delete) (int homun_id);
 
# 109 "../../../server-code/src/char/mapif.h" 3 4
_Bool 
# 109 "../../../server-code/src/char/mapif.h"
     (*homunculus_rename) (const char *name);
 void (*parse_homunculus_create) (int fd, int len, int account_id, const struct s_homunculus *phd);
 void (*parse_homunculus_delete) (int fd, int homun_id);
 void (*parse_homunculus_load) (int fd, int account_id, int homun_id);
 void (*parse_homunculus_save) (int fd, int len, int account_id, const struct s_homunculus *phd);
 void (*parse_homunculus_rename) (int fd, int account_id, int char_id, const char *name);
 void (*mail_sendinbox) (int fd, int char_id, unsigned char flag, struct mail_data *md);
 void (*parse_mail_requestinbox) (int fd);
 void (*parse_mail_read) (int fd);
 void (*mail_sendattach) (int fd, int char_id, struct mail_message *msg);
 void (*mail_getattach) (int fd, int char_id, int mail_id);
 void (*parse_mail_getattach) (int fd);
 void (*mail_delete) (int fd, int char_id, int mail_id, 
# 121 "../../../server-code/src/char/mapif.h" 3 4
                                                       _Bool 
# 121 "../../../server-code/src/char/mapif.h"
                                                            failed);
 void (*parse_mail_delete) (int fd);
 void (*mail_new) (struct mail_message *msg);
 void (*mail_return) (int fd, int char_id, int mail_id, int new_mail);
 void (*parse_mail_return) (int fd);
 void (*mail_send) (int fd, struct mail_message* msg);
 void (*parse_mail_send) (int fd);
 
# 128 "../../../server-code/src/char/mapif.h" 3 4
_Bool 
# 128 "../../../server-code/src/char/mapif.h"
     (*mercenary_create) (struct s_mercenary *merc);
 
# 129 "../../../server-code/src/char/mapif.h" 3 4
_Bool 
# 129 "../../../server-code/src/char/mapif.h"
     (*mercenary_save) (const struct s_mercenary *merc);
 
# 130 "../../../server-code/src/char/mapif.h" 3 4
_Bool 
# 130 "../../../server-code/src/char/mapif.h"
     (*mercenary_load) (int merc_id, int char_id, struct s_mercenary *merc);
 
# 131 "../../../server-code/src/char/mapif.h" 3 4
_Bool 
# 131 "../../../server-code/src/char/mapif.h"
     (*mercenary_delete) (int merc_id);
 void (*mercenary_send) (int fd, struct s_mercenary *merc, unsigned char flag);
 void (*parse_mercenary_create) (int fd, const struct s_mercenary *merc);
 void (*parse_mercenary_load) (int fd, int merc_id, int char_id);
 void (*mercenary_deleted) (int fd, unsigned char flag);
 void (*parse_mercenary_delete) (int fd, int merc_id);
 void (*mercenary_saved) (int fd, unsigned char flag);
 void (*parse_mercenary_save) (int fd, const struct s_mercenary *merc);
 int (*party_created) (int fd, int account_id, int char_id, struct party *p);
 void (*party_noinfo) (int fd, int party_id, int char_id);
 void (*party_info) (int fd, struct party* p, int char_id);
 int (*party_memberadded) (int fd, int party_id, int account_id, int char_id, int flag);
 int (*party_optionchanged) (int fd, struct party *p, int account_id, int flag);
 int (*party_withdraw) (int party_id,int account_id, int char_id);
 int (*party_membermoved) (struct party *p, int idx);
 int (*party_broken) (int party_id, int flag);
 int (*party_message) (int party_id, int account_id, const char *mes, int len, int sfd);
 int (*parse_CreateParty) (int fd, const char *name, int item, int item2, const struct party_member *leader);
 void (*parse_PartyInfo) (int fd, int party_id, int char_id);
 int (*parse_PartyAddMember) (int fd, int party_id, const struct party_member *member);
 int (*parse_PartyChangeOption) (int fd,int party_id,int account_id,int exp,int item);
 int (*parse_PartyLeave) (int fd, int party_id, int account_id, int char_id);
 int (*parse_PartyChangeMap) (int fd, int party_id, int account_id, int char_id, unsigned short map, int online, unsigned int lv);
 int (*parse_BreakParty) (int fd, int party_id);
 int (*parse_PartyMessage) (int fd, int party_id, int account_id, const char *mes, int len);
 int (*parse_PartyLeaderChange) (int fd, int party_id, int account_id, int char_id);
 int (*pet_created) (int fd, int account_id, struct s_pet *p);
 int (*pet_info) (int fd, int account_id, struct s_pet *p);
 int (*pet_noinfo) (int fd, int account_id);
 int (*save_pet_ack) (int fd, int account_id, int flag);
 int (*delete_pet_ack) (int fd, int flag);
 int (*create_pet) (int fd, int account_id, int char_id, short pet_class, short pet_lv, short pet_egg_id,
   short pet_equip, short intimate, short hungry, char rename_flag, char incubate, const char *pet_name);
 int (*load_pet) (int fd, int account_id, int char_id, int pet_id);
 int (*save_pet) (int fd, int account_id, const struct s_pet *data);
 int (*delete_pet) (int fd, int pet_id);
 int (*parse_CreatePet) (int fd);
 int (*parse_LoadPet) (int fd);
 int (*parse_SavePet) (int fd);
 int (*parse_DeletePet) (int fd);
 struct quest *(*quests_fromsql) (int char_id, int *count);
 
# 172 "../../../server-code/src/char/mapif.h" 3 4
_Bool 
# 172 "../../../server-code/src/char/mapif.h"
     (*quest_delete) (int char_id, int quest_id);
 
# 173 "../../../server-code/src/char/mapif.h" 3 4
_Bool 
# 173 "../../../server-code/src/char/mapif.h"
     (*quest_add) (int char_id, struct quest qd);
 
# 174 "../../../server-code/src/char/mapif.h" 3 4
_Bool 
# 174 "../../../server-code/src/char/mapif.h"
     (*quest_update) (int char_id, struct quest qd);
 void (*quest_save_ack) (int fd, int char_id, 
# 175 "../../../server-code/src/char/mapif.h" 3 4
                                             _Bool 
# 175 "../../../server-code/src/char/mapif.h"
                                                  success);
 int (*parse_quest_save) (int fd);
 void (*send_quests) (int fd, int char_id, struct quest *tmp_questlog, int num_quests);
 int (*parse_quest_load) (int fd);
 int (*load_guild_storage) (int fd, int account_id, int guild_id, char flag);
 int (*save_guild_storage_ack) (int fd, int account_id, int guild_id, int fail);
 int (*parse_LoadGuildStorage) (int fd);
 int (*parse_SaveGuildStorage) (int fd);
 int (*itembound_ack) (int fd, int aid, int guild_id);
 int (*parse_ItemBoundRetrieve_sub) (int fd);
 void (*parse_ItemBoundRetrieve) (int fd);
 void (*parse_accinfo) (int fd);
 void (*parse_accinfo2) (
# 187 "../../../server-code/src/char/mapif.h" 3 4
                        _Bool 
# 187 "../../../server-code/src/char/mapif.h"
                             success, int map_fd, int u_fd, int u_aid, int account_id, const char *userid, const char *user_pass,
   const char *email, const char *last_ip, const char *lastlogin, const char *pin_code, const char *birthdate, int group_id, int logincount, int state);
 int (*broadcast) (const unsigned char *mes, int len, unsigned int fontColor, short fontType, short fontSize, short fontAlign, short fontY, int sfd);
 int (*wis_message) (struct WisData *wd);
 void (*wis_response) (int fd, const unsigned char *src, int flag);
 int (*wis_end) (struct WisData *wd, int flag);
 int (*account_reg_reply) (int fd,int account_id,int char_id, int type);
 int (*disconnectplayer) (int fd, int account_id, int char_id, int reason);
 int (*parse_broadcast) (int fd);
 int (*parse_WisRequest) (int fd);
 int (*parse_WisReply) (int fd);
 int (*parse_WisToGM) (int fd);
 int (*parse_Registry) (int fd);
 int (*parse_RegistryRequest) (int fd);
 void (*namechange_ack) (int fd, int account_id, int char_id, int type, int flag, const char *name);
 int (*parse_NameChangeRequest) (int fd);
};


void mapif_defaults(void);


extern struct mapif_interface *mapif;
# 41 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/char/pincode.h" 1
# 26 "../../../server-code/src/char/pincode.h"
struct char_session_data;

enum PincodeResponseCode {
 PINCODE_OK = 0,
 PINCODE_ASK = 1,
 PINCODE_NOTSET = 2,
 PINCODE_EXPIRED = 3,
 PINCODE_UNUSED = 7,
 PINCODE_WRONG = 8,
};




struct pincode_interface {

 int enabled;
 int changetime;
 int maxtry;
 int charselect;
 unsigned int multiplier;
 unsigned int baseSeed;

 void (*handle) (int fd, struct char_session_data* sd);
 void (*decrypt) (unsigned int userSeed, char* pin);
 void (*error) (int account_id);
 void (*update) (int account_id, char* pin);
 void (*sendstate) (int fd, struct char_session_data* sd, uint16 state);
 void (*setnew) (int fd, struct char_session_data* sd);
 void (*change) (int fd, struct char_session_data* sd);
 int (*compare) (int fd, struct char_session_data* sd, char* pin);
 void (*check) (int fd, struct char_session_data* sd);
 
# 58 "../../../server-code/src/char/pincode.h" 3 4
_Bool 
# 58 "../../../server-code/src/char/pincode.h"
     (*config_read) (char *w1, char *w2);
};


void pincode_defaults(void);


extern struct pincode_interface *pincode;
# 42 "../../../server-code/src/char/char.c" 2






# 1 "../../../server-code/src/common/memmgr.h" 1
# 80 "../../../server-code/src/common/memmgr.h"
struct malloc_interface {
 void (*init) (void);
 void (*final) (void);

 void* (*malloc)(size_t size, const char *file, int line, const char *func);
 void* (*calloc)(size_t num, size_t size, const char *file, int line, const char *func);
 void* (*realloc)(void *p, size_t size, const char *file, int line, const char *func);
 void* (*reallocz)(void *p, size_t size, const char *file, int line, const char *func);
 char* (*astrdup)(const char *p, const char *file, int line, const char *func);
 char *(*astrndup)(const char *p, size_t size, const char *file, int line, const char *func);
 void (*free)(void *p, const char *file, int line, const char *func);

 void (*memory_check)(void);
 
# 93 "../../../server-code/src/common/memmgr.h" 3 4
_Bool 
# 93 "../../../server-code/src/common/memmgr.h"
     (*verify_ptr)(void* ptr);
 size_t (*usage) (void);

 void (*post_shutdown) (void);
 void (*init_messages) (void);
};


void malloc_defaults(void);

void memmgr_report(int extra);


extern struct malloc_interface *iMalloc;
# 49 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/common/mapindex.h" 1
# 28 "../../../server-code/src/common/mapindex.h"
struct DBMap;
# 84 "../../../server-code/src/common/mapindex.h"
struct mapindex_interface {
 char config_file[80];

 struct DBMap *db;

 int num;

 char *default_map;

 int default_x;

 int default_y;

 struct {
  char name[(11 + 1)];
 } list[2000];

 int (*init) (void);
 void (*final) (void);

 int (*addmap) (int index, const char* name);
 void (*removemap) (int index);
 const char* (*getmapname) (const char* string, char* output);


 const char* (*getmapname_ext) (const char* string, char* output);

 unsigned short (*name2id) (const char*);
 const char * (*id2name) (uint16 id, const char *file, int line, const char *func);
 
# 113 "../../../server-code/src/common/mapindex.h" 3 4
_Bool 
# 113 "../../../server-code/src/common/mapindex.h"
     (*check_default) (void);
};


void mapindex_defaults(void);


extern struct mapindex_interface *mapindex;
# 50 "../../../server-code/src/char/char.c" 2

# 1 "../../../server-code/src/common/nullpo.h" 1
# 40 "../../../server-code/src/common/nullpo.h"
# 1 "/usr/include/assert.h" 1 3 4
# 66 "/usr/include/assert.h" 3 4




# 69 "/usr/include/assert.h" 3 4
extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));



# 41 "../../../server-code/src/common/nullpo.h" 2
# 155 "../../../server-code/src/common/nullpo.h"

# 155 "../../../server-code/src/common/nullpo.h"
struct nullpo_interface {
 void (*assert_report) (const char *file, int line, const char *func, const char *targetname, const char *title);
};


void nullpo_defaults(void);


extern struct nullpo_interface *nullpo;
# 52 "../../../server-code/src/char/char.c" 2

# 1 "../../../server-code/src/common/socket.h" 1
# 54 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/common/strlib.h" 1
# 54 "../../../server-code/src/common/strlib.h"
typedef enum e_svopt {

 SV_NOESCAPE_NOTERMINATE = 0,

 SV_ESCAPE_C = 1,

 SV_TERMINATE_LF = 2,
 SV_TERMINATE_CRLF = 4,
 SV_TERMINATE_CR = 8,

 SV_KEEP_TERMINATOR = 16
} e_svopt;






struct s_svstate {
 const char* str;
 int len;
 int off;
 int start;
 int end;
 enum e_svopt opt;
 char delim;
 
# 80 "../../../server-code/src/common/strlib.h" 3 4
_Bool 
# 80 "../../../server-code/src/common/strlib.h"
     done;
};



struct StringBuf {
 char *buf_;
 char *ptr_;
 unsigned int max_;
};
typedef struct StringBuf StringBuf;

struct strlib_interface {
 char *(*jstrescape) (char* pt);
 char *(*jstrescapecpy) (char* pt, const char* spt);
 int (*jmemescapecpy) (char* pt, const char* spt, int size);
 int (*remove_control_chars_) (char* str);
 char *(*trim_) (char* str);
 char *(*normalize_name_) (char* str,const char* delims);
 const char *(*stristr_) (const char *haystack, const char *needle);


 size_t (*strnlen_) (const char* string, size_t maxlen);


 char * (*strtok_r_) (char *s1, const char *s2, char **lasts);

 int (*e_mail_check_) (char* email);
 int (*config_switch_) (const char* str);


 char *(*safestrncpy_) (char* dst, const char* src, size_t n);


 size_t (*safestrnlen_) (const char* string, size_t maxlen);




 int (*safesnprintf_) (char *buf, size_t sz, const char *fmt, ...) __attribute__((format(printf, 3, 4)));



 int (*strline_) (const char* str, size_t pos);




 
# 128 "../../../server-code/src/common/strlib.h" 3 4
_Bool 
# 128 "../../../server-code/src/common/strlib.h"
     (*bin2hex_) (char* output, unsigned char* input, size_t count);
};

struct stringbuf_interface {
 StringBuf* (*Malloc) (void);
 void (*Init) (StringBuf* self);
 int (*Printf) (StringBuf *self, const char *fmt, ...) __attribute__((format(printf, 2, 3)));
 int (*Vprintf) (StringBuf* self, const char* fmt, va_list args);
 int (*Append) (StringBuf* self, const StringBuf *sbuf);
 int (*AppendStr) (StringBuf* self, const char* str);
 int (*Length) (StringBuf* self);
 char* (*Value) (StringBuf* self);
 void (*Clear) (StringBuf* self);
 void (*Destroy) (StringBuf* self);
 void (*Free) (StringBuf* self);
};

struct sv_interface {





 int (*parse_next) (struct s_svstate* svstate);






 int (*parse) (const char* str, int len, int startoff, char delim, int* out_pos, int npos, enum e_svopt opt);







 int (*split) (char* str, int len, int startoff, char delim, char** out_fields, int nfields, enum e_svopt opt);




 size_t (*escape_c) (char* out_dest, const char* src, size_t len, const char* escapes);




 size_t (*unescape_c) (char* out_dest, const char* src, size_t len);


 const char* (*skip_escaped_c) (const char* p);




 
# 184 "../../../server-code/src/common/strlib.h" 3 4
_Bool 
# 184 "../../../server-code/src/common/strlib.h"
     (*readdb) (const char* directory, const char* filename, char delim, int mincols, int maxcols, int maxrows, 
# 184 "../../../server-code/src/common/strlib.h" 3 4
                                                                                                                _Bool 
# 184 "../../../server-code/src/common/strlib.h"
                                                                                                                     (*parseproc)(char* fields[], int columns, int current));
};


void strlib_defaults(void);


extern struct strlib_interface *strlib;
extern struct stringbuf_interface *StrBuf;
extern struct sv_interface *sv;
# 55 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/common/sql.h" 1
# 40 "../../../server-code/src/common/sql.h"
enum SqlDataType {
 SQLDT_NULL,

 SQLDT_INT8,
 SQLDT_INT16,
 SQLDT_INT32,
 SQLDT_INT64,
 SQLDT_UINT8,
 SQLDT_UINT16,
 SQLDT_UINT32,
 SQLDT_UINT64,

 SQLDT_CHAR,
 SQLDT_SHORT,
 SQLDT_INT,
 SQLDT_LONG,
 SQLDT_LONGLONG,
 SQLDT_UCHAR,
 SQLDT_USHORT,
 SQLDT_UINT,
 SQLDT_ULONG,
 SQLDT_ULONGLONG,

 SQLDT_FLOAT,
 SQLDT_DOUBLE,

 SQLDT_STRING,
 SQLDT_ENUM,


 SQLDT_BLOB,
 SQLDT_LASTID
};

struct Sql;
struct SqlStmt;

struct sql_interface {



 int (*Connect) (struct Sql *self, const char *user, const char *passwd, const char *host, uint16 port, const char *db);



 int (*GetTimeout) (struct Sql *self, uint32 *out_timeout);



 int (*GetColumnNames) (struct Sql *self, const char *table, char *out_buf, size_t buf_len, char sep);



 int (*SetEncoding) (struct Sql *self, const char *encoding);



 int (*Ping) (struct Sql *self);




 size_t (*EscapeString) (struct Sql *self, char *out_to, const char *from);




 size_t (*EscapeStringLen) (struct Sql *self, char *out_to, const char *from, size_t from_len);





 int (*Query) (struct Sql *self, const char *query, ...) __attribute__((format(printf, 2, 3)));





 int (*QueryV) (struct Sql *self, const char *query, va_list args);





 int (*QueryStr) (struct Sql *self, const char *query);



 uint64 (*LastInsertId) (struct Sql *self);



 uint32 (*NumColumns) (struct Sql *self);



 uint64 (*NumRows) (struct Sql *self);




 int (*NextRow) (struct Sql *self);




 int (*GetData) (struct Sql *self, size_t col, char **out_buf, size_t *out_len);

 void (*FreeResult) (struct Sql *self);

 void (*ShowDebug_) (struct Sql *self, const char *debug_file, const unsigned long debug_line);

 void (*Free) (struct Sql *self);

 struct Sql *(*Malloc) (void);
# 179 "../../../server-code/src/common/sql.h"
 struct SqlStmt* (*StmtMalloc)(struct Sql *sql);






 int (*StmtPrepare) (struct SqlStmt *self, const char *query, ...) __attribute__((format(printf, 2, 3)));






 int (*StmtPrepareV)(struct SqlStmt *self, const char *query, va_list args);






 int (*StmtPrepareStr)(struct SqlStmt *self, const char *query);




 size_t (*StmtNumParams)(struct SqlStmt *self);






 int (*StmtBindParam)(struct SqlStmt *self, size_t idx, enum SqlDataType buffer_type, const void *buffer, size_t buffer_len);





 int (*StmtExecute)(struct SqlStmt *self);




 uint64 (*StmtLastInsertId)(struct SqlStmt *self);




 size_t (*StmtNumColumns)(struct SqlStmt *self);







 int (*StmtBindColumn)(struct SqlStmt *self, size_t idx, enum SqlDataType buffer_type, void *buffer, size_t buffer_len, uint32 *out_length, int8 *out_is_null);




 uint64 (*StmtNumRows)(struct SqlStmt *self);





 int (*StmtNextRow)(struct SqlStmt *self);


 void (*StmtFreeResult)(struct SqlStmt *self);


 void (*StmtFree)(struct SqlStmt *self);

 void (*StmtShowDebug_)(struct SqlStmt *self, const char *debug_file, const unsigned long debug_line);

};


void sql_defaults(void);

void Sql_Init(void);

void Sql_HerculesUpdateCheck(struct Sql *self);
void Sql_HerculesUpdateSkip(struct Sql *self, const char *filename);


extern struct sql_interface *SQL;
# 56 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/common/timer.h" 1
# 32 "../../../server-code/src/common/timer.h"
enum {
 TIMER_ONCE_AUTODEL = 0x01,
 TIMER_INTERVAL = 0x02,
 TIMER_REMOVE_HEAP = 0x10,
};



typedef int (*TimerFunc)(int tid, int64 tick, int id, intptr_t data);

struct TimerData {
 int64 tick;
 TimerFunc func;
 unsigned char type;
 int interval;


 int id;
 intptr_t data;
};







struct timer_interface {


 int64 (*gettick) (void);
 int64 (*gettick_nocache) (void);

 int (*add) (int64 tick, TimerFunc func, int id, intptr_t data);
 int (*add_interval) (int64 tick, TimerFunc func, int id, intptr_t data, int interval);
 const struct TimerData *(*get) (int tid);
 int (*delete) (int tid, TimerFunc func);

 int64 (*addtick) (int tid, int64 tick);
 int64 (*settick) (int tid, int64 tick);

 int (*add_func_list) (TimerFunc func, char* name);

 unsigned long (*get_uptime) (void);

 int (*perform) (int64 tick);
 void (*init) (void);
 void (*final) (void);
};


void timer_defaults(void);


extern struct timer_interface *timer;
# 57 "../../../server-code/src/char/char.c" 2
# 1 "../../../server-code/src/common/utils.h" 1
# 26 "../../../server-code/src/common/utils.h"
# 1 "/usr/include/stdio.h" 1 3 4
# 29 "/usr/include/stdio.h" 3 4




# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 34 "/usr/include/stdio.h" 2 3 4
# 44 "/usr/include/stdio.h" 3 4

# 44 "/usr/include/stdio.h" 3 4
struct _IO_FILE;



typedef struct _IO_FILE FILE;





# 64 "/usr/include/stdio.h" 3 4
typedef struct _IO_FILE __FILE;
# 74 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/libio.h" 1 3 4
# 31 "/usr/include/libio.h" 3 4
# 1 "/usr/include/_G_config.h" 1 3 4
# 15 "/usr/include/_G_config.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 16 "/usr/include/_G_config.h" 2 3 4




# 1 "/usr/include/wchar.h" 1 3 4
# 82 "/usr/include/wchar.h" 3 4
typedef struct
{
  int __count;
  union
  {

    unsigned int __wch;



    char __wchb[4];
  } __value;
} __mbstate_t;
# 21 "/usr/include/_G_config.h" 2 3 4
typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 32 "/usr/include/libio.h" 2 3 4
# 144 "/usr/include/libio.h" 3 4
struct _IO_jump_t; struct _IO_FILE;





typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
# 173 "/usr/include/libio.h" 3 4
};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
# 241 "/usr/include/libio.h" 3 4
struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
# 289 "/usr/include/libio.h" 3 4
  __off64_t _offset;
# 298 "/usr/include/libio.h" 3 4
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;

  int _mode;

  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 334 "/usr/include/libio.h" 3 4
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie, const char *__buf,
     size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn (void *__cookie);
# 386 "/usr/include/libio.h" 3 4
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
# 430 "/usr/include/libio.h" 3 4
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));

extern int _IO_peekc_locked (_IO_FILE *__fp);





extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
# 460 "/usr/include/libio.h" 3 4
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);

extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
# 75 "/usr/include/stdio.h" 2 3 4
# 90 "/usr/include/stdio.h" 3 4
typedef __off_t off_t;
# 102 "/usr/include/stdio.h" 3 4
typedef __ssize_t ssize_t;







typedef _G_fpos_t fpos_t;




# 164 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 1 3 4
# 165 "/usr/include/stdio.h" 2 3 4



extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;







extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));

extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));




extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));








extern FILE *tmpfile (void) ;
# 209 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__ , __leaf__)) ;





extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__ , __leaf__)) ;
# 227 "/usr/include/stdio.h" 3 4
extern char *tempnam (const char *__dir, const char *__pfx)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;








extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);

# 252 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 266 "/usr/include/stdio.h" 3 4






extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes) ;




extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
# 295 "/usr/include/stdio.h" 3 4

# 306 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__)) ;
# 319 "/usr/include/stdio.h" 3 4
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__)) ;






extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__));





extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__));


extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));








extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);




extern int printf (const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));





extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);




extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));





extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));

# 412 "/usr/include/stdio.h" 3 4
extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));








extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) ;




extern int scanf (const char *__restrict __format, ...) ;

extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));
# 443 "/usr/include/stdio.h" 3 4
extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf")

                               ;
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf")
                              ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__))

                      ;
# 463 "/usr/include/stdio.h" 3 4








extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;





extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
# 494 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))



     __attribute__ ((__format__ (__scanf__, 2, 0)));
# 522 "/usr/include/stdio.h" 3 4









extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);

# 550 "/usr/include/stdio.h" 3 4
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 561 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);











extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);

# 594 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);








extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;
# 640 "/usr/include/stdio.h" 3 4

# 665 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char **__restrict __lineptr,
          size_t *__restrict __n, int __delimiter,
          FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
        size_t *__restrict __n, int __delimiter,
        FILE *__restrict __stream) ;







extern __ssize_t getline (char **__restrict __lineptr,
       size_t *__restrict __n,
       FILE *__restrict __stream) ;








extern int fputs (const char *__restrict __s, FILE *__restrict __stream);





extern int puts (const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;




extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);

# 737 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);








extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream) ;




extern void rewind (FILE *__stream);

# 773 "/usr/include/stdio.h" 3 4
extern int fseeko (FILE *__stream, __off_t __off, int __whence);




extern __off_t ftello (FILE *__stream) ;
# 792 "/usr/include/stdio.h" 3 4






extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);




extern int fsetpos (FILE *__stream, const fpos_t *__pos);
# 815 "/usr/include/stdio.h" 3 4

# 824 "/usr/include/stdio.h" 3 4


extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));

extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;

extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;




extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;








extern void perror (const char *__s);






# 1 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h" 1 3 4
# 26 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern const char *const sys_errlist[];
# 854 "/usr/include/stdio.h" 2 3 4




extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
# 872 "/usr/include/stdio.h" 3 4
extern FILE *popen (const char *__command, const char *__modes) ;





extern int pclose (FILE *__stream);





extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__));
# 912 "/usr/include/stdio.h" 3 4
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));



extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;


extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
# 942 "/usr/include/stdio.h" 3 4

# 27 "../../../server-code/src/common/utils.h" 2

# 1 "/usr/include/unistd.h" 1 3 4
# 27 "/usr/include/unistd.h" 3 4

# 205 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/posix_opt.h" 1 3 4
# 206 "/usr/include/unistd.h" 2 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/environments.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/environments.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/environments.h" 2 3 4
# 210 "/usr/include/unistd.h" 2 3 4
# 229 "/usr/include/unistd.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 230 "/usr/include/unistd.h" 2 3 4





typedef __gid_t gid_t;




typedef __uid_t uid_t;
# 258 "/usr/include/unistd.h" 3 4
typedef __useconds_t useconds_t;
# 277 "/usr/include/unistd.h" 3 4
typedef __socklen_t socklen_t;
# 290 "/usr/include/unistd.h" 3 4
extern int access (const char *__name, int __type) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 307 "/usr/include/unistd.h" 3 4
extern int faccessat (int __fd, const char *__file, int __type, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
# 337 "/usr/include/unistd.h" 3 4
extern __off_t lseek (int __fd, __off_t __offset, int __whence) __attribute__ ((__nothrow__ , __leaf__));
# 356 "/usr/include/unistd.h" 3 4
extern int close (int __fd);






extern ssize_t read (int __fd, void *__buf, size_t __nbytes) ;





extern ssize_t write (int __fd, const void *__buf, size_t __n) ;
# 379 "/usr/include/unistd.h" 3 4
extern ssize_t pread (int __fd, void *__buf, size_t __nbytes,
        __off_t __offset) ;






extern ssize_t pwrite (int __fd, const void *__buf, size_t __n,
         __off_t __offset) ;
# 420 "/usr/include/unistd.h" 3 4
extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__ , __leaf__)) ;
# 435 "/usr/include/unistd.h" 3 4
extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__ , __leaf__));
# 447 "/usr/include/unistd.h" 3 4
extern unsigned int sleep (unsigned int __seconds);







extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     __attribute__ ((__nothrow__ , __leaf__));






extern int usleep (__useconds_t __useconds);
# 472 "/usr/include/unistd.h" 3 4
extern int pause (void);



extern int chown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;



extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int lchown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;






extern int fchownat (int __fd, const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;



extern int chdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;



extern int fchdir (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
# 514 "/usr/include/unistd.h" 3 4
extern char *getcwd (char *__buf, size_t __size) __attribute__ ((__nothrow__ , __leaf__)) ;
# 528 "/usr/include/unistd.h" 3 4
extern char *getwd (char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__)) ;




extern int dup (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;


extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__ , __leaf__));
# 546 "/usr/include/unistd.h" 3 4
extern char **__environ;







extern int execve (const char *__path, char *const __argv[],
     char *const __envp[]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern int fexecve (int __fd, char *const __argv[], char *const __envp[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));




extern int execv (const char *__path, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern int execle (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern int execl (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern int execvp (const char *__file, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern int execlp (const char *__file, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
# 601 "/usr/include/unistd.h" 3 4
extern int nice (int __inc) __attribute__ ((__nothrow__ , __leaf__)) ;




extern void _exit (int __status) __attribute__ ((__noreturn__));





# 1 "/usr/include/x86_64-linux-gnu/bits/confname.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/confname.h" 3 4
enum
  {
    _PC_LINK_MAX,

    _PC_MAX_CANON,

    _PC_MAX_INPUT,

    _PC_NAME_MAX,

    _PC_PATH_MAX,

    _PC_PIPE_BUF,

    _PC_CHOWN_RESTRICTED,

    _PC_NO_TRUNC,

    _PC_VDISABLE,

    _PC_SYNC_IO,

    _PC_ASYNC_IO,

    _PC_PRIO_IO,

    _PC_SOCK_MAXBUF,

    _PC_FILESIZEBITS,

    _PC_REC_INCR_XFER_SIZE,

    _PC_REC_MAX_XFER_SIZE,

    _PC_REC_MIN_XFER_SIZE,

    _PC_REC_XFER_ALIGN,

    _PC_ALLOC_SIZE_MIN,

    _PC_SYMLINK_MAX,

    _PC_2_SYMLINKS

  };


enum
  {
    _SC_ARG_MAX,

    _SC_CHILD_MAX,

    _SC_CLK_TCK,

    _SC_NGROUPS_MAX,

    _SC_OPEN_MAX,

    _SC_STREAM_MAX,

    _SC_TZNAME_MAX,

    _SC_JOB_CONTROL,

    _SC_SAVED_IDS,

    _SC_REALTIME_SIGNALS,

    _SC_PRIORITY_SCHEDULING,

    _SC_TIMERS,

    _SC_ASYNCHRONOUS_IO,

    _SC_PRIORITIZED_IO,

    _SC_SYNCHRONIZED_IO,

    _SC_FSYNC,

    _SC_MAPPED_FILES,

    _SC_MEMLOCK,

    _SC_MEMLOCK_RANGE,

    _SC_MEMORY_PROTECTION,

    _SC_MESSAGE_PASSING,

    _SC_SEMAPHORES,

    _SC_SHARED_MEMORY_OBJECTS,

    _SC_AIO_LISTIO_MAX,

    _SC_AIO_MAX,

    _SC_AIO_PRIO_DELTA_MAX,

    _SC_DELAYTIMER_MAX,

    _SC_MQ_OPEN_MAX,

    _SC_MQ_PRIO_MAX,

    _SC_VERSION,

    _SC_PAGESIZE,


    _SC_RTSIG_MAX,

    _SC_SEM_NSEMS_MAX,

    _SC_SEM_VALUE_MAX,

    _SC_SIGQUEUE_MAX,

    _SC_TIMER_MAX,




    _SC_BC_BASE_MAX,

    _SC_BC_DIM_MAX,

    _SC_BC_SCALE_MAX,

    _SC_BC_STRING_MAX,

    _SC_COLL_WEIGHTS_MAX,

    _SC_EQUIV_CLASS_MAX,

    _SC_EXPR_NEST_MAX,

    _SC_LINE_MAX,

    _SC_RE_DUP_MAX,

    _SC_CHARCLASS_NAME_MAX,


    _SC_2_VERSION,

    _SC_2_C_BIND,

    _SC_2_C_DEV,

    _SC_2_FORT_DEV,

    _SC_2_FORT_RUN,

    _SC_2_SW_DEV,

    _SC_2_LOCALEDEF,


    _SC_PII,

    _SC_PII_XTI,

    _SC_PII_SOCKET,

    _SC_PII_INTERNET,

    _SC_PII_OSI,

    _SC_POLL,

    _SC_SELECT,

    _SC_UIO_MAXIOV,

    _SC_IOV_MAX = _SC_UIO_MAXIOV,

    _SC_PII_INTERNET_STREAM,

    _SC_PII_INTERNET_DGRAM,

    _SC_PII_OSI_COTS,

    _SC_PII_OSI_CLTS,

    _SC_PII_OSI_M,

    _SC_T_IOV_MAX,



    _SC_THREADS,

    _SC_THREAD_SAFE_FUNCTIONS,

    _SC_GETGR_R_SIZE_MAX,

    _SC_GETPW_R_SIZE_MAX,

    _SC_LOGIN_NAME_MAX,

    _SC_TTY_NAME_MAX,

    _SC_THREAD_DESTRUCTOR_ITERATIONS,

    _SC_THREAD_KEYS_MAX,

    _SC_THREAD_STACK_MIN,

    _SC_THREAD_THREADS_MAX,

    _SC_THREAD_ATTR_STACKADDR,

    _SC_THREAD_ATTR_STACKSIZE,

    _SC_THREAD_PRIORITY_SCHEDULING,

    _SC_THREAD_PRIO_INHERIT,

    _SC_THREAD_PRIO_PROTECT,

    _SC_THREAD_PROCESS_SHARED,


    _SC_NPROCESSORS_CONF,

    _SC_NPROCESSORS_ONLN,

    _SC_PHYS_PAGES,

    _SC_AVPHYS_PAGES,

    _SC_ATEXIT_MAX,

    _SC_PASS_MAX,


    _SC_XOPEN_VERSION,

    _SC_XOPEN_XCU_VERSION,

    _SC_XOPEN_UNIX,

    _SC_XOPEN_CRYPT,

    _SC_XOPEN_ENH_I18N,

    _SC_XOPEN_SHM,


    _SC_2_CHAR_TERM,

    _SC_2_C_VERSION,

    _SC_2_UPE,


    _SC_XOPEN_XPG2,

    _SC_XOPEN_XPG3,

    _SC_XOPEN_XPG4,


    _SC_CHAR_BIT,

    _SC_CHAR_MAX,

    _SC_CHAR_MIN,

    _SC_INT_MAX,

    _SC_INT_MIN,

    _SC_LONG_BIT,

    _SC_WORD_BIT,

    _SC_MB_LEN_MAX,

    _SC_NZERO,

    _SC_SSIZE_MAX,

    _SC_SCHAR_MAX,

    _SC_SCHAR_MIN,

    _SC_SHRT_MAX,

    _SC_SHRT_MIN,

    _SC_UCHAR_MAX,

    _SC_UINT_MAX,

    _SC_ULONG_MAX,

    _SC_USHRT_MAX,


    _SC_NL_ARGMAX,

    _SC_NL_LANGMAX,

    _SC_NL_MSGMAX,

    _SC_NL_NMAX,

    _SC_NL_SETMAX,

    _SC_NL_TEXTMAX,


    _SC_XBS5_ILP32_OFF32,

    _SC_XBS5_ILP32_OFFBIG,

    _SC_XBS5_LP64_OFF64,

    _SC_XBS5_LPBIG_OFFBIG,


    _SC_XOPEN_LEGACY,

    _SC_XOPEN_REALTIME,

    _SC_XOPEN_REALTIME_THREADS,


    _SC_ADVISORY_INFO,

    _SC_BARRIERS,

    _SC_BASE,

    _SC_C_LANG_SUPPORT,

    _SC_C_LANG_SUPPORT_R,

    _SC_CLOCK_SELECTION,

    _SC_CPUTIME,

    _SC_THREAD_CPUTIME,

    _SC_DEVICE_IO,

    _SC_DEVICE_SPECIFIC,

    _SC_DEVICE_SPECIFIC_R,

    _SC_FD_MGMT,

    _SC_FIFO,

    _SC_PIPE,

    _SC_FILE_ATTRIBUTES,

    _SC_FILE_LOCKING,

    _SC_FILE_SYSTEM,

    _SC_MONOTONIC_CLOCK,

    _SC_MULTI_PROCESS,

    _SC_SINGLE_PROCESS,

    _SC_NETWORKING,

    _SC_READER_WRITER_LOCKS,

    _SC_SPIN_LOCKS,

    _SC_REGEXP,

    _SC_REGEX_VERSION,

    _SC_SHELL,

    _SC_SIGNALS,

    _SC_SPAWN,

    _SC_SPORADIC_SERVER,

    _SC_THREAD_SPORADIC_SERVER,

    _SC_SYSTEM_DATABASE,

    _SC_SYSTEM_DATABASE_R,

    _SC_TIMEOUTS,

    _SC_TYPED_MEMORY_OBJECTS,

    _SC_USER_GROUPS,

    _SC_USER_GROUPS_R,

    _SC_2_PBS,

    _SC_2_PBS_ACCOUNTING,

    _SC_2_PBS_LOCATE,

    _SC_2_PBS_MESSAGE,

    _SC_2_PBS_TRACK,

    _SC_SYMLOOP_MAX,

    _SC_STREAMS,

    _SC_2_PBS_CHECKPOINT,


    _SC_V6_ILP32_OFF32,

    _SC_V6_ILP32_OFFBIG,

    _SC_V6_LP64_OFF64,

    _SC_V6_LPBIG_OFFBIG,


    _SC_HOST_NAME_MAX,

    _SC_TRACE,

    _SC_TRACE_EVENT_FILTER,

    _SC_TRACE_INHERIT,

    _SC_TRACE_LOG,


    _SC_LEVEL1_ICACHE_SIZE,

    _SC_LEVEL1_ICACHE_ASSOC,

    _SC_LEVEL1_ICACHE_LINESIZE,

    _SC_LEVEL1_DCACHE_SIZE,

    _SC_LEVEL1_DCACHE_ASSOC,

    _SC_LEVEL1_DCACHE_LINESIZE,

    _SC_LEVEL2_CACHE_SIZE,

    _SC_LEVEL2_CACHE_ASSOC,

    _SC_LEVEL2_CACHE_LINESIZE,

    _SC_LEVEL3_CACHE_SIZE,

    _SC_LEVEL3_CACHE_ASSOC,

    _SC_LEVEL3_CACHE_LINESIZE,

    _SC_LEVEL4_CACHE_SIZE,

    _SC_LEVEL4_CACHE_ASSOC,

    _SC_LEVEL4_CACHE_LINESIZE,



    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,

    _SC_RAW_SOCKETS,


    _SC_V7_ILP32_OFF32,

    _SC_V7_ILP32_OFFBIG,

    _SC_V7_LP64_OFF64,

    _SC_V7_LPBIG_OFFBIG,


    _SC_SS_REPL_MAX,


    _SC_TRACE_EVENT_NAME_MAX,

    _SC_TRACE_NAME_MAX,

    _SC_TRACE_SYS_MAX,

    _SC_TRACE_USER_EVENT_MAX,


    _SC_XOPEN_STREAMS,


    _SC_THREAD_ROBUST_PRIO_INHERIT,

    _SC_THREAD_ROBUST_PRIO_PROTECT

  };


enum
  {
    _CS_PATH,


    _CS_V6_WIDTH_RESTRICTED_ENVS,



    _CS_GNU_LIBC_VERSION,

    _CS_GNU_LIBPTHREAD_VERSION,


    _CS_V5_WIDTH_RESTRICTED_ENVS,



    _CS_V7_WIDTH_RESTRICTED_ENVS,



    _CS_LFS_CFLAGS = 1000,

    _CS_LFS_LDFLAGS,

    _CS_LFS_LIBS,

    _CS_LFS_LINTFLAGS,

    _CS_LFS64_CFLAGS,

    _CS_LFS64_LDFLAGS,

    _CS_LFS64_LIBS,

    _CS_LFS64_LINTFLAGS,


    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,

    _CS_XBS5_ILP32_OFF32_LDFLAGS,

    _CS_XBS5_ILP32_OFF32_LIBS,

    _CS_XBS5_ILP32_OFF32_LINTFLAGS,

    _CS_XBS5_ILP32_OFFBIG_CFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LIBS,

    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,

    _CS_XBS5_LP64_OFF64_CFLAGS,

    _CS_XBS5_LP64_OFF64_LDFLAGS,

    _CS_XBS5_LP64_OFF64_LIBS,

    _CS_XBS5_LP64_OFF64_LINTFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LIBS,

    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LIBS,

    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V6_LP64_OFF64_CFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LIBS,

    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V7_ILP32_OFF32_LIBS,

    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V7_LP64_OFF64_CFLAGS,

    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V7_LP64_OFF64_LIBS,

    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,


    _CS_V6_ENV,

    _CS_V7_ENV

  };
# 613 "/usr/include/unistd.h" 2 3 4


extern long int pathconf (const char *__path, int __name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__ , __leaf__));


extern long int sysconf (int __name) __attribute__ ((__nothrow__ , __leaf__));



extern size_t confstr (int __name, char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__));




extern __pid_t getpid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __pid_t getppid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __pid_t getpgrp (void) __attribute__ ((__nothrow__ , __leaf__));


extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));

extern __pid_t getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));






extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__ , __leaf__));
# 663 "/usr/include/unistd.h" 3 4
extern int setpgrp (void) __attribute__ ((__nothrow__ , __leaf__));






extern __pid_t setsid (void) __attribute__ ((__nothrow__ , __leaf__));



extern __pid_t getsid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));



extern __uid_t getuid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __uid_t geteuid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __gid_t getgid (void) __attribute__ ((__nothrow__ , __leaf__));


extern __gid_t getegid (void) __attribute__ ((__nothrow__ , __leaf__));




extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__ , __leaf__)) ;
# 703 "/usr/include/unistd.h" 3 4
extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;






extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;
# 759 "/usr/include/unistd.h" 3 4
extern __pid_t fork (void) __attribute__ ((__nothrow__));







extern __pid_t vfork (void) __attribute__ ((__nothrow__ , __leaf__));





extern char *ttyname (int __fd) __attribute__ ((__nothrow__ , __leaf__));



extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;



extern int isatty (int __fd) __attribute__ ((__nothrow__ , __leaf__));





extern int ttyslot (void) __attribute__ ((__nothrow__ , __leaf__));




extern int link (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;




extern int linkat (int __fromfd, const char *__from, int __tofd,
     const char *__to, int __flags)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4))) ;




extern int symlink (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;




extern ssize_t readlink (const char *__restrict __path,
    char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;




extern int symlinkat (const char *__from, int __tofd,
        const char *__to) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3))) ;


extern ssize_t readlinkat (int __fd, const char *__restrict __path,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3))) ;



extern int unlink (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern int unlinkat (int __fd, const char *__name, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern int rmdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__ , __leaf__));


extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__ , __leaf__));






extern char *getlogin (void);







extern int getlogin_r (char *__name, size_t __name_len) __attribute__ ((__nonnull__ (1)));




extern int setlogin (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 874 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/getopt.h" 1 3 4
# 57 "/usr/include/getopt.h" 3 4
extern char *optarg;
# 71 "/usr/include/getopt.h" 3 4
extern int optind;




extern int opterr;



extern int optopt;
# 150 "/usr/include/getopt.h" 3 4
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       __attribute__ ((__nothrow__ , __leaf__));
# 875 "/usr/include/unistd.h" 2 3 4







extern int gethostname (char *__name, size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern int sethostname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;



extern int sethostid (long int __id) __attribute__ ((__nothrow__ , __leaf__)) ;





extern int getdomainname (char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int setdomainname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;





extern int vhangup (void) __attribute__ ((__nothrow__ , __leaf__));


extern int revoke (const char *__file) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;







extern int profil (unsigned short int *__sample_buffer, size_t __size,
     size_t __offset, unsigned int __scale)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int acct (const char *__name) __attribute__ ((__nothrow__ , __leaf__));



extern char *getusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void endusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void setusershell (void) __attribute__ ((__nothrow__ , __leaf__));





extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__ , __leaf__)) ;






extern int chroot (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;



extern char *getpass (const char *__prompt) __attribute__ ((__nonnull__ (1)));







extern int fsync (int __fd);
# 972 "/usr/include/unistd.h" 3 4
extern long int gethostid (void);


extern void sync (void) __attribute__ ((__nothrow__ , __leaf__));





extern int getpagesize (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern int getdtablesize (void) __attribute__ ((__nothrow__ , __leaf__));
# 996 "/usr/include/unistd.h" 3 4
extern int truncate (const char *__file, __off_t __length)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 1019 "/usr/include/unistd.h" 3 4
extern int ftruncate (int __fd, __off_t __length) __attribute__ ((__nothrow__ , __leaf__)) ;
# 1040 "/usr/include/unistd.h" 3 4
extern int brk (void *__addr) __attribute__ ((__nothrow__ , __leaf__)) ;





extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__ , __leaf__));
# 1061 "/usr/include/unistd.h" 3 4
extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__ , __leaf__));
# 1084 "/usr/include/unistd.h" 3 4
extern int lockf (int __fd, int __cmd, __off_t __len) ;
# 1115 "/usr/include/unistd.h" 3 4
extern int fdatasync (int __fildes);
# 1154 "/usr/include/unistd.h" 3 4

# 29 "../../../server-code/src/common/utils.h" 2
# 39 "../../../server-code/src/common/utils.h"

# 39 "../../../server-code/src/common/utils.h"
void WriteDump(FILE* fp, const void* buffer, size_t length);
void ShowDump(const void* buffer, size_t length);

void findfile(const char *p, const char *pat, void (func)(const char*));

# 43 "../../../server-code/src/common/utils.h" 3 4
_Bool 
# 43 "../../../server-code/src/common/utils.h"
    exists(const char* filename);


unsigned int get_percentage(const unsigned int A, const unsigned int B);

int64 apply_percentrate64(int64 value, int rate, int maxrate);
int apply_percentrate(int value, int rate, int maxrate);

const char* timestamp2string(char* str, size_t size, time_t timestamp, const char* format);





extern uint8 GetByte(uint32 val, int idx);
extern uint16 GetWord(uint32 val, int idx);
extern uint16 MakeWord(uint8 byte0, uint8 byte1);
extern uint32 MakeDWord(uint16 word0, uint16 word1);




extern int16 MakeShortLE(int16 val);
extern int32 MakeLongLE(int32 val);
extern uint16 GetUShort(const unsigned char* buf);
extern uint32 GetULong(const unsigned char* buf);
extern int32 GetLong(const unsigned char* buf);
extern float GetFloat(const unsigned char* buf);

size_t hread(void * ptr, size_t size, size_t count, FILE * stream);
size_t hwrite(const void * ptr, size_t size, size_t count, FILE * stream);
# 83 "../../../server-code/src/common/utils.h"
struct HCache_interface {
 void (*init) (void);

 
# 86 "../../../server-code/src/common/utils.h" 3 4
_Bool 
# 86 "../../../server-code/src/common/utils.h"
     (*check) (const char *file);
 FILE *(*open) (const char *file, const char *opt);

 time_t recompile_time;
 
# 90 "../../../server-code/src/common/utils.h" 3 4
_Bool 
# 90 "../../../server-code/src/common/utils.h"
     enabled;
};


void HCache_defaults(void);


extern struct HCache_interface *HCache;
# 58 "../../../server-code/src/char/char.c" 2

# 1 "/usr/include/signal.h" 1 3 4
# 30 "/usr/include/signal.h" 3 4


# 1 "/usr/include/x86_64-linux-gnu/bits/sigset.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/sigset.h" 3 4

# 22 "/usr/include/x86_64-linux-gnu/bits/sigset.h" 3 4
typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
# 102 "/usr/include/x86_64-linux-gnu/bits/sigset.h" 3 4
extern int __sigismember (const __sigset_t *, int);
extern int __sigaddset (__sigset_t *, int);
extern int __sigdelset (__sigset_t *, int);
# 33 "/usr/include/signal.h" 2 3 4







typedef __sig_atomic_t sig_atomic_t;








typedef __sigset_t sigset_t;







# 1 "/usr/include/x86_64-linux-gnu/bits/signum.h" 1 3 4
# 58 "/usr/include/signal.h" 2 3 4
# 80 "/usr/include/signal.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/siginfo.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/siginfo.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 25 "/usr/include/x86_64-linux-gnu/bits/siginfo.h" 2 3 4







typedef union sigval
  {
    int sival_int;
    void *sival_ptr;
  } sigval_t;
# 58 "/usr/include/x86_64-linux-gnu/bits/siginfo.h" 3 4
typedef __clock_t __sigchld_clock_t;



typedef struct
  {
    int si_signo;
    int si_errno;

    int si_code;

    union
      {
 int _pad[((128 / sizeof (int)) - 4)];


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
   } _kill;


 struct
   {
     int si_tid;
     int si_overrun;
     sigval_t si_sigval;
   } _timer;


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     sigval_t si_sigval;
   } _rt;


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     int si_status;
     __sigchld_clock_t si_utime;
     __sigchld_clock_t si_stime;
   } _sigchld;


 struct
   {
     void *si_addr;
     short int si_addr_lsb;
     struct
       {
  void *_lower;
  void *_upper;
       } si_addr_bnd;
   } _sigfault;


 struct
   {
     long int si_band;
     int si_fd;
   } _sigpoll;


 struct
   {
     void *_call_addr;
     int _syscall;
     unsigned int _arch;
   } _sigsys;
      } _sifields;
  } siginfo_t ;
# 160 "/usr/include/x86_64-linux-gnu/bits/siginfo.h" 3 4
enum
{
  SI_ASYNCNL = -60,

  SI_TKILL = -6,

  SI_SIGIO,

  SI_ASYNCIO,

  SI_MESGQ,

  SI_TIMER,

  SI_QUEUE,

  SI_USER,

  SI_KERNEL = 0x80

};




enum
{
  ILL_ILLOPC = 1,

  ILL_ILLOPN,

  ILL_ILLADR,

  ILL_ILLTRP,

  ILL_PRVOPC,

  ILL_PRVREG,

  ILL_COPROC,

  ILL_BADSTK

};


enum
{
  FPE_INTDIV = 1,

  FPE_INTOVF,

  FPE_FLTDIV,

  FPE_FLTOVF,

  FPE_FLTUND,

  FPE_FLTRES,

  FPE_FLTINV,

  FPE_FLTSUB

};


enum
{
  SEGV_MAPERR = 1,

  SEGV_ACCERR

};


enum
{
  BUS_ADRALN = 1,

  BUS_ADRERR,

  BUS_OBJERR,

  BUS_MCEERR_AR,

  BUS_MCEERR_AO

};
# 264 "/usr/include/x86_64-linux-gnu/bits/siginfo.h" 3 4
enum
{
  CLD_EXITED = 1,

  CLD_KILLED,

  CLD_DUMPED,

  CLD_TRAPPED,

  CLD_STOPPED,

  CLD_CONTINUED

};


enum
{
  POLL_IN = 1,

  POLL_OUT,

  POLL_MSG,

  POLL_ERR,

  POLL_PRI,

  POLL_HUP

};
# 316 "/usr/include/x86_64-linux-gnu/bits/siginfo.h" 3 4
typedef union pthread_attr_t pthread_attr_t;



typedef struct sigevent
  {
    sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;

    union
      {
 int _pad[((64 / sizeof (int)) - 4)];



 __pid_t _tid;

 struct
   {
     void (*_function) (sigval_t);
     pthread_attr_t *_attribute;
   } _sigev_thread;
      } _sigev_un;
  } sigevent_t;






enum
{
  SIGEV_SIGNAL = 0,

  SIGEV_NONE,

  SIGEV_THREAD,


  SIGEV_THREAD_ID = 4

};
# 81 "/usr/include/signal.h" 2 3 4




typedef void (*__sighandler_t) (int);




extern __sighandler_t __sysv_signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
# 100 "/usr/include/signal.h" 3 4


extern __sighandler_t signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
# 114 "/usr/include/signal.h" 3 4

# 127 "/usr/include/signal.h" 3 4
extern int kill (__pid_t __pid, int __sig) __attribute__ ((__nothrow__ , __leaf__));






extern int killpg (__pid_t __pgrp, int __sig) __attribute__ ((__nothrow__ , __leaf__));




extern int raise (int __sig) __attribute__ ((__nothrow__ , __leaf__));




extern __sighandler_t ssignal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));
extern int gsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));




extern void psignal (int __sig, const char *__s);


extern void psiginfo (const siginfo_t *__pinfo, const char *__s);
# 187 "/usr/include/signal.h" 3 4
extern int sigblock (int __mask) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));


extern int sigsetmask (int __mask) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));


extern int siggetmask (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));
# 207 "/usr/include/signal.h" 3 4
typedef __sighandler_t sig_t;





extern int sigemptyset (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int sigfillset (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int sigaddset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int sigdelset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int sigismember (const sigset_t *__set, int __signo)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 243 "/usr/include/signal.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/sigaction.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/sigaction.h" 3 4
struct sigaction
  {


    union
      {

 __sighandler_t sa_handler;

 void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;







    __sigset_t sa_mask;


    int sa_flags;


    void (*sa_restorer) (void);
  };
# 244 "/usr/include/signal.h" 2 3 4


extern int sigprocmask (int __how, const sigset_t *__restrict __set,
   sigset_t *__restrict __oset) __attribute__ ((__nothrow__ , __leaf__));






extern int sigsuspend (const sigset_t *__set) __attribute__ ((__nonnull__ (1)));


extern int sigaction (int __sig, const struct sigaction *__restrict __act,
        struct sigaction *__restrict __oact) __attribute__ ((__nothrow__ , __leaf__));


extern int sigpending (sigset_t *__set) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern int sigwait (const sigset_t *__restrict __set, int *__restrict __sig)
     __attribute__ ((__nonnull__ (1, 2)));






extern int sigwaitinfo (const sigset_t *__restrict __set,
   siginfo_t *__restrict __info) __attribute__ ((__nonnull__ (1)));






extern int sigtimedwait (const sigset_t *__restrict __set,
    siginfo_t *__restrict __info,
    const struct timespec *__restrict __timeout)
     __attribute__ ((__nonnull__ (1)));



extern int sigqueue (__pid_t __pid, int __sig, const union sigval __val)
     __attribute__ ((__nothrow__ , __leaf__));
# 301 "/usr/include/signal.h" 3 4
extern const char *const _sys_siglist[65];
extern const char *const sys_siglist[65];



# 1 "/usr/include/x86_64-linux-gnu/bits/sigcontext.h" 1 3 4
# 29 "/usr/include/x86_64-linux-gnu/bits/sigcontext.h" 3 4
struct _fpx_sw_bytes
{
  __uint32_t magic1;
  __uint32_t extended_size;
  __uint64_t xstate_bv;
  __uint32_t xstate_size;
  __uint32_t padding[7];
};

struct _fpreg
{
  unsigned short significand[4];
  unsigned short exponent;
};

struct _fpxreg
{
  unsigned short significand[4];
  unsigned short exponent;
  unsigned short padding[3];
};

struct _xmmreg
{
  __uint32_t element[4];
};
# 121 "/usr/include/x86_64-linux-gnu/bits/sigcontext.h" 3 4
struct _fpstate
{

  __uint16_t cwd;
  __uint16_t swd;
  __uint16_t ftw;
  __uint16_t fop;
  __uint64_t rip;
  __uint64_t rdp;
  __uint32_t mxcsr;
  __uint32_t mxcr_mask;
  struct _fpxreg _st[8];
  struct _xmmreg _xmm[16];
  __uint32_t padding[24];
};

struct sigcontext
{
  __uint64_t r8;
  __uint64_t r9;
  __uint64_t r10;
  __uint64_t r11;
  __uint64_t r12;
  __uint64_t r13;
  __uint64_t r14;
  __uint64_t r15;
  __uint64_t rdi;
  __uint64_t rsi;
  __uint64_t rbp;
  __uint64_t rbx;
  __uint64_t rdx;
  __uint64_t rax;
  __uint64_t rcx;
  __uint64_t rsp;
  __uint64_t rip;
  __uint64_t eflags;
  unsigned short cs;
  unsigned short gs;
  unsigned short fs;
  unsigned short __pad0;
  __uint64_t err;
  __uint64_t trapno;
  __uint64_t oldmask;
  __uint64_t cr2;
  __extension__ union
    {
      struct _fpstate * fpstate;
      __uint64_t __fpstate_word;
    };
  __uint64_t __reserved1 [8];
};



struct _xsave_hdr
{
  __uint64_t xstate_bv;
  __uint64_t reserved1[2];
  __uint64_t reserved2[5];
};

struct _ymmh_state
{
  __uint32_t ymmh_space[64];
};

struct _xstate
{
  struct _fpstate fpstate;
  struct _xsave_hdr xstate_hdr;
  struct _ymmh_state ymmh;
};
# 307 "/usr/include/signal.h" 2 3 4


extern int sigreturn (struct sigcontext *__scp) __attribute__ ((__nothrow__ , __leaf__));






# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 317 "/usr/include/signal.h" 2 3 4




extern int siginterrupt (int __sig, int __interrupt) __attribute__ ((__nothrow__ , __leaf__));

# 1 "/usr/include/x86_64-linux-gnu/bits/sigstack.h" 1 3 4
# 25 "/usr/include/x86_64-linux-gnu/bits/sigstack.h" 3 4
struct sigstack
  {
    void *ss_sp;
    int ss_onstack;
  };



enum
{
  SS_ONSTACK = 1,

  SS_DISABLE

};
# 49 "/usr/include/x86_64-linux-gnu/bits/sigstack.h" 3 4
typedef struct sigaltstack
  {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
  } stack_t;
# 324 "/usr/include/signal.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/sys/ucontext.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/sys/ucontext.h" 3 4
# 1 "/usr/include/signal.h" 1 3 4
# 23 "/usr/include/x86_64-linux-gnu/sys/ucontext.h" 2 3 4
# 31 "/usr/include/x86_64-linux-gnu/sys/ucontext.h" 3 4
__extension__ typedef long long int greg_t;





typedef greg_t gregset_t[23];
# 92 "/usr/include/x86_64-linux-gnu/sys/ucontext.h" 3 4
struct _libc_fpxreg
{
  unsigned short int significand[4];
  unsigned short int exponent;
  unsigned short int padding[3];
};

struct _libc_xmmreg
{
  __uint32_t element[4];
};

struct _libc_fpstate
{

  __uint16_t cwd;
  __uint16_t swd;
  __uint16_t ftw;
  __uint16_t fop;
  __uint64_t rip;
  __uint64_t rdp;
  __uint32_t mxcsr;
  __uint32_t mxcr_mask;
  struct _libc_fpxreg _st[8];
  struct _libc_xmmreg _xmm[16];
  __uint32_t padding[24];
};


typedef struct _libc_fpstate *fpregset_t;


typedef struct
  {
    gregset_t gregs;

    fpregset_t fpregs;
    __extension__ unsigned long long __reserved1 [8];
} mcontext_t;


typedef struct ucontext
  {
    unsigned long int uc_flags;
    struct ucontext *uc_link;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
    __sigset_t uc_sigmask;
    struct _libc_fpstate __fpregs_mem;
  } ucontext_t;
# 327 "/usr/include/signal.h" 2 3 4





extern int sigstack (struct sigstack *__ss, struct sigstack *__oss)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));



extern int sigaltstack (const struct sigaltstack *__restrict __ss,
   struct sigaltstack *__restrict __oss) __attribute__ ((__nothrow__ , __leaf__));
# 361 "/usr/include/signal.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 1 3 4
# 21 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 2 3 4
# 60 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
typedef unsigned long int pthread_t;


union pthread_attr_t
{
  char __size[56];
  long int __align;
};







typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
# 90 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;

    unsigned int __nusers;



    int __kind;

    short __spins;
    short __elision;
    __pthread_list_t __list;
# 125 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
  } __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;




typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;





typedef union
{

  struct
  {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;
    int __writer;
    int __shared;
    signed char __rwelision;




    unsigned char __pad1[7];


    unsigned long int __pad2;


    unsigned int __flags;

  } __data;
# 220 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
  char __size[56];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;




typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 362 "/usr/include/signal.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/sigthread.h" 1 3 4
# 30 "/usr/include/x86_64-linux-gnu/bits/sigthread.h" 3 4
extern int pthread_sigmask (int __how,
       const __sigset_t *__restrict __newmask,
       __sigset_t *__restrict __oldmask)__attribute__ ((__nothrow__ , __leaf__));


extern int pthread_kill (pthread_t __threadid, int __signo) __attribute__ ((__nothrow__ , __leaf__));
# 363 "/usr/include/signal.h" 2 3 4






extern int __libc_current_sigrtmin (void) __attribute__ ((__nothrow__ , __leaf__));

extern int __libc_current_sigrtmax (void) __attribute__ ((__nothrow__ , __leaf__));




# 60 "../../../server-code/src/char/char.c" 2


# 1 "/usr/include/stdlib.h" 1 3 4
# 32 "/usr/include/stdlib.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 33 "/usr/include/stdlib.h" 2 3 4








# 1 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 1 3 4
# 50 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 3 4
typedef enum
{
  P_ALL,
  P_PID,
  P_PGID
} idtype_t;
# 42 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 1 3 4
# 66 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 3 4
union wait
  {
    int w_status;
    struct
      {

 unsigned int __w_termsig:7;
 unsigned int __w_coredump:1;
 unsigned int __w_retcode:8;
 unsigned int:16;







      } __wait_terminated;
    struct
      {

 unsigned int __w_stopval:8;
 unsigned int __w_stopsig:8;
 unsigned int:16;






      } __wait_stopped;
  };
# 43 "/usr/include/stdlib.h" 2 3 4
# 67 "/usr/include/stdlib.h" 3 4
typedef union
  {
    union wait *__uptr;
    int *__iptr;
  } __WAIT_STATUS __attribute__ ((__transparent_union__));
# 95 "/usr/include/stdlib.h" 3 4


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;







__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;


# 139 "/usr/include/stdlib.h" 3 4
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) ;




extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));




__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

# 305 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) ;


extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;




# 1 "/usr/include/x86_64-linux-gnu/sys/types.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4






typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;
# 60 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __dev_t dev_t;
# 70 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __mode_t mode_t;




typedef __nlink_t nlink_t;
# 104 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __id_t id_t;
# 115 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 146 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 147 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
# 200 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));

typedef int register_t __attribute__ ((__mode__ (__word__)));
# 219 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/select.h" 1 3 4
# 30 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/select.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/select.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/select.h" 2 3 4
# 31 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/bits/sigset.h" 1 3 4
# 34 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4
# 45 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/time.h" 1 3 4
# 30 "/usr/include/x86_64-linux-gnu/bits/time.h" 3 4
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
# 46 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4


typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
# 64 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;
# 96 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4

# 106 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 118 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
# 131 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4

# 220 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 3 4


__extension__
extern unsigned int gnu_dev_major (unsigned long long int __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__
extern unsigned int gnu_dev_minor (unsigned long long int __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__
extern unsigned long long int gnu_dev_makedev (unsigned int __major,
            unsigned int __minor)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 58 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 3 4

# 223 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4





typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 273 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4

# 315 "/usr/include/stdlib.h" 2 3 4






extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));


extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));






extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));

extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));




extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));







extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;

  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));









extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;

extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;










extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));

extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));




extern void cfree (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));



# 1 "/usr/include/alloca.h" 1 3 4
# 24 "/usr/include/alloca.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 25 "/usr/include/alloca.h" 2 3 4







extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));






# 493 "/usr/include/stdlib.h" 2 3 4





extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;




extern void *aligned_alloc (size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (2))) ;




extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));





extern void quick_exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));







extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));






extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;

# 578 "/usr/include/stdlib.h" 3 4
extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));


extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));
# 606 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 619 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 641 "/usr/include/stdlib.h" 3 4
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
# 662 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 711 "/usr/include/stdlib.h" 3 4





extern int system (const char *__command) ;

# 733 "/usr/include/stdlib.h" 3 4
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) ;






typedef int (*__compar_fn_t) (const void *, const void *);
# 751 "/usr/include/stdlib.h" 3 4



extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;







extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
# 774 "/usr/include/stdlib.h" 3 4
extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;



__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;







extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;




__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;

# 811 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));






extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));

extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__));








extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 898 "/usr/include/stdlib.h" 3 4
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;
# 950 "/usr/include/stdlib.h" 3 4
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


# 1 "/usr/include/x86_64-linux-gnu/bits/stdlib-float.h" 1 3 4
# 955 "/usr/include/stdlib.h" 2 3 4
# 967 "/usr/include/stdlib.h" 3 4

# 63 "../../../server-code/src/char/char.c" 2




# 66 "../../../server-code/src/char/char.c"
char char_db[256] = "char";
char scdata_db[256] = "sc_data";
char cart_db[256] = "cart_inventory";
char inventory_db[256] = "inventory";
char charlog_db[256] = "charlog";
char storage_db[256] = "storage";
char interlog_db[256] = "interlog";
char skill_db[256] = "skill";
char memo_db[256] = "memo";
char guild_db[256] = "guild";
char guild_alliance_db[256] = "guild_alliance";
char guild_castle_db[256] = "guild_castle";
char guild_expulsion_db[256] = "guild_expulsion";
char guild_member_db[256] = "guild_member";
char guild_position_db[256] = "guild_position";
char guild_skill_db[256] = "guild_skill";
char guild_storage_db[256] = "guild_storage";
char party_db[256] = "party";
char pet_db[256] = "pet";
char mail_db[256] = "mail";
char auction_db[256] = "auction";
char friend_db[256] = "friends";
char hotkey_db[256] = "hotkey";
char quest_db[256] = "quest";
char homunculus_db[256] = "homunculus";
char skill_homunculus_db[256] = "skill_homunculus";
char mercenary_db[256] = "mercenary";
char mercenary_owner_db[256] = "mercenary_owner";
char ragsrvinfo_db[256] = "ragsrvinfo";
char elemental_db[256] = "elemental";
char account_data_db[256] = "account_data";
char acc_reg_num_db[32] = "acc_reg_num_db";
char acc_reg_str_db[32] = "acc_reg_str_db";
char char_reg_str_db[32] = "char_reg_str_db";
char char_reg_num_db[32] = "char_reg_num_db";

struct char_interface char_s;
struct char_interface *chr;


int save_log = 1;

char db_path[1024] = "db";

char wisp_server_name[(23 + 1)] = "Server";
char login_ip_str[128];
uint32 login_ip = 0;
uint16 login_port = 6900;
char char_ip_str[128];
char bind_ip_str[128];
uint32 bind_ip = INADDR_ANY;
int char_maintenance_min_group_id = 0;

# 118 "../../../server-code/src/char/char.c" 3 4
_Bool 
# 118 "../../../server-code/src/char/char.c"
    char_new = 
# 118 "../../../server-code/src/char/char.c" 3 4
               1
# 118 "../../../server-code/src/char/char.c"
                   ;


# 120 "../../../server-code/src/char/char.c" 3 4
_Bool 
# 120 "../../../server-code/src/char/char.c"
    name_ignoring_case = 
# 120 "../../../server-code/src/char/char.c" 3 4
                         0
# 120 "../../../server-code/src/char/char.c"
                              ;
int char_name_option = 0;
char unknown_char_name[(23 + 1)] = "Unknown";

char char_name_letters[1024] = "";

int char_del_level = 0;
int char_del_delay = 86400;

int log_char = 1;
int log_inter = 1;

int char_aegis_delete = 0;

int max_connect_user = -1;
int gm_allow_group = -1;
int autosave_interval = (300*1000);
int start_zeny = 0;
int start_items[32*3];
int guild_exp_rate = 100;


int fame_list_size_chemist = 10;
int fame_list_size_smith = 10;
int fame_list_size_taekwon = 10;


struct fame_list smith_fame_list[10];
struct fame_list chemist_fame_list[10];
struct fame_list taekwon_fame_list[10];



 struct point start_point = { 0, 97, 90 };




unsigned short skillid2idx[10015];






static struct DBMap *auth_db;
# 174 "../../../server-code/src/char/char.c"
static struct DBData char_create_online_char_data(union DBKey key, va_list args)
{
 struct online_char_data* character;
 ((character) = (struct online_char_data *) (iMalloc->calloc(((1)),(sizeof(struct online_char_data)),"../../../server-code/src/char/char.c", 177, __func__)));
 character->account_id = key.i;
 character->char_id = -1;
 character->server = -1;
 character->pincode_enable = -1;
 character->fd = -1;
 character->waiting_disconnect = (-1);
 return DB->ptr2data(character);
}

void char_set_account_online(int account_id)
{
 WFIFOHEAD(chr->login_fd,6);
 WFIFOW(chr->login_fd,0) = 0x272b;
 WFIFOL(chr->login_fd,2) = account_id;
 WFIFOSET(chr->login_fd,6);
}

void char_set_account_offline(int account_id)
{
 WFIFOHEAD(chr->login_fd,6);
 WFIFOW(chr->login_fd,0) = 0x272c;
 WFIFOL(chr->login_fd,2) = account_id;
 WFIFOSET(chr->login_fd,6);
}

void char_set_char_charselect(int account_id)
{
 struct online_char_data* character;

 character = (struct online_char_data*)( DB->data2ptr((chr->online_char_db)->ensure((chr->online_char_db),DB->i2key(account_id),(chr->create_online_char_data))) );

 if( character->server > -1 )
  if( chr->server[character->server].users > 0 )
   chr->server[character->server].users--;

 character->char_id = -1;
 character->server = -1;
 if(character->pincode_enable == -1)
  character->pincode_enable = pincode->charselect + pincode->enabled;

 if(character->waiting_disconnect != (-1)) {
  timer->delete(character->waiting_disconnect, chr->waiting_disconnect);
  character->waiting_disconnect = (-1);
 }

 if (chr->login_fd > 0 && !sockt->session[chr->login_fd]->flag.eof)
  chr->set_account_online(account_id);
}

void char_set_char_online(int map_id, int char_id, int account_id)
{
 struct online_char_data* character;
 struct mmo_charstatus *cp;


 if( (-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `online`='1' WHERE `char_id`='%d' LIMIT 1", char_db, char_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 234));


 character = (struct online_char_data*)( DB->data2ptr((chr->online_char_db)->ensure((chr->online_char_db),DB->i2key(account_id),(chr->create_online_char_data))) );
 if( character->char_id != -1 && character->server > -1 && character->server != map_id )
 {
  (showmsg->showNotice(("chr->set_char_online: Character %d:%d marked in map server %d, but map server %d claims to have (%d:%d) online!\n"), character->account_id, character->char_id, character->server, map_id, account_id, char_id))
                                                                                             ;
  mapif->disconnectplayer(chr->server[character->server].fd, character->account_id, character->char_id, 2);
 }


 character->char_id = char_id;
 character->server = map_id;

 if( character->server > -1 )
  chr->server[character->server].users++;


 if(character->waiting_disconnect != (-1)) {
  timer->delete(character->waiting_disconnect, chr->waiting_disconnect);
  character->waiting_disconnect = (-1);
 }


 cp = (struct mmo_charstatus*)( DB->data2ptr((chr->char_db_)->get((chr->char_db_),DB->i2key(char_id))) );
 inter_guild->CharOnline(char_id, cp?cp->guild_id:-1);


 if (chr->login_fd > 0 && !sockt->session[chr->login_fd]->flag.eof)
  chr->set_account_online(account_id);
}

void char_set_char_offline(int char_id, int account_id)
{
 struct online_char_data* character;

 if ( char_id == -1 )
 {
  if( (-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `online`='0' WHERE `account_id`='%d'", char_db, account_id) )
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 274));
 }
 else
 {
  struct mmo_charstatus* cp = (struct mmo_charstatus*)( DB->data2ptr((chr->char_db_)->get((chr->char_db_),DB->i2key(char_id))) );
  inter_guild->CharOffline(char_id, cp?cp->guild_id:-1);
  if (cp)
   ( (chr->char_db_)->remove((chr->char_db_),DB->i2key(char_id),
# 281 "../../../server-code/src/char/char.c" 3 4
  ((void *)0)
# 281 "../../../server-code/src/char/char.c"
  ) );

  if( (-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `online`='0' WHERE `char_id`='%d' LIMIT 1", char_db, char_id) )
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 284));
 }

 if ((character = (struct online_char_data*)( DB->data2ptr((chr->online_char_db)->get((chr->online_char_db),DB->i2key(account_id))) )) != 
# 287 "../../../server-code/src/char/char.c" 3 4
                                                                                        ((void *)0)
# 287 "../../../server-code/src/char/char.c"
                                                                                            ) {

  if( character->server > -1 )
   if( chr->server[character->server].users > 0 )
    chr->server[character->server].users--;

  if(character->waiting_disconnect != (-1)){
   timer->delete(character->waiting_disconnect, chr->waiting_disconnect);
   character->waiting_disconnect = (-1);
  }

  if(character->char_id == char_id)
  {
   character->char_id = -1;
   character->server = -1;
   character->pincode_enable = -1;
  }


 }


 if (chr->login_fd > 0 && !sockt->session[chr->login_fd]->flag.eof && (char_id == -1 || character == 
# 309 "../../../server-code/src/char/char.c" 3 4
                                                                                                    ((void *)0) 
# 309 "../../../server-code/src/char/char.c"
                                                                                                         || character->fd == -1))
  chr->set_account_offline(account_id);
}




static int char_db_setoffline(union DBKey key, struct DBData *data, va_list ap)
{
 struct online_char_data* character = (struct online_char_data*)DB->data2ptr(data);
 int server_id = 
# 319 "../../../server-code/src/char/char.c" 3 4
                __builtin_va_arg(
# 319 "../../../server-code/src/char/char.c"
                ap
# 319 "../../../server-code/src/char/char.c" 3 4
                ,
# 319 "../../../server-code/src/char/char.c"
                int
# 319 "../../../server-code/src/char/char.c" 3 4
                )
# 319 "../../../server-code/src/char/char.c"
                               ;
 do { if (((void)(character), 
# 320 "../../../server-code/src/char/char.c" 3 4
0
# 320 "../../../server-code/src/char/char.c"
)) return(0); } while(0);
 if (server_id == -1) {
  character->char_id = -1;
  character->server = -1;
  if(character->waiting_disconnect != (-1)){
   timer->delete(character->waiting_disconnect, chr->waiting_disconnect);
   character->waiting_disconnect = (-1);
  }
 } else if (character->server == server_id)
  character->server = -2;
 return 0;
}




static int char_db_kickoffline(union DBKey key, struct DBData *data, va_list ap)
{
 struct online_char_data* character = (struct online_char_data*)DB->data2ptr(data);
 int server_id = 
# 339 "../../../server-code/src/char/char.c" 3 4
                __builtin_va_arg(
# 339 "../../../server-code/src/char/char.c"
                ap
# 339 "../../../server-code/src/char/char.c" 3 4
                ,
# 339 "../../../server-code/src/char/char.c"
                int
# 339 "../../../server-code/src/char/char.c" 3 4
                )
# 339 "../../../server-code/src/char/char.c"
                               ;
 do { if (((void)(character), 
# 340 "../../../server-code/src/char/char.c" 3 4
0
# 340 "../../../server-code/src/char/char.c"
)) return(0); } while(0);

 if (server_id > -1 && character->server != server_id)
  return 0;


 if (character->server > -1 && character->server < 2)
  mapif->disconnectplayer(chr->server[character->server].fd, character->account_id, character->char_id, 1);
 else if (character->waiting_disconnect == (-1))
  chr->set_char_offline(character->char_id, character->account_id);
 else
  return 0;

 return 1;
}

void char_set_login_all_offline(void)
{

 WFIFOHEAD(chr->login_fd,2);
 WFIFOW(chr->login_fd,0) = 0x2737;
 WFIFOSET(chr->login_fd,2);
}

void char_set_all_offline(int id)
{
 if (id < 0)
  (showmsg->showNotice(("Sending all users offline.\n")));
 else
  (showmsg->showNotice(("Sending users of map-server %d offline.\n"),id));
 chr->online_char_db->foreach(chr->online_char_db,chr->db_kickoffline,id);

 if (id >= 0 || chr->login_fd <= 0 || sockt->session[chr->login_fd]->flag.eof)
  return;
 chr->set_login_all_offline();
}

void char_set_all_offline_sql(void)
{

 if( (-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `online` = '0'", char_db) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 381));
 if( (-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `online` = '0'", guild_member_db) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 383));
 if( (-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `connect_member` = '0'", guild_db) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 385));
}




static struct DBData char_create_charstatus(union DBKey key, va_list args)
{
 struct mmo_charstatus *cp;
 cp = (struct mmo_charstatus *) (iMalloc->calloc((1),(sizeof(struct mmo_charstatus)),"../../../server-code/src/char/char.c", 394, __func__));
 cp->char_id = key.i;
 return DB->ptr2data(cp);
}

int char_mmo_char_tosql(int char_id, struct mmo_charstatus* p)
{
 int i = 0;
 int count = 0;
 int diff = 0;
 char save_status[128];
 struct mmo_charstatus *cp;
 int errors = 0;
 StringBuf buf;

 do { if (((void)(p), 
# 409 "../../../server-code/src/char/char.c" 3 4
0
# 409 "../../../server-code/src/char/char.c"
)) return(0); } while(0);
 if (char_id != p->char_id) return 0;

 cp = ( DB->data2ptr((chr->char_db_)->ensure((chr->char_db_),DB->i2key(char_id),(chr->create_charstatus))) );

 StrBuf->Init(&buf);
 memset(save_status, 0, sizeof(save_status));


 if( memcmp(p->inventory, cp->inventory, sizeof(p->inventory)) ) {
  if (!chr->memitemdata_to_sql(p->inventory, 100, p->char_id, TABLE_INVENTORY))
   strcat(save_status, " inventory");
  else
   errors++;
 }


 if( memcmp(p->cart, cp->cart, sizeof(p->cart)) ) {
  if (!chr->memitemdata_to_sql(p->cart, 100, p->char_id, TABLE_CART))
   strcat(save_status, " cart");
  else
   errors++;
 }


 if( memcmp(p->storage.items, cp->storage.items, sizeof(p->storage.items)) ) {
  if (!chr->memitemdata_to_sql(p->storage.items, 600, p->account_id, TABLE_STORAGE))
   strcat(save_status, " storage");
  else
   errors++;
 }

 if (
  (p->base_exp != cp->base_exp) || (p->base_level != cp->base_level) ||
  (p->job_level != cp->job_level) || (p->job_exp != cp->job_exp) ||
  (p->zeny != cp->zeny) ||
  (p->last_point.map != cp->last_point.map) ||
  (p->last_point.x != cp->last_point.x) || (p->last_point.y != cp->last_point.y) ||
  (p->max_hp != cp->max_hp) || (p->hp != cp->hp) ||
  (p->max_sp != cp->max_sp) || (p->sp != cp->sp) ||
  (p->status_point != cp->status_point) || (p->skill_point != cp->skill_point) ||
  (p->str != cp->str) || (p->agi != cp->agi) || (p->vit != cp->vit) ||
  (p->int_ != cp->int_) || (p->dex != cp->dex) || (p->luk != cp->luk) ||
  (p->option != cp->option) ||
  (p->party_id != cp->party_id) || (p->guild_id != cp->guild_id) ||
  (p->pet_id != cp->pet_id) || (p->weapon != cp->weapon) || (p->hom_id != cp->hom_id) ||
  (p->ele_id != cp->ele_id) || (p->shield != cp->shield) || (p->head_top != cp->head_top) ||
  (p->head_mid != cp->head_mid) || (p->head_bottom != cp->head_bottom) || (p->delete_date != cp->delete_date) ||
  (p->rename != cp->rename) || (p->slotchange != cp->slotchange) || (p->robe != cp->robe) ||
  (p->show_equip != cp->show_equip) || (p->allow_party != cp->allow_party) || (p->font != cp->font) ||
  (p->uniqueitem_counter != cp->uniqueitem_counter) || (p->hotkey_rowshift != cp->hotkey_rowshift)
 ) {

  unsigned int opt = 0;

  if( p->allow_party )
   opt |= OPT_ALLOW_PARTY;
  if( p->show_equip )
   opt |= OPT_SHOW_EQUIP;

  if( (-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `base_level`='%u', `job_level`='%u',"
   "`base_exp`='%u', `job_exp`='%u', `zeny`='%d',"
   "`max_hp`='%d',`hp`='%d',`max_sp`='%d',`sp`='%d',`status_point`='%u',`skill_point`='%u',"
   "`str`='%d',`agi`='%d',`vit`='%d',`int`='%d',`dex`='%d',`luk`='%d',"
   "`option`='%u',`party_id`='%d',`guild_id`='%d',`pet_id`='%d',`homun_id`='%d',`elemental_id`='%d',"
   "`weapon`='%d',`shield`='%d',`head_top`='%d',`head_mid`='%d',`head_bottom`='%d',"
   "`last_map`='%s',`last_x`='%d',`last_y`='%d',`save_map`='%s',`save_x`='%d',`save_y`='%d', `rename`='%d',"
   "`delete_date`='%lu',`robe`='%d',`slotchange`='%d', `char_opt`='%u', `font`='%u', `uniqueitem_counter` ='%u',"
   "`hotkey_rowshift`='%d'"
   " WHERE  `account_id`='%d' AND `char_id` = '%d'",
   char_db, p->base_level, p->job_level,
   p->base_exp, p->job_exp, p->zeny,
   p->max_hp, p->hp, p->max_sp, p->sp, p->status_point, p->skill_point,
   p->str, p->agi, p->vit, p->int_, p->dex, p->luk,
   p->option, p->party_id, p->guild_id, p->pet_id, p->hom_id, p->ele_id,
   p->weapon, p->shield, p->head_top, p->head_mid, p->head_bottom,
   mapindex->id2name((p->last_point.map),"../../../server-code/src/char/char.c", 485, __func__), p->last_point.x, p->last_point.y,
   mapindex->id2name((p->save_point.map),"../../../server-code/src/char/char.c", 486, __func__), p->save_point.x, p->save_point.y, p->rename,
   (unsigned long)p->delete_date,
   p->robe,p->slotchange,opt,p->font,p->uniqueitem_counter,
   p->hotkey_rowshift,
   p->account_id, p->char_id) )
  {
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 492));
   errors++;
  } else
   strcat(save_status, " status");
 }

 if( p->bank_vault != cp->bank_vault || p->mod_exp != cp->mod_exp || p->mod_drop != cp->mod_drop || p->mod_death != cp->mod_death ) {
  if( (-1) == SQL->Query(inter->sql_handle, "REPLACE INTO `%s` (`account_id`,`bank_vault`,`base_exp`,`base_drop`,`base_death`) VALUES ('%d','%d','%d','%d','%d')",account_data_db,p->account_id,p->bank_vault,p->mod_exp,p->mod_drop,p->mod_death) ) {
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 500));
   errors++;
  } else
   strcat(save_status, " accdata");
 }


 if (
  (p->hair != cp->hair) || (p->hair_color != cp->hair_color) ||
  (p->clothes_color != cp->clothes_color) || (p->body != cp->body) ||
  (p->class_ != cp->class_) ||
  (p->partner_id != cp->partner_id) || (p->father != cp->father) ||
  (p->mother != cp->mother) || (p->child != cp->child) ||
  (p->karma != cp->karma) || (p->manner != cp->manner) ||
  (p->fame != cp->fame)
 )
 {
  if( (-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `class`='%d',"
   "`hair`='%d', `hair_color`='%d', `clothes_color`='%d', `body`='%d',"
   "`partner_id`='%d', `father`='%d', `mother`='%d', `child`='%d',"
   "`karma`='%d', `manner`='%d', `fame`='%d'"
   " WHERE  `account_id`='%d' AND `char_id` = '%d'",
   char_db, p->class_,
   p->hair, p->hair_color, p->clothes_color, p->body,
   p->partner_id, p->father, p->mother, p->child,
   p->karma, p->manner, p->fame,
   p->account_id, p->char_id) )
  {
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 528));
   errors++;
  } else
   strcat(save_status, " status2");
 }


 if( (p->mer_id != cp->mer_id) ||
  (p->arch_calls != cp->arch_calls) || (p->arch_faith != cp->arch_faith) ||
  (p->spear_calls != cp->spear_calls) || (p->spear_faith != cp->spear_faith) ||
  (p->sword_calls != cp->sword_calls) || (p->sword_faith != cp->sword_faith) )
 {
  if (inter_mercenary->owner_tosql(char_id, p))
   strcat(save_status, " mercenary");
  else
   errors++;
 }


 if( memcmp(p->memo_point, cp->memo_point, sizeof(p->memo_point)) )
 {
  char esc_mapname[(23 + 1)*2+1];


  if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `char_id`='%d'", memo_db, p->char_id) )
  {
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 554));
   errors++;
  }


  StrBuf->Clear(&buf);
  StrBuf->Printf(&buf, "INSERT INTO `%s`(`char_id`,`map`,`x`,`y`) VALUES ", memo_db);
  for( i = 0, count = 0; i < 3; ++i )
  {
   if( p->memo_point[i].map )
   {
    if( count )
     StrBuf->AppendStr(&buf, ",");
    SQL->EscapeString(inter->sql_handle, esc_mapname, mapindex->id2name((p->memo_point[i].map),"../../../server-code/src/char/char.c", 567, __func__));
    StrBuf->Printf(&buf, "('%d', '%s', '%d', '%d')", char_id, esc_mapname, p->memo_point[i].x, p->memo_point[i].y);
    ++count;
   }
  }
  if( count )
  {
   if( (-1) == SQL->QueryStr(inter->sql_handle, StrBuf->Value(&buf)) )
   {
    (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 576));
    errors++;
   }
  }
  strcat(save_status, " memo");
 }


 if( memcmp(p->skill, cp->skill, sizeof(p->skill)) ) {

  if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `char_id`='%d'", skill_db, p->char_id) ) {
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 587));
   errors++;
  }

  StrBuf->Clear(&buf);
  StrBuf->Printf(&buf, "INSERT INTO `%s`(`char_id`,`id`,`lv`,`flag`) VALUES ", skill_db);

  for( i = 0, count = 0; i < 1478; ++i ) {
   if( p->skill[i].id != 0 && p->skill[i].flag != SKILL_FLAG_TEMPORARY ) {
    if( p->skill[i].lv == 0 && ( p->skill[i].flag == SKILL_FLAG_PERM_GRANTED || p->skill[i].flag == SKILL_FLAG_PERMANENT ) )
     continue;
    if( p->skill[i].flag != SKILL_FLAG_PERMANENT && p->skill[i].flag != SKILL_FLAG_PERM_GRANTED && (p->skill[i].flag - SKILL_FLAG_REPLACED_LV_0) == 0 )
     continue;
    if( count )
     StrBuf->AppendStr(&buf, ",");
    StrBuf->Printf(&buf, "('%d','%d','%d','%d')", char_id, p->skill[i].id,
         ( (p->skill[i].flag == SKILL_FLAG_PERMANENT || p->skill[i].flag == SKILL_FLAG_PERM_GRANTED) ? p->skill[i].lv : p->skill[i].flag - SKILL_FLAG_REPLACED_LV_0),
         p->skill[i].flag == SKILL_FLAG_PERM_GRANTED ? p->skill[i].flag : 0);
    ++count;
   }
  }
  if( count )
  {
   if( (-1) == SQL->QueryStr(inter->sql_handle, StrBuf->Value(&buf)) )
   {
    (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 612));
    errors++;
   }
  }

  strcat(save_status, " skills");
 }

 diff = 0;
 for(i = 0; i < 40; i++){
  if(p->friends[i].char_id != cp->friends[i].char_id ||
   p->friends[i].account_id != cp->friends[i].account_id){
   diff = 1;
   break;
  }
 }

 if(diff == 1) {

  if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `char_id`='%d'", friend_db, char_id) )
  {
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 633));
   errors++;
  }

  StrBuf->Clear(&buf);
  StrBuf->Printf(&buf, "INSERT INTO `%s` (`char_id`, `friend_account`, `friend_id`) VALUES ", friend_db);
  for( i = 0, count = 0; i < 40; ++i )
  {
   if( p->friends[i].char_id > 0 )
   {
    if( count )
     StrBuf->AppendStr(&buf, ",");
    StrBuf->Printf(&buf, "('%d','%d','%d')", char_id, p->friends[i].account_id, p->friends[i].char_id);
    count++;
   }
  }
  if( count )
  {
   if( (-1) == SQL->QueryStr(inter->sql_handle, StrBuf->Value(&buf)) )
   {
    (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 653));
    errors++;
   }
  }
  strcat(save_status, " friends");
 }



 StrBuf->Clear(&buf);
 StrBuf->Printf(&buf, "REPLACE INTO `%s` (`char_id`, `hotkey`, `type`, `itemskill_id`, `skill_lvl`) VALUES ", hotkey_db);
 diff = 0;
 for(i = 0; i < ( (int)(sizeof(p->hotkeys)/sizeof((p->hotkeys)[0])) ); i++){
  if(memcmp(&p->hotkeys[i], &cp->hotkeys[i], sizeof(struct hotkey)))
  {
   if( diff )
    StrBuf->AppendStr(&buf, ",");
   StrBuf->Printf(&buf, "('%d','%u','%u','%u','%u')", char_id, (unsigned int)i, (unsigned int)p->hotkeys[i].type, p->hotkeys[i].id , (unsigned int)p->hotkeys[i].lv);
   diff = 1;
  }
 }
 if(diff) {
  if( (-1) == SQL->QueryStr(inter->sql_handle, StrBuf->Value(&buf)) )
  {
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 677));
   errors++;
  } else
   strcat(save_status, " hotkeys");
 }


 StrBuf->Destroy(&buf);
 if (save_status[0]!='\0' && save_log)
  (showmsg->showInfo(("Saved char %d - %s:%s.\n"), char_id, p->name, save_status));
 if (!errors)
  memcpy(cp, p, sizeof(struct mmo_charstatus));
 return 0;
}
# 702 "../../../server-code/src/char/char.c"
int char_memitemdata_to_sql(const struct item items[], int max, int id, int tableswitch)
{
 StringBuf buf;
 struct SqlStmt *stmt = 
# 705 "../../../server-code/src/char/char.c" 3 4
                       ((void *)0)
# 705 "../../../server-code/src/char/char.c"
                           ;
 int i, j;
 const char *tablename = 
# 707 "../../../server-code/src/char/char.c" 3 4
                        ((void *)0)
# 707 "../../../server-code/src/char/char.c"
                            ;
 const char *selectoption = 
# 708 "../../../server-code/src/char/char.c" 3 4
                           ((void *)0)
# 708 "../../../server-code/src/char/char.c"
                               ;
 
# 709 "../../../server-code/src/char/char.c" 3 4
_Bool 
# 709 "../../../server-code/src/char/char.c"
     has_favorite = 
# 709 "../../../server-code/src/char/char.c" 3 4
                    0
# 709 "../../../server-code/src/char/char.c"
                         ;
 struct item item = { 0 };
 
# 711 "../../../server-code/src/char/char.c" 3 4
_Bool 
# 711 "../../../server-code/src/char/char.c"
     *flag = 
# 711 "../../../server-code/src/char/char.c" 3 4
             ((void *)0)
# 711 "../../../server-code/src/char/char.c"
                 ;
 
# 712 "../../../server-code/src/char/char.c" 3 4
_Bool 
# 712 "../../../server-code/src/char/char.c"
     found;
 int errors = 0;

 do { if (((void)(items), 
# 715 "../../../server-code/src/char/char.c" 3 4
0
# 715 "../../../server-code/src/char/char.c"
)) return(0); } while(0);

 switch (tableswitch) {
 case TABLE_INVENTORY: tablename = inventory_db; selectoption = "char_id"; has_favorite = 
# 718 "../../../server-code/src/char/char.c" 3 4
                                                                                                    1
# 718 "../../../server-code/src/char/char.c"
                                                                                                        ; break;
 case TABLE_CART: tablename = cart_db; selectoption = "char_id"; break;
 case TABLE_STORAGE: tablename = storage_db; selectoption = "account_id"; break;
 case TABLE_GUILD_STORAGE: tablename = guild_storage_db; selectoption = "guild_id"; break;
 default:
  (showmsg->showError(("Invalid table name!\n")));
  do { if (( (tableswitch) ? 
# 724 "../../../server-code/src/char/char.c" 3 4
 0 
# 724 "../../../server-code/src/char/char.c"
 : (nullpo->assert_report("../../../server-code/src/char/char.c", 724, __func__, "tableswitch", "failed assertion"), 
# 724 "../../../server-code/src/char/char.c" 3 4
 1
# 724 "../../../server-code/src/char/char.c"
 ) )) return(1); } while(0);
 }






 StrBuf->Init(&buf);
 StrBuf->AppendStr(&buf, "SELECT `id`, `nameid`, `amount`, `equip`, `identify`, `refine`, `attribute`, `expire_time`, `bound`, `unique_id`");
 for (j = 0; j < 4; ++j)
  StrBuf->Printf(&buf, ", `card%d`", j);
 if (has_favorite)
  StrBuf->AppendStr(&buf, ", `favorite`");
 StrBuf->Printf(&buf, " FROM `%s` WHERE `%s`='%d'", tablename, selectoption, id);

 stmt = SQL->StmtMalloc(inter->sql_handle);
 if ((-1) == SQL->StmtPrepareStr(stmt, StrBuf->Value(&buf))
  || (-1) == SQL->StmtExecute(stmt)) {
  (SQL->StmtShowDebug_((stmt), "../../../server-code/src/char/char.c", 743));
  SQL->StmtFree(stmt);
  StrBuf->Destroy(&buf);
  return 1;
 }

 SQL->StmtBindColumn(stmt, 0, SQLDT_INT, &item.id, 0, 
# 749 "../../../server-code/src/char/char.c" 3 4
                                                                    ((void *)0)
# 749 "../../../server-code/src/char/char.c"
                                                                        , 
# 749 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 749 "../../../server-code/src/char/char.c"
                                                                              );
 SQL->StmtBindColumn(stmt, 1, SQLDT_SHORT, &item.nameid, 0, 
# 750 "../../../server-code/src/char/char.c" 3 4
                                                                    ((void *)0)
# 750 "../../../server-code/src/char/char.c"
                                                                        , 
# 750 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 750 "../../../server-code/src/char/char.c"
                                                                              );
 SQL->StmtBindColumn(stmt, 2, SQLDT_SHORT, &item.amount, 0, 
# 751 "../../../server-code/src/char/char.c" 3 4
                                                                    ((void *)0)
# 751 "../../../server-code/src/char/char.c"
                                                                        , 
# 751 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 751 "../../../server-code/src/char/char.c"
                                                                              );
 SQL->StmtBindColumn(stmt, 3, SQLDT_UINT, &item.equip, 0, 
# 752 "../../../server-code/src/char/char.c" 3 4
                                                                    ((void *)0)
# 752 "../../../server-code/src/char/char.c"
                                                                        , 
# 752 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 752 "../../../server-code/src/char/char.c"
                                                                              );
 SQL->StmtBindColumn(stmt, 4, SQLDT_CHAR, &item.identify, 0, 
# 753 "../../../server-code/src/char/char.c" 3 4
                                                                    ((void *)0)
# 753 "../../../server-code/src/char/char.c"
                                                                        , 
# 753 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 753 "../../../server-code/src/char/char.c"
                                                                              );
 SQL->StmtBindColumn(stmt, 5, SQLDT_CHAR, &item.refine, 0, 
# 754 "../../../server-code/src/char/char.c" 3 4
                                                                    ((void *)0)
# 754 "../../../server-code/src/char/char.c"
                                                                        , 
# 754 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 754 "../../../server-code/src/char/char.c"
                                                                              );
 SQL->StmtBindColumn(stmt, 6, SQLDT_CHAR, &item.attribute, 0, 
# 755 "../../../server-code/src/char/char.c" 3 4
                                                                    ((void *)0)
# 755 "../../../server-code/src/char/char.c"
                                                                        , 
# 755 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 755 "../../../server-code/src/char/char.c"
                                                                              );
 SQL->StmtBindColumn(stmt, 7, SQLDT_UINT, &item.expire_time, 0, 
# 756 "../../../server-code/src/char/char.c" 3 4
                                                                    ((void *)0)
# 756 "../../../server-code/src/char/char.c"
                                                                        , 
# 756 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 756 "../../../server-code/src/char/char.c"
                                                                              );
 SQL->StmtBindColumn(stmt, 8, SQLDT_UCHAR, &item.bound, 0, 
# 757 "../../../server-code/src/char/char.c" 3 4
                                                                    ((void *)0)
# 757 "../../../server-code/src/char/char.c"
                                                                        , 
# 757 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 757 "../../../server-code/src/char/char.c"
                                                                              );
 SQL->StmtBindColumn(stmt, 9, SQLDT_UINT64, &item.unique_id, 0, 
# 758 "../../../server-code/src/char/char.c" 3 4
                                                                    ((void *)0)
# 758 "../../../server-code/src/char/char.c"
                                                                        , 
# 758 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 758 "../../../server-code/src/char/char.c"
                                                                              );
 for (j = 0; j < 4; ++j)
  SQL->StmtBindColumn(stmt, 10+j, SQLDT_SHORT, &item.card[j], 0, 
# 760 "../../../server-code/src/char/char.c" 3 4
                                                                ((void *)0)
# 760 "../../../server-code/src/char/char.c"
                                                                    , 
# 760 "../../../server-code/src/char/char.c" 3 4
                                                                      ((void *)0)
# 760 "../../../server-code/src/char/char.c"
                                                                          );
 if (has_favorite)
  SQL->StmtBindColumn(stmt, 10+4, SQLDT_UCHAR, &item.favorite, 0, 
# 762 "../../../server-code/src/char/char.c" 3 4
                                                                         ((void *)0)
# 762 "../../../server-code/src/char/char.c"
                                                                             , 
# 762 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 762 "../../../server-code/src/char/char.c"
                                                                                   );


 flag = (iMalloc->calloc((max),(sizeof(
# 765 "../../../server-code/src/char/char.c" 3 4
       _Bool
# 765 "../../../server-code/src/char/char.c"
       )),"../../../server-code/src/char/char.c", 765, __func__));

 while (0 == SQL->StmtNextRow(stmt)) {
  found = 
# 768 "../../../server-code/src/char/char.c" 3 4
         0
# 768 "../../../server-code/src/char/char.c"
              ;

  for (i = 0; i < max; ++i) {

   if (items[i].nameid == 0 || flag[i])
    continue;

   if (items[i].nameid == item.nameid
    && items[i].unique_id == item.unique_id
    && items[i].card[0] == item.card[0]
    && items[i].card[2] == item.card[2]
    && items[i].card[3] == item.card[3]
   ) {

    do { for ((j) = (0); (j) < (4); ++(j)) if (items[i].card[j] != item.card[j]) break; } while(
# 782 "../../../server-code/src/char/char.c" 3 4
   0
# 782 "../../../server-code/src/char/char.c"
   );
    if (j == 4
     && items[i].amount == item.amount
     && items[i].equip == item.equip
     && items[i].identify == item.identify
     && items[i].refine == item.refine
     && items[i].attribute == item.attribute
     && items[i].expire_time == item.expire_time
     && items[i].bound == item.bound
     && (!has_favorite || items[i].favorite == item.favorite)
    ) {
     ;
    } else {

     StrBuf->Clear(&buf);
     StrBuf->Printf(&buf, "UPDATE `%s` SET `amount`='%d', `equip`='%u', `identify`='%d', `refine`='%d',`attribute`='%d', `expire_time`='%u', `bound`='%d'",
      tablename, items[i].amount, items[i].equip, items[i].identify, items[i].refine, items[i].attribute, items[i].expire_time, items[i].bound);
     for (j = 0; j < 4; ++j)
      StrBuf->Printf(&buf, ", `card%d`=%d", j, items[i].card[j]);
     if (has_favorite)
      StrBuf->Printf(&buf, ", `favorite`='%d'", items[i].favorite);
     StrBuf->Printf(&buf, " WHERE `id`='%d' LIMIT 1", item.id);

     if ((-1) == SQL->QueryStr(inter->sql_handle, StrBuf->Value(&buf))) {
      (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 806));
      errors++;
     }
    }

    found = flag[i] = 
# 811 "../../../server-code/src/char/char.c" 3 4
                     1
# 811 "../../../server-code/src/char/char.c"
                         ;
    break;
   }
  }
  if (!found) {

   if ((-1) == SQL->Query(inter->sql_handle, "DELETE from `%s` where `id`='%d' LIMIT 1", tablename, item.id)) {
    (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 818));
    errors++;
   }
  }
 }
 SQL->StmtFree(stmt);

 StrBuf->Clear(&buf);
 StrBuf->Printf(&buf, "INSERT INTO `%s`(`%s`, `nameid`, `amount`, `equip`, `identify`, `refine`, `attribute`, `expire_time`, `bound`, `unique_id`", tablename, selectoption);
 for (j = 0; j < 4; ++j)
  StrBuf->Printf(&buf, ", `card%d`", j);
 if (has_favorite)
  StrBuf->AppendStr(&buf, ", `favorite`");
 StrBuf->AppendStr(&buf, ") VALUES ");

 found = 
# 833 "../../../server-code/src/char/char.c" 3 4
        0
# 833 "../../../server-code/src/char/char.c"
             ;

 for (i = 0; i < max; ++i) {

  if (items[i].nameid == 0 || flag[i])
   continue;

  if (found)
   StrBuf->AppendStr(&buf, ",");
  else
   found = 
# 843 "../../../server-code/src/char/char.c" 3 4
          1
# 843 "../../../server-code/src/char/char.c"
              ;

  StrBuf->Printf(&buf, "('%d', '%d', '%d', '%u', '%d', '%d', '%d', '%u', '%d', '%"
# 845 "../../../server-code/src/char/char.c" 3 4
                                                                                 "l" "u"
# 845 "../../../server-code/src/char/char.c"
                                                                                       "'",
   id, items[i].nameid, items[i].amount, items[i].equip, items[i].identify, items[i].refine, items[i].attribute, items[i].expire_time, items[i].bound, items[i].unique_id);
  for (j = 0; j < 4; ++j)
   StrBuf->Printf(&buf, ", '%d'", items[i].card[j]);
  if (has_favorite)
   StrBuf->Printf(&buf, ", '%d'", items[i].favorite);
  StrBuf->AppendStr(&buf, ")");
 }

 if (found && (-1) == SQL->QueryStr(inter->sql_handle, StrBuf->Value(&buf))) {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 855));
  errors++;
 }

 StrBuf->Destroy(&buf);
 (iMalloc->free((flag),"../../../server-code/src/char/char.c", 860, __func__));

 return errors;
}
# 878 "../../../server-code/src/char/char.c"
int char_mmo_gender(const struct char_session_data *sd, const struct mmo_charstatus *p, char sex)
{

 (void)sd; (void)p;
 switch (sex) {
  case 'M':
   return SEX_MALE;
  case 'F':
   return SEX_FEMALE;
  case 'U':
  default:
   return 99;
 }
# 912 "../../../server-code/src/char/char.c"
}



int char_mmo_chars_fromsql(struct char_session_data* sd, uint8* buf)
{
 struct SqlStmt *stmt;
 struct mmo_charstatus p;
 int j = 0, i;
 char last_map[((11 + 1) + 4)];
 time_t unban_time = 0;
 char sex[2];

 do { if (((void)(sd), 
# 925 "../../../server-code/src/char/char.c" 3 4
0
# 925 "../../../server-code/src/char/char.c"
)) return(0); } while(0);
 do { if (((void)(buf), 
# 926 "../../../server-code/src/char/char.c" 3 4
0
# 926 "../../../server-code/src/char/char.c"
)) return(0); } while(0);

 stmt = SQL->StmtMalloc(inter->sql_handle);
 if( stmt == 
# 929 "../../../server-code/src/char/char.c" 3 4
            ((void *)0) 
# 929 "../../../server-code/src/char/char.c"
                 ) {
  (SQL->StmtShowDebug_((stmt), "../../../server-code/src/char/char.c", 930));
  return 0;
 }
 memset(&p, 0, sizeof(p));

 for(i = 0 ; i < 9; i++ ) {
  sd->found_char[i] = -1;
  sd->unban_time[i] = 0;
 }


 if ((-1) == SQL->StmtPrepare(stmt, "SELECT "
  "`char_id`,`char_num`,`name`,`class`,`base_level`,`job_level`,`base_exp`,`job_exp`,`zeny`,"
  "`str`,`agi`,`vit`,`int`,`dex`,`luk`,`max_hp`,`hp`,`max_sp`,`sp`,"
  "`status_point`,`skill_point`,`option`,`karma`,`manner`,`hair`,`hair_color`,"
  "`clothes_color`,`body`,`weapon`,`shield`,`head_top`,`head_mid`,`head_bottom`,`last_map`,`rename`,`delete_date`,"
  "`robe`,`slotchange`,`unban_time`,`sex`"
  " FROM `%s` WHERE `account_id`='%d' AND `char_num` < '%d'", char_db, sd->account_id, 9)
  || (-1) == SQL->StmtExecute(stmt)
  || (-1) == SQL->StmtBindColumn(stmt, 0, SQLDT_INT, &p.char_id, 0, 
# 949 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 949 "../../../server-code/src/char/char.c"
                                                                                , 
# 949 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 949 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 1, SQLDT_UCHAR, &p.slot, 0, 
# 950 "../../../server-code/src/char/char.c" 3 4
                                                                         ((void *)0)
# 950 "../../../server-code/src/char/char.c"
                                                                             , 
# 950 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 950 "../../../server-code/src/char/char.c"
                                                                                   )
  || (-1) == SQL->StmtBindColumn(stmt, 2, SQLDT_STRING, &p.name, sizeof(p.name), 
# 951 "../../../server-code/src/char/char.c" 3 4
                                                                                      ((void *)0)
# 951 "../../../server-code/src/char/char.c"
                                                                                          , 
# 951 "../../../server-code/src/char/char.c" 3 4
                                                                                            ((void *)0)
# 951 "../../../server-code/src/char/char.c"
                                                                                                )
  || (-1) == SQL->StmtBindColumn(stmt, 3, SQLDT_SHORT, &p.class_, 0, 
# 952 "../../../server-code/src/char/char.c" 3 4
                                                                           ((void *)0)
# 952 "../../../server-code/src/char/char.c"
                                                                               , 
# 952 "../../../server-code/src/char/char.c" 3 4
                                                                                 ((void *)0)
# 952 "../../../server-code/src/char/char.c"
                                                                                     )
  || (-1) == SQL->StmtBindColumn(stmt, 4, SQLDT_UINT, &p.base_level, 0, 
# 953 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 953 "../../../server-code/src/char/char.c"
                                                                                   , 
# 953 "../../../server-code/src/char/char.c" 3 4
                                                                                     ((void *)0)
# 953 "../../../server-code/src/char/char.c"
                                                                                         )
  || (-1) == SQL->StmtBindColumn(stmt, 5, SQLDT_UINT, &p.job_level, 0, 
# 954 "../../../server-code/src/char/char.c" 3 4
                                                                              ((void *)0)
# 954 "../../../server-code/src/char/char.c"
                                                                                  , 
# 954 "../../../server-code/src/char/char.c" 3 4
                                                                                    ((void *)0)
# 954 "../../../server-code/src/char/char.c"
                                                                                        )
  || (-1) == SQL->StmtBindColumn(stmt, 6, SQLDT_UINT, &p.base_exp, 0, 
# 955 "../../../server-code/src/char/char.c" 3 4
                                                                             ((void *)0)
# 955 "../../../server-code/src/char/char.c"
                                                                                 , 
# 955 "../../../server-code/src/char/char.c" 3 4
                                                                                   ((void *)0)
# 955 "../../../server-code/src/char/char.c"
                                                                                       )
  || (-1) == SQL->StmtBindColumn(stmt, 7, SQLDT_UINT, &p.job_exp, 0, 
# 956 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 956 "../../../server-code/src/char/char.c"
                                                                                , 
# 956 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 956 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 8, SQLDT_INT, &p.zeny, 0, 
# 957 "../../../server-code/src/char/char.c" 3 4
                                                                         ((void *)0)
# 957 "../../../server-code/src/char/char.c"
                                                                             , 
# 957 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 957 "../../../server-code/src/char/char.c"
                                                                                   )
  || (-1) == SQL->StmtBindColumn(stmt, 9, SQLDT_SHORT, &p.str, 0, 
# 958 "../../../server-code/src/char/char.c" 3 4
                                                                        ((void *)0)
# 958 "../../../server-code/src/char/char.c"
                                                                            , 
# 958 "../../../server-code/src/char/char.c" 3 4
                                                                              ((void *)0)
# 958 "../../../server-code/src/char/char.c"
                                                                                  )
  || (-1) == SQL->StmtBindColumn(stmt, 10, SQLDT_SHORT, &p.agi, 0, 
# 959 "../../../server-code/src/char/char.c" 3 4
                                                                        ((void *)0)
# 959 "../../../server-code/src/char/char.c"
                                                                            , 
# 959 "../../../server-code/src/char/char.c" 3 4
                                                                              ((void *)0)
# 959 "../../../server-code/src/char/char.c"
                                                                                  )
  || (-1) == SQL->StmtBindColumn(stmt, 11, SQLDT_SHORT, &p.vit, 0, 
# 960 "../../../server-code/src/char/char.c" 3 4
                                                                        ((void *)0)
# 960 "../../../server-code/src/char/char.c"
                                                                            , 
# 960 "../../../server-code/src/char/char.c" 3 4
                                                                              ((void *)0)
# 960 "../../../server-code/src/char/char.c"
                                                                                  )
  || (-1) == SQL->StmtBindColumn(stmt, 12, SQLDT_SHORT, &p.int_, 0, 
# 961 "../../../server-code/src/char/char.c" 3 4
                                                                         ((void *)0)
# 961 "../../../server-code/src/char/char.c"
                                                                             , 
# 961 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 961 "../../../server-code/src/char/char.c"
                                                                                   )
  || (-1) == SQL->StmtBindColumn(stmt, 13, SQLDT_SHORT, &p.dex, 0, 
# 962 "../../../server-code/src/char/char.c" 3 4
                                                                        ((void *)0)
# 962 "../../../server-code/src/char/char.c"
                                                                            , 
# 962 "../../../server-code/src/char/char.c" 3 4
                                                                              ((void *)0)
# 962 "../../../server-code/src/char/char.c"
                                                                                  )
  || (-1) == SQL->StmtBindColumn(stmt, 14, SQLDT_SHORT, &p.luk, 0, 
# 963 "../../../server-code/src/char/char.c" 3 4
                                                                        ((void *)0)
# 963 "../../../server-code/src/char/char.c"
                                                                            , 
# 963 "../../../server-code/src/char/char.c" 3 4
                                                                              ((void *)0)
# 963 "../../../server-code/src/char/char.c"
                                                                                  )
  || (-1) == SQL->StmtBindColumn(stmt, 15, SQLDT_INT, &p.max_hp, 0, 
# 964 "../../../server-code/src/char/char.c" 3 4
                                                                           ((void *)0)
# 964 "../../../server-code/src/char/char.c"
                                                                               , 
# 964 "../../../server-code/src/char/char.c" 3 4
                                                                                 ((void *)0)
# 964 "../../../server-code/src/char/char.c"
                                                                                     )
  || (-1) == SQL->StmtBindColumn(stmt, 16, SQLDT_INT, &p.hp, 0, 
# 965 "../../../server-code/src/char/char.c" 3 4
                                                                       ((void *)0)
# 965 "../../../server-code/src/char/char.c"
                                                                           , 
# 965 "../../../server-code/src/char/char.c" 3 4
                                                                             ((void *)0)
# 965 "../../../server-code/src/char/char.c"
                                                                                 )
  || (-1) == SQL->StmtBindColumn(stmt, 17, SQLDT_INT, &p.max_sp, 0, 
# 966 "../../../server-code/src/char/char.c" 3 4
                                                                           ((void *)0)
# 966 "../../../server-code/src/char/char.c"
                                                                               , 
# 966 "../../../server-code/src/char/char.c" 3 4
                                                                                 ((void *)0)
# 966 "../../../server-code/src/char/char.c"
                                                                                     )
  || (-1) == SQL->StmtBindColumn(stmt, 18, SQLDT_INT, &p.sp, 0, 
# 967 "../../../server-code/src/char/char.c" 3 4
                                                                       ((void *)0)
# 967 "../../../server-code/src/char/char.c"
                                                                           , 
# 967 "../../../server-code/src/char/char.c" 3 4
                                                                             ((void *)0)
# 967 "../../../server-code/src/char/char.c"
                                                                                 )
  || (-1) == SQL->StmtBindColumn(stmt, 19, SQLDT_UINT, &p.status_point, 0, 
# 968 "../../../server-code/src/char/char.c" 3 4
                                                                                 ((void *)0)
# 968 "../../../server-code/src/char/char.c"
                                                                                     , 
# 968 "../../../server-code/src/char/char.c" 3 4
                                                                                       ((void *)0)
# 968 "../../../server-code/src/char/char.c"
                                                                                           )
  || (-1) == SQL->StmtBindColumn(stmt, 20, SQLDT_UINT, &p.skill_point, 0, 
# 969 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 969 "../../../server-code/src/char/char.c"
                                                                                    , 
# 969 "../../../server-code/src/char/char.c" 3 4
                                                                                      ((void *)0)
# 969 "../../../server-code/src/char/char.c"
                                                                                          )
  || (-1) == SQL->StmtBindColumn(stmt, 21, SQLDT_UINT, &p.option, 0, 
# 970 "../../../server-code/src/char/char.c" 3 4
                                                                           ((void *)0)
# 970 "../../../server-code/src/char/char.c"
                                                                               , 
# 970 "../../../server-code/src/char/char.c" 3 4
                                                                                 ((void *)0)
# 970 "../../../server-code/src/char/char.c"
                                                                                     )
  || (-1) == SQL->StmtBindColumn(stmt, 22, SQLDT_UCHAR, &p.karma, 0, 
# 971 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 971 "../../../server-code/src/char/char.c"
                                                                              , 
# 971 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 971 "../../../server-code/src/char/char.c"
                                                                                    )
  || (-1) == SQL->StmtBindColumn(stmt, 23, SQLDT_SHORT, &p.manner, 0, 
# 972 "../../../server-code/src/char/char.c" 3 4
                                                                           ((void *)0)
# 972 "../../../server-code/src/char/char.c"
                                                                               , 
# 972 "../../../server-code/src/char/char.c" 3 4
                                                                                 ((void *)0)
# 972 "../../../server-code/src/char/char.c"
                                                                                     )
  || (-1) == SQL->StmtBindColumn(stmt, 24, SQLDT_SHORT, &p.hair, 0, 
# 973 "../../../server-code/src/char/char.c" 3 4
                                                                         ((void *)0)
# 973 "../../../server-code/src/char/char.c"
                                                                             , 
# 973 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 973 "../../../server-code/src/char/char.c"
                                                                                   )
  || (-1) == SQL->StmtBindColumn(stmt, 25, SQLDT_SHORT, &p.hair_color, 0, 
# 974 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 974 "../../../server-code/src/char/char.c"
                                                                                   , 
# 974 "../../../server-code/src/char/char.c" 3 4
                                                                                     ((void *)0)
# 974 "../../../server-code/src/char/char.c"
                                                                                         )
  || (-1) == SQL->StmtBindColumn(stmt, 26, SQLDT_SHORT, &p.clothes_color, 0, 
# 975 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 975 "../../../server-code/src/char/char.c"
                                                                                      , 
# 975 "../../../server-code/src/char/char.c" 3 4
                                                                                        ((void *)0)
# 975 "../../../server-code/src/char/char.c"
                                                                                            )
  || (-1) == SQL->StmtBindColumn(stmt, 27, SQLDT_SHORT, &p.body, 0, 
# 976 "../../../server-code/src/char/char.c" 3 4
                                                                         ((void *)0)
# 976 "../../../server-code/src/char/char.c"
                                                                             , 
# 976 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 976 "../../../server-code/src/char/char.c"
                                                                                   )
  || (-1) == SQL->StmtBindColumn(stmt, 28, SQLDT_SHORT, &p.weapon, 0, 
# 977 "../../../server-code/src/char/char.c" 3 4
                                                                           ((void *)0)
# 977 "../../../server-code/src/char/char.c"
                                                                               , 
# 977 "../../../server-code/src/char/char.c" 3 4
                                                                                 ((void *)0)
# 977 "../../../server-code/src/char/char.c"
                                                                                     )
  || (-1) == SQL->StmtBindColumn(stmt, 29, SQLDT_SHORT, &p.shield, 0, 
# 978 "../../../server-code/src/char/char.c" 3 4
                                                                           ((void *)0)
# 978 "../../../server-code/src/char/char.c"
                                                                               , 
# 978 "../../../server-code/src/char/char.c" 3 4
                                                                                 ((void *)0)
# 978 "../../../server-code/src/char/char.c"
                                                                                     )
  || (-1) == SQL->StmtBindColumn(stmt, 30, SQLDT_SHORT, &p.head_top, 0, 
# 979 "../../../server-code/src/char/char.c" 3 4
                                                                             ((void *)0)
# 979 "../../../server-code/src/char/char.c"
                                                                                 , 
# 979 "../../../server-code/src/char/char.c" 3 4
                                                                                   ((void *)0)
# 979 "../../../server-code/src/char/char.c"
                                                                                       )
  || (-1) == SQL->StmtBindColumn(stmt, 31, SQLDT_SHORT, &p.head_mid, 0, 
# 980 "../../../server-code/src/char/char.c" 3 4
                                                                             ((void *)0)
# 980 "../../../server-code/src/char/char.c"
                                                                                 , 
# 980 "../../../server-code/src/char/char.c" 3 4
                                                                                   ((void *)0)
# 980 "../../../server-code/src/char/char.c"
                                                                                       )
  || (-1) == SQL->StmtBindColumn(stmt, 32, SQLDT_SHORT, &p.head_bottom, 0, 
# 981 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 981 "../../../server-code/src/char/char.c"
                                                                                    , 
# 981 "../../../server-code/src/char/char.c" 3 4
                                                                                      ((void *)0)
# 981 "../../../server-code/src/char/char.c"
                                                                                          )
  || (-1) == SQL->StmtBindColumn(stmt, 33, SQLDT_STRING, &last_map, sizeof(last_map), 
# 982 "../../../server-code/src/char/char.c" 3 4
                                                                                          ((void *)0)
# 982 "../../../server-code/src/char/char.c"
                                                                                              , 
# 982 "../../../server-code/src/char/char.c" 3 4
                                                                                                ((void *)0)
# 982 "../../../server-code/src/char/char.c"
                                                                                                    )
  || (-1) == SQL->StmtBindColumn(stmt, 34, SQLDT_USHORT, &p.rename, 0, 
# 983 "../../../server-code/src/char/char.c" 3 4
                                                                           ((void *)0)
# 983 "../../../server-code/src/char/char.c"
                                                                               , 
# 983 "../../../server-code/src/char/char.c" 3 4
                                                                                 ((void *)0)
# 983 "../../../server-code/src/char/char.c"
                                                                                     )
  || (-1) == SQL->StmtBindColumn(stmt, 35, SQLDT_UINT32, &p.delete_date, 0, 
# 984 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 984 "../../../server-code/src/char/char.c"
                                                                                    , 
# 984 "../../../server-code/src/char/char.c" 3 4
                                                                                      ((void *)0)
# 984 "../../../server-code/src/char/char.c"
                                                                                          )
  || (-1) == SQL->StmtBindColumn(stmt, 36, SQLDT_SHORT, &p.robe, 0, 
# 985 "../../../server-code/src/char/char.c" 3 4
                                                                         ((void *)0)
# 985 "../../../server-code/src/char/char.c"
                                                                             , 
# 985 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 985 "../../../server-code/src/char/char.c"
                                                                                   )
  || (-1) == SQL->StmtBindColumn(stmt, 37, SQLDT_USHORT, &p.slotchange, 0, 
# 986 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 986 "../../../server-code/src/char/char.c"
                                                                                   , 
# 986 "../../../server-code/src/char/char.c" 3 4
                                                                                     ((void *)0)
# 986 "../../../server-code/src/char/char.c"
                                                                                         )
  || (-1) == SQL->StmtBindColumn(stmt, 38, SQLDT_LONG, &unban_time, 0, 
# 987 "../../../server-code/src/char/char.c" 3 4
                                                                             ((void *)0)
# 987 "../../../server-code/src/char/char.c"
                                                                                 , 
# 987 "../../../server-code/src/char/char.c" 3 4
                                                                                   ((void *)0)
# 987 "../../../server-code/src/char/char.c"
                                                                                       )
  || (-1) == SQL->StmtBindColumn(stmt, 39, SQLDT_ENUM, &sex, sizeof(sex), 
# 988 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 988 "../../../server-code/src/char/char.c"
                                                                                    , 
# 988 "../../../server-code/src/char/char.c" 3 4
                                                                                      ((void *)0)
# 988 "../../../server-code/src/char/char.c"
                                                                                          )
 ) {
  (SQL->StmtShowDebug_((stmt), "../../../server-code/src/char/char.c", 990));
  SQL->StmtFree(stmt);
  return 0;
 }

 for( i = 0; i < 9 && 0 == SQL->StmtNextRow(stmt); i++ ) {
  if (p.slot >= 9)
   continue;
  p.last_point.map = mapindex->name2id(last_map);
  sd->found_char[p.slot] = p.char_id;
  sd->unban_time[p.slot] = unban_time;
  p.sex = chr->mmo_gender(sd, &p, sex[0]);
  j += chr->mmo_char_tobuf(WBUFP(buf, j), &p);
 }

 memset(sd->new_name,0,sizeof(sd->new_name));

 SQL->StmtFree(stmt);
 return j;
}


int char_mmo_char_fromsql(int char_id, struct mmo_charstatus* p, 
# 1012 "../../../server-code/src/char/char.c" 3 4
                                                                _Bool 
# 1012 "../../../server-code/src/char/char.c"
                                                                     load_everything)
{
 int i,j;
 char t_msg[128] = "";
 struct mmo_charstatus* cp;
 StringBuf buf;
 struct SqlStmt *stmt;
 char last_map[((11 + 1) + 4)];
 char save_map[((11 + 1) + 4)];
 char point_map[((11 + 1) + 4)];
 struct point tmp_point;
 struct item tmp_item;
 struct s_skill tmp_skill;
 struct s_friend tmp_friend;

 struct hotkey tmp_hotkey;
 int hotkey_num = 0;

 unsigned int opt;
 int account_id;
 char sex[2];

 do { if (((void)(p), 
# 1034 "../../../server-code/src/char/char.c" 3 4
0
# 1034 "../../../server-code/src/char/char.c"
)) return(0); } while(0);

 memset(p, 0, sizeof(struct mmo_charstatus));

 if (save_log) (showmsg->showInfo(("Char load request (%d)\n"), char_id));

 stmt = SQL->StmtMalloc(inter->sql_handle);
 if( stmt == 
# 1041 "../../../server-code/src/char/char.c" 3 4
            ((void *)0) 
# 1041 "../../../server-code/src/char/char.c"
                 )
 {
  (SQL->StmtShowDebug_((stmt), "../../../server-code/src/char/char.c", 1043));
  return 0;
 }


 if ((-1) == SQL->StmtPrepare(stmt, "SELECT "
  "`char_id`,`account_id`,`char_num`,`name`,`class`,`base_level`,`job_level`,`base_exp`,`job_exp`,`zeny`,"
  "`str`,`agi`,`vit`,`int`,`dex`,`luk`,`max_hp`,`hp`,`max_sp`,`sp`,"
  "`status_point`,`skill_point`,`option`,`karma`,`manner`,`party_id`,`guild_id`,`pet_id`,`homun_id`,`elemental_id`,`hair`,"
  "`hair_color`,`clothes_color`,`body`,`weapon`,`shield`,`head_top`,`head_mid`,`head_bottom`,`last_map`,`last_x`,`last_y`,"
  "`save_map`,`save_x`,`save_y`,`partner_id`,`father`,`mother`,`child`,`fame`,`rename`,`delete_date`,`robe`,`slotchange`,"
  "`char_opt`,`font`,`uniqueitem_counter`,`sex`,`hotkey_rowshift`"
  " FROM `%s` WHERE `char_id`=? LIMIT 1", char_db)
  || (-1) == SQL->StmtBindParam(stmt, 0, SQLDT_INT, &char_id, 0)
  || (-1) == SQL->StmtExecute(stmt)
  || (-1) == SQL->StmtBindColumn(stmt, 0, SQLDT_INT, &p->char_id, 0, 
# 1058 "../../../server-code/src/char/char.c" 3 4
                                                                             ((void *)0)
# 1058 "../../../server-code/src/char/char.c"
                                                                                 , 
# 1058 "../../../server-code/src/char/char.c" 3 4
                                                                                   ((void *)0)
# 1058 "../../../server-code/src/char/char.c"
                                                                                       )
  || (-1) == SQL->StmtBindColumn(stmt, 1, SQLDT_INT, &p->account_id, 0, 
# 1059 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 1059 "../../../server-code/src/char/char.c"
                                                                                    , 
# 1059 "../../../server-code/src/char/char.c" 3 4
                                                                                      ((void *)0)
# 1059 "../../../server-code/src/char/char.c"
                                                                                          )
  || (-1) == SQL->StmtBindColumn(stmt, 2, SQLDT_UCHAR, &p->slot, 0, 
# 1060 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 1060 "../../../server-code/src/char/char.c"
                                                                              , 
# 1060 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 1060 "../../../server-code/src/char/char.c"
                                                                                    )
  || (-1) == SQL->StmtBindColumn(stmt, 3, SQLDT_STRING, &p->name, sizeof(p->name), 
# 1061 "../../../server-code/src/char/char.c" 3 4
                                                                                        ((void *)0)
# 1061 "../../../server-code/src/char/char.c"
                                                                                            , 
# 1061 "../../../server-code/src/char/char.c" 3 4
                                                                                              ((void *)0)
# 1061 "../../../server-code/src/char/char.c"
                                                                                                  )
  || (-1) == SQL->StmtBindColumn(stmt, 4, SQLDT_SHORT, &p->class_, 0, 
# 1062 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 1062 "../../../server-code/src/char/char.c"
                                                                                , 
# 1062 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1062 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 5, SQLDT_UINT, &p->base_level, 0, 
# 1063 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 1063 "../../../server-code/src/char/char.c"
                                                                                    , 
# 1063 "../../../server-code/src/char/char.c" 3 4
                                                                                      ((void *)0)
# 1063 "../../../server-code/src/char/char.c"
                                                                                          )
  || (-1) == SQL->StmtBindColumn(stmt, 6, SQLDT_UINT, &p->job_level, 0, 
# 1064 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 1064 "../../../server-code/src/char/char.c"
                                                                                   , 
# 1064 "../../../server-code/src/char/char.c" 3 4
                                                                                     ((void *)0)
# 1064 "../../../server-code/src/char/char.c"
                                                                                         )
  || (-1) == SQL->StmtBindColumn(stmt, 7, SQLDT_UINT, &p->base_exp, 0, 
# 1065 "../../../server-code/src/char/char.c" 3 4
                                                                              ((void *)0)
# 1065 "../../../server-code/src/char/char.c"
                                                                                  , 
# 1065 "../../../server-code/src/char/char.c" 3 4
                                                                                    ((void *)0)
# 1065 "../../../server-code/src/char/char.c"
                                                                                        )
  || (-1) == SQL->StmtBindColumn(stmt, 8, SQLDT_UINT, &p->job_exp, 0, 
# 1066 "../../../server-code/src/char/char.c" 3 4
                                                                             ((void *)0)
# 1066 "../../../server-code/src/char/char.c"
                                                                                 , 
# 1066 "../../../server-code/src/char/char.c" 3 4
                                                                                   ((void *)0)
# 1066 "../../../server-code/src/char/char.c"
                                                                                       )
  || (-1) == SQL->StmtBindColumn(stmt, 9, SQLDT_INT, &p->zeny, 0, 
# 1067 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 1067 "../../../server-code/src/char/char.c"
                                                                              , 
# 1067 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 1067 "../../../server-code/src/char/char.c"
                                                                                    )
  || (-1) == SQL->StmtBindColumn(stmt, 10, SQLDT_SHORT, &p->str, 0, 
# 1068 "../../../server-code/src/char/char.c" 3 4
                                                                         ((void *)0)
# 1068 "../../../server-code/src/char/char.c"
                                                                             , 
# 1068 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 1068 "../../../server-code/src/char/char.c"
                                                                                   )
  || (-1) == SQL->StmtBindColumn(stmt, 11, SQLDT_SHORT, &p->agi, 0, 
# 1069 "../../../server-code/src/char/char.c" 3 4
                                                                         ((void *)0)
# 1069 "../../../server-code/src/char/char.c"
                                                                             , 
# 1069 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 1069 "../../../server-code/src/char/char.c"
                                                                                   )
  || (-1) == SQL->StmtBindColumn(stmt, 12, SQLDT_SHORT, &p->vit, 0, 
# 1070 "../../../server-code/src/char/char.c" 3 4
                                                                         ((void *)0)
# 1070 "../../../server-code/src/char/char.c"
                                                                             , 
# 1070 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 1070 "../../../server-code/src/char/char.c"
                                                                                   )
  || (-1) == SQL->StmtBindColumn(stmt, 13, SQLDT_SHORT, &p->int_, 0, 
# 1071 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 1071 "../../../server-code/src/char/char.c"
                                                                              , 
# 1071 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 1071 "../../../server-code/src/char/char.c"
                                                                                    )
  || (-1) == SQL->StmtBindColumn(stmt, 14, SQLDT_SHORT, &p->dex, 0, 
# 1072 "../../../server-code/src/char/char.c" 3 4
                                                                         ((void *)0)
# 1072 "../../../server-code/src/char/char.c"
                                                                             , 
# 1072 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 1072 "../../../server-code/src/char/char.c"
                                                                                   )
  || (-1) == SQL->StmtBindColumn(stmt, 15, SQLDT_SHORT, &p->luk, 0, 
# 1073 "../../../server-code/src/char/char.c" 3 4
                                                                         ((void *)0)
# 1073 "../../../server-code/src/char/char.c"
                                                                             , 
# 1073 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 1073 "../../../server-code/src/char/char.c"
                                                                                   )
  || (-1) == SQL->StmtBindColumn(stmt, 16, SQLDT_INT, &p->max_hp, 0, 
# 1074 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 1074 "../../../server-code/src/char/char.c"
                                                                                , 
# 1074 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1074 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 17, SQLDT_INT, &p->hp, 0, 
# 1075 "../../../server-code/src/char/char.c" 3 4
                                                                        ((void *)0)
# 1075 "../../../server-code/src/char/char.c"
                                                                            , 
# 1075 "../../../server-code/src/char/char.c" 3 4
                                                                              ((void *)0)
# 1075 "../../../server-code/src/char/char.c"
                                                                                  )
  || (-1) == SQL->StmtBindColumn(stmt, 18, SQLDT_INT, &p->max_sp, 0, 
# 1076 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 1076 "../../../server-code/src/char/char.c"
                                                                                , 
# 1076 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1076 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 19, SQLDT_INT, &p->sp, 0, 
# 1077 "../../../server-code/src/char/char.c" 3 4
                                                                        ((void *)0)
# 1077 "../../../server-code/src/char/char.c"
                                                                            , 
# 1077 "../../../server-code/src/char/char.c" 3 4
                                                                              ((void *)0)
# 1077 "../../../server-code/src/char/char.c"
                                                                                  )
  || (-1) == SQL->StmtBindColumn(stmt, 20, SQLDT_UINT, &p->status_point, 0, 
# 1078 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1078 "../../../server-code/src/char/char.c"
                                                                                      , 
# 1078 "../../../server-code/src/char/char.c" 3 4
                                                                                        ((void *)0)
# 1078 "../../../server-code/src/char/char.c"
                                                                                            )
  || (-1) == SQL->StmtBindColumn(stmt, 21, SQLDT_UINT, &p->skill_point, 0, 
# 1079 "../../../server-code/src/char/char.c" 3 4
                                                                                 ((void *)0)
# 1079 "../../../server-code/src/char/char.c"
                                                                                     , 
# 1079 "../../../server-code/src/char/char.c" 3 4
                                                                                       ((void *)0)
# 1079 "../../../server-code/src/char/char.c"
                                                                                           )
  || (-1) == SQL->StmtBindColumn(stmt, 22, SQLDT_UINT, &p->option, 0, 
# 1080 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 1080 "../../../server-code/src/char/char.c"
                                                                                , 
# 1080 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1080 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 23, SQLDT_UCHAR, &p->karma, 0, 
# 1081 "../../../server-code/src/char/char.c" 3 4
                                                                           ((void *)0)
# 1081 "../../../server-code/src/char/char.c"
                                                                               , 
# 1081 "../../../server-code/src/char/char.c" 3 4
                                                                                 ((void *)0)
# 1081 "../../../server-code/src/char/char.c"
                                                                                     )
  || (-1) == SQL->StmtBindColumn(stmt, 24, SQLDT_SHORT, &p->manner, 0, 
# 1082 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 1082 "../../../server-code/src/char/char.c"
                                                                                , 
# 1082 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1082 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 25, SQLDT_INT, &p->party_id, 0, 
# 1083 "../../../server-code/src/char/char.c" 3 4
                                                                              ((void *)0)
# 1083 "../../../server-code/src/char/char.c"
                                                                                  , 
# 1083 "../../../server-code/src/char/char.c" 3 4
                                                                                    ((void *)0)
# 1083 "../../../server-code/src/char/char.c"
                                                                                        )
  || (-1) == SQL->StmtBindColumn(stmt, 26, SQLDT_INT, &p->guild_id, 0, 
# 1084 "../../../server-code/src/char/char.c" 3 4
                                                                              ((void *)0)
# 1084 "../../../server-code/src/char/char.c"
                                                                                  , 
# 1084 "../../../server-code/src/char/char.c" 3 4
                                                                                    ((void *)0)
# 1084 "../../../server-code/src/char/char.c"
                                                                                        )
  || (-1) == SQL->StmtBindColumn(stmt, 27, SQLDT_INT, &p->pet_id, 0, 
# 1085 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 1085 "../../../server-code/src/char/char.c"
                                                                                , 
# 1085 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1085 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 28, SQLDT_INT, &p->hom_id, 0, 
# 1086 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 1086 "../../../server-code/src/char/char.c"
                                                                                , 
# 1086 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1086 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 29, SQLDT_INT, &p->ele_id, 0, 
# 1087 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 1087 "../../../server-code/src/char/char.c"
                                                                                , 
# 1087 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1087 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 30, SQLDT_SHORT, &p->hair, 0, 
# 1088 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 1088 "../../../server-code/src/char/char.c"
                                                                              , 
# 1088 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 1088 "../../../server-code/src/char/char.c"
                                                                                    )
  || (-1) == SQL->StmtBindColumn(stmt, 31, SQLDT_SHORT, &p->hair_color, 0, 
# 1089 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 1089 "../../../server-code/src/char/char.c"
                                                                                    , 
# 1089 "../../../server-code/src/char/char.c" 3 4
                                                                                      ((void *)0)
# 1089 "../../../server-code/src/char/char.c"
                                                                                          )
  || (-1) == SQL->StmtBindColumn(stmt, 32, SQLDT_SHORT, &p->clothes_color, 0, 
# 1090 "../../../server-code/src/char/char.c" 3 4
                                                                                   ((void *)0)
# 1090 "../../../server-code/src/char/char.c"
                                                                                       , 
# 1090 "../../../server-code/src/char/char.c" 3 4
                                                                                         ((void *)0)
# 1090 "../../../server-code/src/char/char.c"
                                                                                             )
  || (-1) == SQL->StmtBindColumn(stmt, 33, SQLDT_SHORT, &p->body, 0, 
# 1091 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 1091 "../../../server-code/src/char/char.c"
                                                                              , 
# 1091 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 1091 "../../../server-code/src/char/char.c"
                                                                                    )
  || (-1) == SQL->StmtBindColumn(stmt, 34, SQLDT_SHORT, &p->weapon, 0, 
# 1092 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 1092 "../../../server-code/src/char/char.c"
                                                                                , 
# 1092 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1092 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 35, SQLDT_SHORT, &p->shield, 0, 
# 1093 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 1093 "../../../server-code/src/char/char.c"
                                                                                , 
# 1093 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1093 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 36, SQLDT_SHORT, &p->head_top, 0, 
# 1094 "../../../server-code/src/char/char.c" 3 4
                                                                              ((void *)0)
# 1094 "../../../server-code/src/char/char.c"
                                                                                  , 
# 1094 "../../../server-code/src/char/char.c" 3 4
                                                                                    ((void *)0)
# 1094 "../../../server-code/src/char/char.c"
                                                                                        )
  || (-1) == SQL->StmtBindColumn(stmt, 37, SQLDT_SHORT, &p->head_mid, 0, 
# 1095 "../../../server-code/src/char/char.c" 3 4
                                                                              ((void *)0)
# 1095 "../../../server-code/src/char/char.c"
                                                                                  , 
# 1095 "../../../server-code/src/char/char.c" 3 4
                                                                                    ((void *)0)
# 1095 "../../../server-code/src/char/char.c"
                                                                                        )
  || (-1) == SQL->StmtBindColumn(stmt, 38, SQLDT_SHORT, &p->head_bottom, 0, 
# 1096 "../../../server-code/src/char/char.c" 3 4
                                                                                 ((void *)0)
# 1096 "../../../server-code/src/char/char.c"
                                                                                     , 
# 1096 "../../../server-code/src/char/char.c" 3 4
                                                                                       ((void *)0)
# 1096 "../../../server-code/src/char/char.c"
                                                                                           )
  || (-1) == SQL->StmtBindColumn(stmt, 39, SQLDT_STRING, &last_map, sizeof(last_map), 
# 1097 "../../../server-code/src/char/char.c" 3 4
                                                                                          ((void *)0)
# 1097 "../../../server-code/src/char/char.c"
                                                                                              , 
# 1097 "../../../server-code/src/char/char.c" 3 4
                                                                                                ((void *)0)
# 1097 "../../../server-code/src/char/char.c"
                                                                                                    )
  || (-1) == SQL->StmtBindColumn(stmt, 40, SQLDT_SHORT, &p->last_point.x, 0, 
# 1098 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1098 "../../../server-code/src/char/char.c"
                                                                                      , 
# 1098 "../../../server-code/src/char/char.c" 3 4
                                                                                        ((void *)0)
# 1098 "../../../server-code/src/char/char.c"
                                                                                            )
  || (-1) == SQL->StmtBindColumn(stmt, 41, SQLDT_SHORT, &p->last_point.y, 0, 
# 1099 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1099 "../../../server-code/src/char/char.c"
                                                                                      , 
# 1099 "../../../server-code/src/char/char.c" 3 4
                                                                                        ((void *)0)
# 1099 "../../../server-code/src/char/char.c"
                                                                                            )
  || (-1) == SQL->StmtBindColumn(stmt, 42, SQLDT_STRING, &save_map, sizeof(save_map), 
# 1100 "../../../server-code/src/char/char.c" 3 4
                                                                                          ((void *)0)
# 1100 "../../../server-code/src/char/char.c"
                                                                                              , 
# 1100 "../../../server-code/src/char/char.c" 3 4
                                                                                                ((void *)0)
# 1100 "../../../server-code/src/char/char.c"
                                                                                                    )
  || (-1) == SQL->StmtBindColumn(stmt, 43, SQLDT_SHORT, &p->save_point.x, 0, 
# 1101 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1101 "../../../server-code/src/char/char.c"
                                                                                      , 
# 1101 "../../../server-code/src/char/char.c" 3 4
                                                                                        ((void *)0)
# 1101 "../../../server-code/src/char/char.c"
                                                                                            )
  || (-1) == SQL->StmtBindColumn(stmt, 44, SQLDT_SHORT, &p->save_point.y, 0, 
# 1102 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1102 "../../../server-code/src/char/char.c"
                                                                                      , 
# 1102 "../../../server-code/src/char/char.c" 3 4
                                                                                        ((void *)0)
# 1102 "../../../server-code/src/char/char.c"
                                                                                            )
  || (-1) == SQL->StmtBindColumn(stmt, 45, SQLDT_INT, &p->partner_id, 0, 
# 1103 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 1103 "../../../server-code/src/char/char.c"
                                                                                    , 
# 1103 "../../../server-code/src/char/char.c" 3 4
                                                                                      ((void *)0)
# 1103 "../../../server-code/src/char/char.c"
                                                                                          )
  || (-1) == SQL->StmtBindColumn(stmt, 46, SQLDT_INT, &p->father, 0, 
# 1104 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 1104 "../../../server-code/src/char/char.c"
                                                                                , 
# 1104 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1104 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 47, SQLDT_INT, &p->mother, 0, 
# 1105 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 1105 "../../../server-code/src/char/char.c"
                                                                                , 
# 1105 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1105 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 48, SQLDT_INT, &p->child, 0, 
# 1106 "../../../server-code/src/char/char.c" 3 4
                                                                           ((void *)0)
# 1106 "../../../server-code/src/char/char.c"
                                                                               , 
# 1106 "../../../server-code/src/char/char.c" 3 4
                                                                                 ((void *)0)
# 1106 "../../../server-code/src/char/char.c"
                                                                                     )
  || (-1) == SQL->StmtBindColumn(stmt, 49, SQLDT_INT, &p->fame, 0, 
# 1107 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 1107 "../../../server-code/src/char/char.c"
                                                                              , 
# 1107 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 1107 "../../../server-code/src/char/char.c"
                                                                                    )
  || (-1) == SQL->StmtBindColumn(stmt, 50, SQLDT_USHORT, &p->rename, 0, 
# 1108 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 1108 "../../../server-code/src/char/char.c"
                                                                                , 
# 1108 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1108 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 51, SQLDT_UINT32, &p->delete_date, 0, 
# 1109 "../../../server-code/src/char/char.c" 3 4
                                                                                 ((void *)0)
# 1109 "../../../server-code/src/char/char.c"
                                                                                     , 
# 1109 "../../../server-code/src/char/char.c" 3 4
                                                                                       ((void *)0)
# 1109 "../../../server-code/src/char/char.c"
                                                                                           )
  || (-1) == SQL->StmtBindColumn(stmt, 52, SQLDT_SHORT, &p->robe, 0, 
# 1110 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 1110 "../../../server-code/src/char/char.c"
                                                                              , 
# 1110 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 1110 "../../../server-code/src/char/char.c"
                                                                                    )
  || (-1) == SQL->StmtBindColumn(stmt, 53, SQLDT_USHORT, &p->slotchange, 0, 
# 1111 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 1111 "../../../server-code/src/char/char.c"
                                                                                    , 
# 1111 "../../../server-code/src/char/char.c" 3 4
                                                                                      ((void *)0)
# 1111 "../../../server-code/src/char/char.c"
                                                                                          )
  || (-1) == SQL->StmtBindColumn(stmt, 54, SQLDT_UINT, &opt, 0, 
# 1112 "../../../server-code/src/char/char.c" 3 4
                                                                      ((void *)0)
# 1112 "../../../server-code/src/char/char.c"
                                                                          , 
# 1112 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 1112 "../../../server-code/src/char/char.c"
                                                                                )
  || (-1) == SQL->StmtBindColumn(stmt, 55, SQLDT_UCHAR, &p->font, 0, 
# 1113 "../../../server-code/src/char/char.c" 3 4
                                                                          ((void *)0)
# 1113 "../../../server-code/src/char/char.c"
                                                                              , 
# 1113 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 1113 "../../../server-code/src/char/char.c"
                                                                                    )
  || (-1) == SQL->StmtBindColumn(stmt, 56, SQLDT_UINT, &p->uniqueitem_counter, 0, 
# 1114 "../../../server-code/src/char/char.c" 3 4
                                                                                        ((void *)0)
# 1114 "../../../server-code/src/char/char.c"
                                                                                            , 
# 1114 "../../../server-code/src/char/char.c" 3 4
                                                                                              ((void *)0)
# 1114 "../../../server-code/src/char/char.c"
                                                                                                  )
  || (-1) == SQL->StmtBindColumn(stmt, 57, SQLDT_ENUM, &sex, sizeof(sex), 
# 1115 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 1115 "../../../server-code/src/char/char.c"
                                                                                    , 
# 1115 "../../../server-code/src/char/char.c" 3 4
                                                                                      ((void *)0)
# 1115 "../../../server-code/src/char/char.c"
                                                                                          )
  || (-1) == SQL->StmtBindColumn(stmt, 58, SQLDT_UCHAR, &p->hotkey_rowshift, 0, 
# 1116 "../../../server-code/src/char/char.c" 3 4
                                                                                     ((void *)0)
# 1116 "../../../server-code/src/char/char.c"
                                                                                         , 
# 1116 "../../../server-code/src/char/char.c" 3 4
                                                                                           ((void *)0)
# 1116 "../../../server-code/src/char/char.c"
                                                                                               )
 ) {
  (SQL->StmtShowDebug_((stmt), "../../../server-code/src/char/char.c", 1118));
  SQL->StmtFree(stmt);
  return 0;
 }
 if (0 != SQL->StmtNextRow(stmt))
 {
  (showmsg->showError(("Requested non-existant character id: %d!\n"), char_id));
  SQL->StmtFree(stmt);
  return 0;
 }

 p->sex = chr->mmo_gender(
# 1129 "../../../server-code/src/char/char.c" 3 4
                         ((void *)0)
# 1129 "../../../server-code/src/char/char.c"
                             , p, sex[0]);

 account_id = p->account_id;

 p->last_point.map = mapindex->name2id(last_map);
 p->save_point.map = mapindex->name2id(save_map);

 if( p->last_point.map == 0 ) {
  p->last_point.map = (unsigned short)( DB->data2i((mapindex->db)->get((mapindex->db),DB->str2key(mapindex->default_map))) );
  p->last_point.x = mapindex->default_x;
  p->last_point.y = mapindex->default_y;
 }

 if( p->save_point.map == 0 ) {
  p->save_point.map = (unsigned short)( DB->data2i((mapindex->db)->get((mapindex->db),DB->str2key(mapindex->default_map))) );
  p->save_point.x = mapindex->default_x;
  p->save_point.y = mapindex->default_y;
 }

 strcat(t_msg, " status");

 if (!load_everything)
 {
  SQL->StmtFree(stmt);
  return 1;
 }



 memset(&tmp_point, 0, sizeof(tmp_point));
 if ((-1) == SQL->StmtPrepare(stmt, "SELECT `map`,`x`,`y` FROM `%s` WHERE `char_id`=? ORDER by `memo_id` LIMIT %d", memo_db, 3)
  || (-1) == SQL->StmtBindParam(stmt, 0, SQLDT_INT, &char_id, 0)
  || (-1) == SQL->StmtExecute(stmt)
  || (-1) == SQL->StmtBindColumn(stmt, 0, SQLDT_STRING, &point_map, sizeof(point_map), 
# 1162 "../../../server-code/src/char/char.c" 3 4
                                                                                           ((void *)0)
# 1162 "../../../server-code/src/char/char.c"
                                                                                               , 
# 1162 "../../../server-code/src/char/char.c" 3 4
                                                                                                 ((void *)0)
# 1162 "../../../server-code/src/char/char.c"
                                                                                                     )
  || (-1) == SQL->StmtBindColumn(stmt, 1, SQLDT_SHORT, &tmp_point.x, 0, 
# 1163 "../../../server-code/src/char/char.c" 3 4
                                                                             ((void *)0)
# 1163 "../../../server-code/src/char/char.c"
                                                                                 , 
# 1163 "../../../server-code/src/char/char.c" 3 4
                                                                                   ((void *)0)
# 1163 "../../../server-code/src/char/char.c"
                                                                                       )
  || (-1) == SQL->StmtBindColumn(stmt, 2, SQLDT_SHORT, &tmp_point.y, 0, 
# 1164 "../../../server-code/src/char/char.c" 3 4
                                                                             ((void *)0)
# 1164 "../../../server-code/src/char/char.c"
                                                                                 , 
# 1164 "../../../server-code/src/char/char.c" 3 4
                                                                                   ((void *)0)
# 1164 "../../../server-code/src/char/char.c"
                                                                                       )
 )
  (SQL->StmtShowDebug_((stmt), "../../../server-code/src/char/char.c", 1166));

 for( i = 0; i < 3 && 0 == SQL->StmtNextRow(stmt); ++i ) {
  tmp_point.map = mapindex->name2id(point_map);
  memcpy(&p->memo_point[i], &tmp_point, sizeof(tmp_point));
 }
 strcat(t_msg, " memo");



 StrBuf->Init(&buf);
 StrBuf->AppendStr(&buf, "SELECT `id`, `nameid`, `amount`, `equip`, `identify`, `refine`, `attribute`, `expire_time`, `favorite`, `bound`, `unique_id`");
 for( i = 0; i < 4; ++i )
  StrBuf->Printf(&buf, ", `card%d`", i);
 StrBuf->Printf(&buf, " FROM `%s` WHERE `char_id`=? LIMIT %d", inventory_db, 100);

 memset(&tmp_item, 0, sizeof(tmp_item));
 if ((-1) == SQL->StmtPrepareStr(stmt, StrBuf->Value(&buf))
  || (-1) == SQL->StmtBindParam(stmt, 0, SQLDT_INT, &char_id, 0)
  || (-1) == SQL->StmtExecute(stmt)
  || (-1) == SQL->StmtBindColumn(stmt, 0, SQLDT_INT, &tmp_item.id, 0, 
# 1186 "../../../server-code/src/char/char.c" 3 4
                                                                                 ((void *)0)
# 1186 "../../../server-code/src/char/char.c"
                                                                                     , 
# 1186 "../../../server-code/src/char/char.c" 3 4
                                                                                       ((void *)0)
# 1186 "../../../server-code/src/char/char.c"
                                                                                           )
  || (-1) == SQL->StmtBindColumn(stmt, 1, SQLDT_SHORT, &tmp_item.nameid, 0, 
# 1187 "../../../server-code/src/char/char.c" 3 4
                                                                                     ((void *)0)
# 1187 "../../../server-code/src/char/char.c"
                                                                                         , 
# 1187 "../../../server-code/src/char/char.c" 3 4
                                                                                           ((void *)0)
# 1187 "../../../server-code/src/char/char.c"
                                                                                               )
  || (-1) == SQL->StmtBindColumn(stmt, 2, SQLDT_SHORT, &tmp_item.amount, 0, 
# 1188 "../../../server-code/src/char/char.c" 3 4
                                                                                     ((void *)0)
# 1188 "../../../server-code/src/char/char.c"
                                                                                         , 
# 1188 "../../../server-code/src/char/char.c" 3 4
                                                                                           ((void *)0)
# 1188 "../../../server-code/src/char/char.c"
                                                                                               )
  || (-1) == SQL->StmtBindColumn(stmt, 3, SQLDT_UINT, &tmp_item.equip, 0, 
# 1189 "../../../server-code/src/char/char.c" 3 4
                                                                                    ((void *)0)
# 1189 "../../../server-code/src/char/char.c"
                                                                                        , 
# 1189 "../../../server-code/src/char/char.c" 3 4
                                                                                          ((void *)0)
# 1189 "../../../server-code/src/char/char.c"
                                                                                              )
  || (-1) == SQL->StmtBindColumn(stmt, 4, SQLDT_CHAR, &tmp_item.identify, 0, 
# 1190 "../../../server-code/src/char/char.c" 3 4
                                                                                       ((void *)0)
# 1190 "../../../server-code/src/char/char.c"
                                                                                           , 
# 1190 "../../../server-code/src/char/char.c" 3 4
                                                                                             ((void *)0)
# 1190 "../../../server-code/src/char/char.c"
                                                                                                 )
  || (-1) == SQL->StmtBindColumn(stmt, 5, SQLDT_CHAR, &tmp_item.refine, 0, 
# 1191 "../../../server-code/src/char/char.c" 3 4
                                                                                     ((void *)0)
# 1191 "../../../server-code/src/char/char.c"
                                                                                         , 
# 1191 "../../../server-code/src/char/char.c" 3 4
                                                                                           ((void *)0)
# 1191 "../../../server-code/src/char/char.c"
                                                                                               )
  || (-1) == SQL->StmtBindColumn(stmt, 6, SQLDT_CHAR, &tmp_item.attribute, 0, 
# 1192 "../../../server-code/src/char/char.c" 3 4
                                                                                        ((void *)0)
# 1192 "../../../server-code/src/char/char.c"
                                                                                            , 
# 1192 "../../../server-code/src/char/char.c" 3 4
                                                                                              ((void *)0)
# 1192 "../../../server-code/src/char/char.c"
                                                                                                  )
  || (-1) == SQL->StmtBindColumn(stmt, 7, SQLDT_UINT, &tmp_item.expire_time, 0, 
# 1193 "../../../server-code/src/char/char.c" 3 4
                                                                                          ((void *)0)
# 1193 "../../../server-code/src/char/char.c"
                                                                                              , 
# 1193 "../../../server-code/src/char/char.c" 3 4
                                                                                                ((void *)0)
# 1193 "../../../server-code/src/char/char.c"
                                                                                                    )
  || (-1) == SQL->StmtBindColumn(stmt, 8, SQLDT_CHAR, &tmp_item.favorite, 0, 
# 1194 "../../../server-code/src/char/char.c" 3 4
                                                                                       ((void *)0)
# 1194 "../../../server-code/src/char/char.c"
                                                                                           , 
# 1194 "../../../server-code/src/char/char.c" 3 4
                                                                                             ((void *)0)
# 1194 "../../../server-code/src/char/char.c"
                                                                                                 )
  || (-1) == SQL->StmtBindColumn(stmt, 9, SQLDT_UCHAR, &tmp_item.bound, 0, 
# 1195 "../../../server-code/src/char/char.c" 3 4
                                                                                    ((void *)0)
# 1195 "../../../server-code/src/char/char.c"
                                                                                        , 
# 1195 "../../../server-code/src/char/char.c" 3 4
                                                                                          ((void *)0)
# 1195 "../../../server-code/src/char/char.c"
                                                                                              )
  || (-1) == SQL->StmtBindColumn(stmt, 10, SQLDT_UINT64, &tmp_item.unique_id, 0, 
# 1196 "../../../server-code/src/char/char.c" 3 4
                                                                                        ((void *)0)
# 1196 "../../../server-code/src/char/char.c"
                                                                                            , 
# 1196 "../../../server-code/src/char/char.c" 3 4
                                                                                              ((void *)0)
# 1196 "../../../server-code/src/char/char.c"
                                                                                                  )
 )
  (SQL->StmtShowDebug_((stmt), "../../../server-code/src/char/char.c", 1198));
 for( i = 0; i < 4; ++i )
  if( (-1) == SQL->StmtBindColumn(stmt, 11+i, SQLDT_SHORT, &tmp_item.card[i], 0, 
# 1200 "../../../server-code/src/char/char.c" 3 4
                                                                                     ((void *)0)
# 1200 "../../../server-code/src/char/char.c"
                                                                                         , 
# 1200 "../../../server-code/src/char/char.c" 3 4
                                                                                           ((void *)0)
# 1200 "../../../server-code/src/char/char.c"
                                                                                               ) )
   (SQL->StmtShowDebug_((stmt), "../../../server-code/src/char/char.c", 1201));

 for( i = 0; i < 100 && 0 == SQL->StmtNextRow(stmt); ++i )
  memcpy(&p->inventory[i], &tmp_item, sizeof(tmp_item));

 strcat(t_msg, " inventory");



 StrBuf->Clear(&buf);
 StrBuf->AppendStr(&buf, "SELECT `id`, `nameid`, `amount`, `equip`, `identify`, `refine`, `attribute`, `expire_time`, `bound`, `unique_id`");
 for( j = 0; j < 4; ++j )
  StrBuf->Printf(&buf, ", `card%d`", j);
 StrBuf->Printf(&buf, " FROM `%s` WHERE `char_id`=? LIMIT %d", cart_db, 100);

 memset(&tmp_item, 0, sizeof(tmp_item));
 if ((-1) == SQL->StmtPrepareStr(stmt, StrBuf->Value(&buf))
  || (-1) == SQL->StmtBindParam(stmt, 0, SQLDT_INT, &char_id, 0)
  || (-1) == SQL->StmtExecute(stmt)
  || (-1) == SQL->StmtBindColumn(stmt, 0, SQLDT_INT, &tmp_item.id, 0, 
# 1220 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1220 "../../../server-code/src/char/char.c"
                                                                                      , 
# 1220 "../../../server-code/src/char/char.c" 3 4
                                                                                        ((void *)0)
# 1220 "../../../server-code/src/char/char.c"
                                                                                            )
  || (-1) == SQL->StmtBindColumn(stmt, 1, SQLDT_SHORT, &tmp_item.nameid, 0, 
# 1221 "../../../server-code/src/char/char.c" 3 4
                                                                                      ((void *)0)
# 1221 "../../../server-code/src/char/char.c"
                                                                                          , 
# 1221 "../../../server-code/src/char/char.c" 3 4
                                                                                            ((void *)0)
# 1221 "../../../server-code/src/char/char.c"
                                                                                                )
  || (-1) == SQL->StmtBindColumn(stmt, 2, SQLDT_SHORT, &tmp_item.amount, 0, 
# 1222 "../../../server-code/src/char/char.c" 3 4
                                                                                      ((void *)0)
# 1222 "../../../server-code/src/char/char.c"
                                                                                          , 
# 1222 "../../../server-code/src/char/char.c" 3 4
                                                                                            ((void *)0)
# 1222 "../../../server-code/src/char/char.c"
                                                                                                )
  || (-1) == SQL->StmtBindColumn(stmt, 3, SQLDT_UINT, &tmp_item.equip, 0, 
# 1223 "../../../server-code/src/char/char.c" 3 4
                                                                                     ((void *)0)
# 1223 "../../../server-code/src/char/char.c"
                                                                                         , 
# 1223 "../../../server-code/src/char/char.c" 3 4
                                                                                           ((void *)0)
# 1223 "../../../server-code/src/char/char.c"
                                                                                               )
  || (-1) == SQL->StmtBindColumn(stmt, 4, SQLDT_CHAR, &tmp_item.identify, 0, 
# 1224 "../../../server-code/src/char/char.c" 3 4
                                                                                        ((void *)0)
# 1224 "../../../server-code/src/char/char.c"
                                                                                            , 
# 1224 "../../../server-code/src/char/char.c" 3 4
                                                                                              ((void *)0)
# 1224 "../../../server-code/src/char/char.c"
                                                                                                  )
  || (-1) == SQL->StmtBindColumn(stmt, 5, SQLDT_CHAR, &tmp_item.refine, 0, 
# 1225 "../../../server-code/src/char/char.c" 3 4
                                                                                      ((void *)0)
# 1225 "../../../server-code/src/char/char.c"
                                                                                          , 
# 1225 "../../../server-code/src/char/char.c" 3 4
                                                                                            ((void *)0)
# 1225 "../../../server-code/src/char/char.c"
                                                                                                )
  || (-1) == SQL->StmtBindColumn(stmt, 6, SQLDT_CHAR, &tmp_item.attribute, 0, 
# 1226 "../../../server-code/src/char/char.c" 3 4
                                                                                         ((void *)0)
# 1226 "../../../server-code/src/char/char.c"
                                                                                             , 
# 1226 "../../../server-code/src/char/char.c" 3 4
                                                                                               ((void *)0)
# 1226 "../../../server-code/src/char/char.c"
                                                                                                   )
  || (-1) == SQL->StmtBindColumn(stmt, 7, SQLDT_UINT, &tmp_item.expire_time, 0, 
# 1227 "../../../server-code/src/char/char.c" 3 4
                                                                                           ((void *)0)
# 1227 "../../../server-code/src/char/char.c"
                                                                                               , 
# 1227 "../../../server-code/src/char/char.c" 3 4
                                                                                                 ((void *)0)
# 1227 "../../../server-code/src/char/char.c"
                                                                                                     )
  || (-1) == SQL->StmtBindColumn(stmt, 8, SQLDT_UCHAR, &tmp_item.bound, 0, 
# 1228 "../../../server-code/src/char/char.c" 3 4
                                                                                     ((void *)0)
# 1228 "../../../server-code/src/char/char.c"
                                                                                         , 
# 1228 "../../../server-code/src/char/char.c" 3 4
                                                                                           ((void *)0)
# 1228 "../../../server-code/src/char/char.c"
                                                                                               )
  || (-1) == SQL->StmtBindColumn(stmt, 9, SQLDT_UINT64, &tmp_item.unique_id, 0, 
# 1229 "../../../server-code/src/char/char.c" 3 4
                                                                                         ((void *)0)
# 1229 "../../../server-code/src/char/char.c"
                                                                                             , 
# 1229 "../../../server-code/src/char/char.c" 3 4
                                                                                               ((void *)0)
# 1229 "../../../server-code/src/char/char.c"
                                                                                                   )
 ) {
  (SQL->StmtShowDebug_((stmt), "../../../server-code/src/char/char.c", 1231));
 }
 for( i = 0; i < 4; ++i )
  if( (-1) == SQL->StmtBindColumn(stmt, 10+i, SQLDT_SHORT, &tmp_item.card[i], 0, 
# 1234 "../../../server-code/src/char/char.c" 3 4
                                                                                     ((void *)0)
# 1234 "../../../server-code/src/char/char.c"
                                                                                         , 
# 1234 "../../../server-code/src/char/char.c" 3 4
                                                                                           ((void *)0)
# 1234 "../../../server-code/src/char/char.c"
                                                                                               ) )
   (SQL->StmtShowDebug_((stmt), "../../../server-code/src/char/char.c", 1235));

 for( i = 0; i < 100 && 0 == SQL->StmtNextRow(stmt); ++i )
  memcpy(&p->cart[i], &tmp_item, sizeof(tmp_item));
 strcat(t_msg, " cart");


 inter_storage->fromsql(p->account_id, &p->storage);
 strcat(t_msg, " storage");



 memset(&tmp_skill, 0, sizeof(tmp_skill));
 if ((-1) == SQL->StmtPrepare(stmt, "SELECT `id`, `lv`,`flag` FROM `%s` WHERE `char_id`=? LIMIT %d", skill_db, 1478)
  || (-1) == SQL->StmtBindParam(stmt, 0, SQLDT_INT, &char_id, 0)
  || (-1) == SQL->StmtExecute(stmt)
  || (-1) == SQL->StmtBindColumn(stmt, 0, SQLDT_USHORT, &tmp_skill.id , 0, 
# 1251 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 1251 "../../../server-code/src/char/char.c"
                                                                                    , 
# 1251 "../../../server-code/src/char/char.c" 3 4
                                                                                      ((void *)0)
# 1251 "../../../server-code/src/char/char.c"
                                                                                          )
  || (-1) == SQL->StmtBindColumn(stmt, 1, SQLDT_UCHAR , &tmp_skill.lv , 0, 
# 1252 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 1252 "../../../server-code/src/char/char.c"
                                                                                    , 
# 1252 "../../../server-code/src/char/char.c" 3 4
                                                                                      ((void *)0)
# 1252 "../../../server-code/src/char/char.c"
                                                                                          )
  || (-1) == SQL->StmtBindColumn(stmt, 2, SQLDT_UCHAR , &tmp_skill.flag, 0, 
# 1253 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0)
# 1253 "../../../server-code/src/char/char.c"
                                                                                    , 
# 1253 "../../../server-code/src/char/char.c" 3 4
                                                                                      ((void *)0)
# 1253 "../../../server-code/src/char/char.c"
                                                                                          )
 ) {
  (SQL->StmtShowDebug_((stmt), "../../../server-code/src/char/char.c", 1255));
 }

 if( tmp_skill.flag != SKILL_FLAG_PERM_GRANTED )
  tmp_skill.flag = SKILL_FLAG_PERMANENT;

 for( i = 0; i < 1478 && 0 == SQL->StmtNextRow(stmt); ++i ) {
  if( skillid2idx[tmp_skill.id] )
   memcpy(&p->skill[skillid2idx[tmp_skill.id]], &tmp_skill, sizeof(tmp_skill));
  else
   (showmsg->showWarning(("chr->mmo_char_fromsql: ignoring invalid skill (id=%u,lv=%u) of character %s (AID=%d,CID=%d)\n"), tmp_skill.id, tmp_skill.lv, p->name, p->account_id, p->char_id));
 }
 strcat(t_msg, " skills");



 memset(&tmp_friend, 0, sizeof(tmp_friend));
 if ((-1) == SQL->StmtPrepare(stmt, "SELECT c.`account_id`, c.`char_id`, c.`name` FROM `%s` c LEFT JOIN `%s` f ON f.`friend_account` = c.`account_id` AND f.`friend_id` = c.`char_id` WHERE f.`char_id`=? LIMIT %d", char_db, friend_db, 40)
  || (-1) == SQL->StmtBindParam(stmt, 0, SQLDT_INT, &char_id, 0)
  || (-1) == SQL->StmtExecute(stmt)
  || (-1) == SQL->StmtBindColumn(stmt, 0, SQLDT_INT, &tmp_friend.account_id, 0, 
# 1275 "../../../server-code/src/char/char.c" 3 4
                                                                                       ((void *)0)
# 1275 "../../../server-code/src/char/char.c"
                                                                                           , 
# 1275 "../../../server-code/src/char/char.c" 3 4
                                                                                             ((void *)0)
# 1275 "../../../server-code/src/char/char.c"
                                                                                                 )
  || (-1) == SQL->StmtBindColumn(stmt, 1, SQLDT_INT, &tmp_friend.char_id, 0, 
# 1276 "../../../server-code/src/char/char.c" 3 4
                                                                                    ((void *)0)
# 1276 "../../../server-code/src/char/char.c"
                                                                                        , 
# 1276 "../../../server-code/src/char/char.c" 3 4
                                                                                          ((void *)0)
# 1276 "../../../server-code/src/char/char.c"
                                                                                              )
  || (-1) == SQL->StmtBindColumn(stmt, 2, SQLDT_STRING, &tmp_friend.name, sizeof(tmp_friend.name), 
# 1277 "../../../server-code/src/char/char.c" 3 4
                                                                                                       ((void *)0)
# 1277 "../../../server-code/src/char/char.c"
                                                                                                           , 
# 1277 "../../../server-code/src/char/char.c" 3 4
                                                                                                             ((void *)0)
# 1277 "../../../server-code/src/char/char.c"
                                                                                                                 )
 ) {
  (SQL->StmtShowDebug_((stmt), "../../../server-code/src/char/char.c", 1279));
 }

 for( i = 0; i < 40 && 0 == SQL->StmtNextRow(stmt); ++i )
  memcpy(&p->friends[i], &tmp_friend, sizeof(tmp_friend));
 strcat(t_msg, " friends");




 memset(&tmp_hotkey, 0, sizeof(tmp_hotkey));
 if ((-1) == SQL->StmtPrepare(stmt, "SELECT `hotkey`, `type`, `itemskill_id`, `skill_lvl` FROM `%s` WHERE `char_id`=?", hotkey_db)
  || (-1) == SQL->StmtBindParam(stmt, 0, SQLDT_INT, &char_id, 0)
  || (-1) == SQL->StmtExecute(stmt)
  || (-1) == SQL->StmtBindColumn(stmt, 0, SQLDT_INT, &hotkey_num, 0, 
# 1293 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 1293 "../../../server-code/src/char/char.c"
                                                                                , 
# 1293 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1293 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 1, SQLDT_UCHAR, &tmp_hotkey.type, 0, 
# 1294 "../../../server-code/src/char/char.c" 3 4
                                                                                 ((void *)0)
# 1294 "../../../server-code/src/char/char.c"
                                                                                     , 
# 1294 "../../../server-code/src/char/char.c" 3 4
                                                                                       ((void *)0)
# 1294 "../../../server-code/src/char/char.c"
                                                                                           )
  || (-1) == SQL->StmtBindColumn(stmt, 2, SQLDT_UINT, &tmp_hotkey.id, 0, 
# 1295 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 1295 "../../../server-code/src/char/char.c"
                                                                                   , 
# 1295 "../../../server-code/src/char/char.c" 3 4
                                                                                     ((void *)0)
# 1295 "../../../server-code/src/char/char.c"
                                                                                         )
  || (-1) == SQL->StmtBindColumn(stmt, 3, SQLDT_USHORT, &tmp_hotkey.lv, 0, 
# 1296 "../../../server-code/src/char/char.c" 3 4
                                                                               ((void *)0)
# 1296 "../../../server-code/src/char/char.c"
                                                                                   , 
# 1296 "../../../server-code/src/char/char.c" 3 4
                                                                                     ((void *)0)
# 1296 "../../../server-code/src/char/char.c"
                                                                                         ) )
  (SQL->StmtShowDebug_((stmt), "../../../server-code/src/char/char.c", 1297));

 while( 0 == SQL->StmtNextRow(stmt) )
 {
  if( hotkey_num >= 0 && hotkey_num < 38 )
   memcpy(&p->hotkeys[hotkey_num], &tmp_hotkey, sizeof(tmp_hotkey));
  else
   (showmsg->showWarning(("chr->mmo_char_fromsql: ignoring invalid hotkey (hotkey=%d,type=%u,id=%u,lv=%u) of character %s (AID=%d,CID=%d)\n"), hotkey_num, tmp_hotkey.type, tmp_hotkey.id, tmp_hotkey.lv, p->name, p->account_id, p->char_id));
 }
 strcat(t_msg, " hotkeys");



 inter_mercenary->owner_fromsql(char_id, p);
 strcat(t_msg, " mercenary");


 p->mod_exp = p->mod_drop = p->mod_death = 100;


 if ((-1) == SQL->StmtPrepare(stmt, "SELECT `bank_vault`,`base_exp`,`base_drop`,`base_death` FROM `%s` WHERE `account_id`=? LIMIT 1", account_data_db)
  || (-1) == SQL->StmtBindParam(stmt, 0, SQLDT_INT, &account_id, 0)
  || (-1) == SQL->StmtExecute(stmt)
  || (-1) == SQL->StmtBindColumn(stmt, 0, SQLDT_INT, &p->bank_vault, 0, 
# 1320 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 1320 "../../../server-code/src/char/char.c"
                                                                                , 
# 1320 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1320 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 1, SQLDT_USHORT, &p->mod_exp, 0, 
# 1321 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 1321 "../../../server-code/src/char/char.c"
                                                                                , 
# 1321 "../../../server-code/src/char/char.c" 3 4
                                                                                  ((void *)0)
# 1321 "../../../server-code/src/char/char.c"
                                                                                      )
  || (-1) == SQL->StmtBindColumn(stmt, 2, SQLDT_USHORT, &p->mod_drop, 0, 
# 1322 "../../../server-code/src/char/char.c" 3 4
                                                                             ((void *)0)
# 1322 "../../../server-code/src/char/char.c"
                                                                                 , 
# 1322 "../../../server-code/src/char/char.c" 3 4
                                                                                   ((void *)0)
# 1322 "../../../server-code/src/char/char.c"
                                                                                       )
  || (-1) == SQL->StmtBindColumn(stmt, 3, SQLDT_USHORT, &p->mod_death, 0, 
# 1323 "../../../server-code/src/char/char.c" 3 4
                                                                              ((void *)0)
# 1323 "../../../server-code/src/char/char.c"
                                                                                  , 
# 1323 "../../../server-code/src/char/char.c" 3 4
                                                                                    ((void *)0)
# 1323 "../../../server-code/src/char/char.c"
                                                                                        )
 ) {
  (SQL->StmtShowDebug_((stmt), "../../../server-code/src/char/char.c", 1325));
 }

 if( 0 == SQL->StmtNextRow(stmt) )
  strcat(t_msg, " accdata");

 if (save_log) (showmsg->showInfo(("Loaded char (%d - %s): %s\n"), char_id, p->name, t_msg));
 SQL->StmtFree(stmt);
 StrBuf->Destroy(&buf);


 if( opt & OPT_ALLOW_PARTY )
  p->allow_party = 
# 1337 "../../../server-code/src/char/char.c" 3 4
                  1
# 1337 "../../../server-code/src/char/char.c"
                      ;
 if( opt & OPT_SHOW_EQUIP )
  p->show_equip = 
# 1339 "../../../server-code/src/char/char.c" 3 4
                 1
# 1339 "../../../server-code/src/char/char.c"
                     ;

 cp = ( DB->data2ptr((chr->char_db_)->ensure((chr->char_db_),DB->i2key(char_id),(chr->create_charstatus))) );
 memcpy(cp, p, sizeof(struct mmo_charstatus));
 return 1;
}


int char_mmo_char_sql_init(void)
{
 chr->char_db_= DB->alloc("../../../server-code/src/char/char.c",__func__,1349,DB_INT,(DB_OPT_RELEASE_DATA),sizeof(int));
# 1358 "../../../server-code/src/char/char.c"
 chr->set_all_offline_sql();

 return 0;
}



# 1364 "../../../server-code/src/char/char.c" 3 4
_Bool 
# 1364 "../../../server-code/src/char/char.c"
    char_char_slotchange(struct char_session_data *sd, int fd, unsigned short from, unsigned short to) {
 struct mmo_charstatus char_dat;
 int from_id = 0;

 do { if (((void)(sd), 
# 1368 "../../../server-code/src/char/char.c" 3 4
0
# 1368 "../../../server-code/src/char/char.c"
)) return(0); } while(0);
 if( from >= 9 || to >= 9 || ( sd->char_slots && to > sd->char_slots ) || sd->found_char[from] <= 0 )
  return 
# 1370 "../../../server-code/src/char/char.c" 3 4
        0
# 1370 "../../../server-code/src/char/char.c"
             ;

 if( !chr->mmo_char_fromsql(sd->found_char[from], &char_dat, 
# 1372 "../../../server-code/src/char/char.c" 3 4
                                                            0
# 1372 "../../../server-code/src/char/char.c"
                                                                 ) )
  return 
# 1373 "../../../server-code/src/char/char.c" 3 4
        0
# 1373 "../../../server-code/src/char/char.c"
             ;

 if( char_dat.slotchange == 0 )
  return 
# 1376 "../../../server-code/src/char/char.c" 3 4
        0
# 1376 "../../../server-code/src/char/char.c"
             ;

 from_id = sd->found_char[from];

 if( sd->found_char[to] > 0 ) {
  
# 1381 "../../../server-code/src/char/char.c" 3 4
 _Bool 
# 1381 "../../../server-code/src/char/char.c"
      result = 
# 1381 "../../../server-code/src/char/char.c" 3 4
               0
# 1381 "../../../server-code/src/char/char.c"
                    ;

  if( 0 != SQL->QueryStr(inter->sql_handle, "START TRANSACTION")
     || 0 != SQL->Query(inter->sql_handle, "UPDATE `%s` SET `char_num`='%d' WHERE `char_id`='%d' LIMIT 1", char_db, from, sd->found_char[to])
     || 0 != SQL->Query(inter->sql_handle, "UPDATE `%s` SET `char_num`='%d' WHERE `char_id`='%d' LIMIT 1", char_db, to, sd->found_char[from])
  )
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1387));
  else
   result = 
# 1389 "../../../server-code/src/char/char.c" 3 4
           1
# 1389 "../../../server-code/src/char/char.c"
               ;

  if( (-1) == SQL->QueryStr(inter->sql_handle, (result == 
# 1391 "../../../server-code/src/char/char.c" 3 4
                                                              1
# 1391 "../../../server-code/src/char/char.c"
                                                                  ) ? "COMMIT" : "ROLLBACK") ) {
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1392));
   result = 
# 1393 "../../../server-code/src/char/char.c" 3 4
           0
# 1393 "../../../server-code/src/char/char.c"
                ;
  }
  if( !result )
   return 
# 1396 "../../../server-code/src/char/char.c" 3 4
         0
# 1396 "../../../server-code/src/char/char.c"
              ;
 } else {
  if( (-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `char_num`='%d' WHERE `char_id`='%d' LIMIT 1", char_db, to, sd->found_char[from] ) ) {
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1399));
   return 
# 1400 "../../../server-code/src/char/char.c" 3 4
         0
# 1400 "../../../server-code/src/char/char.c"
              ;
  }
 }


 if( (-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `slotchange`=`slotchange`-1 WHERE `char_id`='%d' LIMIT 1", char_db, from_id ) ) {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1406));
  return 
# 1407 "../../../server-code/src/char/char.c" 3 4
        0
# 1407 "../../../server-code/src/char/char.c"
             ;
 }

 return 
# 1410 "../../../server-code/src/char/char.c" 3 4
       1
# 1410 "../../../server-code/src/char/char.c"
           ;
}




int char_rename_char_sql(struct char_session_data *sd, int char_id)
{
 struct mmo_charstatus char_dat;
 char esc_name[(23 + 1)*2+1];

 do { if (((void)(sd), 
# 1421 "../../../server-code/src/char/char.c" 3 4
0
# 1421 "../../../server-code/src/char/char.c"
)) return(2); } while(0);

 if( sd->new_name[0] == 0 )
  return 2;

 if( !chr->mmo_char_fromsql(char_id, &char_dat, 
# 1426 "../../../server-code/src/char/char.c" 3 4
                                               0
# 1426 "../../../server-code/src/char/char.c"
                                                    ) )
  return 2;

 if (sd->account_id != char_dat.account_id)
  return 2;

 if( char_dat.rename == 0 )
  return 1;

 SQL->EscapeStringLen(inter->sql_handle, esc_name, sd->new_name, (strlib->strnlen_((sd->new_name),((23 + 1)))));


 if( (-1) == SQL->Query(inter->sql_handle, "SELECT 1 FROM `%s` WHERE `name` LIKE '%s' LIMIT 1", char_db, esc_name) )
 {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1440));
  return 4;
 }

 if( (-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `name` = '%s', `rename` = '%d' WHERE `char_id` = '%d'", char_db, esc_name, --char_dat.rename, char_id) )
 {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1446));
  return 3;
 }


 if( char_dat.guild_id )
  inter_guild->charname_changed(char_dat.guild_id, sd->account_id, char_id, sd->new_name);

 (strlib->safestrncpy_((char_dat.name),(sd->new_name),((23 + 1))));
 memset(sd->new_name,0,sizeof(sd->new_name));


 if( log_char )
 {
  if( (-1) == SQL->Query(inter->sql_handle,
   "INSERT INTO `%s` (`time`, `char_msg`,`account_id`,`char_id`,`char_num`,`name`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`hair`,`hair_color`)"
   "VALUES (NOW(), '%s', '%d', '%d', '%d', '%s', '0', '0', '0', '0', '0', '0', '0', '0')",
   charlog_db, "change char name", sd->account_id, char_dat.char_id, char_dat.slot, esc_name) )
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1464));
 }

 return 0;
}

int char_check_char_name(char * name, char * esc_name)
{
 int i;

 do { if (((void)(name), 
# 1474 "../../../server-code/src/char/char.c" 3 4
0
# 1474 "../../../server-code/src/char/char.c"
)) return(-2); } while(0);
 do { if (((void)(esc_name), 
# 1475 "../../../server-code/src/char/char.c" 3 4
0
# 1475 "../../../server-code/src/char/char.c"
)) return(-2); } while(0);


 if (name[0] == '\0')
  return -2;




 if( strlen( name ) < 4 )
  return -2;

 if( (strlib->remove_control_chars_(name)) )
  return -2;


 if( strcasecmp(name, wisp_server_name) == 0 )
  return -1;


 if( char_name_option == 1 )
 {
  for( i = 0; i < (23 + 1) && name[i]; i++ )
   if( strchr(char_name_letters, name[i]) == 
# 1498 "../../../server-code/src/char/char.c" 3 4
                                            ((void *)0) 
# 1498 "../../../server-code/src/char/char.c"
                                                 )
    return -2;
 }
 else if( char_name_option == 2 )
 {
  for( i = 0; i < (23 + 1) && name[i]; i++ )
   if( strchr(char_name_letters, name[i]) != 
# 1504 "../../../server-code/src/char/char.c" 3 4
                                            ((void *)0) 
# 1504 "../../../server-code/src/char/char.c"
                                                 )
    return -5;
 }
 if( name_ignoring_case ) {
  if( (-1) == SQL->Query(inter->sql_handle, "SELECT 1 FROM `%s` WHERE BINARY `name` = '%s' LIMIT 1", char_db, esc_name) ) {
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1509));
   return -2;
  }
 } else {
  if( (-1) == SQL->Query(inter->sql_handle, "SELECT 1 FROM `%s` WHERE `name` = '%s' LIMIT 1", char_db, esc_name) ) {
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1514));
   return -2;
  }
 }
 if( SQL->NumRows(inter->sql_handle) > 0 )
  return -1;

 return 0;
}
# 1534 "../../../server-code/src/char/char.c"
int char_make_new_char_sql(struct char_session_data *sd, const char *name_, int str, int agi, int vit, int int_, int dex, int luk, int slot, int hair_color, int hair_style)
{
 char name[(23 + 1)];
 char esc_name[(23 + 1)*2+1];
 int char_id, flag, k, l;

 do { if (((void)(sd), 
# 1540 "../../../server-code/src/char/char.c" 3 4
0
# 1540 "../../../server-code/src/char/char.c"
)) return(-2); } while(0);
 do { if (((void)(name_), 
# 1541 "../../../server-code/src/char/char.c" 3 4
0
# 1541 "../../../server-code/src/char/char.c"
)) return(-2); } while(0);
 (strlib->safestrncpy_((name),(name_),((23 + 1))));
 (strlib->normalize_name_((name),("\255\xA0\032\t\x0A\x0D ")));
 SQL->EscapeStringLen(inter->sql_handle, esc_name, name, (strlib->strnlen_((name),((23 + 1)))));

 flag = chr->check_char_name(name,esc_name);
 if( flag < 0 )
  return flag;



 if(slot < 0 || slot >= sd->char_slots)







  return -4;





 if( sd->found_char[slot] != -1 )
  return -2;



 if( (-1) == SQL->Query(inter->sql_handle, "INSERT INTO `%s` (`account_id`, `char_num`, `name`, `zeny`, `status_point`,`str`, `agi`, `vit`, `int`, `dex`, `luk`, `max_hp`, `hp`,"
  "`max_sp`, `sp`, `hair`, `hair_color`, `last_map`, `last_x`, `last_y`, `save_map`, `save_x`, `save_y`) VALUES ("
  "'%d', '%d', '%s', '%d',  '%d','%d', '%d', '%d', '%d', '%d', '%d', '%d', '%d','%d', '%d','%d', '%d', '%s', '%d', '%d', '%s', '%d', '%d')",
  char_db, sd->account_id , slot, esc_name, start_zeny, 48, str, agi, vit, int_, dex, luk,
  (40 * (100 + vit)/100) , (40 * (100 + vit)/100 ), (11 * (100 + int_)/100), (11 * (100 + int_)/100), hair_style, hair_color,
  mapindex->id2name((start_point.map),"../../../server-code/src/char/char.c", 1576, __func__), start_point.x, start_point.y, mapindex->id2name((start_point.map),"../../../server-code/src/char/char.c", 1576, __func__), start_point.x, start_point.y) )
 {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1578));
  return -2;
 }
# 1595 "../../../server-code/src/char/char.c"
 char_id = (int)SQL->LastInsertId(inter->sql_handle);

 if( !char_id )
  return -2;


 if (log_char) {
  if( (-1) == SQL->Query(inter->sql_handle, "INSERT INTO `%s` (`time`, `char_msg`,`account_id`,`char_id`,`char_num`,`name`,`str`,`agi`,`vit`,`int`,`dex`,`luk`,`hair`,`hair_color`)"
   "VALUES (NOW(), '%s', '%d', '%d', '%d', '%s', '%d', '%d', '%d', '%d', '%d', '%d', '%d', '%d')",
   charlog_db, "make new char", sd->account_id, char_id, slot, esc_name, str, agi, vit, int_, dex, luk, hair_style, hair_color) )
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1605));
 }


 for (k = 0; k < ( (int)(sizeof(start_items)/sizeof((start_items)[0])) ) && start_items[k] != 0; k += 3) {

  if( start_items[k+2] == 1 )
  {
   if( (-1) == SQL->Query(inter->sql_handle,
    "INSERT INTO `%s` (`char_id`,`nameid`, `amount`, `identify`) VALUES ('%d', '%d', '%d', '%d')",
    inventory_db, char_id, start_items[k], start_items[k + 1], 1) )
     (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1616));
  }
  else if( start_items[k+2] == 0 )
  {

   for( l = 0; l < start_items[k+1]; l++ )
   {
    if( (-1) == SQL->Query(inter->sql_handle,
     "INSERT INTO `%s` (`char_id`,`nameid`, `amount`, `identify`) VALUES ('%d', '%d', '%d', '%d')",
     inventory_db, char_id, start_items[k], 1, 1)
     )
     (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1627));
   }
  }
 }

 (showmsg->showInfo(("Created char: account: %d, char: %d, slot: %d, name: %s\n"), sd->account_id, char_id, slot, name));
 return char_id;
}




int char_divorce_char_sql(int partner_id1, int partner_id2)
{
 unsigned char buf[64];

 if( (-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `partner_id`='0' WHERE `char_id`='%d' OR `char_id`='%d' LIMIT 2", char_db, partner_id1, partner_id2) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1644));
 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE (`nameid`='%d' OR `nameid`='%d') AND (`char_id`='%d' OR `char_id`='%d') LIMIT 2", inventory_db, 2634, 2635, partner_id1, partner_id2) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1646));

 WBUFW(buf,0) = 0x2b12;
 WBUFL(buf,2) = partner_id1;
 WBUFL(buf,6) = partner_id2;
 mapif->sendall(buf,10);

 return 0;
}







int char_delete_char_sql(int char_id)
{
 char name[(23 + 1)];
 char esc_name[(23 + 1)*2+1];
 int account_id, party_id, guild_id, hom_id, base_level, partner_id, father_id, mother_id, elemental_id;
 char *data;
 size_t len;

 if ((-1) == SQL->Query(inter->sql_handle, "SELECT `name`,`account_id`,`party_id`,`guild_id`,`base_level`,`homun_id`,`partner_id`,`father`,`mother`,`elemental_id` FROM `%s` WHERE `char_id`='%d'", char_db, char_id))
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1671));

 if( 0 != SQL->NextRow(inter->sql_handle) )
 {
  (showmsg->showError(("chr->delete_char_sql: Unable to fetch character data, deletion aborted.\n")));
  SQL->FreeResult(inter->sql_handle);
  return -1;
 }

 SQL->GetData(inter->sql_handle, 0, &data, &len); (strlib->safestrncpy_((name),(data),((23 + 1))));
 SQL->GetData(inter->sql_handle, 1, &data, 
# 1681 "../../../server-code/src/char/char.c" 3 4
                                          ((void *)0)
# 1681 "../../../server-code/src/char/char.c"
                                              ); account_id = atoi(data);
 SQL->GetData(inter->sql_handle, 2, &data, 
# 1682 "../../../server-code/src/char/char.c" 3 4
                                          ((void *)0)
# 1682 "../../../server-code/src/char/char.c"
                                              ); party_id = atoi(data);
 SQL->GetData(inter->sql_handle, 3, &data, 
# 1683 "../../../server-code/src/char/char.c" 3 4
                                          ((void *)0)
# 1683 "../../../server-code/src/char/char.c"
                                              ); guild_id = atoi(data);
 SQL->GetData(inter->sql_handle, 4, &data, 
# 1684 "../../../server-code/src/char/char.c" 3 4
                                          ((void *)0)
# 1684 "../../../server-code/src/char/char.c"
                                              ); base_level = atoi(data);
 SQL->GetData(inter->sql_handle, 5, &data, 
# 1685 "../../../server-code/src/char/char.c" 3 4
                                          ((void *)0)
# 1685 "../../../server-code/src/char/char.c"
                                              ); hom_id = atoi(data);
 SQL->GetData(inter->sql_handle, 6, &data, 
# 1686 "../../../server-code/src/char/char.c" 3 4
                                          ((void *)0)
# 1686 "../../../server-code/src/char/char.c"
                                              ); partner_id = atoi(data);
 SQL->GetData(inter->sql_handle, 7, &data, 
# 1687 "../../../server-code/src/char/char.c" 3 4
                                          ((void *)0)
# 1687 "../../../server-code/src/char/char.c"
                                              ); father_id = atoi(data);
 SQL->GetData(inter->sql_handle, 8, &data, 
# 1688 "../../../server-code/src/char/char.c" 3 4
                                          ((void *)0)
# 1688 "../../../server-code/src/char/char.c"
                                              ); mother_id = atoi(data);
 SQL->GetData(inter->sql_handle, 9, &data, 
# 1689 "../../../server-code/src/char/char.c" 3 4
                                          ((void *)0)
# 1689 "../../../server-code/src/char/char.c"
                                              );
 elemental_id = atoi(data);

 SQL->EscapeStringLen(inter->sql_handle, esc_name, name, (((len) < ((23 + 1))) ? (len) : ((23 + 1))));
 SQL->FreeResult(inter->sql_handle);



 if( ( char_del_level > 0 && base_level >= char_del_level )
  || ( char_del_level < 0 && base_level <= -char_del_level )
 ) {
   (showmsg->showInfo(("Char deletion aborted: %s, BaseLevel: %i\n"), name, base_level));
   return -1;
 }


 if( partner_id )
  chr->divorce_char_sql(char_id, partner_id);


 if( father_id || mother_id )
 {
  unsigned char buf[64];

  if( (-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `child`='0' WHERE `char_id`='%d' OR `char_id`='%d'", char_db, father_id, mother_id) )
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1714));
  if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `id` = '410'AND (`char_id`='%d' OR `char_id`='%d')", skill_db, father_id, mother_id) )
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1716));

  WBUFW(buf,0) = 0x2b25;
  WBUFL(buf,2) = father_id;
  WBUFL(buf,6) = mother_id;
  WBUFL(buf,10) = char_id;
  mapif->sendall(buf,14);
 }


 if (party_id)
  inter_party->leave(party_id, account_id, char_id);



 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `char_id`='%d' AND `incubate` = '0'", pet_db, char_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1732));


 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` USING `%s` JOIN `%s` ON `pet_id` = `card1`|`card2`<<16 WHERE `%s`.char_id = '%d' AND card0 = -256", pet_db, pet_db, inventory_db, inventory_db, char_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1736));
 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` USING `%s` JOIN `%s` ON `pet_id` = `card1`|`card2`<<16 WHERE `%s`.char_id = '%d' AND card0 = -256", pet_db, pet_db, cart_db, cart_db, char_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1738));


 if( hom_id )
  mapif->homunculus_delete(hom_id);


 if (elemental_id)
  mapif->elemental_delete(elemental_id);


 inter_mercenary->owner_delete(char_id);


 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `char_id` = '%d'", friend_db, char_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1753));



 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `friend_id` = '%d'", friend_db, char_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1758));



 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `char_id`='%d'", hotkey_db, char_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1763));



 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `char_id`='%d'", inventory_db, char_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1768));


 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `char_id`='%d'", cart_db, char_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1772));


 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `char_id`='%d'", memo_db, char_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1776));


 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `char_id`='%d'", char_reg_str_db, char_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1780));
 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `char_id`='%d'", char_reg_num_db, char_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1782));


 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `char_id`='%d'", skill_db, char_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1786));


 if ((-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `dest_id`='%d'", mail_db, char_id))
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1790));



 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `account_id` = '%d' AND `char_id`='%d'", scdata_db, account_id, char_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1795));



 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `char_id`='%d'", char_db, char_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1800));
 else if( log_char ) {
  if( (-1) == SQL->Query(inter->sql_handle,
   "INSERT INTO `%s`(`time`, `account_id`, `char_id`, `char_num`, `char_msg`, `name`)"
   " VALUES (NOW(), '%d', '%d', '%d', 'Deleted character', '%s')",
   charlog_db, account_id, char_id, 0, esc_name) )
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1806));
 }







 if( (-1) == SQL->Query(inter->sql_handle, "SELECT `guild_id` FROM `%s` WHERE `char_id` = '%d'", guild_db, char_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1816));
 else if( SQL->NumRows(inter->sql_handle) > 0 )
  mapif->parse_BreakGuild(0,guild_id);
 else if( guild_id )
  inter_guild->leave(guild_id, account_id, char_id);
 return 0;
}




int char_count_users(void)
{
 int i, users;

 users = 0;
 for(i = 0; i < ( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) ); i++) {
  if (chr->server[i].fd > 0) {
   users += chr->server[i].users;
  }
 }
 return users;
}





int char_mmo_char_tobuf(uint8* buffer, struct mmo_charstatus* p) {
 unsigned short offset = 0;
 uint8* buf;

 if( buffer == 
# 1848 "../../../server-code/src/char/char.c" 3 4
              ((void *)0) 
# 1848 "../../../server-code/src/char/char.c"
                   || p == 
# 1848 "../../../server-code/src/char/char.c" 3 4
                           ((void *)0) 
# 1848 "../../../server-code/src/char/char.c"
                                )
  return 0;

 buf = WBUFP(buffer,0);
 WBUFL(buf,0) = p->char_id;
 WBUFL(buf,4) = (((p->base_exp) < (
# 1853 "../../../server-code/src/char/char.c" 3 4
               (2147483647)
# 1853 "../../../server-code/src/char/char.c"
               )) ? (p->base_exp) : (
# 1853 "../../../server-code/src/char/char.c" 3 4
               (2147483647)
# 1853 "../../../server-code/src/char/char.c"
               ));
 WBUFL(buf,8) = p->zeny;
 WBUFL(buf,12) = (((p->job_exp) < (
# 1855 "../../../server-code/src/char/char.c" 3 4
                (2147483647)
# 1855 "../../../server-code/src/char/char.c"
                )) ? (p->job_exp) : (
# 1855 "../../../server-code/src/char/char.c" 3 4
                (2147483647)
# 1855 "../../../server-code/src/char/char.c"
                ));
 WBUFL(buf,16) = p->job_level;
 WBUFL(buf,20) = 0;
 WBUFL(buf,24) = 0;
 WBUFL(buf,28) = (p->option &~ 0x40);
 WBUFL(buf,32) = p->karma;
 WBUFL(buf,36) = p->manner;
 WBUFW(buf,40) = (((p->status_point) < (
# 1862 "../../../server-code/src/char/char.c" 3 4
                (32767)
# 1862 "../../../server-code/src/char/char.c"
                )) ? (p->status_point) : (
# 1862 "../../../server-code/src/char/char.c" 3 4
                (32767)
# 1862 "../../../server-code/src/char/char.c"
                ));

 WBUFL(buf,42) = p->hp;
 WBUFL(buf,46) = p->max_hp;
 offset+=4;
 buf = WBUFP(buffer,offset);




 WBUFW(buf,46) = (((p->sp) < (
# 1872 "../../../server-code/src/char/char.c" 3 4
                (32767)
# 1872 "../../../server-code/src/char/char.c"
                )) ? (p->sp) : (
# 1872 "../../../server-code/src/char/char.c" 3 4
                (32767)
# 1872 "../../../server-code/src/char/char.c"
                ));
 WBUFW(buf,48) = (((p->max_sp) < (
# 1873 "../../../server-code/src/char/char.c" 3 4
                (32767)
# 1873 "../../../server-code/src/char/char.c"
                )) ? (p->max_sp) : (
# 1873 "../../../server-code/src/char/char.c" 3 4
                (32767)
# 1873 "../../../server-code/src/char/char.c"
                ));
 WBUFW(buf,50) = 150;
 WBUFW(buf,52) = p->class_;
 WBUFW(buf,54) = p->hair;
# 1885 "../../../server-code/src/char/char.c"
 WBUFW(buf,56) = p->option&(OPTION_RIDING|OPTION_DRAGON|OPTION_WUG|OPTION_WUGRIDER|OPTION_MADOGEAR|OPTION_HANBOK) ? 0 : p->weapon;

 WBUFW(buf,58) = p->base_level;
 WBUFW(buf,60) = (((p->skill_point) < (
# 1888 "../../../server-code/src/char/char.c" 3 4
                (32767)
# 1888 "../../../server-code/src/char/char.c"
                )) ? (p->skill_point) : (
# 1888 "../../../server-code/src/char/char.c" 3 4
                (32767)
# 1888 "../../../server-code/src/char/char.c"
                ));
 WBUFW(buf,62) = p->head_bottom;
 WBUFW(buf,64) = p->shield;
 WBUFW(buf,66) = p->head_top;
 WBUFW(buf,68) = p->head_mid;
 WBUFW(buf,70) = p->hair_color;
 WBUFW(buf,72) = p->clothes_color;
 memcpy(WBUFP(buf,74), p->name, (23 + 1));
 WBUFB(buf,98) = (((p->str) < (((uint8) 0xFF))) ? (p->str) : (((uint8) 0xFF)));
 WBUFB(buf,99) = (((p->agi) < (((uint8) 0xFF))) ? (p->agi) : (((uint8) 0xFF)));
 WBUFB(buf,100) = (((p->vit) < (((uint8) 0xFF))) ? (p->vit) : (((uint8) 0xFF)));
 WBUFB(buf,101) = (((p->int_) < (((uint8) 0xFF))) ? (p->int_) : (((uint8) 0xFF)));
 WBUFB(buf,102) = (((p->dex) < (((uint8) 0xFF))) ? (p->dex) : (((uint8) 0xFF)));
 WBUFB(buf,103) = (((p->luk) < (((uint8) 0xFF))) ? (p->luk) : (((uint8) 0xFF)));
 WBUFW(buf,104) = p->slot;

 WBUFW(buf,106) = ( p->rename > 0 ) ? 0 : 1;
 offset += 2;


 mapindex->getmapname_ext(mapindex->id2name((p->last_point.map),"../../../server-code/src/char/char.c", 1908, __func__), WBUFP(buf,108));
 offset += ((11 + 1) + 4);


 WBUFL(buf,124) = (int)p->delete_date;
 offset += 4;


 WBUFL(buf,128) = p->robe;
 offset += 4;



  WBUFL(buf,132) = ( p->slotchange > 0 ) ? 1 : 0;
  offset += 4;


  WBUFL(buf,136) = ( p->rename > 0 ) ? 1 : 0;
  offset += 4;


  WBUFB(buf,140) = p->sex;
  offset += 1;



 return 106+offset;
}


void char_mmo_char_send099d(int fd, struct char_session_data *sd) {
 WFIFOHEAD(fd,4 + (9*150));
 WFIFOW(fd,0) = 0x99d;
 WFIFOW(fd,2) = chr->mmo_chars_fromsql(sd, WFIFOP(fd,4)) + 4;
 WFIFOSET(fd,WFIFOW(fd,2));
}



void char_mmo_char_send_ban_list(int fd, struct char_session_data *sd) {
 int i;
 time_t now = time(
# 1949 "../../../server-code/src/char/char.c" 3 4
                  ((void *)0)
# 1949 "../../../server-code/src/char/char.c"
                      );

 do { if (((void)(sd), 
# 1951 "../../../server-code/src/char/char.c" 3 4
0
# 1951 "../../../server-code/src/char/char.c"
)) return; } while(0);
 do { for ((i) = (0); (i) < (9); ++(i)) if (sd->unban_time[i]) break; } while(
# 1952 "../../../server-code/src/char/char.c" 3 4
0
# 1952 "../../../server-code/src/char/char.c"
);
 if( i != 9 ) {
  int c;

  WFIFOHEAD(fd, 4 + (9*24));

  WFIFOW(fd,0) = 0x20d;

  for(i = 0, c = 0; i < 9; i++) {
   if( sd->unban_time[i] ) {
    timestamp2string(WFIFOP(fd,8 + (28*c)), 20, sd->unban_time[i], "%Y-%m-%d %H:%M:%S");

    if( sd->unban_time[i] > now )
     WFIFOL(fd, 4 + (24*c)) = sd->found_char[i];
    else {

     WFIFOL(fd, 4 + (24*c)) = 0;

     sd->unban_time[i] = 0;
     if( (-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `unban_time`='0' WHERE `char_id`='%d' LIMIT 1", char_db, sd->found_char[i]) )
      (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 1972));
    }
    c++;
   }
  }

  WFIFOW(fd,2) = 4 + (24*c);

  WFIFOSET(fd, WFIFOW(fd,2));
 }
}




void char_mmo_char_send_slots_info(int fd, struct char_session_data* sd) {
 do { if (((void)(sd), 
# 1988 "../../../server-code/src/char/char.c" 3 4
0
# 1988 "../../../server-code/src/char/char.c"
)) return; } while(0);
 WFIFOHEAD(fd,29);
 WFIFOW(fd,0) = 0x82d;
 WFIFOW(fd,2) = 29;
 WFIFOB(fd,4) = sd->char_slots;
 WFIFOB(fd,5) = 9 - sd->char_slots;
 WFIFOB(fd,6) = 0;
 WFIFOB(fd,7) = sd->char_slots;
 WFIFOB(fd,8) = sd->char_slots;
 memset(WFIFOP(fd,9), 0, 20);
 WFIFOSET(fd,29);
}



int char_mmo_char_send_characters(int fd, struct char_session_data* sd)
{
 int j, offset = 0;
 do { if (((void)(sd), 
# 2006 "../../../server-code/src/char/char.c" 3 4
0
# 2006 "../../../server-code/src/char/char.c"
)) return(0); } while(0);

 offset += 3;

 if (save_log)
  (showmsg->showInfo(("Loading Char Data (""\033[1m""%d""\033[0m"")\n"),sd->account_id));

 j = 24 + offset;
 WFIFOHEAD(fd,j + 9*150);
 WFIFOW(fd,0) = 0x6b;

 WFIFOB(fd,4) = 9;
 WFIFOB(fd,5) = sd->char_slots;
 WFIFOB(fd,6) = 9;

 memset(WFIFOP(fd,4 + offset), 0, 20);
 j+=chr->mmo_chars_fromsql(sd, WFIFOP(fd,j));
 WFIFOW(fd,2) = j;
 WFIFOSET(fd,j);

 return 0;
}

int char_char_married(int pl1, int pl2)
{
 if( (-1) == SQL->Query(inter->sql_handle, "SELECT `partner_id` FROM `%s` WHERE `char_id` = '%d'", char_db, pl1) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 2032));
 else if( 0 == SQL->NextRow(inter->sql_handle) )
 {
  char* data;

  SQL->GetData(inter->sql_handle, 0, &data, 
# 2037 "../../../server-code/src/char/char.c" 3 4
                                           ((void *)0)
# 2037 "../../../server-code/src/char/char.c"
                                               );
  if( pl2 == atoi(data) )
  {
   SQL->FreeResult(inter->sql_handle);
   return 1;
  }
 }
 SQL->FreeResult(inter->sql_handle);
 return 0;
}

int char_char_child(int parent_id, int child_id)
{
 if( (-1) == SQL->Query(inter->sql_handle, "SELECT `child` FROM `%s` WHERE `char_id` = '%d'", char_db, parent_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 2051));
 else if( 0 == SQL->NextRow(inter->sql_handle) )
 {
  char* data;

  SQL->GetData(inter->sql_handle, 0, &data, 
# 2056 "../../../server-code/src/char/char.c" 3 4
                                           ((void *)0)
# 2056 "../../../server-code/src/char/char.c"
                                               );
  if( child_id == atoi(data) )
  {
   SQL->FreeResult(inter->sql_handle);
   return 1;
  }
 }
 SQL->FreeResult(inter->sql_handle);
 return 0;
}

int char_char_family(int cid1, int cid2, int cid3)
{
 if( (-1) == SQL->Query(inter->sql_handle, "SELECT `char_id`,`partner_id`,`child` FROM `%s` WHERE `char_id` IN ('%d','%d','%d')", char_db, cid1, cid2, cid3) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 2070));
 else while( 0 == SQL->NextRow(inter->sql_handle) )
 {
  int charid;
  int partnerid;
  int childid;
  char* data;

  SQL->GetData(inter->sql_handle, 0, &data, 
# 2078 "../../../server-code/src/char/char.c" 3 4
                                           ((void *)0)
# 2078 "../../../server-code/src/char/char.c"
                                               ); charid = atoi(data);
  SQL->GetData(inter->sql_handle, 1, &data, 
# 2079 "../../../server-code/src/char/char.c" 3 4
                                           ((void *)0)
# 2079 "../../../server-code/src/char/char.c"
                                               ); partnerid = atoi(data);
  SQL->GetData(inter->sql_handle, 2, &data, 
# 2080 "../../../server-code/src/char/char.c" 3 4
                                           ((void *)0)
# 2080 "../../../server-code/src/char/char.c"
                                               ); childid = atoi(data);

  if( (cid1 == charid && ((cid2 == partnerid && cid3 == childid ) || (cid2 == childid && cid3 == partnerid))) ||
   (cid1 == partnerid && ((cid2 == charid && cid3 == childid ) || (cid2 == childid && cid3 == charid ))) ||
   (cid1 == childid && ((cid2 == charid && cid3 == partnerid) || (cid2 == partnerid && cid3 == charid ))) )
  {
   SQL->FreeResult(inter->sql_handle);
   return childid;
  }
 }
 SQL->FreeResult(inter->sql_handle);
 return 0;
}




void char_disconnect_player(int account_id)
{
 int i;
 struct char_session_data* sd;


 do { for ((i) = (0); (i) < (sockt->fd_max); ++(i)) if (sockt->session[i] && (sd = (struct char_session_data*)sockt->session[i]->session_data) && sd->account_id == account_id) break; } while(
# 2103 "../../../server-code/src/char/char.c" 3 4
0
# 2103 "../../../server-code/src/char/char.c"
);
 if( i < sockt->fd_max )
  sockt->eof(i);
}

void char_authfail_fd(int fd, int type)
{
 WFIFOHEAD(fd,3);
 WFIFOW(fd,0) = 0x81;
 WFIFOB(fd,2) = type;
 WFIFOSET(fd,3);
}

void char_request_account_data(int account_id)
{
 WFIFOHEAD(chr->login_fd,6);
 WFIFOW(chr->login_fd,0) = 0x2716;
 WFIFOL(chr->login_fd,2) = account_id;
 WFIFOSET(chr->login_fd,6);
}

static void char_auth_ok(int fd, struct char_session_data *sd)
{
 struct online_char_data* character;

 do { if (((void)(sd), 
# 2128 "../../../server-code/src/char/char.c" 3 4
0
# 2128 "../../../server-code/src/char/char.c"
)) return; } while(0);

 if( (character = (struct online_char_data*)( DB->data2ptr((chr->online_char_db)->get((chr->online_char_db),DB->i2key(sd->account_id))) )) != 
# 2130 "../../../server-code/src/char/char.c" 3 4
                                                                                            ((void *)0) 
# 2130 "../../../server-code/src/char/char.c"
                                                                                                 ) {

  if (character->server > -1) {

   mapif->disconnectplayer(chr->server[character->server].fd, character->account_id, character->char_id, 2);
   if (character->waiting_disconnect == (-1))
    character->waiting_disconnect = timer->add(timer->gettick()+20000, chr->waiting_disconnect, character->account_id, 0);
   character->pincode_enable = -1;
   chr->authfail_fd(fd, 8);
   return;
  }
  if (character->fd >= 0 && character->fd != fd) {

   chr->authfail_fd(fd, 8);
   return;
  }
  character->fd = fd;
 }

 if (chr->login_fd > 0) {
  chr->request_account_data(sd->account_id);
 }


 sd->auth = 
# 2154 "../../../server-code/src/char/char.c" 3 4
           1
# 2154 "../../../server-code/src/char/char.c"
               ;


 chr->set_char_charselect(sd->account_id);


}

void char_ping_login_server(int fd)
{
 WFIFOHEAD(fd,2);
 WFIFOW(fd,0) = 0x2719;
 WFIFOSET(fd,2);
}

int char_parse_fromlogin_connection_state(int fd)
{
 if (RFIFOB(fd,2)) {

  (showmsg->showError(("Can not connect to login-server.\n")));
  (showmsg->showError(("The server communication passwords (default s1/p1) are probably invalid.\n")));
  (showmsg->showError(("Also, please make sure your login db has the correct communication username/passwords and the gender of the account is S.\n")));
  (showmsg->showError(("The communication passwords are set in /conf/map-server.conf and /conf/char-server.conf\n")));
  sockt->eof(fd);
  return 1;
 } else {
  (showmsg->showStatus(("Connected to login-server (connection #%d).\n"), fd));
  loginif->on_ready();
 }
 RFIFOSKIP(fd,3);
 return 0;
}



void char_auth_error(int fd, unsigned char flag)
{
 WFIFOHEAD(fd,3);
 WFIFOW(fd,0) = 0x6c;
 WFIFOB(fd,2) = flag;
 WFIFOSET(fd,3);
}

void char_parse_fromlogin_auth_state(int fd)
{
 struct char_session_data* sd = 
# 2199 "../../../server-code/src/char/char.c" 3 4
                               ((void *)0)
# 2199 "../../../server-code/src/char/char.c"
                                   ;
 int account_id = RFIFOL(fd,2);
 uint32 login_id1 = RFIFOL(fd,6);
 uint32 login_id2 = RFIFOL(fd,10);
 uint8 sex = RFIFOB(fd,14);
 uint8 result = RFIFOB(fd,15);
 int request_id = RFIFOL(fd,16);
 uint32 version = RFIFOL(fd,20);
 uint8 clienttype = RFIFOB(fd,24);
 int group_id = RFIFOL(fd,25);
 unsigned int expiration_time = RFIFOL(fd, 29);
 RFIFOSKIP(fd,33);

 if (sockt->session_is_active(request_id) && (sd=(struct char_session_data*)sockt->session[request_id]->session_data) &&
  !sd->auth && sd->account_id == account_id && sd->login_id1 == login_id1 && sd->login_id2 == login_id2 && sd->sex == sex )
 {
  int client_fd = request_id;
  sd->version = version;
  sd->clienttype = clienttype;
  switch( result ) {
   case 0:

    if( chr->server_type == CST_MAINTENANCE && group_id < char_maintenance_min_group_id ) {
     chr->auth_error(client_fd, 0);
     break;
    }

    if( chr->server_type == CST_PAYING && (time_t)expiration_time < time(
# 2226 "../../../server-code/src/char/char.c" 3 4
                                                                        ((void *)0)
# 2226 "../../../server-code/src/char/char.c"
                                                                            ) ) {
     chr->auth_error(client_fd, 0);
     break;
    }
    chr->auth_ok(client_fd, sd);
    break;
   case 1:
    chr->auth_error(client_fd, 0);
    break;
  }
 }
}

void char_parse_fromlogin_account_data(int fd)
{
 struct char_session_data* sd = (struct char_session_data*)sockt->session[fd]->session_data;
 int i;

 do { for ((i) = (0); (i) < (sockt->fd_max); ++(i)) if (sockt->session[i] && (sd = (struct char_session_data*)sockt->session[i]->session_data) && sd->auth && sd->account_id == RFIFOL(fd,2)) break; } while(
# 2244 "../../../server-code/src/char/char.c" 3 4
0
# 2244 "../../../server-code/src/char/char.c"
);
 if( i < sockt->fd_max ) {
  memcpy(sd->email, RFIFOP(fd,6), 40);
  sd->expiration_time = (time_t)RFIFOL(fd,46);
  sd->group_id = RFIFOB(fd,50);
  sd->char_slots = RFIFOB(fd,51);
  if( sd->char_slots > 9 ) {
   (showmsg->showError(("Account '%d' `character_slots` column is higher than supported MAX_CHARS (%d), update MAX_CHARS in mmo.h! capping to MAX_CHARS...\n"),sd->account_id,sd->char_slots));
   sd->char_slots = 9;
  } else if ( sd->char_slots <= 0 )
   sd->char_slots = 9;
  (strlib->safestrncpy_((sd->birthdate),(RFIFOP(fd,52)),(sizeof(sd->birthdate))));
  (strlib->safestrncpy_((sd->pincode),(RFIFOP(fd,63)),(sizeof(sd->pincode))));
  sd->pincode_change = RFIFOL(fd,68);

  if( (max_connect_user == 0 && sd->group_id != gm_allow_group) ||
   ( max_connect_user > 0 && chr->count_users() >= max_connect_user && sd->group_id != gm_allow_group ) ) {

   chr->auth_error(i, 0);
  } else {


   chr->mmo_char_send_slots_info(i, sd);
   chr->mmo_char_send_characters(i, sd);




   chr->mmo_char_send_ban_list(i, sd);


   pincode->handle(i, sd);

  }
 }
 RFIFOSKIP(fd,72);
}

void char_parse_fromlogin_login_pong(int fd)
{
 RFIFOSKIP(fd,2);
 if (sockt->session[fd])
  sockt->session[fd]->flag.ping = 0;
}

void char_changesex(int account_id, int sex)
{
 unsigned char buf[7];

 WBUFW(buf,0) = 0x2b0d;
 WBUFL(buf,2) = account_id;
 WBUFB(buf,6) = sex;
 mapif->sendall(buf, 7);
}
# 2310 "../../../server-code/src/char/char.c"
void char_change_sex_sub(int sex, int acc, int char_id, int class_, int guild_id)
{

 if (class_ == JOB_BARD || class_ == JOB_DANCER)
  class_ = (sex == SEX_MALE ? JOB_BARD : JOB_DANCER);
 else if (class_ == JOB_CLOWN || class_ == JOB_GYPSY)
  class_ = (sex == SEX_MALE ? JOB_CLOWN : JOB_GYPSY);
 else if (class_ == JOB_BABY_BARD || class_ == JOB_BABY_DANCER)
  class_ = (sex == SEX_MALE ? JOB_BABY_BARD : JOB_BABY_DANCER);
 else if (class_ == JOB_MINSTREL || class_ == JOB_WANDERER)
  class_ = (sex == SEX_MALE ? JOB_MINSTREL : JOB_WANDERER);
 else if (class_ == JOB_MINSTREL_T || class_ == JOB_WANDERER_T)
  class_ = (sex == SEX_MALE ? JOB_MINSTREL_T : JOB_WANDERER_T);
 else if (class_ == JOB_BABY_MINSTREL || class_ == JOB_BABY_WANDERER)
  class_ = (sex == SEX_MALE ? JOB_BABY_MINSTREL : JOB_BABY_WANDERER);
 else if (class_ == JOB_KAGEROU || class_ == JOB_OBORO)
  class_ = (sex == SEX_MALE ? JOB_KAGEROU : JOB_OBORO);

 if ((-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `equip`='0' WHERE `char_id`='%d'", inventory_db, char_id))
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 2329));

 if ((-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `class`='%d', `weapon`='0', `shield`='0', "
    "`head_top`='0', `head_mid`='0', `head_bottom`='0' WHERE `char_id`='%d'",
    char_db, class_, char_id))
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 2334));
 if (guild_id)
  inter_guild->sex_changed(guild_id, acc, char_id, sex);
}

int char_parse_fromlogin_changesex_reply(int fd)
{
 int char_id = 0, class_ = 0, guild_id = 0;
 int i;
 struct char_auth_node *node;
 struct SqlStmt *stmt;

 int acc = RFIFOL(fd,2);
 int sex = RFIFOB(fd,6);

 RFIFOSKIP(fd,7);


 if (acc <= 0) {
  (showmsg->showError(("Received invalid account id from login server! (aid: %d)\n"), acc));
  return 1;
 }

 node = (struct char_auth_node*)( DB->data2ptr((auth_db)->get((auth_db),DB->i2key(acc))) );
 if (node != 
# 2358 "../../../server-code/src/char/char.c" 3 4
            ((void *)0)
# 2358 "../../../server-code/src/char/char.c"
                )
  node->sex = sex;


 stmt = SQL->StmtMalloc(inter->sql_handle);
 if ((-1) == SQL->StmtPrepare(stmt, "SELECT `char_id`,`class`,`guild_id` FROM `%s` WHERE `account_id` = '%d'", char_db, acc)
  || (-1) == SQL->StmtExecute(stmt)
 ) {
  (SQL->StmtShowDebug_((stmt), "../../../server-code/src/char/char.c", 2366));
  SQL->StmtFree(stmt);
 }
 SQL->StmtBindColumn(stmt, 0, SQLDT_INT, &char_id, 0, 
# 2369 "../../../server-code/src/char/char.c" 3 4
                                                      ((void *)0)
# 2369 "../../../server-code/src/char/char.c"
                                                          , 
# 2369 "../../../server-code/src/char/char.c" 3 4
                                                            ((void *)0)
# 2369 "../../../server-code/src/char/char.c"
                                                                );
 SQL->StmtBindColumn(stmt, 1, SQLDT_INT, &class_, 0, 
# 2370 "../../../server-code/src/char/char.c" 3 4
                                                      ((void *)0)
# 2370 "../../../server-code/src/char/char.c"
                                                          , 
# 2370 "../../../server-code/src/char/char.c" 3 4
                                                            ((void *)0)
# 2370 "../../../server-code/src/char/char.c"
                                                                );
 SQL->StmtBindColumn(stmt, 2, SQLDT_INT, &guild_id, 0, 
# 2371 "../../../server-code/src/char/char.c" 3 4
                                                      ((void *)0)
# 2371 "../../../server-code/src/char/char.c"
                                                          , 
# 2371 "../../../server-code/src/char/char.c" 3 4
                                                            ((void *)0)
# 2371 "../../../server-code/src/char/char.c"
                                                                );

 for (i = 0; i < 9 && 0 == SQL->StmtNextRow(stmt); ++i) {
  char_change_sex_sub(sex, acc, char_id, class_, guild_id);
 }
 SQL->StmtFree(stmt);


 chr->disconnect_player(acc);


 chr->changesex(acc, sex);
 return 0;
}

void char_parse_fromlogin_account_reg2(int fd)
{

 mapif->sendall(RFIFOP(fd, 0), RFIFOW(fd,2));
 RFIFOSKIP(fd, RFIFOW(fd,2));
}

void mapif_ban(int id, unsigned int flag, int status)
{

 unsigned char buf[11];
 WBUFW(buf,0) = 0x2b14;
 WBUFL(buf,2) = id;
 WBUFB(buf,6) = flag;
 WBUFL(buf,7) = status;
 mapif->sendall(buf, 11);
}

void char_parse_fromlogin_ban(int fd)
{
 mapif->ban(RFIFOL(fd,2), RFIFOB(fd,6), RFIFOL(fd,7));

 chr->disconnect_player(RFIFOL(fd,2));
 RFIFOSKIP(fd,11);
}

void char_parse_fromlogin_kick(int fd)
{
 int aid = RFIFOL(fd,2);
 struct online_char_data* character = (struct online_char_data*)( DB->data2ptr((chr->online_char_db)->get((chr->online_char_db),DB->i2key(aid))) );
 RFIFOSKIP(fd,6);
 if( character != 
# 2417 "../../../server-code/src/char/char.c" 3 4
                 ((void *)0) 
# 2417 "../../../server-code/src/char/char.c"
                      )
 {
  if( character->server > -1 ) {

   mapif->disconnectplayer(chr->server[character->server].fd, character->account_id, character->char_id, 2);
   if (character->waiting_disconnect == (-1))
    character->waiting_disconnect = timer->add(timer->gettick()+30000, chr->waiting_disconnect, character->account_id, 0);
  }
  else
  {
   struct char_session_data *tsd;
   int i;
   do { for ((i) = (0); (i) < (sockt->fd_max); ++(i)) if (sockt->session[i] && (tsd = (struct char_session_data*)sockt->session[i]->session_data) && tsd->account_id == aid) break; } while(
# 2429 "../../../server-code/src/char/char.c" 3 4
  0
# 2429 "../../../server-code/src/char/char.c"
  );
   if( i < sockt->fd_max )
   {
    chr->authfail_fd(i, 2);
    sockt->eof(i);
   }
   else
    chr->set_char_offline(-1, aid);
  }
 }
 ( (auth_db)->remove((auth_db),DB->i2key(aid),
# 2439 "../../../server-code/src/char/char.c" 3 4
((void *)0)
# 2439 "../../../server-code/src/char/char.c"
) );
}

void char_update_ip(int fd)
{
 WFIFOHEAD(fd,6);
 WFIFOW(fd,0) = 0x2736;
 WFIFOL(fd,2) = htonl(chr->ip);
 WFIFOSET(fd,6);
}

void char_parse_fromlogin_update_ip(int fd)
{
 unsigned char buf[2];
 uint32 new_ip = 0;

 WBUFW(buf,0) = 0x2b1e;
 mapif->sendall(buf, 2);

 new_ip = sockt->host2ip(login_ip_str);
 if (new_ip && new_ip != login_ip)
  login_ip = new_ip;

 new_ip = sockt->host2ip(char_ip_str);
 if (new_ip && new_ip != chr->ip) {

  chr->ip = new_ip;
  (showmsg->showInfo(("Updating IP for [%s].\n"), char_ip_str));

  chr->update_ip(fd);
 }
 RFIFOSKIP(fd,2);
}

void char_parse_fromlogin_accinfo2_failed(int fd)
{
 mapif->parse_accinfo2(
# 2475 "../../../server-code/src/char/char.c" 3 4
                      0
# 2475 "../../../server-code/src/char/char.c"
                           , RFIFOL(fd,2), RFIFOL(fd,6), RFIFOL(fd,10), RFIFOL(fd,14),
                      
# 2476 "../../../server-code/src/char/char.c" 3 4
                     ((void *)0)
# 2476 "../../../server-code/src/char/char.c"
                         , 
# 2476 "../../../server-code/src/char/char.c" 3 4
                           ((void *)0)
# 2476 "../../../server-code/src/char/char.c"
                               , 
# 2476 "../../../server-code/src/char/char.c" 3 4
                                 ((void *)0)
# 2476 "../../../server-code/src/char/char.c"
                                     , 
# 2476 "../../../server-code/src/char/char.c" 3 4
                                       ((void *)0)
# 2476 "../../../server-code/src/char/char.c"
                                           , 
# 2476 "../../../server-code/src/char/char.c" 3 4
                                             ((void *)0)
# 2476 "../../../server-code/src/char/char.c"
                                                 , 
# 2476 "../../../server-code/src/char/char.c" 3 4
                                                   ((void *)0)
# 2476 "../../../server-code/src/char/char.c"
                                                       , 
# 2476 "../../../server-code/src/char/char.c" 3 4
                                                         ((void *)0)
# 2476 "../../../server-code/src/char/char.c"
                                                             , -1, 0, 0);
 RFIFOSKIP(fd,18);
}

void char_parse_fromlogin_accinfo2_ok(int fd)
{
 mapif->parse_accinfo2(
# 2482 "../../../server-code/src/char/char.c" 3 4
                      1
# 2482 "../../../server-code/src/char/char.c"
                          , RFIFOL(fd,167), RFIFOL(fd,171), RFIFOL(fd,175), RFIFOL(fd,179),
                       RFIFOP(fd,2), RFIFOP(fd,26), RFIFOP(fd,59), RFIFOP(fd,99), RFIFOP(fd,119),
                       RFIFOP(fd,151), RFIFOP(fd,156), RFIFOL(fd,115), RFIFOL(fd,143), RFIFOL(fd,147));
 RFIFOSKIP(fd,183);
}

int char_parse_fromlogin(int fd) {

 if( fd != chr->login_fd ) {
  (showmsg->showDebug(("chr->parse_fromlogin: Disconnecting invalid session #%d (is not the login-server)\n"), fd));
  sockt->close(fd);
  return 0;
 }

 if( sockt->session[fd]->flag.eof ) {
  sockt->close(fd);
  chr->login_fd = -1;
  loginif->on_disconnect();
  return 0;
 } else if ( sockt->session[fd]->flag.ping ) {
  if( ((sockt->last_tick)-(sockt->session[fd]->rdata_tick)) > (sockt->stall_time * 2) ) {
   sockt->eof(fd);
   return 0;
  } else if( sockt->session[fd]->flag.ping != 2 ) {
   chr->ping_login_server(fd);
   sockt->session[fd]->flag.ping = 2;
  }
 }

 while (RFIFOREST(fd) >= 2) {
  uint16 command = RFIFOW(fd,0);

  if (( (HPM->packets[hpParse_FromLogin])._len_ ) > 0) {
   int result = HPM->parse_packets(fd,command,hpParse_FromLogin);
   if (result == 1)
    continue;
   if (result == 2)
    return 0;
  }

  switch (command) {

   case 0x2711:
    if (RFIFOREST(fd) < 3)
     return 0;
    if (chr->parse_fromlogin_connection_state(fd))
     return 0;
   break;


   case 0x2713:
    if (RFIFOREST(fd) < 33)
     return 0;
   {
    chr->parse_fromlogin_auth_state(fd);
   }
   break;

   case 0x2717:
   {
    if (RFIFOREST(fd) < 72)
     return 0;
    chr->parse_fromlogin_account_data(fd);
   }
   break;


   case 0x2718:
    if (RFIFOREST(fd) < 2)
     return 0;
    chr->parse_fromlogin_login_pong(fd);
   break;


   case 0x2723:
    if (RFIFOREST(fd) < 7)
     return 0;
   {
    if (chr->parse_fromlogin_changesex_reply(fd))
     return 0;
   }
   break;


   case 0x3804:
    if (RFIFOREST(fd) < 4 || RFIFOREST(fd) < RFIFOW(fd,2))
     return 0;
    chr->parse_fromlogin_account_reg2(fd);
   break;


   case 0x2731:
    if (RFIFOREST(fd) < 11)
     return 0;
    chr->parse_fromlogin_ban(fd);
   break;


   case 0x2734:
    if (RFIFOREST(fd) < 6)
     return 0;
   {
    chr->parse_fromlogin_kick(fd);
   }
   break;


   case 0x2735:
   {
    chr->parse_fromlogin_update_ip(fd);
   }
   break;

   case 0x2736:
    if (RFIFOREST(fd) < 18)
     return 0;

    chr->parse_fromlogin_accinfo2_failed(fd);
   break;

   case 0x2737:
    if (RFIFOREST(fd) < 183)
     return 0;

    chr->parse_fromlogin_accinfo2_ok(fd);
   break;

   default:
    (showmsg->showError(("Unknown packet 0x%04x received from login-server, disconnecting.\n"), command));
    sockt->eof(fd);
    return 0;
   }
 }

 RFIFOFLUSH(fd);
 return 0;
}

int char_request_accreg2(int account_id, int char_id)
{
 if (chr->login_fd > 0) {
  WFIFOHEAD(chr->login_fd,10);
  WFIFOW(chr->login_fd,0) = 0x272e;
  WFIFOL(chr->login_fd,2) = account_id;
  WFIFOL(chr->login_fd,6) = char_id;
  WFIFOSET(chr->login_fd,10);
  return 1;
 }
 return 0;
}




void char_global_accreg_to_login_start (int account_id, int char_id) {
 WFIFOHEAD(chr->login_fd, 60000 + 300);
 WFIFOW(chr->login_fd,0) = 0x2728;
 WFIFOW(chr->login_fd,2) = 14;
 WFIFOL(chr->login_fd,4) = account_id;
 WFIFOL(chr->login_fd,8) = char_id;
 WFIFOW(chr->login_fd,12) = 0;
}




void char_global_accreg_to_login_send (void) {
 WFIFOSET(chr->login_fd, WFIFOW(chr->login_fd,2));
}




void char_global_accreg_to_login_add (const char *key, unsigned int index, intptr_t val, 
# 2655 "../../../server-code/src/char/char.c" 3 4
                                                                                        _Bool 
# 2655 "../../../server-code/src/char/char.c"
                                                                                             is_string) {
 int nlen = WFIFOW(chr->login_fd,2);
 size_t len = strlen(key)+1;

 WFIFOB(chr->login_fd, nlen) = (unsigned char)len;
 nlen += 1;

 (strlib->safestrncpy_((WFIFOP(chr->login_fd,nlen)),(key),(len)));
 nlen += len;

 WFIFOL(chr->login_fd, nlen) = index;
 nlen += 4;

 if( is_string ) {
  WFIFOB(chr->login_fd, nlen) = val ? 2 : 3;
  nlen += 1;

  if( val ) {
   char *sval = (char*)val;
   len = strlen(sval)+1;

   WFIFOB(chr->login_fd, nlen) = (unsigned char)len;
   nlen += 1;

   (strlib->safestrncpy_((WFIFOP(chr->login_fd,nlen)),(sval),(len)));
   nlen += len;
  }
 } else {
  WFIFOB(chr->login_fd, nlen) = val ? 0 : 1;
  nlen += 1;

  if( val ) {
   WFIFOL(chr->login_fd, nlen) = (int)val;
   nlen += 4;
  }
 }

 WFIFOW(chr->login_fd,12) += 1;

 WFIFOW(chr->login_fd,2) = nlen;
 if( WFIFOW(chr->login_fd,2) > 60000 ) {
  int account_id = WFIFOL(chr->login_fd,4), char_id = WFIFOL(chr->login_fd,8);
  chr->global_accreg_to_login_send();
  chr->global_accreg_to_login_start(account_id,char_id);
 }
}

void char_read_fame_list(void) {
 int i;
 char* data;
 size_t len;


 memset(smith_fame_list, 0, sizeof(smith_fame_list));
 memset(chemist_fame_list, 0, sizeof(chemist_fame_list));
 memset(taekwon_fame_list, 0, sizeof(taekwon_fame_list));

 if( (-1) == SQL->Query(inter->sql_handle, "SELECT `char_id`,`fame`,`name` FROM `%s` WHERE `fame`>0 AND (`class`='%d' OR `class`='%d' OR `class`='%d' OR `class`='%d' OR `class`='%d' OR `class`='%d') ORDER BY `fame` DESC LIMIT 0,%d", char_db, JOB_BLACKSMITH, JOB_WHITESMITH, JOB_BABY_BLACKSMITH, JOB_MECHANIC, JOB_MECHANIC_T, JOB_BABY_MECHANIC, fame_list_size_smith) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 2713));
 for( i = 0; i < fame_list_size_smith && 0 == SQL->NextRow(inter->sql_handle); ++i )
 {

  SQL->GetData(inter->sql_handle, 0, &data, 
# 2717 "../../../server-code/src/char/char.c" 3 4
                                           ((void *)0)
# 2717 "../../../server-code/src/char/char.c"
                                               );
  smith_fame_list[i].id = atoi(data);

  SQL->GetData(inter->sql_handle, 1, &data, &len);
  smith_fame_list[i].fame = atoi(data);

  SQL->GetData(inter->sql_handle, 2, &data, &len);
  memcpy(smith_fame_list[i].name, data, (((len) < ((23 + 1))) ? (len) : ((23 + 1))));
 }

 if( (-1) == SQL->Query(inter->sql_handle, "SELECT `char_id`,`fame`,`name` FROM `%s` WHERE `fame`>0 AND (`class`='%d' OR `class`='%d' OR `class`='%d' OR `class`='%d' OR `class`='%d' OR `class`='%d') ORDER BY `fame` DESC LIMIT 0,%d", char_db, JOB_ALCHEMIST, JOB_CREATOR, JOB_BABY_ALCHEMIST, JOB_GENETIC, JOB_GENETIC_T, JOB_BABY_GENETIC, fame_list_size_chemist) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 2728));
 for( i = 0; i < fame_list_size_chemist && 0 == SQL->NextRow(inter->sql_handle); ++i )
 {

  SQL->GetData(inter->sql_handle, 0, &data, 
# 2732 "../../../server-code/src/char/char.c" 3 4
                                           ((void *)0)
# 2732 "../../../server-code/src/char/char.c"
                                               );
  chemist_fame_list[i].id = atoi(data);

  SQL->GetData(inter->sql_handle, 1, &data, &len);
  chemist_fame_list[i].fame = atoi(data);

  SQL->GetData(inter->sql_handle, 2, &data, &len);
  memcpy(chemist_fame_list[i].name, data, (((len) < ((23 + 1))) ? (len) : ((23 + 1))));
 }

 if( (-1) == SQL->Query(inter->sql_handle, "SELECT `char_id`,`fame`,`name` FROM `%s` WHERE `fame`>0 AND (`class`='%d') ORDER BY `fame` DESC LIMIT 0,%d", char_db, JOB_TAEKWON, fame_list_size_taekwon) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 2743));
 for( i = 0; i < fame_list_size_taekwon && 0 == SQL->NextRow(inter->sql_handle); ++i )
 {

  SQL->GetData(inter->sql_handle, 0, &data, 
# 2747 "../../../server-code/src/char/char.c" 3 4
                                           ((void *)0)
# 2747 "../../../server-code/src/char/char.c"
                                               );
  taekwon_fame_list[i].id = atoi(data);

  SQL->GetData(inter->sql_handle, 1, &data, &len);
  taekwon_fame_list[i].fame = atoi(data);

  SQL->GetData(inter->sql_handle, 2, &data, &len);
  memcpy(taekwon_fame_list[i].name, data, (((len) < ((23 + 1))) ? (len) : ((23 + 1))));
 }
 SQL->FreeResult(inter->sql_handle);
}


int char_send_fame_list(int fd) {
 int i, len = 8;
 unsigned char buf[32000];

 WBUFW(buf,0) = 0x2b1b;

 for(i = 0; i < fame_list_size_smith && smith_fame_list[i].id; i++) {
  memcpy(WBUFP(buf, len), &smith_fame_list[i], sizeof(struct fame_list));
  len += sizeof(struct fame_list);
 }

 WBUFW(buf,6) = len;

 for(i = 0; i < fame_list_size_chemist && chemist_fame_list[i].id; i++) {
  memcpy(WBUFP(buf, len), &chemist_fame_list[i], sizeof(struct fame_list));
  len += sizeof(struct fame_list);
 }

 WBUFW(buf,4) = len;

 for(i = 0; i < fame_list_size_taekwon && taekwon_fame_list[i].id; i++) {
  memcpy(WBUFP(buf, len), &taekwon_fame_list[i], sizeof(struct fame_list));
  len += sizeof(struct fame_list);
 }

 WBUFW(buf,2) = len;

 if (fd != -1)
  mapif->send(fd, buf, len);
 else
  mapif->sendall(buf, len);

 return 0;
}

void char_update_fame_list(int type, int index, int fame) {
 unsigned char buf[8];
 WBUFW(buf,0) = 0x2b22;
 WBUFB(buf,2) = type;
 WBUFB(buf,3) = index;
 WBUFL(buf,4) = fame;
 mapif->sendall(buf, 8);
}



int char_loadName(int char_id, char* name)
{
 char* data;
 size_t len;

 if( (-1) == SQL->Query(inter->sql_handle, "SELECT `name` FROM `%s` WHERE `char_id`='%d'", char_db, char_id) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 2812));
 else if( 0 == SQL->NextRow(inter->sql_handle) )
 {
  SQL->GetData(inter->sql_handle, 0, &data, &len);
  (strlib->safestrncpy_((name),(data),((23 + 1))));
  return 1;
 }
 else
 {
  (strlib->safestrncpy_((name),(unknown_char_name),((23 + 1))));
 }
 return 0;
}


void mapif_server_init(int id)
{

 chr->server[id].fd = -1;
}


void mapif_server_destroy(int id)
{
 if( chr->server[id].fd == -1 )
 {
  sockt->close(chr->server[id].fd);
  chr->server[id].fd = -1;
 }
}



void mapif_server_reset(int id)
{
 int i,j;
 unsigned char buf[16384];
 int fd = chr->server[id].fd;

 WBUFW(buf,0) = 0x2b20;
 WBUFL(buf,4) = htonl(chr->server[id].ip);
 WBUFW(buf,8) = htons(chr->server[id].port);
 j = 0;
 for (i = 0; i < ( (chr->server[id].maps)._len_ ); i++) {
  uint16 m = ( ( (chr->server[id].maps)._data_ )[i] );
  if (m != 0)
   WBUFW(buf,10+(j++)*4) = m;
 }
 if (j > 0) {
  WBUFW(buf,2) = j * 4 + 10;
  mapif->sendallwos(fd, buf, WBUFW(buf,2));
 }
 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `index`='%d'", ragsrvinfo_db, chr->server[id].fd) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 2865));
 chr->online_char_db->foreach(chr->online_char_db,chr->db_setoffline,id);
 mapif->server_destroy(id);
 mapif->server_init(id);
}


void mapif_on_disconnect(int id)
{
 (showmsg->showStatus(("Map-server #%d has disconnected.\n"), id));
 mapif->server_reset(id);
}

void mapif_on_parse_accinfo(int account_id, int u_fd, int u_aid, int u_group, int map_fd) {
 do { if (( (chr->login_fd > 0) ? 
# 2879 "../../../server-code/src/char/char.c" 3 4
0 
# 2879 "../../../server-code/src/char/char.c"
: (nullpo->assert_report("../../../server-code/src/char/char.c", 2879, __func__, "chr->login_fd > 0", "failed assertion"), 
# 2879 "../../../server-code/src/char/char.c" 3 4
1
# 2879 "../../../server-code/src/char/char.c"
) )) return; } while(0);
 WFIFOHEAD(chr->login_fd,22);
 WFIFOW(chr->login_fd,0) = 0x2740;
 WFIFOL(chr->login_fd,2) = account_id;
 WFIFOL(chr->login_fd,6) = u_fd;
 WFIFOL(chr->login_fd,10) = u_aid;
 WFIFOL(chr->login_fd,14) = u_group;
 WFIFOL(chr->login_fd,18) = map_fd;
 WFIFOSET(chr->login_fd,22);
}

void char_parse_frommap_datasync(int fd)
{
 sockt->datasync(fd, 
# 2892 "../../../server-code/src/char/char.c" 3 4
                    0
# 2892 "../../../server-code/src/char/char.c"
                         );
 RFIFOSKIP(fd,RFIFOW(fd,2));
}

void char_parse_frommap_skillid2idx(int fd)
{
 int i;
 int j = RFIFOW(fd, 2) - 4;

 memset(&skillid2idx, 0, sizeof(skillid2idx));
 if( j )
  j /= 4;
 for(i = 0; i < j; i++) {
  if( RFIFOW(fd, 4 + (i*4)) > 10015 ) {
   (showmsg->showWarning(("Error skillid2dx[%d] = %d failed, %d is higher than MAX_SKILL_ID (%d)\n"),RFIFOW(fd, 4 + (i*4)), RFIFOW(fd, 6 + (i*4)),RFIFOW(fd, 4 + (i*4)),10015));
   continue;
  }
  skillid2idx[RFIFOW(fd, 4 + (i*4))] = RFIFOW(fd, 6 + (i*4));
 }
 RFIFOSKIP(fd, RFIFOW(fd, 2));
}

void char_map_received_ok(int fd)
{
 WFIFOHEAD(fd, 3 + (23 + 1));
 WFIFOW(fd,0) = 0x2afb;
 WFIFOB(fd,2) = 0;
 memcpy(WFIFOP(fd,3), wisp_server_name, (23 + 1));
 WFIFOSET(fd,3+(23 + 1));
}

void char_send_maps(int fd, int id, int j)
{
 int k,i;

 if (j == 0) {
  (showmsg->showWarning(("Map-server %d has NO maps.\n"), id));
 } else {
  unsigned char buf[16384];

  WBUFW(buf,0) = 0x2b04;
  WBUFW(buf,2) = j * 4 + 10;
  WBUFL(buf,4) = htonl(chr->server[id].ip);
  WBUFW(buf,8) = htons(chr->server[id].port);
  memcpy(WBUFP(buf,10), RFIFOP(fd,4), j * 4);
  mapif->sendallwos(fd, buf, WBUFW(buf,2));
 }

 for(k = 0; k < ( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) ); k++) {
  if (chr->server[k].fd > 0 && k != id) {
   WFIFOHEAD(fd,10 + 4 * ( (chr->server[k].maps)._len_ ));
   WFIFOW(fd,0) = 0x2b04;
   WFIFOL(fd,4) = htonl(chr->server[k].ip);
   WFIFOW(fd,8) = htons(chr->server[k].port);
   j = 0;
   for(i = 0; i < ( (chr->server[k].maps)._len_ ); i++) {
    uint16 m = ( ( (chr->server[k].maps)._data_ )[i] );
    if (m != 0)
     WFIFOW(fd,10+(j++)*4) = m;
   }
   if (j > 0) {
    WFIFOW(fd,2) = j * 4 + 10;
    WFIFOSET(fd,WFIFOW(fd,2));
   }
  }
 }
}

void char_parse_frommap_map_names(int fd, int id)
{
 int i;

 do { if (( (chr->server[id].maps)._max_ ) > 0) { (iMalloc->free((( (chr->server[id].maps)._data_ )),"../../../server-code/src/char/char.c", 2964, __func__)); ( (chr->server[id].maps)._data_ ) = 
# 2964 "../../../server-code/src/char/char.c" 3 4
((void *)0)
# 2964 "../../../server-code/src/char/char.c"
; ( (chr->server[id].maps)._max_ ) = 0; ( (chr->server[id].maps)._len_ ) = 0; } } while(
# 2964 "../../../server-code/src/char/char.c" 3 4
0
# 2964 "../../../server-code/src/char/char.c"
);
 do { int _empty_ = ( (chr->server[id].maps)._max_ )-( (chr->server[id].maps)._len_ ); if (((RFIFOW(fd, 2) - 4) / 4) > _empty_) { while (((RFIFOW(fd, 2) - 4) / 4) > _empty_) _empty_ += (1); do { if ((_empty_+( (chr->server[id].maps)._len_ )) > ( (chr->server[id].maps)._max_ )) { if (( (chr->server[id].maps)._max_ ) == 0) ( (chr->server[id].maps)._data_ ) = (iMalloc->malloc(((_empty_+( (chr->server[id].maps)._len_ ))*sizeof(( ( ( (chr->server[id].maps)._data_ )[0] ) ))),"../../../server-code/src/char/char.c", 2965, __func__)); else ( (chr->server[id].maps)._data_ ) = (iMalloc->realloc((( (chr->server[id].maps)._data_ )),((_empty_+( (chr->server[id].maps)._len_ ))*sizeof(( ( ( (chr->server[id].maps)._data_ )[0] ) ))),"../../../server-code/src/char/char.c", 2965, __func__)); memset(( (chr->server[id].maps)._data_ )+( (chr->server[id].maps)._len_ ), 0, (( (chr->server[id].maps)._max_ )-( (chr->server[id].maps)._len_ ))*sizeof(( ( ( (chr->server[id].maps)._data_ )[0] ) ))); ( (chr->server[id].maps)._max_ ) = (_empty_+( (chr->server[id].maps)._len_ )); } else if ((_empty_+( (chr->server[id].maps)._len_ )) == 0 && ( (chr->server[id].maps)._max_ ) > 0) { (iMalloc->free((( (chr->server[id].maps)._data_ )),"../../../server-code/src/char/char.c", 2965, __func__)); ( (chr->server[id].maps)._data_ ) = 
# 2965 "../../../server-code/src/char/char.c" 3 4
((void *)0)
# 2965 "../../../server-code/src/char/char.c"
; ( (chr->server[id].maps)._max_ ) = 0; ( (chr->server[id].maps)._len_ ) = 0; } else if ((_empty_+( (chr->server[id].maps)._len_ )) < ( (chr->server[id].maps)._max_ )) { ( (chr->server[id].maps)._data_ ) = (iMalloc->realloc((( (chr->server[id].maps)._data_ )),((_empty_+( (chr->server[id].maps)._len_ ))*sizeof(( ( ( (chr->server[id].maps)._data_ )[0] ) ))),"../../../server-code/src/char/char.c", 2965, __func__)); ( (chr->server[id].maps)._max_ ) = (_empty_+( (chr->server[id].maps)._len_ )); if ((_empty_+( (chr->server[id].maps)._len_ )) - ( (chr->server[id].maps)._len_ ) > 0) ( (chr->server[id].maps)._len_ ) = (_empty_+( (chr->server[id].maps)._len_ )); } } while(
# 2965 "../../../server-code/src/char/char.c" 3 4
0
# 2965 "../../../server-code/src/char/char.c"
); } } while(
# 2965 "../../../server-code/src/char/char.c" 3 4
0
# 2965 "../../../server-code/src/char/char.c"
);
 for (i = 4; i < RFIFOW(fd,2); i += 4) {
  do { ( ( (chr->server[id].maps)._data_ )[( (chr->server[id].maps)._len_ )] ) = (RFIFOW(fd,i)); ++( (chr->server[id].maps)._len_ ); }while(
# 2967 "../../../server-code/src/char/char.c" 3 4
 0
# 2967 "../../../server-code/src/char/char.c"
 );
 }

 (showmsg->showStatus(("Map-Server %d connected: %d maps, from IP %u.%u.%u.%u port %d.\n"), id, (int)( (chr->server[id].maps)._len_ ), CONVIP(chr->server[id].ip), chr->server[id].port))
                                                                                                  ;
 (showmsg->showStatus(("Map-server %d loading complete.\n"), id));


 chr->map_received_ok(fd);
 chr->send_fame_list(fd);
 chr->send_maps(fd, id, (int)( (chr->server[id].maps)._len_ ));
 RFIFOSKIP(fd,RFIFOW(fd,2));
}

void char_send_scdata(int fd, int aid, int cid)
{

 if( (-1) == SQL->Query(inter->sql_handle, "SELECT `type`, `tick`, `val1`, `val2`, `val3`, `val4` "
  "FROM `%s` WHERE `account_id` = '%d' AND `char_id`='%d'",
  scdata_db, aid, cid) )
 {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 2988));
  return;
 }
 if( SQL->NumRows(inter->sql_handle) > 0 ) {
  struct status_change_data scdata;
  int count;
  char* data;

  memset(&scdata, 0, sizeof(scdata));
  WFIFOHEAD(fd,14+50*sizeof(struct status_change_data));
  WFIFOW(fd,0) = 0x2b1d;
  WFIFOL(fd,4) = aid;
  WFIFOL(fd,8) = cid;
  for( count = 0; count < 50 && 0 == SQL->NextRow(inter->sql_handle); ++count )
  {
   SQL->GetData(inter->sql_handle, 0, &data, 
# 3003 "../../../server-code/src/char/char.c" 3 4
                                            ((void *)0)
# 3003 "../../../server-code/src/char/char.c"
                                                ); scdata.type = atoi(data);
   SQL->GetData(inter->sql_handle, 1, &data, 
# 3004 "../../../server-code/src/char/char.c" 3 4
                                            ((void *)0)
# 3004 "../../../server-code/src/char/char.c"
                                                ); scdata.tick = atoi(data);
   SQL->GetData(inter->sql_handle, 2, &data, 
# 3005 "../../../server-code/src/char/char.c" 3 4
                                            ((void *)0)
# 3005 "../../../server-code/src/char/char.c"
                                                ); scdata.val1 = atoi(data);
   SQL->GetData(inter->sql_handle, 3, &data, 
# 3006 "../../../server-code/src/char/char.c" 3 4
                                            ((void *)0)
# 3006 "../../../server-code/src/char/char.c"
                                                ); scdata.val2 = atoi(data);
   SQL->GetData(inter->sql_handle, 4, &data, 
# 3007 "../../../server-code/src/char/char.c" 3 4
                                            ((void *)0)
# 3007 "../../../server-code/src/char/char.c"
                                                ); scdata.val3 = atoi(data);
   SQL->GetData(inter->sql_handle, 5, &data, 
# 3008 "../../../server-code/src/char/char.c" 3 4
                                            ((void *)0)
# 3008 "../../../server-code/src/char/char.c"
                                                ); scdata.val4 = atoi(data);
   memcpy(WFIFOP(fd, 14+count*sizeof(struct status_change_data)), &scdata, sizeof(struct status_change_data));
  }
  if (count >= 50)
   (showmsg->showWarning(("Too many status changes for %d:%d, some of them were not loaded.\n"), aid, cid));
  if (count > 0) {
   WFIFOW(fd,2) = 14 + count*sizeof(struct status_change_data);
   WFIFOW(fd,12) = count;
   WFIFOSET(fd,WFIFOW(fd,2));


   if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `account_id` = '%d' AND `char_id`='%d'", scdata_db, aid, cid) )
    (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 3020));
  }
 } else {
  WFIFOHEAD(fd,14);
  WFIFOW(fd,0) = 0x2b1d;
  WFIFOW(fd,2) = 14;
  WFIFOL(fd,4) = aid;
  WFIFOL(fd,8) = cid;
  WFIFOW(fd,12) = 0;
  WFIFOSET(fd,WFIFOW(fd,2));
 }
 SQL->FreeResult(inter->sql_handle);

}

void char_parse_frommap_request_scdata(int fd)
{

 int aid = RFIFOL(fd,2);
 int cid = RFIFOL(fd,6);
 chr->send_scdata(fd, aid, cid);

 RFIFOSKIP(fd, 10);
}

void char_parse_frommap_set_users_count(int fd, int id)
{
 if (RFIFOW(fd,2) != chr->server[id].users) {
  chr->server[id].users = RFIFOW(fd,2);
  (showmsg->showInfo(("User Count: %d (Server: %d)\n"), chr->server[id].users, id));
 }
 RFIFOSKIP(fd, 4);
}

void char_parse_frommap_set_users(int fd, int id)
{

 int i;

 chr->server[id].users = RFIFOW(fd,4);
 chr->online_char_db->foreach(chr->online_char_db,chr->db_setoffline,id);
 for(i = 0; i < chr->server[id].users; i++) {
  int aid = RFIFOL(fd,6+i*8);
  int cid = RFIFOL(fd,6+i*8+4);
  struct online_char_data *character = ( DB->data2ptr((chr->online_char_db)->ensure((chr->online_char_db),DB->i2key(aid),(chr->create_online_char_data))) );
  if (character->server > -1 && character->server != id) {
   (showmsg->showNotice(("Set map user: Character (%d:%d) marked on map server %d, but map server %d claims to have (%d:%d) online!\n"), character->account_id, character->char_id, character->server, id, aid, cid))
                                                                               ;
   mapif->disconnectplayer(chr->server[character->server].fd, character->account_id, character->char_id, 2);
  }
  character->server = id;
  character->char_id = cid;
 }

 RFIFOSKIP(fd,RFIFOW(fd,2));
}

void char_save_character_ack(int fd, int aid, int cid)
{
 WFIFOHEAD(fd,10);
 WFIFOW(fd,0) = 0x2b21;
 WFIFOL(fd,2) = aid;
 WFIFOL(fd,6) = cid;
 WFIFOSET(fd,10);
}

void char_parse_frommap_save_character(int fd, int id)
{
 int aid = RFIFOL(fd,4), cid = RFIFOL(fd,8), size = RFIFOW(fd,2);
 struct online_char_data* character;

 if (size - 13 != sizeof(struct mmo_charstatus)) {
  (showmsg->showError(("parse_from_map (save-char): Size mismatch! %d != %""z" "u""\n"), size-13, sizeof(struct mmo_charstatus)));
  RFIFOSKIP(fd,size);
  return;
 }

 if (RFIFOB(fd,12)
  || ( (character = (struct online_char_data*)( DB->data2ptr((chr->online_char_db)->get((chr->online_char_db),DB->i2key(aid))) )) != 
# 3098 "../../../server-code/src/char/char.c" 3 4
                                                                                   ((void *)0)
     
# 3099 "../../../server-code/src/char/char.c"
    && character->char_id == cid)
 ) {
  struct mmo_charstatus char_dat;
  memcpy(&char_dat, RFIFOP(fd,13), sizeof(struct mmo_charstatus));
  chr->mmo_char_tosql(cid, &char_dat);
 } else {

  (showmsg->showError(("parse_from_map (save-char): Received data for non-existing/offline character (%d:%d).\n"), aid, cid));
  chr->set_char_online(id, cid, aid);
 }

 if (RFIFOB(fd,12)) {

  chr->set_char_offline(cid, aid);
  chr->save_character_ack(fd, aid, cid);
 }
 RFIFOSKIP(fd,size);
}



void char_select_ack(int fd, int account_id, uint8 flag)
{
 WFIFOHEAD(fd,7);
 WFIFOW(fd,0) = 0x2b03;
 WFIFOL(fd,2) = account_id;
 WFIFOB(fd,6) = flag;
 WFIFOSET(fd,7);
}

void char_parse_frommap_char_select_req(int fd)
{
 int account_id = RFIFOL(fd,2);
 uint32 login_id1 = RFIFOL(fd,6);
 uint32 login_id2 = RFIFOL(fd,10);
 uint32 ip = RFIFOL(fd,14);
 int32 group_id = RFIFOL(fd, 18);
 RFIFOSKIP(fd,22);

 if( core->runflag != CHARSERVER_ST_RUNNING )
 {
  chr->select_ack(fd, account_id, 0);
 }
 else
 {
  struct char_auth_node* node;


  ((node) = (struct char_auth_node *) (iMalloc->calloc(((1)),(sizeof(struct char_auth_node)),"../../../server-code/src/char/char.c", 3147, __func__)));
  node->account_id = account_id;
  node->char_id = 0;
  node->login_id1 = login_id1;
  node->login_id2 = login_id2;
  node->group_id = group_id;

  node->ip = ntohl(ip);



  ( (auth_db)->put((auth_db),DB->i2key(account_id),DB->ptr2data(node),
# 3158 "../../../server-code/src/char/char.c" 3 4
 ((void *)0)
# 3158 "../../../server-code/src/char/char.c"
 ) );


  chr->set_char_charselect(account_id);
  chr->select_ack(fd, account_id, 1);
 }
}

void char_change_map_server_ack(int fd, const uint8 *data, 
# 3166 "../../../server-code/src/char/char.c" 3 4
                                                          _Bool 
# 3166 "../../../server-code/src/char/char.c"
                                                               ok)
{
 WFIFOHEAD(fd,30);
 WFIFOW(fd,0) = 0x2b06;
 memcpy(WFIFOP(fd,2), data, 28);
 if (!ok)
  WFIFOL(fd,6) = 0;
 WFIFOSET(fd,30);
}

void char_parse_frommap_change_map_server(int fd)
{
 int map_id, map_fd = -1;
 struct mmo_charstatus* char_data;

 map_id = chr->search_mapserver(RFIFOW(fd,18), ntohl(RFIFOL(fd,24)), ntohs(RFIFOW(fd,28)));
 if (map_id >= 0)
  map_fd = chr->server[map_id].fd;

 char_data = (struct mmo_charstatus*)( DB->data2ptr((chr->char_db_)->get((chr->char_db_),DB->ui2key(RFIFOL(fd,14)))) );
 if (char_data == 
# 3186 "../../../server-code/src/char/char.c" 3 4
                 ((void *)0)
# 3186 "../../../server-code/src/char/char.c"
                     ) {

  struct mmo_charstatus char_dat;
  chr->mmo_char_fromsql(RFIFOL(fd,14), &char_dat, 
# 3189 "../../../server-code/src/char/char.c" 3 4
                                                 1
# 3189 "../../../server-code/src/char/char.c"
                                                     );
  char_data = (struct mmo_charstatus*)( DB->data2ptr((chr->char_db_)->get((chr->char_db_),DB->ui2key(RFIFOL(fd,14)))) );
 }

 if (core->runflag == CHARSERVER_ST_RUNNING && sockt->session_is_active(map_fd) && char_data) {

  struct online_char_data* data;
  struct char_auth_node* node;


  char_data->last_point.map = RFIFOW(fd,18);
  char_data->last_point.x = RFIFOW(fd,20);
  char_data->last_point.y = RFIFOW(fd,22);
  char_data->sex = RFIFOB(fd,30);


  ((node) = (struct char_auth_node *) (iMalloc->calloc(((1)),(sizeof(struct char_auth_node)),"../../../server-code/src/char/char.c", 3205, __func__)));
  node->account_id = RFIFOL(fd,2);
  node->char_id = RFIFOL(fd,14);
  node->login_id1 = RFIFOL(fd,6);
  node->login_id2 = RFIFOL(fd,10);
  node->sex = RFIFOB(fd,30);
  node->expiration_time = 0;
  node->ip = ntohl(RFIFOL(fd,31));
  node->group_id = RFIFOL(fd,35);
  node->changing_mapservers = 1;
  ( (auth_db)->put((auth_db),DB->i2key(RFIFOL(fd,2)),DB->ptr2data(node),
# 3215 "../../../server-code/src/char/char.c" 3 4
 ((void *)0)
# 3215 "../../../server-code/src/char/char.c"
 ) );

  data = ( DB->data2ptr((chr->online_char_db)->ensure((chr->online_char_db),DB->i2key(RFIFOL(fd,2)),(chr->create_online_char_data))) );
  data->char_id = char_data->char_id;
  data->server = map_id;


  chr->change_map_server_ack(fd, RFIFOP(fd,2), 
# 3222 "../../../server-code/src/char/char.c" 3 4
                                              1
# 3222 "../../../server-code/src/char/char.c"
                                                  );
 } else {
  chr->change_map_server_ack(fd, RFIFOP(fd,2), 
# 3224 "../../../server-code/src/char/char.c" 3 4
                                              0
# 3224 "../../../server-code/src/char/char.c"
                                                   );
 }
 RFIFOSKIP(fd,39);
}

void char_parse_frommap_remove_friend(int fd)
{
 int char_id = RFIFOL(fd,2);
 int friend_id = RFIFOL(fd,6);
 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `char_id`='%d' AND `friend_id`='%d' LIMIT 1",
  friend_db, char_id, friend_id) ) {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 3235));
 }
 RFIFOSKIP(fd,10);
}

void char_char_name_ack(int fd, int char_id)
{
 WFIFOHEAD(fd,30);
 WFIFOW(fd,0) = 0x2b09;
 WFIFOL(fd,2) = char_id;
 chr->loadName(char_id, WFIFOP(fd,6));
 WFIFOSET(fd,30);
}

void char_parse_frommap_char_name_request(int fd)
{
 chr->char_name_ack(fd, RFIFOL(fd,2));
 RFIFOSKIP(fd,6);
}

void char_parse_frommap_change_email(int fd)
{
 if (chr->login_fd > 0) {
  WFIFOHEAD(chr->login_fd,86);
  memcpy(WFIFOP(chr->login_fd,0), RFIFOP(fd,0),86);
  WFIFOW(chr->login_fd,0) = 0x2722;
  WFIFOSET(chr->login_fd,86);
 }
 RFIFOSKIP(fd, 86);
}

void mapif_char_ban(int char_id, time_t timestamp)
{
 unsigned char buf[11];
 WBUFW(buf,0) = 0x2b14;
 WBUFL(buf,2) = char_id;
 WBUFB(buf,6) = 2;
 WBUFL(buf,7) = (unsigned int)timestamp;
 mapif->sendall(buf, 11);
}

void char_ban(int account_id, int char_id, time_t *unban_time, short year, short month, short day, short hour, short minute, short second)
{
 time_t timestamp;
 struct tm *tmtime;
 struct SqlStmt *stmt = SQL->StmtMalloc(inter->sql_handle);

 do { if (((void)(unban_time), 
# 3282 "../../../server-code/src/char/char.c" 3 4
0
# 3282 "../../../server-code/src/char/char.c"
)) return; } while(0);

 if (*unban_time == 0 || *unban_time < time(
# 3284 "../../../server-code/src/char/char.c" 3 4
                                           ((void *)0)
# 3284 "../../../server-code/src/char/char.c"
                                               ))
  timestamp = time(
# 3285 "../../../server-code/src/char/char.c" 3 4
                  ((void *)0)
# 3285 "../../../server-code/src/char/char.c"
                      );
 else
  timestamp = *unban_time;

 tmtime = localtime(&timestamp);
 tmtime->tm_year = tmtime->tm_year + year;
 tmtime->tm_mon = tmtime->tm_mon + month;
 tmtime->tm_mday = tmtime->tm_mday + day;
 tmtime->tm_hour = tmtime->tm_hour + hour;
 tmtime->tm_min = tmtime->tm_min + minute;
 tmtime->tm_sec = tmtime->tm_sec + second;
 timestamp = mktime(tmtime);

 if( 0 != SQL->StmtPrepare(stmt,
  "UPDATE `%s` SET `unban_time` = ? WHERE `char_id` = ? LIMIT 1",
  char_db)
    || 0 != SQL->StmtBindParam(stmt, 0, SQLDT_LONG, &timestamp, sizeof(timestamp))
    || 0 != SQL->StmtBindParam(stmt, 1, SQLDT_INT, &char_id, sizeof(char_id))
    || 0 != SQL->StmtExecute(stmt)
 ) {
  (SQL->StmtShowDebug_((stmt), "../../../server-code/src/char/char.c", 3305));
 }

 SQL->StmtFree(stmt);


 if( timestamp > time(
# 3311 "../../../server-code/src/char/char.c" 3 4
                     ((void *)0)
# 3311 "../../../server-code/src/char/char.c"
                         ) ) {
  mapif->char_ban(char_id, timestamp);

  chr->disconnect_player(account_id);
 }
}

void char_unban(int char_id, int *result)
{

 if( (-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `unban_time` = '0' WHERE `char_id` = '%d' LIMIT 1", char_db, char_id) ) {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 3322));
  if (result)
   *result = 1;
 }
}

void char_ask_name_ack(int fd, int acc, const char* name, int type, int result)
{
 do { if (((void)(name), 
# 3330 "../../../server-code/src/char/char.c" 3 4
0
# 3330 "../../../server-code/src/char/char.c"
)) return; } while(0);
 WFIFOHEAD(fd,34);
 WFIFOW(fd,0) = 0x2b0f;
 WFIFOL(fd, 2) = acc;
 (strlib->safestrncpy_((WFIFOP(fd,6)),(name),((23 + 1))));
 WFIFOW(fd,30) = type;
 WFIFOW(fd,32) = result;
 WFIFOSET(fd,34);
}
# 3350 "../../../server-code/src/char/char.c"
int char_changecharsex(int char_id, int sex)
{
 int class_ = 0, guild_id = 0, account_id = 0;
 char *data;


 if ((-1) == SQL->Query(inter->sql_handle, "SELECT `account_id`,`class`,`guild_id` FROM `%s` WHERE `char_id` = '%d'", char_db, char_id)) {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 3357));
  return 1;
 }
 if (SQL->NumRows(inter->sql_handle) != 1 || (-1) == SQL->NextRow(inter->sql_handle)) {
  SQL->FreeResult(inter->sql_handle);
  return 1;
 }
 SQL->GetData(inter->sql_handle, 0, &data, 
# 3364 "../../../server-code/src/char/char.c" 3 4
                                          ((void *)0)
# 3364 "../../../server-code/src/char/char.c"
                                              ); account_id = atoi(data);
 SQL->GetData(inter->sql_handle, 1, &data, 
# 3365 "../../../server-code/src/char/char.c" 3 4
                                          ((void *)0)
# 3365 "../../../server-code/src/char/char.c"
                                              ); class_ = atoi(data);
 SQL->GetData(inter->sql_handle, 2, &data, 
# 3366 "../../../server-code/src/char/char.c" 3 4
                                          ((void *)0)
# 3366 "../../../server-code/src/char/char.c"
                                              ); guild_id = atoi(data);
 SQL->FreeResult(inter->sql_handle);

 if ((-1) == SQL->Query(inter->sql_handle, "UPDATE `%s` SET `sex` = '%c' WHERE `char_id` = '%d'", char_db, sex == SEX_MALE ? 'M' : 'F', char_id)) {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 3370));
  return 1;
 }
 char_change_sex_sub(sex, account_id, char_id, class_, guild_id);


 chr->disconnect_player(account_id);


 chr->changesex(account_id, sex);
 return 0;
}

void char_parse_frommap_change_account(int fd)
{
 int result = 0;
 char esc_name[(23 + 1)*2+1];

 int acc = RFIFOL(fd,2);
 const char *name = RFIFOP(fd,6);
 int type = RFIFOW(fd,30);
 short year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
 int sex = SEX_MALE;
 if (type == 2 || type == 6) {
  year = RFIFOW(fd,32);
  month = RFIFOW(fd,34);
  day = RFIFOW(fd,36);
  hour = RFIFOW(fd,38);
  minute = RFIFOW(fd,40);
  second = RFIFOW(fd,42);
 } else if (type == 8) {
  sex = RFIFOB(fd, 32);
 }
 RFIFOSKIP(fd,44);

 SQL->EscapeStringLen(inter->sql_handle, esc_name, name, (strlib->strnlen_((name),((23 + 1)))));

 if((-1) == SQL->Query(inter->sql_handle, "SELECT `account_id`,`char_id`,`unban_time` FROM `%s` WHERE `name` = '%s'", char_db, esc_name)) {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 3408));
 } else if (SQL->NumRows(inter->sql_handle) == 0) {
  SQL->FreeResult(inter->sql_handle);
  result = 1;
 } else if (0 != SQL->NextRow(inter->sql_handle)) {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 3413));
  SQL->FreeResult(inter->sql_handle);
  result = 1;
 } else {
  int account_id, char_id;
  char *data;
  time_t unban_time;

  SQL->GetData(inter->sql_handle, 0, &data, 
# 3421 "../../../server-code/src/char/char.c" 3 4
                                           ((void *)0)
# 3421 "../../../server-code/src/char/char.c"
                                               ); account_id = atoi(data);
  SQL->GetData(inter->sql_handle, 1, &data, 
# 3422 "../../../server-code/src/char/char.c" 3 4
                                           ((void *)0)
# 3422 "../../../server-code/src/char/char.c"
                                               ); char_id = atoi(data);
  SQL->GetData(inter->sql_handle, 2, &data, 
# 3423 "../../../server-code/src/char/char.c" 3 4
                                           ((void *)0)
# 3423 "../../../server-code/src/char/char.c"
                                               ); unban_time = atol(data);
  SQL->FreeResult(inter->sql_handle);

  if( chr->login_fd <= 0 ) {
   result = 3;




  } else {
   switch (type) {
   case CHAR_ASK_NAME_BLOCK:
    loginif->block_account(account_id, 5);
    break;
   case CHAR_ASK_NAME_BAN:
    loginif->ban_account(account_id, year, month, day, hour, minute, second);
    break;
   case CHAR_ASK_NAME_UNBLOCK:
    loginif->block_account(account_id, 0);
    break;
   case CHAR_ASK_NAME_UNBAN:
    loginif->unban_account(account_id);
    break;
   case CHAR_ASK_NAME_CHANGESEX:
    loginif->changesex(account_id);
    break;
   case CHAR_ASK_NAME_CHARBAN:

    chr->ban(account_id, char_id, &unban_time, year, month, day, hour, minute, second);
    break;
   case CHAR_ASK_NAME_CHARUNBAN:
    chr->unban(char_id, &result);
    break;
   case CHAR_ASK_NAME_CHANGECHARSEX:
    result = chr->changecharsex(char_id, sex);
    break;
   }
  }
 }


 if (acc != -1 && type != CHAR_ASK_NAME_CHANGESEX && type != CHAR_ASK_NAME_CHANGECHARSEX) {
  chr->ask_name_ack(fd, acc, name, type, result);
 }
}

void char_parse_frommap_fame_list(int fd)
{
 int cid = RFIFOL(fd, 2);
 int fame = RFIFOL(fd, 6);
 char type = RFIFOB(fd, 10);
 int size;
 struct fame_list* list;
 int player_pos;
 int fame_pos;

 switch(type) {
  case RANKTYPE_BLACKSMITH: size = fame_list_size_smith; list = smith_fame_list; break;
  case RANKTYPE_ALCHEMIST: size = fame_list_size_chemist; list = chemist_fame_list; break;
  case RANKTYPE_TAEKWON: size = fame_list_size_taekwon; list = taekwon_fame_list; break;
  default: size = 0; list = 
# 3483 "../../../server-code/src/char/char.c" 3 4
                                                                 ((void *)0)
# 3483 "../../../server-code/src/char/char.c"
                                                                     ; break;
 }

 if (!list) {
  RFIFOSKIP(fd, 11);
  return;
 }
 do { for ((player_pos) = (0); (player_pos) < (size); ++(player_pos)) if (list[player_pos].id == cid) break; } while(
# 3490 "../../../server-code/src/char/char.c" 3 4
0
# 3490 "../../../server-code/src/char/char.c"
);
 do { for ((fame_pos) = (0); (fame_pos) < (size); ++(fame_pos)) if (list[fame_pos].fame <= fame) break; } while(
# 3491 "../../../server-code/src/char/char.c" 3 4
0
# 3491 "../../../server-code/src/char/char.c"
);

 if( player_pos == size && fame_pos == size )
  ;
 else if( fame_pos == player_pos ) {

  list[player_pos].fame = fame;
  chr->update_fame_list(type, player_pos, fame);
 } else {

  if( player_pos == size ) {

   do { if ((size - 1) != (fame_pos)) { struct fame_list _backup_; memmove(&_backup_, (list)+(size - 1), sizeof(struct fame_list)); if ((size - 1) < (fame_pos)) memmove((list)+(size - 1), (list)+(size - 1)+1, ((fame_pos)-(size - 1))*sizeof(struct fame_list)); else if ((size - 1) > (fame_pos)) memmove((list)+(fame_pos)+1, (list)+(fame_pos), ((size - 1)-(fame_pos))*sizeof(struct fame_list)); memmove((list)+(fame_pos), &_backup_, sizeof(struct fame_list)); } } while(
# 3503 "../../../server-code/src/char/char.c" 3 4
  0
# 3503 "../../../server-code/src/char/char.c"
  );
   list[fame_pos].id = cid;
   list[fame_pos].fame = fame;
   chr->loadName(cid, list[fame_pos].name);
  } else {

   if( fame_pos == size )
    --fame_pos;
   do { if ((player_pos) != (fame_pos)) { struct fame_list _backup_; memmove(&_backup_, (list)+(player_pos), sizeof(struct fame_list)); if ((player_pos) < (fame_pos)) memmove((list)+(player_pos), (list)+(player_pos)+1, ((fame_pos)-(player_pos))*sizeof(struct fame_list)); else if ((player_pos) > (fame_pos)) memmove((list)+(fame_pos)+1, (list)+(fame_pos), ((player_pos)-(fame_pos))*sizeof(struct fame_list)); memmove((list)+(fame_pos), &_backup_, sizeof(struct fame_list)); } } while(
# 3511 "../../../server-code/src/char/char.c" 3 4
  0
# 3511 "../../../server-code/src/char/char.c"
  );
   list[fame_pos].fame = fame;
  }
  chr->send_fame_list(-1);
 }

 RFIFOSKIP(fd,11);
}

void char_parse_frommap_divorce_char(int fd)
{
 chr->divorce_char_sql(RFIFOL(fd,2), RFIFOL(fd,6));
 RFIFOSKIP(fd,10);
}

void char_parse_frommap_ragsrvinfo(int fd)
{
 char esc_server_name[sizeof(chr->server_name)*2+1];

 SQL->EscapeString(inter->sql_handle, esc_server_name, chr->server_name);

 if( (-1) == SQL->Query(inter->sql_handle, "INSERT INTO `%s` SET `index`='%d',`name`='%s',`exp`='%u',`jexp`='%u',`drop`='%u'",
  ragsrvinfo_db, fd, esc_server_name, RFIFOL(fd,2), RFIFOL(fd,6), RFIFOL(fd,10)) )
 {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 3535));
 }
 RFIFOSKIP(fd,14);
}

void char_parse_frommap_set_char_offline(int fd)
{
 chr->set_char_offline(RFIFOL(fd,2),RFIFOL(fd,6));
 RFIFOSKIP(fd,10);
}

void char_parse_frommap_set_all_offline(int fd, int id)
{
 chr->set_all_offline(id);
 RFIFOSKIP(fd,2);
}

void char_parse_frommap_set_char_online(int fd, int id)
{
 chr->set_char_online(id, RFIFOL(fd,2),RFIFOL(fd,6));
 RFIFOSKIP(fd,10);
}

void char_parse_frommap_build_fame_list(int fd)
{
 chr->read_fame_list();
 chr->send_fame_list(-1);
 RFIFOSKIP(fd,2);
}

void char_parse_frommap_save_status_change_data(int fd)
{

 int aid = RFIFOL(fd, 4);
 int cid = RFIFOL(fd, 8);
 int count = RFIFOW(fd, 12);


 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `account_id` = '%d' AND `char_id`='%d'", scdata_db, aid, cid) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 3574));

 if( count > 0 )
 {
  struct status_change_data data;
  StringBuf buf;
  int i;

  StrBuf->Init(&buf);
  StrBuf->Printf(&buf, "INSERT INTO `%s` (`account_id`, `char_id`, `type`, `tick`, `val1`, `val2`, `val3`, `val4`) VALUES ", scdata_db);
  for( i = 0; i < count; ++i )
  {
   memcpy (&data, RFIFOP(fd, 14+i*sizeof(struct status_change_data)), sizeof(struct status_change_data));
   if( i > 0 )
    StrBuf->AppendStr(&buf, ", ");
   StrBuf->Printf(&buf, "('%d','%d','%hu','%d','%d','%d','%d','%d')", aid, cid,
    data.type, data.tick, data.val1, data.val2, data.val3, data.val4);
  }
  if( (-1) == SQL->QueryStr(inter->sql_handle, StrBuf->Value(&buf)) )
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 3593));
  StrBuf->Destroy(&buf);
 }

 RFIFOSKIP(fd, RFIFOW(fd, 2));
}

void char_send_pong(int fd)
{
 WFIFOHEAD(fd,2);
 WFIFOW(fd,0) = 0x2b24;
 WFIFOSET(fd,2);
}

void char_parse_frommap_ping(int fd)
{
 chr->send_pong(fd);
 RFIFOSKIP(fd,2);
}

void char_map_auth_ok(int fd, int account_id, struct char_auth_node* node, struct mmo_charstatus* cd)
{
 do { if (((void)(cd), 
# 3615 "../../../server-code/src/char/char.c" 3 4
0
# 3615 "../../../server-code/src/char/char.c"
)) return; } while(0);
 WFIFOHEAD(fd,25 + sizeof(struct mmo_charstatus));
 WFIFOW(fd,0) = 0x2afd;
 WFIFOW(fd,2) = 25 + sizeof(struct mmo_charstatus);
 WFIFOL(fd,4) = account_id;
 if (node)
 {
  WFIFOL(fd,8) = node->login_id1;
  WFIFOL(fd,12) = node->login_id2;
  WFIFOL(fd,16) = (uint32)node->expiration_time;
  WFIFOL(fd,20) = node->group_id;
  WFIFOB(fd,24) = node->changing_mapservers;
 }
 else
 {
  WFIFOL(fd,8) = 0;
  WFIFOL(fd,12) = 0;
  WFIFOL(fd,16) = 0;
  WFIFOL(fd,20) = 0;
  WFIFOB(fd,24) = 0;
 }
 memcpy(WFIFOP(fd,25), cd, sizeof(struct mmo_charstatus));
 WFIFOSET(fd, WFIFOW(fd,2));
}

void char_map_auth_failed(int fd, int account_id, int char_id, int login_id1, char sex, uint32 ip)
{
 WFIFOHEAD(fd,19);
 WFIFOW(fd,0) = 0x2b27;
 WFIFOL(fd,2) = account_id;
 WFIFOL(fd,6) = char_id;
 WFIFOL(fd,10) = login_id1;
 WFIFOB(fd,14) = sex;
 WFIFOL(fd,15) = htonl(ip);
 WFIFOSET(fd,19);
}

void char_parse_frommap_auth_request(int fd, int id)
{
 struct mmo_charstatus char_dat;
 struct char_auth_node* node;
 struct mmo_charstatus* cd;

 int account_id = RFIFOL(fd,2);
 int char_id = RFIFOL(fd,6);
 int login_id1 = RFIFOL(fd,10);
 char sex = RFIFOB(fd,14);
 uint32 ip = ntohl(RFIFOL(fd,15));
 char standalone = RFIFOB(fd, 19);
 RFIFOSKIP(fd,20);

 node = (struct char_auth_node*)( DB->data2ptr((auth_db)->get((auth_db),DB->i2key(account_id))) );
 cd = (struct mmo_charstatus*)( DB->data2ptr((chr->char_db_)->get((chr->char_db_),DB->ui2key(char_id))) );

 if( cd == 
# 3669 "../../../server-code/src/char/char.c" 3 4
          ((void *)0) 
# 3669 "../../../server-code/src/char/char.c"
               ) {
  chr->mmo_char_fromsql(char_id, &char_dat, 
# 3670 "../../../server-code/src/char/char.c" 3 4
                                           1
# 3670 "../../../server-code/src/char/char.c"
                                               );
  cd = (struct mmo_charstatus*)( DB->data2ptr((chr->char_db_)->get((chr->char_db_),DB->ui2key(char_id))) );
 }

 if( core->runflag == CHARSERVER_ST_RUNNING && cd && standalone ) {
  cd->sex = sex;

  chr->map_auth_ok(fd, account_id, 
# 3677 "../../../server-code/src/char/char.c" 3 4
                                  ((void *)0)
# 3677 "../../../server-code/src/char/char.c"
                                      , cd);
  chr->set_char_online(id, char_id, account_id);
  return;
 }

 if( core->runflag == CHARSERVER_ST_RUNNING &&
  cd != 
# 3683 "../../../server-code/src/char/char.c" 3 4
       ((void *)0) 
# 3683 "../../../server-code/src/char/char.c"
            &&
  node != 
# 3684 "../../../server-code/src/char/char.c" 3 4
         ((void *)0) 
# 3684 "../../../server-code/src/char/char.c"
              &&
  node->account_id == account_id &&
  node->char_id == char_id &&
  node->login_id1 == login_id1

                   )
 {
  if( cd->sex == 99 )
   cd->sex = sex;

  chr->map_auth_ok(fd, account_id, node, cd);

  ( (auth_db)->remove((auth_db),DB->i2key(account_id),
# 3696 "../../../server-code/src/char/char.c" 3 4
 ((void *)0)
# 3696 "../../../server-code/src/char/char.c"
 ) );
  chr->set_char_online(id, char_id, account_id);
 }
 else
 {
  chr->map_auth_failed(fd, account_id, char_id, login_id1, sex, ip);
 }
}

void char_parse_frommap_update_ip(int fd, int id)
{
 chr->server[id].ip = ntohl(RFIFOL(fd, 2));
 (showmsg->showInfo(("Updated IP address of map-server #%d to %u.%u.%u.%u.\n"), id, CONVIP(chr->server[id].ip)));
 RFIFOSKIP(fd,6);
}

void char_parse_frommap_request_stats_report(int fd)
{
 int sfd;
 struct hSockOpt opt;
 RFIFOSKIP(fd, 2);

 opt.silent = 1;
 opt.setTimeo = 1;

 if ((sfd = sockt->make_connection(sockt->host2ip("stats.herc.ws"),(uint16)25427,&opt) ) == -1) {
  RFIFOSKIP(fd, RFIFOW(fd,2) );
  RFIFOFLUSH(fd);
  return;
 }

 sockt->session[sfd]->flag.server = 1;
 sockt->realloc_fifo(sfd, FIFOSIZE_SERVERLINK, FIFOSIZE_SERVERLINK);

 WFIFOHEAD(sfd, RFIFOW(fd,2) );

 memcpy(WFIFOP(sfd,0), RFIFOP(fd, 0), RFIFOW(fd,2));

 WFIFOSET(sfd, RFIFOW(fd,2) );

 do {
  sockt->flush(sfd);
  sleep(1);
 } while( !sockt->session[sfd]->flag.eof && sockt->session[sfd]->wdata_size );

 sockt->close(sfd);

 RFIFOSKIP(fd, RFIFOW(fd,2) );
 RFIFOFLUSH(fd);
}

void char_parse_frommap_scdata_update(int fd)
{
 int account_id = RFIFOL(fd, 2);
 int char_id = RFIFOL(fd, 6);
 int val1 = RFIFOL(fd, 12);
 int val2 = RFIFOL(fd, 16);
 int val3 = RFIFOL(fd, 20);
 int val4 = RFIFOL(fd, 24);
 short type = RFIFOW(fd, 10);

 if ((-1) == SQL->Query(inter->sql_handle, "REPLACE INTO `%s`"
   " (`account_id`,`char_id`,`type`,`tick`,`val1`,`val2`,`val3`,`val4`)"
   " VALUES ('%d','%d','%d','%d','%d','%d','%d','%d')",
   scdata_db, account_id, char_id, type, (-1), val1, val2, val3, val4)
 ) {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 3762));
 }
 RFIFOSKIP(fd, 28);
}

void char_parse_frommap_scdata_delete(int fd)
{
 int account_id = RFIFOL(fd, 2);
 int char_id = RFIFOL(fd, 6);
 short type = RFIFOW(fd, 10);

 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `account_id` = '%d' AND `char_id` = '%d' AND `type` = '%d' LIMIT 1",
        scdata_db, account_id, char_id, type) )
 {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 3776));
 }
 RFIFOSKIP(fd, 12);
}

int char_parse_frommap(int fd)
{
 int id;

 do { for ((id) = (0); (id) < (( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) )); ++(id)) if (chr->server[id].fd == fd) break; } while(
# 3785 "../../../server-code/src/char/char.c" 3 4
0
# 3785 "../../../server-code/src/char/char.c"
);
 if( id == ( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) ) ) {
  (showmsg->showDebug(("chr->parse_frommap: Disconnecting invalid session #%d (is not a map-server)\n"), fd));
  sockt->close(fd);
  return 0;
 }
 if( sockt->session[fd]->flag.eof ) {
  sockt->close(fd);
  chr->server[id].fd = -1;
  mapif->on_disconnect(id);
  return 0;
 }

 while (RFIFOREST(fd) >= 2) {
  int packet_id = RFIFOW(fd,0);
  if (( (HPM->packets[hpParse_FromMap])._len_ ) > 0) {
   int result = HPM->parse_packets(fd,packet_id,hpParse_FromMap);
   if (result == 1)
    continue;
   if (result == 2)
    return 0;
  }

  switch (packet_id) {
   case 0x2b0a:
    if( RFIFOREST(fd) < RFIFOW(fd, 2) )
     return 0;
    chr->parse_frommap_datasync(fd);
    break;

   case 0x2b0b:
    if( RFIFOREST(fd) < RFIFOW(fd, 2) )
     return 0;
    chr->parse_frommap_skillid2idx(fd);
    break;
   case 0x2afa:
    if (RFIFOREST(fd) < 4 || RFIFOREST(fd) < RFIFOW(fd,2))
     return 0;
    chr->parse_frommap_map_names(fd, id);
   break;

   case 0x2afc:
    if (RFIFOREST(fd) < 10)
     return 0;
   {
    chr->parse_frommap_request_scdata(fd);
   }
   break;

   case 0x2afe:
    if (RFIFOREST(fd) < 4)
     return 0;
    chr->parse_frommap_set_users_count(fd, id);
    break;

   case 0x2aff:
    if (RFIFOREST(fd) < 6 || RFIFOREST(fd) < RFIFOW(fd,2))
     return 0;
   {
    chr->parse_frommap_set_users(fd, id);
   }
   break;

   case 0x2b01:
    if (RFIFOREST(fd) < 4 || RFIFOREST(fd) < RFIFOW(fd,2))
     return 0;
   {
    chr->parse_frommap_save_character(fd, id);

   }
   break;

   case 0x2b02:
    if( RFIFOREST(fd) < 22 )
     return 0;
   {
    chr->parse_frommap_char_select_req(fd);
   }
   break;

   case 0x2b05:
    if (RFIFOREST(fd) < 39)
     return 0;
   {
    chr->parse_frommap_change_map_server(fd);
   }
   break;

   case 0x2b07:
    if (RFIFOREST(fd) < 10)
     return 0;
    {
     chr->parse_frommap_remove_friend(fd);
    }
   break;

   case 0x2b08:
    if (RFIFOREST(fd) < 6)
     return 0;

    chr->parse_frommap_char_name_request(fd);
   break;

   case 0x2b0c:
    if (RFIFOREST(fd) < 86)
     return 0;
    chr->parse_frommap_change_email(fd);
   break;

   case 0x2b0e:
    if (RFIFOREST(fd) < 44)
     return 0;
   {
    chr->parse_frommap_change_account(fd);
   }
   break;

   case 0x2b10:
    if (RFIFOREST(fd) < 11)
     return 0;
   {
    chr->parse_frommap_fame_list(fd);
   }
   break;


   case 0x2b11:
    if( RFIFOREST(fd) < 10 )
     return 0;

    chr->parse_frommap_divorce_char(fd);
   break;

   case 0x2b16:
    if( RFIFOREST(fd) < 14 )
     return 0;
   {
    chr->parse_frommap_ragsrvinfo(fd);
   }
   break;

   case 0x2b17:
    if (RFIFOREST(fd) < 6)
     return 0;
    chr->parse_frommap_set_char_offline(fd);
   break;

   case 0x2b18:
    chr->parse_frommap_set_all_offline(fd, id);
   break;

   case 0x2b19:
    if (RFIFOREST(fd) < 10)
     return 0;
    chr->parse_frommap_set_char_online(fd, id);
   break;

   case 0x2b1a:
    if (RFIFOREST(fd) < 2)
     return 0;
    chr->parse_frommap_build_fame_list(fd);
   break;

   case 0x2b1c:
    if (RFIFOREST(fd) < 4 || RFIFOREST(fd) < RFIFOW(fd,2))
     return 0;
   {
    chr->parse_frommap_save_status_change_data(fd);
   }
   break;

   case 0x2b23:
    chr->parse_frommap_ping(fd);
   break;

   case 0x2b26:
    if (RFIFOREST(fd) < 20)
     return 0;

   {
    chr->parse_frommap_auth_request(fd, id);
   }
   break;

   case 0x2736:
    if (RFIFOREST(fd) < 6) return 0;
    chr->parse_frommap_update_ip(fd, id);
   break;

   case 0x3008:
    if( RFIFOREST(fd) < RFIFOW(fd,4) )
     return 0;
    else {
     chr->parse_frommap_request_stats_report(fd);
   }
   break;


   case 0x2740:
    if( RFIFOREST(fd) < 28 )
     return 0;
    else {
     chr->parse_frommap_scdata_update(fd);
    }
    break;


   case 0x2741:
    if( RFIFOREST(fd) < 12 )
     return 0;
    else {
     chr->parse_frommap_scdata_delete(fd);
    }
    break;

   default:
   {

    int r = inter->parse_frommap(fd);
    if (r == 1) break;
    if (r == 2) return 0;


    (showmsg->showError(("Unknown packet 0x%04x from map server, disconnecting.\n"), RFIFOW(fd,0)));
    sockt->eof(fd);
    return 0;
   }
  }
 }

 return 0;
}

void do_init_mapif(void)
{
 int i;
 for( i = 0; i < ( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) ); ++i )
  mapif->server_init(i);
}

void do_final_mapif(void)
{
 int i;
 for( i = 0; i < ( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) ); ++i )
  mapif->server_destroy(i);
}



int char_search_mapserver(unsigned short map, uint32 ip, uint16 port)
{
 int i, j;

 for(i = 0; i < ( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) ); i++)
 {
  if (chr->server[i].fd > 0
  && (ip == (uint32)-1 || chr->server[i].ip == ip)
  && (port == (uint16)-1 || chr->server[i].port == port)
  ) {
   do { for ((j) = (0); (j) < (( (chr->server[i].maps)._len_ )); ++(j)) if (( ( (chr->server[i].maps)._data_ )[j] ) == map) break; } while(
# 4044 "../../../server-code/src/char/char.c" 3 4
  0
# 4044 "../../../server-code/src/char/char.c"
  );
   if (j != ( (chr->server[i].maps)._len_ ))
    return i;
  }
 }

 return -1;
}


static int char_mapif_init(int fd)
{
 return inter->mapif_init(fd);
}
# 4066 "../../../server-code/src/char/char.c"
uint32 char_lan_subnet_check(uint32 ip)
{
 struct s_subnet lan = {0};
 if (sockt->lan_subnet_check(ip, &lan)) {
  (showmsg->showInfo(("Subnet check [%u.%u.%u.%u]: Matches ""\033[1;36m""%u.%u.%u.%u/%u.%u.%u.%u""\033[0m""\n"), CONVIP(ip), CONVIP(lan.ip & lan.mask), CONVIP(lan.mask)));
  return lan.ip;
 }
 (showmsg->showInfo(("Subnet check [%u.%u.%u.%u]: ""\033[1;36m""WAN""\033[0m""\n"), CONVIP(ip)));
 return 0;
}
# 4086 "../../../server-code/src/char/char.c"
void char_delete2_ack(int fd, int char_id, uint32 result, time_t delete_date)
{
 WFIFOHEAD(fd,14);
 WFIFOW(fd,0) = 0x828;
 WFIFOL(fd,2) = char_id;
 WFIFOL(fd,6) = result;

 WFIFOL(fd,10) = (int)(delete_date - time(
# 4093 "../../../server-code/src/char/char.c" 3 4
                                         ((void *)0)
# 4093 "../../../server-code/src/char/char.c"
                                             ));




 WFIFOSET(fd,14);
}

void char_delete2_accept_actual_ack(int fd, int char_id, uint32 result)
{
 WFIFOHEAD(fd,10);
 WFIFOW(fd,0) = 0x82a;
 WFIFOL(fd,2) = char_id;
 WFIFOL(fd,6) = result;
 WFIFOSET(fd,10);
}
# 4118 "../../../server-code/src/char/char.c"
void char_delete2_accept_ack(int fd, int char_id, uint32 result)
{

 if( result == 1 ) {
  struct char_session_data* sd = (struct char_session_data*)sockt->session[fd]->session_data;
  chr->mmo_char_send099d(fd, sd);
 }

 chr->delete2_accept_actual_ack(fd, char_id, result);
}





void char_delete2_cancel_ack(int fd, int char_id, uint32 result)
{
 WFIFOHEAD(fd,10);
 WFIFOW(fd,0) = 0x82c;
 WFIFOL(fd,2) = char_id;
 WFIFOL(fd,6) = result;
 WFIFOSET(fd,10);
}

static void char_delete2_req(int fd, struct char_session_data* sd)
{
 int char_id, i;
 char* data;
 time_t delete_date;

 char_id = RFIFOL(fd,2);
 do { if (((void)(sd), 
# 4149 "../../../server-code/src/char/char.c" 3 4
0
# 4149 "../../../server-code/src/char/char.c"
)) return; } while(0);

 do { for ((i) = (0); (i) < (9); ++(i)) if (sd->found_char[i] == char_id) break; } while(
# 4151 "../../../server-code/src/char/char.c" 3 4
0
# 4151 "../../../server-code/src/char/char.c"
);
 if( i == 9 )
 {
  chr->delete2_ack(fd, char_id, 3, 0);
  return;
 }

 if( 0 != SQL->Query(inter->sql_handle, "SELECT `delete_date` FROM `%s` WHERE `char_id`='%d'", char_db, char_id) || 0 != SQL->NextRow(inter->sql_handle) )
 {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 4160));
  chr->delete2_ack(fd, char_id, 3, 0);
  return;
 }

 SQL->GetData(inter->sql_handle, 0, &data, 
# 4165 "../../../server-code/src/char/char.c" 3 4
                                          ((void *)0)
# 4165 "../../../server-code/src/char/char.c"
                                              ); delete_date = strtoul(data, 
# 4165 "../../../server-code/src/char/char.c" 3 4
                                                                             ((void *)0)
# 4165 "../../../server-code/src/char/char.c"
                                                                                 , 10);

 if( delete_date ) {
  chr->delete2_ack(fd, char_id, 0, 0);
  return;
 }




 if (char_aegis_delete) {
  int party_id = 0, guild_id = 0;
  if( 0 != SQL->Query(inter->sql_handle, "SELECT `party_id`, `guild_id` FROM `%s` WHERE `char_id`='%d'", char_db, char_id)
   || 0 != SQL->NextRow(inter->sql_handle)
  ) {
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 4180));
   chr->delete2_ack(fd, char_id, 3, 0);
   return;
  }
  SQL->GetData(inter->sql_handle, 0, &data, 
# 4184 "../../../server-code/src/char/char.c" 3 4
                                           ((void *)0)
# 4184 "../../../server-code/src/char/char.c"
                                               ); party_id = atoi(data);
  SQL->GetData(inter->sql_handle, 1, &data, 
# 4185 "../../../server-code/src/char/char.c" 3 4
                                           ((void *)0)
# 4185 "../../../server-code/src/char/char.c"
                                               ); guild_id = atoi(data);

  if( guild_id )
  {
   chr->delete2_ack(fd, char_id, 4, 0);
   return;
  }

  if( party_id )
  {
   chr->delete2_ack(fd, char_id, 5, 0);
   return;
  }
 }


 delete_date = time(
# 4201 "../../../server-code/src/char/char.c" 3 4
                   ((void *)0)
# 4201 "../../../server-code/src/char/char.c"
                       )+char_del_delay;

 if( 0 != SQL->Query(inter->sql_handle, "UPDATE `%s` SET `delete_date`='%lu' WHERE `char_id`='%d'", char_db, (unsigned long)delete_date, char_id) )
 {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 4205));
  chr->delete2_ack(fd, char_id, 3, 0);
  return;
 }

 chr->delete2_ack(fd, char_id, 1, delete_date);
}

static void char_delete2_accept(int fd, struct char_session_data* sd)
{
 char birthdate[8+1];
 int char_id, i;
 unsigned int base_level;
 char* data;
 time_t delete_date;

 do { if (((void)(sd), 
# 4221 "../../../server-code/src/char/char.c" 3 4
0
# 4221 "../../../server-code/src/char/char.c"
)) return; } while(0);
 char_id = RFIFOL(fd,2);

 (showmsg->showInfo(("\033[1;31m""Request Char Deletion: ""\033[1;32m""%d (%d)""\033[0m""\n"), sd->account_id, char_id));


 birthdate[0] = RFIFOB(fd,6);
 birthdate[1] = RFIFOB(fd,7);
 birthdate[2] = '-';
 birthdate[3] = RFIFOB(fd,8);
 birthdate[4] = RFIFOB(fd,9);
 birthdate[5] = '-';
 birthdate[6] = RFIFOB(fd,10);
 birthdate[7] = RFIFOB(fd,11);
 birthdate[8] = 0;

 do { for ((i) = (0); (i) < (9); ++(i)) if (sd->found_char[i] == char_id) break; } while(
# 4237 "../../../server-code/src/char/char.c" 3 4
0
# 4237 "../../../server-code/src/char/char.c"
);
 if( i == 9 )
 {
  chr->delete2_accept_ack(fd, char_id, 3);
  return;
 }

 if( 0 != SQL->Query(inter->sql_handle, "SELECT `base_level`,`delete_date` FROM `%s` WHERE `char_id`='%d'", char_db, char_id) || 0 != SQL->NextRow(inter->sql_handle) )
 {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 4246));
  chr->delete2_accept_ack(fd, char_id, 3);
  return;
 }

 SQL->GetData(inter->sql_handle, 0, &data, 
# 4251 "../../../server-code/src/char/char.c" 3 4
                                          ((void *)0)
# 4251 "../../../server-code/src/char/char.c"
                                              ); base_level = (unsigned int)strtoul(data, 
# 4251 "../../../server-code/src/char/char.c" 3 4
                                                                                          ((void *)0)
# 4251 "../../../server-code/src/char/char.c"
                                                                                              , 10);
 SQL->GetData(inter->sql_handle, 1, &data, 
# 4252 "../../../server-code/src/char/char.c" 3 4
                                          ((void *)0)
# 4252 "../../../server-code/src/char/char.c"
                                              ); delete_date = strtoul(data, 
# 4252 "../../../server-code/src/char/char.c" 3 4
                                                                             ((void *)0)
# 4252 "../../../server-code/src/char/char.c"
                                                                                 , 10);

 if( !delete_date || delete_date>time(
# 4254 "../../../server-code/src/char/char.c" 3 4
                                     ((void *)0)
# 4254 "../../../server-code/src/char/char.c"
                                         ) )
 {
  chr->delete2_accept_ack(fd, char_id, 4);
  return;
 }

 if( strcmp(sd->birthdate+2, birthdate) )
 {
  chr->delete2_accept_ack(fd, char_id, 5);
  return;
 }

 if( ( char_del_level > 0 && base_level >= (unsigned int)char_del_level ) || ( char_del_level < 0 && base_level <= (unsigned int)(-char_del_level) ) )
 {
  chr->delete2_accept_ack(fd, char_id, 2);
  return;
 }


 if( chr->delete_char_sql(char_id) < 0 )
 {
  chr->delete2_accept_ack(fd, char_id, 3);
  return;
 }


 sd->found_char[i] = -1;

 chr->delete2_accept_ack(fd, char_id, 1);
}

static void char_delete2_cancel(int fd, struct char_session_data* sd)
{
 int char_id, i;

 do { if (((void)(sd), 
# 4289 "../../../server-code/src/char/char.c" 3 4
0
# 4289 "../../../server-code/src/char/char.c"
)) return; } while(0);
 char_id = RFIFOL(fd,2);

 do { for ((i) = (0); (i) < (9); ++(i)) if (sd->found_char[i] == char_id) break; } while(
# 4292 "../../../server-code/src/char/char.c" 3 4
0
# 4292 "../../../server-code/src/char/char.c"
);
 if( i == 9 )
 {
  chr->delete2_cancel_ack(fd, char_id, 2);
  return;
 }




 if( 0 != SQL->Query(inter->sql_handle, "UPDATE `%s` SET `delete_date`='0' WHERE `char_id`='%d'", char_db, char_id) )
 {
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 4304));
  chr->delete2_cancel_ack(fd, char_id, 2);
  return;
 }

 chr->delete2_cancel_ack(fd, char_id, 1);
}

void char_send_account_id(int fd, int account_id)
{
 WFIFOHEAD(fd,4);
 WFIFOL(fd,0) = account_id;
 WFIFOSET(fd,4);
}

void char_parse_char_connect(int fd, struct char_session_data* sd, uint32 ipl)
{
 int account_id = RFIFOL(fd,2);
 uint32 login_id1 = RFIFOL(fd,6);
 uint32 login_id2 = RFIFOL(fd,10);
 int sex = RFIFOB(fd,16);
 struct char_auth_node* node;

 RFIFOSKIP(fd,17);

 (showmsg->showInfo(("request connect - account_id:%d/login_id1:%u/login_id2:%u\n"), account_id, login_id1, login_id2));

 if (sd) {



  return;
 }

 ((sockt->session[fd]->session_data) = (struct char_session_data *) (iMalloc->calloc(((1)),(sizeof(struct char_session_data)),"../../../server-code/src/char/char.c", 4338, __func__)));
 sd = (struct char_session_data*)sockt->session[fd]->session_data;
 sd->account_id = account_id;
 sd->login_id1 = login_id1;
 sd->login_id2 = login_id2;
 sd->sex = sex;
 sd->auth = 
# 4344 "../../../server-code/src/char/char.c" 3 4
           0
# 4344 "../../../server-code/src/char/char.c"
                ;


 chr->send_account_id(fd, account_id);

 if( core->runflag != CHARSERVER_ST_RUNNING ) {
  chr->auth_error(fd, 0);
  return;
 }


 node = (struct char_auth_node*)( DB->data2ptr((auth_db)->get((auth_db),DB->i2key(account_id))) );
 if( node != 
# 4356 "../../../server-code/src/char/char.c" 3 4
            ((void *)0) 
# 4356 "../../../server-code/src/char/char.c"
                 &&
  node->account_id == account_id &&
  node->login_id1 == login_id1 &&
  node->login_id2 == login_id2
                            )
 {

  if( chr->server_type == CST_MAINTENANCE && node->group_id < char_maintenance_min_group_id ) {
   chr->auth_error(fd, 0);
   return;
  }

  if( chr->server_type == CST_PAYING && (time_t)node->expiration_time < time(
# 4368 "../../../server-code/src/char/char.c" 3 4
                                                                            ((void *)0)
# 4368 "../../../server-code/src/char/char.c"
                                                                                ) ) {
   chr->auth_error(fd, 0);
   return;
  }
  ( (auth_db)->remove((auth_db),DB->i2key(account_id),
# 4372 "../../../server-code/src/char/char.c" 3 4
 ((void *)0)
# 4372 "../../../server-code/src/char/char.c"
 ) );
  chr->auth_ok(fd, sd);
 }
 else
 {
  if (chr->login_fd > 0) {
   loginif->auth(fd, sd, ipl);
  } else {
   chr->auth_error(fd, 0);
  }
 }
}

void char_send_map_info(int fd, int i, uint32 subnet_map_ip, struct mmo_charstatus *cd)
{
 do { if (((void)(cd), 
# 4387 "../../../server-code/src/char/char.c" 3 4
0
# 4387 "../../../server-code/src/char/char.c"
)) return; } while(0);
 WFIFOHEAD(fd,28);
 WFIFOW(fd,0) = 0x71;
 WFIFOL(fd,2) = cd->char_id;
 mapindex->getmapname_ext(mapindex->id2name((cd->last_point.map),"../../../server-code/src/char/char.c", 4391, __func__), WFIFOP(fd,6));
 WFIFOL(fd,22) = htonl((subnet_map_ip) ? subnet_map_ip : chr->server[i].ip);
 WFIFOW(fd,26) = sockt->ntows(htons(chr->server[i].port));
 WFIFOSET(fd,28);
}

void char_send_wait_char_server(int fd)
{
 WFIFOHEAD(fd, 24);
 WFIFOW(fd,0) = 0x840;
 WFIFOW(fd,2) = 24;
 (strlib->safestrncpy_((WFIFOP(fd,4)),("0"),(20)));
 WFIFOSET(fd, 24);
}

int char_search_default_maps_mapserver(struct mmo_charstatus *cd)
{
 int i;
 int j;
 do { if (((void)(cd), 
# 4410 "../../../server-code/src/char/char.c" 3 4
0
# 4410 "../../../server-code/src/char/char.c"
)) return(-1); } while(0);
 if ((i = chr->search_mapserver((j=mapindex->name2id("prontera")),-1,-1)) >= 0) {
  cd->last_point.x = 273;
  cd->last_point.y = 354;
 } else if ((i = chr->search_mapserver((j=mapindex->name2id("geffen")),-1,-1)) >= 0) {
  cd->last_point.x = 120;
  cd->last_point.y = 100;
 } else if ((i = chr->search_mapserver((j=mapindex->name2id("morocc")),-1,-1)) >= 0) {
  cd->last_point.x = 160;
  cd->last_point.y = 94;
 } else if ((i = chr->search_mapserver((j=mapindex->name2id("alberta")),-1,-1)) >= 0) {
  cd->last_point.x = 116;
  cd->last_point.y = 57;
 } else if ((i = chr->search_mapserver((j=mapindex->name2id("payon")),-1,-1)) >= 0) {
  cd->last_point.x = 87;
  cd->last_point.y = 117;
 } else if ((i = chr->search_mapserver((j=mapindex->name2id("izlude")),-1,-1)) >= 0) {
  cd->last_point.x = 94;
  cd->last_point.y = 103;
 }
 if (i >= 0)
 {
  cd->last_point.map = j;
  (showmsg->showWarning(("Unable to find map-server for '%s', sending to major city '%s'.\n"), mapindex->id2name((cd->last_point.map),"../../../server-code/src/char/char.c", 4433, __func__), mapindex->id2name((j),"../../../server-code/src/char/char.c", 4433, __func__)));
 }
 return i;
}

void char_parse_char_select(int fd, struct char_session_data* sd, uint32 ipl) __attribute__((nonnull (2)));
void char_parse_char_select(int fd, struct char_session_data* sd, uint32 ipl)
{
 struct mmo_charstatus char_dat;
 struct mmo_charstatus *cd;
 struct char_auth_node* node;
 char* data;
 int char_id;
 int server_id = 0;
 int i;
 int map_fd;
 uint32 subnet_map_ip;
 int slot = RFIFOB(fd,2);

 RFIFOSKIP(fd,3);


 if( pincode->enabled ){
  struct online_char_data* character;
  character = (struct online_char_data*)( DB->data2ptr((chr->online_char_db)->get((chr->online_char_db),DB->i2key(sd->account_id))) );
  if( character && character->pincode_enable == -1){
   chr->auth_error(fd, 0);
   return;
  }
 }


 do { for ((server_id) = (0); (server_id) < (( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) )); ++(server_id)) if (chr->server[server_id].fd > 0 && ( (chr->server[server_id].maps)._len_ ) > 0) break; } while(
# 4465 "../../../server-code/src/char/char.c" 3 4
0
# 4465 "../../../server-code/src/char/char.c"
);


 if( server_id == ( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) ) ) {
  chr->send_wait_char_server(fd);
  return;
 }

 if (0 != SQL->Query(inter->sql_handle, "SELECT `char_id` FROM `%s` WHERE `account_id`='%d' AND `char_num`='%d'", char_db, sd->account_id, slot)
  || 0 != SQL->NextRow(inter->sql_handle)
  || 0 != SQL->GetData(inter->sql_handle, 0, &data, 
# 4475 "../../../server-code/src/char/char.c" 3 4
                                                             ((void *)0)
# 4475 "../../../server-code/src/char/char.c"
                                                                 )
 ) {

  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 4478));
  SQL->FreeResult(inter->sql_handle);
  chr->auth_error(fd, 0);
  return;
 }

 char_id = atoi(data);
 SQL->FreeResult(inter->sql_handle);


 if( sd->found_char[slot] == char_id && sd->unban_time[slot] > time(
# 4488 "../../../server-code/src/char/char.c" 3 4
                                                                   ((void *)0)
# 4488 "../../../server-code/src/char/char.c"
                                                                       ) ) {
  chr->auth_error(fd, 0);
  return;
 }


 chr->set_char_online(-2,char_id,sd->account_id);
 if( !chr->mmo_char_fromsql(char_id, &char_dat, 
# 4495 "../../../server-code/src/char/char.c" 3 4
                                               1
# 4495 "../../../server-code/src/char/char.c"
                                                   ) ) {
  chr->set_char_offline(char_id, sd->account_id);

  chr->auth_error(fd, 0);
  return;
 }


 cd = (struct mmo_charstatus *)( DB->data2ptr((chr->char_db_)->get((chr->char_db_),DB->i2key(char_id))) );
 do { if (((void)(cd), 
# 4504 "../../../server-code/src/char/char.c" 3 4
0
# 4504 "../../../server-code/src/char/char.c"
)) return; } while(0);
 if( cd->sex == 99 )
  cd->sex = sd->sex;

 if (log_char) {
  char esc_name[(23 + 1)*2+1];

  SQL->EscapeStringLen(inter->sql_handle, esc_name, char_dat.name, (strlib->strnlen_((char_dat.name),((23 + 1)))));
  if( (-1) == SQL->Query(inter->sql_handle,
   "INSERT INTO `%s`(`time`, `account_id`, `char_id`, `char_num`, `name`) VALUES (NOW(), '%d', '%d', '%d', '%s')",
   charlog_db, sd->account_id, cd->char_id, slot, esc_name) )
   (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 4515));
 }
 (showmsg->showInfo(("Selected char: (Account %d: %d - %s)\n"), sd->account_id, slot, char_dat.name));


 i = chr->search_mapserver(cd->last_point.map, -1, -1);


 if (i < 0 || !cd->last_point.map) {
  unsigned short j;

  do { for ((j) = (0); (j) < (( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) )); ++(j)) if (chr->server[j].fd >= 0 && ( (chr->server[j].maps)._len_ ) > 0) break; } while(
# 4526 "../../../server-code/src/char/char.c" 3 4
 0
# 4526 "../../../server-code/src/char/char.c"
 );
  if (j == ( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) )) {
   (showmsg->showInfo(("Connection Closed. No map servers available.\n")));
   chr->authfail_fd(fd, 1);
   return;
  }
  i = chr->search_default_maps_mapserver(cd);
  if (i < 0)
  {
   (showmsg->showInfo(("Connection Closed. No map server available that has a major city, and unable to find map-server for '%s'.\n"), mapindex->id2name((cd->last_point.map),"../../../server-code/src/char/char.c", 4535, __func__)));
   chr->authfail_fd(fd, 1);
   return;
  }
 }



 if ((map_fd = chr->server[i].fd) < 1 || sockt->session[map_fd] == 
# 4543 "../../../server-code/src/char/char.c" 3 4
                                                                  ((void *)0)
# 4543 "../../../server-code/src/char/char.c"
                                                                      )
 {
  (showmsg->showError(("chr->parse_char: Attempting to write to invalid session %d! Map Server #%d disconnected.\n"), map_fd, i));
  chr->server[i].fd = -1;
  memset(&chr->server[i], 0, sizeof(struct mmo_map_server));
  chr->authfail_fd(fd, 1);
  return;
 }

 subnet_map_ip = chr->lan_subnet_check(ipl);

 chr->send_map_info(fd, i, subnet_map_ip, cd);


 ((node) = (struct char_auth_node *) (iMalloc->calloc(((1)),(sizeof(struct char_auth_node)),"../../../server-code/src/char/char.c", 4557, __func__)));
 node->account_id = sd->account_id;
 node->char_id = cd->char_id;
 node->login_id1 = sd->login_id1;
 node->login_id2 = sd->login_id2;
 node->sex = sd->sex;
 node->expiration_time = sd->expiration_time;
 node->group_id = sd->group_id;
 node->ip = ipl;
 ( (auth_db)->put((auth_db),DB->i2key(sd->account_id),DB->ptr2data(node),
# 4566 "../../../server-code/src/char/char.c" 3 4
((void *)0)
# 4566 "../../../server-code/src/char/char.c"
) );
}

void char_creation_failed(int fd, int result)
{
 WFIFOHEAD(fd,3);
 WFIFOW(fd,0) = 0x6e;




 switch (result) {
  case -1: WFIFOB(fd,2) = 0x00; break;
  case -2: WFIFOB(fd,2) = 0xFF; break;
  case -3: WFIFOB(fd,2) = 0x01; break;
  case -4: WFIFOB(fd,2) = 0x03; break;
  case -5: WFIFOB(fd,2) = 0x02; break;

  default:
   (showmsg->showWarning(("chr->parse_char: Unknown result received from chr->make_new_char_sql!\n")));
   WFIFOB(fd,2) = 0xFF;
   break;
 }
 WFIFOSET(fd,3);
}

void char_creation_ok(int fd, struct mmo_charstatus *char_dat)
{
 int len;


 WFIFOHEAD(fd,2+150);
 WFIFOW(fd,0) = 0x6d;
 len = 2 + chr->mmo_char_tobuf(WFIFOP(fd,2), char_dat);
 WFIFOSET(fd,len);
}

void char_parse_char_create_new_char(int fd, struct char_session_data* sd) __attribute__((nonnull (2)));
void char_parse_char_create_new_char(int fd, struct char_session_data* sd)
{
 int result;
 if( !char_new ) {

  result = -2;
 } else {

  result = chr->make_new_char_sql(sd, RFIFOP(fd,2), 1, 1, 1, 1, 1, 1, RFIFOB(fd,26),RFIFOW(fd,27),RFIFOW(fd,29));



 }


 if (result < 0) {
  chr->creation_failed(fd, result);
 } else {

  struct mmo_charstatus char_dat;
  chr->mmo_char_fromsql(result, &char_dat, 
# 4624 "../../../server-code/src/char/char.c" 3 4
                                          0
# 4624 "../../../server-code/src/char/char.c"
                                               );
  chr->creation_ok(fd, &char_dat);


  sd->found_char[char_dat.slot] = result;
 }

 RFIFOSKIP(fd,31);



}



void char_delete_char_failed(int fd, int flag)
{
 WFIFOHEAD(fd,3);
 WFIFOW(fd,0) = 0x70;
 WFIFOB(fd,2) = flag;
 WFIFOSET(fd,3);
}

void char_delete_char_ok(int fd)
{
 WFIFOHEAD(fd,2);
 WFIFOW(fd,0) = 0x6f;
 WFIFOSET(fd,2);
}

void char_parse_char_delete_char(int fd, struct char_session_data* sd, unsigned short cmd) __attribute__((nonnull (2)));
void char_parse_char_delete_char(int fd, struct char_session_data* sd, unsigned short cmd)
{
 char email[40];
 int cid = RFIFOL(fd,2);
 int i;


 if (pincode->enabled) {
  struct online_char_data* character;
  character = (struct online_char_data*)( DB->data2ptr((chr->online_char_db)->get((chr->online_char_db),DB->i2key(sd->account_id))) );
  if( character && character->pincode_enable == -1 ){
   chr->auth_error(fd, 0);
   RFIFOSKIP(fd,( cmd == 0x68) ? 46 : 56);
   return;
  }
 }

 (showmsg->showInfo(("\033[1;31m""Request Char Deletion: ""\033[1;32m""%d (%d)""\033[0m""\n"), sd->account_id, cid));
 memcpy(email, RFIFOP(fd,6), 40);
 RFIFOSKIP(fd,( cmd == 0x68) ? 46 : 56);


 if (strcasecmp(email, sd->email) != 0
  && ( strcmp("a@a.com", sd->email) != 0
   || (strcmp("a@a.com", email) != 0 && strcmp("", email) != 0)
 )) {

  chr->delete_char_failed(fd, 0);
  return;
 }


 do { for ((i) = (0); (i) < (9); ++(i)) if (sd->found_char[i] == cid) break; } while(
# 4687 "../../../server-code/src/char/char.c" 3 4
0
# 4687 "../../../server-code/src/char/char.c"
);
 if( i == 9 )
 {
  chr->delete_char_failed(fd, 0);
  return;
 }


 sd->found_char[i] = -1;


 if(chr->delete_char_sql(cid)<0){



  chr->delete_char_failed(fd, 0);
  return;
 }

 chr->delete_char_ok(fd);
}

void char_parse_char_ping(int fd)
{
 RFIFOSKIP(fd,6);
}

void char_allow_rename(int fd, int flag)
{
 WFIFOHEAD(fd, 4);
 WFIFOW(fd,0) = 0x28e;
 WFIFOW(fd,2) = flag;
 WFIFOSET(fd,4);
}

void char_parse_char_rename_char(int fd, struct char_session_data* sd) __attribute__((nonnull (2)));
void char_parse_char_rename_char(int fd, struct char_session_data* sd)
{
 int i, cid =RFIFOL(fd,2);
 char name[(23 + 1)];
 char esc_name[(23 + 1)*2+1];
 (strlib->safestrncpy_((name),(RFIFOP(fd,6)),((23 + 1))));
 RFIFOSKIP(fd,30);

 do { for ((i) = (0); (i) < (9); ++(i)) if (sd->found_char[i] == cid) break; } while(
# 4731 "../../../server-code/src/char/char.c" 3 4
0
# 4731 "../../../server-code/src/char/char.c"
);
 if( i == 9 )
  return;

 (strlib->normalize_name_((name),("\255\xA0\032\t\x0A\x0D ")));
 SQL->EscapeStringLen(inter->sql_handle, esc_name, name, (strlib->strnlen_((name),((23 + 1)))));
 if( !chr->check_char_name(name,esc_name) ) {
  i = 1;
  (strlib->safestrncpy_((sd->new_name),(name),((23 + 1))));
 } else {
  i = 0;
 }

 chr->allow_rename(fd, i);
}

void char_parse_char_rename_char2(int fd, struct char_session_data* sd) __attribute__((nonnull (2)));
void char_parse_char_rename_char2(int fd, struct char_session_data* sd)
{
 int i, aid = RFIFOL(fd,2), cid =RFIFOL(fd,6);
 char name[(23 + 1)];
 char esc_name[(23 + 1)*2+1];
 (strlib->safestrncpy_((name),(RFIFOP(fd,10)),((23 + 1))));
 RFIFOSKIP(fd,34);

 if( aid != sd->account_id )
  return;
 do { for ((i) = (0); (i) < (9); ++(i)) if (sd->found_char[i] == cid) break; } while(
# 4758 "../../../server-code/src/char/char.c" 3 4
0
# 4758 "../../../server-code/src/char/char.c"
);
 if( i == 9 )
  return;

 (strlib->normalize_name_((name),("\255\xA0\032\t\x0A\x0D ")));
 SQL->EscapeStringLen(inter->sql_handle, esc_name, name, (strlib->strnlen_((name),((23 + 1)))));
 if( !chr->check_char_name(name,esc_name) )
 {
  i = 1;
  (strlib->safestrncpy_((sd->new_name),(name),((23 + 1))));
 }
 else
  i = 0;

 chr->allow_rename(fd, i);
}

void char_rename_char_ack(int fd, int flag)
{
 WFIFOHEAD(fd, 4);
 WFIFOW(fd,0) = 0x290;
 WFIFOW(fd,2) = flag;
 WFIFOSET(fd,4);
}

void char_parse_char_rename_char_confirm(int fd, struct char_session_data* sd) __attribute__((nonnull (2)));
void char_parse_char_rename_char_confirm(int fd, struct char_session_data* sd)
{
 int i;
 int cid = RFIFOL(fd,2);
 RFIFOSKIP(fd,6);

 do { for ((i) = (0); (i) < (9); ++(i)) if (sd->found_char[i] == cid) break; } while(
# 4790 "../../../server-code/src/char/char.c" 3 4
0
# 4790 "../../../server-code/src/char/char.c"
);
 if( i == 9 )
  return;
 i = chr->rename_char_sql(sd, cid);

 chr->rename_char_ack(fd, i);
}

void char_captcha_notsupported(int fd)
{
 WFIFOHEAD(fd,5);
 WFIFOW(fd,0) = 0x7e9;
 WFIFOW(fd,2) = 5;
 WFIFOB(fd,4) = 1;
 WFIFOSET(fd,5);
}

void char_parse_char_request_captcha(int fd)
{
 chr->captcha_notsupported(fd);
 RFIFOSKIP(fd,8);
}

void char_parse_char_check_captcha(int fd)
{
 chr->captcha_notsupported(fd);
 RFIFOSKIP(fd,32);
}

void char_parse_char_delete2_req(int fd, struct char_session_data* sd)
{
 chr->delete2_req(fd, sd);
 RFIFOSKIP(fd,6);
}

void char_parse_char_delete2_accept(int fd, struct char_session_data* sd)
{
 chr->delete2_accept(fd, sd);
 RFIFOSKIP(fd,12);
}

void char_parse_char_delete2_cancel(int fd, struct char_session_data* sd)
{
 chr->delete2_cancel(fd, sd);
 RFIFOSKIP(fd,6);
}




void char_login_map_server_ack(int fd, uint8 flag)
{
 WFIFOHEAD(fd,3);
 WFIFOW(fd,0) = 0x2af9;
 WFIFOB(fd,2) = flag;
 WFIFOSET(fd,3);
}

void char_parse_char_login_map_server(int fd, uint32 ipl)
{
 char l_user[24], l_pass[24];
 int i;
 (strlib->safestrncpy_((l_user),(RFIFOP(fd,2)),(24)));
 (strlib->safestrncpy_((l_pass),(RFIFOP(fd,26)),(24)));

 do { for ((i) = (0); (i) < (( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) )); ++(i)) if (chr->server[i].fd <= 0) break; } while(
# 4855 "../../../server-code/src/char/char.c" 3 4
0
# 4855 "../../../server-code/src/char/char.c"
);
 if (core->runflag != CHARSERVER_ST_RUNNING ||
  i == ( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) ) ||
  strcmp(l_user, chr->userid) != 0 ||
  strcmp(l_pass, chr->passwd) != 0 ||
  !sockt->allowed_ip_check(ipl))
 {
  chr->login_map_server_ack(fd, 3);
 } else {
  chr->login_map_server_ack(fd, 0);

  chr->server[i].fd = fd;
  chr->server[i].ip = ntohl(RFIFOL(fd,54));
  chr->server[i].port = ntohs(RFIFOW(fd,58));
  chr->server[i].users = 0;
  sockt->session[fd]->func_parse = chr->parse_frommap;
  sockt->session[fd]->flag.server = 1;
  sockt->realloc_fifo(fd, FIFOSIZE_SERVERLINK, FIFOSIZE_SERVERLINK);
  chr->mapif_init(fd);
 }
 sockt->datasync(fd, 
# 4875 "../../../server-code/src/char/char.c" 3 4
                    1
# 4875 "../../../server-code/src/char/char.c"
                        );

 RFIFOSKIP(fd,60);
}

void char_parse_char_pincode_check(int fd, struct char_session_data* sd) __attribute__((nonnull (2)));
void char_parse_char_pincode_check(int fd, struct char_session_data* sd)
{
 if (RFIFOL(fd,2) == sd->account_id)
  pincode->check(fd, sd);

 RFIFOSKIP(fd, 10);
}

void char_parse_char_pincode_window(int fd, struct char_session_data* sd) __attribute__((nonnull (2)));
void char_parse_char_pincode_window(int fd, struct char_session_data* sd)
{
 if (RFIFOL(fd,2) == sd->account_id)
  pincode->sendstate(fd, sd, PINCODE_NOTSET);

 RFIFOSKIP(fd, 6);
}

void char_parse_char_pincode_change(int fd, struct char_session_data* sd) __attribute__((nonnull (2)));
void char_parse_char_pincode_change(int fd, struct char_session_data* sd)
{
 if (RFIFOL(fd,2) == sd->account_id)
  pincode->change(fd, sd);

 RFIFOSKIP(fd, 14);
}

void char_parse_char_pincode_first_pin(int fd, struct char_session_data* sd) __attribute__((nonnull (2)));
void char_parse_char_pincode_first_pin(int fd, struct char_session_data* sd)
{
 if (RFIFOL(fd,2) == sd->account_id)
  pincode->setnew (fd, sd);
 RFIFOSKIP(fd, 10);
}

void char_parse_char_request_chars(int fd, struct char_session_data* sd)
{
 chr->mmo_char_send099d(fd, sd);
 RFIFOSKIP(fd,2);
}

void char_change_character_slot_ack(int fd, 
# 4921 "../../../server-code/src/char/char.c" 3 4
                                           _Bool 
# 4921 "../../../server-code/src/char/char.c"
                                                ret)
{
 WFIFOHEAD(fd, 8);
 WFIFOW(fd,0) = 0x8d5;
 WFIFOW(fd,2) = 8;
 WFIFOW(fd,4) = ret?0:1;
 WFIFOW(fd,6) = 0;
 WFIFOSET(fd, 8);
}

void char_parse_char_move_character(int fd, struct char_session_data* sd)
{
 
# 4933 "../../../server-code/src/char/char.c" 3 4
_Bool 
# 4933 "../../../server-code/src/char/char.c"
     ret = chr->char_slotchange(sd, fd, RFIFOW(fd, 2), RFIFOW(fd, 4));
 chr->change_character_slot_ack(fd, ret);

 if( ret )

  chr->mmo_char_send099d(fd, sd);



 RFIFOSKIP(fd, 8);
}

int char_parse_char_unknown_packet(int fd, uint32 ipl)
{
 (showmsg->showError(("chr->parse_char: Received unknown packet ""\033[1;37m""0x%x""\033[0m"" from ip '""\033[1;37m""%s""\033[0m""'! Disconnecting!\n"), RFIFOW(fd,0), sockt->ip2str(ipl, 
# 4947 "../../../server-code/src/char/char.c" 3 4
((void *)0)
# 4947 "../../../server-code/src/char/char.c"
)));
 sockt->eof(fd);
 return 1;
}

int char_parse_char(int fd)
{
 unsigned short cmd;
 struct char_session_data* sd;
 uint32 ipl = sockt->session[fd]->client_addr;

 sd = (struct char_session_data*)sockt->session[fd]->session_data;


 if(chr->login_fd < 0)
  sockt->eof(fd);

 if(sockt->session[fd]->flag.eof)
 {
  if( sd != 
# 4966 "../../../server-code/src/char/char.c" 3 4
           ((void *)0) 
# 4966 "../../../server-code/src/char/char.c"
                && sd->auth ) {

   struct online_char_data* data = (struct online_char_data*)( DB->data2ptr((chr->online_char_db)->get((chr->online_char_db),DB->i2key(sd->account_id))) );
   if( data != 
# 4969 "../../../server-code/src/char/char.c" 3 4
              ((void *)0) 
# 4969 "../../../server-code/src/char/char.c"
                   && data->fd == fd)
    data->fd = -1;
   if( data == 
# 4971 "../../../server-code/src/char/char.c" 3 4
              ((void *)0) 
# 4971 "../../../server-code/src/char/char.c"
                   || data->server == -1)
    chr->set_char_offline(-1,sd->account_id);
  }
  sockt->close(fd);
  return 0;
 }

 while (RFIFOREST(fd) >= 2) {
  cmd = RFIFOW(fd,0);




  if (( (HPM->packets[hpParse_Char])._len_ ) > 0) {
   int result = HPM->parse_packets(fd,cmd,hpParse_Char);
   if (result == 1)
    continue;
   if (result == 2)
    return 0;
  }

  switch (cmd) {


   case 0x65:
    if( RFIFOREST(fd) < 17 )
     return 0;
   {
    chr->parse_char_connect(fd, sd, ipl);
   }
   break;


   case 0x66:
    do { if(RFIFOREST(fd) < (3)) return 0; if (sd==
# 5005 "../../../server-code/src/char/char.c" 3 4
   ((void *)0) 
# 5005 "../../../server-code/src/char/char.c"
   || !sd->auth) { RFIFOSKIP(fd,(3)); return 0; } } while (0);
   {
    chr->parse_char_select(fd, sd, ipl);
   }
   break;




   case 0x970:
   {
    do { if(RFIFOREST(fd) < (31)) return 0; if (sd==
# 5016 "../../../server-code/src/char/char.c" 3 4
   ((void *)0) 
# 5016 "../../../server-code/src/char/char.c"
   || !sd->auth) { RFIFOSKIP(fd,(31)); return 0; } } while (0);







    chr->parse_char_create_new_char(fd, sd);
   }
   break;


   case 0x68:

   case 0x1fb:
    if (cmd == 0x68) do { if(RFIFOREST(fd) < (46)) return 0; if (sd==
# 5032 "../../../server-code/src/char/char.c" 3 4
                    ((void *)0) 
# 5032 "../../../server-code/src/char/char.c"
                    || !sd->auth) { RFIFOSKIP(fd,(46)); return 0; } } while (0);
    if (cmd == 0x1fb) do { if(RFIFOREST(fd) < (56)) return 0; if (sd==
# 5033 "../../../server-code/src/char/char.c" 3 4
                     ((void *)0) 
# 5033 "../../../server-code/src/char/char.c"
                     || !sd->auth) { RFIFOSKIP(fd,(56)); return 0; } } while (0);
   {
    chr->parse_char_delete_char(fd, sd, cmd);
   }
   break;



   case 0x187:
    if (RFIFOREST(fd) < 6)
     return 0;
    chr->parse_char_ping(fd);
   break;


   case 0x8fc:
    do { if(RFIFOREST(fd) < (30)) return 0; if (sd==
# 5049 "../../../server-code/src/char/char.c" 3 4
   ((void *)0) 
# 5049 "../../../server-code/src/char/char.c"
   || !sd->auth) { RFIFOSKIP(fd,(30)); return 0; } } while (0);
    {
     chr->parse_char_rename_char(fd, sd);
    }
    break;



   case 0x28d:
    do { if(RFIFOREST(fd) < (34)) return 0; if (sd==
# 5058 "../../../server-code/src/char/char.c" 3 4
   ((void *)0) 
# 5058 "../../../server-code/src/char/char.c"
   || !sd->auth) { RFIFOSKIP(fd,(34)); return 0; } } while (0);
    {
     chr->parse_char_rename_char2(fd, sd);
    }
    break;


   case 0x28f:





    do { if(RFIFOREST(fd) < (6)) return 0; if (sd==
# 5071 "../../../server-code/src/char/char.c" 3 4
   ((void *)0) 
# 5071 "../../../server-code/src/char/char.c"
   || !sd->auth) { RFIFOSKIP(fd,(6)); return 0; } } while (0);
    {
     chr->parse_char_rename_char_confirm(fd, sd);
    }
    break;



   case 0x7e5:
    chr->parse_char_request_captcha(fd);
    break;



   case 0x7e7:
    chr->parse_char_check_captcha(fd);
   break;


   case 0x827:
    do { if(RFIFOREST(fd) < (6)) return 0; if (sd==
# 5091 "../../../server-code/src/char/char.c" 3 4
   ((void *)0) 
# 5091 "../../../server-code/src/char/char.c"
   || !sd->auth) { RFIFOSKIP(fd,(6)); return 0; } } while (0);
    chr->parse_char_delete2_req(fd, sd);
   break;


   case 0x829:
    do { if(RFIFOREST(fd) < (12)) return 0; if (sd==
# 5097 "../../../server-code/src/char/char.c" 3 4
   ((void *)0) 
# 5097 "../../../server-code/src/char/char.c"
   || !sd->auth) { RFIFOSKIP(fd,(12)); return 0; } } while (0);
    chr->parse_char_delete2_accept(fd, sd);
   break;


   case 0x82b:
    do { if(RFIFOREST(fd) < (6)) return 0; if (sd==
# 5103 "../../../server-code/src/char/char.c" 3 4
   ((void *)0) 
# 5103 "../../../server-code/src/char/char.c"
   || !sd->auth) { RFIFOSKIP(fd,(6)); return 0; } } while (0);
    chr->parse_char_delete2_cancel(fd, sd);
   break;


   case 0x2af8:
    if (RFIFOREST(fd) < 60)
     return 0;
   {
    chr->parse_char_login_map_server(fd, ipl);
   }
   return 0;


   case 0x8b8:
    do { if(RFIFOREST(fd) < (10)) return 0; if (sd==
# 5118 "../../../server-code/src/char/char.c" 3 4
   ((void *)0) 
# 5118 "../../../server-code/src/char/char.c"
   || !sd->auth) { RFIFOSKIP(fd,(10)); return 0; } } while (0);
    chr->parse_char_pincode_check(fd, sd);
   break;


   case 0x8c5:
    do { if(RFIFOREST(fd) < (6)) return 0; if (sd==
# 5124 "../../../server-code/src/char/char.c" 3 4
   ((void *)0) 
# 5124 "../../../server-code/src/char/char.c"
   || !sd->auth) { RFIFOSKIP(fd,(6)); return 0; } } while (0);
    chr->parse_char_pincode_window(fd, sd);
   break;


   case 0x8be:
    do { if(RFIFOREST(fd) < (14)) return 0; if (sd==
# 5130 "../../../server-code/src/char/char.c" 3 4
   ((void *)0) 
# 5130 "../../../server-code/src/char/char.c"
   || !sd->auth) { RFIFOSKIP(fd,(14)); return 0; } } while (0);
    chr->parse_char_pincode_change(fd, sd);
   break;


   case 0x8ba:
    do { if(RFIFOREST(fd) < (10)) return 0; if (sd==
# 5136 "../../../server-code/src/char/char.c" 3 4
   ((void *)0) 
# 5136 "../../../server-code/src/char/char.c"
   || !sd->auth) { RFIFOSKIP(fd,(10)); return 0; } } while (0);
    chr->parse_char_pincode_first_pin(fd, sd);
   break;

   case 0x9a1:
    do { if(RFIFOREST(fd) < (2)) return 0; if (sd==
# 5141 "../../../server-code/src/char/char.c" 3 4
   ((void *)0) 
# 5141 "../../../server-code/src/char/char.c"
   || !sd->auth) { RFIFOSKIP(fd,(2)); return 0; } } while (0);
    chr->parse_char_request_chars(fd, sd);
   break;


   case 0x8d4:
    do { if(RFIFOREST(fd) < (8)) return 0; if (sd==
# 5147 "../../../server-code/src/char/char.c" 3 4
   ((void *)0) 
# 5147 "../../../server-code/src/char/char.c"
   || !sd->auth) { RFIFOSKIP(fd,(8)); return 0; } } while (0);
    {
     chr->parse_char_move_character(fd, sd);
    }
   break;


   default:
    if (chr->parse_char_unknown_packet(fd, ipl))
     return 0;
   }
 }

 RFIFOFLUSH(fd);
 return 0;
}

int mapif_sendall(const unsigned char *buf, unsigned int len)
{
 int i, c;

 do { if (((void)(buf), 
# 5168 "../../../server-code/src/char/char.c" 3 4
0
# 5168 "../../../server-code/src/char/char.c"
)) return(0); } while(0);
 c = 0;
 for(i = 0; i < ( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) ); i++) {
  int fd;
  if ((fd = chr->server[i].fd) > 0) {
   WFIFOHEAD(fd,len);
   memcpy(WFIFOP(fd,0), buf, len);
   WFIFOSET(fd,len);
   c++;
  }
 }

 return c;
}

int mapif_sendallwos(int sfd, unsigned char *buf, unsigned int len)
{
 int i, c;

 do { if (((void)(buf), 
# 5187 "../../../server-code/src/char/char.c" 3 4
0
# 5187 "../../../server-code/src/char/char.c"
)) return(0); } while(0);
 c = 0;
 for(i = 0; i < ( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) ); i++) {
  int fd;
  if ((fd = chr->server[i].fd) > 0 && fd != sfd) {
   WFIFOHEAD(fd,len);
   memcpy(WFIFOP(fd,0), buf, len);
   WFIFOSET(fd,len);
   c++;
  }
 }

 return c;
}

int mapif_send(int fd, unsigned char *buf, unsigned int len)
{
 do { if (((void)(buf), 
# 5204 "../../../server-code/src/char/char.c" 3 4
0
# 5204 "../../../server-code/src/char/char.c"
)) return(0); } while(0);
 if (fd >= 0) {
  int i;
  do { for ((i) = (0); (i) < (( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) )); ++(i)) if (fd == chr->server[i].fd) break; } while(
# 5207 "../../../server-code/src/char/char.c" 3 4
 0
# 5207 "../../../server-code/src/char/char.c"
 );
  if( i < ( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) ) )
  {
   WFIFOHEAD(fd,len);
   memcpy(WFIFOP(fd,0), buf, len);
   WFIFOSET(fd,len);
   return 1;
  }
 }
 return 0;
}

void mapif_send_users_count(int users)
{
 uint8 buf[6];

 WBUFW(buf,0) = 0x2b00;
 WBUFL(buf,2) = users;
 mapif->sendall(buf,6);
}

int char_broadcast_user_count(int tid, int64 tick, int id, intptr_t data) {
 int users = chr->count_users();


 static int prev_users = 0;
 if( prev_users == users )
  return 0;
 prev_users = users;

 if( chr->login_fd > 0 && sockt->session[chr->login_fd] )
 {

  loginif->send_users_count(users);
 }

 mapif->send_users_count(users);

 return 0;
}





static int char_send_accounts_tologin_sub(union DBKey key, struct DBData *data, va_list ap)
{
 struct online_char_data* character = DB->data2ptr(data);
 int* i = 
# 5255 "../../../server-code/src/char/char.c" 3 4
         __builtin_va_arg(
# 5255 "../../../server-code/src/char/char.c"
         ap
# 5255 "../../../server-code/src/char/char.c" 3 4
         ,
# 5255 "../../../server-code/src/char/char.c"
         int*
# 5255 "../../../server-code/src/char/char.c" 3 4
         )
# 5255 "../../../server-code/src/char/char.c"
                         ;

 do { if (((void)(character), 
# 5257 "../../../server-code/src/char/char.c" 3 4
0
# 5257 "../../../server-code/src/char/char.c"
)) return(0); } while(0);
 if(character->server > -1)
 {
  WFIFOL(chr->login_fd,8+(*i)*4) = character->account_id;
  (*i)++;
  return 1;
 }
 return 0;
}

int char_send_accounts_tologin(int tid, int64 tick, int id, intptr_t data) {
 if (chr->login_fd > 0 && sockt->session[chr->login_fd])
 {

  int users = chr->online_char_db->size(chr->online_char_db);
  int i = 0;

  WFIFOHEAD(chr->login_fd,8+users*4);
  WFIFOW(chr->login_fd,0) = 0x272d;
  chr->online_char_db->foreach(chr->online_char_db, chr->send_accounts_tologin_sub, &i, users);
  WFIFOW(chr->login_fd,2) = 8+ i*4;
  WFIFOL(chr->login_fd,4) = i;
  WFIFOSET(chr->login_fd,WFIFOW(chr->login_fd,2));
 }
 return 0;
}

int char_check_connect_login_server(int tid, int64 tick, int id, intptr_t data) {
 if (chr->login_fd > 0 && sockt->session[chr->login_fd] != 
# 5285 "../../../server-code/src/char/char.c" 3 4
                                                          ((void *)0)
# 5285 "../../../server-code/src/char/char.c"
                                                              )
  return 0;

 (showmsg->showInfo(("Attempt to connect to login-server...\n")));

 if ((chr->login_fd = sockt->make_connection(login_ip, login_port, 
# 5290 "../../../server-code/src/char/char.c" 3 4
                                                                  ((void *)0)
# 5290 "../../../server-code/src/char/char.c"
                                                                      )) == -1) {
  chr->login_fd = 0;
  return 0;
 }

 sockt->session[chr->login_fd]->func_parse = chr->parse_fromlogin;
 sockt->session[chr->login_fd]->flag.server = 1;
 sockt->realloc_fifo(chr->login_fd, FIFOSIZE_SERVERLINK, FIFOSIZE_SERVERLINK);

 loginif->connect_to_server();

 return 1;
}





static int char_waiting_disconnect(int tid, int64 tick, int id, intptr_t data) {
 struct online_char_data* character;
 if ((character = (struct online_char_data*)( DB->data2ptr((chr->online_char_db)->get((chr->online_char_db),DB->i2key(id))) )) != 
# 5310 "../../../server-code/src/char/char.c" 3 4
                                                                                ((void *)0) 
# 5310 "../../../server-code/src/char/char.c"
                                                                                     && character->waiting_disconnect == tid) {

  character->waiting_disconnect = (-1);
  chr->set_char_offline(character->char_id, character->account_id);
 }
 return 0;
}




static int char_online_data_cleanup_sub(union DBKey key, struct DBData *data, va_list ap)
{
 struct online_char_data *character= DB->data2ptr(data);
 do { if (((void)(character), 
# 5324 "../../../server-code/src/char/char.c" 3 4
0
# 5324 "../../../server-code/src/char/char.c"
)) return(0); } while(0);
 if (character->fd != -1)
  return 0;
 if (character->server == -2)
  chr->set_char_offline(character->char_id, character->account_id);
 if (character->server < 0)

  ( (chr->online_char_db)->remove((chr->online_char_db),(key),
# 5331 "../../../server-code/src/char/char.c" 3 4
 ((void *)0)
# 5331 "../../../server-code/src/char/char.c"
 ) );
 return 0;
}

static int char_online_data_cleanup(int tid, int64 tick, int id, intptr_t data) {
 chr->online_char_db->foreach(chr->online_char_db, chr->online_data_cleanup_sub);
 return 0;
}

void char_sql_config_read(const char* cfgName)
{
 char line[1024], w1[1024], w2[1024];
 FILE* fp;

 if ((fp = fopen(cfgName, "r")) == 
# 5345 "../../../server-code/src/char/char.c" 3 4
                                  ((void *)0)
# 5345 "../../../server-code/src/char/char.c"
                                      ) {
  (showmsg->showError(("File not found: %s\n"), cfgName));
  return;
 }

 while(fgets(line, sizeof(line), fp))
 {
  if(line[0] == '/' && line[1] == '/')
   continue;

  if (sscanf(line, "%1023[^:]: %1023[^\r\n]", w1, w2) != 2)
   continue;

  if(!strcasecmp(w1,"char_db"))
   (strlib->safestrncpy_((char_db),(w2),(sizeof(char_db))));
  else if(!strcasecmp(w1,"scdata_db"))
   (strlib->safestrncpy_((scdata_db),(w2),(sizeof(scdata_db))));
  else if(!strcasecmp(w1,"cart_db"))
   (strlib->safestrncpy_((cart_db),(w2),(sizeof(cart_db))));
  else if(!strcasecmp(w1,"inventory_db"))
   (strlib->safestrncpy_((inventory_db),(w2),(sizeof(inventory_db))));
  else if(!strcasecmp(w1,"charlog_db"))
   (strlib->safestrncpy_((charlog_db),(w2),(sizeof(charlog_db))));
  else if(!strcasecmp(w1,"storage_db"))
   (strlib->safestrncpy_((storage_db),(w2),(sizeof(storage_db))));
  else if(!strcasecmp(w1,"skill_db"))
   (strlib->safestrncpy_((skill_db),(w2),(sizeof(skill_db))));
  else if(!strcasecmp(w1,"interlog_db"))
   (strlib->safestrncpy_((interlog_db),(w2),(sizeof(interlog_db))));
  else if(!strcasecmp(w1,"memo_db"))
   (strlib->safestrncpy_((memo_db),(w2),(sizeof(memo_db))));
  else if(!strcasecmp(w1,"guild_db"))
   (strlib->safestrncpy_((guild_db),(w2),(sizeof(guild_db))));
  else if(!strcasecmp(w1,"guild_alliance_db"))
   (strlib->safestrncpy_((guild_alliance_db),(w2),(sizeof(guild_alliance_db))));
  else if(!strcasecmp(w1,"guild_castle_db"))
   (strlib->safestrncpy_((guild_castle_db),(w2),(sizeof(guild_castle_db))));
  else if(!strcasecmp(w1,"guild_expulsion_db"))
   (strlib->safestrncpy_((guild_expulsion_db),(w2),(sizeof(guild_expulsion_db))));
  else if(!strcasecmp(w1,"guild_member_db"))
   (strlib->safestrncpy_((guild_member_db),(w2),(sizeof(guild_member_db))));
  else if(!strcasecmp(w1,"guild_skill_db"))
   (strlib->safestrncpy_((guild_skill_db),(w2),(sizeof(guild_skill_db))));
  else if(!strcasecmp(w1,"guild_position_db"))
   (strlib->safestrncpy_((guild_position_db),(w2),(sizeof(guild_position_db))));
  else if(!strcasecmp(w1,"guild_storage_db"))
   (strlib->safestrncpy_((guild_storage_db),(w2),(sizeof(guild_storage_db))));
  else if(!strcasecmp(w1,"party_db"))
   (strlib->safestrncpy_((party_db),(w2),(sizeof(party_db))));
  else if(!strcasecmp(w1,"pet_db"))
   (strlib->safestrncpy_((pet_db),(w2),(sizeof(pet_db))));
  else if(!strcasecmp(w1,"mail_db"))
   (strlib->safestrncpy_((mail_db),(w2),(sizeof(mail_db))));
  else if(!strcasecmp(w1,"auction_db"))
   (strlib->safestrncpy_((auction_db),(w2),(sizeof(auction_db))));
  else if(!strcasecmp(w1,"friend_db"))
   (strlib->safestrncpy_((friend_db),(w2),(sizeof(friend_db))));
  else if(!strcasecmp(w1,"hotkey_db"))
   (strlib->safestrncpy_((hotkey_db),(w2),(sizeof(hotkey_db))));
  else if(!strcasecmp(w1,"quest_db"))
   (strlib->safestrncpy_((quest_db),(w2),(sizeof(quest_db))));
  else if(!strcasecmp(w1,"homunculus_db"))
   (strlib->safestrncpy_((homunculus_db),(w2),(sizeof(homunculus_db))));
  else if(!strcasecmp(w1,"skill_homunculus_db"))
   (strlib->safestrncpy_((skill_homunculus_db),(w2),(sizeof(skill_homunculus_db))));
  else if(!strcasecmp(w1,"mercenary_db"))
   (strlib->safestrncpy_((mercenary_db),(w2),(sizeof(mercenary_db))));
  else if(!strcasecmp(w1,"mercenary_owner_db"))
   (strlib->safestrncpy_((mercenary_owner_db),(w2),(sizeof(mercenary_owner_db))));
  else if(!strcasecmp(w1,"ragsrvinfo_db"))
   (strlib->safestrncpy_((ragsrvinfo_db),(w2),(sizeof(ragsrvinfo_db))));
  else if(!strcasecmp(w1,"elemental_db"))
   (strlib->safestrncpy_((elemental_db),(w2),(sizeof(elemental_db))));
  else if(!strcasecmp(w1,"account_data_db"))
   (strlib->safestrncpy_((account_data_db),(w2),(sizeof(account_data_db))));
  else if(!strcasecmp(w1,"char_reg_num_db"))
   (strlib->safestrncpy_((char_reg_num_db),(w2),(sizeof(char_reg_num_db))));
  else if(!strcasecmp(w1,"char_reg_str_db"))
   (strlib->safestrncpy_((char_reg_str_db),(w2),(sizeof(char_reg_str_db))));
  else if(!strcasecmp(w1,"acc_reg_str_db"))
   (strlib->safestrncpy_((acc_reg_str_db),(w2),(sizeof(acc_reg_str_db))));
  else if(!strcasecmp(w1,"acc_reg_num_db"))
   (strlib->safestrncpy_((acc_reg_num_db),(w2),(sizeof(acc_reg_num_db))));

  else if(!strcasecmp(w1,"import"))
   chr->sql_config_read(w2);
  else
   HPM->parseConf(w1, w2, HPCT_CHAR_INTER);
 }
 fclose(fp);
 (showmsg->showInfo(("Done reading %s.\n"), cfgName));
}

void char_config_dispatch(char *w1, char *w2) {
 
# 5439 "../../../server-code/src/char/char.c" 3 4
_Bool 
# 5439 "../../../server-code/src/char/char.c"
     (*dispatch_to[]) (char *w1, char *w2) = {

  pincode->config_read
 };
 int i, len = ( (int)(sizeof(dispatch_to)/sizeof((dispatch_to)[0])) );
 for(i = 0; i < len; i++) {
  if( (*dispatch_to[i])(w1,w2) )
   break;
 }
 if (i == len)
  HPM->parseConf(w1, w2, HPCT_CHAR);
}

int char_config_read(const char* cfgName)
{
 char line[1024], w1[1024], w2[1024];
 FILE* fp = fopen(cfgName, "r");

 if (fp == 
# 5457 "../../../server-code/src/char/char.c" 3 4
          ((void *)0)
# 5457 "../../../server-code/src/char/char.c"
              ) {
  (showmsg->showError(("Configuration file not found: %s.\n"), cfgName));
  return 1;
 }

 while(fgets(line, sizeof(line), fp)) {
  if (line[0] == '/' && line[1] == '/')
   continue;

  if (sscanf(line, "%1023[^:]: %1023[^\r\n]", w1, w2) != 2)
   continue;

  (strlib->remove_control_chars_(w1));
  (strlib->remove_control_chars_(w2));
  if(strcasecmp(w1,"timestamp_format") == 0) {
   (strlib->safestrncpy_((showmsg->timestamp_format),(w2),(sizeof(showmsg->timestamp_format))));
  } else if(strcasecmp(w1,"console_silent")==0){
   showmsg->silent = atoi(w2);
   if (showmsg->silent)
    (showmsg->showInfo(("Console Silent Setting: %d\n"), atoi(w2)));
  } else if(strcasecmp(w1,"stdout_with_ansisequence")==0){
   showmsg->stdout_with_ansisequence = (strlib->config_switch_(w2)) ? 
# 5478 "../../../server-code/src/char/char.c" 3 4
                                                          1 
# 5478 "../../../server-code/src/char/char.c"
                                                               : 
# 5478 "../../../server-code/src/char/char.c" 3 4
                                                                 0
# 5478 "../../../server-code/src/char/char.c"
                                                                      ;
  } else if (strcasecmp(w1, "userid") == 0) {
   (strlib->safestrncpy_((chr->userid),(w2),(sizeof(chr->userid))));
  } else if (strcasecmp(w1, "passwd") == 0) {
   (strlib->safestrncpy_((chr->passwd),(w2),(sizeof(chr->passwd))));
  } else if (strcasecmp(w1, "server_name") == 0) {
   (strlib->safestrncpy_((chr->server_name),(w2),(sizeof(chr->server_name))));
  } else if (strcasecmp(w1, "wisp_server_name") == 0) {
   if (strlen(w2) >= 4) {
    (strlib->safestrncpy_((wisp_server_name),(w2),(sizeof(wisp_server_name))));
   }
  } else if (strcasecmp(w1, "login_ip") == 0) {
   login_ip = sockt->host2ip(w2);
   if (login_ip) {
    char ip_str[16];
    (strlib->safestrncpy_((login_ip_str),(w2),(sizeof(login_ip_str))));
    (showmsg->showStatus(("Login server IP address : %s -> %s\n"), w2, sockt->ip2str(login_ip, ip_str)));
   }
  } else if (strcasecmp(w1, "login_port") == 0) {
   login_port = atoi(w2);
  } else if (strcasecmp(w1, "char_ip") == 0) {
   chr->ip = sockt->host2ip(w2);
   if (chr->ip) {
    char ip_str[16];
    (strlib->safestrncpy_((char_ip_str),(w2),(sizeof(char_ip_str))));
    (showmsg->showStatus(("Character server IP address : %s -> %s\n"), w2, sockt->ip2str(chr->ip, ip_str)));
   }
  } else if (strcasecmp(w1, "bind_ip") == 0) {
   bind_ip = sockt->host2ip(w2);
   if (bind_ip) {
    char ip_str[16];
    (strlib->safestrncpy_((bind_ip_str),(w2),(sizeof(bind_ip_str))));
    (showmsg->showStatus(("Character server binding IP address : %s -> %s\n"), w2, sockt->ip2str(bind_ip, ip_str)));
   }
  } else if (strcasecmp(w1, "char_port") == 0) {
   chr->port = atoi(w2);
  } else if (strcasecmp(w1, "char_server_type") == 0) {
   chr->server_type = atoi(w2);
  } else if (strcasecmp(w1, "char_new") == 0) {
   char_new = (
# 5517 "../../../server-code/src/char/char.c" 3 4
              _Bool
# 5517 "../../../server-code/src/char/char.c"
                  )atoi(w2);
  } else if (strcasecmp(w1, "char_new_display") == 0) {
   chr->new_display = atoi(w2);
  } else if (strcasecmp(w1, "max_connect_user") == 0) {
   max_connect_user = atoi(w2);
   if (max_connect_user < -1)
    max_connect_user = -1;
  } else if(strcasecmp(w1, "gm_allow_group") == 0) {
   gm_allow_group = atoi(w2);
  } else if (strcasecmp(w1, "autosave_time") == 0) {
   autosave_interval = atoi(w2) * 1000;
   if (autosave_interval <= 0)
    autosave_interval = (300*1000);
  } else if (strcasecmp(w1, "save_log") == 0) {
   save_log = (strlib->config_switch_(w2));
  }

   else if (strcasecmp(w1, "start_point_re") == 0) {
    char map[((11 + 1) + 4)];
    int x, y;
    if (sscanf(w2, "%15[^,],%d,%d", map, &x, &y) < 3)
     continue;
    start_point.map = mapindex->name2id(map);
    if (!start_point.map)
     (showmsg->showError(("Specified start_point_re '%s' not found in map-index cache.\n"), map));
    start_point.x = x;
    start_point.y = y;
   }
# 5558 "../../../server-code/src/char/char.c"
  else if (strcasecmp(w1, "start_items") == 0) {
   int i;
   char *split;

   i = 0;
   split = strtok(w2, ",");
   while (split != 
# 5564 "../../../server-code/src/char/char.c" 3 4
                  ((void *)0) 
# 5564 "../../../server-code/src/char/char.c"
                       && i < 32 * 3) {
    char *split2 = split;
    split = strtok(
# 5566 "../../../server-code/src/char/char.c" 3 4
                  ((void *)0)
# 5566 "../../../server-code/src/char/char.c"
                      , ",");
    start_items[i] = atoi(split2);

    if (start_items[i] < 0)
     start_items[i] = 0;

    ++i;
   }


   if( i%3 )
   {
    (showmsg->showWarning(("chr->config_read: There are not enough parameters in start_items, ignoring last item...\n")));
    if( i%3 == 1 )
     start_items[i-1] = 0;
    else
     start_items[i-2] = 0;
   }
  } else if (strcasecmp(w1, "start_zeny") == 0) {
   start_zeny = atoi(w2);
   if (start_zeny < 0)
    start_zeny = 0;
  } else if(strcasecmp(w1,"log_char")==0) {
   log_char = atoi(w2);
  } else if (strcasecmp(w1, "unknown_char_name") == 0) {
   (strlib->safestrncpy_((unknown_char_name),(w2),(sizeof(unknown_char_name))));
   unknown_char_name[(23 + 1)-1] = '\0';
  } else if (strcasecmp(w1, "name_ignoring_case") == 0) {
   name_ignoring_case = (
# 5594 "../../../server-code/src/char/char.c" 3 4
                        _Bool
# 5594 "../../../server-code/src/char/char.c"
                            )(strlib->config_switch_(w2));
  } else if (strcasecmp(w1, "char_name_option") == 0) {
   char_name_option = atoi(w2);
  } else if (strcasecmp(w1, "char_name_letters") == 0) {
   (strlib->safestrncpy_((char_name_letters),(w2),(sizeof(char_name_letters))));
  } else if (strcasecmp(w1, "char_del_level") == 0) {
   char_del_level = atoi(w2);
  } else if (strcasecmp(w1, "char_del_delay") == 0) {
   char_del_delay = atoi(w2);
  } else if (strcasecmp(w1, "char_aegis_delete") == 0) {
   char_aegis_delete = atoi(w2);
  } else if(strcasecmp(w1,"db_path")==0) {
   (strlib->safestrncpy_((db_path),(w2),(sizeof(db_path))));
  } else if (strcasecmp(w1, "fame_list_alchemist") == 0) {
   fame_list_size_chemist = atoi(w2);
   if (fame_list_size_chemist > 10) {
    (showmsg->showWarning(("Max fame list size is %d (fame_list_alchemist)\n"), 10));
    fame_list_size_chemist = 10;
   }
  } else if (strcasecmp(w1, "fame_list_blacksmith") == 0) {
   fame_list_size_smith = atoi(w2);
   if (fame_list_size_smith > 10) {
    (showmsg->showWarning(("Max fame list size is %d (fame_list_blacksmith)\n"), 10));
    fame_list_size_smith = 10;
   }
  } else if (strcasecmp(w1, "fame_list_taekwon") == 0) {
   fame_list_size_taekwon = atoi(w2);
   if (fame_list_size_taekwon > 10) {
    (showmsg->showWarning(("Max fame list size is %d (fame_list_taekwon)\n"), 10));
    fame_list_size_taekwon = 10;
   }
  } else if (strcasecmp(w1, "guild_exp_rate") == 0) {
   guild_exp_rate = atoi(w2);
  } else if (strcasecmp(w1, "char_maintenance_min_group_id") == 0) {
   char_maintenance_min_group_id = atoi(w2);
  } else if (strcasecmp(w1, "import") == 0) {
   chr->config_read(w2);
  } else
   chr->config_dispatch(w1,w2);
 }
 fclose(fp);

 (showmsg->showInfo(("Done reading %s.\n"), cfgName));
 return 0;
}

int do_final(void) {
 int i;

 (showmsg->showStatus(("Terminating...\n")));

 HPM->event(HPET_FINAL);

 chr->set_all_offline(-1);
 chr->set_all_offline_sql();

 inter->final();

 sockt->flush_fifos();

 do_final_mapif();
 loginif->final();

 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s`", ragsrvinfo_db) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 5658));

 chr->char_db_->destroy(chr->char_db_, 
# 5660 "../../../server-code/src/char/char.c" 3 4
                                      ((void *)0)
# 5660 "../../../server-code/src/char/char.c"
                                          );
 chr->online_char_db->destroy(chr->online_char_db, 
# 5661 "../../../server-code/src/char/char.c" 3 4
                                                  ((void *)0)
# 5661 "../../../server-code/src/char/char.c"
                                                      );
 auth_db->destroy(auth_db, 
# 5662 "../../../server-code/src/char/char.c" 3 4
                          ((void *)0)
# 5662 "../../../server-code/src/char/char.c"
                              );

 if( chr->char_fd != -1 ) {
  sockt->close(chr->char_fd);
  chr->char_fd = -1;
 }

 HPM_char_do_final();

 SQL->Free(inter->sql_handle);
 mapindex->final();

 for (i = 0; i < 2; i++)
  do { if (( (chr->server[i].maps)._max_ ) > 0) { (iMalloc->free((( (chr->server[i].maps)._data_ )),"../../../server-code/src/char/char.c", 5675, __func__)); ( (chr->server[i].maps)._data_ ) = 
# 5675 "../../../server-code/src/char/char.c" 3 4
 ((void *)0)
# 5675 "../../../server-code/src/char/char.c"
 ; ( (chr->server[i].maps)._max_ ) = 0; ( (chr->server[i].maps)._len_ ) = 0; } } while(
# 5675 "../../../server-code/src/char/char.c" 3 4
 0
# 5675 "../../../server-code/src/char/char.c"
 );

 (iMalloc->free((chr->CHAR_CONF_NAME),"../../../server-code/src/char/char.c", 5677, __func__));
 (iMalloc->free((chr->NET_CONF_NAME),"../../../server-code/src/char/char.c", 5678, __func__));
 (iMalloc->free((chr->SQL_CONF_NAME),"../../../server-code/src/char/char.c", 5679, __func__));
 (iMalloc->free((chr->INTER_CONF_NAME),"../../../server-code/src/char/char.c", 5680, __func__));

 HPM->event(HPET_POST_FINAL);

 (showmsg->showStatus(("Finished.\n")));
 return 
# 5685 "../../../server-code/src/char/char.c" 3 4
       0
# 5685 "../../../server-code/src/char/char.c"
                   ;
}





void do_abort(void)
{
}

void set_server_type(void) {
 (core->server_type) = SERVER_TYPE_CHAR;
}


void do_shutdown(void)
{
 if( core->runflag != CHARSERVER_ST_SHUTDOWN )
 {
  int id;
  core->runflag = CHARSERVER_ST_SHUTDOWN;
  (showmsg->showStatus(("Shutting down...\n")));

  for( id = 0; id < ( (int)(sizeof(chr->server)/sizeof((chr->server)[0])) ); ++id )
   mapif->server_reset(id);
  loginif->check_shutdown();
  sockt->flush_fifos();
  core->runflag = CORE_ST_STOP;
 }
}







static 
# 5723 "../../../server-code/src/char/char.c" 3 4
      _Bool 
# 5723 "../../../server-code/src/char/char.c"
      cmdline_arg_charconfig (const char *name, const char *params)
{
 (iMalloc->free((chr->CHAR_CONF_NAME),"../../../server-code/src/char/char.c", 5725, __func__));
 chr->CHAR_CONF_NAME = (iMalloc->astrdup((params),"../../../server-code/src/char/char.c", 5726, __func__));
 return 
# 5727 "../../../server-code/src/char/char.c" 3 4
       1
# 5727 "../../../server-code/src/char/char.c"
           ;
}






static 
# 5735 "../../../server-code/src/char/char.c" 3 4
      _Bool 
# 5735 "../../../server-code/src/char/char.c"
      cmdline_arg_interconfig (const char *name, const char *params)
{
 (iMalloc->free((chr->INTER_CONF_NAME),"../../../server-code/src/char/char.c", 5737, __func__));
 chr->INTER_CONF_NAME = (iMalloc->astrdup((params),"../../../server-code/src/char/char.c", 5738, __func__));
 return 
# 5739 "../../../server-code/src/char/char.c" 3 4
       1
# 5739 "../../../server-code/src/char/char.c"
           ;
}






static 
# 5747 "../../../server-code/src/char/char.c" 3 4
      _Bool 
# 5747 "../../../server-code/src/char/char.c"
      cmdline_arg_netconfig (const char *name, const char *params)
{
 (iMalloc->free((chr->NET_CONF_NAME),"../../../server-code/src/char/char.c", 5749, __func__));
 chr->NET_CONF_NAME = (iMalloc->astrdup((params),"../../../server-code/src/char/char.c", 5750, __func__));
 return 
# 5751 "../../../server-code/src/char/char.c" 3 4
       1
# 5751 "../../../server-code/src/char/char.c"
           ;
}



void cmdline_args_init_local(void)
{
 cmdline->arg_add(((unsigned int)-1), "--" "char-config", '\0', cmdline_arg_charconfig, "Alternative char-server configuration.", CMDLINE_OPT_PARAM);
 cmdline->arg_add(((unsigned int)-1), "--" "inter-config", '\0', cmdline_arg_interconfig, "Alternative inter-server configuration.", CMDLINE_OPT_PARAM);
 cmdline->arg_add(((unsigned int)-1), "--" "net-config", '\0', cmdline_arg_netconfig, "Alternative network configuration.", CMDLINE_OPT_PARAM);
}

int do_init(int argc, char **argv) {
 int i;
 memset(&skillid2idx, 0, sizeof(skillid2idx));

 char_load_defaults();

 chr->CHAR_CONF_NAME = (iMalloc->astrdup(("conf/char-server.conf"),"../../../server-code/src/char/char.c", 5769, __func__));
 chr->NET_CONF_NAME = (iMalloc->astrdup(("conf/network.conf"),"../../../server-code/src/char/char.c", 5770, __func__));
 chr->SQL_CONF_NAME = (iMalloc->astrdup(("conf/inter-server.conf"),"../../../server-code/src/char/char.c", 5771, __func__));
 chr->INTER_CONF_NAME = (iMalloc->astrdup(("conf/inter-server.conf"),"../../../server-code/src/char/char.c", 5772, __func__));

 for (i = 0; i < 2; i++)
  memset(&(chr->server[i].maps), 0, sizeof(chr->server[i].maps));

 HPM_char_do_init();
 cmdline->exec(argc, argv, CMDLINE_OPT_PREINIT);
 HPM->config_read();
 HPM->event(HPET_PRE_INIT);


 mapindex->init();


  start_point.map = mapindex->name2id("iz_int");




 cmdline->exec(argc, argv, CMDLINE_OPT_NORMAL);
 chr->config_read(chr->CHAR_CONF_NAME);
 sockt->net_config_read(chr->NET_CONF_NAME);
 chr->sql_config_read(chr->SQL_CONF_NAME);

 if (strcmp(chr->userid, "s1")==0 && strcmp(chr->passwd, "p1")==0) {
  (showmsg->showWarning(("Using the default user/password s1/p1 is NOT RECOMMENDED.\n")));
  (showmsg->showNotice(("Please edit your 'login' table to create a proper inter-server user/password (gender 'S')\n")));
  (showmsg->showNotice(("And then change the user/password to use in conf/char-server.conf (or conf/import/char_conf.txt)\n")));
 }

 inter->init_sql(chr->INTER_CONF_NAME);

 auth_db = DB->alloc("../../../server-code/src/char/char.c",__func__,5804,DB_INT,(DB_OPT_RELEASE_DATA),sizeof(int));
 chr->online_char_db = DB->alloc("../../../server-code/src/char/char.c",__func__,5805,DB_INT,(DB_OPT_RELEASE_DATA),sizeof(int));

 HPM->event(HPET_INIT);

 chr->mmo_char_sql_init();
 chr->read_fame_list();

 if ((sockt->naddr_ != 0) && (!login_ip || !chr->ip)) {
  char ip_str[16];
  sockt->ip2str(sockt->addr_[0], ip_str);

  if (sockt->naddr_ > 1)
   (showmsg->showStatus(("Multiple interfaces detected..  using %s as our IP address\n"), ip_str));
  else
   (showmsg->showStatus(("Defaulting to %s as our IP address\n"), ip_str));
  if (!login_ip) {
   (strlib->safestrncpy_((login_ip_str),(ip_str),(sizeof(login_ip_str))));
   login_ip = sockt->str2ip(login_ip_str);
  }
  if (!chr->ip) {
   (strlib->safestrncpy_((char_ip_str),(ip_str),(sizeof(char_ip_str))));
   chr->ip = sockt->str2ip(char_ip_str);
  }
 }

 loginif->init();
 do_init_mapif();


 timer->add_func_list(chr->broadcast_user_count, "chr->broadcast_user_count");
 timer->add_interval(timer->gettick() + 1000, chr->broadcast_user_count, 0, 0, 5 * 1000);


 timer->add_func_list(chr->waiting_disconnect, "chr->waiting_disconnect");


 timer->add_func_list(chr->online_data_cleanup, "chr->online_data_cleanup");
 timer->add_interval(timer->gettick() + 1000, chr->online_data_cleanup, 0, 0, 600 * 1000);



 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `account_id` = '0'", char_db) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 5847));


 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `guild_lv` = '0' AND `max_member` = '0' AND `exp` = '0' AND `next_exp` = '0' AND `average_lv` = '0'", guild_db) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 5851));


 if( (-1) == SQL->Query(inter->sql_handle, "DELETE FROM `%s` WHERE `guild_id` = '0' AND `account_id` = '0' AND `char_id` = '0'", guild_member_db) )
  (SQL->ShowDebug_((inter->sql_handle), "../../../server-code/src/char/char.c", 5855));

 sockt->set_defaultparse(chr->parse_char);

 if ((chr->char_fd = sockt->make_listen_bind(bind_ip,chr->port)) == -1) {
  (showmsg->showFatalError(("Failed to bind to port '""\033[1;37m""%d""\033[0m""'\n"),chr->port));
  exit(
# 5861 "../../../server-code/src/char/char.c" 3 4
      1
# 5861 "../../../server-code/src/char/char.c"
                  );
 }

 Sql_HerculesUpdateCheck(inter->sql_handle);

 console->input->setSQL(inter->sql_handle);
 console->display_gplnotice();

 (showmsg->showStatus(("The char-server is ""\033[1;32m""ready""\033[0m"" (Server is listening on the port %d).\n\n"), chr->port));

 if( core->runflag != CORE_ST_STOP )
 {
  core->shutdown_callback = do_shutdown;
  core->runflag = CHARSERVER_ST_RUNNING;
 }

 HPM->event(HPET_READY);

 return 0;
}

void char_load_defaults(void)
{
 mapindex_defaults();
 pincode_defaults();
 char_defaults();
 loginif_defaults();
 mapif_defaults();
 inter_auction_defaults();
 inter_elemental_defaults();
 inter_guild_defaults();
 inter_homunculus_defaults();
 inter_mail_defaults();
 inter_mercenary_defaults();
 inter_party_defaults();
 inter_pet_defaults();
 inter_quest_defaults();
 inter_storage_defaults();
 inter_defaults();
 geoip_defaults();
}

void char_defaults(void)
{
 chr = &char_s;

 memset(chr->server, 0, sizeof(chr->server));

 chr->login_fd = 0;
 chr->char_fd = -1;
 chr->online_char_db = 
# 5911 "../../../server-code/src/char/char.c" 3 4
                      ((void *)0)
# 5911 "../../../server-code/src/char/char.c"
                          ;
 chr->char_db_ = 
# 5912 "../../../server-code/src/char/char.c" 3 4
                ((void *)0)
# 5912 "../../../server-code/src/char/char.c"
                    ;

 memset(chr->userid, 0, sizeof(chr->userid));
 memset(chr->passwd, 0, sizeof(chr->passwd));
 memset(chr->server_name, 0, sizeof(chr->server_name));

 chr->ip = 0;
 chr->port = 6121;
 chr->server_type = 0;
 chr->new_display = 0;

 chr->waiting_disconnect = char_waiting_disconnect;
 chr->delete_char_sql = char_delete_char_sql;
 chr->create_online_char_data = char_create_online_char_data;
 chr->set_account_online = char_set_account_online;
 chr->set_account_offline = char_set_account_offline;
 chr->set_char_charselect = char_set_char_charselect;
 chr->set_char_online = char_set_char_online;
 chr->set_char_offline = char_set_char_offline;
 chr->db_setoffline = char_db_setoffline;
 chr->db_kickoffline = char_db_kickoffline;
 chr->set_login_all_offline = char_set_login_all_offline;
 chr->set_all_offline = char_set_all_offline;
 chr->set_all_offline_sql = char_set_all_offline_sql;
 chr->create_charstatus = char_create_charstatus;
 chr->mmo_char_tosql = char_mmo_char_tosql;
 chr->memitemdata_to_sql = char_memitemdata_to_sql;
 chr->mmo_gender = char_mmo_gender;
 chr->mmo_chars_fromsql = char_mmo_chars_fromsql;
 chr->mmo_char_fromsql = char_mmo_char_fromsql;
 chr->mmo_char_sql_init = char_mmo_char_sql_init;
 chr->char_slotchange = char_char_slotchange;
 chr->rename_char_sql = char_rename_char_sql;
 chr->check_char_name = char_check_char_name;
 chr->make_new_char_sql = char_make_new_char_sql;
 chr->divorce_char_sql = char_divorce_char_sql;
 chr->count_users = char_count_users;
 chr->mmo_char_tobuf = char_mmo_char_tobuf;
 chr->mmo_char_send099d = char_mmo_char_send099d;
 chr->mmo_char_send_ban_list = char_mmo_char_send_ban_list;
 chr->mmo_char_send_slots_info = char_mmo_char_send_slots_info;
 chr->mmo_char_send_characters = char_mmo_char_send_characters;
 chr->char_married = char_char_married;
 chr->char_child = char_char_child;
 chr->char_family = char_char_family;
 chr->disconnect_player = char_disconnect_player;
 chr->authfail_fd = char_authfail_fd;
 chr->request_account_data = char_request_account_data;
 chr->auth_ok = char_auth_ok;
 chr->ping_login_server = char_ping_login_server;
 chr->parse_fromlogin_connection_state = char_parse_fromlogin_connection_state;
 chr->auth_error = char_auth_error;
 chr->parse_fromlogin_auth_state = char_parse_fromlogin_auth_state;
 chr->parse_fromlogin_account_data = char_parse_fromlogin_account_data;
 chr->parse_fromlogin_login_pong = char_parse_fromlogin_login_pong;
 chr->changesex = char_changesex;
 chr->parse_fromlogin_changesex_reply = char_parse_fromlogin_changesex_reply;
 chr->parse_fromlogin_account_reg2 = char_parse_fromlogin_account_reg2;
 chr->parse_fromlogin_ban = char_parse_fromlogin_ban;
 chr->parse_fromlogin_kick = char_parse_fromlogin_kick;
 chr->update_ip = char_update_ip;
 chr->parse_fromlogin_update_ip = char_parse_fromlogin_update_ip;
 chr->parse_fromlogin_accinfo2_failed = char_parse_fromlogin_accinfo2_failed;
 chr->parse_fromlogin_accinfo2_ok = char_parse_fromlogin_accinfo2_ok;
 chr->parse_fromlogin = char_parse_fromlogin;
 chr->request_accreg2 = char_request_accreg2;
 chr->global_accreg_to_login_start = char_global_accreg_to_login_start;
 chr->global_accreg_to_login_send = char_global_accreg_to_login_send;
 chr->global_accreg_to_login_add = char_global_accreg_to_login_add;
 chr->read_fame_list = char_read_fame_list;
 chr->send_fame_list = char_send_fame_list;
 chr->update_fame_list = char_update_fame_list;
 chr->loadName = char_loadName;
 chr->parse_frommap_datasync = char_parse_frommap_datasync;
 chr->parse_frommap_skillid2idx = char_parse_frommap_skillid2idx;
 chr->map_received_ok = char_map_received_ok;
 chr->send_maps = char_send_maps;
 chr->parse_frommap_map_names = char_parse_frommap_map_names;
 chr->send_scdata = char_send_scdata;
 chr->parse_frommap_request_scdata = char_parse_frommap_request_scdata;
 chr->parse_frommap_set_users_count = char_parse_frommap_set_users_count;
 chr->parse_frommap_set_users = char_parse_frommap_set_users;
 chr->save_character_ack = char_save_character_ack;
 chr->parse_frommap_save_character = char_parse_frommap_save_character;
 chr->select_ack = char_select_ack;
 chr->parse_frommap_char_select_req = char_parse_frommap_char_select_req;
 chr->change_map_server_ack = char_change_map_server_ack;
 chr->parse_frommap_change_map_server = char_parse_frommap_change_map_server;
 chr->parse_frommap_remove_friend = char_parse_frommap_remove_friend;
 chr->char_name_ack = char_char_name_ack;
 chr->parse_frommap_char_name_request = char_parse_frommap_char_name_request;
 chr->parse_frommap_change_email = char_parse_frommap_change_email;
 chr->ban = char_ban;
 chr->unban = char_unban;
 chr->ask_name_ack = char_ask_name_ack;
 chr->changecharsex = char_changecharsex;
 chr->parse_frommap_change_account = char_parse_frommap_change_account;
 chr->parse_frommap_fame_list = char_parse_frommap_fame_list;
 chr->parse_frommap_divorce_char = char_parse_frommap_divorce_char;
 chr->parse_frommap_ragsrvinfo = char_parse_frommap_ragsrvinfo;
 chr->parse_frommap_set_char_offline = char_parse_frommap_set_char_offline;
 chr->parse_frommap_set_all_offline = char_parse_frommap_set_all_offline;
 chr->parse_frommap_set_char_online = char_parse_frommap_set_char_online;
 chr->parse_frommap_build_fame_list = char_parse_frommap_build_fame_list;
 chr->parse_frommap_save_status_change_data = char_parse_frommap_save_status_change_data;
 chr->send_pong = char_send_pong;
 chr->parse_frommap_ping = char_parse_frommap_ping;
 chr->map_auth_ok = char_map_auth_ok;
 chr->map_auth_failed = char_map_auth_failed;
 chr->parse_frommap_auth_request = char_parse_frommap_auth_request;
 chr->parse_frommap_update_ip = char_parse_frommap_update_ip;
 chr->parse_frommap_request_stats_report = char_parse_frommap_request_stats_report;
 chr->parse_frommap_scdata_update = char_parse_frommap_scdata_update;
 chr->parse_frommap_scdata_delete = char_parse_frommap_scdata_delete;
 chr->parse_frommap = char_parse_frommap;
 chr->search_mapserver = char_search_mapserver;
 chr->mapif_init = char_mapif_init;
 chr->lan_subnet_check = char_lan_subnet_check;
 chr->delete2_ack = char_delete2_ack;
 chr->delete2_accept_actual_ack = char_delete2_accept_actual_ack;
 chr->delete2_accept_ack = char_delete2_accept_ack;
 chr->delete2_cancel_ack = char_delete2_cancel_ack;
 chr->delete2_req = char_delete2_req;
 chr->delete2_accept = char_delete2_accept;
 chr->delete2_cancel = char_delete2_cancel;
 chr->send_account_id = char_send_account_id;
 chr->parse_char_connect = char_parse_char_connect;
 chr->send_map_info = char_send_map_info;
 chr->send_wait_char_server = char_send_wait_char_server;
 chr->search_default_maps_mapserver = char_search_default_maps_mapserver;
 chr->parse_char_select = char_parse_char_select;
 chr->creation_failed = char_creation_failed;
 chr->creation_ok = char_creation_ok;
 chr->parse_char_create_new_char = char_parse_char_create_new_char;
 chr->delete_char_failed = char_delete_char_failed;
 chr->delete_char_ok = char_delete_char_ok;
 chr->parse_char_delete_char = char_parse_char_delete_char;
 chr->parse_char_ping = char_parse_char_ping;
 chr->allow_rename = char_allow_rename;
 chr->parse_char_rename_char = char_parse_char_rename_char;
 chr->parse_char_rename_char2 = char_parse_char_rename_char2;
 chr->rename_char_ack = char_rename_char_ack;
 chr->parse_char_rename_char_confirm = char_parse_char_rename_char_confirm;
 chr->captcha_notsupported = char_captcha_notsupported;
 chr->parse_char_request_captcha = char_parse_char_request_captcha;
 chr->parse_char_check_captcha = char_parse_char_check_captcha;
 chr->parse_char_delete2_req = char_parse_char_delete2_req;
 chr->parse_char_delete2_accept = char_parse_char_delete2_accept;
 chr->parse_char_delete2_cancel = char_parse_char_delete2_cancel;
 chr->login_map_server_ack = char_login_map_server_ack;
 chr->parse_char_login_map_server = char_parse_char_login_map_server;
 chr->parse_char_pincode_check = char_parse_char_pincode_check;
 chr->parse_char_pincode_window = char_parse_char_pincode_window;
 chr->parse_char_pincode_change = char_parse_char_pincode_change;
 chr->parse_char_pincode_first_pin = char_parse_char_pincode_first_pin;
 chr->parse_char_request_chars = char_parse_char_request_chars;
 chr->change_character_slot_ack = char_change_character_slot_ack;
 chr->parse_char_move_character = char_parse_char_move_character;
 chr->parse_char_unknown_packet = char_parse_char_unknown_packet;
 chr->parse_char = char_parse_char;
 chr->broadcast_user_count = char_broadcast_user_count;
 chr->send_accounts_tologin_sub = char_send_accounts_tologin_sub;
 chr->send_accounts_tologin = char_send_accounts_tologin;
 chr->check_connect_login_server = char_check_connect_login_server;
 chr->online_data_cleanup_sub = char_online_data_cleanup_sub;
 chr->online_data_cleanup = char_online_data_cleanup;
 chr->sql_config_read = char_sql_config_read;
 chr->config_dispatch = char_config_dispatch;
 chr->config_read = char_config_read;
}
