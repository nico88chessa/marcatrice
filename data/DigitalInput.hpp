#ifndef DIGITALINPUT_HPP
#define DIGITALINPUT_HPP

#include <QString>

#include <configure.h>
#include <Constants.hpp>

namespace PROGRAM_NAMESPACE {

class DigitalInput {
public:
    using Ptr = DigitalInput*;
    using ConstPtr = const DigitalInput*;

private:
    QString name;
    int channel;
    bool invertLogic;
    DeviceKey device;
    bool isAlarm;
    IOType elementType;

public:
    DigitalInput() :
        DigitalInput("", -1, false, DeviceKey::NONE, false, IOType::NOT_VALID) { }

    DigitalInput(QString name, int channel, bool invertLogic,
                 DeviceKey device, bool isAlarm, IOType elementType) :
        name(name), channel(channel), invertLogic(invertLogic),
        device(device), isAlarm(isAlarm), elementType(elementType) { }

    inline QString getName() const { return name; }
    inline int getChannel() const { return channel; }
    inline bool getInvertLogic() const { return invertLogic; }
    inline DeviceKey getDevice() const { return device; }
    inline bool getIsAlarm() const { return isAlarm; }
    inline IOType getElementType() const { return elementType; }

    friend inline bool operator==(const DigitalInput& l, const DigitalInput& r);
    friend inline bool operator<(const DigitalInput& l, const DigitalInput& r);

};

bool operator==(const DigitalInput& l, const DigitalInput& r) {
    return (l.device == r.device) && (l.channel == r.channel);
}

bool operator<(const DigitalInput& l, const DigitalInput& r) {
    return (l.device < r.device) || (
                (l.device == r.device) && (l.channel < r.channel));
}

}

#endif // DIGITALINPUT_HPP
