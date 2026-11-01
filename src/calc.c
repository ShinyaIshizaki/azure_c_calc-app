#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // 1. HTTPヘッダーの出力（文字コード UTF-8）
    printf("Content-Type: text/html;charset=UTF-8\n\n");

    // 2. 環境変数 QUERY_STRING からクエリ文字列を取得
    char *query = getenv("QUERY_STRING");
    int a = 0, b = 0;
    int parsed = 0;

    if (query != NULL) {
        // "a=10&b=20" のような形式を sscanf でパース
        if (sscanf(query, "a=%d&b=%d", &a, &b) == 2) {
            parsed = 1;
        }
    }

    // 3. 動的な HTML レスポンスの生成
    printf("<!DOCTYPE html>\n");
    printf("<html lang=\"ja\">\n");
    printf("<head>\n");
    printf("  <meta charset=\"UTF-8\">\n");
    printf("  <title>CGI Calculator</title>\n");
    printf("</head>\n");
    printf("<body>\n");
    printf("  <h1>CGI 計算アプリ (Task 4)</h1>\n");

    if (parsed) {
        int sum = a + b;
        printf("  <p>計算結果: %d + %d = <strong>%d</strong></p>\n", a, b, sum);
    } else {
        printf("  <p style=\"color: red;\">エラー: パラメータが正しく指定されていません。</p>\n");
        printf("  <p>利用例: <a href=\"calc.cgi?a=10&b=20\">calc.cgi?a=10&b=20</a></p>\n");
    }

    printf("</body>\n");
    printf("</html>\n");

    return 0;
}