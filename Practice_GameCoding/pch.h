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
#include <format>

using namespace std;

#include "Types.h"
#include "Enums.h"
#include "Defines.h"

// �޸� ���� ���� - ��� â�� ���� �� �� �޸𸮸� �˷���
#define _CRTBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif