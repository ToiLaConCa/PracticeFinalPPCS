# 📌 DAY 04: BẢNG LOGIC $\rightarrow$ VĂN PHẠM CFG & ANTLR (.g4)

> **Mục tiêu:** Nắm vững tuyệt kỹ nhìn bảng Độ ưu tiên (Precedence) & Tính kết hợp (Associativity) để viết văn phạm phi ngữ cảnh (CFG / ANTLR .g4). Đây là câu hỏi **100% xuất hiện trong phần thi tự luận viết tay**!  
> **Thời gian dự kiến:** 45 - 60 phút.

---

## ⚡ 2 Câu Thần Chú Bất Bại (Thuộc Lòng Đi Thi)

### Thần chú 1: Độ ưu tiên (Precedence)
> **ƯU TIÊN CÀNG THẤP $\rightarrow$ VIẾT Ở CÀNG CAO (GẦN GỐC ROOT)**  
> **ƯU TIÊN CÀNG CAO $\rightarrow$ VIẾT Ở CÀNG SÂU (GẦN LÁ PRIMARY)**

*Giải thích bản chất:* Trong cây Parse Tree, toán tử ở lá (tầng sâu) sẽ được tính trước. Toán tử ở gốc (tầng cao) sẽ tính sau cùng. Do đó, toán tử ưu tiên thấp nhất (ví dụ `||` hoặc phép gán `=`) phải nằm ở tầng cao nhất!

### Thần chú 2: Tính kết hợp (Associativity)
- **Left-to-Right (Kết hợp Trái - đa số phép 2 ngôi binary):**  
  👉 **ĐỆ QUY TRÁI** (Tên quy tắc nằm bên TRÁI toán tử):
  ```text
  expr -> expr OP nextLevel | nextLevel ;
  ```
- **Right-to-Left (Kết hợp Phải - phép gán, toán tử 1 ngôi prefix như `!`, `-`):**  
  👉 **ĐỆ QUY PHẢI** (Tên quy tắc nằm bên PHẢI toán tử):
  ```text
  expr -> OP expr | nextLevel ;
  ```

---

## 📝 Danh Sách Bài Tập Ngày 4

### Bài 1: Văn Phạm Biểu Thức Logic Boolean (`Bai1_Boolean_Grammar.g4`)
Cho bảng độ ưu tiên và tính kết hợp sau (đề thi kinh điển):

| Mức ưu tiên (1 = Cao nhất) | Toán tử (Operators) | Tính kết hợp (Associativity) | Tên Tầng Đề Xuất |
|:---:|:---:|:---:|:---:|
| **1 (Cao nhất)** | `!` (NOT logic) | Right-to-Left (Phải sang trái) | `notExpr` |
| **2** | `<`, `<=`, `>`, `>=` (So sánh) | Left-to-Right (Trái sang phải) | `relExpr` |
| **3** | `==`, `!=` (Bằng / Khác) | Left-to-Right (Trái sang phải) | `eqExpr` |
| **4** | `&&` (AND logic) | Left-to-Right (Trái sang phải) | `andExpr` |
| **5 (Thấp nhất)** | `\|\|` (OR logic) | Left-to-Right (Trái sang phải) | `orExpr` |
| **Lá cơ sở** | `ID`, `TRUE`, `FALSE`, `( expr )` | - | `primary` |

👉 Nhiệm vụ: Viết hoàn chỉnh các luật ngữ pháp trong file `Bai1_Boolean_Grammar.g4`.

---

### Bài 2: Văn Phạm Số Học & Gán Biến (`Bai2_Arithmetic_Assign_Grammar.g4`)
Cho bảng độ ưu tiên phức hợp gồm cả phép gán, số học và lũy thừa:

| Mức ưu tiên | Toán tử | Tính kết hợp | Ý nghĩa |
|:---:|:---:|:---:|:---|
| **1 (Cao nhất)** | `^` (Lũy thừa) | **Right-to-Left** (2^3^4 = 2^(3^4)) | Đệ quy phải |
| **2** | `*`, `/`, `%` | Left-to-Right | Nhân, chia, chia dư |
| **3** | `+`, `-` | Left-to-Right | Cộng, trừ |
| **4 (Thấp nhất)** | `=`, `+=`, `-=` | **Right-to-Left** (a = b = c) | Gán giá trị |
| **Lá cơ sở** | `ID`, `INT_LITERAL`, `( expr )` | - | Biến hoặc số |

👉 Nhiệm vụ: Viết hoàn chỉnh các luật ngữ pháp trong file `Bai2_Arithmetic_Assign_Grammar.g4`.

---

## 🎯 Tiêu Chí Chấm Điểm
1. Sắp xếp thứ tự các tầng quy tắc đúng tuyệt đối theo quy tắc Thấp ở Gốc $\rightarrow$ Cao ở Lá. (4đ)
2. Viết đúng đệ quy trái cho Left-to-Right và đệ quy phải cho Right-to-Left. (4đ)
3. Xử lý đúng tầng `primary` có dấu ngoặc tròn `( expr )`. (2đ)
