#pragma once
#include <string>
#ifdef HW102DLL_EXPORTS
#define LEAVER_API __declspec(dllexport)
#else
#define LEAVER_API __declspec(dllimport)
#endif

using namespace std;

class Leaver {
public:
	LEAVER_API string leave(string a);
};
