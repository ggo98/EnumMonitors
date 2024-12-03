// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <vector>
#include <algorithm>
#include <iostream>

void EnumerateMonitors();
void EnumerateMonitorsWithNames();

int main()
{
    //std::cout << "Hello World!\n";
    
    EnumerateMonitors();
    //EnumerateMonitorsWithNames();

}

///*
struct MonitorInfo {
    HMONITOR hMonitor;
    RECT rect;
#ifdef UNICODE
    std::wstring friendlyName;
#else
    std::string friendlyName;
#endif
};

BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData) {
    MONITORINFO monitorInfo;
    monitorInfo.cbSize = sizeof(MONITORINFO);

    if (GetMonitorInfo(hMonitor, &monitorInfo)) {
        MonitorInfo info;
        info.hMonitor = hMonitor;
        info.rect = monitorInfo.rcMonitor;

        // Retrieve the friendly name using EnumDisplayDevices
        DISPLAY_DEVICE displayDevice;
        displayDevice.cb = sizeof(DISPLAY_DEVICE);

        // EnumDisplayDevices with NULL as deviceName will go through each display adapter
        for (int deviceIndex = 0; EnumDisplayDevices(NULL, deviceIndex, &displayDevice, 0); deviceIndex++) {
            if (displayDevice.StateFlags & DISPLAY_DEVICE_ACTIVE) {
                DISPLAY_DEVICE monitorDevice;
                monitorDevice.cb = sizeof(DISPLAY_DEVICE);

                // Get the monitor attached to the display adapter
                if (EnumDisplayDevices(displayDevice.DeviceName, 0, &monitorDevice, 0)) {
                    // Match the monitor's coordinates to ensure it’s the right one
                    if (monitorInfo.rcMonitor.left == lprcMonitor->left &&
                        monitorInfo.rcMonitor.top == lprcMonitor->top) {
                        info.friendlyName = monitorDevice.DeviceString;
                        break;
                    }
                }
            }
        }

        std::vector<MonitorInfo>* monitors = reinterpret_cast<std::vector<MonitorInfo>*>(dwData);
        if (0 == info.rect.left) // normally main display...
            monitors->insert(monitors->begin(), info);
        else
            monitors->push_back(info);
    }
    return TRUE;
}

void EnumerateMonitors() {
    std::vector<MonitorInfo> monitors;

    // Enumerate monitors and gather information
    EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, reinterpret_cast<LPARAM>(&monitors));

    // Output each monitor's details
    for (const auto& monitor : monitors) {
        std::cout << "Monitor Rectangle: Left=" << monitor.rect.left << ", Top=" << monitor.rect.top;
        std::cout << ", Right=" << monitor.rect.right << ", Bottom=" << monitor.rect.bottom << std::endl;
#ifdef UNICODE
        std::wcout << "Friendly Name: " << monitor.friendlyName << std::endl;
#else
        std::cout << "Friendly Name: " << monitor.friendlyName << std::endl;
#endif
    }
}
//*/


//BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData) {
//    MONITORINFOEX monitorInfo;
//    memset(&monitorInfo, 0, sizeof(MONITORINFOEX));
//    monitorInfo.cbSize = sizeof(MONITORINFOEX);
//
//    // Get information about the monitor
//    if (GetMonitorInfo(hMonitor, &monitorInfo)) {
//        // Use EnumDisplayDevices with the monitor's device name to get a friendly name
//        DISPLAY_DEVICE displayDevice = { 0 };
//        displayDevice.cb = sizeof(DISPLAY_DEVICE);
//
//        if (EnumDisplayDevices(monitorInfo.szDevice, 0, &displayDevice, EDD_GET_DEVICE_INTERFACE_NAME)) {
//            // Print the friendly name of the monitor
//            std::wcout << L"Monitor Friendly Name: " << displayDevice.DeviceString << std::endl;
//            std::wcout << L"Monitor Device Name: " << monitorInfo.szDevice << std::endl;
//            std::wcout << L"Monitor Rectangle: Left: " << monitorInfo.rcMonitor.left
//                << L", Top: " << monitorInfo.rcMonitor.top
//                << L", Right: " << monitorInfo.rcMonitor.right
//                << L", Bottom: " << monitorInfo.rcMonitor.bottom << std::endl;
//        }
//    }
//    return TRUE; // Continue to the next monitor
//}
//
//void EnumerateMonitorsWithNames() 
//{
//    EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, 0);
//}

//struct MonitorInfo {
//    HMONITOR hMonitor;
//    RECT rect;
//};
//
//BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData) {
//    MONITORINFO monitorInfo;
//    monitorInfo.cbSize = sizeof(MONITORINFO);
//    if (GetMonitorInfo(hMonitor, &monitorInfo)) {
//        MonitorInfo info = { hMonitor, monitorInfo.rcMonitor };
//        std::vector<MonitorInfo>* monitors = reinterpret_cast<std::vector<MonitorInfo>*>(dwData);
//        monitors->push_back(info);
//    }
//    return TRUE; // Continue to the next monitor
//}
//
//void EnumerateMonitorsLeftToRight() 
//{
//    std::vector<MonitorInfo> monitors;
//
//    // Enumerate monitors and populate the vector
//    EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, reinterpret_cast<LPARAM>(&monitors));
//
//    // Sort monitors left to right by their `left` coordinate
//    std::sort(monitors.begin(), monitors.end(), [](const MonitorInfo& a, const MonitorInfo& b) {
//        return a.rect.left < b.rect.left;
//        });
//
//    // Display sorted monitors' rectangles
//    for (const auto& monitor : monitors) {
//        std::cout << "Monitor Rectangle: ";
//        std::cout << "Left: " << monitor.rect.left << ", Top: " << monitor.rect.top;
//        std::cout << ", Right: " << monitor.rect.right << ", Bottom: " << monitor.rect.bottom << std::endl;
//    }
//}



