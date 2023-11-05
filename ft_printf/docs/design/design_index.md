# Design Index

# 全体像フロー

1. printfの引数をva_listに変換する。
2. vprintf_fdに`fd = 1`で渡す。
3. `format`を`未定関数`に渡す。
4. 戻り値の`未定の構造体`とva_listを`未定関数2`に渡す。
5. 戻り値の出力文字数を`vaprintf_fd`の戻り値として、`printf`に渡す。
6. `printf`はそれを出力する。

# プロトタイプ宣言などのリンク

* [printf](./printf.md)
* [vprintf](./vprintf.md)
