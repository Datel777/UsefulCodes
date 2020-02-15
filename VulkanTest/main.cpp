#include <iostream>
#include "vulkan/vulkan.h"

using namespace std;

int main()
{
    VkInstanceCreateInfo info{}; //initialize with zeros

    VkInstance instance;

    if (vkCreateInstance(&info, nullptr, &instance) == VK_SUCCESS)
    {
        cout << "SUCCESS!!!" << endl;
    } else {
        cout << "SOMETHING GOES WRONG" << endl;
    }

    system("pause");

    return 0;
}
