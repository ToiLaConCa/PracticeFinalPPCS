# 🎯 Practice Final PPCS — Lộ Trình 5 Ngày Nước Rút Về Đích 🚀

> **Repository ôn thi Final môn PPCS (Principles of Programming & Computing / Computer Science)**  
> **Mục tiêu:** Nắm chắc bản chất 3 phần thi chính (OOP C++, Hàm/Mảng C++, Văn phạm CFG/ANTLR & Parse Tree) trong đúng 5 ngày.  
> **Cơ chế học tập:** Mỗi ngày mở thư mục tương ứng, đọc đề $\rightarrow$ code hoàn thiện $\rightarrow$ `git commit` & `git push` $\rightarrow$ gọi AI chấm điểm & sửa lỗi ngay trên commit!

---

## 📅 Lộ Trình Ôn Tập 5 Ngày (5-Day Sprint Roadmap)

| Ngày | Chủ Đề Trọng Tâm | Dạng Bài Tập | Trọng Số Đề Thi | Thư Mục | Trạng Thái |
|:---:|:---|:---|:---:|:---|:---:|
| **Day 01** | **Kế Thừa & Đóng Gói (Inheritance)** | Constructor Chaining, `protected` vs `private`, Override phương thức cơ bản | 25% | `Day01_OOP_Inheritance/` | ⏳ Chờ làm |
| **Day 02** | **Đa Hình & Hàm Ảo (Polymorphism)** | `virtual`, `override`, Virtual Destructor, Mảng con trỏ cơ sở đa hình | 25% | `Day02_Polymorphism_Virtual/` | ⏳ Chờ làm |
| **Day 03** | **Hàm, Con Trỏ & Mảng (Functions)** | Tham trị vs Tham chiếu (`&`) vs Con trỏ (`*`), Thao tác lọc mảng 1D | 20% | `Day03_Functions_Pointers_Arrays/` | ⏳ Chờ làm |
| **Day 04** | **Bảng Logic $\rightarrow$ Grammar (.g4 / CFG)** | Thần chú "Thấp ở Gốc, Cao ở Lá", Đệ quy trái (LTR) vs Đệ quy phải (RTL) | 15% | `Day04_Grammar_CFG_ANTLR/` | ⏳ Chờ làm |
| **Day 05** | **Vẽ Parse Tree & Mock Exam Final** | Kỹ thuật vẽ cây cú pháp từng bước + Đề thi thử tổng hợp 60 phút | 15% | `Day05_ParseTree_MockExam/` | ⏳ Chờ làm |

---

## 🛠️ Quy Trình Làm Bài & Nhận Điểm Hàng Ngày (Workflow)

```text
1. MỞ BÀI TẬP:
   └── Mở thư mục của ngày hôm đó (ví dụ Day01_OOP_Inheritance)
   └── Đọc file README.md để nắm yêu cầu và tóm tắt lý thuyết 3 phút

2. VIẾT CODE:
   └── Mở file template có sẵn (chứa các vị trí // TODO: ...)
   └── Tự code phần logic vào

3. CHẠY THỬ NGHIỆM:
   └── Biên dịch và chạy test cases có sẵn:
       g++ -std=c++17 <ten_file>.cpp -o test && ./test

4. COMMIT & PUSH LÊN GITHUB:
   └── git add .
   └── git commit -m "Day 01: Hoan thanh Bai 1 va Bai 2"
   └── git push origin main

5. GỌI AI CHẤM BÀI:
   └── Nhắn cho mình (Antigravity): "Mình vừa push Day 01, chấm bài giúp mình nhé!"
   └── Mình sẽ review từng dòng code, phân tích edge-cases, chấm điểm theo barem thi và chỉ ra điểm cần tối ưu!
```

---

## 💡 Bảng Phím Tắt Tiện Ích
- Biên dịch nhanh file C++:
  ```bash
  g++ -std=c++17 Bai1_SmartHome_Device.cpp -o app && ./app
  ```
- Hoặc dùng script kiểm tra nhanh đi kèm:
  ```bash
  ./run_test.sh Day01_OOP_Inheritance/Bai1_SmartHome_Device.cpp
  ```

---
*Chúc bạn ôn tập tập trung, đạt điểm tuyệt đối trong kỳ thi Final sắp tới! 💯*
