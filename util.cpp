#include "util.h"

std::random_device Util::g_randomDevice;
std::mt19937 Util::g_randomGenerator = std::mt19937(g_randomDevice());
