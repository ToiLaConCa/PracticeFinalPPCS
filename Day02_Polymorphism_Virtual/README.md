# 📌 DAY 02: ĐA HÌNH (POLYMORPHISM) & HÀM ẢO (VIRTUAL FUNCTIONS)

> **Mục tiêu:** Nắm vững từ khóa `virtual`, `override`, Virtual Destructor, hàm thuần ảo (Pure Virtual Function) và quản lý đa hình qua mảng con trỏ cơ sở `Base* arr[]`.  
> **Thời gian dự kiến:** 45 - 60 phút.

---

## ⚡ Tóm Tắt Lý Thuyết Cốt Lõi (Đọc trong 3 phút)

### 1. Tại sao phải có `virtual`?
Nếu không có `virtual`, C++ sẽ thực hiện **Early Binding (Liên kết tĩnh)**: khi gọi phương thức thông qua con trỏ lớp cha `Base* p = new Derived();`, C++ sẽ gọi hàm của lớp `Base` thay vì của lớp `Derived`!
Thêm `virtual` giúp C++ kích hoạt **Late Binding (Liên kết động)** qua bảng ảo `vtable`, gọi đúng hàm của lớp con tại thời điểm chạy (Runtime).

### 2. Từ khóa `override`
Đặt ở cuối khai báo hàm trong lớp con:
```cpp
class Cha {
public:
    virtual void sayHello() { cout << "Hello Cha"; }
    virtual ~Cha() {} // BẮT BUỘC có virtual destructor khi có hàm ảo!
};

class Con : public Cha {
public:
    void sayHello() override { cout << "Hello Con"; }
};
```
> [!IMPORTANT]
> **Bắt buộc nhớ khi đi thi:** Khi lớp cha có hàm `virtual`, destructor của lớp cha **bắt buộc** phải là `virtual ~Cha() {}` để tránh rò rỉ bộ nhớ khi `delete` con trỏ cha.

### 3. Hàm thuần ảo (Pure Virtual Function) & Lớp trừu tượng (Abstract Class)
```cpp
virtual double calculateSalary() = 0; // = 0 biến hàm thành thuần ảo
```
Lớp có ít nhất 1 hàm thuần ảo là **Lớp trừu tượng**, không thể khởi tạo trực tiếp đối tượng (`Employee e;` sẽ báo lỗi).

---

## 📝 Danh Sách Bài Tập Ngày 2

### Bài 1: Hệ Thống Tính Lương Đa Hình (`Bai1_Employee_Payroll.cpp`)
- **Lớp trừu tượng `Employee`:**
  - Thuộc tính `protected`: `id`, `name`, `baseRate`.
  - Hàm ảo thuần túy: `virtual double calculateSalary() const = 0;`.
  - Hàm ảo in thông tin: `virtual void printSlip() const;`.
  - Virtual Destructor: `virtual ~Employee() {}`.
- **Lớp con `FullTimeEmployee`:** Lương = `baseRate * 1.5` + `bonus`.
- **Lớp con `PartTimeEmployee`:** Lương = `baseRate * hoursWorked`.
- **Hàm quản lý:** `double calculateTotalPayroll(Employee* list[], int n)`.

### Bài 2: Hệ Thống Nhân Vật RPG (`Bai2_Game_Character.cpp`)
- **Lớp cơ sở `Character`:**
  - Thuộc tính `protected`: `name`, `hp`, `maxHp`.
  - Hàm ảo: `virtual void attack(Character& target) = 0;`, `virtual void takeDamage(int dmg);`.
- **Lớp `Warrior`:** Tấn công vật lý, có giáp giảm sát thương.
- **Lớp `Mage`:** Dùng năng lượng MP để tung phép thuật, nếu hết MP thì tấn công cơ bản.

---

## 🎯 Tiêu Chí Chấm Điểm
1. Khai báo đúng `virtual` và `virtual ~Destructor()`. (2đ)
2. Lớp con sử dụng từ khóa `override`. (2đ)
3. Cài đặt đúng thuật toán tính toán của từng lớp con. (3đ)
4. Mảng con trỏ duyệt gọi đúng hàm đa hình mà không ép kiểu thủ công. (3đ)
