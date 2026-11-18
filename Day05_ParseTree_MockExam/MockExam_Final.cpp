// Họ và Tên: [Điền tên của bạn]
// MSSV: [Điền MSSV]
// ============================================================================
// DAY 05 - ĐỀ THI THỬ TỔNG HỢP MÔN PPCS (THỜI GIAN: 60 PHÚT)
// ============================================================================
// Đề bài: Xây dựng hệ thống quản lý khóa học đại học (Course Management System)
// áp dụng Kế thừa, Đa hình, Con trỏ và Hàm xử lý mảng.
// ============================================================================

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// ----------------------------------------------------------------------------
// PHẦN 1: THIẾT KẾ HỆ THỐNG CLASS (OOP & POLYMORPHISM) - (6.0 điểm)
// ----------------------------------------------------------------------------

// 1. Lớp trừu tượng Course
class Course {
protected:
    string courseId;
    string courseName;
    int credits;           // Số tín chỉ
    double baseFeePerCredit; // Học phí cơ bản mỗi tín chỉ

public:
    Course(string id, string name, int credits, double baseFee)
        : courseId(id), courseName(name), credits(credits), baseFeePerCredit(baseFee) {}

    virtual ~Course() {}

    string getCourseId() const { return courseId; }
    string getCourseName() const { return courseName; }
    int getCredits() const { return credits; }

    // TODO: Khai báo hàm thuần ảo tính học phí thực tế
    virtual double calculateTuition() const = 0;

    // TODO: Hàm ảo kiểm tra xem khóa học có phải là trực tuyến không
    virtual bool isOnline() const {
        return false;
    }
};

// 2. Lớp OnlineCourse kế thừa Course
class OnlineCourse : public Course {
private:
    string platform;        // "Zoom", "Coursera", "Teams"...
    double techSupportFee;  // Phí hỗ trợ nền tảng công nghệ

public:
    // TODO: Constructor Chaining
    OnlineCourse(string id, string name, int credits, double baseFee, string platform, double techFee)
        : Course(id, name, credits, baseFee), platform(platform), techSupportFee(techFee) {}

    bool isOnline() const override {
        return true;
    }

    // Học phí Online = (credits * baseFeePerCredit * 0.9) + techSupportFee
    // (Được giảm 10% học phí tín chỉ do học từ xa)
    double calculateTuition() const override {
        // TODO: Hoàn thành tính học phí
        return 0.0;
    }
};

// 3. Lớp InPersonCourse (Học trực tiếp trên giảng đường) kế thừa Course
class InPersonCourse : public Course {
private:
    string roomNumber;      // Phòng học (VD: "B4-302")
    double labFacilityFee;  // Phí phòng thí nghiệm / thiết bị

public:
    // TODO: Constructor Chaining
    InPersonCourse(string id, string name, int credits, double baseFee, string room, double labFee)
        : Course(id, name, credits, baseFee), roomNumber(room), labFacilityFee(labFee) {}

    // Học phí Trực tiếp = (credits * baseFeePerCredit) + labFacilityFee
    double calculateTuition() const override {
        // TODO: Hoàn thành tính học phí
        return 0.0;
    }
};

// ----------------------------------------------------------------------------
// PHẦN 2: CÁC HÀM XỬ LÝ MẢNG CON TRỎ ĐA HÌNH (FUNCTIONS & POINTERS) - (4.0 điểm)
// ----------------------------------------------------------------------------

// 1. Tính tổng học phí của tất cả khóa học trong danh sách
double calculateTotalTuition(Course* courses[], int n) {
    double total = 0.0;
    // TODO: Duyệt qua mảng con trỏ và tính tổng calculateTuition()
    return total;
}

// 2. Đếm số lượng khóa học trực tuyến (Online)
int countOnlineCourses(Course* courses[], int n) {
    int count = 0;
    // TODO: Đếm số lượng khóa học có isOnline() == true
    return count;
}

// 3. Tìm con trỏ trỏ tới khóa học có học phí cao nhất
Course* findMostExpensiveCourse(Course* courses[], int n) {
    if (n <= 0) return nullptr;
    // TODO: Tìm và trả về con trỏ Course* có calculateTuition() lớn nhất
    return nullptr;
}

// ----------------------------------------------------------------------------
// HÀM KIỂM THỬ TỰ ĐỘNG CỦA ĐỀ THI
// ----------------------------------------------------------------------------
int main() {
    cout << "=== BẮT ĐẦU CHẤM ĐỀ THI THỬ PPCS FINAL ===" << endl;

    // Tạo danh sách các khóa học
    // Course 1: Online - 3 tín chỉ, 500,000/tín chỉ, nền tảng Teams, phí tech 100,000
    // Học phí = (3 * 500,000 * 0.9) + 100,000 = 1,350,000 + 100,000 = 1,450,000
    Course* c1 = new OnlineCourse("CS101", "Lap Trinh Huong Doi Tuong", 3, 500000.0, "Teams", 100000.0);
    assert(c1->calculateTuition() == 1450000.0);
    assert(c1->isOnline() == true);

    // Course 2: InPerson - 4 tín chỉ, 500,000/tín chỉ, phòng B4-302, phí lab 400,000
    // Học phí = (4 * 500,000) + 400,000 = 2,000,000 + 400,000 = 2,400,000
    Course* c2 = new InPersonCourse("CS102", "Cau Truc Du Lieu", 4, 500000.0, "B4-302", 400000.0);
    assert(c2->calculateTuition() == 2400000.0);
    assert(c2->isOnline() == false);

    // Course 3: Online - 2 tín chỉ, 600,000/tín chỉ, nền tảng Coursera, phí tech 50,000
    // Học phí = (2 * 600,000 * 0.9) + 50,000 = 1,080,000 + 50,000 = 1,130,000
    Course* c3 = new OnlineCourse("CS103", "Nguyen Ly He Dieu Hanh", 2, 600000.0, "Coursera", 50000.0);
    assert(c3->calculateTuition() == 1130000.0);

    Course* danhSach[3] = { c1, c2, c3 };

    // Kiểm tra tổng học phí: 1,450,000 + 2,400,000 + 1,130,000 = 4,980,000
    assert(calculateTotalTuition(danhSach, 3) == 4980000.0);

    // Kiểm tra đếm số khóa online: c1, c3 -> 2
    assert(countOnlineCourses(danhSach, 3) == 2);

    // Kiểm tra khóa học đắt nhất: c2 (2,400,000)
    Course* maxCourse = findMostExpensiveCourse(danhSach, 3);
    assert(maxCourse == c2);
    assert(maxCourse->getCourseId() == "CS102");

    // Dọn dẹp bộ nhớ
    delete c1;
    delete c2;
    delete c3;

    cout << "\n🎉 XUẤT SẮC: BẠN ĐÃ VƯỢT QUA 100% ĐỀ THI THỬ FINAL VỚI ĐIỂM SỐ 10/10!" << endl;
    return 0;
}
