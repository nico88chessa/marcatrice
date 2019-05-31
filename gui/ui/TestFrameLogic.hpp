#ifndef TESTFRAMELOGIC_HPP
#define TESTFRAMELOGIC_HPP

#include <QObject>

#include <MotionManager.hpp>
#include <IOManager.hpp>
#include <laser-ipg-temporary/communication/ipg_sync_interface.hpp>

class TestFrame;

class TestFrameLogic : public QObject {
    Q_OBJECT

    friend class TestFrame;

public:
    using Ptr = TestFrameLogic *;
    using ConstPtr = const TestFrameLogic *;

private:
    TestFrame* qPtr;
    QSharedPointer<PROGRAM_NAMESPACE::MotionManager> motionManager;
    QSharedPointer<PROGRAM_NAMESPACE::IOManager> ioManager;
    QSharedPointer<ipg::IpgSyncInterface> ipgInterface;

    bool isProcessStopped;
    bool isLaserInitialized;

public:
    TestFrameLogic();
    ~TestFrameLogic();

    void setupMotionManager(const QSharedPointer<mibdv::MotionManager>& motionManager);
    void setupIOManager(const QSharedPointer<mibdv::IOManager>& ioManager);
    void setupLaserIpgYLPN(const QSharedPointer<ipg::IpgSyncInterface>& ipgInterface);

private:
    bool setupLaserOn();
    bool setupLaserOff();
    bool getPulseEnergy(float& energyJoule);

private slots:
    void startProcess();
    void stopProcess();

    void changeGuideLaserState();

    // WARNING NIC 03/04/2019 - inizio gestione temporanea laser YLPN (da rifare)
    void initIpgYLPNLaser();

signals:
    // WARNING NIC 03/04/2019 - inizio gestione temporanea laser YLPN (da rifare)
    void laserIpgYLPNinitializedSignal();

};

#endif // TESTFRAMELOGIC_HPP
