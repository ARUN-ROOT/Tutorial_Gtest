#ifndef DRIVEALERTSERVICE_H
#define DRIVEALERTSERVICE_H

class DriveAlertService {
public:
    static DriveAlertService& getInstance() {
        static DriveAlertService instance;
        return instance;
    }

    static void setInstance(DriveAlertService* instance) {
        getInstance().instance_ = instance;
    }

    static void resetInstance() {
        getInstance().instance_ = nullptr;
    }

    virtual double getLatitude() {
        if (instance_) {
            return instance_->getLatitude();
        }
        return latitude_;
    }

    virtual double getLongitude() {
        if (instance_) {
            return instance_->getLongitude();
        }
        return longitude_;
    }

protected:
    DriveAlertService() : instance_(nullptr), latitude_(0.0), longitude_(0.0) {}
    virtual ~DriveAlertService() = default;

private:
    DriveAlertService* instance_;
    double latitude_;
    double longitude_;
};

#endif // DRIVEALERTSERVICE_H
