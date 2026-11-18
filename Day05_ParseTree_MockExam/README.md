# 📌 DAY 05: VẼ PARSE TREE (CÂY CÚ PHÁP) & ĐỀ THI THỬ TỔNG HỢP

> **Mục tiêu:** Nắm chắc phương pháp vẽ cây cú pháp (Parse Tree) bằng tay cho các biểu thức logic / số học, và hoàn thành 1 đề thi thử tổng hợp (Mock Exam) bao quát toàn bộ kiến thức OOP & Hàm C++.  
> **Thời gian dự kiến:** 60 - 90 phút.

---

## ⚡ Bí Kíp Vẽ Parse Tree Bằng Tay (Ăn Trọn Điểm Thi Tự Luận)

### Quy trình 3 bước vẽ cây:
1. **Bước 1 (Đóng ngoặc biểu thức theo độ ưu tiên):**  
   Trước khi vẽ, hãy dùng bút chì đóng ngoặc biểu thức dựa trên bảng độ ưu tiên.
   - Ví dụ biểu thức: `! A || B && C`
   - Nhìn bảng: `!` cao nhất $\rightarrow$ `(!A)`
   - Kế tiếp `&&` cao hơn `||` $\rightarrow$ `(B && C)`
   - Cuối cùng `||` $\rightarrow$ `((!A) || (B && C))`
2. **Bước 2 (Xác định gốc Root):**  
   Toán tử bị bao bọc sau cùng (ưu tiên thấp nhất) sẽ là gốc của cây (ở đây là `||`).
3. **Bước 3 (Vẽ từ Gốc bung dần xuống Lá):**  
   - Gốc `orExpr` bung ra: `orExpr` $\rightarrow$ `orExpr` `||` `andExpr`.
   - Vế trái bung tiếp `!A`.
   - Vế phải bung tiếp `B && C`.

---

## 📝 Danh Sách Bài Tập Ngày 5

### Bài 1: Luyện Vẽ Parse Tree (`Bai1_Parse_Tree_Exercise.md`)
Vẽ cây phân tích cú pháp (dưới dạng văn bản, cây thụt đầu dòng hoặc ASCII art) cho 3 câu thi thật:
1. `Câu 1:` `A && B || ! C`
2. `Câu 2:` `A < B == C > D`
3. `Câu 3:` `x = y + 2 * 3`

### Bài 2: Đề Thi Thử Tổng Hợp 60 Phút (`MockExam_Final.cpp`)
Đề bài kết hợp:
- Lớp cơ sở `Course` và 2 lớp con `OnlineCourse`, `InPersonCourse`.
- Kế thừa, Đa hình tính học phí thực tế sau khi áp dụng học bổng / phụ phí phòng lab.
- Hàm quản lý mảng con trỏ `Course*`: Tìm khóa học có học phí cao nhất, đếm số khóa học online, và sắp xếp.

---

## 🎯 Tiêu Chí Chấm Điểm
1. Vẽ cây phân tích cú pháp đúng thứ tự ưu tiên (toán tử tính trước nằm ở lá). (5đ)
2. Mock Exam biên dịch không lỗi, chạy pass 100% test cases trong `main()`. (5đ)
