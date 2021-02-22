#ifndef ENABLE_COLOR
	#define ENABLE_COLOR
#endif

#ifdef ENABLE_COLOR
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


#ifndef ENABLE_LOGS
	#define ENABLE_LOGS
#endif
#ifdef ENABLE_LOGS
	#define ENABLE_INFO
	#define ENABLE_ERROR
	#define ENABLE_WARNING
#endif

#ifdef ENABLE_INFO
	#define log_info( class_name, func, message);              \
	std::cerr << GREEN    << "[INFO]    [" <<  class_name << "] [" << func << "] : " << message << " "   << RESET << endl;
#else
	#define log_info( class_name, func, message);              \
	// nothig do
	#define log_info_val( class_name, func, message, val);     \
	// nothig do
#endif

#ifdef ENABLE_ERROR
	#define log_error( class_name, func, message );            \
	std::cerr << RED      << "[ERROR]   [" <<  class_name << "] [" << func << "] : " << message << " "   << RESET << endl;
#else
	#define log_error( class_name, func, message );            \
	// nothig do
#endif

#ifdef ENABLE_WARNING
	#define log_warning( class_name, func, message );          \
	std::cerr << YELLOW   << "[WARNING] [" <<  class_name << "] [" << func << "] : " << message << " "   << RESET << endl;
#else
	#define log_werning( class_name, func, message );          \
	// nothig do
#endif
