
/** copied by https://programming-place.net/ppp/contents/c/rev_res/file001.html */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    ファイルをコピーする。

    src_path:  コピー元ファイルのパス
    dest_path: コピー先ファイルのパス
    戻り値:   成功したら 0以外、失敗したら 0
*/
int copy_file(const char* src_path, const char* dest_path)
{
    // コピー元とコピー先が同じ
    if (strcmp(src_path, dest_path) == 0) {
        return 0;
    }

    int result = 1;

    // バイナリモードで開く
    FILE* fp_src = fopen(src_path, "rb");
    FILE* fp_dest = fopen(dest_path, "wb");
    if (fp_src == NULL || fp_dest == NULL) {
        result = 0;
    }

    if (result != 0) {
        for (;;) {
            char c;

            // 1バイト読み込む
            if (fread(&c, sizeof(c), 1, fp_src) < 1) {
                if (feof(fp_src)) {
                    break;
                }
                else {
                    result = 0;
                    break;
                }
            }

            // 1バイト書き込む
            if (fwrite(&c, sizeof(c), 1, fp_dest) < 1) {
                result = 0;
                break;
            }
        }
    }

    if (fp_dest != NULL) {
        if (fclose(fp_dest) == EOF) {
            result = 0;
        }
    }
    if (fp_src != NULL) {
        if (fclose(fp_src) == EOF) {
            result = 0;
        }
    }

    return result;
}
