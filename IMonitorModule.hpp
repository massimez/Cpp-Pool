#ifndef I_MONITOR_MODULE_HPP_
#define I_MONITOR_MODULE_HPP_

class IMonitorModule
{
public:
    // IMonitorModule() = delete;
    // ~IMonitorModule() = delete;
    // IMonitorModule(const IMonitorModule &p2) = delete;
    // IMonitorModule &IMonitorModule::operator=(const IMonitorModule&) = delete;

    // initializes the monitor (if necessary)
    virtual void init() = 0;
    
    // changes the internal state of variables (if necessary)
    virtual void update() = 0;
};

#endif