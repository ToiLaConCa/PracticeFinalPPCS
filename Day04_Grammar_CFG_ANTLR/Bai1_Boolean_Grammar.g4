// Họ và Tên: [Điền tên của bạn]
// MSSV: [Điền MSSV]
// ============================================================================
// DAY 04 - BÀI TẬP 1: VĂN PHẠM LOGIC BOOLEAN (ANTLR v4 / CFG)
// ============================================================================
// Bảng độ ưu tiên:
// Mức 1 (Cao nhất, RTL): !
// Mức 2 (LTR)         : <, <=, >, >=
// Mức 3 (LTR)         : ==, !=
// Mức 4 (LTR)         : &&
// Mức 5 (Thấp nhất, LTR): ||
// ============================================================================

grammar BooleanGrammar;

// 1. Điểm bắt đầu (Start symbol): Ưu tiên THẤP NHẤT nằm ở đây (Mức 5: ||)
// TODO: Viết quy tắc cho orExpr (Left-to-Right -> Đệ quy trái)
// orExpr
//     : orExpr '||' andExpr
//     | andExpr
//     ;
orExpr
    : // TODO: Điền quy tắc ở đây
    ;

// 2. Mức 4: && (Left-to-Right -> Đệ quy trái)
// TODO: Viết quy tắc cho andExpr
andExpr
    : // TODO: Điền quy tắc ở đây
    ;

// 3. Mức 3: ==, != (Left-to-Right -> Đệ quy trái)
// TODO: Viết quy tắc cho eqExpr
eqExpr
    : // TODO: Điền quy tắc ở đây
    ;

// 4. Mức 2: <, <=, >, >= (Left-to-Right -> Đệ quy trái)
// TODO: Viết quy tắc cho relExpr
relExpr
    : // TODO: Điền quy tắc ở đây
    ;

// 5. Mức 1 (Cao nhất): ! (Right-to-Left -> Đệ quy phải)
// TODO: Viết quy tắc cho notExpr
// Lưu ý: notExpr -> '!' notExpr | primary
notExpr
    : // TODO: Điền quy tắc ở đây
    ;

// 6. Tầng lá (Primary): ID, TRUE, FALSE hoặc biểu thức trong ngoặc tròn
primary
    : ID
    | TRUE
    | FALSE
    | '(' orExpr ')'
    ;

// ----------------------------------------------------------------------------
// LEXER RULES (Các token từ vựng)
// ----------------------------------------------------------------------------
TRUE       : 'true' ;
FALSE      : 'false' ;
ID         : [a-zA-Z_][a-zA-Z0-9_]* ;
WS         : [ \t\r\n]+ -> skip ;
