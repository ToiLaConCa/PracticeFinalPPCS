# 📌 DAY 01: KẾ THỪA (INHERITANCE) & CONSTRUCTOR CHAINING

> **Mục tiêu:** Nắm chắc cú pháp kế thừa `public`, cơ chế Constructor Chaining và phân biệt 3 mức truy cập (`private`, `protected`, `public`).  
> **Thời gian dự kiến:** 45 - 60 phút.

---

## ⚡ Tóm Tắt Lý Thuyết Cốt Lõi (Đọc trong 3 phút)

### 1. Phân biệt 3 quyền truy cập
- `private`: Chỉ nội bộ lớp đó dùng. Lớp con **không** chạm được trực tiếp.
- `protected`: Lớp cha và các lớp con **kế thừa** dùng thoải mái. Bên ngoài (`main`) không gọi được. *(Mẹo thi: Thuộc tính lớp cha luôn để `protected`)*.
- `public`: Ai cũng truy cập được.

### 2. Cú pháp kế thừa & Constructor Chaining
Khi khởi tạo đối tượng lớp con, lớp cha **bắt buộc** phải được khởi tạo trước. Ta dùng dấu hai chấm `:` để gọi constructor của cha:

```cpp
class Cha {
protected:
    string id;
    string ten;
public:
    Cha(string id, string ten) : id(id), ten(ten) {}
};

class Con : public Cha {
private:
    int giaTri;
public:
    // Constructor Chaining: Gọi Cha(id, ten) trước, rồi mới gán giaTri
    Con(string id, string ten, int gv) : Cha(id, ten), giaTri(gv) {}
};
```

---

## 📝 Danh Sách Bài Tập Ngày 1

### Bài 1: Quản Lý Thiết Bị Nhà Thông Minh (`Bai1_SmartHome_Device.cpp`)
- **Lớp cơ sở `SmartDevice`:**
  - Thuộc tính `protected`: `id` (string), `name` (string), `powerWatts` (double), `isOn` (bool).
  - Constructor đầy đủ 3 tham số (mặc định `isOn = false`).
  - Phương thức: `togglePower()`, `showBaseInfo()`, getter/setter.
- **Lớp con `SmartLight` kế thừa `SmartDevice`:**
  - Thuộc tính riêng: `brightness` (int từ 0 - 100), `color` (string).
  - Constructor Chaining khởi tạo đầy đủ.
  - Phương thức: `adjustBrightness(int delta)`, `displayDetails()`.
- **Lớp con `SmartThermostat` kế thừa `SmartDevice`:**
  - Thuộc tính riêng: `targetTemperature` (double), `mode` (string: "Cool", "Heat", "Eco").
  - Constructor Chaining khởi tạo đầy đủ.
  - Phương thức: `setTemperature(double temp)`, `displayDetails()`.

### Bài 2: Đội Xe Vận Tải (`Bai2_Vehicle_Fleet.cpp`)
- **Lớp cơ sở `Vehicle`:**
  - Thuộc tính `protected`: `model` (string), `brand` (string), `batteryCapacity` (double), `currentBattery` (double).
  - Constructor Chaining, phương thức `consumeBattery(double amount)`, `chargeBattery(double amount)`.
- **Lớp con `ElectricCar` kế thừa `Vehicle`:**
  - Thuộc tính riêng: `passengerSeats` (int), `hasAutopilot` (bool).
  - Phương thức: `drive(double distanceKm)` (tính lượng pin tiêu hao dựa trên số ghế và quãng đường).

---

## 🎯 Tiêu Chí Chấm Điểm
1. Khai báo đúng `protected` cho thuộc tính lớp cha. (2đ)
2. Viết đúng cú pháp Constructor Chaining gọi constructor của lớp cha. (3đ)
3. Cập nhật trạng thái và validate dữ liệu hợp lệ (ví dụ pin không vượt quá 100%, nhiệt độ không âm...). (3đ)
4. Chạy vượt qua toàn bộ assertions trong hàm `main()`. (2đ)
