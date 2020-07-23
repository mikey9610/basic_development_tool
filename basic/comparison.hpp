/*
	STATIC CLASS COMPARISON
*/

#ifndef CAMPARISON
#define CAMPARISON

namespace bdt {

class cmp {
public:

	template<typename T>
	inline static T bigger(const T& value1, const T& value2) {	return (value1>value2)?value1:value2;	}

	template<typename T>
	inline static T smaller(const T& value1, const T& value2) {	return (value1<value2)?value1:value2;	}

};

}

#endif