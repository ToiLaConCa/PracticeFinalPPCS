# 📌 DAY 03: HÀM, CON TRỎ & THAO TÁC MẢNG (FUNCTIONS, POINTERS & ARRAYS)

> **Mục tiêu:** Nắm chắc cơ chế truyền tham số trong C++ (Tham trị vs Tham chiếu `&` vs Con trỏ `*`), kỹ thuật lọc và biến đổi mảng một chiều (Array Transformations).  
> **Thời gian dự kiến:** 45 - 60 phút.

---

## ⚡ Tóm Tắt Lý Thuyết Cốt Lõi (Đọc trong 3 phút)

### 1. Phân biệt 4 kiểu truyền tham số
| Cách truyền | Cú pháp | Trong hàm có sửa biến gốc ở `main` không? | Khi nào dùng? |
|---|---|:---:|---|
| **Tham trị (By Value)** | `void f(int x)` | ❌ Không | Khi chỉ đọc biến kiểu cơ bản (`int`, `char`, `double`). |
| **Tham chiếu (By Reference)** | `void f(int& x)` | ✅ **Có** | Khi muốn thay đổi giá trị của biến gốc (ví dụ hàm `swap`). |
| **Con trỏ (Pointer)** | `void f(int* p)` | ✅ **Có** (qua `*p`) | Quản lý bộ nhớ động hoặc con trỏ mảng. |
| **Tham chiếu hằng (Const Ref)** | `void f(const string& s)` | ❌ Không | Khi truyền đối tượng lớn (string, vector, struct) để **tránh tốn bộ nhớ copy** nhưng cấm sửa đổi. |

### 2. Mảng 1 chiều trong C++
- Tên mảng `a` thực chất phân rã thành con trỏ trỏ vào phần tử đầu tiên: `a == &a[0]`.
- Khi truyền mảng vào hàm, bắt buộc phải truyền kèm số lượng phần tử `int n`:
  ```cpp
  void xuatMang(const int a[], int n);
  ```

---

## 📝 Danh Sách Bài Tập Ngày 3

### Bài 1: Lọc Và Biến Đổi Mảng (`Bai1_Array_Filter_Transform.cpp`)
Đề bài mô phỏng đúng dạng câu hỏi C++ hàm trong đề thi PPCS:
1. `int demSoLeViTriChan(const int a[], int n)`: Đếm các số lẻ (`val % 2 != 0`) nằm ở vị trí chỉ số chẵn (`index 0, 2, 4...`).
2. `void tachChanLe(const int a[], int n, int chan[], int& nChan, int le[], int& nLe)`: Tách các phần tử của mảng `a` thành 2 mảng `chan` và `le`, cập nhật số lượng qua tham chiếu `int&`.
3. `void daoNguocMang(int a[], int n)`: Đảo ngược mảng tại chỗ (in-place) không dùng mảng phụ.

### Bài 2: Con Trỏ Và Hoán Vị Nâng Cao (`Bai2_Pointer_Reference_Ops.cpp`)
1. `void swapByReference(int& a, int& b)`: Hoán vị dùng tham chiếu.
2. `void swapByPointer(int* a, int* b)`: Hoán vị dùng con trỏ (kiểm tra an toàn con trỏ `nullptr`).
3. `void timMinMax(const int a[], int n, int*& pMin, int*& pMax)`: Tìm con trỏ trỏ vào phần tử nhỏ nhất và lớn nhất trong mảng.

---

## 🎯 Tiêu Chí Chấm Điểm
1. Sử dụng đúng cú pháp tham chiếu `&` khi cần thay đổi giá trị. (3đ)
2. Không bị lỗi truy cập ngoài biên mảng (Out of bounds). (3đ)
3. Thuật toán đảo ngược mảng tại chỗ đúng chuẩn O(n) thời gian và O(1) không gian. (2đ)
4. Vượt qua 100% assertions kiểm thử tự động. (2đ)
