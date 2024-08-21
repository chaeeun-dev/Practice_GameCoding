#pragma once
// 자주 사용하는 헤더

#include <iostream>
#include <Windows.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <format>

using namespace std;

#include "Types.h"
#include "Enums.h"
#include "Defines.h"

// 메모리 누수 감지 - 출력 창에 해지 안 된 메모리를 알려줌
#define _CRTBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif