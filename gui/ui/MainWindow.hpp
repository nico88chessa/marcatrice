#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QScopedPointer>

#include "UnmovableWindow.hpp"

#include <galil/GalilPLCInspector.hpp>
#include <IOInspector.hpp>

#include <IOManager.hpp>
#include <MotionManager.hpp>
#include <AbstractDeviceConnectionWatcher.hpp>
#include <AbstractMotionInspector.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public UnmovableWindow {
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    QScopedPointer<PROGRAM_NAMESPACE::ErrorManager> errorManager;

    QScopedPointer<PROGRAM_NAMESPACE::AbstractMotionInspector> motionInspector;
    QScopedPointer<PROGRAM_NAMESPACE::IOInspector> ioInspector;
    QScopedPointer<PROGRAM_NAMESPACE::GalilPLCInspector> galilPLCInspector;

    QSharedPointer<PROGRAM_NAMESPACE::IOManager> ioManager;
    QSharedPointer<PROGRAM_NAMESPACE::MotionManager> motionManager;

    QSharedPointer<PROGRAM_NAMESPACE::IAbstractDevice> cn; // utilizzato da motionManager
    QSharedPointer<PROGRAM_NAMESPACE::IAbstractDevice> plc; // utilizzato da motionManager e ioManager
    QScopedPointer<PROGRAM_NAMESPACE::AbstractDeviceConnectionWatcher> cnConnectionWatcher;
    QScopedPointer<PROGRAM_NAMESPACE::AbstractDeviceConnectionWatcher> plcConnectionWatcher;

public:

private:
    void setupUi();
    void setupSignalsAndSlots() const;
    void setupUiPanels();
    void setupUiLeftPanel();
    void setupUiContentPanel();

    void initDevices();
    void initMotionInspector();
    void initGalilPLCInspector();
    void initIOInspector();
    void initCNConnectionWatcher();
    void initPLCConnectionWatcher();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

private slots:
    void setupStyleSheets() const;
    void startDevices();
    void stopDevices();

signals:
    void galilPLCStatusUpdateSignal(const PROGRAM_NAMESPACE::GalilPLCStatusBean status);
    void ioStatusUpdateSignal(const PROGRAM_NAMESPACE::DigitalInputStatus& digitalInputs,
                              const PROGRAM_NAMESPACE::DigitalOutputStatus& digitalOutputs,
                              const PROGRAM_NAMESPACE::AnalogInputStatus& analogInputs);
    void motionStatusUpdateSignal(const QVariant& status);

};

#endif // MAINWINDOW_HPP
