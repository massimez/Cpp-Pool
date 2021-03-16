#ifndef I_MONITOR_DISPLAY_HPP_
#define I_MONITOR_DISPLAY_HPP_

class IMonitorDisplay
{
public:
    // IMonitorDisplay() = delete;
    // ~IMonitorDisplay() = delete;
    // IMonitorDisplay(const IMonitorDisplay &p2) = delete;
    // IMonitorDisplay &IMonitorDisplay::operator=(const IMonitorDisplay&) = delete;

    // displays the monitor module in a graphical manner
    // NOTE: this is probably the wrong signature.
    // It probably needs to take an SFML window as a parameter,
    // but I haven't installed SFML yet and I don't feel like writing dummy code
    virtual void displayGraphical() = 0;
    
    // displays the monitor module in the terminal
    virtual void displayText() = 0;
};

#endif