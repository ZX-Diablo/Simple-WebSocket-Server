#ifndef REGEX_HPP
#define	REGEX_HPP

#if defined _SIMPLEWEB_CPP11_STL_ && !defined _SIMPLEWEB_NO_CPP11_REGEX_
	#ifndef _SIMPLEWEB_CPP11_REGEX
		#define _SIMPLEWEB_CPP11_REGEX
	#endif
#endif

#ifdef _SIMPLEWEB_CPP11_REGEX
	#include <regex>
#else
	#include <boost/regex.hpp>
#endif

namespace SimpleWeb
{

#ifdef _SIMPLEWEB_CPP11_REGEX
	using std::regex;
	using std::smatch;
	using std::regex_match;
#else
	using boost::regex;
	using boost::smatch;
	using boost::regex_match;
#endif

}

#endif	/* REGEX_HPP */
