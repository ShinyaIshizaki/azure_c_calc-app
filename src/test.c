#include <stdio.h>

int main(void) {
// HTTPレスポンスヘッダーを出力（空行 \r\n\r\n がヘッダーとボディの区切り
    printf("Content-Type: text/html; charset=utf-8\r\n\r\n"

// HTTPボディ（ブラウザに表示されるHTML）を出力
           "<!DOCTYPE html>\n"
           "<html>\n"
           "<head><title>CGI Test</title></head>\n"
           "<body>\n"
           "<h1>Hello from C CGI!</h1>\n"
           "<p>C言語プログラムがAzure VM上で正常に実行されました。</p>\n"
           "</body>\n"
           "</html>\n");
    return 0;
}
