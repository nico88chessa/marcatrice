#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QSettings>
#include <QString>
#include <QMap>

#include <configure.h>
#include <Constants.hpp>
#include <Logger.hpp>
#include <data/DigitalInput.hpp>
#include <data/DigitalOutput.hpp>
#include <data/AnalogInput.hpp>
#include <Utils.hpp>

namespace PROGRAM_NAMESPACE {


class Settings {
public:
    using Ptr = Settings*;
    using ConstPtr = const Settings*;

private:
    static constexpr char ARRAY_DIGITAL_INPUT[] = "DigitalInput";
    static constexpr char ARRAY_DIGITAL_OUTPUT[] = "DigitalOutput";
    static constexpr char ARRAY_ANALOG_INPUT[] = "AnalogInput";

private:
    Settings();
    ~Settings() { }

    void loadValuesFromFile();
    void writeValuesToFile();
    bool validateDigitalInput(const DigitalInput& i) const;
    bool validateDigitalOutput(const DigitalOutput& i) const;
    bool validateAnalogInput(const AnalogInput& i) const;

public:
    Settings(const Settings&) = delete;
    void operator=(const Settings&) = delete;
    void operator=(Settings&&) = delete;

    bool validateSettings() const;

    static Settings& instance();

    int getAxisXStepPerMm() const { return axisXStepPerMm; }
    int getAxisXMinPosMm() const { return axisXMinPosMm; }
    int getAxisXMaxPosMm() const { return axisXMaxPosMm; }
    real getAxisXBaseOffsetMm() const { return axisXBaseOffsetMm; }
    real getAxisXManualSpeedMms() const { return axisXManualSpeedMms; }
    real getAxisXManualAccMms2() const { return axisXManualAccMms2; }
    real getAxisXManualDecMms2() const { return axisXManualDecMms2; }
    real getAxisXOperativeSpeedMms() const { return axisXOperativeSpeedMms; }
    real getAxisXOperativeAccMms2() const { return axisXOperativeAccMms2; }
    real getAxisXOperativeDecMms2() const { return axisXOperativeDecMms2; }
    int getAxisYStepPerMm() const { return axisYStepPerMm; }
    int getAxisYMinPosMm() const { return axisYMinPosMm; }
    int getAxisYMaxPosMm() const { return axisYMaxPosMm; }
    real getAxisYBaseOffsetMm() const { return axisYBaseOffsetMm; }
    real getAxisYManualSpeedMms() const { return axisYManualSpeedMms; }
    real getAxisYManualAccMms2() const { return axisYManualAccMms2; }
    real getAxisYManualDecMms2() const { return axisYManualDecMms2; }
    real getAxisYOperativeSpeedMms() const { return axisYOperativeSpeedMms; }
    real getAxisYOperativeAccMms2() const { return axisYOperativeAccMms2; }
    real getAxisYOperativeDecMms2() const { return axisYOperativeDecMms2; }
    int getAxisZStepPerMm() const { return axisZStepPerMm; }
    int getAxisZMinPosMm() const { return axisZMinPosMm; }
    int getAxisZMaxPosMm() const { return axisZMaxPosMm; }
    real getAxisZBaseOffsetMm() const { return axisZBaseOffsetMm; }
    real getAxisZManualSpeedMms() const { return axisZManualSpeedMms; }
    real getAxisZManualAccMms2() const { return axisZManualAccMms2; }
    real getAxisZManualDecMms2() const { return axisZManualDecMms2; }
    real getAxisZOperativeSpeedMms() const { return axisZOperativeSpeedMms; }
    real getAxisZOperativeAccMms2() const { return axisZOperativeAccMms2; }
    real getAxisZOperativeDecMms2() const { return axisZOperativeDecMms2; }

    const QMap<IOType, DigitalInput>& getDigitalInputs() const { return digitalInputs; }
    const QMap<IOType, DigitalOutput>& getDigitalOutputs() const { return digitalOutputs; }
    const QMap<IOType, AnalogInput>& getAnalogInputs() const { return analogInputs; }

    int getGalilCNConnectionTimeoutMs() const { return galilCNConnectionTimeoutMs; }
    int getGalilCNStatusRefreshIntervalMs() const { return galilCNStatusRefreshIntervalMs; }
    int getGalilCNCheckConnectionIntervalMs() const { return galilCNCheckConnectionIntervalMs; }
    QString getGalilCNIpAddress() const { return galilCNIpAddress; }
    int getGalilPLCConnectionTimeoutMs() const { return galilPLCConnectionTimeoutMs; }
    int getGalilPLCStatusRefreshIntervalMs() const { return galilPLCStatusRefreshIntervalMs; }
    int getGalilPLCCheckConnectionIntervalMs() const { return galilPLCCheckConnectionIntervalMs; }
    QString getGalilPLCIpAddress() const { return galilPLCIpAddress; }

    DeviceKey getMachineCNType() const { return machineCNType; }
    DeviceKey getMachinePLCType() const { return machinePLCType; }
    int getMachineIORefreshIntervalMs() const { return machineIORefreshIntervalMs; }



private:
    // ASSE X
    int axisXStepPerMm;
    int axisXMinPosMm;
    int axisXMaxPosMm;
    real axisXBaseOffsetMm;
    real axisXManualSpeedMms;
    real axisXManualAccMms2;
    real axisXManualDecMms2;
    real axisXOperativeSpeedMms;
    real axisXOperativeAccMms2;
    real axisXOperativeDecMms2;

    // ASSE Y
    int axisYStepPerMm;
    int axisYMinPosMm;
    int axisYMaxPosMm;
    real axisYBaseOffsetMm;
    real axisYManualSpeedMms;
    real axisYManualAccMms2;
    real axisYManualDecMms2;
    real axisYOperativeSpeedMms;
    real axisYOperativeAccMms2;
    real axisYOperativeDecMms2;

    // ASSE Z
    int axisZStepPerMm;
    int axisZMinPosMm;
    int axisZMaxPosMm;
    real axisZBaseOffsetMm;
    real axisZManualSpeedMms;
    real axisZManualAccMms2;
    real axisZManualDecMms2;
    real axisZOperativeSpeedMms;
    real axisZOperativeAccMms2;
    real axisZOperativeDecMms2;

    // IO
    QMap<IOType, DigitalInput> digitalInputs;
    QMap<IOType, DigitalOutput> digitalOutputs;
    QMap<IOType, AnalogInput> analogInputs;

    // MACHINE
    DeviceKey machineCNType;
    DeviceKey machinePLCType;
    int machineIORefreshIntervalMs;

    // GALIL CN PARAMETERS
    int galilCNConnectionTimeoutMs;
    int galilCNStatusRefreshIntervalMs;
    int galilCNCheckConnectionIntervalMs;
    QString galilCNIpAddress;

    // GALIL PLC PARAMETERS
    int galilPLCConnectionTimeoutMs;
    int galilPLCStatusRefreshIntervalMs;
    int galilPLCCheckConnectionIntervalMs;
    QString galilPLCIpAddress;

};

}

#endif // SETTINGS_HPP
