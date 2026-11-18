// Họ và Tên: [Điền tên của bạn]
// MSSV: [Điền MSSV]
// ============================================================================
// DAY 02 - BÀI TẬP 1: LỚP TRỪU TƯỢNG VÀ TÍNH ĐA HÌNH (EMPLOYEE PAYROLL)
// ============================================================================

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// ----------------------------------------------------------------------------
// 1. LỚP TRỪU TƯỢNG: Employee
// ----------------------------------------------------------------------------
class Employee {
protected:
    string id;
    string name;
    double baseRate; // Mức lương cơ bản

public:
    Employee(string id, string name, double rate) : id(id), name(name), baseRate(rate) {}

    // BẮT BUỘC: Virtual Destructor để thu hồi bộ nhớ an toàn
    virtual ~Employee() {}

    string getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    // TODO: Khai báo hàm thuần ảo (Pure Virtual) tính lương
    // virtual double calculateSalary() const = 0;
    virtual double calculateSalary() const = 0;

    // Hàm ảo hiển thị thông tin
    virtual void printDetails() const {
        cout << "[NV] ID: " << id << " | Ten: " << name
             << " | Luong thuc nhan: " << calculateSalary() << " VND" << endl;
    }
};

// ----------------------------------------------------------------------------
// 2. LỚP CON 1: FullTimeEmployee (Nhân viên toàn thời gian)
// ----------------------------------------------------------------------------
class FullTimeEmployee : public Employee {
private:
    double monthlyBonus; // Thưởng tháng cố định

public:
    // TODO: Viết Constructor Chaining
    FullTimeEmployee(string id, string name, double baseRate, double bonus)
        : Employee(id, name, baseRate), monthlyBonus(bonus) {}

    // TODO: Override hàm calculateSalary()
    // Công thức: Luong = (baseRate * 1.5) + monthlyBonus
    double calculateSalary() const override {
        // TODO: Hoàn thành tính lương
        return 0.0;
    }
};

// ----------------------------------------------------------------------------
// 3. LỚP CON 2: PartTimeEmployee (Nhân viên bán thời gian)
// ----------------------------------------------------------------------------
class PartTimeEmployee : public Employee {
private:
    int hoursWorked; // Số giờ làm việc trong tháng

public:
    // TODO: Viết Constructor Chaining
    PartTimeEmployee(string id, string name, double hourlyRate, int hours)
        : Employee(id, name, hourlyRate), hoursWorked(hours) {}

    // TODO: Override hàm calculateSalary()
    // Công thức: Luong = baseRate * hoursWorked
    double calculateSalary() const override {
        // TODO: Hoàn thành tính lương
        return 0.0;
    }
};

// ----------------------------------------------------------------------------
// 4. HÀM QUẢN LÝ ĐA HÌNH
// ----------------------------------------------------------------------------
// Tính tổng quỹ lương của toàn bộ nhân viên trong công ty thông qua mảng con trỏ Employee*
double calculateTotalPayroll(Employee* list[], int n) {
    double total = 0.0;
    // TODO: Duyệt qua từng con trỏ trong mảng và cộng dồn calculateSalary()
    return total;
}

// ----------------------------------------------------------------------------
// HÀM KIỂM THỬ TỰ ĐỘNG
// ----------------------------------------------------------------------------
int main() {
    cout << "=== KIỂM THỬ DAY 02 - BÀI 1 ===" << endl;

    // Khởi tạo các đối tượng thông qua con trỏ lớp cơ sở
    Employee* nv1 = new FullTimeEmployee("FT01", "Nguyen Van A", 10000000.0, 2000000.0);
    // Luong = (10,000,000 * 1.5) + 2,000,000 = 17,000,000
    assert(nv1->calculateSalary() == 17000000.0);

    Employee* nv2 = new PartTimeEmployee("PT01", "Tran Thi B", 50000.0, 120);
    // Luong = 50,000 * 120 = 6,000,000
    assert(nv2->calculateSalary() == 6000000.0);

    Employee* danhSach[2] = { nv1, nv2 };
    double tongLuong = calculateTotalPayroll(danhSach, 2);
    // Tong = 17,000,000 + 6,000,000 = 23,000,000
    assert(tongLuong == 23000000.0);

    // Giải phóng bộ nhớ ảo an toàn
    delete nv1;
    delete nv2;

    cout << "\n✅ CHÚC MỪNG: BẠN ĐÃ VƯỢT QUA TOÀN BỘ TEST CASES BÀI 1!" << endl;
    return 0;
}
