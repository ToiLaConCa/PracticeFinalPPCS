// Họ và Tên: [Điền tên của bạn]
// MSSV: [Điền MSSV]
// ============================================================================
// DAY 04 - BÀI TẬP 2: VĂN PHẠM SỐ HỌC & PHÉP GÁN (ARITHMETIC & ASSIGNMENT)
// ============================================================================
// Bảng độ ưu tiên:
// Mức 1 (Cao nhất, RTL): ^ (Lũy thừa)
// Mức 2 (LTR)         : *, /, % (Nhân, chia, dư)
// Mức 3 (LTR)         : +, - (Cộng, trừ)
// Mức 4 (Thấp nhất, RTL): =, +=, -= (Gán giá trị)
// ============================================================================

grammar ArithmeticAssignGrammar;

// 1. Điểm bắt đầu (Start symbol): Ưu tiên THẤP NHẤT (Mức 4: Gán =, +=, -=)
// Lưu ý: Phép gán là Right-to-Left (a = b = 5 tính b = 5 trước rồi gán cho a)
// Quy tắc Đệ quy phải:
// assignExpr -> ID ('=' | '+=' | '-=') assignExpr | addExpr
assignExpr
    : // TODO: Điền quy tắc ở đây
    ;

// 2. Mức 3: +, - (Left-to-Right -> Đệ quy trái)
// addExpr -> addExpr ('+' | '-') mulExpr | mulExpr
addExpr
    : // TODO: Điền quy tắc ở đây
    ;

// 3. Mức 2: *, /, % (Left-to-Right -> Đệ quy trái)
// mulExpr -> mulExpr ('*' | '/' | '%') powerExpr | powerExpr
mulExpr
    : // TODO: Điền quy tắc ở đây
    ;

// 4. Mức 1: ^ Lũy thừa (Right-to-Left -> Đệ quy phải!)
// Ví dụ: 2 ^ 3 ^ 2 = 2 ^ (3 ^ 2) = 2 ^ 9 = 512
// Quy tắc Đệ quy phải: powerExpr -> primary '^' powerExpr | primary
powerExpr
    : // TODO: Điền quy tắc ở đây
    ;

// 5. Tầng cơ sở (Primary)
primary
    : ID
    | INT_LITERAL
    | '(' assignExpr ')'
    ;

// ----------------------------------------------------------------------------
// LEXER RULES
// ----------------------------------------------------------------------------
ID          : [a-zA-Z_][a-zA-Z0-9_]* ;
INT_LITERAL : [0-9]+ ;
WS          : [ \t\r\n]+ -> skip ;
