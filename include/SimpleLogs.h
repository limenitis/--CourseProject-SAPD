#ifndef COLOR_MODE_ON
	#define COLOR_MODE_ON
#endif

#ifdef COLOR_MODE_ON
	#define DEFAULT "\x1b[30m"
	#define GREEN   "\x1b[32m"
	#define RED     "\x1b[31m" 
	#define YELLOW  "\x1b[33m"
	#define RESET   "\x1b[0m" 
#else 
	#define DEFAULT ""
	#define GREEN   ""
	#define RED     "" 
	#define YELLOW  ""
	#define RESET   ""
#endif


#ifndef LOG_MODE_ON
	#define LOG_MODE_ON
#endif
#ifdef LOG_MODE_ON
	#define LOG_MODE_INFO
	#define LOG_MODE_ERROR
	#define LOG_MODE_WARNING
#endif

#ifdef LOG_MODE_INFO
	#define log_info( class_name, func, message);              \
	cerr << GREEN    << "| [INFO]    [" <<  class_name << "] [" << func << "] : " << message << " "   << RESET << endl;
	#define log_info_val( class_name, func, message, val);     \
	cerr << GREEN    << "| [INFO]    [" <<  class_name << "] [" << func << "] : " << message << " | " << val << RESET<< endl;
#else
	#define log_info( class_name, func, message);              \
	// nothig do
	#define log_info_val( class_name, func, message, val);     \
	// nothig do
#endif

#ifdef LOG_MODE_ERROR
	#define log_error( class_name, func, message );            \
	cerr << RED      << "| [ERROR]   [" <<  class_name << "] [" << func << "] : " << message << " "   << RESET << endl;
#else
	#define log_error( class_name, func, message );            \
	// nothig do
#endif

#ifdef LOG_MODE_WARNING
	#define log_werning( class_name, func, message );          \
	cerr << YELLOW   << "| [WARNING] [" <<  class_name << "] [" << func << "] : " << message << " "   << RESET << endl;
#else
	#define log_werning( class_name, func, message );          \
	// nothig do
#endif
