#include <stdarg.h>
#include <stdio.h>
#ifndef _WIN32
	#include <unistd.h>
#endif

#include <log.h>

#if CPUINFO_LOG_LEVEL >= CPUINFO_LOG_ERROR
	void cpuinfo_log_error(const char* format, ...) {
		va_list args;
		va_start(args, format);

		#if defined(__ANDROID__) || defined(_WIN32)
			fprintf(stderr, "Error: ");
			vfprintf(stderr, format, args);
			fprintf(stderr, "\n");
			fflush(stderr);
		#else
			dprintf(STDERR_FILENO, "Error: ");
			vdprintf(STDERR_FILENO, format, args);
			dprintf(STDERR_FILENO, "\n");
		#endif

		va_end(args);
	}
#endif

#if CPUINFO_LOG_LEVEL >= CPUINFO_LOG_WARNING
	void cpuinfo_log_warning(const char* format, ...) {
		va_list args;
		va_start(args, format);

		#if defined(__ANDROID__) || defined(_WIN32)
			fprintf(stderr, "Warning: ");
			vfprintf(stderr, format, args);
			fprintf(stderr, "\n");
			fflush(stderr);
		#else
			dprintf(STDERR_FILENO, "Warning: ");
			vdprintf(STDERR_FILENO, format, args);
			dprintf(STDERR_FILENO, "\n");
		#endif

		va_end(args);
	}
#endif

#if CPUINFO_LOG_LEVEL >= CPUINFO_LOG_INFO
	void cpuinfo_log_info(const char* format, ...) {
		va_list args;
		va_start(args, format);

		#if defined(__ANDROID__) || defined(_WIN32)
			printf("Note: ");
			vprintf(format, args);
			printf("\n");
			fflush(stdout);
		#else
			vdprintf(STDOUT_FILENO, format, args);
			dprintf(STDOUT_FILENO, "\n");
		#endif

		va_end(args);
	}
#endif

#if CPUINFO_LOG_LEVEL >= CPUINFO_LOG_DEBUG
	void cpuinfo_log_debug(const char* format, ...) {
		va_list args;
		va_start(args, format);

		#if defined(__ANDROID__) || defined(_WIN32)
			printf("Debug: ");
			vprintf(format, args);
			printf("\n");
			fflush(stdout);
		#else
			vdprintf(STDOUT_FILENO, format, args);
			dprintf(STDOUT_FILENO, "\n");
		#endif

		va_end(args);
	}
#endif
