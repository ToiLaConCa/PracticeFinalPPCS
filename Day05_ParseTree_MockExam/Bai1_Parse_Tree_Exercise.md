# 🌳 BÀI TẬP VẼ CÂY CÚ PHÁP (PARSE TREE EXERCISES)

> **Họ và Tên:** [Điền tên của bạn]  
> **MSSV:** [Điền MSSV]  
> **Hướng dẫn:** Bạn hãy vẽ cấu trúc cây phân tích cú pháp cho từng câu dưới đây (có thể dùng cây thụt dòng Markdown hoặc ASCII art).

---

## CÂU 1: Biểu thức `A && B || ! C`
Dựa trên văn phạm Boolean (Day 04):
- Độ ưu tiên: `!` (cao nhất) $\rightarrow$ `&&` $\rightarrow$ `||` (thấp nhất).
- Đóng ngoặc: `((A && B) || (!C))`

### CÂY CÚ PHÁP CỦA BẠN:
<!-- TODO: Hãy vẽ cây cú pháp của bạn ở dưới đây -->
```text
orExpr
├── ...
```

---

## CÂU 2: Biểu thức `A < B == C > D`
Dựa trên văn phạm Boolean:
- Độ ưu tiên: `<`, `>` (cao hơn) $\rightarrow$ `==` (thấp hơn).
- Đóng ngoặc: `((A < B) == (C > D))`

### CÂY CÚ PHÁP CỦA BẠN:
<!-- TODO: Hãy vẽ cây cú pháp của bạn ở dưới đây -->
```text
eqExpr
├── ...
```

---

## CÂU 3: Biểu thức `x = y + 2 * 3`
Dựa trên văn phạm Số học & Gán:
- Độ ưu tiên: `*` (cao nhất) $\rightarrow$ `+` $\rightarrow$ `=` (thấp nhất).
- Đóng ngoặc: `(x = (y + (2 * 3)))`

### CÂY CÚ PHÁP CỦA BẠN:
<!-- TODO: Hãy vẽ cây cú pháp của bạn ở dưới đây -->
```text
assignExpr
├── ...
```
