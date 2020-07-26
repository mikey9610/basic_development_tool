/*
	STATIC CLASS COMPARISON
*/

#ifndef CAMPARISON
#define CAMPARISON

namespace bdt {

class cmp {
private:

	cmp() {}

public:

	template<typename T>
	inline static T _bigger(const T& value1, const T& value2) {	return (value1>value2)?value1:value2;	}

	template<typename T>
	inline static T _smaller(const T& value1, const T& value2) {	return (value1<value2)?value1:value2;	}

};

}

#endif