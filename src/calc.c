#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // 1. HTTPレスポンスヘッダーを出力
    printf("Content-Type: text/html; charset=utf-8\r\n\r\n");

    // 2. 環境変数からリクエストメソッドとクエリ文字列を取得
    char *method = getenv("REQUEST_METHOD");
    char *query_string = getenv("QUERY_STRING");

    // 3. レスポンスHTMLを出力
    printf("<!DOCTYPE html>\n");
    printf("<html lang=\"ja\">\n");
    printf("<head>\n");
    printf("  <meta charset=\"UTF-8\">\n");
    printf("  <title>CGI GET Parameter Test</title>\n");
    printf("  <style>\n");
    printf("    body { font-family: sans-serif; max-width: 600px; margin: 40px auto; padding: 20px; }\n");
    printf("    .result { background: #eef6ff; padding: 15px; border-radius: 6px; border-left: 4px solid #0066cc; }\n");
    printf("    code { background: #e0e0e0; padding: 2px 6px; border-radius: 4px; }\n");
    printf("  </style>\n");
    printf("</head>\n");
    printf("<body>\n");
    printf("  <h1>C言語CGI: GETパラメータ受信結果</h1>\n");
    printf("  <div class=\"result\">\n");

    // メソッドの表示
    if (method != NULL) {
        printf("    <p><strong>リクエストメソッド:</strong> <code>%s</code></p>\n", method);
    } else {
        printf("    <p>リクエストメソッドが取得できませんでした。</p>\n");
    }

    // クエリ文字列の表示
    if (query_string != NULL && query_string[0] != '\0') {
        printf("    <p><strong>受信した生データ (QUERY_STRING):</strong> <code>%s</code></p>\n", query_string);
    } else {
        printf("    <p>クエリ文字列 (QUERY_STRING) は空です。</p>\n");
    }

    printf("  </div>\n");
    printf("  <p><a href=\"/\">← フォーム画面に戻る</a></p>\n");
    printf("</body>\n");
    printf("</html>\n");

    return 0;
}