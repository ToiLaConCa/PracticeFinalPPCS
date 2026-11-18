// Họ và Tên: [Điền tên của bạn]
// MSSV: [Điền MSSV]
// ============================================================================
// DAY 03 - BÀI TẬP 2: CON TRỎ VÀ THAM CHIẾU NÂNG CAO (POINTERS & REFERENCES)
// ============================================================================

#include <iostream>
#include <cassert>

using namespace std;

// ----------------------------------------------------------------------------
// 1. Hoán vị hai số nguyên bằng THAM CHIẾU (Pass by Reference)
// ----------------------------------------------------------------------------
void swapByRef(int& x, int& y) {
    // TODO: Hoán vị x và y
}

// ----------------------------------------------------------------------------
// 2. Hoán vị hai số nguyên bằng CON TRỎ (Pass by Pointer)
// Bắt buộc kiểm tra nếu px == nullptr hoặc py == nullptr thì không làm gì
// ----------------------------------------------------------------------------
void swapByPtr(int* px, int* py) {
    // TODO: Hoán vị giá trị mà px và py trỏ tới
}

// ----------------------------------------------------------------------------
// 3. Tìm con trỏ trỏ tới phần tử nhỏ nhất và lớn nhất trong mảng
// Ghi kết quả vào hai con trỏ pMin và pMax được truyền theo THAM CHIẾU CON TRỎ (int*&)
// ----------------------------------------------------------------------------
void findMinMaxPointers(int a[], int n, int*& pMin, int*& pMax) {
    if (n <= 0) {
        pMin = nullptr;
        pMax = nullptr;
        return;
    }
    // TODO: Gán pMin = &a[0], pMax = &a[0]
    // Duyệt từ 1 đến n - 1:
    // Nếu a[i] < *pMin -> pMin = &a[i]
    // Nếu a[i] > *pMax -> pMax = &a[i]
}

// ----------------------------------------------------------------------------
// HÀM KIỂM THỬ TỰ ĐỘNG
// ----------------------------------------------------------------------------
int main() {
    cout << "=== KIỂM THỬ DAY 03 - BÀI 2 ===" << endl;

    // Test 1: Swap by Reference
    int a = 10, b = 20;
    swapByRef(a, b);
    assert(a == 20 && b == 10);

    // Test 2: Swap by Pointer
    int x = 99, y = 100;
    swapByPtr(&x, &y);
    assert(x == 100 && y == 99);

    // Thử truyền nullptr (không được crash)
    swapByPtr(nullptr, &y);
    assert(y == 99);

    // Test 3: Find Min/Max Pointers
    int numbers[6] = { 45, 12, 89, 5, 67, 33 };
    int* pMin = nullptr;
    int* pMax = nullptr;

    findMinMaxPointers(numbers, 6, pMin, pMax);
    assert(pMin != nullptr && *pMin == 5);
    assert(pMax != nullptr && *pMax == 89);
    assert(pMin == &numbers[3]); // Kiểm tra chính xác địa chỉ trong mảng
    assert(pMax == &numbers[2]);

    cout << "\n✅ CHÚC MỪNG: BẠN ĐÃ VƯỢT QUA TOÀN BỘ TEST CASES BÀI 2!" << endl;
    return 0;
}
