// Họ và Tên: [Điền tên của bạn]
// MSSV: [Điền MSSV]
// ============================================================================
// DAY 01 - BÀI TẬP 2: KẾ THỪA VÀ KIỂM SOÁT THUỘC TÍNH (VEHICLE -> ELECTRIC CAR)
// ============================================================================

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// ----------------------------------------------------------------------------
// 1. LỚP CƠ SỞ: Vehicle
// ----------------------------------------------------------------------------
class Vehicle {
protected:
    string vin;             // Mã định danh xe
    string brand;           // Hãng sản xuất
    double batteryCapacity; // Dung lượng tối đa (kWh)
    double currentBattery;  // Mức pin hiện tại (kWh)

public:
    // TODO: Constructor khởi tạo 4 thuộc tính.
    // Nếu currentBattery > batteryCapacity thì gán currentBattery = batteryCapacity
    Vehicle(string vin, string brand, double capacity, double initialBattery) {
        // TODO: Hoàn thành code khởi tạo
    }

    string getVin() const {
        return vin;
    }

    string getBrand() const {
        return brand;
    }

    double getBatteryCapacity() const {
        return batteryCapacity;
    }

    double getCurrentBattery() const {
        return currentBattery;
    }

    // Nạp pin: Tăng lượng pin, tối đa bằng batteryCapacity
    void charge(double kWh) {
        // TODO: Viết hàm nạp pin
    }

    // Tiêu hao pin: Trừ lượng pin, tối thiểu bằng 0
    bool consumeBattery(double kWh) {
        // TODO: Nếu currentBattery >= kWh thì trừ và trả về true, ngược lại trả về false
        return false;
    }

    double getBatteryPercentage() const {
        return (batteryCapacity > 0) ? (currentBattery / batteryCapacity) * 100.0 : 0.0;
    }
};

// ----------------------------------------------------------------------------
// 2. LỚP DẪN XUẤT: ElectricCar kế thừa từ Vehicle
// ----------------------------------------------------------------------------
class ElectricCar : public Vehicle {
private:
    int passengerSeats;
    bool autopilotEnabled;

public:
    // TODO: Dùng Constructor Chaining để chuyển tiếp tham số cho lớp Vehicle
    ElectricCar(string vin, string brand, double capacity, double initialBattery, int seats, bool autopilot)
        : Vehicle(vin, brand, capacity, initialBattery) {
        // TODO: Gán passengerSeats và autopilotEnabled
    }

    int getPassengerSeats() const {
        return passengerSeats;
    }

    bool isAutopilotEnabled() const {
        return autopilotEnabled;
    }

    void toggleAutopilot() {
        autopilotEnabled = !autopilotEnabled;
    }

    // Lái xe một quãng đường:
    // Mức tiêu hao năng lượng cơ bản: 0.15 kWh cho mỗi 1 km.
    // Nếu bật autopilot: tiêu hao thêm 0.02 kWh mỗi km (tổng cộng 0.17 kWh/km).
    // Trả về true nếu đủ pin để đi hết quãng đường, ngược lại trả về false và không trừ pin.
    bool drive(double distanceKm) {
        // TODO: Tính toán lượng pin cần dùng và gọi consumeBattery()
        return false;
    }
};

// ----------------------------------------------------------------------------
// HÀM KIỂM THỬ TỰ ĐỘNG
// ----------------------------------------------------------------------------
int main() {
    cout << "=== KIỂM THỬ DAY 01 - BÀI 2 ===" << endl;

    ElectricCar car("VIN999", "Tesla", 75.0, 50.0, 5, false);
    assert(car.getVin() == "VIN999");
    assert(car.getBrand() == "Tesla");
    assert(car.getBatteryCapacity() == 75.0);
    assert(car.getCurrentBattery() == 50.0);
    assert(car.getPassengerSeats() == 5);
    assert(car.isAutopilotEnabled() == false);

    // Thử sạc pin
    car.charge(30.0); // 50 + 30 = 80 -> chỉ nhận tối đa 75.0
    assert(car.getCurrentBattery() == 75.0);

    // Chạy xe 100 km (tốn 100 * 0.15 = 15.0 kWh)
    bool ok1 = car.drive(100.0);
    assert(ok1 == true);
    assert(car.getCurrentBattery() == 60.0);

    // Bật Autopilot và chạy 200 km (tốn 200 * 0.17 = 34.0 kWh)
    car.toggleAutopilot();
    assert(car.isAutopilotEnabled() == true);
    bool ok2 = car.drive(200.0);
    assert(ok2 == true);
    assert(car.getCurrentBattery() == 26.0);

    // Thử chạy quãng đường quá dài (200 km tốn 34 kWh > 26 kWh hiện có)
    bool ok3 = car.drive(200.0);
    assert(ok3 == false);
    assert(car.getCurrentBattery() == 26.0); // Không bị trừ pin khi không đủ

    cout << "\n✅ CHÚC MỪNG: BẠN ĐÃ VƯỢT QUA TOÀN BỘ TEST CASES BÀI 2!" << endl;
    return 0;
}
