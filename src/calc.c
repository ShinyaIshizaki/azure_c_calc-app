#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

int main(void) {
    // HTTPレスポンスヘッダー
    printf("Content-Type: text/html; charset=utf-8\r\n\r\n");

    char *method = getenv("REQUEST_METHOD");
    
    // 【重要】配列として正しく宣言 (サイズ MAX_BUFFER)
    char raw_data[MAX_BUFFER] = {0};

    // リクエストメソッドに応じた処理分岐
    if (method != NULL && strcmp(method, "GET") == 0) {
        // GETの場合: 環境変数 QUERY_STRING から取得
        char *query_string = getenv("QUERY_STRING");
        if (query_string != NULL) {
            strncpy(raw_data, query_string, MAX_BUFFER - 1);
        }
    } else if (method != NULL && strcmp(method, "POST") == 0) {
        // POSTの場合: CONTENT_LENGTH を読み取り、標準入力 (stdin) から取得
        char *content_length_str = getenv("CONTENT_LENGTH");
        if (content_length_str != NULL) {
            int content_length = atoi(content_length_str);

            // バッファオーバーフロー防止チェック
            if (content_length > 0 && content_length < MAX_BUFFER) {
                // 標準入力 (stdin) から指定バイト数分読み込む
                fread(raw_data, 1, content_length, stdin);
                raw_data[content_length] = '\0'; // ナル終端処理
            }
        }
    }

    // HTML出力
    printf("<!DOCTYPE html>\n");
    printf("<html lang=\"ja\">\n");
    printf("<head>\n");
    printf("  <meta charset=\"UTF-8\">\n");
    printf("  <title>CGI GET/POST Test</title>\n");
    printf("  <style>\n");
    printf("    body { font-family: sans-serif; max-width: 600px; margin: 40px auto; padding: 20px; }\n");
    printf("    .result { background: #eef6ff; padding: 15px; border-radius: 6px; border-left: 4px solid #0066cc; }\n");
    printf("    code { background: #e0e0e0; padding: 2px 6px; border-radius: 4px; }\n");
    printf("  </style>\n");
    printf("</head>\n");
    printf("<body>\n");
    printf("  <h1>C言語CGI: データ受信結果</h1>\n");
    printf("  <div class=\"result\">\n");
    printf("    <p><strong>リクエストメソッド:</strong> <code>%s</code></p>\n", method ? method : "UNKNOWN");
    printf("    <p><strong>受信した生データ:</strong> <code>%s</code></p>\n", raw_data[0] != '\0' ? raw_data : "(空)");
    printf("  </div>\n");
    printf("  <p><a href=\"/\">← フォーム画面に戻る</a></p>\n");
    printf("</body>\n");
    printf("</html>\n");

    return 0;
}