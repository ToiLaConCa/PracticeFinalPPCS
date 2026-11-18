// Họ và Tên: [Điền tên của bạn]
// MSSV: [Điền MSSV]
// ============================================================================
// DAY 01 - BÀI TẬP 1: KẾ THỪA VÀ CONSTRUCTOR CHAINING (SMART DEVICE)
// ============================================================================

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// ----------------------------------------------------------------------------
// 1. LỚP CƠ SỞ: SmartDevice
// ----------------------------------------------------------------------------
class SmartDevice {
protected:
    string id;
    string name;
    double powerWatts;
    bool isOn;

public:
    // TODO: Viết Constructor khởi tạo id, name, powerWatts; isOn mặc định = false
    SmartDevice(string id, string name, double powerWatts) {
        // TODO: Hoàn thành code khởi tạo ở đây
    }

    void togglePower() {
        // TODO: Đảo trạng thái isOn (bật thành tắt, tắt thành bật)
    }

    bool getIsOn() const {
        return isOn;
    }

    string getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    double getPowerWatts() const {
        return powerWatts;
    }

    void showBaseInfo() const {
        cout << "[Device] ID: " << id << " | Name: " << name
             << " | Power: " << powerWatts << "W | State: "
             << (isOn ? "ON" : "OFF") << endl;
    }
};

// ----------------------------------------------------------------------------
// 2. LỚP DẪN XUẤT 1: SmartLight kế thừa từ SmartDevice
// ----------------------------------------------------------------------------
class SmartLight : public SmartDevice {
private:
    int brightness; // Độ sáng: 0 -> 100 (%)
    string color;   // Màu sắc: "Warm White", "Daylight", "RGB"...

public:
    // TODO: Dùng Constructor Chaining gọi lại Constructor của SmartDevice
    // Khởi tạo thêm brightness (kiểm tra nếu < 0 thì = 0, nếu > 100 thì = 100) và color
    SmartLight(string id, string name, double power, int brightness, string color)
        : SmartDevice(id, name, power) {
        // TODO: Hoàn thành gán brightness và color
    }

    int getBrightness() const {
        return brightness;
    }

    string getColor() const {
        return color;
    }

    // Tăng/giảm độ sáng, đảm bảo luôn nằm trong khoảng [0, 100]
    void adjustBrightness(int delta) {
        // TODO: Viết logic điều chỉnh độ sáng
    }

    void displayDetails() const {
        showBaseInfo();
        cout << "   -> [Light] Brightness: " << brightness << "% | Color: " << color << endl;
    }
};

// ----------------------------------------------------------------------------
// 3. LỚP DẪN XUẤT 2: SmartThermostat kế thừa từ SmartDevice
// ----------------------------------------------------------------------------
class SmartThermostat : public SmartDevice {
private:
    double targetTemperature; // Nhiệt độ mục tiêu (độ C)
    string mode;              // "Cool", "Heat", "Eco"

public:
    // TODO: Viết Constructor Chaining
    SmartThermostat(string id, string name, double power, double targetTemp, string mode)
        : SmartDevice(id, name, power) {
        // TODO: Hoàn thành gán targetTemperature và mode
    }

    double getTargetTemperature() const {
        return targetTemperature;
    }

    string getMode() const {
        return mode;
    }

    void setTemperature(double newTemp) {
        // TODO: Chỉ cho phép nhiệt độ trong khoảng 16.0 đến 32.0 độ C
    }

    void setMode(string newMode) {
        // TODO: Chỉ chấp nhận "Cool", "Heat", "Eco"
    }

    void displayDetails() const {
        showBaseInfo();
        cout << "   -> [Thermostat] Target: " << targetTemperature << "°C | Mode: " << mode << endl;
    }
};

// ----------------------------------------------------------------------------
// HÀM KIỂM THỬ TỰ ĐỘNG (Bấm chạy để kiểm tra code của bạn)
// ----------------------------------------------------------------------------
int main() {
    cout << "=== KIỂM THỬ DAY 01 - BÀI 1 ===" << endl;

    // Test SmartLight
    SmartLight light("L01", "Living Room Lamp", 12.5, 80, "Warm White");
    assert(light.getId() == "L01");
    assert(light.getName() == "Living Room Lamp");
    assert(light.getBrightness() == 80);
    assert(light.getIsOn() == false);

    light.togglePower();
    assert(light.getIsOn() == true);

    light.adjustBrightness(30);  // 80 + 30 = 110 -> chặn ở 100
    assert(light.getBrightness() == 100);

    light.adjustBrightness(-150); // 100 - 150 = -50 -> chặn ở 0
    assert(light.getBrightness() == 0);

    // Test SmartThermostat
    SmartThermostat thermo("T01", "Central AC", 1500.0, 24.5, "Cool");
    assert(thermo.getTargetTemperature() == 24.5);
    assert(thermo.getMode() == "Cool");

    thermo.setTemperature(10.0); // Ngoài khoảng [16, 32] -> không đổi
    assert(thermo.getTargetTemperature() == 24.5);

    thermo.setTemperature(26.0); // Hợp lệ
    assert(thermo.getTargetTemperature() == 26.0);

    cout << "\n✅ CHÚC MỪNG: BẠN ĐÃ VƯỢT QUA TOÀN BỘ TEST CASES BÀI 1!" << endl;
    return 0;
}
