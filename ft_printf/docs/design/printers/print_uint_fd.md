
# print_uint_fd

## prototype

```c
int	print_uint_fd(int fd, t_conv_specification *cs, va_list args);
```

## return value

成功時: 出力した文字数
失敗時: 負の値

## description

* `%u`用の出力関数。
* 内部的に`unsigned int`に変換される。
* fdに符号なし10進数として出力する。
* `+`と` `フラグは無視される。
* 精度が指定されている場合は、`0`フラグは無視される。
