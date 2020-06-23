#pragma once
#include "ControllerSpec1.1.h"
#include "DirectInput.h"
#include "N64Controller.h"
#include <memory>

class CProject64Input
{
public:
    CProject64Input(HINSTANCE hinst);
    ~CProject64Input();

    void InitiateControllers(CONTROL_INFO * ControlInfo);
    void StartScanDevices(int32_t DisplayCtrlId);
    void EndScanDevices(void);
    CDirectInput::ScanResult ScanDevices(BUTTON & Button);
    std::wstring ButtonAssignment(BUTTON & Button);

    inline HINSTANCE hInst(void) const { return m_hinst; }
    inline bool IsScanning(void) const { return m_Scanning; }
    inline int32_t DisplayCtrlId(void) const { return m_DisplayCtrlId; }
    inline N64CONTROLLER & Controllers(int32_t Controller) { return m_Controllers[Controller]; }

private:
    CProject64Input();
    CProject64Input(const CProject64Input&);
    CProject64Input& operator=(const CProject64Input&);

    N64CONTROLLER m_Controllers[4];
    std::unique_ptr<CDirectInput> m_DirectInput;
    HINSTANCE m_hinst;
    bool m_Scanning;
    int32_t m_DisplayCtrlId;
};

extern CProject64Input * g_InputPlugin;