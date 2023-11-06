
# print_char_fd

## prototype

```c
int	print_char_fd(int fd, t_conv_specification *cs, va_list args);
```

## return value

成功時: 出力した文字数
失敗時: 負の値

## description

* `%c`用の出力関数。
* `int`で受け取る。
* 内部的に`unsigned char`に変換される。
* fdに一文字出力する。
* `+`と` `フラグは無視される。
* 精度は無視される。
