// Họ và Tên: [Điền tên của bạn]
// MSSV: [Điền MSSV]
// ============================================================================
// DAY 03 - BÀI TẬP 1: THAO TÁC MẢNG VÀ THAM CHIẾU (ARRAY FILTER & TRANSFORM)
// ============================================================================

#include <iostream>
#include <cassert>

using namespace std;

// ----------------------------------------------------------------------------
// 1. Đếm các phần tử là số lẻ nằm ở vị trí chỉ số chẵn (index 0, 2, 4...)
// Ví dụ: mảng [3, 4, 7, 8, 2] -> index 0 (3: lẻ), index 2 (7: lẻ), index 4 (2: chẵn) -> Kết quả: 2
// ----------------------------------------------------------------------------
int demSoLeViTriChan(const int a[], int n) {
    int count = 0;
    // TODO: Duyệt qua các vị trí chẵn (i = 0; i < n; i += 2) và kiểm tra a[i] % 2 != 0
    return count;
}

// ----------------------------------------------------------------------------
// 2. Tách mảng ban đầu thành 2 mảng con: mảng số chẵn và mảng số lẻ
// Lưu ý: nChan và nLe phải được cập nhật ra bên ngoài thông qua THAM CHIẾU (int&)
// ----------------------------------------------------------------------------
void tachChanLe(const int a[], int n, int chan[], int& nChan, int le[], int& nLe) {
    nChan = 0;
    nLe = 0;
    // TODO: Duyệt qua từng phần tử a[i]:
    // Nếu chẵn -> chan[nChan++] = a[i]
    // Nếu lẻ   -> le[nLe++]     = a[i]
}

// ----------------------------------------------------------------------------
// 3. Đảo ngược mảng tại chỗ (In-place Array Reversal)
// KHÔNG ĐƯỢC dùng mảng phụ. Dùng kỹ thuật 2 con trỏ / 2 chỉ số (left, right).
// ----------------------------------------------------------------------------
void daoNguocMang(int a[], int n) {
    // TODO: Hoán vị a[left] và a[right] cho đến khi left >= right
}

// ----------------------------------------------------------------------------
// HÀM KIỂM THỬ TỰ ĐỘNG
// ----------------------------------------------------------------------------
int main() {
    cout << "=== KIỂM THỬ DAY 03 - BÀI 1 ===" << endl;

    // Test 1: Đếm số lẻ vị trí chẵn
    int arr1[6] = { 5, 2, 9, 4, 3, 6 };
    // index 0: 5 (lẻ) -> đếm 1
    // index 2: 9 (lẻ) -> đếm 2
    // index 4: 3 (lẻ) -> đếm 3
    assert(demSoLeViTriChan(arr1, 6) == 3);

    int arr2[5] = { 2, 3, 4, 5, 6 };
    // index 0: 2 (chẵn), index 2: 4 (chẵn), index 4: 6 (chẵn) -> Kết quả 0
    assert(demSoLeViTriChan(arr2, 5) == 0);

    // Test 2: Tách chẵn lẻ
    int a[7] = { 10, 15, 22, 33, 40, 51, 60 };
    int chan[10], le[10];
    int nChan = 0, nLe = 0;

    tachChanLe(a, 7, chan, nChan, le, nLe);
    assert(nChan == 4);
    assert(nLe == 3);
    assert(chan[0] == 10 && chan[1] == 22 && chan[2] == 40 && chan[3] == 60);
    assert(le[0] == 15 && le[1] == 33 && le[2] == 51);

    // Test 3: Đảo ngược mảng
    int arrRev[5] = { 1, 2, 3, 4, 5 };
    daoNguocMang(arrRev, 5);
    assert(arrRev[0] == 5);
    assert(arrRev[1] == 4);
    assert(arrRev[2] == 3);
    assert(arrRev[3] == 2);
    assert(arrRev[4] == 1);

    cout << "\n✅ CHÚC MỪNG: BẠN ĐÃ VƯỢT QUA TOÀN BỘ TEST CASES BÀI 1!" << endl;
    return 0;
}
