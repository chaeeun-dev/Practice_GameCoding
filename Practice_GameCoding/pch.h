#pragma once
// ���� ����ϴ� ���

#include <iostream>
#include <Windows.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>

// C++ 20
#include <format>
#include <filesystem>
namespace fs = std::filesystem;

using namespace std;

#include "Types.h"
#include "Enums.h"
#include "Defines.h"
#include "Utils.h"
#include "values.h"

// �޸� ���� ���� - ��� â�� ���� �� �� �޸𸮸� �˷���
#define _CRTBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#pragma comment(lib, "msimg32.lib")	// TransparentBlt �ʿ�